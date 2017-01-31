#!/bin/bash


## BTagMu + QCD MuEnriched - nominal
#
# -Double 
#
mkdir Mu_250_noSlimmedTrees_combined
./combineOutput.py -w Mu_250_noSlimmedTrees -o Mu_250_noSlimmedTrees_combined

mkdir Mu_250_noSlimmedTrees_merged
./mergeDatasets.py -w Mu_250_noSlimmedTrees_combined -o Mu_250_noSlimmedTrees_merged -d rizki_datasetListForMerging_80x_BTagMu_QCDMuEnriched_mcJPCalib_pt250.txt

mv -v Mu_250_noSlimmedTrees_merged/Final_histograms_btagval.root Mu_250_noSlimmedTrees_merged/Final_DoubleMuonTaggedFatJets_MuonEnrichedJets_dataWithMCJP_histograms_btagval.root

mkdir Mu_350_noSlimmedTrees_combined
./combineOutput.py -w Mu_350_noSlimmedTrees -o Mu_350_noSlimmedTrees_combined

mkdir Mu_350_noSlimmedTrees_merged
./mergeDatasets.py -w Mu_350_noSlimmedTrees_combined -o Mu_350_noSlimmedTrees_merged -d rizki_datasetListForMerging_80x_BTagMu_QCDMuEnriched_mcJPCalib_pt350.txt

mv -v Mu_350_noSlimmedTrees_merged/Final_histograms_btagval.root Mu_350_noSlimmedTrees_merged/Final_DoubleMuonTaggedFatJets_MuonEnrichedJets_dataWithMCJP_histograms_btagval.root



## BTagMu + QCD MuEnriched - bfragdown
#
# -Double 
#
# mkdir Mu_250_noSlimmedTrees_bfragdown_combined
# ./combineOutput.py -w Mu_250_noSlimmedTrees_bfragdown -o Mu_250_noSlimmedTrees_bfragdown_combined
# 
# mkdir Mu_250_noSlimmedTrees_bfragdown_merged
# ./mergeDatasets.py -w Mu_250_noSlimmedTrees_bfragdown_combined -o Mu_250_noSlimmedTrees_bfragdown_merged -d rizki_datasetListForMerging_80x_BTagMu_QCDMuEnriched_mcJPCalib_pt250.txt
# 
# mv -v Mu_250_noSlimmedTrees_bfragdown_merged/Final_histograms_btagval.root Mu_250_noSlimmedTrees_bfragdown_merged/Final_DoubleMuonTaggedFatJets_MuonEnrichedJets_dataWithMCJP_histograms_btagval.root
# 
# mkdir Mu_350_noSlimmedTrees_bfragdown_combined
# ./combineOutput.py -w Mu_350_noSlimmedTrees_bfragdown -o Mu_350_noSlimmedTrees_bfragdown_combined
# 
# mkdir Mu_350_noSlimmedTrees_bfragdown_merged
# ./mergeDatasets.py -w Mu_350_noSlimmedTrees_bfragdown_combined -o Mu_350_noSlimmedTrees_bfragdown_merged -d rizki_datasetListForMerging_80x_BTagMu_QCDMuEnriched_mcJPCalib_pt350.txt
# 
# mv -v Mu_350_noSlimmedTrees_bfragdown_merged/Final_histograms_btagval.root Mu_350_noSlimmedTrees_bfragdown_merged/Final_DoubleMuonTaggedFatJets_MuonEnrichedJets_dataWithMCJP_histograms_btagval.root


