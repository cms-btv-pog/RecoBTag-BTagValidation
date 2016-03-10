#!/usr/bin/env python

import ROOT

pt = '425'

f = '/afs/cern.ch/work/r/rsyarif/work/HbbTagVal/Feb06-2016_SubjetPtReweight/CMSSW_7_6_3/src/RecoBTag/BTagValidation/test/rizki_LXBatch_BulkGravTohhTohbbhbb_narrow_M-1000_useSoftDrop_fjpt425_50m_DoubleMuTag_merged/Final_histograms_btagval.root'

if (pt=='425') : f2 = '/afs/cern.ch/work/r/rsyarif/work/HbbTagVal/Feb06-2016_SubjetPtReweight/CMSSW_7_6_3/src/RecoBTag/BTagValidation/test/rizki_LXBatch_QCDMuEnriched_useSoftDrop_fjpt425_50m_DoubleMuTag_merged/Final_histograms_btagval.root'

SV1EnergyRatio_data = ROOT.TH1D("SV1EnergyRatio_signalmc", ";;SV Energy Ratio (1^{st}) ;;",100,-1,4)
SV1EnergyRatio_mc_noweight = ROOT.TH1D("SV1EnergyRatio_mc_noweight",";;SV Energy Ratio (1^{st})  ;;",100,-1,4)
SV1EnergyRatio_mc_reweight = ROOT.TH1D("SV1EnergyRatio_mc_reweight",";;SV Energy Ratio (1^{st})  ;;",100,-1,4)
SV1EnergyRatioweight_mc_data = ROOT.TH1D("SV1EnergyRatioweight_mc_data",";;SV Energy Ratio (1^{st})  ;;",100,-1,4) #its really for mc signal/bkg, NOT data/MC!


fin = ROOT.TFile.Open(f, "READ")
h = fin.Get("SIGNAL__FatJet_tau1_vertexEnergyRatio_bfromg")
fin2 = ROOT.TFile.Open(f2, "READ")  
h2 = fin2.Get("QCD__FatJet_tau1_vertexEnergyRatio_bfromg")
integral = h.Integral()
integral2 = h2.Integral()
h.Scale(1./integral)
h2.Scale(1./integral2)
SV1EnergyRatio_data.Add(h)
SV1EnergyRatio_mc_noweight.Add(h2)
fin.Close()
  
#for f in files_mc: 
#  fin = ROOT.TFile.Open(f, "READ")
#  h = fin.Get("/btagval/h1_fatjet_pt")
#  SV1EnergyRatio_mc_noweight.Add(h)
#  fin.Close()

#integral = SV1EnergyRatio_mc_noweight.Integral()
#SV1EnergyRatio_mc_noweight.Scale(1./integral)

nbins = SV1EnergyRatio_data.GetNbinsX()
for ibin in xrange(1, nbins+1):
  ndata = SV1EnergyRatio_data.GetBinContent(ibin)
  nmc = SV1EnergyRatio_mc_noweight.GetBinContent(ibin)
  wt = ndata/nmc if nmc else ndata 
  SV1EnergyRatioweight_mc_data.SetBinContent(ibin, wt)
  SV1EnergyRatio_mc_reweight.SetBinContent(ibin, nmc*wt)
  print "bin", ibin , " wt", wt

fout = ROOT.TFile("SV1EnergyRatio_Hbb_QCDbb_pt"+pt+"_weight.root", "RECREATE")
fout.cd()
SV1EnergyRatio_data.Write()
SV1EnergyRatio_mc_noweight.Write()
SV1EnergyRatio_mc_reweight.Write()
SV1EnergyRatioweight_mc_data.Write()
fout.Close()

SV1EnergyRatio_mc_noweight.SetLineStyle(2)
SV1EnergyRatio_mc_noweight.SetLineColor(2)

c0 = ROOT.TCanvas()
c0.cd()
SV1EnergyRatio_data.Draw("histe0")
SV1EnergyRatio_mc_noweight.Draw("histsame")

leg = ROOT.TLegend(0.6,0.7,0.88,0.88)
leg.AddEntry(SV1EnergyRatio_data, "Hbb MC")
leg.AddEntry(SV1EnergyRatio_mc_noweight, "QCD MC")
leg.Draw()

c0.SaveAs("SV1EnergyRatio_Hbb_QCDbb_pt"+pt+"_noweight.pdf")
  
c1 = ROOT.TCanvas()
c1.cd()
SV1EnergyRatio_data.Draw("histe0")
SV1EnergyRatio_mc_reweight.Draw("histsame")

leg = ROOT.TLegend(0.6,0.7,0.88,0.88)
leg.AddEntry(SV1EnergyRatio_data, "data")
leg.AddEntry(SV1EnergyRatio_mc_reweight, "QCD MC")
leg.Draw()

c1.SaveAs("SV1EnergyRatio_Hbb_QCDbb_pt"+pt+"_reweight.pdf")

c2 = ROOT.TCanvas()
c2.cd()
SV1EnergyRatioweight_mc_data.Draw("histe0")

leg = ROOT.TLegend(0.6,0.7,0.88,0.88)
leg.AddEntry(SV1EnergyRatioweight_mc_data, "weight")
leg.Draw()

c1.SaveAs("SV1EnergyRatio_Hbb_QCDbb_pt"+pt+"_weights.pdf")
c1.SaveAs("SV1EnergyRatio_Hbb_QCDbb_pt"+pt+"_weights.C")

