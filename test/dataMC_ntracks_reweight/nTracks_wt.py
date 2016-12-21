#!/usr/bin/env python

import ROOT

dir = "/afs/cern.ch/user/r/rsyarif/workHere/HbbTagVal/July27-2016_SFMeasurement/CMSSW_8_0_12/src/RecoBTag/BTagValidation/test/";

# fname = 'rizki_SF_80x_DoubleMuonTag_BTagMu_QCDMuEnriched_dataWithMCJP_v2_12p9_correctedJP'

# fname = 'rizki_SF_80x_DoubleMuonTag_BTagMu_QCDMuEnriched_dataWithMCJP_v2_12p9_correctedJP_v3'
# f = dir+fname+'_merged/Final_DoubleMuonTaggedFatJets_MuonEnrichedJets_dataWithMCJP_histograms_btagval.root'

# fname = 'rizki_SF_80x_SingleMuonTag_BTagMu_QCDMuEnriched_dataWithMCJP_v2_12p9_correctedJP_v3'
# f = dir+fname+'_merged/Final_MuonTaggedFatJets_MuonEnrichedJets_dataWithMCJP_histograms_btagval.root'

# fname = 'rizki_SF_80x_DoubleMuonTag_BTagMu_QCDMuEnriched_dataWithMCJP_v2_12p9_correctedJP_v3_BTagMuTrigJet300'
# f = dir+fname+'_merged/Final_DoubleMuonTaggedFatJets_MuonEnrichedJets_dataWithMCJP_histograms_btagval.root'

fname = 'rizki_SF_80x_DoubleMuonTag_BTagMu_QCDMuEnriched_dataWithMCJP_v2_12p9_correctedJP_v3_BTagMuTrigDiJet170'
f = dir+fname+'_merged/Final_DoubleMuonTaggedFatJets_MuonEnrichedJets_dataWithMCJP_histograms_btagval.root'

print 'Processing file: ', f

h7 = ROOT.TH1D("h7",";ntracks total QCD;;",80,-0.5,79.5)
nTracks_data = ROOT.TH1D("nTracks_data", ";ntracks;;",80,-0.5,79.5)
nTracks_mc_noweight = ROOT.TH1D("nTracks_mc_noweight",";ntracks;;",80,-0.5,79.5)
nTracks_mc_reweight = ROOT.TH1D("nTracks_mc_reweight",";ntracks;;",80,-0.5,79.5)
nTracksweight_mc_data = ROOT.TH1D("nTracksweight_mc_data",";ntracks;;",80,-0.5,79.5)


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
nTracks_data.Add(h)
nTracks_mc_noweight.Add(h7)
fin.Close()
  
#for f in files_mc: 
#  fin = ROOT.TFile.Open(f, "READ")
#  h = fin.Get("/btagval/h1_fatjet_pt")
#  nTracks_mc_noweight.Add(h)
#  fin.Close()

#integral = nTracks_mc_noweight.Integral()
#nTracks_mc_noweight.Scale(1./integral)

nbins = nTracks_data.GetNbinsX()
for ibin in xrange(1, nbins+1):
  ndata = nTracks_data.GetBinContent(ibin)
  nmc = nTracks_mc_noweight.GetBinContent(ibin)
#   wt = ndata/nmc if nmc else ndata if ndata > 0 else 1 #why do we need 0/0 = 1 instead of 0/0 = 0 ? - rizki
  wt = ndata/nmc if nmc else ndata #why do we need 0/0 = 1 instead of 0/0 = 0 ? - rizki
  nTracksweight_mc_data.SetBinContent(ibin, wt)
  nTracks_mc_reweight.SetBinContent(ibin, nmc*wt)
  print "bin", ibin ," ndata",ndata," nmc",nmc, " wt", wt

fout = ROOT.TFile("ntracks_dataMC_weight_"+fname+".root", "RECREATE")
fout.cd()
nTracks_data.Write()
nTracks_mc_noweight.Write()
nTracks_mc_reweight.Write()
nTracksweight_mc_data.Write()
fout.Close()

nTracks_mc_noweight.SetLineStyle(2)
nTracks_mc_noweight.SetLineColor(2)

c0 = ROOT.TCanvas()
c0.cd()
nTracks_data.Draw("histe0")
nTracks_mc_noweight.Draw("histsame")

leg = ROOT.TLegend(0.6,0.7,0.88,0.88)
leg.AddEntry(nTracks_data, "Hbb MC")
leg.AddEntry(nTracks_mc_noweight, "QCD MC")
leg.Draw()

c0.SaveAs("ntracks_dataMC_noweight_"+fname+".pdf")
  
c1 = ROOT.TCanvas()
c1.cd()
nTracks_data.Draw("histe0")
nTracks_mc_reweight.Draw("histsame")

leg = ROOT.TLegend(0.6,0.7,0.88,0.88)
leg.AddEntry(nTracks_data, "data")
leg.AddEntry(nTracks_mc_reweight, "QCD MC")
leg.Draw()

c1.SaveAs("ntracks_dataMC_reweight_"+fname+".pdf")

c2 = ROOT.TCanvas()
c2.cd()
nTracksweight_mc_data.Draw("histe0")

leg = ROOT.TLegend(0.6,0.7,0.88,0.88)
leg.AddEntry(nTracksweight_mc_data, "weight")
leg.Draw()


