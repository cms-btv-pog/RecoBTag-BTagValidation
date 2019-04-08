#!/usr/bin/env python

import ROOT
import os

def main(f,var,bins,xmin,xmax,isLog):


	var_data = ROOT.TH1D(var+"_data", ";pT(all jets);;",bins,xmin,xmax)
	var_mc_noweight = ROOT.TH1D(var+"_mc_noweight",";pT(all jets);;",bins,xmin,xmax)
	var_mc_reweight = ROOT.TH1D(var+"_mc_reweight",";pT(all jets);;",bins,xmin,xmax)
	varweight_data_mc = ROOT.TH1D(var+"_weight_data_mc",";pT(all jets);;",bins,xmin,xmax)
	
	QCDstr = "QCDMuEnr";

	fin = ROOT.TFile.Open(f, "READ")
	h_data = fin.Get("DATA__"+var+"_data")
	h_qcd_b  = fin.Get(QCDstr+"__"+var+"_b")
	h_qcd_c  = fin.Get(QCDstr+"__"+var+"_c")
	h_qcd_l  = fin.Get(QCDstr+"__"+var+"_l")
	h_qcd_bfromg  = fin.Get(QCDstr+"__"+var+"_bfromg")
	h_qcd_cfromg  = fin.Get(QCDstr+"__"+var+"_cfromg")
	h_qcd = h_qcd_b.Clone("hqcd")
	h_qcd.Add(h_qcd_c)
	h_qcd.Add(h_qcd_l)
	h_qcd.Add(h_qcd_bfromg)
	h_qcd.Add(h_qcd_cfromg)
	integral_data = h_data.Integral()
	integral_qcd = h_qcd.Integral()
	h_data.Scale(1./integral_data)
	h_qcd.Scale(1./integral_qcd)
	var_data.Add(h_data)
	var_mc_noweight.Add(h_qcd)
	fin.Close()
  
	nbins = var_data.GetNbinsX()
	for ibin in xrange(1, nbins+1):
	  ndata = var_data.GetBinContent(ibin)
	  nmc = var_mc_noweight.GetBinContent(ibin)
	#   wt = ndata/nmc if nmc else ndata if ndata > 0 else 1 #why do we need 0/0 = 1 instead of 0/0 = 0 ? - rizki
	  wt = ndata/nmc if nmc else ndata #why do we need 0/0 = 1 instead of 0/0 = 0 ? - rizki
	  varweight_data_mc.SetBinContent(ibin, wt)
	  var_mc_reweight.SetBinContent(ibin, nmc*wt)
	  print "bin", ibin ," ndata",ndata," nmc",nmc, " wt", wt
  
	fout = ROOT.TFile(var+"_data_mc_weight_"+fname+".root", "RECREATE")
	fout.cd()
	var_data.Write()
	var_mc_noweight.Write()
	var_mc_reweight.Write()
	varweight_data_mc.Write()
	fout.Close()

	var_mc_noweight.SetLineStyle(2)
	var_mc_noweight.SetLineColor(2)

	c0 = ROOT.TCanvas()
	c0.cd()
	if isLog: c0.SetLogy()
	var_data.Draw("histe0")
	var_mc_noweight.Draw("histsame")

	leg = ROOT.TLegend(0.6,0.7,0.88,0.88)
	leg.AddEntry(var_data, "data")
	leg.AddEntry(var_mc_noweight, "QCD MC")
	leg.Draw()

	c0.SaveAs(var+"_data_mc_noweight_"+fname+".pdf")
  
	c1 = ROOT.TCanvas()
	c1.cd()
	if isLog: c1.SetLogy()
	var_data.Draw("histe0")
	var_mc_reweight.Draw("histsame")

	leg = ROOT.TLegend(0.6,0.7,0.88,0.88)
	leg.AddEntry(var_data, "data")
	leg.AddEntry(var_mc_reweight, "QCD MC")
	leg.Draw()

	c1.SaveAs(var+"_data_mc_reweight_"+fname+".pdf")


if __name__ == "__main__":

	dir = "/afs/cern.ch/user/r/rsyarif/workHere/HbbTagVal/Jan10-2018_CommSF_v1/CMSSW_9_4_1/src/RecoBTag/BTagValidation/BTV/results/plots_final"

# 	var = "FatJet_pt_all"
# 	bins = 500
# 	xmin = 0.
# 	xmax = 5000.
# 	isLog = False
# 
# 	fname = 'Run2017BCDEF_ReReco_QCDMuonEnriched_AK8Jet300orAK4Jet300_Pt350_Final_DoubleMuonTaggedFatJets_histograms_btagval_v3'
# 	f = dir+'/'+fname+'.root'	
# 	main(f,var,bins,xmin,xmax,isLog)
# 
# 	fname = 'Run2017BCDEF_ReReco_QCDMuonEnriched_AK4DiJet170_Pt250_Final_DoubleMuonTaggedFatJets_histograms_btagval_v1_v3'
# 	f = dir+'/'+fname+'.root'	
# 	main(f,var,bins,xmin,xmax,isLog)
# 
# 	fname = 'Run2017B_ReReco_QCDMuonEnriched_AK8Jet300orAK4Jet300_Pt350_Final_DoubleMuonTaggedFatJets_histograms_btagval_v3'
# 	f = dir+'/'+fname+'.root'	
# 	main(f,var,bins,xmin,xmax,isLog)
# 
# 	fname = 'Run2017B_ReReco_QCDMuonEnriched_AK4DiJet170_Pt250_Final_DoubleMuonTaggedFatJets_histograms_btagval_v1_v3'
# 	f = dir+'/'+fname+'.root'	
# 	main(f,var,bins,xmin,xmax,isLog)
# 
# 	fname = 'Run2017CDE_ReReco_QCDMuonEnriched_AK8Jet300orAK4Jet300_Pt350_Final_DoubleMuonTaggedFatJets_histograms_btagval_v3'
# 	f = dir+'/'+fname+'.root'	
# 	main(f,var,bins,xmin,xmax,isLog)
# 
# 	fname = 'Run2017CDE_ReReco_QCDMuonEnriched_AK4DiJet170_Pt250_Final_DoubleMuonTaggedFatJets_histograms_btagval_v1_v3'
# 	f = dir+'/'+fname+'.root'	
# 	main(f,var,bins,xmin,xmax,isLog)
# 
# 	fname = 'Run2017EF_ReReco_QCDMuonEnriched_AK8Jet300orAK4Jet300_Pt350_Final_DoubleMuonTaggedFatJets_histograms_btagval_v3'
# 	f = dir+'/'+fname+'.root'	
# 	main(f,var,bins,xmin,xmax,isLog)
# 
# 	fname = 'Run2017EF_ReReco_QCDMuonEnriched_AK4DiJet170_Pt250_Final_DoubleMuonTaggedFatJets_histograms_btagval_v1_v3'
# 	f = dir+'/'+fname+'.root'	
# 	main(f,var,bins,xmin,xmax,isLog)


