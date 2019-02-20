import sys, ROOT

sys.path.append('/cvmfs/cms.cern.ch/slc6_amd64_gcc630/cms/cmssw/CMSSW_10_2_7/src/')

from SimGeneral.MixingModule.mix_2018_25ns_JuneProjectionFull18_PoissonOOTPU_cfi import *

probFunctionVariable = mix.input.nbPileupEvents.probFunctionVariable

probValue = mix.input.nbPileupEvents.probValue

hmc = ROOT.TH1D("pileup","MC pileup",100,0.,100)
for ii in range(len(probValue)):
  print ii, " ", probFunctionVariable[ii], " ", probValue[ii]  
  hmc.Fill(probFunctionVariable[ii], probValue[ii]) 
 
fout = ROOT.TFile("PUDistMC_2018_25ns_JuneProjectionFull18_PoissonOOTPU.root","RECREATE")
fout.cd()
hmc.Write()
fout.Close()
