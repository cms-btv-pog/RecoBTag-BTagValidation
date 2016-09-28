#!/bin/bash

#nominal (BTagMu_Jet300) - #using minbias xsec 62000 PU DataDist - JEC unc turned on
./createAndSubmitJobs.py -w rizki_SF_80x_DoubleMuonTag_BTagMu_QCDMuEnriched_dataWithMCJP_v2_12p9_correctedJP_v3_BTagMuTrigJet300 -c btagvalidation_cfg.py -d txt_forJobSubmits/rizki_SF_80x_DoubleMuonTag_QCDMuEnriched_dataWithMCJP_v2_12p9_correctedJP_v3_BTagMuTrigJet300.txt -q cmscaf1nh 

#nominal (BTagMu_Jet300) - #using minbias xsec 62000 PU DataDist - bfragdown
./createAndSubmitJobs.py -w rizki_SF_80x_DoubleMuonTag_BTagMu_QCDMuEnriched_dataWithMCJP_v2_12p9_correctedJP_v3_BTagMuTrigJet300_bfragdown -c btagvalidation_cfg.py -d txt_forJobSubmits/rizki_SF_80x_DoubleMuonTag_QCDMuEnriched_dataWithMCJP_v2_12p9_correctedJP_v3_BTagMuTrigJet300_bragdown.txt -q cmscaf1nh 

#nominal (BTagMu_Jet300) - #using minbias xsec 62000 PU DataDist - bfragup
./createAndSubmitJobs.py -w rizki_SF_80x_DoubleMuonTag_BTagMu_QCDMuEnriched_dataWithMCJP_v2_12p9_correctedJP_v3_BTagMuTrigJet300_bfragup -c btagvalidation_cfg.py -d txt_forJobSubmits/rizki_SF_80x_DoubleMuonTag_QCDMuEnriched_dataWithMCJP_v2_12p9_correctedJP_v3_BTagMuTrigJet300_bfragup.txt -q cmscaf1nh 

#nominal (BTagMu_Jet300) - #using minbias xsec 62000 PU DataDist - CD
./createAndSubmitJobs.py -w rizki_SF_80x_DoubleMuonTag_BTagMu_QCDMuEnriched_dataWithMCJP_v2_12p9_correctedJP_v3_BTagMuTrigJet300_CD -c btagvalidation_cfg.py -d txt_forJobSubmits/rizki_SF_80x_DoubleMuonTag_QCDMuEnriched_dataWithMCJP_v2_12p9_correctedJP_v3_BTagMuTrigJet300_CD.txt -q cmscaf1nh 

#nominal (BTagMu_Jet300) - #using minbias xsec 62000 PU DataDist - cfrag
./createAndSubmitJobs.py -w rizki_SF_80x_DoubleMuonTag_BTagMu_QCDMuEnriched_dataWithMCJP_v2_12p9_correctedJP_v3_BTagMuTrigJet300_cfrag -c btagvalidation_cfg.py -d txt_forJobSubmits/rizki_SF_80x_DoubleMuonTag_QCDMuEnriched_dataWithMCJP_v2_12p9_correctedJP_v3_BTagMuTrigJet300_cfrag.txt -q cmscaf1nh 

#nominal (BTagMu_Jet300) - #using minbias xsec 62000 PU DataDist - K0L
./createAndSubmitJobs.py -w rizki_SF_80x_DoubleMuonTag_BTagMu_QCDMuEnriched_dataWithMCJP_v2_12p9_correctedJP_v3_BTagMuTrigJet300_K0L -c btagvalidation_cfg.py -d txt_forJobSubmits/rizki_SF_80x_DoubleMuonTag_QCDMuEnriched_dataWithMCJP_v2_12p9_correctedJP_v3_BTagMuTrigJet300_K0L.txt -q cmscaf1nh 

