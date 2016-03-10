{
	gROOT->ProcessLine(".L makeComparisonBackground_3hist.C");

	std::vector<TString> option;
	option.push_back("425_ptreweight");
	option.push_back("425_sjptbalancereweight");
	option.push_back("425_massSoftDropreweight");
	option.push_back("425_jetNTracksreweight");

	std::vector<int> isLog;
	isLog.push_back(0);
	isLog.push_back(1);	

	for (int i=0 ; i<option.size();i++){
		cout << "option[" << i << "] = " << option[i] << endl;
		for (int j=0 ; j<isLog.size();j++){
			makeComparisonBackground_3hist("DoubleB_bfromg", -1, 1, "Final Discriminator",2,option[i], isLog[j]);
			makeComparisonBackground_3hist("jetNTracks_bfromg", 0, 40, "Number of tracks",1,option[i], isLog[j]);
			makeComparisonBackground_3hist("nSV_bfromg", 0, 10, "Number of SV",1,option[i], isLog[j]);
			makeComparisonBackground_3hist("tau1_vertexEnergyRatio_bfromg", 0, 4, "SV energy ratio (1^{st})",2,option[i], isLog[j]);
			makeComparisonBackground_3hist("tau1_vertexMass_bfromg", 0, 50, "SV Mass (1^{st})",2,option[i], isLog[j]);
			makeComparisonBackground_3hist("tau2_vertexEnergyRatio_bfromg", 0, 4, "SV energy ratio (2^{nd})",2,option[i], isLog[j]);
			makeComparisonBackground_3hist("tau2_vertexMass_bfromg", 0, 50, "SV Mass (2^{nd})",2,option[i], isLog[j]);
			makeComparisonBackground_3hist("pt_all_bfromg", 0, 1500, "p_{T}",2,option[i], isLog[j]);
			makeComparisonBackground_3hist("mass_bfromg", 0, 400, "Mass",2,option[i], isLog[j]);
			makeComparisonBackground_3hist("prunedMass_bfromg", 0, 400, "Mass_{Pruned}",2,option[i], isLog[j]);
			makeComparisonBackground_3hist("softdropMass_bfromg", 0, 400, "Mass_{SoftDrop}",2,option[i], isLog[j]);
			if(option[i]!="425_ptreweight")makeComparisonBackground_3hist("softdropsubjet_ptBalance_bfromg", 0, 1, "Subjets pT_{1}/(pT_{1}+pT_{2}) (softdrop)",1,option[i], isLog[j]);
		}
	}
	
	gROOT->ProcessLine(".q");

} 
