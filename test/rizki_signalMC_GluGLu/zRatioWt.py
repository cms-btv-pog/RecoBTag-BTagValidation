#!/usr/bin/env python

import ROOT

pt = '425'
# tag = 'Single'
tag = 'Double'

if(tag=='Double') : f = '/afs/cern.ch/work/r/rsyarif/work/HbbTagVal/Feb06-2016_SubjetPtReweight/CMSSW_7_6_3/src/RecoBTag/BTagValidation/test/rizki_LXBatch_BulkGravTohhTohbbhbb_narrow_M-1000_useSoftDrop_fjpt425_50m_DoubleMuTag_merged/Final_histograms_btagval.root'
if(tag=='Single') : f = '/afs/cern.ch/work/r/rsyarif/work/HbbTagVal/Feb06-2016_SubjetPtReweight/CMSSW_7_6_3/src/RecoBTag/BTagValidation/test/rizki_LXBatch_BulkGravTohhTohbbhbb_narrow_M-1000_usePruned_fjpt425_50m_SingleMuTag_TightMu_signal_merged/Final_histograms_btagval.root'

if (tag=='Double') : f2 = '/afs/cern.ch/work/r/rsyarif/work/HbbTagVal/Feb06-2016_SubjetPtReweight/CMSSW_7_6_3/src/RecoBTag/BTagValidation/test/rizki_LXBatch_QCDMuEnriched_useSoftDrop_fjpt425_50m_DoubleMuTag_merged/Final_histograms_btagval.root'
if (tag=='Single') : f2 = '/afs/cern.ch/work/r/rsyarif/work/HbbTagVal/Feb06-2016_SubjetPtReweight/CMSSW_7_6_3/src/RecoBTag/BTagValidation/test/rizki_LXBatch_QCDMuEnriched_usePruned_fjpt425_50m_SingleMuTag_TightMu_merged/Final_histograms_btagval.root'

Zratio_data = ROOT.TH1D("Zratio_signalmc", ";;z_{ratio} ;;",100,0.,60.)
Zratio_mc_noweight = ROOT.TH1D("Zratio_mc_noweight",";;z_{ratio}  ;;",100,0.,60.)
Zratio_mc_reweight = ROOT.TH1D("Zratio_mc_reweight",";;z_{ratio}  ;;",100,0.,60.)
Zratioweight_mc_data = ROOT.TH1D("Zratioweight_mc_data",";;z_{ratio}  ;;",100,0.,60.) #its really for mc signal/bkg, NOT data/MC!


fin = ROOT.TFile.Open(f, "READ")
h = fin.Get("SIGNAL__FatJet_z_ratio_bfromg")
fin2 = ROOT.TFile.Open(f2, "READ")  
h2 = fin2.Get("QCD__FatJet_z_ratio_bfromg")
integral = h.Integral()
integral2 = h2.Integral()
h.Scale(1./integral)
h2.Scale(1./integral2)
Zratio_data.Add(h)
Zratio_mc_noweight.Add(h2)
fin.Close()
  
#for f in files_mc: 
#  fin = ROOT.TFile.Open(f, "READ")
#  h = fin.Get("/btagval/h1_fatjet_pt")
#  Zratio_mc_noweight.Add(h)
#  fin.Close()

#integral = Zratio_mc_noweight.Integral()
#Zratio_mc_noweight.Scale(1./integral)

nbins = Zratio_data.GetNbinsX()
for ibin in xrange(1, nbins+1):
  ndata = Zratio_data.GetBinContent(ibin)
  nmc = Zratio_mc_noweight.GetBinContent(ibin)
  wt = ndata/nmc if nmc else ndata 
  Zratioweight_mc_data.SetBinContent(ibin, wt)
  Zratio_mc_reweight.SetBinContent(ibin, nmc*wt)
  print "bin", ibin , " wt", wt

fout = ROOT.TFile("Zratio_Hbb_QCDbb_pt"+pt+"_"+tag+"_weight.root", "RECREATE")
fout.cd()
Zratio_data.Write()
Zratio_mc_noweight.Write()
Zratio_mc_reweight.Write()
Zratioweight_mc_data.Write()
fout.Close()

Zratio_mc_noweight.SetLineStyle(2)
Zratio_mc_noweight.SetLineColor(2)

c0 = ROOT.TCanvas()
c0.cd()
Zratio_data.Draw("histe0")
Zratio_mc_noweight.Draw("histsame")

leg = ROOT.TLegend(0.6,0.7,0.88,0.88)
leg.AddEntry(Zratio_data, "Hbb MC")
leg.AddEntry(Zratio_mc_noweight, "QCD MC")
leg.Draw()

c0.SaveAs("Zratio_Hbb_QCDbb_pt"+pt+"_"+tag+"_noweight.pdf")
  
c1 = ROOT.TCanvas()
c1.cd()
Zratio_data.Draw("histe0")
Zratio_mc_reweight.Draw("histsame")

leg = ROOT.TLegend(0.6,0.7,0.88,0.88)
leg.AddEntry(Zratio_data, "data")
leg.AddEntry(Zratio_mc_reweight, "QCD MC")
leg.Draw()

c1.SaveAs("Zratio_Hbb_QCDbb_pt"+pt+"_"+tag+"_reweight.pdf")

c2 = ROOT.TCanvas()
c2.cd()
Zratioweight_mc_data.Draw("histe0")

leg = ROOT.TLegend(0.6,0.7,0.88,0.88)
leg.AddEntry(Zratioweight_mc_data, "weight")
leg.Draw()

c1.SaveAs("Zratio_Hbb_QCDbb_pt"+pt+"_"+tag+"_weights.pdf")
c1.SaveAs("Zratio_Hbb_QCDbb_pt"+pt+"_"+tag+"_weights.C")