#nominal (BTagMu_Jet300) - #using minbias xsec 62000 PU DataDist - nTracks
./createAndSubmitJobs.py -w rizki_SF_80x_DoubleMuonTag_BTagMu_QCDMuEnriched_dataWithMCJP_v2_12p9_correctedJP_v3_BTagMuTrigJet300_nTracks -c btagvalidation_cfg.py -d txt_forJobSubmits/rizki_SF_80x_DoubleMuonTag_QCDMuEnriched_dataWithMCJP_v2_12p9_correctedJP_v3_BTagMuTrigJet300_nTracks.txt -q cmscaf1nh 

#nominal (BTagMu_Jet300) - #using minbias xsec 58900 PU DataDist - PU down
./createAndSubmitJobs.py -w rizki_SF_80x_DoubleMuonTag_BTagMu_QCDMuEnriched_dataWithMCJP_v2_12p9_correctedJP_v3_BTagMuTrigJet300_puDown -c btagvalidation_cfg.py -d txt_forJobSubmits/rizki_SF_80x_DoubleMuonTag_QCDMuEnriched_dataWithMCJP_v2_12p9_correctedJP_v3_BTagMuTrigJet300_puDown.txt -q cmscaf1nh 

#nominal (BTagMu_Jet300) - #using minbias xsec 65100 PU DataDist - PU up
./createAndSubmitJobs.py -w rizki_SF_80x_DoubleMuonTag_BTagMu_QCDMuEnriched_dataWithMCJP_v2_12p9_correctedJP_v3_BTagMuTrigJet300_puUp -c btagvalidation_cfg.py -d txt_forJobSubmits/rizki_SF_80x_DoubleMuonTag_QCDMuEnriched_dataWithMCJP_v2_12p9_correctedJP_v3_BTagMuTrigJet300_puUp.txt -q cmscaf1nh 


#nominal (BTagMu_DiJet170) - #using minbias xsec 62000 PU DataDist - JEC unc turned on
./createAndSubmitJobs.py -w rizki_SF_80x_DoubleMuonTag_BTagMu_QCDMuEnriched_dataWithMCJP_v2_12p9_correctedJP_v3_BTagMuTrigDiJet170 -c btagvalidation_cfg.py -d txt_forJobSubmits/rizki_SF_80x_DoubleMuonTag_QCDMuEnriched_dataWithMCJP_v2_12p9_correctedJP_v3_BTagMuTrigDiJet170.txt -q cmscaf1nh 

#nominal (BTagMu_DiJet170) - #using minbias xsec 62000 PU DataDist - bfragdown
./createAndSubmitJobs.py -w rizki_SF_80x_DoubleMuonTag_BTagMu_QCDMuEnriched_dataWithMCJP_v2_12p9_correctedJP_v3_BTagMuTrigDiJet170_bfragdown -c btagvalidation_cfg.py -d txt_forJobSubmits/rizki_SF_80x_DoubleMuonTag_QCDMuEnriched_dataWithMCJP_v2_12p9_correctedJP_v3_BTagMuTrigDiJet170_bragdown.txt -q cmscaf1nh 

#nominal (BTagMu_DiJet170) - #using minbias xsec 62000 PU DataDist - bfragup
./createAndSubmitJobs.py -w rizki_SF_80x_DoubleMuonTag_BTagMu_QCDMuEnriched_dataWithMCJP_v2_12p9_correctedJP_v3_BTagMuTrigDiJet170_bfragup -c btagvalidation_cfg.py -d txt_forJobSubmits/rizki_SF_80x_DoubleMuonTag_QCDMuEnriched_dataWithMCJP_v2_12p9_correctedJP_v3_BTagMuTrigDiJet170_bfragup.txt -q cmscaf1nh 

#nominal (BTagMu_DiJet170) - #using minbias xsec 62000 PU DataDist - CD
./createAndSubmitJobs.py -w rizki_SF_80x_DoubleMuonTag_BTagMu_QCDMuEnriched_dataWithMCJP_v2_12p9_correctedJP_v3_BTagMuTrigDiJet170_CD -c btagvalidation_cfg.py -d txt_forJobSubmits/rizki_SF_80x_DoubleMuonTag_QCDMuEnriched_dataWithMCJP_v2_12p9_correctedJP_v3_BTagMuTrigDiJet170_CD.txt -q cmscaf1nh 

