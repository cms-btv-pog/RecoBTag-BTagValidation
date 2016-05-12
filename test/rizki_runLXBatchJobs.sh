#!/bin/bash

./createAndSubmitJobs.py -w rizki_LXBatch_QCDMuEnriched_useSoftDrop_fjpt425_50m_DoubleMuTag_Zratio_reweight -c btagvalidation_cfg.py -d alice_datasetList_LxplusJob_Zratio76x_reweight.txt -q cmscaf1nh
./createAndSubmitJobs.py -w rizki_LXBatch_QCDMuEnriched_useSoftDrop_fjpt425_50m_DoubleMuTag_SV1EnergyRatio_Zratio_reweight -c btagvalidation_cfg.py -d alice_datasetList_LxplusJob_SV1EnergyRatio76x_Zratio76x_reweight.txt -q cmscaf1nh
# 
# ./createAndSubmitJobs.py -w rizki_LXBatch_QCDMuEnriched_usePruned_fjpt425_50m_SingleMuTag_TightMu_SV1EnergyRatio_reweight -c btagvalidation_cfg.py -d alice_datasetList_LxplusJob_76x_SingleMuTag_TightMu_Pruned_SV1EnergyRatio76x_reweight.txt -q cmscaf1nh
./createAndSubmitJobs.py -w rizki_LXBatch_QCDMuEnriched_usePruned_fjpt425_50m_SingleMuTag_TightMu_Zratio_reweight -c btagvalidation_cfg.py -d alice_datasetList_LxplusJob_76x_SingleMuTag_TightMu_Pruned_Zratio76x_reweight.txt -q cmscaf1nh
./createAndSubmitJobs.py -w rizki_LXBatch_QCDMuEnriched_usePruned_fjpt425_50m_SingleMuTag_TightMu_SV1EnergyRatio_Zratio_reweight -c btagvalidation_cfg.py -d alice_datasetList_LxplusJob_76x_SingleMuTag_TightMu_Pruned_SV1EnergyRatio76x_Zratio76x_reweight.txt -q cmscaf1nh


# ./createAndSubmitJobs.py -w rizki_LXBatch_QCDMuEnriched_usePruned_fjpt425_50m_SingleMuTag_TightMu -c btagvalidation_cfg.py -d alice_datasetList_LxplusJob_76x_SingleMuTag_TightMu_Pruned.txt -q cmscaf1nh

# ./createAndSubmitJobs.py -w rizki_LXBatch_BulkGravTohhTohbbhbb_narrow_M-1000_usePruned_fjpt425_50m_SingleMuTag_TightMu_signal -c btagvalidation_cfg.py -d alice_datasetList_LxplusJob_76x_SingleMuTag_TightMu_Pruned_signal.txt -q cmscaf1nh


#./createAndSubmitJobs.py -w rizki_LXBatch_QCDMuEnriched_useSoftDrop_fjpt425_50m_DoubleMuTag_IPSig1stAboveB_reweight -c btagvalidation_cfg.py -d alice_datasetList_LxplusJob_IPSig1stAboveB76x_reweight.txt -q cmscaf1nh


# ./createAndSubmitJobs.py -w rizki_LXBatch_QCDMuEnriched_useSoftDrop_fjpt425_50m_DoubleMuTag_SV1EnergyRatio_jetNTracks_reweight -c btagvalidation_cfg.py -d alice_datasetList_LxplusJob_SV1EnergyRatio76x_jetNTracks76x_reweight.txt -q cmscaf1nh

# ./createAndSubmitJobs.py -w rizki_LXBatch_QCDMuEnriched_useSoftDrop_fjpt425_50m_DoubleMuTag_SV1EnergyRatio_reweight -c btagvalidation_cfg.py -d alice_datasetList_LxplusJob_SV1EnergyRatio76x_reweight.txt -q cmscaf1nh

# ./createAndSubmitJobs.py -w rizki_LXBatch_QCDMuEnriched_useSoftDrop_fjpt425_50m_DoubleMuTag_jetNTracks_reweight -c btagvalidation_cfg.py -d alice_datasetList_LxplusJob_jetNTracks76x_reweight.txt -q cmscaf1nh

