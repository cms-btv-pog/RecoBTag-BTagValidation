#!/usr/bin/env python


import ROOT
import os

/afs/cern.ch/work/d/devdatta/CMSREL/BTagging/CMSSW_9_4_12/src/RecoBTag/BTagValidation/test/dataMC_pt_reweight/../BATCH_Moriond2019_RunIIMiniAOD_17June2018_Nominal/Final_histograms_btagval.root

dir = "/afs/cern.ch/work/d/devdatta/CMSREL/BTagging/CMSSW_9_4_12/src/RecoBTag/BTagValidation/test/"
fname = 'Mu_350'
f = dir+fname+'_merged/Final_DoubleMuonTaggedFatJets_MuonEnrichedJets_dataWithMCJP_histograms_btagval.root'


files_data = [
f
]

jetpt_data = ROOT.TH1D("jetpt_data", ";pT(all jets);;",500,0.,5000.)
jetpt_mc_noweight = ROOT.TH1D("jetpt_mc_noweight",";pT(all jets);;",500,0.,5000.)
jetpt_mc_reweight = ROOT.TH1D("jetpt_mc_reweight",";pT(all jets);;",500,0.,5000.)
jetptweight_mc_data = ROOT.TH1D("jetptweight_mc_data",";pT(all jets);;",500,0.,5000.)

hpt_qcd = ROOT.TH1D("jetpt_mc", ";pT(all jets);;",500,0.,5000.)

for f in files_data:
  fin = ROOT.TFile.Open(f, "READ")
  hpt_data = fin.Get("DATA__FatJet_pt_all_data")
  hpt_qcd_b  = fin.Get("QCD__FatJet_pt_all_b")
  hpt_qcd_c  = fin.Get("QCD__FatJet_pt_all_c")
  hpt_qcd_l  = fin.Get("QCD__FatJet_pt_all_l")
  hpt_qcd_bfromg  = fin.Get("QCD__FatJet_pt_all_bfromg")
  hpt_qcd_cfromg  = fin.Get("QCD__FatJet_pt_all_cfromg")
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
#   wt = ndata/nmc if nmc else ndata if ndata > 0 else 1 #why do we need 0/0 = 1 instead of 0/0 = 0 ? - rizki
  wt = ndata/nmc if nmc else ndata #why do we need 0/0 = 1 instead of 0/0 = 0 ? - rizki
  jetptweight_mc_data.SetBinContent(ibin, wt)
  jetpt_mc_reweight.SetBinContent(ibin, nmc*wt)
  print "bin", ibin ," ndata",ndata," nmc",nmc, " wt", wt
  
fout = ROOT.TFile("FatJetPt_data_mc_weight_"+fname+".root", "RECREATE")
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

c0.SaveAs("FatJetPt_mc_data_noweight_"+fname+".pdf")
  
c1 = ROOT.TCanvas()
c1.cd()
c1.SetLogy()
jetpt_data.Draw("histe0")
jetpt_mc_reweight.Draw("histsame")

leg = ROOT.TLegend(0.6,0.7,0.88,0.88)
leg.AddEntry(jetpt_data, "data")
leg.AddEntry(jetpt_mc_reweight, "QCD MC")
leg.Draw()

c1.SaveAs("FatJetPt_mc_data_reweight_"+fname+".pdf")