#nominal (BTagMu_DiJet170) - #using minbias xsec 62000 PU DataDist - cfrag
./createAndSubmitJobs.py -w rizki_SF_80x_DoubleMuonTag_BTagMu_QCDMuEnriched_dataWithMCJP_v2_12p9_correctedJP_v3_BTagMuTrigDiJet170_cfrag -c btagvalidation_cfg.py -d txt_forJobSubmits/rizki_SF_80x_DoubleMuonTag_QCDMuEnriched_dataWithMCJP_v2_12p9_correctedJP_v3_BTagMuTrigDiJet170_cfrag.txt -q cmscaf1nh 

#nominal (BTagMu_DiJet170) - #using minbias xsec 62000 PU DataDist - K0L
./createAndSubmitJobs.py -w rizki_SF_80x_DoubleMuonTag_BTagMu_QCDMuEnriched_dataWithMCJP_v2_12p9_correctedJP_v3_BTagMuTrigDiJet170_K0L -c btagvalidation_cfg.py -d txt_forJobSubmits/rizki_SF_80x_DoubleMuonTag_QCDMuEnriched_dataWithMCJP_v2_12p9_correctedJP_v3_BTagMuTrigDiJet170_K0L.txt -q cmscaf1nh 

#nominal (BTagMu_DiJet170) - #using minbias xsec 62000 PU DataDist - nTracks
./createAndSubmitJobs.py -w rizki_SF_80x_DoubleMuonTag_BTagMu_QCDMuEnriched_dataWithMCJP_v2_12p9_correctedJP_v3_BTagMuTrigDiJet170_nTracks -c btagvalidation_cfg.py -d txt_forJobSubmits/rizki_SF_80x_DoubleMuonTag_QCDMuEnriched_dataWithMCJP_v2_12p9_correctedJP_v3_BTagMuTrigDiJet170_nTracks.txt -q cmscaf1nh 

#nominal (BTagMu_DiJet170) - #using minbias xsec 58900 PU DataDist - PU down
./createAndSubmitJobs.py -w rizki_SF_80x_DoubleMuonTag_BTagMu_QCDMuEnriched_dataWithMCJP_v2_12p9_correctedJP_v3_BTagMuTrigDiJet170_puDown -c btagvalidation_cfg.py -d txt_forJobSubmits/rizki_SF_80x_DoubleMuonTag_QCDMuEnriched_dataWithMCJP_v2_12p9_correctedJP_v3_BTagMuTrigDiJet170_puDown.txt -q cmscaf1nh 

#nominal (BTagMu_DiJet170) - #using minbias xsec 65100 PU DataDist - PU up
./createAndSubmitJobs.py -w rizki_SF_80x_DoubleMuonTag_BTagMu_QCDMuEnriched_dataWithMCJP_v2_12p9_correctedJP_v3_BTagMuTrigDiJet170_puUp -c btagvalidation_cfg.py -d txt_forJobSubmits/rizki_SF_80x_DoubleMuonTag_QCDMuEnriched_dataWithMCJP_v2_12p9_correctedJP_v3_BTagMuTrigDiJet170_puUp.txt -q cmscaf1nh 


#nominal - one trig at at time - BTagMu_DiJet170_Mu5 - #using minbias xsec 62000 PU DataDist
# ./createAndSubmitJobs.py -w rizki_SF_80x_DoubleMuonTag_BTagMu_QCDMuEnriched_dataWithMCJP_v2_12p9_correctedJP_v3_BTagMuTrigDiJet170 -c btagvalidation_cfg.py -d txt_forJobSubmits/rizki_SF_80x_DoubleMuonTag_QCDMuEnriched_dataWithMCJP_v2_12p9_correctedJP_v3_BTagMuTrigDiJet170.txt -q cmscaf1nh 
# ./createAndSubmitJobs.py -w rizki_SF_80x_SingleMuonTag_BTagMu_QCDMuEnriched_dataWithMCJP_v2_12p9_correctedJP_v3_BTagMuTrigDiJet170 -c btagvalidation_cfg.py -d txt_forJobSubmits/rizki_SF_80x_SingleMuonTag_QCDMuEnriched_dataWithMCJP_v2_12p9_correctedJP_v3_BTagMuTrigDiJet170.txt -q cmscaf1nh 

