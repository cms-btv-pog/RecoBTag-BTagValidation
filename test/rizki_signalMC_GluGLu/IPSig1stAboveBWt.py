#!/usr/bin/env python

import ROOT

pt = '425'
tag = 'Single'
# tag = 'Double'

if(tag=='Double') : f = '/afs/cern.ch/work/r/rsyarif/work/HbbTagVal/Feb06-2016_SubjetPtReweight/CMSSW_7_6_3/src/RecoBTag/BTagValidation/test/rizki_LXBatch_BulkGravTohhTohbbhbb_narrow_M-1000_useSoftDrop_fjpt425_50m_DoubleMuTag_merged/Final_histograms_btagval.root'
if(tag=='Single') : f = '/afs/cern.ch/work/r/rsyarif/work/HbbTagVal/Feb06-2016_SubjetPtReweight/CMSSW_7_6_3/src/RecoBTag/BTagValidation/test/rizki_LXBatch_BulkGravTohhTohbbhbb_narrow_M-1000_usePruned_fjpt425_50m_SingleMuTag_TightMu_signal_merged/Final_histograms_btagval.root'

if (tag=='Double') : f2 = '/afs/cern.ch/work/r/rsyarif/work/HbbTagVal/Feb06-2016_SubjetPtReweight/CMSSW_7_6_3/src/RecoBTag/BTagValidation/test/rizki_LXBatch_QCDMuEnriched_useSoftDrop_fjpt425_50m_DoubleMuTag_merged/Final_histograms_btagval.root'
if (tag=='Single') : f2 = '/afs/cern.ch/work/r/rsyarif/work/HbbTagVal/Feb06-2016_SubjetPtReweight/CMSSW_7_6_3/src/RecoBTag/BTagValidation/test/rizki_LXBatch_QCDMuEnriched_usePruned_fjpt425_50m_SingleMuTag_TightMu_merged/Final_histograms_btagval.root'

IPSig1stAboveB_data = ROOT.TH1D("IPSig1stAboveB_signalmc", ";;IP Sig 1st Track Above Bottom ;;",100,-20,20)
IPSig1stAboveB_mc_noweight = ROOT.TH1D("IPSig1stAboveB_mc_noweight",";;IP Sig 1st Track Above Bottom  ;;",100,-20,20)
IPSig1stAboveB_mc_reweight = ROOT.TH1D("IPSig1stAboveB_mc_reweight",";;IP Sig 1st Track Above Bottom  ;;",100,-20,20)
IPSig1stAboveBweight_mc_data = ROOT.TH1D("IPSig1stAboveBweight_mc_data",";;IP Sig 1st Track Above Bottom  ;;",100,-20,20) #its really for mc signal/bkg, NOT data/MC!


fin = ROOT.TFile.Open(f, "READ")
h = fin.Get("SIGNAL__FatJet_trackSip2dSigAboveBottom_0_bfromg")
fin2 = ROOT.TFile.Open(f2, "READ")  
h2 = fin2.Get("QCD__FatJet_trackSip2dSigAboveBottom_0_bfromg")
integral = h.Integral()
integral2 = h2.Integral()
h.Scale(1./integral)
h2.Scale(1./integral2)
IPSig1stAboveB_data.Add(h)
IPSig1stAboveB_mc_noweight.Add(h2)
fin.Close()
  
#for f in files_mc: 
#  fin = ROOT.TFile.Open(f, "READ")
#  h = fin.Get("/btagval/h1_fatjet_pt")
#  IPSig1stAboveB_mc_noweight.Add(h)
#  fin.Close()

#integral = IPSig1stAboveB_mc_noweight.Integral()
#IPSig1stAboveB_mc_noweight.Scale(1./integral)

nbins = IPSig1stAboveB_data.GetNbinsX()
for ibin in xrange(1, nbins+1):
  ndata = IPSig1stAboveB_data.GetBinContent(ibin)
  nmc = IPSig1stAboveB_mc_noweight.GetBinContent(ibin)
  wt = ndata/nmc if nmc else ndata 
  IPSig1stAboveBweight_mc_data.SetBinContent(ibin, wt)
  IPSig1stAboveB_mc_reweight.SetBinContent(ibin, nmc*wt)
  print "bin", ibin , " wt", wt

fout = ROOT.TFile("IPSig1stAboveB_Hbb_QCDbb_pt"+pt+"_"+tag+"_weight.root", "RECREATE")
fout.cd()
IPSig1stAboveB_data.Write()
IPSig1stAboveB_mc_noweight.Write()
IPSig1stAboveB_mc_reweight.Write()
IPSig1stAboveBweight_mc_data.Write()
fout.Close()

IPSig1stAboveB_mc_noweight.SetLineStyle(2)
IPSig1stAboveB_mc_noweight.SetLineColor(2)

c0 = ROOT.TCanvas()
c0.cd()
IPSig1stAboveB_data.Draw("histe0")
IPSig1stAboveB_mc_noweight.Draw("histsame")

leg = ROOT.TLegend(0.6,0.7,0.88,0.88)
leg.AddEntry(IPSig1stAboveB_data, "Hbb MC")
leg.AddEntry(IPSig1stAboveB_mc_noweight, "QCD MC")
leg.Draw()

c0.SaveAs("IPSig1stAboveB_Hbb_QCDbb_pt"+pt+"_"+tag+"_noweight.pdf")
  
c1 = ROOT.TCanvas()
c1.cd()
IPSig1stAboveB_data.Draw("histe0")
IPSig1stAboveB_mc_reweight.Draw("histsame")

leg = ROOT.TLegend(0.6,0.7,0.88,0.88)
leg.AddEntry(IPSig1stAboveB_data, "data")
leg.AddEntry(IPSig1stAboveB_mc_reweight, "QCD MC")
leg.Draw()

c1.SaveAs("IPSig1stAboveB_Hbb_QCDbb_pt"+pt+"_"+tag+"_reweight.pdf")

c2 = ROOT.TCanvas()
c2.cd()
IPSig1stAboveBweight_mc_data.Draw("histe0")

leg = ROOT.TLegend(0.6,0.7,0.88,0.88)
leg.AddEntry(IPSig1stAboveBweight_mc_data, "weight")
leg.Draw()

c1.SaveAs("IPSig1stAboveB_Hbb_QCDbb_pt"+pt+"_"+tag+"_weights.pdf")
c1.SaveAs("IPSig1stAboveB_Hbb_QCDbb_pt"+pt+"_"+tag+"_weights.C")

