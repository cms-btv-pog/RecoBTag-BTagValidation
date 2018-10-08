import os
import sys
import importlib
import ROOT
from optparse import OptionParser


# usage description
usage = "Usage: python %prog [options] \nExample: python %prog -p SimGeneral/MixingModule/python/mix_2017_25ns_WinterMC_PUScenarioV1_PoissonOOTPU_cfi.py -o PUDistMC.root"

# input parameters
parser = OptionParser(usage=usage)

parser.add_option("-p", "--pu_config", dest="pu_config",
                  help="Pileup configuration file (This parameter is mandatory)",
                  metavar="PU_CONFIG")

parser.add_option("-o", "--output", dest="output",
                  help="Output file (This parameter is optional and set to 'PUDistMC.root' by default)",
                  default="PUDistMC.root",
                  metavar="OUTPUT")

(options, args) = parser.parse_args()

# make sure all necessary input parameters are provided
if not options.pu_config:
    print 'Mandatory parameter missing'
    print ''
    parser.print_help()
    sys.exit(1)

pu = options.pu_config.replace("python/","").replace(".py","").replace("/",".")

mod = importlib.import_module(pu, package=None)

probFunctionVariable = mod.mix.input.nbPileupEvents.probFunctionVariable
probValue = mod.mix.input.nbPileupEvents.probValue

hmc = ROOT.TH1D("pileup","MC pileup",len(probFunctionVariable),0.,float(len(probFunctionVariable)))
for i in range(len(probValue)):
  print "nPU prob :", probFunctionVariable[i], probValue[i]
  hmc.SetBinContent(probFunctionVariable[i], probValue[i])

fout = ROOT.TFile(options.output,"RECREATE")
fout.cd()
hmc.Write()
fout.Close()
