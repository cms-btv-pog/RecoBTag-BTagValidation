#!/bin/bash

./createAndSubmitJobs.py -w Mu_350 -c btagvalidation_cfg.py -d txt_forJobSubmits/rizki_SF_80x_DoubleMuonTag_QCDMuEnriched_BTagMu_mcJPcalib_HLTAK8Jet300_OR_HLTJet300_pt350.txt -q 8nh
./createAndSubmitJobs.py -w Mu_250 -c btagvalidation_cfg.py -d txt_forJobSubmits/rizki_SF_80x_DoubleMuonTag_QCDMuEnriched_BTagMu_mcJPcalib_HLTDiJet170_pt250to350.txt -q 8nh

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

./createAndSubmitJobs.py -w Mu_350_dataJPcalib -c btagvalidation_cfg.py -d txt_forJobSubmits/rizki_SF_80x_DoubleMuonTag_QCDMuEnriched_BTagMu_mcJPcalib_HLTAK8Jet300_OR_HLTJet300_pt350_dataJPcalib.txt -q cmscaf1nh
./createAndSubmitJobs.py -w Mu_250_dataJPcalib -c btagvalidation_cfg.py -d txt_forJobSubmits/rizki_SF_80x_DoubleMuonTag_QCDMuEnriched_BTagMu_mcJPcalib_HLTDiJet170_pt250to350_dataJPcalib.txt -q cmscaf1nh

# ./createAndSubmitJobs.py -w Mu_350_run2016BtoF -c btagvalidation_cfg.py -d txt_forJobSubmits/rizki_SF_80x_DoubleMuonTag_QCDMuEnriched_BTagMu_mcJPcalib_HLTJet300_pt350_run2016BtoF.txt -q 8nh
# ./createAndSubmitJobs.py -w Mu_250_run2016BtoF -c btagvalidation_cfg.py -d txt_forJobSubmits/rizki_SF_80x_DoubleMuonTag_QCDMuEnriched_BTagMu_mcJPcalib_HLTDiJet170_pt250to350_run2016BtoF.txt -q 8nh
