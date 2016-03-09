#!/usr/bin/env python

import ROOT

pt = '425'

f = '/afs/cern.ch/work/r/rsyarif/work/HbbTagVal/Feb06-2016_SubjetPtReweight/CMSSW_7_6_3/src/RecoBTag/BTagValidation/test/rizki_LXBatch_BulkGravTohhTohbbhbb_narrow_M-1000_useSoftDrop_fjpt425_50m_DoubleMuTag_merged/Final_histograms_btagval.root'

if (pt=='425') : f2 = '/afs/cern.ch/work/r/rsyarif/work/HbbTagVal/Feb06-2016_SubjetPtReweight/CMSSW_7_6_3/src/RecoBTag/BTagValidation/test/rizki_LXBatch_QCDMuEnriched_useSoftDrop_fjpt425_50m_DoubleMuTag_merged/Final_histograms_btagval.root'

massSoftDrop_data = ROOT.TH1D("massSoftDrop_signalmc", ";;M_{soft drop} (AK8 jets) [GeV];;",200,0,400)
massSoftDrop_mc_noweight = ROOT.TH1D("massSoftDrop_mc_noweight",";;M_{soft drop} (AK8 jets) [GeV];;",200,0,400)
massSoftDrop_mc_reweight = ROOT.TH1D("massSoftDrop_mc_reweight",";;M_{soft drop} (AK8 jets) [GeV];;",200,0,400)
massSoftDropweight_mc_data = ROOT.TH1D("massSoftDropweight_mc_data",";;M_{soft drop} (AK8 jets) [GeV];;",200,0,400) #its really for mc signal/bkg, NOT data/MC!


fin = ROOT.TFile.Open(f, "READ")
h = fin.Get("SIGNAL__FatJet_softdropMass_bfromg")
fin2 = ROOT.TFile.Open(f2, "READ")  
h2 = fin2.Get("QCD__FatJet_softdropMass_bfromg")
integral = h.Integral()
integral2 = h2.Integral()
h.Scale(1./integral)
h2.Scale(1./integral2)
massSoftDrop_data.Add(h)
massSoftDrop_mc_noweight.Add(h2)
fin.Close()
  
#for f in files_mc: 
#  fin = ROOT.TFile.Open(f, "READ")
#  h = fin.Get("/btagval/h1_fatjet_pt")
#  massSoftDrop_mc_noweight.Add(h)
#  fin.Close()

#integral = massSoftDrop_mc_noweight.Integral()
#massSoftDrop_mc_noweight.Scale(1./integral)

nbins = massSoftDrop_data.GetNbinsX()
for ibin in xrange(1, nbins+1):
  ndata = massSoftDrop_data.GetBinContent(ibin)
  nmc = massSoftDrop_mc_noweight.GetBinContent(ibin)
  wt = ndata/nmc if nmc else ndata 
  massSoftDropweight_mc_data.SetBinContent(ibin, wt)
  massSoftDrop_mc_reweight.SetBinContent(ibin, nmc*wt)
  print "bin", ibin , " wt", wt

fout = ROOT.TFile("massSoftDrop_Hbb_QCDbb_pt"+pt+"_weight.root", "RECREATE")
fout.cd()
massSoftDrop_data.Write()
massSoftDrop_mc_noweight.Write()
massSoftDrop_mc_reweight.Write()
massSoftDropweight_mc_data.Write()
fout.Close()

massSoftDrop_mc_noweight.SetLineStyle(2)
massSoftDrop_mc_noweight.SetLineColor(2)

c0 = ROOT.TCanvas()
c0.cd()
massSoftDrop_data.Draw("histe0")
massSoftDrop_mc_noweight.Draw("histsame")

leg = ROOT.TLegend(0.6,0.7,0.88,0.88)
leg.AddEntry(massSoftDrop_data, "Hbb MC")
leg.AddEntry(massSoftDrop_mc_noweight, "QCD MC")
leg.Draw()

c0.SaveAs("massSoftDrop_Hbb_QCDbb_pt"+pt+"_noweight.pdf")
  
c1 = ROOT.TCanvas()
c1.cd()
massSoftDrop_data.Draw("histe0")
massSoftDrop_mc_reweight.Draw("histsame")

leg = ROOT.TLegend(0.6,0.7,0.88,0.88)
leg.AddEntry(massSoftDrop_data, "data")
leg.AddEntry(massSoftDrop_mc_reweight, "QCD MC")
leg.Draw()

c1.SaveAs("massSoftDrop_Hbb_QCDbb_pt"+pt+"_reweight.pdf")

c2 = ROOT.TCanvas()
c2.cd()
massSoftDropweight_mc_data.Draw("histe0")

leg = ROOT.TLegend(0.6,0.7,0.88,0.88)
leg.AddEntry(massSoftDropweight_mc_data, "weight")
leg.Draw()

c1.SaveAs("massSoftDrop_Hbb_QCDbb_pt"+pt+"_weights.pdf")
c1.SaveAs("massSoftDrop_Hbb_QCDbb_pt"+pt+"_weights.C")

