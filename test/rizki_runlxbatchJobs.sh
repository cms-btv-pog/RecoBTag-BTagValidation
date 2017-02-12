#!/bin/bash

eospath=/eos/cms/store/group/phys_btag/BoostedBTag/BTagNTuples/8_0_X_v2.03/BTagValJobs_rizki/

# ./createAndSubmitJobs_new.py -w Mu_350 -e true -o $eospath -c btagvalidation_cfg.py -d txt_forJobSubmits/rizki_SF_80x_DoubleMuonTag_QCDMuEnriched_BTagMu_mcJPcalib_HLTAK8Jet300_OR_HLTJet300_pt350.txt -q 8nh
# ./createAndSubmitJobs_new.py -w Mu_250 -e true -o $eospath -c btagvalidation_cfg.py -d txt_forJobSubmits/rizki_SF_80x_DoubleMuonTag_QCDMuEnriched_BTagMu_mcJPcalib_HLTDiJet170_pt250to350.txt -q 8nh

# ./createAndSubmitJobs_new.py -w Mu_350_ptReweighted -e true -o $eospath -c btagvalidation_cfg.py -d txt_forJobSubmits/rizki_SF_80x_DoubleMuonTag_QCDMuEnriched_BTagMu_mcJPcalib_HLTAK8Jet300_OR_HLTJet300_pt350_ptReweighted.txt -q 8nh
# ./createAndSubmitJobs_new.py -w Mu_250_ptReweighted -e true -o $eospath -c btagvalidation_cfg.py -d txt_forJobSubmits/rizki_SF_80x_DoubleMuonTag_QCDMuEnriched_BTagMu_mcJPcalib_HLTDiJet170_pt250to350_ptReweighted.txt -q 8nh
# 
# ./createAndSubmitJobs_new.py -w Mu_350_bfragdown -e true -o $eospath -c btagvalidation_cfg.py -d txt_forJobSubmits/rizki_SF_80x_DoubleMuonTag_QCDMuEnriched_BTagMu_mcJPcalib_HLTAK8Jet300_OR_HLTJet300_pt350_bfragdown.txt -q 8nh
# ./createAndSubmitJobs_new.py -w Mu_250_bfragdown -e true -o $eospath -c btagvalidation_cfg.py -d txt_forJobSubmits/rizki_SF_80x_DoubleMuonTag_QCDMuEnriched_BTagMu_mcJPcalib_HLTDiJet170_pt250to350_bfragdown.txt -q 8nh
# 
# ./createAndSubmitJobs_new.py -w Mu_350_bfragup -e true -o $eospath -c btagvalidation_cfg.py -d txt_forJobSubmits/rizki_SF_80x_DoubleMuonTag_QCDMuEnriched_BTagMu_mcJPcalib_HLTAK8Jet300_OR_HLTJet300_pt350_bfragup.txt -q 8nh
./createAndSubmitJobs_new.py -w Mu_250_bfragup -e true -o $eospath -c btagvalidation_cfg.py -d txt_forJobSubmits/rizki_SF_80x_DoubleMuonTag_QCDMuEnriched_BTagMu_mcJPcalib_HLTDiJet170_pt250to350_bfragup.txt -q 8nh

./createAndSubmitJobs_new.py -w Mu_350_CD -e true -o $eospath -c btagvalidation_cfg.py -d txt_forJobSubmits/rizki_SF_80x_DoubleMuonTag_QCDMuEnriched_BTagMu_mcJPcalib_HLTAK8Jet300_OR_HLTJet300_pt350_CD.txt -q 8nh
./createAndSubmitJobs_new.py -w Mu_250_CD -e true -o $eospath -c btagvalidation_cfg.py -d txt_forJobSubmits/rizki_SF_80x_DoubleMuonTag_QCDMuEnriched_BTagMu_mcJPcalib_HLTDiJet170_pt250to350_CD.txt -q 8nh

