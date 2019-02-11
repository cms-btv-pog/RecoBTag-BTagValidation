#!/bin/bash


## BTagMu + QCD MuEnriched - nominal
#
# -Double 
#
# mkdir Mu_250_combined
# ./combineOutput.py -w Mu_250 -o Mu_250_combined
# 
# mkdir Mu_250_merged
# ./mergeDatasets.py -w Mu_250_combined -o Mu_250_merged -d rizki_datasetListForMerging_80x_BTagMu_QCDMuEnriched_mcJPCalib_pt250.txt
# 
# mv -v Mu_250_merged/Final_histograms_btagval.root Mu_250_merged/Final_DoubleMuonTaggedFatJets_MuonEnrichedJets_dataWithMCJP_histograms_btagval.root
# 
# mkdir Mu_350_combined
# ./combineOutput.py -w Mu_350 -o Mu_350_combined
# 
# mkdir Mu_350_merged
# ./mergeDatasets.py -w Mu_350_combined -o Mu_350_merged -d rizki_datasetListForMerging_80x_BTagMu_QCDMuEnriched_mcJPCalib_pt350.txt
# 
# mv -v Mu_350_merged/Final_histograms_btagval.root Mu_350_merged/Final_DoubleMuonTaggedFatJets_MuonEnrichedJets_dataWithMCJP_histograms_btagval.root


## BTagMu + QCD MuEnriched - ptReweighted
#
# -Double 
#
# mkdir Mu_250_ptReweighted_combined
# ./combineOutput.py -w Mu_250_ptReweighted -o Mu_250_ptReweighted_combined
./combineOutput_new.py -w Mu_250_ptReweighted -o Mu_250_ptReweighted_combined -e true --eospath /eos/cms/store/group/phys_btag/BoostedBTag/BTagNTuples/8_0_X_v2.03/BTagValJobs_rizki/

# 
# mkdir Mu_250_ptReweighted_merged
# ./mergeDatasets.py -w Mu_250_ptReweighted_combined -o Mu_250_ptReweighted_merged -d rizki_datasetListForMerging_80x_BTagMu_QCDMuEnriched_mcJPCalib_pt250.txt
# 
# mv -v Mu_250_ptReweighted_merged/Final_histograms_btagval.root Mu_250_ptReweighted_merged/Final_DoubleMuonTaggedFatJets_MuonEnrichedJets_dataWithMCJP_histograms_btagval.root
# 
# mkdir Mu_350_ptReweighted_combined
# ./combineOutput.py -w Mu_350_ptReweighted -o Mu_350_ptReweighted_combined
./combineOutput_new.py -w Mu_350_ptReweighted -o Mu_350_ptReweighted_combined -e true --eospath /eos/cms/store/group/phys_btag/BoostedBTag/BTagNTuples/8_0_X_v2.03/BTagValJobs_rizki/
# 
# mkdir Mu_350_ptReweighted_merged
# ./mergeDatasets.py -w Mu_350_ptReweighted_combined -o Mu_350_ptReweighted_merged -d rizki_datasetListForMerging_80x_BTagMu_QCDMuEnriched_mcJPCalib_pt350.txt
# 
# mv -v Mu_350_ptReweighted_merged/Final_histograms_btagval.root Mu_350_ptReweighted_merged/Final_DoubleMuonTaggedFatJets_MuonEnrichedJets_dataWithMCJP_histograms_btagval.root



## BTagMu + QCD MuEnriched - bfragdown
#
# -Double 
#
# mkdir Mu_250_bfragdown_combined
# ./combineOutput.py -w Mu_250_bfragdown -o Mu_250_bfragdown_combined
./combineOutput_new.py -w Mu_250_bfragdown -o Mu_250_bfragdown_combined -e true --eospath /eos/cms/store/group/phys_btag/BoostedBTag/BTagNTuples/8_0_X_v2.03/BTagValJobs_rizki/
# 
# mkdir Mu_250_bfragdown_merged
# ./mergeDatasets.py -w Mu_250_bfragdown_combined -o Mu_250_bfragdown_merged -d rizki_datasetListForMerging_80x_BTagMu_QCDMuEnriched_mcJPCalib_pt250.txt
# 
# mv -v Mu_250_bfragdown_merged/Final_histograms_btagval.root Mu_250_bfragdown_merged/Final_DoubleMuonTaggedFatJets_MuonEnrichedJets_dataWithMCJP_histograms_btagval.root
# 
# mkdir Mu_350_bfragdown_combined
# ./combineOutput.py -w Mu_350_bfragdown -o Mu_350_bfragdown_combined
./combineOutput_new.py -w Mu_350_bfragdown -o Mu_350_bfragdown_combined -e true --eospath /eos/cms/store/group/phys_btag/BoostedBTag/BTagNTuples/8_0_X_v2.03/BTagValJobs_rizki/
# 
# mkdir Mu_350_bfragdown_merged
# ./mergeDatasets.py -w Mu_350_bfragdown_combined -o Mu_350_bfragdown_merged -d rizki_datasetListForMerging_80x_BTagMu_QCDMuEnriched_mcJPCalib_pt350.txt
# 
# mv -v Mu_350_bfragdown_merged/Final_histograms_btagval.root Mu_350_bfragdown_merged/Final_DoubleMuonTaggedFatJets_MuonEnrichedJets_dataWithMCJP_histograms_btagval.root