## BTagMu + QCD MuEnriched - bfragup
#
# -Double 
#
# mkdir Mu_250_noSlimmedTrees_bfragup_combined
# ./combineOutput.py -w Mu_250_noSlimmedTrees_bfragup -o Mu_250_noSlimmedTrees_bfragup_combined
# 
# mkdir Mu_250_noSlimmedTrees_bfragup_merged
# ./mergeDatasets.py -w Mu_250_noSlimmedTrees_bfragup_combined -o Mu_250_noSlimmedTrees_bfragup_merged -d rizki_datasetListForMerging_80x_BTagMu_QCDMuEnriched_mcJPCalib_pt250.txt
# 
# mv -v Mu_250_noSlimmedTrees_bfragup_merged/Final_histograms_btagval.root Mu_250_noSlimmedTrees_bfragup_merged/Final_DoubleMuonTaggedFatJets_MuonEnrichedJets_dataWithMCJP_histograms_btagval.root
# 
# mkdir Mu_350_noSlimmedTrees_bfragup_combined
# ./combineOutput.py -w Mu_350_noSlimmedTrees_bfragup -o Mu_350_noSlimmedTrees_bfragup_combined
# 
# mkdir Mu_350_noSlimmedTrees_bfragup_merged
# ./mergeDatasets.py -w Mu_350_noSlimmedTrees_bfragup_combined -o Mu_350_noSlimmedTrees_bfragup_merged -d rizki_datasetListForMerging_80x_BTagMu_QCDMuEnriched_mcJPCalib_pt350.txt
# 
# mv -v Mu_350_noSlimmedTrees_bfragup_merged/Final_histograms_btagval.root Mu_350_noSlimmedTrees_bfragup_merged/Final_DoubleMuonTaggedFatJets_MuonEnrichedJets_dataWithMCJP_histograms_btagval.root



## BTagMu + QCD MuEnriched - CD
#
# -Double 
#
# mkdir Mu_250_noSlimmedTrees_CD_combined
# ./combineOutput.py -w Mu_250_noSlimmedTrees_CD -o Mu_250_noSlimmedTrees_CD_combined
# 
# mkdir Mu_250_noSlimmedTrees_CD_merged
# ./mergeDatasets.py -w Mu_250_noSlimmedTrees_CD_combined -o Mu_250_noSlimmedTrees_CD_merged -d rizki_datasetListForMerging_80x_BTagMu_QCDMuEnriched_mcJPCalib_pt250.txt
# 
# mv -v Mu_250_noSlimmedTrees_CD_merged/Final_histograms_btagval.root Mu_250_noSlimmedTrees_CD_merged/Final_DoubleMuonTaggedFatJets_MuonEnrichedJets_dataWithMCJP_histograms_btagval.root

# mkdir Mu_350_noSlimmedTrees_CD_combined
# ./combineOutput.py -w Mu_350_noSlimmedTrees_CD -o Mu_350_noSlimmedTrees_CD_combined
# 
# mkdir Mu_350_noSlimmedTrees_CD_merged
# ./mergeDatasets.py -w Mu_350_noSlimmedTrees_CD_combined -o Mu_350_noSlimmedTrees_CD_merged -d rizki_datasetListForMerging_80x_BTagMu_QCDMuEnriched_mcJPCalib_pt350.txt
# 
# mv -v Mu_350_noSlimmedTrees_CD_merged/Final_histograms_btagval.root Mu_350_noSlimmedTrees_CD_merged/Final_DoubleMuonTaggedFatJets_MuonEnrichedJets_dataWithMCJP_histograms_btagval.root



## BTagMu + QCD MuEnriched - cfrag
#
# -Double 
#
# mkdir Mu_250_noSlimmedTrees_cfrag_combined
# ./combineOutput.py -w Mu_250_noSlimmedTrees_cfrag -o Mu_250_noSlimmedTrees_cfrag_combined
# 
# mkdir Mu_250_noSlimmedTrees_cfrag_merged
# ./mergeDatasets.py -w Mu_250_noSlimmedTrees_cfrag_combined -o Mu_250_noSlimmedTrees_cfrag_merged -d rizki_datasetListForMerging_80x_BTagMu_QCDMuEnriched_mcJPCalib_pt250.txt
# 
# mv -v Mu_250_noSlimmedTrees_cfrag_merged/Final_histograms_btagval.root Mu_250_noSlimmedTrees_cfrag_merged/Final_DoubleMuonTaggedFatJets_MuonEnrichedJets_dataWithMCJP_histograms_btagval.root

