#!/usr/bin/env python

import ROOT

#pt = '330'
# pt = '450'


f = "/afs/cern.ch/user/r/rsyarif/public/alice_LXBatch_Templates_SingleMu_ALLpt_merged/Final_MuonTaggedFatJets_MuonEnrichedJets_histograms_btagval.root";
#f = "/afs/cern.ch/user/r/rsyarif/public/alice_LXBatch_Templates_Double_ALLpt_merged/Final_DoubleMuonTaggedFatJets_MuonEnrichedJets_histograms_btagval.root";


#if (pt=='330') : f2 = '/afs/cern.ch/user/r/rsyarif/workHere/HbbTagVal/Update_11Dec/CMSSW_7_4_14/src/RecoBTag/BTagValidation/test/rizki_LXBatch_BoostedTaggerValidation_BTagMu_QCDMuEnriched_usePruned_fjpt'+pt+'_eta2p4_DoubleMuTag_50m200_merged/Final_histograms_btagval_DoubleMuonTaggedFatJets_MuonEnrichedJets_Pruned.root'

#if (pt=='450') : f2 = '/afs/cern.ch/user/r/rsyarif/workHere/HbbTagVal/Update_11Dec/CMSSW_7_4_14/src/RecoBTag/BTagValidation/test/rizki_LXBatch_BoostedTaggerValidation_DoubleMuonTagged_50m200_tau21-1p0_fj450_usePruned_debug_ptRatioCut_merged/Final_histograms_btagval_DoubleMuonTaggedFatJets_MuonEnrichedJets_Pruned.root'

h7 = ROOT.TH1D("h7",";ntracks total QCD;;",80,-0.5,79.5)
jetpt_data = ROOT.TH1D("jetpt_data", ";ntracks;;",80,-0.5,79.5)
jetpt_mc_noweight = ROOT.TH1D("jetpt_mc_noweight",";ntracks;;",80,-0.5,79.5)
jetpt_mc_reweight = ROOT.TH1D("jetpt_mc_reweight",";ntracks;;",80,-0.5,79.5)
jetptweight_mc_data = ROOT.TH1D("jetptweight_mc_data",";ntracks;;",80,-0.5,79.5)


fin = ROOT.TFile.Open(f, "READ")
h = fin.Get("DATA__FatJet_track_multi_data")
h2 = fin.Get("QCD__FatJet_track_multi_bfromg")
h3 = fin.Get("QCD__FatJet_track_multi_b")
h4 = fin.Get("QCD__FatJet_track_multi_c")
h5 = fin.Get("QCD__FatJet_track_multi_cfromg")
h6 = fin.Get("QCD__FatJet_track_multi_l")
h7.Add(h2)
h7.Add(h3)
h7.Add(h4)
h7.Add(h5)
h7.Add(h6)
integral = h.Integral()
integral2 = h7.Integral()
h.Scale(1./integral)
h7.Scale(1./integral2)
jetpt_data.Add(h)
jetpt_mc_noweight.Add(h7)
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

fout = ROOT.TFile("ntracks_dataMC_weight_single_mu.root", "RECREATE")
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

c0.SaveAs("ntracks_dataMC_noweight.pdf")
  
c1 = ROOT.TCanvas()
c1.cd()
jetpt_data.Draw("histe0")
jetpt_mc_reweight.Draw("histsame")

leg = ROOT.TLegend(0.6,0.7,0.88,0.88)
leg.AddEntry(jetpt_data, "data")
leg.AddEntry(jetpt_mc_reweight, "QCD MC")
leg.Draw()

c1.SaveAs("ntracks_dataMC_reweight.pdf")

c2 = ROOT.TCanvas()
c2.cd()
jetptweight_mc_data.Draw("histe0")

leg = ROOT.TLegend(0.6,0.7,0.88,0.88)
leg.AddEntry(jetptweight_mc_data, "weight")
leg.Draw()

c1.SaveAs("ntracks_dataMC_weights.pdf")
c1.SaveAs("ntracks_dataMC_weights.C")