## BTagMu + QCD MuEnriched - bfragup
#
# -Double 
#
# mkdir Mu_250_bfragup_combined
# ./combineOutput.py -w Mu_250_bfragup -o Mu_250_bfragup_combined
./combineOutput_new.py -w Mu_250_bfragup -o Mu_250_bfragup_combined -e true --eospath /eos/cms/store/group/phys_btag/BoostedBTag/BTagNTuples/8_0_X_v2.03/BTagValJobs_rizki/

# mkdir Mu_250_bfragup_merged
# ./mergeDatasets.py -w Mu_250_bfragup_combined -o Mu_250_bfragup_merged -d rizki_datasetListForMerging_80x_BTagMu_QCDMuEnriched_mcJPCalib_pt250.txt
# 
# mv -v Mu_250_bfragup_merged/Final_histograms_btagval.root Mu_250_bfragup_merged/Final_DoubleMuonTaggedFatJets_MuonEnrichedJets_dataWithMCJP_histograms_btagval.root
# 
# mkdir Mu_350_bfragup_combined
# ./combineOutput.py -w Mu_350_bfragup -o Mu_350_bfragup_combined
#---> need to rerun? ./combineOutput_new.py -w Mu_350_bfragup -o Mu_350_bfragup_combined -e true --eospath /eos/cms/store/group/phys_btag/BoostedBTag/BTagNTuples/8_0_X_v2.03/BTagValJobs_rizki/
# 
# mkdir Mu_350_bfragup_merged
# ./mergeDatasets.py -w Mu_350_bfragup_combined -o Mu_350_bfragup_merged -d rizki_datasetListForMerging_80x_BTagMu_QCDMuEnriched_mcJPCalib_pt350.txt
# 
# mv -v Mu_350_bfragup_merged/Final_histograms_btagval.root Mu_350_bfragup_merged/Final_DoubleMuonTaggedFatJets_MuonEnrichedJets_dataWithMCJP_histograms_btagval.root



## BTagMu + QCD MuEnriched - CD
#
# -Double 
#
# mkdir Mu_250_CD_combined
# ./combineOutput.py -w Mu_250_CD -o Mu_250_CD_combined
./combineOutput_new.py -w Mu_250_CD -o Mu_250_CD_combined -e true --eospath /eos/cms/store/group/phys_btag/BoostedBTag/BTagNTuples/8_0_X_v2.03/BTagValJobs_rizki/

# mkdir Mu_250_CD_merged
# ./mergeDatasets.py -w Mu_250_CD_combined -o Mu_250_CD_merged -d rizki_datasetListForMerging_80x_BTagMu_QCDMuEnriched_mcJPCalib_pt250.txt
# 
# mv -v Mu_250_CD_merged/Final_histograms_btagval.root Mu_250_CD_merged/Final_DoubleMuonTaggedFatJets_MuonEnrichedJets_dataWithMCJP_histograms_btagval.root

# mkdir Mu_350_CD_combined
# ./combineOutput.py -w Mu_350_CD -o Mu_350_CD_combined
./combineOutput_new.py -w Mu_350_CD -o Mu_350_CD_combined -e true --eospath /eos/cms/store/group/phys_btag/BoostedBTag/BTagNTuples/8_0_X_v2.03/BTagValJobs_rizki/

# mkdir Mu_350_CD_merged
# ./mergeDatasets.py -w Mu_350_CD_combined -o Mu_350_CD_merged -d rizki_datasetListForMerging_80x_BTagMu_QCDMuEnriched_mcJPCalib_pt350.txt
# 
# mv -v Mu_350_CD_merged/Final_histograms_btagval.root Mu_350_CD_merged/Final_DoubleMuonTaggedFatJets_MuonEnrichedJets_dataWithMCJP_histograms_btagval.root