./createAndSubmitJobs_new.py -w Mu_350_cfrag -e true -o $eospath -c btagvalidation_cfg.py -d txt_forJobSubmits/rizki_SF_80x_DoubleMuonTag_QCDMuEnriched_BTagMu_mcJPcalib_HLTAK8Jet300_OR_HLTJet300_pt350_cfrag.txt -q 8nh
./createAndSubmitJobs_new.py -w Mu_250_cfrag -e true -o $eospath -c btagvalidation_cfg.py -d txt_forJobSubmits/rizki_SF_80x_DoubleMuonTag_QCDMuEnriched_BTagMu_mcJPcalib_HLTDiJet170_pt250to350_cfrag.txt -q 8nh

./createAndSubmitJobs_new.py -w Mu_350_K0L -e true -o $eospath -c btagvalidation_cfg.py -d txt_forJobSubmits/rizki_SF_80x_DoubleMuonTag_QCDMuEnriched_BTagMu_mcJPcalib_HLTAK8Jet300_OR_HLTJet300_pt350_K0L.txt -q 8nh
./createAndSubmitJobs_new.py -w Mu_250_K0L -e true -o $eospath -c btagvalidation_cfg.py -d txt_forJobSubmits/rizki_SF_80x_DoubleMuonTag_QCDMuEnriched_BTagMu_mcJPcalib_HLTDiJet170_pt250to350_K0L.txt -q 8nh

./createAndSubmitJobs_new.py -w Mu_350_nTracks -e true -o $eospath -c btagvalidation_cfg.py -d txt_forJobSubmits/rizki_SF_80x_DoubleMuonTag_QCDMuEnriched_BTagMu_mcJPcalib_HLTAK8Jet300_OR_HLTJet300_pt350_nTracks.txt -q 8nh
./createAndSubmitJobs_new.py -w Mu_250_nTracks -e true -o $eospath -c btagvalidation_cfg.py -d txt_forJobSubmits/rizki_SF_80x_DoubleMuonTag_QCDMuEnriched_BTagMu_mcJPcalib_HLTDiJet170_pt250to350_nTracks.txt -q 8nh

./createAndSubmitJobs_new.py -w Mu_350_puDown -e true -o $eospath -c btagvalidation_cfg.py -d txt_forJobSubmits/rizki_SF_80x_DoubleMuonTag_QCDMuEnriched_BTagMu_mcJPcalib_HLTAK8Jet300_OR_HLTJet300_pt350_puDown.txt -q 8nh
./createAndSubmitJobs_new.py -w Mu_250_puDown -e true -o $eospath -c btagvalidation_cfg.py -d txt_forJobSubmits/rizki_SF_80x_DoubleMuonTag_QCDMuEnriched_BTagMu_mcJPcalib_HLTDiJet170_pt250to350_puDown.txt -q 8nh

./createAndSubmitJobs_new.py -w Mu_350_puUp -e true -o $eospath -c btagvalidation_cfg.py -d txt_forJobSubmits/rizki_SF_80x_DoubleMuonTag_QCDMuEnriched_BTagMu_mcJPcalib_HLTAK8Jet300_OR_HLTJet300_pt350_puUp.txt -q 8nh
./createAndSubmitJobs_new.py -w Mu_250_puUp -e true -o $eospath -c btagvalidation_cfg.py -d txt_forJobSubmits/rizki_SF_80x_DoubleMuonTag_QCDMuEnriched_BTagMu_mcJPcalib_HLTDiJet170_pt250to350_puUp.txt -q 8nh

# ./createAndSubmitJobs_new.py -w Mu_350_dataJPcalib -e true -o $eospath -c btagvalidation_cfg.py -d txt_forJobSubmits/rizki_SF_80x_DoubleMuonTag_QCDMuEnriched_BTagMu_mcJPcalib_HLTAK8Jet300_OR_HLTJet300_pt350_dataJPcalib.txt -q cmscaf1nh
# ./createAndSubmitJobs_new.py -w Mu_250_dataJPcalib -e true -o $eospath -c btagvalidation_cfg.py -d txt_forJobSubmits/rizki_SF_80x_DoubleMuonTag_QCDMuEnriched_BTagMu_mcJPcalib_HLTDiJet170_pt250to350_dataJPcalib.txt -q cmscaf1nh

