#!/bin/bash

echo "Testing Double Muon Tag"
cmsRun btagvalidation_cfg.py fatJetPtMin=350 applyFatJetMuonTagging=True fatJetDoubleTagging=True triggerSelection=HLT_BTagMu_Jet300_Mu5_v,HLT_BTagMu_AK8Jet300_Mu5_v useJetProbaTree=True useRelaxedMuonID=True doPUReweightingOfficial=True usePrunedMass=True useSoftDropSubjets=True fatJetTau21Min=0. fatJetTau21Max=1.0 fatJetGroomedMassMin=50. reportEvery=100 outFilename=bTagValPlots_Double_testRun.root

echo "Testing Single Muon Tag"
cmsRun btagvalidation_cfg.py fatJetPtMin=350 applyFatJetMuonTagging=True fatJetDoubleTagging=False triggerSelection=HLT_BTagMu_Jet300_Mu5_v,HLT_BTagMu_AK8Jet300_Mu5_v useJetProbaTree=True useRelaxedMuonID=False doPUReweightingOfficial=True usePrunedMass=True useSoftDropSubjets=True fatJetTau21Min=0. fatJetTau21Max=1.0 fatJetGroomedMassMin=50. reportEvery=100 outFilename=bTagValPlots_Single_testRun.root