# ./createAndSubmitJobs.py -w rizki_LXBatch_QCDMuEnriched_useSoftDrop_fjpt425_50m_DoubleMuTag_massSoftDrop_reweight -c btagvalidation_cfg.py -d alice_datasetList_LxplusJob_massSoftDrop76x_reweight.txt -q cmscaf1nh

# ./createAndSubmitJobs.py -w rizki_LXBatch_QCDMuEnriched_useSoftDrop_fjpt425_50m_DoubleMuTag_reweight -c btagvalidation_cfg.py -d alice_datasetList_LxplusJob_subjetPtBalance76x_reweight.txt -q cmscaf1nh


# ./createAndSubmitJobs.py -w rizki_LXBatch_BulkGravTohhTohbbhbb_narrow_M-1000_useSoftDrop_fjpt425_50m_DoubleMuTag -c btagvalidation_cfg.py -d alice_datasetList_LxplusJob_subjetPtBalance76x_signal.txt -q cmscaf1nh
# 
# ./createAndSubmitJobs.py -w rizki_LXBatch_QCDMuEnriched_useSoftDrop_fjpt425_50m_DoubleMuTag -c btagvalidation_cfg.py -d alice_datasetList_LxplusJob_subjetPtBalance76x.txt -q cmscaf1nh

#./createAndSubmitJobs.py -w rizki_LXBatch_BoostedTaggerValidation_cutFlow_BTagMu_QCDMuEnriched_usePruned_fjpt330_eta2p4_DoubleMuTag_50m200_reweightPT -c btagvalidation_cfg.py -d rizki_datasetList_BoostedTaggerValidation_cutFlow_BTagMu_QCDMuEnriched_usePruned_fjpt330_eta2p4_DoubleMuTag_m50to200_reweightPT.txt -q cmscaf1nh

#./createAndSubmitJobs.py -w alice_LXBatch_Templates_Double_Xtra -c btagvalidation_cfg.py -d alice_doubleperformance76X.txt -q 1nd

#./createAndSubmitJobs.py -w alice_LXBatch_Templates_Single_Xtra -c btagvalidation_cfg.py -d alice_performance76X.txt -q 1nd

#./createAndSubmitJobs.py -w alice_LXBatch_Templates_Double_PU_down_300 -c btagvalidation_down_cfg.py -d alice_doubleperformance76X_300.txt -q 1nd
#./createAndSubmitJobs.py -w alice_LXBatch_Templates_Double_PU_down_310 -c btagvalidation_down_cfg.py -d alice_doubleperformance76X_310.txt -q 1nd
#./createAndSubmitJobs.py -w alice_LXBatch_Templates_Double_PU_down_360 -c btagvalidation_down_cfg.py -d alice_doubleperformance76X_360.txt -q 1nd
#./createAndSubmitJobs.py -w alice_LXBatch_Templates_Double_PU_down_450 -c btagvalidation_down_cfg.py -d alice_doubleperformance76X_450.txt -q 1nd

#./createAndSubmitJobs.py -w alice_LXBatch_Templates_Double_bfragbd_300 -c btagvalidation_cfg.py -d alice_doubleperformance76X_300_bd.txt -q 1nd
#./createAndSubmitJobs.py -w alice_LXBatch_Templates_Double_bfragbd_310 -c btagvalidation_cfg.py -d alice_doubleperformance76X_310_bd.txt -q 1nd
./createAndSubmitJobs.py -w alice_LXBatch_Templates_Double_bfragbd_360 -c btagvalidation_cfg.py -d alice_doubleperformance76X_360_bd.txt -q 1nd
#./createAndSubmitJobs.py -w alice_LXBatch_Templates_Double_bfragbd_450 -c btagvalidation_cfg.py -d alice_doubleperformance76X_450_bd.txt -q 1nd

#./createAndSubmitJobs.py -w alice_LXBatch_Templates_Double_CD_300 -c btagvalidation_cfg.py -d alice_doubleperformance76X_CD_300.txt -q 1nd
#./createAndSubmitJobs.py -w alice_LXBatch_Templates_Double_CD_310 -c btagvalidation_cfg.py -d alice_doubleperformance76X_CD_310.txt -q 1nd
#./createAndSubmitJobs.py -w alice_LXBatch_Templates_Double_CD_360 -c btagvalidation_cfg.py -d alice_doubleperformance76X_CD_360.txt -q 1nd
#./createAndSubmitJobs.py -w alice_LXBatch_Templates_Double_CD_450 -c btagvalidation_cfg.py -d alice_doubleperformance76X_CD_450.txt -q 1nd