# ./createAndSubmitJobs_new.py -w Mu_350_dataJPcalib_ptReweighted -e true -o $eospath -c btagvalidation_cfg.py -d txt_forJobSubmits/rizki_SF_80x_DoubleMuonTag_QCDMuEnriched_BTagMu_mcJPcalib_HLTAK8Jet300_OR_HLTJet300_pt350_dataJPcalib_ptReweighted.txt -q cmscaf1nh
# ./createAndSubmitJobs_new.py -w Mu_250_dataJPcalib_ptReweighted -e true -o $eospath -c btagvalidation_cfg.py -d txt_forJobSubmits/rizki_SF_80x_DoubleMuonTag_QCDMuEnriched_BTagMu_mcJPcalib_HLTDiJet170_pt250to350_dataJPcalib_ptReweighted.txt -q cmscaf1nh



#############older submit scipts, only saves locally.###########

# ./createAndSubmitJobs.py -w Mu_350 -c btagvalidation_cfg.py -d txt_forJobSubmits/rizki_SF_80x_DoubleMuonTag_QCDMuEnriched_BTagMu_mcJPcalib_HLTAK8Jet300_OR_HLTJet300_pt350.txt -q 8nh
# ./createAndSubmitJobs.py -w Mu_250 -c btagvalidation_cfg.py -d txt_forJobSubmits/rizki_SF_80x_DoubleMuonTag_QCDMuEnriched_BTagMu_mcJPcalib_HLTDiJet170_pt250to350.txt -q 8nh

# ./createAndSubmitJobs.py -w Mu_350_bfragdown -c btagvalidation_cfg.py -d txt_forJobSubmits/rizki_SF_80x_DoubleMuonTag_QCDMuEnriched_BTagMu_mcJPcalib_HLTAK8Jet300_OR_HLTJet300_pt350_bfragdown.txt -q 8nh
# ./createAndSubmitJobs.py -w Mu_250_bfragdown -c btagvalidation_cfg.py -d txt_forJobSubmits/rizki_SF_80x_DoubleMuonTag_QCDMuEnriched_BTagMu_mcJPcalib_HLTDiJet170_pt250to350_bfragdown.txt -q 8nh

# ./createAndSubmitJobs.py -w Mu_350_bfragup -c btagvalidation_cfg.py -d txt_forJobSubmits/rizki_SF_80x_DoubleMuonTag_QCDMuEnriched_BTagMu_mcJPcalib_HLTAK8Jet300_OR_HLTJet300_pt350_bfragup.txt -q 8nh
# ./createAndSubmitJobs.py -w Mu_250_bfragup -c btagvalidation_cfg.py -d txt_forJobSubmits/rizki_SF_80x_DoubleMuonTag_QCDMuEnriched_BTagMu_mcJPcalib_HLTDiJet170_pt250to350_bfragup.txt -q 8nh

