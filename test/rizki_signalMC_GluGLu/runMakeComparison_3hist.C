{
	gROOT->ProcessLine(".L makeComparisonBackground_3hist.C");

	option="425_ptreweight";
// 	option="425_sjptbalancereweight";
	isLog=0;
	makeComparisonBackground_3hist("BDTG_SV_bfromg", -1, 1, "Final Discriminator",2,option, isLog);
	makeComparisonBackground_3hist("jetNTracks_bfromg", 0, 40, "Number of tracks",1,option, isLog);
	makeComparisonBackground_3hist("nSV_bfromg", 0, 10, "Number of SV",1,option, isLog);
	makeComparisonBackground_3hist("tau1_vertexEnergyRatio_bfromg", 0, 4, "SV energy ratio (1^{st})",2,option, isLog);
	makeComparisonBackground_3hist("tau1_vertexMass_bfromg", 0, 50, "SV Mass (1^{st})",2,option, isLog);
	makeComparisonBackground_3hist("tau2_vertexEnergyRatio_bfromg", 0, 4, "SV energy ratio (2^{nd})",2,option, isLog);
	makeComparisonBackground_3hist("tau2_vertexMass_bfromg", 0, 50, "SV Mass (2^{nd})",2,option, isLog);
	makeComparisonBackground_3hist("pt_all_bfromg", 0, 1500, "p_{T}",2,option, isLog);
	makeComparisonBackground_3hist("mass_bfromg", 0, 400, "Mass",2,option, isLog);
	makeComparisonBackground_3hist("prunedMass_bfromg", 0, 400, "Mass_{Pruned}",2,option, isLog);
	makeComparisonBackground_3hist("softdropMass_bfromg", 0, 400, "Mass_{SoftDrop}",2,option, isLog);
	if(option=="425_sjptbalancereweight")makeComparisonBackground_3hist("softdropsubjet_ptBalance_bfromg", 0, 1, "Subjets pT_1/(pT_1+pT_2) (softdrop)",1,option, isLog);

	isLog=1;
	makeComparisonBackground_3hist("BDTG_SV_bfromg", -1, 1, "Final Discriminator",2,option, isLog);
	makeComparisonBackground_3hist("jetNTracks_bfromg", 0, 40, "Number of tracks",1,option, isLog);
	makeComparisonBackground_3hist("nSV_bfromg", 0, 10, "Number of SV",1,option, isLog);
	makeComparisonBackground_3hist("tau1_vertexEnergyRatio_bfromg", 0, 4, "SV energy ratio (1^{st})",2,option, isLog);
	makeComparisonBackground_3hist("tau1_vertexMass_bfromg", 0, 50, "SV Mass (1^{st})",2,option, isLog);
	makeComparisonBackground_3hist("tau2_vertexEnergyRatio_bfromg", 0, 4, "SV energy ratio (2^{nd})",2,option, isLog);
	makeComparisonBackground_3hist("tau2_vertexMass_bfromg", 0, 50, "SV Mass (2^{nd})",2,option, isLog);
	makeComparisonBackground_3hist("pt_all_bfromg", 0, 1500, "p_{T}",2,option, isLog);
	makeComparisonBackground_3hist("mass_bfromg", 0, 400, "Mass",2,option, isLog);
	makeComparisonBackground_3hist("prunedMass_bfromg", 0, 400, "Mass_{Pruned}",2,option, isLog);
	makeComparisonBackground_3hist("softdropMass_bfromg", 0, 400, "Mass_{SoftDrop}",2,option, isLog);
	if(option=="425_sjptbalancereweight")makeComparisonBackground_3hist("softdropsubjet_ptBalance_bfromg", 0, 1, "Subjets pT_1/(pT_1+pT_2) (softdrop)",1,option, isLog);	

	gROOT->ProcessLine(".q");

} 