#nominal - one trig at at time - BTagMu_Jet300 - #using minbias xsec 62000 PU DataDist
# ./createAndSubmitJobs.py -w rizki_SF_80x_DoubleMuonTag_BTagMu_QCDMuEnriched_dataWithMCJP_v2_12p9_correctedJP_v3_BTagMuTrigJet300 -c btagvalidation_cfg.py -d txt_forJobSubmits/rizki_SF_80x_DoubleMuonTag_QCDMuEnriched_dataWithMCJP_v2_12p9_correctedJP_v3_BTagMuTrigJet300.txt -q cmscaf1nh 
# ./createAndSubmitJobs.py -w rizki_SF_80x_SingleMuonTag_BTagMu_QCDMuEnriched_dataWithMCJP_v2_12p9_correctedJP_v3_BTagMuTrigJet300 -c btagvalidation_cfg.py -d txt_forJobSubmits/rizki_SF_80x_SingleMuonTag_QCDMuEnriched_dataWithMCJP_v2_12p9_correctedJP_v3_BTagMuTrigJet300.txt -q cmscaf1nh 

#nominal - one trig at at time - BTagMu_AK8Jet300 - #using minbias xsec 62000 PU DataDist
# ./createAndSubmitJobs.py -w rizki_SF_80x_DoubleMuonTag_BTagMu_QCDMuEnriched_dataWithMCJP_v2_12p9_correctedJP_v3_BTagMuTrigAK8Jet300 -c btagvalidation_cfg.py -d txt_forJobSubmits/rizki_SF_80x_DoubleMuonTag_QCDMuEnriched_dataWithMCJP_v2_12p9_correctedJP_v3_BTagMuTrigAK8Jet300.txt -q cmscaf1nh 
# ./createAndSubmitJobs.py -w rizki_SF_80x_SingleMuonTag_BTagMu_QCDMuEnriched_dataWithMCJP_v2_12p9_correctedJP_v3_BTagMuTrigAK8Jet300 -c btagvalidation_cfg.py -d txt_forJobSubmits/rizki_SF_80x_SingleMuonTag_QCDMuEnriched_dataWithMCJP_v2_12p9_correctedJP_v3_BTagMuTrigAK8Jet300.txt -q cmscaf1nh 

#nominal (fixed trigger) - #using minbias xsec 62000 PU DataDist
# ./createAndSubmitJobs.py -w rizki_SF_80x_DoubleMuonTag_BTagMu_QCDMuEnriched_dataWithMCJP_v2_12p9_correctedJP_v3 -c btagvalidation_cfg.py -d txt_forJobSubmits/rizki_SF_80x_DoubleMuonTag_QCDMuEnriched_dataWithMCJP_v2_12p9_correctedJP_v3.txt -q cmscaf1nh 
# ./createAndSubmitJobs.py -w rizki_SF_80x_SingleMuonTag_BTagMu_QCDMuEnriched_dataWithMCJP_v2_12p9_correctedJP_v3 -c btagvalidation_cfg.py -d txt_forJobSubmits/rizki_SF_80x_SingleMuonTag_QCDMuEnriched_dataWithMCJP_v2_12p9_correctedJP_v3.txt -q cmscaf1nh 

#nominal (NO trigger)
# ./createAndSubmitJobs.py -w rizki_SF_80x_DoubleMuonTag_BTagMu_QCDMuEnriched_dataWithMCJP_v2_12p9_correctedJP_v3a -c btagvalidation_cfg.py -d txt_forJobSubmits/rizki_SF_80x_DoubleMuonTag_QCDMuEnriched_dataWithMCJP_v2_12p9_correctedJP_v3a.txt -q 8nh #cmscaf1nh 
# ./createAndSubmitJobs.py -w rizki_SF_80x_SingleMuonTag_BTagMu_QCDMuEnriched_dataWithMCJP_v2_12p9_correctedJP_v3a -c btagvalidation_cfg.py -d txt_forJobSubmits/rizki_SF_80x_SingleMuonTag_QCDMuEnriched_dataWithMCJP_v2_12p9_correctedJP_v3a.txt -q 8nh #cmscaf1nh 