## BTagMu + QCD MuEnriched - cfrag
#
# -Double 
#
# mkdir Mu_250_cfrag_combined
# ./combineOutput.py -w Mu_250_cfrag -o Mu_250_cfrag_combined
./combineOutput_new.py -w Mu_250_cfrag -o Mu_250_cfrag_combined -e true --eospath /eos/cms/store/group/phys_btag/BoostedBTag/BTagNTuples/8_0_X_v2.03/BTagValJobs_rizki/

# mkdir Mu_250_cfrag_merged
# ./mergeDatasets.py -w Mu_250_cfrag_combined -o Mu_250_cfrag_merged -d rizki_datasetListForMerging_80x_BTagMu_QCDMuEnriched_mcJPCalib_pt250.txt
# 
# mv -v Mu_250_cfrag_merged/Final_histograms_btagval.root Mu_250_cfrag_merged/Final_DoubleMuonTaggedFatJets_MuonEnrichedJets_dataWithMCJP_histograms_btagval.root

# mkdir Mu_350_cfrag_combined
# ./combineOutput.py -w Mu_350_cfrag -o Mu_350_cfrag_combined
./combineOutput_new.py -w Mu_350_cfrag -o Mu_350_cfrag_combined -e true --eospath /eos/cms/store/group/phys_btag/BoostedBTag/BTagNTuples/8_0_X_v2.03/BTagValJobs_rizki/

# mkdir Mu_350_cfrag_merged
# ./mergeDatasets.py -w Mu_350_cfrag_combined -o Mu_350_cfrag_merged -d rizki_datasetListForMerging_80x_BTagMu_QCDMuEnriched_mcJPCalib_pt350.txt
# 
# mv -v Mu_350_cfrag_merged/Final_histograms_btagval.root Mu_350_cfrag_merged/Final_DoubleMuonTaggedFatJets_MuonEnrichedJets_dataWithMCJP_histograms_btagval.root



## BTagMu + QCD MuEnriched - K0L
#
# -Double 
#
# mkdir Mu_250_K0L_combined
# ./combineOutput.py -w Mu_250_K0L -o Mu_250_K0L_combined
./combineOutput_new.py -w Mu_250_K0L -o Mu_250_K0L_combined -e true --eospath /eos/cms/store/group/phys_btag/BoostedBTag/BTagNTuples/8_0_X_v2.03/BTagValJobs_rizki/

# mkdir Mu_250_K0L_merged
# ./mergeDatasets.py -w Mu_250_K0L_combined -o Mu_250_K0L_merged -d rizki_datasetListForMerging_80x_BTagMu_QCDMuEnriched_mcJPCalib_pt250.txt
# 
# mv -v Mu_250_K0L_merged/Final_histograms_btagval.root Mu_250_K0L_merged/Final_DoubleMuonTaggedFatJets_MuonEnrichedJets_dataWithMCJP_histograms_btagval.root

# mkdir Mu_350_K0L_combined
# ./combineOutput.py -w Mu_350_K0L -o Mu_350_K0L_combined
./combineOutput_new.py -w Mu_350_K0L -o Mu_350_K0L_combined -e true --eospath /eos/cms/store/group/phys_btag/BoostedBTag/BTagNTuples/8_0_X_v2.03/BTagValJobs_rizki/

# mkdir Mu_350_K0L_merged
# ./mergeDatasets.py -w Mu_350_K0L_combined -o Mu_350_K0L_merged -d rizki_datasetListForMerging_80x_BTagMu_QCDMuEnriched_mcJPCalib_pt350.txt
# 
# mv -v Mu_350_K0L_merged/Final_histograms_btagval.root Mu_350_K0L_merged/Final_DoubleMuonTaggedFatJets_MuonEnrichedJets_dataWithMCJP_histograms_btagval.root



## BTagMu + QCD MuEnriched - nTracks
#
# -Double 
#
# mkdir Mu_250_nTracks_combined
# ./combineOutput.py -w Mu_250_nTracks -o Mu_250_nTracks_combined
./combineOutput_new.py -w Mu_250_nTracks -o Mu_250_nTracks_combined -e true --eospath /eos/cms/store/group/phys_btag/BoostedBTag/BTagNTuples/8_0_X_v2.03/BTagValJobs_rizki/

