#!/usr/bin/env python

import os, re, sys, ROOT, imp
from help import *

tdrstyle = imp.load_source('tdrstyle', 'tdrstyle.py')
CMS_lumi = imp.load_source('CMS_lumi', 'CMS_lumi.py') 

class Commissioning:
  def __init__(self, f, hists, workdir):
    self.f = ROOT.TFile.Open(f, "READ")
    self.hists = hists
    self.workdir = workdir

  def Draw(self):
    for h in self.hists:
      self.DrawStacked(h)

  def DrawStacked(self,h):
    hname  = h[0]
    htitle = h[1]
    rebin  = h[2]
    xlo    = h[3]
    xhi    = h[4]
   
    print "Drawing %s" %hname

    h_b    = self.f.Get("QCD__SoftDropSubJet_%s_b"     % hname) 
    h_c    = self.f.Get("QCD__SoftDropSubJet_%s_c"     % hname) 
    h_bb   = self.f.Get("QCD__SoftDropSubJet_%s_bfromg"% hname) 
    h_cc   = self.f.Get("QCD__SoftDropSubJet_%s_cfromg"% hname) 
    h_l    = self.f.Get("QCD__SoftDropSubJet_%s_l"     % hname) 
    h_data = self.f.Get("DATA__SoftDropSubJet_%s_data" % hname) 

    fix(h_b   )   
    fix(h_c   )   
    fix(h_bb  )   
    fix(h_cc  )   
    fix(h_l   )   
    fix(h_data)   

    h_b    .Rebin(rebin)  
    h_c    .Rebin(rebin)  
    h_bb   .Rebin(rebin)  
    h_cc   .Rebin(rebin)  
    h_l    .Rebin(rebin)  
    h_data .Rebin(rebin)  

    h_bkg = h_b.Clone("h_bkg")
    h_bkg  .Add(h_c )    
    h_bkg  .Add(h_bb)    
    h_bkg  .Add(h_cc)    
    h_bkg  .Add(h_l )    

    binwidth = h_bkg.GetBinWidth(1)
    if binwidth%1. == 0: binwidth = int(binwidth)
    h_bkg.SetTitle(htitle.replace("BINWIDTH", str(binwidth)))

    scale = h_data.Integral()/h_bkg.Integral()
     
    h_b    .Scale(scale)   
    h_c    .Scale(scale)   
    h_bb   .Scale(scale)   
    h_cc   .Scale(scale)   
    h_l    .Scale(scale)   
    h_bkg  .Scale(scale)  

    if xlo < xhi: h_bkg.GetXaxis().SetRangeUser(xlo, xhi)
    h_bkg.SetMaximum(100000.*max(h_bkg.GetMaximum(), h_data.GetMaximum()))
    h_bkg.SetMinimum(0.2)

    beautify(h_c   , 8   ,1 , 0  , 1001 , 1, 1 , 0.0) 
    beautify(h_cc  , 6   ,1 , 0  , 1001 , 1, 1 , 0.0) 
    beautify(h_b   , 2   ,1 , 0  , 1001 , 1, 1 , 0.0) 
    beautify(h_bb  , 7   ,1 , 0  , 1001 , 1, 1 , 0.0) 
    beautify(h_l   , 4   ,1 , 0  , 1001 , 1, 1 , 0.0) 
    beautify(h_bkg , 0   ,1 , 0  , 0    , 0, 1 , 0.0) 
    beautify(h_data, 0   ,1 , 1  , 0    , 1, 20, 0.75)

    hs_bkg = ROOT.THStack("hs_bkg", h_b.GetTitle())
    hs_bkg.Add(h_b )   
    hs_bkg.Add(h_c )   
    hs_bkg.Add(h_bb)   
    hs_bkg.Add(h_cc)   
    hs_bkg.Add(h_l )   

    ROOT.gROOT.SetBatch()
    ROOT.gROOT.SetStyle("Plain")
    ROOT.gStyle.SetOptStat(000)
    ROOT.gStyle.SetOptTitle(0000)
    ROOT.gStyle.SetPalette(1)
    ROOT.gStyle.SetNdivisions(405,"x")
    ROOT.gStyle.SetEndErrorSize(0)
    ROOT.gStyle.SetErrorX(0.001)
    ROOT.gStyle.SetPadTickX(1)
    ROOT.gStyle.SetPadTickY(1)

    c = ROOT.TCanvas("c_%s" % hname, "", 800, 600)
    c.cd()

    pad0 = ROOT.TPad("pad0", "", 0, 0.25, 1., 1.)
    pad1 = ROOT.TPad("pad1", "", 0, 0.00, 1., 0.32)

    pad0.Draw()
    pad0.cd()
    pad0.SetFillColor(0)
    pad0.SetBorderMode(0)
    pad0.SetBorderSize(2)
    pad0.SetFrameBorderMode(0)
    pad0.SetTopMargin(0.080)
    pad0.SetLeftMargin(0.12) 
    pad0.SetRightMargin(0.08) 
    pad0.SetLogy(1)

    labelsizex=0.12
    labelsizey=0.12
    titlesizex=0.15
    titlesizey=0.14

    h_bkg.GetXaxis().SetLabelSize(0.)
    h_bkg.GetXaxis().SetTitleSize(0.)
    h_bkg.GetYaxis().SetLabelSize(labelsizey * (pad1.GetHNDC()/ pad0.GetHNDC()))
    h_bkg.GetYaxis().SetTitleSize(titlesizey * (pad1.GetHNDC()/ pad0.GetHNDC()))
    h_bkg.SetLabelOffset(0.0050,"Y")
    h_bkg.SetTitleOffset(0.34 * (pad0.GetHNDC()/ pad1.GetHNDC()),"Y")
    if xlo < xhi: h_bkg.GetXaxis().SetRangeUser(xlo, xhi)

    h_bkg.Draw("hist")
    hs_bkg.Draw("histsame")
    h_data.Draw("samee1x0")

    leg = ROOT.TLegend(0.65,0.55,0.90,0.90,"","brNDC")
    leg.SetBorderSize(1)
    leg.SetTextFont(62)
    leg.SetLineColor(1)
    leg.SetLineStyle(1)
    leg.SetLineWidth(1)
    leg.SetFillColor(0)
    leg.SetFillStyle(1001)
    leg.SetBorderSize(0)
    leg.SetTextSize(0.05)
    leg.AddEntry(h_data    , "Data"    , "e1p")
    leg.AddEntry(h_b       , "b"       , "f")
    leg.AddEntry(h_c       , "c"       , "f")
    leg.AddEntry(h_l       , "udsg"    , "f")
    leg.Draw()

    iPos = 11
    CMS_lumi.relPosX = 0.04
    CMS_lumi.writeExtraText = 1
    CMS_lumi.extraText = "Work in Progess"
    CMS_lumi.lumi_13TeV = "41.7 fb^{-1}"
    CMS_lumi.lumiTextOffset = 0.18
    CMS_lumi.CMS_lumi(pad0, 4, iPos)

    tex1 = ROOT.TLatex(pad0.GetLeftMargin()+0.04,0.74,"Muon-tagged subjets of AK8 jets")
    tex1.SetNDC()
    tex1.SetTextAlign(13)
    tex1.SetTextFont(42)
    tex1.SetTextSize(0.055)
    tex1.SetLineWidth(2)
    tex1.Draw()

    tex3 = ROOT.TLatex(pad0.GetLeftMargin()+0.04,0.68,"p_{T} (AK8 jets) > 350 GeV")
    tex3.SetNDC()
    tex3.SetTextAlign(13)
    tex3.SetTextFont(42)
    tex3.SetTextSize(0.055)
    tex3.SetLineWidth(2)
    tex3.Draw()

    pad0.RedrawAxis()
    pad0.Update()
    pad0.Modified()
    c.cd()

    pad1.Draw()
    pad1.cd()
    pad1.SetFillColor(0)
    pad1.SetBorderMode(0)
    pad1.SetBorderSize(2)
    pad1.SetGridy()
    pad1.SetBottomMargin(0.31)
    pad1.SetFrameBorderMode(0)
    pad1.SetLeftMargin(0.12) 
    pad1.SetRightMargin(0.08) 
  
    h_ratio = h_data.Clone("h_ratio")
    h_ratio.SetTitle(htitle.replace("BINWIDTH", str(binwidth)))
    h_ratio.Divide(h_bkg)

    h_ratio.SetMarkerStyle(20)
    h_ratio.SetMarkerSize(0.75)
    h_ratio.SetLineWidth(2)

    h_ratio.GetYaxis().SetTitle("Data/MC")
    h_ratio.SetTitleOffset(0.9,"X")
    h_ratio.SetTitleOffset(0.34,"Y")
    h_ratio.GetYaxis().SetNdivisions( 505 )

    h_ratio.GetXaxis().SetLabelSize( labelsizex )
    h_ratio.GetXaxis().SetTitleSize( titlesizex )
    h_ratio.GetYaxis().SetLabelSize( labelsizey )
    h_ratio.GetYaxis().SetTitleSize( titlesizey )
    if xlo < xhi: h_ratio.GetXaxis().SetRangeUser(xlo, xhi)

    h_ratio.SetMinimum(0.4)
    h_ratio.SetMaximum(1.6)
    h_ratio.Draw("E1X0")

    pad1.Modified()
    c.Modified()
    c.cd()
    c.SetSelected(c)

    if not re.search("^/", self.workdir):
      workdir = os.path.join(os.getcwd(), self.workdir)
    if not os.path.exists(workdir):
      os.mkdir(workdir)

    c.SaveAs(os.path.join(workdir,"%s.pdf" % c.GetName()))
    c.SaveAs(os.path.join(workdir,"%s.png" % c.GetName()))

