{
	gROOT->ProcessLine(".L makeComparisonBackground.C");

	bool Reweight = false;
	option="425_DoubleMu_SoftDrop";
// 	option="425_SingleMu_Pruned_TightMu";
	isLog=0;

	makeComparisonBackground("z_ratio_bfromg", 0, 30., "z_{ratio}",1,option, isLog, Reweight);

	makeComparisonBackground("JP_bfromg", 0, 2.5, "JP Discriminator",1,option, isLog, Reweight);

	makeComparisonBackground("DoubleB_bfromg", -1, 1, "Final Discriminator",2,option, isLog, Reweight);
	makeComparisonBackground("jetNTracks_bfromg", 0, 40, "Number of tracks",1,option, isLog, Reweight);

	makeComparisonBackground("trackSip2dSigAboveCharm_0_bfromg", -20, 20, "IP Sig 1st Track Above Charm",1,option, isLog, Reweight);
	makeComparisonBackground("trackSip2dSigAboveBottom_0_bfromg", -20, 20, "IP Sig 1st Track Above Bottom",1,option, isLog, Reweight);
	makeComparisonBackground("trackSip2dSigAboveBottom_1_bfromg", -20, 20, "IP Sig 2nd Track Above Bottom",1,option, isLog, Reweight);
	makeComparisonBackground("trackSip3dSig_0_bfromg", -20, 20, "IP Sig 1st track",1,option, isLog, Reweight);
	makeComparisonBackground("trackSip3dSig_1_bfromg", -20, 20, "IP Sig 2nd track",1,option, isLog, Reweight);
	makeComparisonBackground("trackSip3dSig_2_bfromg", -20, 20, "IP Sig 3rd track",1,option, isLog, Reweight);
	makeComparisonBackground("trackSip3dSig_3_bfromg", -20, 20, "IP Sig 4th track",1,option, isLog, Reweight);
	makeComparisonBackground("tau1_trackSip3dSig_0_bfromg", -20, 20, "IP Sig 1st track of SV_{0}",1,option, isLog, Reweight);
	makeComparisonBackground("tau1_trackSip3dSig_1_bfromg", -20, 20, "IP Sig 2nd track of SV_{0}",1,option, isLog, Reweight);
	makeComparisonBackground("tau2_trackSip3dSig_0_bfromg", -20, 20, "IP Sig 1st track of SV_{1}",1,option, isLog, Reweight);
	makeComparisonBackground("tau2_trackSip3dSig_1_bfromg", -20, 20, "IP Sig 2nd track of SV_{1}",1,option, isLog, Reweight);
	makeComparisonBackground("tau1_trackEtaRel_0_bfromg", 0, 10, "EtaRel 1st track for SV_{0}",1,option, isLog, Reweight);
	makeComparisonBackground("tau1_trackEtaRel_1_bfromg", 0, 10, "EtaRel 2nd track for SV_{0}",1,option, isLog, Reweight);
	makeComparisonBackground("tau1_trackEtaRel_2_bfromg", 0, 10, "EtaRel 3rd track for SV_{0}",1,option, isLog, Reweight);
	makeComparisonBackground("tau2_trackEtaRel_0_bfromg", 0, 10, "EtaRel 1st track for SV_{1}",1,option, isLog, Reweight);
	makeComparisonBackground("tau2_trackEtaRel_1_bfromg", 0, 10, "EtaRel 2nd track for SV_{1}",1,option, isLog, Reweight);
	makeComparisonBackground("tau2_trackEtaRel_2_bfromg", 0, 10, "EtaRel 3rd track for SV_{1}",1,option, isLog, Reweight);

	makeComparisonBackground("nSV_bfromg", 0, 10, "Number of SV",1,option, isLog, Reweight);
	makeComparisonBackground("tau1_vertexEnergyRatio_bfromg", 0, 4, "SV energy ratio (1^{st})",2,option, isLog, Reweight);
	makeComparisonBackground("tau1_vertexMass_bfromg", 0, 50, "SV Mass (1^{st})",2,option, isLog, Reweight);
	makeComparisonBackground("tau2_vertexEnergyRatio_bfromg", 0, 4, "SV energy ratio (2^{nd})",2,option, isLog, Reweight);
	makeComparisonBackground("tau2_vertexMass_bfromg", 0, 50, "SV Mass (2^{nd})",2,option, isLog, Reweight);
	makeComparisonBackground("pt_all_bfromg", 0, 1500, "p_{T}",2,option, isLog, Reweight);
	makeComparisonBackground("mass_bfromg", 0, 400, "Mass",2,option, isLog, Reweight);
	makeComparisonBackground("prunedMass_bfromg", 0, 400, "Mass_{Pruned}",2,option, isLog, Reweight);
	makeComparisonBackground("softdropMass_bfromg", 0, 400, "Mass_{SoftDrop}",2,option, isLog, Reweight);
	if(option=="425_DoubleMu_SoftDrop")makeComparisonBackground("softdropsubjet_ptBalance_bfromg", 0, 1, "Subjets pT_{1}/(pT_{1}+pT_{2}) (softdrop)",1,option, isLog, Reweight);
	std::cout<< "check"<< std::endl;
	isLog=1;
	makeComparisonBackground("z_ratio_bfromg", 0, 30., "z_{ratio}",1,option, isLog, Reweight);

	makeComparisonBackground("JP_bfromg", 0, 2.5, "JP Discriminator",1,option, isLog, Reweight);

	makeComparisonBackground("DoubleB_bfromg", -1, 1, "Final Discriminator",2,option, isLog, Reweight);
	makeComparisonBackground("jetNTracks_bfromg", 0, 40, "Number of tracks",1,option, isLog, Reweight);

	makeComparisonBackground("trackSip2dSigAboveCharm_0_bfromg", -20, 20, "IP Sig 1st Track Above Charm",1,option, isLog, Reweight);
	makeComparisonBackground("trackSip2dSigAboveBottom_0_bfromg", -20, 20, "IP Sig 1st Track Above Bottom",1,option, isLog, Reweight);
	makeComparisonBackground("trackSip2dSigAboveBottom_1_bfromg", -20, 20, "IP Sig 2nd Track Above Bottom",1,option, isLog, Reweight);
	makeComparisonBackground("trackSip3dSig_0_bfromg", -20, 20, "IP Sig 1st track",1,option, isLog, Reweight);
	makeComparisonBackground("trackSip3dSig_1_bfromg", -20, 20, "IP Sig 2nd track",1,option, isLog, Reweight);
	makeComparisonBackground("trackSip3dSig_2_bfromg", -20, 20, "IP Sig 3rd track",1,option, isLog, Reweight);
	makeComparisonBackground("trackSip3dSig_3_bfromg", -20, 20, "IP Sig 4th track",1,option, isLog, Reweight);
	makeComparisonBackground("tau1_trackSip3dSig_0_bfromg", -20, 20, "IP Sig 1st track of SV_{0}",1,option, isLog, Reweight);
	makeComparisonBackground("tau1_trackSip3dSig_1_bfromg", -20, 20, "IP Sig 2nd track of SV_{0}",1,option, isLog, Reweight);
	makeComparisonBackground("tau2_trackSip3dSig_0_bfromg", -20, 20, "IP Sig 1st track of SV_{1}",1,option, isLog, Reweight);
	makeComparisonBackground("tau2_trackSip3dSig_1_bfromg", -20, 20, "IP Sig 2nd track of SV_{1}",1,option, isLog, Reweight);
	makeComparisonBackground("tau1_trackEtaRel_0_bfromg", 0, 10, "EtaRel 1st track for SV_{0}",1,option, isLog, Reweight);
	makeComparisonBackground("tau1_trackEtaRel_1_bfromg", 0, 10, "EtaRel 2nd track for SV_{0}",1,option, isLog, Reweight);
	makeComparisonBackground("tau1_trackEtaRel_2_bfromg", 0, 10, "EtaRel 3rd track for SV_{0}",1,option, isLog, Reweight);
	makeComparisonBackground("tau2_trackEtaRel_0_bfromg", 0, 10, "EtaRel 1st track for SV_{1}",1,option, isLog, Reweight);
	makeComparisonBackground("tau2_trackEtaRel_1_bfromg", 0, 10, "EtaRel 2nd track for SV_{1}",1,option, isLog, Reweight);
	makeComparisonBackground("tau2_trackEtaRel_2_bfromg", 0, 10, "EtaRel 3rd track for SV_{1}",1,option, isLog, Reweight);

	makeComparisonBackground("nSV_bfromg", 0, 10, "Number of SV",1,option, isLog, Reweight);
	makeComparisonBackground("tau1_vertexEnergyRatio_bfromg", 0, 4, "SV energy ratio (1^{st})",2,option, isLog, Reweight);
	makeComparisonBackground("tau1_vertexMass_bfromg", 0, 50, "SV Mass (1^{st})",2,option, isLog, Reweight);
	makeComparisonBackground("tau2_vertexEnergyRatio_bfromg", 0, 4, "SV energy ratio (2^{nd})",2,option, isLog, Reweight);
	makeComparisonBackground("tau2_vertexMass_bfromg", 0, 50, "SV Mass (2^{nd})",2,option, isLog, Reweight);
	makeComparisonBackground("pt_all_bfromg", 0, 1500, "p_{T}",2,option, isLog, Reweight);
	makeComparisonBackground("mass_bfromg", 0, 400, "Mass",2,option, isLog, Reweight);
	makeComparisonBackground("prunedMass_bfromg", 0, 400, "Mass_{Pruned}",2,option, isLog, Reweight);
	makeComparisonBackground("softdropMass_bfromg", 0, 400, "Mass_{SoftDrop}",2,option, isLog, Reweight);
	if (option=="425_DoubleMu_SoftDrop")makeComparisonBackground("softdropsubjet_ptBalance_bfromg", 0, 1, "Subjets pT_{1}/(pT_{1}+pT_{2}) (softdrop)",1,option, isLog, Reweight);	

	gROOT->ProcessLine(".q");

} 
