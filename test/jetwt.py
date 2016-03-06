#!/usr/bin/env python

import ROOT

files_data = [
'FatJets_76X_FatJetsDoubleMuTagged_PUWt_07Feb2016/Final_histograms_btagval_DoubleMuonTaggedFatJets_MuonEnrichedJets.root'
]

jetpt_data = ROOT.TH1D("jetpt_data", ";pT(all jets);;",500,0.,5000.)
jetpt_mc_noweight = ROOT.TH1D("jetpt_mc_noweight",";pT(all jets);;",500,0.,5000.)
jetpt_mc_reweight = ROOT.TH1D("jetpt_mc_reweight",";pT(all jets);;",500,0.,5000.)
jetptweight_mc_data = ROOT.TH1D("jetptweight_mc_data",";pT(all jets);;",500,0.,5000.)

jetmass_data          = ROOT.TH1D("jetmass_data"         ,";M(all jets);",40,0.,400)
jetmass_mc_noweight   = ROOT.TH1D("jetmass_mc_noweight"  ,";M(all jets);",40,0.,400)
jetmass_mc_reweight   = ROOT.TH1D("jetmass_mc_reweight"  ,";M(all jets);",40,0.,400)
jetmassweight_mc_data = ROOT.TH1D("jetmassweight_mc_data",";M(all jets);",40,0.,400)

for f in files_data:
  fin = ROOT.TFile.Open(f, "READ")
  #hptdata = fin.Get("DATA__h1_fatjet_pt")
  #hptqcd  = fin.Get("QCD__h1_fatjet_pt")
  hpt_data = fin.Get("DATA__SoftDropSubJet_pt_all_data")
  hpt_qcd_b  = fin.Get("QCD__SoftDropSubJet_pt_all_b")
  hpt_qcd_c  = fin.Get("QCD__SoftDropSubJet_pt_all_c")
  hpt_qcd_l  = fin.Get("QCD__SoftDropSubJet_pt_all_l")
  hpt_qcd_bfromg  = fin.Get("QCD__SoftDropSubJet_pt_all_bfromg")
  hpt_qcd_cfromg  = fin.Get("QCD__SoftDropSubJet_pt_all_cfromg")
  hpt_qcd = hpt_qcd_b.Clone("hptqcd")
  hpt_qcd.Add(hpt_qcd_c)
  hpt_qcd.Add(hpt_qcd_l)
  hpt_qcd.Add(hpt_qcd_bfromg)
  hpt_qcd.Add(hpt_qcd_cfromg)
  integral_data = hpt_data.Integral()
  integral_qcd = hpt_qcd.Integral()
  hpt_data.Scale(1./integral_data)
  hpt_qcd.Scale(1./integral_qcd)
  jetpt_data.Add(hpt_data)
  jetpt_mc_noweight.Add(hpt_qcd)
  fin.Close()
  
nbins = jetpt_data.GetNbinsX()
for ibin in xrange(1, nbins+1):
  ndata = jetpt_data.GetBinContent(ibin)
  nmc = jetpt_mc_noweight.GetBinContent(ibin)
  wt = ndata/nmc if nmc else ndata if ndata > 0 else 1
  jetptweight_mc_data.SetBinContent(ibin, wt)
  jetpt_mc_reweight.SetBinContent(ibin, nmc*wt)
  print "bin", ibin , " wt", wt

#for f in files_data:
#  fin = ROOT.TFile.Open(f, "READ")
#  hmassdata = fin.Get("DATA__FatJet_mass_data")
#  hmass_b  = fin.Get("QCD__h1_fatjet_b")
#  hmass_c  = fin.Get("QCD__h1_fatjet_c")     
#  hmass_l  = fin.Get("QCD__h1_fatjet_l")     
#  hmass_bfromg  = fin.Get("QCD__h1_fatjet_bfromg")
#  hmass_cfromg  = fin.Get("QCD__h1_fatjet_cfromg")
#
#  integral_data = hmassdata.Integral()
#  integral_qcd = hmassqcd.Integral()
#  hmassdata.Scale(1./integral_data)
#  hmassqcd.Scale(1./integral_qcd)
#  jetmass_data.Add(hmassdata)
#  jetmass_mc_noweight.Add(hmassqcd)
#  fin.Close()
  
nbins = jetmass_data.GetNbinsX()
for ibin in xrange(1, nbins+1):
  ndata = jetmass_data.GetBinContent(ibin)
  nmc = jetmass_mc_noweight.GetBinContent(ibin)
  wt = ndata/nmc if nmc else ndata if ndata > 0 else 1
  jetmassweight_mc_data.SetBinContent(ibin, wt)
  jetmass_mc_reweight.SetBinContent(ibin, nmc*wt)
  print "bin", ibin , " wt", wt

fout = ROOT.TFile("SoftDropSubJetPt_data_mc_DoubleMuonTagged_QCDMuEnriched_76XMiniAODv2.root", "RECREATE")
fout.cd()
jetpt_data.Write()
jetpt_mc_noweight.Write()
jetpt_mc_reweight.Write()
jetptweight_mc_data.Write()
fout.Close()

jetpt_mc_noweight.SetLineStyle(2)
jetpt_mc_noweight.SetLineColor(2)

c0 = ROOT.TCanvas()
c0.cd()
c0.SetLogy()
jetpt_data.Draw("histe0")
jetpt_mc_noweight.Draw("histsame")

leg = ROOT.TLegend(0.6,0.7,0.88,0.88)
leg.AddEntry(jetpt_data, "data")
leg.AddEntry(jetpt_mc_noweight, "QCD MC")
leg.Draw()

c0.SaveAs("jetpt_mc_data_noweight_25ns__MINIAOD.pdf")
  
c1 = ROOT.TCanvas()
c1.cd()
c1.SetLogy()
jetpt_data.Draw("histe0")
jetpt_mc_reweight.Draw("histsame")

leg = ROOT.TLegend(0.6,0.7,0.88,0.88)
leg.AddEntry(jetpt_data, "data")
leg.AddEntry(jetpt_mc_reweight, "QCD MC")
leg.Draw()

c1.SaveAs("jetpt_mc_data_reweight_25ns__MINIAOD.pdf")