# 
# 	fname = 'Run2017BCDEF_ReReco_QCDMuonEnriched_AK8Jet300orAK4Jet300_Pt350_Final_DoubleMuonTaggedFatJets_histograms_btagval_v2'
# 	f = dir+'/'+fname+'.root'	
# 	main(f,var,bins,xmin,xmax,isLog)
# 
# 	fname = 'Run2017BCDEF_ReReco_QCDMuonEnriched_AK4DiJet170_Pt250_Final_DoubleMuonTaggedFatJets_histograms_btagval_v1_v2'
# 	f = dir+'/'+fname+'.root'	
# 	main(f,var,bins,xmin,xmax,isLog)
# 
# 	fname = 'Run2017BCDEF_ReReco_QCDMuonEnriched_AK8DiJet170orAK4DiJet170_Pt250_Final_DoubleMuonTaggedFatJets_histograms_btagval_v2_v2'
# 	f = dir+'/'+fname+'.root'	
# 	main(f,var,bins,xmin,xmax,isLog)


	var = "FatJet_track_multi"
	bins = 80
	xmin = -0.5
	xmax = 79.5
	isLog = False


# 	fname = 'Run2017BCDEF_ReReco_QCDMuonEnriched_AK8Jet300orAK4Jet300_Pt350_Final_DoubleMuonTaggedFatJets_histograms_btagval_v3_ptReweighted'
# 	f = dir+'/'+fname+'.root'	
# 	main(f,var,bins,xmin,xmax,isLog)
# 
# 	fname = 'Run2017BCDEF_ReReco_QCDMuonEnriched_AK4DiJet170_Pt250_Final_DoubleMuonTaggedFatJets_histograms_btagval_v1_v3_ptReweighted'
# 	f = dir+'/'+fname+'.root'	
# 	main(f,var,bins,xmin,xmax,isLog)

	fname = 'Run2017B_ReReco_QCDMuonEnriched_AK8Jet300orAK4Jet300_Pt350_Final_DoubleMuonTaggedFatJets_histograms_btagval_v3_ptReweighted'
	f = dir+'/'+fname+'.root'	
	main(f,var,bins,xmin,xmax,isLog)

	fname = 'Run2017B_ReReco_QCDMuonEnriched_AK4DiJet170_Pt250_Final_DoubleMuonTaggedFatJets_histograms_btagval_v1_v3_ptReweighted'
	f = dir+'/'+fname+'.root'	
	main(f,var,bins,xmin,xmax,isLog)

	fname = 'Run2017CDE_ReReco_QCDMuonEnriched_AK8Jet300orAK4Jet300_Pt350_Final_DoubleMuonTaggedFatJets_histograms_btagval_v3_ptReweighted'
	f = dir+'/'+fname+'.root'	
	main(f,var,bins,xmin,xmax,isLog)

	fname = 'Run2017CDE_ReReco_QCDMuonEnriched_AK4DiJet170_Pt250_Final_DoubleMuonTaggedFatJets_histograms_btagval_v1_v3_ptReweighted'
	f = dir+'/'+fname+'.root'	
	main(f,var,bins,xmin,xmax,isLog)

	fname = 'Run2017EF_ReReco_QCDMuonEnriched_AK8Jet300orAK4Jet300_Pt350_Final_DoubleMuonTaggedFatJets_histograms_btagval_v3_ptReweighted'
	f = dir+'/'+fname+'.root'	
	main(f,var,bins,xmin,xmax,isLog)

	fname = 'Run2017EF_ReReco_QCDMuonEnriched_AK4DiJet170_Pt250_Final_DoubleMuonTaggedFatJets_histograms_btagval_v1_v3_ptReweighted'
	f = dir+'/'+fname+'.root'	
	main(f,var,bins,xmin,xmax,isLog)


# 	fname = 'Run2017BCDEF_ReReco_QCDMuonEnriched_AK8Jet300orAK4Jet300_Pt350_Final_DoubleMuonTaggedFatJets_histograms_btagval_v2_ptReweighted'
# 	f = dir+'/'+fname+'.root'	
# 	main(f,var,bins,xmin,xmax,isLog)
# 
# 	fname = 'Run2017BCDEF_ReReco_QCDMuonEnriched_AK4DiJet170_Pt250_Final_DoubleMuonTaggedFatJets_histograms_btagval_v1_v2_ptReweighted'
# 	f = dir+'/'+fname+'.root'	
# 	main(f,var,bins,xmin,xmax,isLog)
