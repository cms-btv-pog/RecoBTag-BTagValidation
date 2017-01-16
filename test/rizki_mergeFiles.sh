#!/bin/bash


## BTagMu + QCD MuEnriched 
#
# -Double 
#
mkdir Mu_250_noSlimmedTrees_combined
./combineOutput.py -w Mu_250_noSlimmedTrees -o Mu_250_noSlimmedTrees_combined

mkdir Mu_250_noSlimmedTrees_merged
./mergeDatasets.py -w Mu_250_noSlimmedTrees_combined -o Mu_250_noSlimmedTrees_merged -d rizki_datasetListForMerging_80x_BTagMu_QCDMuEnriched_mcJPCalib.txt
# 
mv -v Mu_250_noSlimmedTrees_merged/Final_histograms_btagval.root Mu_250_noSlimmedTrees_merged/Final_DoubleMuonTaggedFatJets_MuonEnrichedJets_dataWithMCJP_histograms_btagval.root

mkdir Mu_350_noSlimmedTrees_combined
./combineOutput.py -w Mu_350_noSlimmedTrees -o Mu_350_noSlimmedTrees_combined
# 
mkdir Mu_350_noSlimmedTrees_merged
./mergeDatasets.py -w Mu_350_noSlimmedTrees_combined -o Mu_350_noSlimmedTrees_merged -d rizki_datasetListForMerging_80x_BTagMu_QCDMuEnriched_mcJPCalib.txt
# 
mv -v Mu_350_noSlimmedTrees_merged/Final_histograms_btagval.root Mu_350_noSlimmedTrees_merged/Final_DoubleMuonTaggedFatJets_MuonEnrichedJets_dataWithMCJP_histograms_btagval.root