#nominal - one trig at at time - BTagMu_Jet300 - #using minbias xsec 69200 PU DataDist (fixed trigger)
# ./createAndSubmitJobs.py -w rizki_SF_80x_DoubleMuonTag_BTagMu_QCDMuEnriched_dataWithMCJP_v2_12p9_correctedJP_v1a_BTagMuTrigJet300 -c btagvalidation_cfg.py -d txt_forJobSubmits/rizki_SF_80x_DoubleMuonTag_QCDMuEnriched_dataWithMCJP_v2_12p9_correctedJP_v1a_BTagMuTrigJet300.txt -q cmscaf1nh 
# ./createAndSubmitJobs.py -w rizki_SF_80x_SingleMuonTag_BTagMu_QCDMuEnriched_dataWithMCJP_v2_12p9_correctedJP_v1a_BTagMuTrigJet300 -c btagvalidation_cfg.py -d txt_forJobSubmits/rizki_SF_80x_SingleMuonTag_QCDMuEnriched_dataWithMCJP_v2_12p9_correctedJP_v1a_BTagMuTrigJet300.txt -q cmscaf1nh 

#nominal - one trig at at time - BTagMu_AK8Jet300 - #using minbias xsec 69200 PU DataDist (fixed trigger)
# ./createAndSubmitJobs.py -w rizki_SF_80x_DoubleMuonTag_BTagMu_QCDMuEnriched_dataWithMCJP_v2_12p9_correctedJP_v1a_BTagMuTrigAK8Jet300 -c btagvalidation_cfg.py -d txt_forJobSubmits/rizki_SF_80x_DoubleMuonTag_QCDMuEnriched_dataWithMCJP_v2_12p9_correctedJP_v1a_BTagMuTrigAK8Jet300.txt -q cmscaf1nh 
# ./createAndSubmitJobs.py -w rizki_SF_80x_SingleMuonTag_BTagMu_QCDMuEnriched_dataWithMCJP_v2_12p9_correctedJP_v1a_BTagMuTrigAK8Jet300 -c btagvalidation_cfg.py -d txt_forJobSubmits/rizki_SF_80x_SingleMuonTag_QCDMuEnriched_dataWithMCJP_v2_12p9_correctedJP_v1a_BTagMuTrigAK8Jet300.txt -q cmscaf1nh 

#nominal - #using minbias xsec 69200 PU DataDist (fixed trigger)
# ./createAndSubmitJobs.py -w rizki_SF_80x_DoubleMuonTag_BTagMu_QCDMuEnriched_dataWithMCJP_v2_12p9_correctedJP_v1a -c btagvalidation_cfg.py -d txt_forJobSubmits/rizki_SF_80x_DoubleMuonTag_QCDMuEnriched_dataWithMCJP_v2_12p9_correctedJP_v1a.txt -q cmscaf1nh 
# ./createAndSubmitJobs.py -w rizki_SF_80x_SingleMuonTag_BTagMu_QCDMuEnriched_dataWithMCJP_v2_12p9_correctedJP_v1a -c btagvalidation_cfg.py -d txt_forJobSubmits/rizki_SF_80x_SingleMuonTag_QCDMuEnriched_dataWithMCJP_v2_12p9_correctedJP_v1a.txt -q cmscaf1nh 

