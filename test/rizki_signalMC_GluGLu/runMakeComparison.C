{
	gROOT->ProcessLine(".L makeComparisonBackground.C");

	bool Reweight = false;
	option="425";
	isLog=0;
	makeComparisonBackground("BDTG_SV_bfromg", -1, 1, "Final Discriminator",2,option, isLog, Reweight);
	makeComparisonBackground("jetNTracks_bfromg", 0, 40, "Number of tracks",1,option, isLog, Reweight);
	makeComparisonBackground("nSV_bfromg", 0, 10, "Number of SV",1,option, isLog, Reweight);
	makeComparisonBackground("tau1_vertexEnergyRatio_bfromg", 0, 4, "SV energy ratio (1^{st})",2,option, isLog, Reweight);
	makeComparisonBackground("tau1_vertexMass_bfromg", 0, 50, "SV Mass (1^{st})",2,option, isLog, Reweight);
	makeComparisonBackground("tau2_vertexEnergyRatio_bfromg", 0, 4, "SV energy ratio (2^{nd})",2,option, isLog, Reweight);
	makeComparisonBackground("tau2_vertexMass_bfromg", 0, 50, "SV Mass (2^{nd})",2,option, isLog, Reweight);
	makeComparisonBackground("pt_all_bfromg", 0, 1500, "p_{T}",2,option, isLog, Reweight);
	makeComparisonBackground("mass_bfromg", 0, 400, "Mass",2,option, isLog, Reweight);
	makeComparisonBackground("prunedMass_bfromg", 0, 400, "Mass_{Pruned}",2,option, isLog, Reweight);
	makeComparisonBackground("softdropMass_bfromg", 0, 400, "Mass_{SoftDrop}",2,option, isLog, Reweight);
	makeComparisonBackground("softdropsubjet_ptBalance_bfromg", 0, 1, "Subjets pT_1/(pT_1+pT_2) (softdrop)",1,option, isLog, Reweight);

	isLog=1;
	makeComparisonBackground("BDTG_SV_bfromg", -1, 1, "Final Discriminator",2,option, isLog, Reweight);
	makeComparisonBackground("jetNTracks_bfromg", 0, 40, "Number of tracks",1,option, isLog, Reweight);
	makeComparisonBackground("nSV_bfromg", 0, 10, "Number of SV",1,option, isLog, Reweight);
	makeComparisonBackground("tau1_vertexEnergyRatio_bfromg", 0, 4, "SV energy ratio (1^{st})",2,option, isLog, Reweight);
	makeComparisonBackground("tau1_vertexMass_bfromg", 0, 50, "SV Mass (1^{st})",2,option, isLog, Reweight);
	makeComparisonBackground("tau2_vertexEnergyRatio_bfromg", 0, 4, "SV energy ratio (2^{nd})",2,option, isLog, Reweight);
	makeComparisonBackground("tau2_vertexMass_bfromg", 0, 50, "SV Mass (2^{nd})",2,option, isLog, Reweight);
	makeComparisonBackground("pt_all_bfromg", 0, 1500, "p_{T}",2,option, isLog, Reweight);
	makeComparisonBackground("mass_bfromg", 0, 400, "Mass",2,option, isLog, Reweight);
	makeComparisonBackground("prunedMass_bfromg", 0, 400, "Mass_{Pruned}",2,option, isLog, Reweight);
	makeComparisonBackground("softdropMass_bfromg", 0, 400, "Mass_{SoftDrop}",2,option, isLog, Reweight);
	makeComparisonBackground("softdropsubjet_ptBalance_bfromg", 0, 1, "Subjets pT_1/(pT_1+pT_2) (softdrop)",1,option, isLog, Reweight);

	Reweight = true;
	option="425";
	isLog=0;
	makeComparisonBackground("BDTG_SV_bfromg", -1, 1, "Final Discriminator",2,option, isLog, Reweight);
	makeComparisonBackground("jetNTracks_bfromg", 0, 40, "Number of tracks",1,option, isLog, Reweight);
	makeComparisonBackground("nSV_bfromg", 0, 10, "Number of SV",1,option, isLog, Reweight);
	makeComparisonBackground("tau1_vertexEnergyRatio_bfromg", 0, 4, "SV energy ratio (1^{st})",2,option, isLog, Reweight);
	makeComparisonBackground("tau1_vertexMass_bfromg", 0, 50, "SV Mass (1^{st})",2,option, isLog, Reweight);
	makeComparisonBackground("tau2_vertexEnergyRatio_bfromg", 0, 4, "SV energy ratio (2^{nd})",2,option, isLog, Reweight);
	makeComparisonBackground("tau2_vertexMass_bfromg", 0, 50, "SV Mass (2^{nd})",2,option, isLog, Reweight);
	makeComparisonBackground("pt_all_bfromg", 0, 1500, "p_{T}",2,option, isLog, Reweight);
	makeComparisonBackground("mass_bfromg", 0, 400, "Mass",2,option, isLog, Reweight);
	makeComparisonBackground("prunedMass_bfromg", 0, 400, "Mass_{Pruned}",2,option, isLog, Reweight);
	makeComparisonBackground("softdropMass_bfromg", 0, 400, "Mass_{SoftDrop}",2,option, isLog, Reweight);
	makeComparisonBackground("softdropsubjet_ptBalance_bfromg", 0, 1, "Subjets pT_1/(pT_1+pT_2) (softdrop)",1,option, isLog, Reweight);

	isLog=1;
	makeComparisonBackground("BDTG_SV_bfromg", -1, 1, "Final Discriminator",2,option, isLog, Reweight);
	makeComparisonBackground("jetNTracks_bfromg", 0, 40, "Number of tracks",1,option, isLog, Reweight);
	makeComparisonBackground("nSV_bfromg", 0, 10, "Number of SV",1,option, isLog, Reweight);
	makeComparisonBackground("tau1_vertexEnergyRatio_bfromg", 0, 4, "SV energy ratio (1^{st})",2,option, isLog, Reweight);
	makeComparisonBackground("tau1_vertexMass_bfromg", 0, 50, "SV Mass (1^{st})",2,option, isLog, Reweight);
	makeComparisonBackground("tau2_vertexEnergyRatio_bfromg", 0, 4, "SV energy ratio (2^{nd})",2,option, isLog, Reweight);
	makeComparisonBackground("tau2_vertexMass_bfromg", 0, 50, "SV Mass (2^{nd})",2,option, isLog, Reweight);
	makeComparisonBackground("pt_all_bfromg", 0, 1500, "p_{T}",2,option, isLog, Reweight);
	makeComparisonBackground("mass_bfromg", 0, 400, "Mass",2,option, isLog, Reweight);
	makeComparisonBackground("prunedMass_bfromg", 0, 400, "Mass_{Pruned}",2,option, isLog, Reweight);
	makeComparisonBackground("softdropMass_bfromg", 0, 400, "Mass_{SoftDrop}",2,option, isLog, Reweight);
	makeComparisonBackground("softdropsubjet_ptBalance_bfromg", 0, 1, "Subjets pT_1/(pT_1+pT_2) (softdrop)",1,option, isLog, Reweight);
	

	gROOT->ProcessLine(".q");

} 
