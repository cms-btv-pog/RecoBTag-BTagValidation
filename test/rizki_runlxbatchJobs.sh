#!/bin/bash
 
./createAndSubmitJobs.py -w Mu_350_noSlimmedTrees -c btagvalidation_cfg.py -d txt_forJobSubmits/rizki_SF_80x_DoubleMuonTag_QCDMuEnriched_BTagMu_mcJPcalib_HLTAK8Jet300_pt350.txt -q cmscaf1nh
./createAndSubmitJobs.py -w Mu_250_noSlimmedTrees -c btagvalidation_cfg.py -d txt_forJobSubmits/rizki_SF_80x_DoubleMuonTag_QCDMuEnriched_BTagMu_mcJPcalib_HLTDiJet170_pt250to350.txt -q cmscaf1nh
