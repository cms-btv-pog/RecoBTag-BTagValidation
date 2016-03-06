#!/usr/bin/env python

import ROOT

pt = '425'

f = '<signalfilepath>.root'

if (pt=='425') : f2 = '<QCDfilepath>.root'

subjetptbalance_data = ROOT.TH1D("subjetptbalance_signalmc", ";pT(all jets);;",100,0.,1.)
subjetptbalance_mc_noweight = ROOT.TH1D("subjetptbalance_mc_noweight",";pT(all jets);;",100,0.,1.)
subjetptbalance_mc_reweight = ROOT.TH1D("subjetptbalance_mc_reweight",";pT(all jets);;",100,0.,1.)
subjetptbalanceweight_mc_data = ROOT.TH1D("subjetptbalanceweight_mc_data",";pT(all jets);;",100,0.,1.)


fin = ROOT.TFile.Open(f, "READ")
h = fin.Get("btagval/FatJet_prunedsubjet_ptBalance_bfromg")
fin2 = ROOT.TFile.Open(f2, "READ")  
h2 = fin2.Get("QCD__FatJet_prunedsubjet_ptBalance_bfromg")
integral = h.Integral()
integral2 = h2.Integral()
h.Scale(1./integral)
h2.Scale(1./integral2)
subjetptbalance_data.Add(h)
subjetptbalance_mc_noweight.Add(h2)
fin.Close()
  
#for f in files_mc: 
#  fin = ROOT.TFile.Open(f, "READ")
#  h = fin.Get("/btagval/h1_fatjet_pt")
#  subjetptbalance_mc_noweight.Add(h)
#  fin.Close()

#integral = subjetptbalance_mc_noweight.Integral()
#subjetptbalance_mc_noweight.Scale(1./integral)

nbins = subjetptbalance_data.GetNbinsX()
for ibin in xrange(1, nbins+1):
  ndata = subjetptbalance_data.GetBinContent(ibin)
  nmc = subjetptbalance_mc_noweight.GetBinContent(ibin)
  wt = ndata/nmc if nmc else ndata 
  subjetptbalanceweight_mc_data.SetBinContent(ibin, wt)
  subjetptbalance_mc_reweight.SetBinContent(ibin, nmc*wt)
  print "bin", ibin , " wt", wt

fout = ROOT.TFile("subjetptbalance_Hbb_QCDbb_pt"+pt+"_weight.root", "RECREATE")
fout.cd()
subjetptbalance_data.Write()
subjetptbalance_mc_noweight.Write()
subjetptbalance_mc_reweight.Write()
subjetptbalanceweight_mc_data.Write()
fout.Close()

subjetptbalance_mc_noweight.SetLineStyle(2)
subjetptbalance_mc_noweight.SetLineColor(2)

c0 = ROOT.TCanvas()
c0.cd()
subjetptbalance_data.Draw("histe0")
subjetptbalance_mc_noweight.Draw("histsame")

leg = ROOT.TLegend(0.6,0.7,0.88,0.88)
leg.AddEntry(subjetptbalance_data, "Hbb MC")
leg.AddEntry(subjetptbalance_mc_noweight, "QCD MC")
leg.Draw()

c0.SaveAs("subjetptbalance_Hbb_QCDbb_"+pt+"_noweight.pdf")
  
c1 = ROOT.TCanvas()
c1.cd()
subjetptbalance_data.Draw("histe0")
subjetptbalance_mc_reweight.Draw("histsame")

leg = ROOT.TLegend(0.6,0.7,0.88,0.88)
leg.AddEntry(subjetptbalance_data, "data")
leg.AddEntry(subjetptbalance_mc_reweight, "QCD MC")
leg.Draw()

c1.SaveAs("subjetptbalance_Hbb_QCDbb_"+pt+"_reweight.pdf")

c2 = ROOT.TCanvas()
c2.cd()
subjetptbalanceweight_mc_data.Draw("histe0")

leg = ROOT.TLegend(0.6,0.7,0.88,0.88)
leg.AddEntry(subjetptbalanceweight_mc_data, "weight")
leg.Draw()

c1.SaveAs("subjetptbalance_Hbb_QCDbb_"+pt+"_weights.pdf")
c1.SaveAs("subjetptbalance_Hbb_QCDbb_"+pt+"_weights.C")

