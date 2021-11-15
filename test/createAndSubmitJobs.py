#!/usr/bin/env python

import sys, os, shutil, re, subprocess
#from optparse import OptionParser
from argparse import ArgumentParser 


def make_filenamelist(input_dir):

    proc = subprocess.Popen( [ '/usr/bin/eos', 'ls', input_dir ], stdout = subprocess.PIPE, stderr = subprocess.STDOUT )
    output = proc.communicate()[0]
    if proc.returncode != 0:
        print output
        sys.exit(1)

    return output.splitlines()


def process_input_dir(input_dir, match, filelist):

    input_dir = input_dir.rstrip('/')+'/'
    filenamelist = make_filenamelist(input_dir)

    path = input_dir;
    name = ''
    jobdict = {}

    for filename in filenamelist:
        if( not re.search('.root$', filename) ):
            continue
        if ( match!=None and not re.search(match, filename) ):
            continue
        m1 = re.search('_\d+.root', filename)
        if name=='':
            name = re.split('_\d+.root', filename)[0]
        jobstring = filename[m1.start():].lstrip('_').replace('.root','').split('_')
        job = int(jobstring[0])
        if job not in jobdict.keys():
            jobdict[job] = []
            #jobdict[job].append([int(jobstring[1])])
            #jobdict[job].append([jobstring[2]])
        #else:
        #    jobdict[job][0].append(int(jobstring[1]))
        #    jobdict[job][1].append(jobstring[2])

    jobs = jobdict.keys()
    if( len(jobs)==0 ):
        print 'No matching .root files found'
        sys.exit()

    jobs.sort()
    for job in jobs:
        filename = (path+name+'_%i.root')%(job) 
        filelist.append(filename)

    return


cfi_template = """FileNames = {'FileNames':[
INPUT_FILES
]}
"""

condor_template = """universe              = vanilla
#requirements          = (OpSysAndVer =?= "SLCern6")
requirements          = (OpSysAndVer =?= "CentOS7")
executable            = EXEC
arguments             = $(ClusterID) $(ProcId)
output                = OUTPUT/job_JOB_NUMBER.$(ClusterId).$(ProcId).out
error                 = OUTPUT/job_JOB_NUMBER.$(ClusterId).$(ProcId).err
log                   = OUTPUT/job_JOB_NUMBER.$(ClusterId).log
+JobFlavour           = "QUEUE"
queue
"""


bash_template = """#!/bin/bash

BATCHDIR=${PWD}

export SCRAM_ARCH=slc7_amd64_gcc700
cd MAIN_WORKDIR
eval `scram runtime -sh`

cp -v MAIN_WORKDIR/CMSSW_cfg.py $BATCHDIR/CMSSW_cfg.py
cp -v MAIN_WORKDIR/PUDistMC_2018_25ns_JuneProjectionFull18_PoissonOOTPU.root $BATCHDIR/PUDistMC_2018_25ns_JuneProjectionFull18_PoissonOOTPU.root
cp -v MAIN_WORKDIR/RunII2018All_PUXsec69000nb.root $BATCHDIR/RunII2018All_PUXsec69000nb.root
cp -v MAIN_WORKDIR/RunII2018All_PUXsec72450nb.root $BATCHDIR/RunII2018All_PUXsec72450nb.root
cp -v MAIN_WORKDIR/RunII2018All_PUXsec65550nb.root $BATCHDIR/RunII2018All_PUXsec65550nb.root
cp -v DATASET_WORKDIR/input/inputFiles_JOB_NUMBER_cfi.py $BATCHDIR/inputFiles_cfi.py
cp -v MAIN_WORKDIR/CSVv2.csv $BATCHDIR/
cd $BATCHDIR
echo "Running CMSSW job"
cmsRun CMSSW_cfg.py CFG_PARAMETERS
exitcode=$?

cp -v OUTPUT_FILENAME.root DATASET_WORKDIR/output/OUTPUT_FILENAME_JOB_NUMBER.root

exit $exitcode

"""


# usage description
usage = """Usage: ./createAndSubmitJobs.py [options]\n
Example: ./createAndSubmitJobs.py -w LXBatch_Jobs -d datasetList.txt -c btagvalidation_cfg.py\n
For more help: ./createAndSubmitJobs.py --help
"""