# mkdir Mu_250_nTracks_merged
# ./mergeDatasets.py -w Mu_250_nTracks_combined -o Mu_250_nTracks_merged -d rizki_datasetListForMerging_80x_BTagMu_QCDMuEnriched_mcJPCalib_pt250.txt
# 
# mv -v Mu_250_nTracks_merged/Final_histograms_btagval.root Mu_250_nTracks_merged/Final_DoubleMuonTaggedFatJets_MuonEnrichedJets_dataWithMCJP_histograms_btagval.root
# 
# mkdir Mu_350_nTracks_combined
# ./combineOutput.py -w Mu_350_nTracks -o Mu_350_nTracks_combined
./combineOutput_new.py -w Mu_350_nTracks -o Mu_350_nTracks_combined -e true --eospath /eos/cms/store/group/phys_btag/BoostedBTag/BTagNTuples/8_0_X_v2.03/BTagValJobs_rizki/

# mkdir Mu_350_nTracks_merged
# ./mergeDatasets.py -w Mu_350_nTracks_combined -o Mu_350_nTracks_merged -d rizki_datasetListForMerging_80x_BTagMu_QCDMuEnriched_mcJPCalib_pt350.txt
# 
# mv -v Mu_350_nTracks_merged/Final_histograms_btagval.root Mu_350_nTracks_merged/Final_DoubleMuonTaggedFatJets_MuonEnrichedJets_dataWithMCJP_histograms_btagval.root



## BTagMu + QCD MuEnriched - puDown
#
# -Double 
#
# mkdir Mu_250_puDown_combined
# ./combineOutput.py -w Mu_250_puDown -o Mu_250_puDown_combined
./combineOutput_new.py -w Mu_250_puDown -o Mu_250_puDown_combined -e true --eospath /eos/cms/store/group/phys_btag/BoostedBTag/BTagNTuples/8_0_X_v2.03/BTagValJobs_rizki/

# mkdir Mu_250_puDown_merged
# ./mergeDatasets.py -w Mu_250_puDown_combined -o Mu_250_puDown_merged -d rizki_datasetListForMerging_80x_BTagMu_QCDMuEnriched_mcJPCalib_pt250.txt
# 
# mv -v Mu_250_puDown_merged/Final_histograms_btagval.root Mu_250_puDown_merged/Final_DoubleMuonTaggedFatJets_MuonEnrichedJets_dataWithMCJP_histograms_btagval.root
# 
# mkdir Mu_350_puDown_combined
# ./combineOutput.py -w Mu_350_puDown -o Mu_350_puDown_combined
./combineOutput_new.py -w Mu_350_puDown -o Mu_350_puDown_combined -e true --eospath /eos/cms/store/group/phys_btag/BoostedBTag/BTagNTuples/8_0_X_v2.03/BTagValJobs_rizki/

# mkdir Mu_350_puDown_merged
# ./mergeDatasets.py -w Mu_350_puDown_combined -o Mu_350_puDown_merged -d rizki_datasetListForMerging_80x_BTagMu_QCDMuEnriched_mcJPCalib_pt350.txt
# 
# mv -v Mu_350_puDown_merged/Final_histograms_btagval.root Mu_350_puDown_merged/Final_DoubleMuonTaggedFatJets_MuonEnrichedJets_dataWithMCJP_histograms_btagval.root



## BTagMu + QCD MuEnriched - puUp
#
# -Double 
#
# mkdir Mu_250_puUp_combined
# ./combineOutput.py -w Mu_250_puUp -o Mu_250_puUp_combined
#-->not run properly ./combineOutput_new.py -w Mu_250_puUp -o Mu_250_puUp_combined -e true --eospath /eos/cms/store/group/phys_btag/BoostedBTag/BTagNTuples/8_0_X_v2.03/BTagValJobs_rizki/
# 
# mkdir Mu_250_puUp_merged
# ./mergeDatasets.py -w Mu_250_puUp_combined -o Mu_250_puUp_merged -d rizki_datasetListForMerging_80x_BTagMu_QCDMuEnriched_mcJPCalib_pt250.txt
# 
# mv -v Mu_250_puUp_merged/Final_histograms_btagval.root Mu_250_puUp_merged/Final_DoubleMuonTaggedFatJets_MuonEnrichedJets_dataWithMCJP_histograms_btagval.root
# 
# mkdir Mu_350_puUp_combined
# ./combineOutput.py -w Mu_350_puUp -o Mu_350_puUp_combined
./combineOutput_new.py -w Mu_350_puUp -o Mu_350_puUp_combined -e true --eospath /eos/cms/store/group/phys_btag/BoostedBTag/BTagNTuples/8_0_X_v2.03/BTagValJobs_rizki/

