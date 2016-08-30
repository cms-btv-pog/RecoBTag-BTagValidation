#!/usr/bin/env python

import ROOT

dir = "/afs/cern.ch/user/r/rsyarif/workHere/HbbTagVal/July27-2016_SFMeasurement/CMSSW_8_0_12/src/RecoBTag/BTagValidation/test/";
fname = 'rizki_SF_80x_DoubleMuonTag_BTagMu_QCDMuEnriched_dataWithMCJP_v2_12p9_correctedJP'
f = dir+fname+'_merged/Final_DoubleMuonTaggedFatJets_MuonEnrichedJets_dataWithMCJP_histograms_btagval.root'


files_data = [
f
]

var = "FatJet_pt_all"
bins = 500
xmin = 0.
xmax = 5000.
isLog = False

var_data = ROOT.TH1D("var_data", ";pT(all jets);;",bins,xmin,xmax)
var_mc_noweight = ROOT.TH1D("var_mc_noweight",";pT(all jets);;",bins,xmin,xmax)
var_mc_reweight = ROOT.TH1D("var_mc_reweight",";pT(all jets);;",bins,xmin,xmax)
varweight_mc_data = ROOT.TH1D("varweight_mc_data",";pT(all jets);;",bins,xmin,xmax)

for f in files_data:
  fin = ROOT.TFile.Open(f, "READ")
  h_data = fin.Get("DATA__"+var+"_data")
  h_qcd_b  = fin.Get("QCD__"+var+"_b")
  h_qcd_c  = fin.Get("QCD__"+var+"_c")
  h_qcd_l  = fin.Get("QCD__"+var+"_l")
  h_qcd_bfromg  = fin.Get("QCD__"+var+"_bfromg")
  h_qcd_cfromg  = fin.Get("QCD__"+var+"_cfromg")
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
  varweight_mc_data.SetBinContent(ibin, wt)
  var_mc_reweight.SetBinContent(ibin, nmc*wt)
  print "bin", ibin ," ndata",ndata," nmc",nmc, " wt", wt
  
fout = ROOT.TFile(var+"_data_mc_weight_"+fname+".root", "RECREATE")
fout.cd()
var_data.Write()
var_mc_noweight.Write()
var_mc_reweight.Write()
varweight_mc_data.Write()
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

c0.SaveAs(var+"_mc_data_noweight_"+fname+".pdf")
  
c1 = ROOT.TCanvas()
c1.cd()
if isLog: c1.SetLogy()
var_data.Draw("histe0")
var_mc_reweight.Draw("histsame")

leg = ROOT.TLegend(0.6,0.7,0.88,0.88)
leg.AddEntry(var_data, "data")
leg.AddEntry(var_mc_reweight, "QCD MC")
leg.Draw()

c1.SaveAs(var+"_mc_data_reweight_"+fname+".pdf")
