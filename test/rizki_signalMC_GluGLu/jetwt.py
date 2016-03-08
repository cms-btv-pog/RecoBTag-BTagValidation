#!/usr/bin/env python

import ROOT

pt = '425'

f = '/afs/cern.ch/work/r/rsyarif/work/HbbTagVal/Feb06-2016_SubjetPtReweight/CMSSW_7_6_3/src/RecoBTag/BTagValidation/test/rizki_LXBatch_BulkGravTohhTohbbhbb_narrow_M-1000_useSoftDrop_fjpt425_50m_DoubleMuTag_merged/Final_histograms_btagval.root'

if (pt=='425') : f2 = '/afs/cern.ch/work/r/rsyarif/work/HbbTagVal/Feb06-2016_SubjetPtReweight/CMSSW_7_6_3/src/RecoBTag/BTagValidation/test/rizki_LXBatch_QCDMuEnriched_useSoftDrop_fjpt425_50m_DoubleMuTag_reweight_merged/Final_histograms_btagval.root'

jetpt_data = ROOT.TH1D("jetpt_signalmc", ";pT(all jets);;",500,0.,5000.)
jetpt_mc_noweight = ROOT.TH1D("jetpt_mc_noweight",";pT(all jets);;",500,0.,5000.)
jetpt_mc_reweight = ROOT.TH1D("jetpt_mc_reweight",";pT(all jets);;",500,0.,5000.)
jetptweight_mc_data = ROOT.TH1D("jetptweight_mc_data",";pT(all jets);;",500,0.,5000.)


fin = ROOT.TFile.Open(f, "READ")
h = fin.Get("SIGNAL__FatJet_pt_all_bfromg")
fin2 = ROOT.TFile.Open(f2, "READ")  
h2 = fin2.Get("QCD__FatJet_pt_all_bfromg")
integral = h.Integral()
integral2 = h2.Integral()
h.Scale(1./integral)
h2.Scale(1./integral2)
jetpt_data.Add(h)
jetpt_mc_noweight.Add(h2)
fin.Close()
  
#for f in files_mc: 
#  fin = ROOT.TFile.Open(f, "READ")
#  h = fin.Get("/btagval/h1_fatjet_pt")
#  jetpt_mc_noweight.Add(h)
#  fin.Close()

#integral = jetpt_mc_noweight.Integral()
#jetpt_mc_noweight.Scale(1./integral)

nbins = jetpt_data.GetNbinsX()
for ibin in xrange(1, nbins+1):
  ndata = jetpt_data.GetBinContent(ibin)
  nmc = jetpt_mc_noweight.GetBinContent(ibin)
  wt = ndata/nmc if nmc else ndata 
  jetptweight_mc_data.SetBinContent(ibin, wt)
  jetpt_mc_reweight.SetBinContent(ibin, nmc*wt)
  print "bin", ibin , " wt", wt

fout = ROOT.TFile("jetpt_Hbb_QCDbb_pt"+pt+"_weight.root", "RECREATE")
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
jetpt_data.Draw("histe0")
jetpt_mc_noweight.Draw("histsame")

leg = ROOT.TLegend(0.6,0.7,0.88,0.88)
leg.AddEntry(jetpt_data, "Hbb MC")
leg.AddEntry(jetpt_mc_noweight, "QCD MC")
leg.Draw()

c0.SaveAs("jetpt_Hbb_QCDbb_"+pt+"_noweight.pdf")
  
c1 = ROOT.TCanvas()
c1.cd()
jetpt_data.Draw("histe0")
jetpt_mc_reweight.Draw("histsame")

leg = ROOT.TLegend(0.6,0.7,0.88,0.88)
leg.AddEntry(jetpt_data, "data")
leg.AddEntry(jetpt_mc_reweight, "QCD MC")
leg.Draw()

c1.SaveAs("jetpt_Hbb_QCDbb_"+pt+"_reweight.pdf")

c2 = ROOT.TCanvas()
c2.cd()
jetptweight_mc_data.Draw("histe0")

leg = ROOT.TLegend(0.6,0.7,0.88,0.88)
leg.AddEntry(jetptweight_mc_data, "weight")
leg.Draw()

c1.SaveAs("jetpt_Hbb_QCDbb_"+pt+"_weights.pdf")
c1.SaveAs("jetpt_Hbb_QCDbb_"+pt+"_weights.C")

