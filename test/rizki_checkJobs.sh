#!/bin/bash

# ./checkJobs.py -w Mu_350  
# ./checkJobs.py -w Mu_250 
 
# ./checkJobs.py -w Mu_350_bfragdown  
# ./checkJobs.py -w Mu_250_bfragdown 
# 
# ./checkJobs.py -w Mu_350_bfragup  
# ./checkJobs.py -w Mu_250_bfragup 
# 
# ./checkJobs.py -w Mu_350_CD #- Alice
# ./checkJobs.py -w Mu_250_CD #- Alice

# ./checkJobs.py -w Mu_350_cfrag #- Alice
# ./checkJobs.py -w Mu_250_cfrag #- Alice
# 
# ./checkJobs.py -w Mu_350_K0L 
# ./checkJobs.py -w Mu_250_K0L  
# 
# ./checkJobs.py -w Mu_350_nTracks  
# ./checkJobs.py -w Mu_250_nTracks 
# 
# ./checkJobs.py -w Mu_350_puDown  
# ./checkJobs.py -w Mu_250_puDown 
# 
# ./checkJobs.py -w Mu_350_puUp  
# ./checkJobs.py -w Mu_250_puUp 

# ./checkJobs.py -w Mu_350_dataJPcalib
# ./checkJobs.py -w Mu_250_dataJPcalib

# ./checkJobs.py -w Mu_350_run2016BtoF
# ./checkJobs.py -w Mu_250_run2016BtoF

eospath=/eos/cms/store/group/phys_btag/BoostedBTag/BTagNTuples/8_0_X_v2.03/BTagValJobs_rizki/

# ./checkJobs_new.py -w Mu_350 -o $eospath 
# ./checkJobs_new.py -w Mu_250 -o $eospath

./checkJobs_new.py -w Mu_350_ptReweighted -o $eospath  
./checkJobs_new.py -w Mu_250_ptReweighted -o $eospath 
 
./checkJobs_new.py -w Mu_350_bfragdown -o $eospath  
./checkJobs_new.py -w Mu_250_bfragdown -o $eospath 

./checkJobs_new.py -w Mu_350_bfragup -o $eospath  
./checkJobs_new.py -w Mu_250_bfragup -o $eospath 

./checkJobs_new.py -w Mu_350_CD -o $eospath
./checkJobs_new.py -w Mu_250_CD -o $eospath

./checkJobs_new.py -w Mu_350_cfrag -o $eospath
./checkJobs_new.py -w Mu_250_cfrag -o $eospath

./checkJobs_new.py -w Mu_350_K0L -o $eospath 
./checkJobs_new.py -w Mu_250_K0L -o $eospath  

./checkJobs_new.py -w Mu_350_nTracks -o $eospath  
./checkJobs_new.py -w Mu_250_nTracks -o $eospath 

./checkJobs_new.py -w Mu_350_puDown -o $eospath  
./checkJobs_new.py -w Mu_250_puDown -o $eospath 

./checkJobs_new.py -w Mu_350_puUp -o $eospath  
./checkJobs_new.py -w Mu_250_puUp -o $eospath 

# ./checkJobs_new.py -w Mu_350_dataJPcalib -o $eospath
# ./checkJobs_new.py -w Mu_250_dataJPcalib -o $eospath