#./createAndSubmitJobs.py -w alice_LXBatch_Templates_Double_C_300 -c btagvalidation_cfg.py -d alice_doubleperformance76X_C_300.txt -q 1nd
#./createAndSubmitJobs.py -w alice_LXBatch_Templates_Double_C_310 -c btagvalidation_cfg.py -d alice_doubleperformance76X_C_310.txt -q 1nd
#./createAndSubmitJobs.py -w alice_LXBatch_Templates_Double_C_360 -c btagvalidation_cfg.py -d alice_doubleperformance76X_C_360.txt -q 1nd
#./createAndSubmitJobs.py -w alice_LXBatch_Templates_Double_C_450 -c btagvalidation_cfg.py -d alice_doubleperformance76X_C_450.txt -q 1nd

#./createAndSubmitJobs.py -w alice_LXBatch_Templates_Double_K0L_300 -c btagvalidation_cfg.py -d alice_doubleperformance76X_K0L_300.txt -q 1nd
#./createAndSubmitJobs.py -w alice_LXBatch_Templates_Double_K0L_310 -c btagvalidation_cfg.py -d alice_doubleperformance76X_K0L_310.txt -q 1nd
#./createAndSubmitJobs.py -w alice_LXBatch_Templates_Double_K0L_360 -c btagvalidation_cfg.py -d alice_doubleperformance76X_K0L_360.txt -q 1nd
#./createAndSubmitJobs.py -w alice_LXBatch_Templates_Double_K0L_450 -c btagvalidation_cfg.py -d alice_doubleperformance76X_K0L_450.txt -q 1nd

#./createAndSubmitJobs.py -w alice_LXBatch_Templates_Single_back_300 -c btagvalidation_cfg.py -d alice_doubleperformance76X_300_SingleMu.txt -q 1nd

#./createAndSubmitJobs.py -w alice_LXBatch_Templates_Single_back_310 -c btagvalidation_cfg.py -d alice_doubleperformance76X_310_SingleMu.txt -q 1nd

#./createAndSubmitJobs.py -w alice_LXBatch_Templates_Single_back_360 -c btagvalidation_cfg.py -d alice_doubleperformance76X_360_SingleMu.txt -q 1nd

#./createAndSubmitJobs.py -w alice_LXBatch_Templates_Single_back_450 -c btagvalidation_cfg.py -d alice_doubleperformance76X_450_SingleMu.txt -q 1nd

#./createAndSubmitJobs.py -w alice_LXBatch_Templates_Single_ntracks_300 -c btagvalidation_cfg.py -d alice_performance76X_300.txt -q 1nd

#./createAndSubmitJobs.py -w alice_LXBatch_Templates_Single_ntracks_310 -c btagvalidation_cfg.py -d alice_performance76X_310.txt -q 1nd

#./createAndSubmitJobs.py -w alice_LXBatch_Templates_Single_ntracks_360 -c btagvalidation_cfg.py -d alice_performance76X_360.txt -q 1nd

#./createAndSubmitJobs.py -w alice_LXBatch_Templates_Single_ntracks_450 -c btagvalidation_cfg.py -d alice_performance76X_450.txt -q 1nd

#./createAndSubmitJobs.py -w alice_LXBatch_Templates_Single_MuonTight0p25 -c btagvalidation_cfg.py -d alice_performance76X.txt -q 1nd  