#JetHT - nominal
# ./createAndSubmitJobs.py -w rizki_SF_80x_DoubleMuonTag_JetHT_QCDincl_dataWithMCJP_v2_12p9_correctedJP_pt300 -c btagvalidation_cfg.py -d txt_forJobSubmits/rizki_SF_80x_DoubleMuonTag_QCDincl_dataWithMCJP_v2_12p9_correctedJP_pt300.txt -q cmscaf1nh
# ./createAndSubmitJobs.py -w rizki_SF_80x_DoubleMuonTag_JetHT_QCDincl_dataWithMCJP_v2_12p9_correctedJP_pt310 -c btagvalidation_cfg.py -d txt_forJobSubmits/rizki_SF_80x_DoubleMuonTag_QCDincl_dataWithMCJP_v2_12p9_correctedJP_pt310.txt -q cmscaf1nh
# ./createAndSubmitJobs.py -w rizki_SF_80x_DoubleMuonTag_JetHT_QCDincl_dataWithMCJP_v2_12p9_correctedJP_pt360 -c btagvalidation_cfg.py -d txt_forJobSubmits/rizki_SF_80x_DoubleMuonTag_QCDincl_dataWithMCJP_v2_12p9_correctedJP_pt360.txt -q cmscaf1nh
# ./createAndSubmitJobs.py -w rizki_SF_80x_DoubleMuonTag_JetHT_QCDincl_dataWithMCJP_v2_12p9_correctedJP_pt450 -c btagvalidation_cfg.py -d txt_forJobSubmits/rizki_SF_80x_DoubleMuonTag_QCDincl_dataWithMCJP_v2_12p9_correctedJP_pt450.txt -q cmscaf1nh

# ./createAndSubmitJobs.py -w rizki_SF_80x_SingleMuonTag_JetHT_QCDincl_dataWithMCJP_v2_12p9_correctedJP_pt300 -c btagvalidation_cfg.py -d txt_forJobSubmits/rizki_SF_80x_SingleMuonTag_QCDincl_dataWithMCJP_v2_12p9_correctedJP_pt300.txt -q cmscaf1nh
# ./createAndSubmitJobs.py -w rizki_SF_80x_SingleMuonTag_JetHT_QCDincl_dataWithMCJP_v2_12p9_correctedJP_pt310 -c btagvalidation_cfg.py -d txt_forJobSubmits/rizki_SF_80x_SingleMuonTag_QCDincl_dataWithMCJP_v2_12p9_correctedJP_pt310.txt -q cmscaf1nh
# ./createAndSubmitJobs.py -w rizki_SF_80x_SingleMuonTag_JetHT_QCDincl_dataWithMCJP_v2_12p9_correctedJP_pt360 -c btagvalidation_cfg.py -d txt_forJobSubmits/rizki_SF_80x_SingleMuonTag_QCDincl_dataWithMCJP_v2_12p9_correctedJP_p360.txt -q cmscaf1nh
# ./createAndSubmitJobs.py -w rizki_SF_80x_SingleMuonTag_JetHT_QCDincl_dataWithMCJP_v2_12p9_correctedJP_pt450 -c btagvalidation_cfg.py -d txt_forJobSubmits/rizki_SF_80x_SingleMuonTag_QCDincl_dataWithMCJP_v2_12p9_correctedJP_pt450.txt -q cmscaf1nh

#fatjetPt
# ./createAndSubmitJobs.py -w rizki_SF_80x_DoubleMuonTag_BTagMu_QCDMuEnriched_dataWithMCJP_v2_12p9_correctedJP_v3_fatjetPtReweight -c btagvalidation_cfg.py -d txt_forJobSubmits/rizki_SF_80x_DoubleMuonTag_QCDMuEnriched_dataWithMCJP_v2_12p9_correctedJP_v3_fatjetPtReweight.txt -q cmscaf1nh #using minbias xsec 62000 PU DataDist
# ./createAndSubmitJobs.py -w rizki_SF_80x_SingleMuonTag_BTagMu_QCDMuEnriched_dataWithMCJP_v2_12p9_correctedJP_v3_fatjetPtReweight -c btagvalidation_cfg.py -d txt_forJobSubmits/rizki_SF_80x_SingleMuonTag_QCDMuEnriched_dataWithMCJP_v2_12p9_correctedJP_v3_fatjetPtReweight.txt -q cmscaf1nh #using minbias xsec 62000 PU DataDist