def main():
  # input parameters
  #parser = OptionParser(usage=usage)
  parser = ArgumentParser(description=usage)

  parser.add_argument("-w", "--main_workdir", dest="main_workdir", action='store', help="Main working directory", metavar="MAIN_WORKDIR")
  parser.add_argument("-d", "--dataset_list", dest="dataset_list", action='store', help="Text file containing a list of datasets to be processed", metavar="DATASET_LIST")
  parser.add_argument('-m', '--match', dest="match", action='store', help='Only files containing the MATCH string in their names will be considered (This parameter is optional)', metavar='MATCH')
  parser.add_argument("-c", "--cmssw_cfg", dest="cmssw_cfg", action='store', help="CMSSW configuration file", metavar="CMSSW_CFG")
  parser.add_argument('-f', '--fraction', dest='fraction', action='store', default='1.0', help='Fraction of files to be processed. Default value is 1 (This parameter is optional)', metavar='FRACTION')
  parser.add_argument("-q", "--queue", dest="queue", action='store', default='8nh', help="LXBatch/condor queue (choose among cmst3 8nm 1nh 8nh 1nd 1nw). Default is '8nh' (This parameter is optional)", metavar="QUEUE")
  parser.add_argument("-n", "--no_submission", dest="no_submission", action='store_true', default=False, help="Create the necessary configuration files and skip the job submission (This parameter is optional)")
  parser.add_argument("-b", "--batch_option", dest="batch_option", action='store', default='lxbatch', help="Select lxbatch or condor as the batch submission option. You may need to adjust the batch queue accordingly (This parameter is optional)")

  #(options, args) = parser.parse_args()
  args = parser.parse_args()
  if args.batch_option == 'condor' and args.queue == '': args.queue = 'tomorrow'

  # make sure all necessary input parameters are provided
  if not (args.main_workdir and args.dataset_list and args.cmssw_cfg):
    print usage
    sys.exit()

  main_workdir = args.main_workdir
  dataset_list = args.dataset_list
  cmssw_cfg = args.cmssw_cfg

  # redefine main_workdir as an absolute path (if not defined in such form already)
  if not re.search("^/", main_workdir):
    main_workdir = os.path.join(os.getcwd(),main_workdir)

  # create the main working directory
  if not os.path.exists(main_workdir):
    os.mkdir(main_workdir)

  # copy the dataset list file to the main_workdir
  shutil.copyfile(dataset_list,os.path.join(main_workdir,'datasetList.txt'))

  # copy the CMSSW cfg file to the cfg_files_dir
  shutil.copyfile(cmssw_cfg,os.path.join(main_workdir,'CMSSW_cfg.py'))

  # look for pileup distribution, CSV SF files, pt and other weight files and copy them into main_workdir
  cfg_dirname = os.path.dirname(cmssw_cfg)
  if cfg_dirname=='':
    cfg_dirname = os.getcwd()
  for filename in os.listdir(cfg_dirname):
    if not os.path.isfile(os.path.join(cfg_dirname,filename)):
      continue
    if re.search("^RunII2018All_PUXsec69000nb.root$", filename):
      shutil.copy(os.path.join(cfg_dirname,filename),main_workdir)
    if re.search("^RunII2018All_PUXsec72450nb.root$", filename):
      shutil.copy(os.path.join(cfg_dirname,filename),main_workdir)
    if re.search("^RunII2018All_PUXsec65550nb.root$", filename):
      shutil.copy(os.path.join(cfg_dirname,filename),main_workdir)
    if re.search("^PUDistMC_2018_25ns_JuneProjectionFull18_PoissonOOTPU.root$", filename):
      shutil.copy(os.path.join(cfg_dirname,filename),main_workdir)
    if re.search("^CSVv2.csv$", filename):
      shutil.copy(os.path.join(cfg_dirname,filename),main_workdir)
  # open and read the dataset_list file
  dataset_list_file = open(dataset_list,"r")
  dataset_list_lines = dataset_list_file.readlines()

  # loop over datasets
  for line in dataset_list_lines:
    line_elements = line.split()
    if (len(line_elements)==0 or line_elements[0][0]=='#'): continue

    output_filename = 'bTagValPlots'
    cfg_parameters = ''
    if( len(line_elements)>3 ):
      cfg_parameters = line_elements[3]
      if( line_elements[3].split('=')[0]=='outFilename' ): output_filename = line_elements[3].split('=')[1].replace('.root','')
      for par in range(4,len(line_elements)):
        cfg_parameters = cfg_parameters + ' ' + line_elements[par]
        if( line_elements[par].split('=')[0]=='outFilename' ): output_filename = line_elements[par].split('=')[1].replace('.root','')

    dataset = line_elements[0].lstrip('/').replace('/','__')
    print 'Processing ' + line_elements[0]

    dataset_workdir = os.path.join(main_workdir,dataset)

    # create the dataset working directory
    os.mkdir(dataset_workdir)
    os.mkdir(os.path.join(dataset_workdir,'input'))
    os.mkdir(os.path.join(dataset_workdir,'output'))

    filelist = []
    process_input_dir(line_elements[2], args.match, filelist)

    ##################################################
    njobs = line_elements[1]
    numfiles = int(len(filelist)*float(args.fraction))
    ijobmax=int(njobs)
    if ijobmax > numfiles:
       ijobmax=numfiles
       print '  Number of jobs requested exceeds the total number of input files.\n  The number of jobs set to ' + str(ijobmax) + ' to match the number of input files'
    filesperjob = int(numfiles/ijobmax)
    if numfiles%ijobmax!=0:
       filesperjob = filesperjob + 1
       ijobmax = int(numfiles/filesperjob)
       if numfiles%filesperjob!=0:
           ijobmax = ijobmax + 1
       if ijobmax != int(njobs):
           print '  Could not create the exact number of jobs requested.\n  For optimal job splitting, the number of jobs set to ' + str(ijobmax)
    #################################################
    ifile = 0
    for ijob in range(ijobmax):
       # prepare the list of input files
       input_files = '    \'root://eoscms.cern.ch/' + filelist[ifile] + '\''
       for i in range(filesperjob-1):
           if ifile>(numfiles-2):
               break
           ifile = ifile + 1
           input_files += (',\n    \'root://eoscms.cern.ch/' + filelist[ifile] + '\'')
       ifile = ifile + 1

       ## create input cfi file
       input_files_cfi = open(os.path.join(dataset_workdir,'input','inputFiles_' + str(ijob) + '_cfi.py'),'w')
       input_files_cfi.write(re.sub('INPUT_FILES',input_files,cfi_template))
       input_files_cfi.close()

       ## create Bash script
       bash_script = open(os.path.join(dataset_workdir,'input','job_' + str(ijob) + '.sh'),'w')
       bash_script_content = re.sub('MAIN_WORKDIR',main_workdir,bash_template)
       bash_script_content = re.sub('DATASET_WORKDIR',dataset_workdir,bash_script_content)
       bash_script_content = re.sub('JOB_NUMBER',str(ijob),bash_script_content)
       bash_script_content = re.sub('CFG_PARAMETERS',cfg_parameters,bash_script_content)
       bash_script_content = re.sub('OUTPUT_FILENAME',output_filename,bash_script_content)
       bash_script.write(bash_script_content)
       bash_script.close()

       if args.batch_option == 'condor':
         condor_script = open(os.path.join(dataset_workdir,'input','job_' + str(ijob) + '.condor'),'w')
         #condor_script_content = re.sub('EXEC',os.path.join(dataset_workdir,'input','job_' + str(ijob) + '.sh'),condor_template)
         condor_script_content = re.sub('EXEC','job_' + str(ijob) + '.sh',condor_template)
         condor_script_content = re.sub('JOB_NUMBER',str(ijob),condor_script_content)
         condor_script_content = re.sub('OUTPUT',os.path.join(dataset_workdir,'output'),condor_script_content)
         condor_script_content = re.sub('QUEUE',args.queue,condor_script_content)
         condor_script.write(condor_script_content)
         condor_script.close()

       if(not args.no_submission):
         if args.batch_option == 'lxbatch':
           cmd = 'bsub -q ' + args.queue + ' -o ' + os.path.join(dataset_workdir,'output','job_' + str(ijob) + '.log') + ' source ' + os.path.join(dataset_workdir,'input','job_' + str(ijob) + '.sh')
           os.system(cmd)
         elif args.batch_option == 'condor':
           os.chdir(os.path.join(dataset_workdir,'input'))
           cmd = 'condor_submit ' +  os.path.join(dataset_workdir,'output','job_' + str(ijob) + '.log') + ' source ' + os.path.join(dataset_workdir,'input','job_' + str(ijob) + '.condor')
           os.system(cmd)
           os.chdir(cfg_dirname)

  # close all open files
  dataset_list_file.close()


if __name__ == "__main__":
  main()
