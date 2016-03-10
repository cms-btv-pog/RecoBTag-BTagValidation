#!/usr/bin/env python

import ROOT

pt = '425'

f = '/afs/cern.ch/work/r/rsyarif/work/HbbTagVal/Feb06-2016_SubjetPtReweight/CMSSW_7_6_3/src/RecoBTag/BTagValidation/test/rizki_LXBatch_BulkGravTohhTohbbhbb_narrow_M-1000_useSoftDrop_fjpt425_50m_DoubleMuTag_merged/Final_histograms_btagval.root'

if (pt=='425') : f2 = '/afs/cern.ch/work/r/rsyarif/work/HbbTagVal/Feb06-2016_SubjetPtReweight/CMSSW_7_6_3/src/RecoBTag/BTagValidation/test/rizki_LXBatch_QCDMuEnriched_useSoftDrop_fjpt425_50m_DoubleMuTag_merged/Final_histograms_btagval.root'

jetNTracks_data = ROOT.TH1D("jetNTracks_signalmc", ";;Number of tracks ;;",40,0,40)
jetNTracks_mc_noweight = ROOT.TH1D("jetNTracks_mc_noweight",";;Number of tracks ;;",40,0,40)
jetNTracks_mc_reweight = ROOT.TH1D("jetNTracks_mc_reweight",";;Number of tracks ;;",40,0,40)
jetNTracksweight_mc_data = ROOT.TH1D("jetNTracksweight_mc_data",";;Number of tracks ;;",40,0,40) #its really for mc signal/bkg, NOT data/MC!


fin = ROOT.TFile.Open(f, "READ")
h = fin.Get("SIGNAL__FatJet_jetNTracks_bfromg")
fin2 = ROOT.TFile.Open(f2, "READ")  
h2 = fin2.Get("QCD__FatJet_jetNTracks_bfromg")
integral = h.Integral()
integral2 = h2.Integral()
h.Scale(1./integral)
h2.Scale(1./integral2)
jetNTracks_data.Add(h)
jetNTracks_mc_noweight.Add(h2)
fin.Close()
  
#for f in files_mc: 
#  fin = ROOT.TFile.Open(f, "READ")
#  h = fin.Get("/btagval/h1_fatjet_pt")
#  jetNTracks_mc_noweight.Add(h)
#  fin.Close()

#integral = jetNTracks_mc_noweight.Integral()
#jetNTracks_mc_noweight.Scale(1./integral)

nbins = jetNTracks_data.GetNbinsX()
for ibin in xrange(1, nbins+1):
  ndata = jetNTracks_data.GetBinContent(ibin)
  nmc = jetNTracks_mc_noweight.GetBinContent(ibin)
  wt = ndata/nmc if nmc else ndata 
  jetNTracksweight_mc_data.SetBinContent(ibin, wt)
  jetNTracks_mc_reweight.SetBinContent(ibin, nmc*wt)
  print "bin", ibin , " wt", wt

fout = ROOT.TFile("jetNTracks_Hbb_QCDbb_pt"+pt+"_weight.root", "RECREATE")
fout.cd()
jetNTracks_data.Write()
jetNTracks_mc_noweight.Write()
jetNTracks_mc_reweight.Write()
jetNTracksweight_mc_data.Write()
fout.Close()

jetNTracks_mc_noweight.SetLineStyle(2)
jetNTracks_mc_noweight.SetLineColor(2)

c0 = ROOT.TCanvas()
c0.cd()
jetNTracks_data.Draw("histe0")
jetNTracks_mc_noweight.Draw("histsame")

leg = ROOT.TLegend(0.6,0.7,0.88,0.88)
leg.AddEntry(jetNTracks_data, "Hbb MC")
leg.AddEntry(jetNTracks_mc_noweight, "QCD MC")
leg.Draw()

c0.SaveAs("jetNTracks_Hbb_QCDbb_pt"+pt+"_noweight.pdf")
  
c1 = ROOT.TCanvas()
c1.cd()
jetNTracks_data.Draw("histe0")
jetNTracks_mc_reweight.Draw("histsame")

leg = ROOT.TLegend(0.6,0.7,0.88,0.88)
leg.AddEntry(jetNTracks_data, "data")
leg.AddEntry(jetNTracks_mc_reweight, "QCD MC")
leg.Draw()

c1.SaveAs("jetNTracks_Hbb_QCDbb_pt"+pt+"_reweight.pdf")

c2 = ROOT.TCanvas()
c2.cd()
jetNTracksweight_mc_data.Draw("histe0")

leg = ROOT.TLegend(0.6,0.7,0.88,0.88)
leg.AddEntry(jetNTracksweight_mc_data, "weight")
leg.Draw()

c1.SaveAs("jetNTracks_Hbb_QCDbb_pt"+pt+"_weights.pdf")
c1.SaveAs("jetNTracks_Hbb_QCDbb_pt"+pt+"_weights.C")