#bfragDown
# ./createAndSubmitJobs.py -w rizki_SF_80x_DoubleMuonTag_BTagMu_QCDMuEnriched_dataWithMCJP_v2_12p9_correctedJP_v3_bfragDown -c btagvalidation_cfg.py -d txt_forJobSubmits/rizki_SF_80x_DoubleMuonTag_QCDMuEnriched_dataWithMCJP_v2_12p9_correctedJP_v3_bfragDown.txt -q cmscaf1nh #using minbias xsec 62000 PU DataDist
# ./createAndSubmitJobs.py -w rizki_SF_80x_SingleMuonTag_BTagMu_QCDMuEnriched_dataWithMCJP_v2_12p9_correctedJP_v3_bfragDown -c btagvalidation_cfg.py -d txt_forJobSubmits/rizki_SF_80x_SingleMuonTag_QCDMuEnriched_dataWithMCJP_v2_12p9_correctedJP_v3_bfragDown.txt -q cmscaf1nh #using minbias xsec 62000 PU DataDist

#bfragUp
# ./createAndSubmitJobs.py -w rizki_SF_80x_DoubleMuonTag_BTagMu_QCDMuEnriched_dataWithMCJP_v2_12p9_correctedJP_v3_bfragUp -c btagvalidation_cfg.py -d txt_forJobSubmits/rizki_SF_80x_DoubleMuonTag_QCDMuEnriched_dataWithMCJP_v2_12p9_correctedJP_v3_bfragUp.txt -q cmscaf1nh #using minbias xsec 62000 PU DataDist
# ./createAndSubmitJobs.py -w rizki_SF_80x_SingleMuonTag_BTagMu_QCDMuEnriched_dataWithMCJP_v2_12p9_correctedJP_v3_bfragUp -c btagvalidation_cfg.py -d txt_forJobSubmits/rizki_SF_80x_SingleMuonTag_QCDMuEnriched_dataWithMCJP_v2_12p9_correctedJP_v3_bfragUp.txt -q cmscaf1nh #using minbias xsec 62000 PU DataDist

#nTracks
# ./createAndSubmitJobs.py -w rizki_SF_80x_DoubleMuonTag_BTagMu_QCDMuEnriched_dataWithMCJP_v2_12p9_correctedJP_v3_nTracksReweight -c btagvalidation_cfg.py -d txt_forJobSubmits/rizki_SF_80x_DoubleMuonTag_QCDMuEnriched_dataWithMCJP_v2_12p9_correctedJP_v3_nTracksReweight.txt -q cmscaf1nh #using minbias xsec 62000 PU DataDist
# ./createAndSubmitJobs.py -w rizki_SF_80x_SingleMuonTag_BTagMu_QCDMuEnriched_dataWithMCJP_v2_12p9_correctedJP_v3_nTracksReweight -c btagvalidation_cfg.py -d txt_forJobSubmits/rizki_SF_80x_SingleMuonTag_QCDMuEnriched_dataWithMCJP_v2_12p9_correctedJP_v3_nTracksReweight.txt -q cmscaf1nh #using minbias xsec 62000 PU DataDist


#others
# ./createAndSubmitJobs.py -w rizki_SF_80x_DoubleMuonTag_BTagMu_QCDMuEnriched_dataWithMCJP_v2_12p9_correctedJP_v2 -c btagvalidation_cfg.py -d txt_forJobSubmits/rizki_SF_80x_DoubleMuonTag_QCDMuEnriched_dataWithMCJP_v2_12p9_correctedJP.txt -q cmscaf1nh #using Devdattas PU file
# ./createAndSubmitJobs.py -w rizki_SF_80x_SingleMuonTag_BTagMu_QCDMuEnriched_dataWithMCJP_v2_12p9_correctedJP_v2 -c btagvalidation_cfg.py -d txt_forJobSubmits/rizki_SF_80x_SingleMuonTag_QCDMuEnriched_dataWithMCJP_v2_12p9_correctedJP.txt -q cmscaf1nh #using Devdattas PU file