# mkdir Mu_350_noSlimmedTrees_cfrag_combined
# ./combineOutput.py -w Mu_350_noSlimmedTrees_cfrag -o Mu_350_noSlimmedTrees_cfrag_combined
# 
# mkdir Mu_350_noSlimmedTrees_cfrag_merged
# ./mergeDatasets.py -w Mu_350_noSlimmedTrees_cfrag_combined -o Mu_350_noSlimmedTrees_cfrag_merged -d rizki_datasetListForMerging_80x_BTagMu_QCDMuEnriched_mcJPCalib_pt350.txt
# 
# mv -v Mu_350_noSlimmedTrees_cfrag_merged/Final_histograms_btagval.root Mu_350_noSlimmedTrees_cfrag_merged/Final_DoubleMuonTaggedFatJets_MuonEnrichedJets_dataWithMCJP_histograms_btagval.root



## BTagMu + QCD MuEnriched - K0L
#
# -Double 
#
# mkdir Mu_250_noSlimmedTrees_K0L_combined
# ./combineOutput.py -w Mu_250_noSlimmedTrees_K0L -o Mu_250_noSlimmedTrees_K0L_combined
# 
# mkdir Mu_250_noSlimmedTrees_K0L_merged
# ./mergeDatasets.py -w Mu_250_noSlimmedTrees_K0L_combined -o Mu_250_noSlimmedTrees_K0L_merged -d rizki_datasetListForMerging_80x_BTagMu_QCDMuEnriched_mcJPCalib_pt250.txt
# 
# mv -v Mu_250_noSlimmedTrees_K0L_merged/Final_histograms_btagval.root Mu_250_noSlimmedTrees_K0L_merged/Final_DoubleMuonTaggedFatJets_MuonEnrichedJets_dataWithMCJP_histograms_btagval.root

# mkdir Mu_350_noSlimmedTrees_K0L_combined
# ./combineOutput.py -w Mu_350_noSlimmedTrees_K0L -o Mu_350_noSlimmedTrees_K0L_combined
# 
# mkdir Mu_350_noSlimmedTrees_K0L_merged
# ./mergeDatasets.py -w Mu_350_noSlimmedTrees_K0L_combined -o Mu_350_noSlimmedTrees_K0L_merged -d rizki_datasetListForMerging_80x_BTagMu_QCDMuEnriched_mcJPCalib_pt350.txt
# 
# mv -v Mu_350_noSlimmedTrees_K0L_merged/Final_histograms_btagval.root Mu_350_noSlimmedTrees_K0L_merged/Final_DoubleMuonTaggedFatJets_MuonEnrichedJets_dataWithMCJP_histograms_btagval.root



## BTagMu + QCD MuEnriched - nTracks
#
# -Double 
#
# mkdir Mu_250_noSlimmedTrees_nTracks_combined
# ./combineOutput.py -w Mu_250_noSlimmedTrees_nTracks -o Mu_250_noSlimmedTrees_nTracks_combined
# 
# mkdir Mu_250_noSlimmedTrees_nTracks_merged
# ./mergeDatasets.py -w Mu_250_noSlimmedTrees_nTracks_combined -o Mu_250_noSlimmedTrees_nTracks_merged -d rizki_datasetListForMerging_80x_BTagMu_QCDMuEnriched_mcJPCalib_pt250.txt
# 
# mv -v Mu_250_noSlimmedTrees_nTracks_merged/Final_histograms_btagval.root Mu_250_noSlimmedTrees_nTracks_merged/Final_DoubleMuonTaggedFatJets_MuonEnrichedJets_dataWithMCJP_histograms_btagval.root
# 
# mkdir Mu_350_noSlimmedTrees_nTracks_combined
# ./combineOutput.py -w Mu_350_noSlimmedTrees_nTracks -o Mu_350_noSlimmedTrees_nTracks_combined
# 
# mkdir Mu_350_noSlimmedTrees_nTracks_merged
# ./mergeDatasets.py -w Mu_350_noSlimmedTrees_nTracks_combined -o Mu_350_noSlimmedTrees_nTracks_merged -d rizki_datasetListForMerging_80x_BTagMu_QCDMuEnriched_mcJPCalib_pt350.txt
# 
# mv -v Mu_350_noSlimmedTrees_nTracks_merged/Final_histograms_btagval.root Mu_350_noSlimmedTrees_nTracks_merged/Final_DoubleMuonTaggedFatJets_MuonEnrichedJets_dataWithMCJP_histograms_btagval.root



