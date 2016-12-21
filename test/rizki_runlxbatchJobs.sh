#!/bin/bash
 
./createAndSubmitJobs.py -w Mu_350 -c btagvalidation_cfg.py -d runningBTagVal_15/txt_forJobSubmits/rizki_SF_80x_DoubleMuonTag_QCDMuEnriched_BTagMu_mcJPcalib_HLTAK8Jet300_pt350.txt -q 1nd
./createAndSubmitJobs.py -w Mu_250 -c btagvalidation_cfg.py -d runningBTagVal_15/txt_forJobSubmits/rizki_SF_80x_DoubleMuonTag_QCDMuEnriched_BTagMu_mcJPcalib_HLTDiJet170_pt250to350.txt -q 1nd
./createAndSubmitJobs.py -w Incl_350 -c btagvalidation_cfg.py -d runningBTagVal_15/txt_forJobSubmits/rizki_SF_80x_DoubleMuonTag_QCDincl_JetHT_mcJPcalib_HLTAK8Jet300_pt350.txt -q 1nd
./createAndSubmitJobs.py -w Incl_250 -c btagvalidation_cfg.py -d runningBTagVal_15/txt_forJobSubmits/rizki_SF_80x_DoubleMuonTag_QCDincl_JetHT_mcJPcalib_HLTDiJet170_pt250to350.txt -q 1nd
                                     