# ./createAndSubmitJobs.py -w Mu_350_CD -c btagvalidation_cfg.py -d txt_forJobSubmits/rizki_SF_80x_DoubleMuonTag_QCDMuEnriched_BTagMu_mcJPcalib_HLTAK8Jet300_OR_HLTJet300_pt350_CD.txt -q 8nh
# ./createAndSubmitJobs.py -w Mu_250_CD -c btagvalidation_cfg.py -d txt_forJobSubmits/rizki_SF_80x_DoubleMuonTag_QCDMuEnriched_BTagMu_mcJPcalib_HLTDiJet170_pt250to350_CD.txt -q 8nh
# 
# ./createAndSubmitJobs.py -w Mu_350_cfrag -c btagvalidation_cfg.py -d txt_forJobSubmits/rizki_SF_80x_DoubleMuonTag_QCDMuEnriched_BTagMu_mcJPcalib_HLTAK8Jet300_OR_HLTJet300_pt350_cfrag.txt -q 8nh
# ./createAndSubmitJobs.py -w Mu_250_cfrag -c btagvalidation_cfg.py -d txt_forJobSubmits/rizki_SF_80x_DoubleMuonTag_QCDMuEnriched_BTagMu_mcJPcalib_HLTDiJet170_pt250to350_cfrag.txt -q 8nh
# 
# ./createAndSubmitJobs.py -w Mu_350_K0L -c btagvalidation_cfg.py -d txt_forJobSubmits/rizki_SF_80x_DoubleMuonTag_QCDMuEnriched_BTagMu_mcJPcalib_HLTAK8Jet300_OR_HLTJet300_pt350_K0L.txt -q 8nh
# ./createAndSubmitJobs.py -w Mu_250_K0L -c btagvalidation_cfg.py -d txt_forJobSubmits/rizki_SF_80x_DoubleMuonTag_QCDMuEnriched_BTagMu_mcJPcalib_HLTDiJet170_pt250to350_K0L.txt -q 8nh
# 
# ./createAndSubmitJobs.py -w Mu_350_nTracks -c btagvalidation_cfg.py -d txt_forJobSubmits/rizki_SF_80x_DoubleMuonTag_QCDMuEnriched_BTagMu_mcJPcalib_HLTAK8Jet300_OR_HLTJet300_pt350_nTracks.txt -q 8nh
# ./createAndSubmitJobs.py -w Mu_250_nTracks -c btagvalidation_cfg.py -d txt_forJobSubmits/rizki_SF_80x_DoubleMuonTag_QCDMuEnriched_BTagMu_mcJPcalib_HLTDiJet170_pt250to350_nTracks.txt -q 8nh
# 
# ./createAndSubmitJobs.py -w Mu_350_puDown -c btagvalidation_cfg.py -d txt_forJobSubmits/rizki_SF_80x_DoubleMuonTag_QCDMuEnriched_BTagMu_mcJPcalib_HLTAK8Jet300_OR_HLTJet300_pt350_puDown.txt -q 8nh
# ./createAndSubmitJobs.py -w Mu_250_puDown -c btagvalidation_cfg.py -d txt_forJobSubmits/rizki_SF_80x_DoubleMuonTag_QCDMuEnriched_BTagMu_mcJPcalib_HLTDiJet170_pt250to350_puDown.txt -q 8nh

# ./createAndSubmitJobs.py -w Mu_350_puUp -c btagvalidation_cfg.py -d txt_forJobSubmits/rizki_SF_80x_DoubleMuonTag_QCDMuEnriched_BTagMu_mcJPcalib_HLTAK8Jet300_OR_HLTJet300_pt350_puUp.txt -q 8nh
# ./createAndSubmitJobs.py -w Mu_250_puUp -c btagvalidation_cfg.py -d txt_forJobSubmits/rizki_SF_80x_DoubleMuonTag_QCDMuEnriched_BTagMu_mcJPcalib_HLTDiJet170_pt250to350_puUp.txt -q 8nh

# ./createAndSubmitJobs.py -w Mu_350_dataJPcalib -c btagvalidation_cfg.py -d txt_forJobSubmits/rizki_SF_80x_DoubleMuonTag_QCDMuEnriched_BTagMu_mcJPcalib_HLTAK8Jet300_OR_HLTJet300_pt350_dataJPcalib.txt -q cmscaf1nh
# ./createAndSubmitJobs.py -w Mu_250_dataJPcalib -c btagvalidation_cfg.py -d txt_forJobSubmits/rizki_SF_80x_DoubleMuonTag_QCDMuEnriched_BTagMu_mcJPcalib_HLTDiJet170_pt250to350_dataJPcalib.txt -q cmscaf1nh

# ./createAndSubmitJobs.py -w Mu_350_run2016BtoF -c btagvalidation_cfg.py -d txt_forJobSubmits/rizki_SF_80x_DoubleMuonTag_QCDMuEnriched_BTagMu_mcJPcalib_HLTJet300_pt350_run2016BtoF.txt -q 8nh
# ./createAndSubmitJobs.py -w Mu_250_run2016BtoF -c btagvalidation_cfg.py -d txt_forJobSubmits/rizki_SF_80x_DoubleMuonTag_QCDMuEnriched_BTagMu_mcJPcalib_HLTDiJet170_pt250to350_run2016BtoF.txt -q 8nh
