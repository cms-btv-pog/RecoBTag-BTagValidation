#!/usr/bin/env python

import sys, os, subprocess, string, re, shutil
from optparse import OptionParser


# usage description
usage = """Usage: ./checkJobs.py [options]\n
Example: ./checkJobs.py -w LXBatch_Jobs\n
For more help: ./checkJobs.py  --help
"""

def main():

  # input parameters
  parser = OptionParser(usage=usage)

  parser.add_option("-w", "--main_workdir", dest="main_workdir",
                    help="Main working directory",
                    metavar="MAIN_WORKDIR")

  parser.add_option("-q", "--queue", dest="queue",
                    action='store', default='8nh',
                    help="LXBatch queue (choose among cmst3 8nm 1nh 8nh 1nd 1nw). Default is '8nh' (This parameter is optional)",
                    metavar="QUEUE")

  parser.add_option("-r", "--resubmit", dest="resubmit",
                    action='store_true', default=False,
                    help="Resubmit unfinished or failed jobs (This parameter is optional)")

  parser.add_option("-o", "--output_dir", dest="output_dir",
                    help="Output directory (This parameter is optional)",
                    metavar="eos_OUTPUT_DIR")

  (options, args) = parser.parse_args()

  # make sure all necessary input parameters are provided
  if not options.main_workdir:
    print usage
    sys.exit()

  main_workdir = options.main_workdir

  # redefine main_workdir as an absolute path (if not defined in such form already)
  if not re.search("^/", main_workdir):
    main_workdir = os.path.join(os.getcwd(),main_workdir)


  if not options.output_dir:
  	out_workdir = main_workdir
  	print 'out_workdir: ',out_workdir
  else:
  	out_workdir = options.output_dir
  	os.system('/afs/cern.ch/project/eos/installation/0.3.84-aquamarine/bin/eos.select -b fuse mount $HOME/eos')
  	print 'out_workdir: ',out_workdir


  # open and read the dataset_list file
  dataset_list_file = open(os.path.join(main_workdir,'datasetList.txt'),'r')
  dataset_list_lines = dataset_list_file.readlines()

  print 'Checking...', main_workdir

  # loop over datasets
  for line in dataset_list_lines:

    line_elements = line.split()
    if (len(line_elements)==0 or line_elements[0][0]=='#'): continue

    workdir = line_elements[0].lstrip('/').replace('/','__')

    print '------------------------------------------------------------------------------------'
    print line_elements[0]

    dataset_workdir = os.path.join(main_workdir,workdir)
    print 'checking input at: ',dataset_workdir
    dataset_workdir_output = dataset_workdir
    if options.output_dir:
    	dataset_workdir_output = os.path.join(out_workdir,options.main_workdir)
    	dataset_workdir_output = os.path.join(dataset_workdir_output,workdir)
    	#print 'dataset_workdir_output: ',dataset_workdir_output
    print 'checking output at: ',dataset_workdir_output

    all_jobs = []
    for filename in os.listdir(os.path.join(dataset_workdir,'input')):
        if( re.search('.sh$', filename) ):
            all_jobs.append(filename.split('.sh')[0].split('_')[-1])

    done_jobs = []
    for filename in os.listdir(os.path.join(dataset_workdir_output,'output')):
        if( re.search('.root$', filename) ):
            done_jobs.append(filename.split('.root')[0].split('_')[-1])

    failed_jobs = []
    for job in all_jobs:
        if job not in done_jobs:
            failed_jobs.append(job)

    if(len(failed_jobs)>0):
        print 'Unfinished or failed jobs:'
        failed_jobs.sort()
        print failed_jobs

        if(options.resubmit):
            print 'Resubmitting unfinished or failed jobs...'

            for job in failed_jobs:
                if os.path.exists(os.path.join(dataset_workdir,'output','job_' + job + '.log')):
                    shutil.copyfile(os.path.join(dataset_workdir,'output','job_' + job + '.log'),os.path.join(dataset_workdir,'output','job_' + job + '.log.old'))
                cmd = 'bsub -q ' + options.queue + ' -o ' + os.path.join(dataset_workdir,'output','job_' + job + '.log') + ' source ' + os.path.join(dataset_workdir,'input','job_' + job + '.sh')
                os.system(cmd)

            print 'Done'
    else:
        print 'No unfinished or failed jobs'

  if options.output_dir:
  	os.system('/afs/cern.ch/project/eos/installation/0.3.84-aquamarine/bin/eos.select -b fuse umount $HOME/eos')


if __name__ == "__main__":
  main()
