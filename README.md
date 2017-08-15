BTagValidation
==============

Boosted b-tag validation analysis 

To set up:

Follow the directions to clone cms-btv-pog/RecoBTag-PerformanceMeasurements at https://github.com/cms-btv-pog/RecoBTag-PerformanceMeasurements

After setting up the PerformanceMeasurements package:

``
cd CMSSW_9_2_2/src      

git clone git@github.com:cms-btv-pog/RecoBTag-BTagValidation.git RecoBTag/BTagValidation -b commissioning_92X --depth 1

scram b -j8

cd RecoBTag/BTagValidation/test/

cmsRun btagvalidation_cfg.py
``