# mkdir Mu_350_puUp_merged
# ./mergeDatasets.py -w Mu_350_puUp_combined -o Mu_350_puUp_merged -d rizki_datasetListForMerging_80x_BTagMu_QCDMuEnriched_mcJPCalib_pt350.txt
# 
# mv -v Mu_350_puUp_merged/Final_histograms_btagval.root Mu_350_puUp_merged/Final_DoubleMuonTaggedFatJets_MuonEnrichedJets_dataWithMCJP_histograms_btagval.root



## BTagMu + QCD MuEnriched - dataJPcalib
#
# -Double 
#
# mkdir Mu_250_dataJPcalib_combined
# ./combineOutput.py -w Mu_250_dataJPcalib -o Mu_250_dataJPcalib_combined
# ./combineOutput_new.py -w Mu_250_dataJPcalib -o Mu_250_dataJPcalib_combined -e true --eospath /eos/cms/store/group/phys_btag/BoostedBTag/BTagNTuples/8_0_X_v2.03/BTagValJobs_rizki/
# 
# mkdir Mu_250_dataJPcalib_merged
# ./mergeDatasets.py -w Mu_250_dataJPcalib_combined -o Mu_250_dataJPcalib_merged -d rizki_datasetListForMerging_80x_BTagMu_QCDMuEnriched_mcJPCalib_pt250_dataJPcalib.txt
# 
# mv -v Mu_250_dataJPcalib_merged/Final_histograms_btagval.root Mu_250_dataJPcalib_merged/Final_DoubleMuonTaggedFatJets_MuonEnrichedJets_dataWithDATAJP_histograms_btagval.root

# mkdir Mu_350_dataJPcalib_combined
# ./combineOutput.py -w Mu_350_dataJPcalib -o Mu_350_dataJPcalib_combined
# ./combineOutput_new.py -w Mu_350_dataJPcalib -o Mu_350_dataJPcalib_combined -e true --eospath /eos/cms/store/group/phys_btag/BoostedBTag/BTagNTuples/8_0_X_v2.03/BTagValJobs_rizki/
# 
# mkdir Mu_350_dataJPcalib_merged
# ./mergeDatasets.py -w Mu_350_dataJPcalib_combined -o Mu_350_dataJPcalib_merged -d rizki_datasetListForMerging_80x_BTagMu_QCDMuEnriched_mcJPCalib_pt350_dataJPcalib.txt
# 
# mv -v Mu_350_dataJPcalib_merged/Final_histograms_btagval.root Mu_350_dataJPcalib_merged/Final_DoubleMuonTaggedFatJets_MuonEnrichedJets_dataWithDATAJP_histograms_btagval.root



## BTagMu + QCD MuEnriched - run2016BtoF
#
# -Double 
#
# mkdir Mu_250_run2016BtoF_combined
# ./combineOutput.py -w Mu_250_run2016BtoF -o Mu_250_run2016BtoF_combined
# 
# mkdir Mu_250_run2016BtoF_merged
# ./mergeDatasets.py -w Mu_250_run2016BtoF_combined -o Mu_250_run2016BtoF_merged -d rizki_datasetListForMerging_80x_BTagMu_QCDMuEnriched_mcJPCalib_pt250_run2016BtoF.txt
# 
# mv -v Mu_250_run2016BtoF_merged/Final_histograms_btagval.root Mu_250_run2016BtoF_merged/Final_DoubleMuonTaggedFatJets_MuonEnrichedJets_dataWithMCJP_histograms_btagval.root

# mkdir Mu_350_run2016BtoF_combined
# ./combineOutput.py -w Mu_350_run2016BtoF -o Mu_350_run2016BtoF_combined
# 
# mkdir Mu_350_run2016BtoF_merged
# ./mergeDatasets.py -w Mu_350_run2016BtoF_combined -o Mu_350_run2016BtoF_merged -d rizki_datasetListForMerging_80x_BTagMu_QCDMuEnriched_mcJPCalib_pt350_run2016BtoF.txt
# 
# mv -v Mu_350_run2016BtoF_merged/Final_histograms_btagval.root Mu_350_run2016BtoF_merged/Final_DoubleMuonTaggedFatJets_MuonEnrichedJets_dataWithMCJP_histograms_btagval.root