## BTagMu + QCD MuEnriched - puDown
#
# -Double 
#
# mkdir Mu_250_noSlimmedTrees_puDown_combined
# ./combineOutput.py -w Mu_250_noSlimmedTrees_puDown -o Mu_250_noSlimmedTrees_puDown_combined
# 
# mkdir Mu_250_noSlimmedTrees_puDown_merged
# ./mergeDatasets.py -w Mu_250_noSlimmedTrees_puDown_combined -o Mu_250_noSlimmedTrees_puDown_merged -d rizki_datasetListForMerging_80x_BTagMu_QCDMuEnriched_mcJPCalib_pt250.txt
# 
# mv -v Mu_250_noSlimmedTrees_puDown_merged/Final_histograms_btagval.root Mu_250_noSlimmedTrees_puDown_merged/Final_DoubleMuonTaggedFatJets_MuonEnrichedJets_dataWithMCJP_histograms_btagval.root
# 
# mkdir Mu_350_noSlimmedTrees_puDown_combined
# ./combineOutput.py -w Mu_350_noSlimmedTrees_puDown -o Mu_350_noSlimmedTrees_puDown_combined
# 
# mkdir Mu_350_noSlimmedTrees_puDown_merged
# ./mergeDatasets.py -w Mu_350_noSlimmedTrees_puDown_combined -o Mu_350_noSlimmedTrees_puDown_merged -d rizki_datasetListForMerging_80x_BTagMu_QCDMuEnriched_mcJPCalib_pt350.txt
# 
# mv -v Mu_350_noSlimmedTrees_puDown_merged/Final_histograms_btagval.root Mu_350_noSlimmedTrees_puDown_merged/Final_DoubleMuonTaggedFatJets_MuonEnrichedJets_dataWithMCJP_histograms_btagval.root



## BTagMu + QCD MuEnriched - puUp
#
# -Double 
#
# mkdir Mu_250_noSlimmedTrees_puUp_combined
# ./combineOutput.py -w Mu_250_noSlimmedTrees_puUp -o Mu_250_noSlimmedTrees_puUp_combined
# 
# mkdir Mu_250_noSlimmedTrees_puUp_merged
# ./mergeDatasets.py -w Mu_250_noSlimmedTrees_puUp_combined -o Mu_250_noSlimmedTrees_puUp_merged -d rizki_datasetListForMerging_80x_BTagMu_QCDMuEnriched_mcJPCalib_pt250.txt
# 
# mv -v Mu_250_noSlimmedTrees_puUp_merged/Final_histograms_btagval.root Mu_250_noSlimmedTrees_puUp_merged/Final_DoubleMuonTaggedFatJets_MuonEnrichedJets_dataWithMCJP_histograms_btagval.root
# 
# mkdir Mu_350_noSlimmedTrees_puUp_combined
# ./combineOutput.py -w Mu_350_noSlimmedTrees_puUp -o Mu_350_noSlimmedTrees_puUp_combined
# 
# mkdir Mu_350_noSlimmedTrees_puUp_merged
# ./mergeDatasets.py -w Mu_350_noSlimmedTrees_puUp_combined -o Mu_350_noSlimmedTrees_puUp_merged -d rizki_datasetListForMerging_80x_BTagMu_QCDMuEnriched_mcJPCalib_pt350.txt
# 
# mv -v Mu_350_noSlimmedTrees_puUp_merged/Final_histograms_btagval.root Mu_350_noSlimmedTrees_puUp_merged/Final_DoubleMuonTaggedFatJets_MuonEnrichedJets_dataWithMCJP_histograms_btagval.root