# ./createAndSubmitJobs.py -w rizki_SF_80x_DoubleMuonTag_BTagMu_QCDMuEnriched_dataWithMCJP_v2_12p9_correctedJP -c btagvalidation_cfg.py -d txt_forJobSubmits/rizki_SF_80x_DoubleMuonTag_QCDMuEnriched_dataWithMCJP_v2_12p9_correctedJP.txt -q cmscaf1nh
# ./createAndSubmitJobs.py -w rizki_SF_80x_SingleMuonTag_BTagMu_QCDMuEnriched_dataWithMCJP_v2_12p9_correctedJP -c btagvalidation_cfg.py -d txt_forJobSubmits/rizki_SF_80x_SingleMuonTag_QCDMuEnriched_dataWithMCJP_v2_12p9_correctedJP.txt -q cmscaf1nh

# ./createAndSubmitJobs.py -w rizki_SF_80x_DoubleMuonTag_JetHT_QCDincl_dataWithMCJP -c btagvalidation_cfg.py -d txt_forJobSubmits/rizki_SF_80x_DoubleMuonTag_QCDincl_dataWithMCJP.txt -q cmscaf1nh
# ./createAndSubmitJobs.py -w rizki_SF_80x_SingleMuonTag_JetHT_QCDincl_dataWithMCJP -c btagvalidation_cfg.py -d txt_forJobSubmits/rizki_SF_80x_SingleMuonTag_QCDincl_dataWithMCJP.txt -q cmscaf1nh

# ./createAndSubmitJobs.py -w rizki_SF_80x_DoubleMuonTag_BTagMu_QCDMuEnriched_dataWithMCJP -c btagvalidation_cfg.py -d txt_forJobSubmits/rizki_SF_80x_DoubleMuonTag_QCDMuEnriched_dataWithMCJP.txt -q cmscaf1nh
# ./createAndSubmitJobs.py -w rizki_SF_80x_SingleMuonTag_BTagMu_QCDMuEnriched_dataWithMCJP -c btagvalidation_cfg.py -d txt_forJobSubmits/rizki_SF_80x_SingleMuonTag_QCDMuEnriched_dataWithMCJP.txt -q cmscaf1nh

# ./createAndSubmitJobs.py -w rizki_SF_80x_DoubleMuonTag_JetHT_QCDincl -c btagvalidation_cfg.py -d txt_forJobSubmits/rizki_SF_80x_DoubleMuonTag_QCDincl.txt -q cmscaf1nh
# ./createAndSubmitJobs.py -w rizki_SF_80x_SingleMuonTag_JetHT_QCDincl -c btagvalidation_cfg.py -d txt_forJobSubmits/rizki_SF_80x_SingleMuonTag_QCDincl.txt -q cmscaf1nh

# ./createAndSubmitJobs.py -w rizki_SF_80x_DoubleMuonTag_BTagMu_QCDMuEnriched -c btagvalidation_cfg.py -d txt_forJobSubmits/rizki_SF_80x_DoubleMuonTag_QCDMuEnriched.txt -q cmscaf1nh
#./createAndSubmitJobs.py -w rizki_SF_80x_SingleMuonTag_BTagMu_QCDMuEnriched -c btagvalidation_cfg.py -d txt_forJobSubmits/rizki_SF_80x_SingleMuonTag_QCDMuEnriched.txt -q cmscaf1nh

# ./createAndSubmitJobs.py -w rizki_SF_80x_DoubleMuonTag -c btagvalidation_cfg.py -d txt_forJobSubmits/rizki_SF_80x_DoubleMuonTag_QCDMuEnriched.txt -q cmscaf1nh
# ./createAndSubmitJobs.py -w rizki_SF_80x_SingleMuonTag -c btagvalidation_cfg.py -d txt_forJobSubmits/rizki_SF_80x_SingleMuonTag_QCDMuEnriched.txt -q cmscaf1nh

# ./createAndSubmitJobs.py -w rizki_SF_80x_DoubleMuonTag_QCDincl -c btagvalidation_cfg.py -d txt_forJobSubmits/rizki_SF_80x_DoubleMuonTag_QCDincl.txt -q cmscaf1nh
# ./createAndSubmitJobs.py -w rizki_SF_80x_SingleMuonTag_QCDincl -c btagvalidation_cfg.py -d txt_forJobSubmits/rizki_SF_80x_SingleMuonTag_QCDincl.txt -q cmscaf1nh