# ./createAndSubmitJobs.py -w rizki_LXBatch_BoostedTaggerValidation_cutFlow_usePruned_fjpt450_eta2p4_DoubleMuTag_50m200_tau0p5 -c btagvalidation_cfg.py -d rizki_datasetList_BoostedTaggerValidation_cutFlow_usePruned_fjpt450_eta2p4_DoubleMuTag_m50to200_tau0p5.txt -q cmscaf1nh
# ./createAndSubmitJobs.py -w rizki_LXBatch_BoostedTaggerValidation_cutFlow_usePruned_fjpt450_eta2p4_DoubleMuTag_50m200_tau0p7 -c btagvalidation_cfg.py -d rizki_datasetList_BoostedTaggerValidation_cutFlow_usePruned_fjpt450_eta2p4_DoubleMuTag_m50to200_tau0p7.txt -q cmscaf1nh
# ./createAndSubmitJobs.py -w rizki_LXBatch_BoostedTaggerValidation_cutFlow_usePruned_fjpt450_eta2p4_DoubleMuTag_50m200 -c btagvalidation_cfg.py -d rizki_datasetList_BoostedTaggerValidation_cutFlow_usePruned_fjpt450_eta2p4_DoubleMuTag_m50to200.txt -q cmscaf1nh
# ./createAndSubmitJobs.py -w rizki_LXBatch_BoostedTaggerValidation_cutFlow_usePruned_fjpt450_eta2p4_DoubleMuTag -c btagvalidation_cfg.py -d rizki_datasetList_BoostedTaggerValidation_cutFlow_usePruned_fjpt450_eta2p4_DoubleMuTag.txt -q cmscaf1nh
# ./createAndSubmitJobs.py -w rizki_LXBatch_BoostedTaggerValidation_cutFlow_usePruned_fjpt450_eta2p4_SingleMuTag -c btagvalidation_cfg.py -d rizki_datasetList_BoostedTaggerValidation_cutFlow_usePruned_fjpt450_eta2p4_SingleMuTag.txt -q cmscaf1nh
# ./createAndSubmitJobs.py -w rizki_LXBatch_BoostedTaggerValidation_cutFlow_usePruned_fjpt450_eta2p4 -c btagvalidation_cfg.py -d rizki_datasetList_BoostedTaggerValidation_cutFlow_usePruned_fjpt450_eta2p4.txt -q cmscaf1nh
# ./createAndSubmitJobs.py -w rizki_LXBatch_BoostedTaggerValidation_cutFlow_usePruned_fjpt450 -c btagvalidation_cfg.py -d rizki_datasetList_BoostedTaggerValidation_cutFlow_usePruned_fjpt450.txt -q cmscaf1nh
# ./createAndSubmitJobs.py -w rizki_LXBatch_BoostedTaggerValidation_cutFlow_usePruned -c btagvalidation_cfg.py -d rizki_datasetList_BoostedTaggerValidation_cutFlow_usePruned.txt -q cmscaf1nh
# 
# ./createAndSubmitJobs.py -w rizki_LXBatch_BoostedTaggerValidation_cutFlow_BTagMu_QCDMuEnriched_usePruned_fjpt330_eta2p4_SingleMuTag -c btagvalidation_cfg.py -d rizki_datasetList_BoostedTaggerValidation_cutFlow_BTagMu_QCDMuEnriched_usePruned_fjpt330_eta2p4_SingleMuTag.txt -q cmscaf1nh
# ./createAndSubmitJobs.py -w rizki_LXBatch_BoostedTaggerValidation_cutFlow_BTagMu_QCDMuEnriched_usePruned_fjpt330_eta2p4_DoubleMuTag -c btagvalidation_cfg.py -d rizki_datasetList_BoostedTaggerValidation_cutFlow_BTagMu_QCDMuEnriched_usePruned_fjpt330_eta2p4_DoubleMuTag.txt -q cmscaf1nh
# ./createAndSubmitJobs.py -w rizki_LXBatch_BoostedTaggerValidation_cutFlow_BTagMu_QCDMuEnriched_usePruned_fjpt330_eta2p4_DoubleMuTag_50m200 -c btagvalidation_cfg.py -d rizki_datasetList_BoostedTaggerValidation_cutFlow_BTagMu_QCDMuEnriched_usePruned_fjpt330_eta2p4_DoubleMuTag_m50to200.txt -q 8nh
# ./createAndSubmitJobs.py -w rizki_LXBatch_BoostedTaggerValidation_cutFlow_BTagMu_QCDMuEnriched_usePruned_fjpt330_eta2p4_DoubleMuTag_50m200_tau0p7 -c btagvalidation_cfg.py -d rizki_datasetList_BoostedTaggerValidation_cutFlow_BTagMu_QCDMuEnriched_usePruned_fjpt330_eta2p4_DoubleMuTag_m50to200_tau0p7.txt -q cmscaf1nh
#./createAndSubmitJobs.py -w rizki_LXBatch_BoostedTaggerValidation_cutFlow_BTagMu_QCDMuEnriched_usePruned_fjpt330_eta2p4_DoubleMuTag_50m200_tau0p5 -c btagvalidation_cfg.py -d rizki_datasetList_BoostedTaggerValidation_cutFlow_BTagMu_QCDMuEnriched_usePruned_fjpt330_eta2p4_DoubleMuTag_m50to200_tau0p5.txt -q cmscaf1nh