hists = [
    ("pt_all"            , ";p_{T}(all jets) [GeV];Jets/ BINWIDTH GeV;"                   , 10, -999999, -999999),
    ("trk_multi_sel"     , ";N(selected tracks);Jets/ BINWIDTH unit;"                     , 1 , -999999, -999999),
    ("track_IPs"         , ";3D IP/#sigma of all tracks;tracks/ BINWIDTH unit;"           , 1 , -999999, -999999),
    ("track_dist"        , ";Distance to jet axis [cm];Tracks/ BINWIDTH cm;"              , 1 , -999999, -999999),
    ("track_nHit"        , ";Number hits in the tracker;;Tracks/ BINWIDTH unit;"          , 1 , -999999, -999999),
    ("track_HPix"        , ";Number hits in the pixel;;Tracks/ BINWIDTH unit;"            , 1 , -999999, -999999),
    ("track_pt"          , ";p_{T} of all tracks [GeV];;Tracks/ BINWIDTH GeV;"            , 1 , -999999, -999999),
    ("sv_multi_0"        , ";Number of SVs;;Jets/ BINWIDTH unit;"                         , 1 , -999999, -999999),
    ("sv_flightSig2D"    , ";SV 2D flight distance significance;;SVs/ BINWIDTH unit;"     , 1 , -999999, -999999),
    ("CSVIVFv2"          , ";CSVv2 discriminator;;Jets/ BINWIDTH GeV;"                    , 1 , -999999, -999999),
    ("JP"                , ";JP discriminator;;Jets/ BINWIDTH GeV;"                       , 1 , -999999, -999999),
    ("TagVarCSV_sv_mass" , ";Corrected SV mass [GeV];;SVs/ BINWIDTH GeV;"                 , 1 , -999999, -999999),
    ]

comm = Commissioning("/afs/cern.ch/user/d/devdatta/afswork/CMSREL/BTagging/CMSSW_9_4_1/src/RecoBTag/BTagValidation/test/BATCH_Moriond2018_12Feb2018/Final_histograms_btagval.root", hists, "13Feb2018")
comm.Draw()

