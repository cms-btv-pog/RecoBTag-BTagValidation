#!/bin/bash

# ./createAndSubmitJobs.py -w rizki_commissioning_80x_DoubleMuonTag -c btagvalidation_cfg.py -d rizki_commissioning_80x_DoubleMuonTag_QCDMuEnriched.txt -q cmscaf1nh
# ./createAndSubmitJobs.py -w rizki_commissioning_80x_SingleMuonTag -c btagvalidation_cfg.py -d rizki_commissioning_80x_SingleMuonTag_QCDMuEnriched.txt -q cmscaf1nh


./createAndSubmitJobs.py -w rizki_commissioning_80x_DoubleMuonTag_QCDincl -c btagvalidation_cfg.py -d rizki_commissioning_80x_DoubleMuonTag_QCDincl.txt -q cmscaf1nh
./createAndSubmitJobs.py -w rizki_commissioning_80x_SingleMuonTag_QCDincl -c btagvalidation_cfg.py -d rizki_commissioning_80x_SingleMuonTag_QCDincl.txt -q cmscaf1nh


