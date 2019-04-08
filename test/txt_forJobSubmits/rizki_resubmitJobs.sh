#!/bin/bash

# ./checkJobs.py -w Mu_350 -r -q 8nh #cmscaf1nh #1nd 
# ./checkJobs.py -w Mu_250 -r -q 8nh #cmscaf1nh #1nd 
#  
# ./checkJobs.py -w Mu_350_bfragdown -r -q 8nh #cmscaf1nh #1nd 
# ./checkJobs.py -w Mu_250_bfragdown -r -q 8nh #cmscaf1nh #1nd 
# 
# ./checkJobs.py -w Mu_350_bfragup -r -q 8nh #cmscaf1nh #1nd 
# ./checkJobs.py -w Mu_250_bfragup -r -q 8nh #cmscaf1nh #1nd 
# 
# ./checkJobs.py -w Mu_350_CD -r -q 8nh #cmscaf1nh #1nd  
# ./checkJobs.py -w Mu_250_CD -r -q 8nh #cmscaf1nh #1nd  

# ./checkJobs.py -w Mu_350_cfrag -r -q 8nh #cmscaf1nh #1nd 
# ./checkJobs.py -w Mu_250_cfrag -r -q 8nh #cmscaf1nh #1nd
# 
# ./checkJobs.py -w Mu_350_K0L -r -q 8nh #cmscaf1nh #1nd 
# ./checkJobs.py -w Mu_250_K0L -r -q 8nh #cmscaf1nh #1nd
# 
# ./checkJobs.py -w Mu_350_nTracks -r -q 8nh #cmscaf1nh #1nd  
# ./checkJobs.py -w Mu_250_nTracks -r -q 8nh #cmscaf1nh #1nd 
# 
# ./checkJobs.py -w Mu_350_puDown -r -q 8nh #cmscaf1nh #1nd 
# ./checkJobs.py -w Mu_250_puDown -r -q 8nh #cmscaf1nh #1nd 
# 
# ./checkJobs.py -w Mu_350_puUp -r -q 8nh #cmscaf1nh #1nd 
# ./checkJobs.py -w Mu_250_puUp -r -q 8nh #cmscaf1nh #1nd 

# ./checkJobs.py -w Mu_350_dataJPcalib -r -q 8nh #cmscaf1nh #1nd 
# ./checkJobs.py -w Mu_250_dataJPcalib -r -q 8nh #cmscaf1nh #1nd 


eospath=/eos/cms/store/group/phys_btag/BoostedBTag/BTagNTuples/8_0_X_v2.03/BTagValJobs_rizki/

# ./checkJobs_new.py -w Mu_350 -o $eospath -r -q 8nh
# ./checkJobs_new.py -w Mu_250 -o $eospath -r -q 8nh
 
./checkJobs_new.py -w Mu_350_ptReweighted -o $eospath -r -q 8nh  
./checkJobs_new.py -w Mu_250_ptReweighted -o $eospath -r -q 8nh 

./checkJobs_new.py -w Mu_350_bfragdown -o $eospath -r -q 8nh  
./checkJobs_new.py -w Mu_250_bfragdown -o $eospath  -r -q 8nh

./checkJobs_new.py -w Mu_350_bfragup -o $eospath -r -q 8nh
./checkJobs_new.py -w Mu_250_bfragup -o $eospath -r -q 8nh

./checkJobs_new.py -w Mu_350_CD -o $eospath -r -q 8nh
./checkJobs_new.py -w Mu_250_CD -o $eospath -r -q 8nh

# ./checkJobs_new.py -w Mu_350_cfrag -o $eospath -r -q 8nh
# ./checkJobs_new.py -w Mu_250_cfrag -o $eospath -r -q 8nh
# 
# ./checkJobs_new.py -w Mu_350_K0L -o $eospath -r -q 8nh
# ./checkJobs_new.py -w Mu_250_K0L -o $eospath -r -q 8nh
# 
# ./checkJobs_new.py -w Mu_350_nTracks -o $eospath -r -q 8nh
# ./checkJobs_new.py -w Mu_250_nTracks -o $eospath -r -q 8nh
# 
# ./checkJobs_new.py -w Mu_350_puDown -o $eospath -r -q 8nh
# ./checkJobs_new.py -w Mu_250_puDown -o $eospath -r -q 8nh
# 
# ./checkJobs_new.py -w Mu_350_puUp -o $eospath -r -q 8nh  
# ./checkJobs_new.py -w Mu_250_puUp -o $eospath -r -q 8nh 

# ./checkJobs_new.py -w Mu_350_dataJPcalib -o $eospath -r -q cmscaf1nh
# ./checkJobs_new.py -w Mu_250_dataJPcalib -o $eospath -r -q cmscaf1nh
