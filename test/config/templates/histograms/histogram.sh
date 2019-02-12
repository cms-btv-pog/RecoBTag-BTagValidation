#!/bin/bash

export SCRAM_ARCH=<SCRAM_ARCH>
export X509_USER_PROXY=<X509_USER_PROXY_file>

cd <CMSSW_dir>
eval `scramv1 runtime -sh`

cd -
cp <X509_USER_PROXY_path> .
cmsRun <path_batch_file_wo_ext>.py
rm <X509_USER_PROXY_file>