# ./createAndSubmitJobs.py -w rizki_LXBatch_BoostedTaggerValidation_DoubleMuonTagged_50m200_tau21-1p0_fj450_usePruned_debug_ptRatioCut -c btagvalidation_cfg.py -d rizki_datasetList_BoostedTaggerValidation_DoubleMuonTagged_50m200_tau21-1p0_fj450_usePruned.txt -q cmscaf1nh
# ./createAndSubmitJobs.py -w rizki_LXBatch_BoostedTaggerValidation_DoubleMuonTagged_50m200_tau21-1p0_fj450_usePruned_debug -c btagvalidation_cfg.py -d rizki_datasetList_BoostedTaggerValidation_DoubleMuonTagged_50m200_tau21-1p0_fj450_usePruned.txt -q cmscaf1nh

# ./createAndSubmitJobs.py -w rizki_LXBatch_BoostedTaggerValidation_DoubleMuonTagged_50m200_tau21-1p0_fj450_usePruned -c btagvalidation_cfg.py -d rizki_datasetList_BoostedTaggerValidation_DoubleMuonTagged_50m200_tau21-1p0_fj450_usePruned.txt

#./createAndSubmitJobs.py -w rizki_LXBatch_Jobs_fatJetPtMin_450_tau-0p5  -c btagvalidation_cfg.py -d rizki_datasetList2015_2ndTime_withJetPtWeight_fj450.txt 

# ./createAndSubmitJobs.py -w rizki_LXBatch_Jobs_SingleMuonTagged_tau21-0p5_fj450 -c btagvalidation_cfg.py -d rizki_datasetList2015_SingleMuonTagged_tau21-0p5_fj450.txt
# ./createAndSubmitJobs.py -w rizki_LXBatch_Jobs_fatJetPtMin_450_tau-0p5  -c btagvalidation_cfg.py -d rizki_datasetList2015_fj450.txt 
# ./createAndSubmitJobs.py -w rizki_LXBatch_BoostedTaggerValidation_DoubleMuonTagged_50m200_tau21-1p0_fj450 -c btagvalidation_cfg.py -d rizki_datasetList_BoostedTaggerValidation_DoubleMuonTagged_50m200_tau21-1p0_fj450.txt

#./createAndSubmitJobs.py -w rizki_LXBatch_Jobs_fatJetPtMin_425_tau-0p5  -c btagvalidation_cfg.py -d rizki_datasetList2015_2ndTime_withJetPtWeight.txt 
#./createAndSubmitJobs.py -w rizki_LXBatch_BoostedTaggerValidation_DoubleMuonTagged_50m200_tau21-1p0_fj425 -c btagvalidation_cfg.py -d rizki_datasetList_BoostedTaggerValidation_DoubleMuonTagged_50m200_tau21-1p0_fj425.txt
#./createAndSubmitJobs.py -w rizki_LXBatch_BoostedTaggerValidation_DoubleMuonTagged_50m200_tau21-1p0_fj330_newTriggerPath -c btagvalidation_cfg.py -d rizki_datasetList_BoostedTaggerValidation_DoubleMuonTagged_50m200_tau21-1p0_fj330_newTriggerPath.txt
#./createAndSubmitJobs.py -w rizki_LXBatch_Jobs_fatJetPtMin_425_tau-0p5  -c btagvalidation_cfg.py -d rizki_datasetList2015.txt 
#./createAndSubmitJobs.py -w rizki_LXBatch_Jobs_SingleMuonTagged_tau21-0p5 -c btagvalidation_cfg.py -d rizki_datasetList2015_SingleMuonTagged_tau21-0p5.txt
