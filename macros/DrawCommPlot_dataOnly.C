#include "tdrstyle.C"
#include "CMS_lumi.C"
#include "help.C"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
#include "TH1D.h"
#include "TMultiGraph.h"
#include "TGraph.h"
#include "THStack.h"
#include "TFile.h"
#include "TROOT.h"
#include "TF1.h"
#include "TMath.h"
#include <TLegend.h>
#include <TProfile.h>
#include <TLatex.h>
#include <TAxis.h>
#include <TProfile.h>
#include <TString.h>

#include <iostream>
#include <fstream>
#include <iomanip>
#include <stdlib.h>

using namespace std;

TString ptcut = "p_{T} (AK8 jets) > 350 GeV";
TString filename0	="/afs/cern.ch/user/r/rsyarif/workHere/HbbTagVal/Jan12_SFCommPlots_NoTreeBTagVal/CMSSW_8_0_23/src/RecoBTag/BTagValidation/test/Mu_350_merged_PRH/Final_DoubleMuonTaggedFatJets_MuonEnrichedJets_dataWithMCJP_histograms_btagval.root"; //--> GT:80X_dataRun2_Prompt_v15

// TString filename1    ="/afs/cern.ch/user/r/rsyarif/workHere/HbbTagVal/Aug2-2017_2017Data/CMSSW_9_2_7_patch1/src/RecoBTag/BTagValidation/test/Mu_350_BTagMu_PRBv1/Final_DoubleMuonTaggedFatJets_MuonEnrichedJets_dataWithMCJP_histograms_btagval.root";
// TString filename2    ="/afs/cern.ch/user/r/rsyarif/workHere/HbbTagVal/Aug2-2017_2017Data/CMSSW_9_2_7_patch1/src/RecoBTag/BTagValidation/test/Mu_350_BTagMu_PRBv2/Final_DoubleMuonTaggedFatJets_MuonEnrichedJets_dataWithMCJP_histograms_btagval.root";
// TString filename3    ="/afs/cern.ch/user/r/rsyarif/workHere/HbbTagVal/Aug2-2017_2017Data/CMSSW_9_2_7_patch1/src/RecoBTag/BTagValidation/test/Mu_350_BTagMu_PRCv1/Final_DoubleMuonTaggedFatJets_MuonEnrichedJets_dataWithMCJP_histograms_btagval.root";

TString filename1    ="/afs/cern.ch/user/r/rsyarif/workHere/HbbTagVal/Aug2-2017_2017Data/CMSSW_9_2_7_patch1/src/RecoBTag/BTagValidation/test/Mu_350_BTagMu_PRBC_case1/Final_DoubleMuonTaggedFatJets_MuonEnrichedJets_histograms_btagval.root";
TString filename2    ="/afs/cern.ch/user/r/rsyarif/workHere/HbbTagVal/Aug2-2017_2017Data/CMSSW_9_2_7_patch1/src/RecoBTag/BTagValidation/test/Mu_350_BTagMu_PRBC_case2/Final_DoubleMuonTaggedFatJets_MuonEnrichedJets_histograms_btagval.root";
TString filename3    ="/afs/cern.ch/user/r/rsyarif/workHere/HbbTagVal/Aug2-2017_2017Data/CMSSW_9_2_7_patch1/src/RecoBTag/BTagValidation/test/Mu_350_BTagMu_PRBC_case3/Final_DoubleMuonTaggedFatJets_MuonEnrichedJets_histograms_btagval.root";
TString filename4    ="/afs/cern.ch/user/r/rsyarif/workHere/HbbTagVal/Aug2-2017_2017Data/CMSSW_9_2_7_patch1/src/RecoBTag/BTagValidation/test/Mu_350_BTagMu_PRBC_case4/Final_DoubleMuonTaggedFatJets_MuonEnrichedJets_histograms_btagval.root";

// TString filename1    ="/afs/cern.ch/user/r/rsyarif/workHere/HbbTagVal/Aug2-2017_2017Data/CMSSW_9_2_7_patch1/src/RecoBTag/BTagValidation/test/Mu_350_BTagMu_23June2017B/Final_DoubleMuonTaggedFatJets_MuonEnrichedJets_dataWithMCJP_histograms_btagval.root";


TString filename_ext="" ;

// TString dir4plots   = "Comm_DoubleMuTag_BTagMu_10Aug2017";
TString dir4plots   = "Comm_DoubleMuTag_BTagMu_15Aug2017";

TString filename_uncUp  ="" ;
TString filename_uncDown="" ;

TString title1 = "                   (13 TeV)";
TString datacaption = "Data";//"HLT_PFJet320, jet p_{T}>400 GeV";

TString formata=".pdf";
TString formatb=".png";
TString formatc=".C";

bool bOverflow = 1;
bool web       = 0;
bool prunedjets= 0;
bool logy      = 1;
bool dodata    = 1;
bool extNorm   = 0; // used only for double-muon- and double-b-tagged fat jets
double norm_lightjets = 1.27 ; // used only for QCD MuEnriched.
// double norm_lightjets = 1.0 ; // used for QCDincl.

bool inclTTbar = 0;
bool inclZjj   = 0;
bool uncBand   = 0; // used only for double-muon- and double-b-tagged fat jets with scale factors applied
bool setSampleName = 1;

void DrawAll(bool Draw_track_plots, bool Draw_Nminus1_plots, bool Draw_sv_plots, bool Draw_muons_plots, bool Draw_discriminator_plots, bool Draw_tagRate_plots, bool Draw_2D_plots, TString histoTag);
void Draw(TString name, TString histotitle, bool log);
void DrawStacked(TString name, TString histotitle, bool log, bool doData, bool fExtNorm=false, int nRebin=1, bool setXRange=false, double rangeXLow=0., double rangeXHigh=0.);
void DrawTagRate(TString name, TString histotitle, bool log, bool doData);
void Draw2DPlot(TString name, TString histotitle, TString titleX, TString titleY, bool log, bool doData, bool doProfile);

//DrawCommPlot(true,false,true,false,true,false,false)

//--------------------------
void DrawCommPlot_dataOnly(bool Draw_track_plots=false,
    bool Draw_Nminus1_plots=false,
    bool Draw_sv_plots=false,
    bool Draw_muons_plots=false,
    bool Draw_discriminator_plots=false,
    bool Draw_tagRate_plots=false,
    bool Draw_2D_plots=false) {

  gROOT->SetBatch(kTRUE);
  gROOT->SetStyle("Plain");
  gStyle->SetOptTitle(0);
  gStyle->SetOptStat(0);
  gStyle->SetPadTickX(1);
  gStyle->SetPadTickY(1);
  gStyle->SetErrorX(0);

  TString action = "mkdir -p " + dir4plots;
  system(action);
//   Draw("h1_pt_hat"   ,"p_{T} hat",1);
//   Draw("h1_pt_hat_sel" ,"p_{T} hat after selection",1); 
//   Draw("h1_nPV"      ,"# of PV",0);
//   Draw("h1_nPV_unw"      ,"# of PV",0);
//   Draw("h1_nFatJet"  ,"# of fat jets",0);
//   Draw("QCD__h1_nSubJet"  ,"# of subjets",0);


  TString histoTag = "FatJet" ;
  DrawAll(Draw_track_plots, Draw_Nminus1_plots, Draw_sv_plots, Draw_muons_plots, Draw_discriminator_plots, Draw_tagRate_plots, Draw_2D_plots, histoTag) ;
  
  gApplication->Terminate();

}

//--------------------------
void DrawAll(bool Draw_track_plots, bool Draw_Nminus1_plots, bool Draw_sv_plots, bool Draw_muons_plots, bool Draw_discriminator_plots, bool Draw_tagRate_plots, bool Draw_2D_plots, TString histoTag) {

  DrawStacked(histoTag+"_pt_all"      ,"p_{T} [GeV/c]"                ,logy ,dodata ,extNorm ,6  ,1 ,0. ,2000.);
  DrawStacked(histoTag+"_eta"         ,"#eta"                         ,logy ,dodata ,extNorm ,2  ,0 ,0. ,0.   );
  //DrawStacked(histoTag+"_phi"         ,"#phi"                         ,logy ,dodata ,extNorm ,40 ,0 ,0. ,0.   );
  DrawStacked(histoTag+"_phi"         ,"#phi"                         ,logy ,dodata ,extNorm ,2  ,0 ,0. ,0.   );
  DrawStacked(histoTag+"_mass"        ,"Mass [GeV/c^{2}]"             ,logy ,dodata ,extNorm ,4  ,0 ,0. ,400. );
//   DrawStacked(histoTag+"_CSV"         ,"CSV"                          ,logy ,dodata ,extNorm ,1  ,0 ,0  ,1.   );
//   DrawStacked(histoTag+"_CSVIVFv2"    ,"CSVv2 Discriminator"          ,logy ,dodata ,extNorm ,1  ,0 ,0. ,1.   );
//   DrawStacked(histoTag+"_JP"          ,"JP Discriminator"             ,logy ,dodata ,extNorm ,1  ,0 ,0. ,1.   );
//   DrawStacked(histoTag+"_JBP"         ,"JBP Discriminator"            ,logy ,dodata ,extNorm ,1  ,0 ,0. ,1.   );
//   DrawStacked(histoTag+"_track_multi" ,"Number of tracks in the jets" ,logy ,dodata ,extNorm ,0. ,0.,0. ,0.   );
  if( histoTag=="FatJet" ) {
    //if( prunedjets) {
      DrawStacked(histoTag+"_prunedMass"          ,"M_{pruned}[GeV/c^{2}]"                            ,logy ,dodata ,extNorm ,4 ,0 ,0. ,0.);
      //DrawStacked(histoTag+"_prunedsubjet_dR"    ,"#DeltaR(subjet_{1},subjet_{2}) in #eta-#phi plane" ,logy ,dodata ,extNorm ,4 ,0 ,0. ,0.);
      //DrawStacked(histoTag+"_prunedsubjet_dyphi" ,"#DeltaR(subjet_{1},subjet_{2}) in y-#phi plane"    ,logy ,dodata ,extNorm ,4 ,0 ,0. ,0.);
      //DrawStacked(histoTag+"_massDrop_pruned"    ,"Mass drop (pruned AK8 jets) [GeV]"                 ,logy ,dodata ,extNorm ,4 ,0 ,0. ,0.);
    //}
    //else {
      DrawStacked(histoTag+"_softdropMass"         ,"M_{softdrop}[GeV/c^{2}]"                           ,logy ,dodata ,extNorm ,4 ,0 ,0. ,0.);
      //DrawStacked(histoTag+"_softdropsubjet_dR"    ,"#DeltaR(subjet_{1},subjet_{2}) in #eta-#phi plane" ,logy ,dodata ,extNorm ,4 ,0 ,0. ,0.);
      //DrawStacked(histoTag+"_softdropsubjet_dyphi" ,"#DeltaR(subjet_{1},subjet_{2}) in y-#phi plane"    ,logy ,dodata ,extNorm ,4 ,0 ,0. ,0.);
      //DrawStacked(histoTag+"_massDrop_softdrop"    ,"Mass drop (soft drop AK8 jets) [GeV]"              ,logy ,dodata ,extNorm ,4 ,0 ,0. ,0.);
    //}
    //DrawStacked(histoTag+"_nsubjettiness","#tau_{2}/#tau_{1}"                                 ,logy ,dodata ,extNorm ,2 ,0 ,0. ,0.);
    DrawStacked(histoTag+"_DoubleB"      ,"double-b discriminator"                                           ,logy ,dodata ,extNorm ,4 ,1 ,-1 ,1.);

//     DrawStacked(histoTag+"_DoubleB_pt400to450"      ,"DoubleB (400<p_T<450)"                                           ,logy ,dodata ,extNorm ,2 ,0 ,-1 ,1.);
//     DrawStacked(histoTag+"_DoubleB_pt450to500"      ,"DoubleB (450<p_T<500)"                                           ,logy ,dodata ,extNorm ,2 ,0 ,-1 ,1.);
//     DrawStacked(histoTag+"_DoubleB_pt500to600"      ,"DoubleB (500<p_T<600)"                                           ,logy ,dodata ,extNorm ,2 ,0 ,-1 ,1.);
//     DrawStacked(histoTag+"_DoubleB_pt600to2000"      ,"DoubleB (600<p_T<2000)"                                           ,logy ,dodata ,extNorm ,2 ,0 ,-1 ,1.);
//     DrawStacked(histoTag+"_DoubleB_pt400to500"      ,"DoubleB (400<p_T<500)"                                           ,logy ,dodata ,extNorm ,2 ,0 ,-1 ,1.);
//     DrawStacked(histoTag+"_DoubleB_pt300to400"      ,"DoubleB (300<p_T<400)"                                           ,logy ,dodata ,extNorm ,2 ,0 ,-1 ,1.);
//     DrawStacked(histoTag+"_DoubleB_pt500to2000"      ,"DoubleB (500<p_T<2000)"                                           ,logy ,dodata ,extNorm ,2 ,0 ,-1 ,1.);

    //////added by rizki - start

    DrawStacked(histoTag+"_z_ratio"           ,"z variable"                                   ,logy ,dodata ,extNorm ,4 ,0 ,0. ,0.);

    int trackSip_rebin = 5;
    DrawStacked(histoTag+"_trackSip3dSig_0"  ,"IP Sig 1st track"                            ,logy ,dodata ,extNorm ,trackSip_rebin ,0 ,0. ,0.);
    DrawStacked(histoTag+"_trackSip3dSig_1"  ,"IP Sig 2nd track"                            ,logy ,dodata ,extNorm ,trackSip_rebin ,0 ,0. ,0.);
    DrawStacked(histoTag+"_trackSip3dSig_2"  ,"IP Sig 3rd track"                            ,logy ,dodata ,extNorm ,trackSip_rebin ,0 ,0. ,0.);
    DrawStacked(histoTag+"_trackSip3dSig_3"  ,"IP Sig 4th track"                            ,logy ,dodata ,extNorm ,trackSip_rebin ,0 ,0. ,0.);

    DrawStacked(histoTag+"_tau1_trackSip3dSig_1"  ,"IP Sig 2nd track of SV_{0}"                            ,logy ,dodata ,extNorm ,trackSip_rebin ,0 ,0. ,0.);
    DrawStacked(histoTag+"_tau1_trackSip3dSig_0"  ,"IP Sig 1st track of SV_{0}"                            ,logy ,dodata ,extNorm ,trackSip_rebin ,0 ,0. ,0.);
    DrawStacked(histoTag+"_tau2_trackSip3dSig_1"  ,"IP Sig 2nd track of SV_{1}"                            ,logy ,dodata ,extNorm ,trackSip_rebin ,0 ,0. ,0.);
    DrawStacked(histoTag+"_tau2_trackSip3dSig_0"  ,"IP Sig 1st track of SV_{1}"                            ,logy ,dodata ,extNorm ,trackSip_rebin ,0 ,0. ,0.);

    DrawStacked(histoTag+"_trackSip2dSigAboveCharm_0"  ,"IP Sig 1st Track Above Charm"                          ,logy ,dodata ,extNorm ,trackSip_rebin ,0 ,0. ,0.);
    DrawStacked(histoTag+"_trackSip2dSigAboveBottom_0"  ,"IP Sig 1st Track Above Bottom"                          ,logy ,dodata ,extNorm ,trackSip_rebin ,0 ,0. ,0.);
    DrawStacked(histoTag+"_trackSip2dSigAboveBottom_1"  ,"IP Sig 2nd Track Above Bottom"                          ,logy ,dodata ,extNorm ,trackSip_rebin ,0 ,0. ,0.);

    DrawStacked(histoTag+"_tau1_trackEtaRel_0"  ,"EtaRel 1st track for SV_{0}"                            ,logy ,dodata ,extNorm ,4 ,1 ,0. ,10.);
    DrawStacked(histoTag+"_tau1_trackEtaRel_1"  ,"EtaRel 2nd track for SV_{0}"                            ,logy ,dodata ,extNorm ,4 ,1 ,0. ,10.);
    DrawStacked(histoTag+"_tau1_trackEtaRel_2"  ,"EtaRel 3rd track for SV_{0}"                            ,logy ,dodata ,extNorm ,4 ,1 ,0. ,10.);

    DrawStacked(histoTag+"_tau2_trackEtaRel_0"  ,"EtaRel 1st track for SV_{1}"                            ,logy ,dodata ,extNorm ,4 ,1 ,0. ,10.);  
    DrawStacked(histoTag+"_tau2_trackEtaRel_1"  ,"EtaRel 2nd track for SV_{1}"                            ,logy ,dodata ,extNorm ,4 ,1 ,0. ,10.);
    DrawStacked(histoTag+"_tau2_trackEtaRel_2"  ,"EtaRel 3rd track for SV_{1}"                            ,logy ,dodata ,extNorm ,4 ,1 ,0. ,10.);

    DrawStacked(histoTag+"_tau1_vertexMass"  ,"SV_{0} mass [GeV]"                          ,logy ,dodata ,extNorm ,1 ,1 ,0. ,50.);
    DrawStacked(histoTag+"_tau1_vertexEnergyRatio"  ,"SV_{0} Energy ratio"                          ,logy ,dodata ,extNorm ,4 ,0 ,0. ,0.);
    DrawStacked(histoTag+"_tau1_vertexDeltaR"  ,"tau1_vertexDeltaR"                          ,logy ,dodata ,extNorm ,4 ,1 ,0.1 ,1.);
    DrawStacked(histoTag+"_tau1_flightDistance2dSig"  ,"SV_{0} 2D flight distance significance"                          ,logy ,dodata ,extNorm ,2 ,1 ,0. ,20.);

    DrawStacked(histoTag+"_tau2_vertexMass"  ,"SV_{1} mass [GeV]"                          ,logy ,dodata ,extNorm ,1 ,1 ,0. ,50.);
    DrawStacked(histoTag+"_tau2_vertexEnergyRatio"  ,"SV_{1} Energy ratio"                          ,logy ,dodata ,extNorm ,4 ,0 ,0. ,0.);
    DrawStacked(histoTag+"_tau2_flightDistance2dSig"  ,"SV_{1} 2D flight distance significance"                          ,logy ,dodata ,extNorm ,2 ,1 ,0. ,20.);

    DrawStacked(histoTag+"_jetNTracks"  ,"Number of tracks"                          ,logy ,dodata ,extNorm ,1 ,0 ,0. ,0.);
    DrawStacked(histoTag+"_nSV"  ,"Number of SV"                          ,logy ,dodata ,extNorm ,1 ,0 ,0. ,0.);

    ////DrawStacked(histoTag+"_BDTG_SV"           ,"Boosted bb tagger Discriminator"                                   ,logy ,dodata ,extNorm ,2 ,0 ,0. ,0.);

    //////added by rizki - end

  }

  if (Draw_track_plots) {
    DrawStacked(histoTag+"_trk_multi_sel"      ,"Number of selected tracks in the jets" ,logy ,dodata ,extNorm ,1. ,1., 0., 40.);
    DrawStacked(histoTag+"_track_nHit"         ,"Number of hits"                        ,logy ,dodata ,extNorm ,1. ,0.);
    DrawStacked(histoTag+"_track_HPix"         ,"Number of hits in the Pixel"           ,logy ,dodata ,extNorm ,1. ,0.);
    DrawStacked(histoTag+"_track_len"          ,"Track decay length [cm]"               ,logy ,dodata ,extNorm ,2. ,0.);
    DrawStacked(histoTag+"_track_dist"         ,"Track distance to the jet axis [cm]"   ,logy ,dodata ,extNorm ,2. ,0.);
    DrawStacked(histoTag+"_track_pt"           ,"p_{T} of all the tracks [GeV/c]"       ,logy ,dodata ,extNorm ,4. ,0.);
    DrawStacked(histoTag+"_track_IPs"          ,"3D IP significance of tracks"          ,logy ,dodata ,extNorm ,2. ,0.);
    DrawStacked(histoTag+"_track_IP"           ,"3D IP of all tracks [cm]"              ,logy ,dodata ,extNorm ,2. ,0.);
    DrawStacked(histoTag+"_track_chi2"         ,"normalized #chi^{2} of the tracks"     ,logy ,dodata ,extNorm ,0. ,0.);
    DrawStacked(histoTag+"_track_dz"           ,"Track transverse IP"                   ,logy ,dodata ,extNorm ,0. ,0.);
    DrawStacked(histoTag+"_track_isfromSV"     ,"Track is from SV"                      ,logy ,dodata ,extNorm ,0. ,0.);
    DrawStacked(histoTag+"_track_IPs1tr"       ,"3D IP significance of the first track" ,logy ,dodata ,extNorm ,0. ,0.);
    DrawStacked(histoTag+"_track_IPs2tr"       ,"3D IP significance of the second track",logy ,dodata ,extNorm ,0. ,0.);
    DrawStacked(histoTag+"_track_IPs3tr"       ,"3D IP significance of the third track" ,logy ,dodata ,extNorm ,0. ,0.);
    DrawStacked(histoTag+"_track_IP1tr"        ,"3D IP of the first track"              ,logy ,dodata ,extNorm ,0. ,0.);
    DrawStacked(histoTag+"_track_IP2tr"        ,"3D IP of the second track"             ,logy ,dodata ,extNorm ,0. ,0.);
    DrawStacked(histoTag+"_track_IP3tr"        ,"3D IP of the third track"              ,logy ,dodata ,extNorm ,0. ,0.);
    DrawStacked(histoTag+"_track_IP2Ds"        ,"2D IP significance of all tracks"      ,logy ,dodata ,extNorm ,0. ,0.);
    DrawStacked(histoTag+"_track_IP2Ds1tr"     ,"2D IP significance of the first track" ,logy ,dodata ,extNorm ,0. ,0.);
    DrawStacked(histoTag+"_track_IP2Ds2tr"     ,"2D IP significance of the second track",logy ,dodata ,extNorm ,0. ,0.);
    DrawStacked(histoTag+"_track_IP2Ds3tr"     ,"2D IP significance of the second track",logy ,dodata ,extNorm ,0. ,0.);
    DrawStacked(histoTag+"_track_IP2D"         ,"2D IP of all tracks"                   ,logy ,dodata ,extNorm ,0. ,0.);
    DrawStacked(histoTag+"_track_IP2D1tr"      ,"2D IP of the first track"              ,logy ,dodata ,extNorm ,0. ,0.);
    DrawStacked(histoTag+"_track_IP2D2tr"      ,"2D IP of the second track"             ,logy ,dodata ,extNorm ,0. ,0.);
    DrawStacked(histoTag+"_track_IP2D3tr"      ,"2D IP of the third track"              ,logy ,dodata ,extNorm ,0. ,0.);
    DrawStacked(histoTag+"_track_IP2Derr"      ,"2D IP error of all tracks"             ,logy ,dodata ,extNorm ,0. ,0.);
    DrawStacked(histoTag+"_track_IP2Derr1tr"   ,"2D IP error of the first track"        ,logy ,dodata ,extNorm ,0. ,0.);
    DrawStacked(histoTag+"_track_IP2Derr2tr"   ,"2D IP error of the second track"       ,logy ,dodata ,extNorm ,0. ,0.);
    DrawStacked(histoTag+"_track_IP2Derr3tr"   ,"2D IP error of the third track"        ,logy ,dodata ,extNorm ,0. ,0.);
    DrawStacked(histoTag+"_track_IPerr"        ,"3D IP error of all tracks"             ,logy ,dodata ,extNorm ,0. ,0.);
    DrawStacked(histoTag+"_track_IPerr1tr"     ,"3D IP error of the first track"        ,logy ,dodata ,extNorm ,0. ,0.);
    DrawStacked(histoTag+"_track_IPerr2tr"     ,"3D IP error of the second track"       ,logy ,dodata ,extNorm ,0. ,0.);
    DrawStacked(histoTag+"_track_IPerr3tr"     ,"3D IP error of the third track"        ,logy ,dodata ,extNorm ,0. ,0.);
  }
  if (Draw_sv_plots){
    DrawStacked(histoTag+"_sv_multi_0"           ,"Nb. of secondary vertices"                         ,logy ,dodata ,extNorm ,1. ,0.);
    DrawStacked(histoTag+"_pt_sv"                ,"p_{T} of jets containing a SV [GeV/c]"             ,logy ,dodata ,extNorm ,4. ,0.);
    DrawStacked(histoTag+"_sv_mass"              ,"SV mass [GeV/c^{2}]"                               ,logy ,dodata ,extNorm ,(filename0.Contains("DoubleMuon") ? 5 : 5)  ,1, 0., 4.);
    DrawStacked(histoTag+"_sv_mass"              ,"SV mass [GeV/c^{2}]"                               ,logy ,dodata ,extNorm ,(filename0.Contains("DoubleMuon") ? 5 : 5)  ,1, 0., 4.);
    DrawStacked(histoTag+"_TagVarCSV_sv_mass"    ,"TagVarCSV(SV mass) [GeV/c^{2}]"                    ,logy ,dodata ,extNorm ,(filename0.Contains("DoubleMuon") ? 5 : 5)  ,1, 0., 4.);
    DrawStacked(histoTag+"_sv_deltaR_jet"        ,"#DeltaR between the jet and the SV direction"      ,logy ,dodata ,extNorm ,2. ,0.);
    DrawStacked(histoTag+"_sv_en_ratio"          ,"SV energy ratio"                                   ,logy ,dodata ,extNorm ,2. ,0.);
    DrawStacked(histoTag+"_sv_pt"                ,"SV p_{T} [GeV/c]"                                  ,logy ,dodata ,extNorm ,5. ,0.);
    DrawStacked(histoTag+"_sv_flight3DSig"       ,"SV 3D flight distance significance"                ,logy ,dodata ,extNorm ,5. ,0.);
    DrawStacked(histoTag+"_svnTrk_firstVxt"      ,"Number of tracks from the first SV"                ,logy ,dodata ,extNorm ,1. ,0.);
    DrawStacked(histoTag+"_sv_multi"             ,"nr. of SV"                                         ,logy ,dodata ,extNorm ,0. ,0.);
    DrawStacked(histoTag+"_sv_mass_3trk"         ,"SV mass if #tracks@SV >=3"                         ,logy ,dodata ,extNorm ,0. ,0.);
    DrawStacked(histoTag+"_sv_chi2norm"          ,"SV norm. #chi^{2}"                                 ,logy ,dodata ,extNorm ,0. ,0.);
    DrawStacked(histoTag+"_sv_deltaR_sumJet"     ,"#DeltaR between the jet and the SV"                ,logy ,dodata ,extNorm ,0. ,0.);
    DrawStacked(histoTag+"_sv_deltaR_sumDir"     ,"#DeltaR between the jet direction and the SV"      ,logy ,dodata ,extNorm ,0. ,0.);
    DrawStacked(histoTag+"_sv_eta"               ,"SV #eta"                                           ,logy ,dodata ,extNorm ,0. ,0.);
    DrawStacked(histoTag+"_sv_phi"               ,"SV #phi"                                           ,logy ,dodata ,extNorm ,0. ,0.);
    DrawStacked(histoTag+"_sv_flight3D"          ,"SV 3D flight distance"                             ,logy ,dodata ,extNorm ,0. ,0.);
    DrawStacked(histoTag+"_sv_flight2D"          ,"SV 2D flight distance"                             ,logy ,dodata ,extNorm ,0. ,0.);
    DrawStacked(histoTag+"_sv_flightSig2D"       ,"SV 2D flight distance significance"                ,logy ,dodata ,extNorm ,0. ,0.);
    DrawStacked(histoTag+"_sv_flight3Derr"       ,"SV 3D flight distance error"                       ,logy ,dodata ,extNorm ,0. ,0.);
    DrawStacked(histoTag+"_sv_flight2Derr"       ,"SV 2D flight distance error"                       ,logy ,dodata ,extNorm ,0. ,0.);
    DrawStacked(histoTag+"_svnTrk"               ,"nr. of tracks from a SV"                           ,logy ,dodata ,extNorm ,0. ,0.);
    //DrawStacked(histoTag+"_sv_aboveC"            ,"IP2D of the first track above the charm threshold" ,logy ,dodata ,extNorm ,0. ,0.);
  }
  if (Draw_muons_plots){
    DrawStacked(histoTag+"_muon_multi",     "Number of muons"                ,logy ,dodata ,extNorm ,0. ,0.);
    DrawStacked(histoTag+"_muon_multi_sel", "Number of selected muons"       ,logy ,dodata ,extNorm ,0. ,0.);
    DrawStacked(histoTag+"_mu_ptrel",       "p_{T} rel. of the muon [GeV/c]" ,logy ,dodata ,extNorm ,0. ,0.);
    DrawStacked(histoTag+"_mu_chi2",        "Norm. #chi^{2} of the muon"     ,logy ,dodata ,extNorm ,0. ,0.);
    DrawStacked(histoTag+"_muon_Pt",        "Muon p_{T} [GeV/c]"             ,logy ,dodata ,extNorm ,2. ,0.);
    DrawStacked(histoTag+"_muon_eta",       "Muon #eta"                      ,logy ,dodata ,extNorm ,0. ,0.);
    DrawStacked(histoTag+"_muon_phi",       "Muon #phi"                      ,logy ,dodata ,extNorm ,0. ,0.);
    DrawStacked(histoTag+"_muon_Ip3d",      "Muon 3D IP [cm]"                ,logy ,dodata ,extNorm ,6. ,0.);
    DrawStacked(histoTag+"_muon_Ip2d",      "Muon 2D IP [cm]"                ,logy ,dodata ,extNorm ,6. ,0.);
    DrawStacked(histoTag+"_muon_Sip3d",     "Muon 3D IP significance"        ,logy ,dodata ,extNorm ,0. ,0.);
    DrawStacked(histoTag+"_muon_Sip2d",     "Muon 2D IP significance"        ,logy ,dodata ,extNorm ,0. ,0.);
    DrawStacked(histoTag+"_muon_DeltaR",    "Muon1 #Delta R"                 ,logy ,dodata ,extNorm ,0. ,0.);
    DrawStacked(histoTag+"_muon_ptRatio", "(p_{T}(#mu_{1})/p_{T}(jet)" ,logy ,dodata ,extNorm ,0. ,0.);
//     DrawStacked(histoTag+"_muComb_ptRatio", "(p_{T}(#mu_{1})+p_{T}(#mu_{2}))/p_{T}(jet)" ,logy ,dodata ,extNorm ,0. ,0.);

  }
  if (Draw_Nminus1_plots){
    DrawStacked(histoTag+"_track_nHit_cut"    ,"Number of hits @N-1 step"             ,logy ,dodata ,extNorm, 0. ,0.);
    DrawStacked(histoTag+"_track_HPix_cut"    ,"Number of hits in the Pixel @N-1 step",logy ,dodata ,extNorm, 0. ,0.);
    DrawStacked(histoTag+"_track_chi2_cut"    ,"Normalized #chi^{2} @N-1 step"        ,logy ,dodata ,extNorm, 0. ,0.);
    DrawStacked(histoTag+"_track_len_cut"     ,"Decay length @N-1 step"               ,logy ,dodata ,extNorm, 0. ,0.);
    DrawStacked(histoTag+"_track_dist_cut"    ,"Distance to the jet axis @N-1 step"   ,logy ,dodata ,extNorm, 0. ,0.);
    DrawStacked(histoTag+"_track_dz_cut"      ,"Transverse IP @N-1 step"              ,logy ,dodata ,extNorm, 0. ,0.);
    DrawStacked(histoTag+"_track_pt_cut"          ,"Track p_{T} @N-1 step"            ,logy ,dodata ,extNorm, 0. ,0.);
  }
  if (Draw_discriminator_plots){
    //DrawStacked(histoTag+"_JP"    ,"JP Discriminator"                 ,1 ,1 ,0 ,0. ,0.) ;
    //DrawStacked(histoTag+"_JBP"   ,"JBP Discriminator"                ,1 ,1 ,0 ,0. ,0.) ;
    //DrawStacked(histoTag+"_SSV"   ,"SSVHE Discriminator"              ,1 ,1 ,0 ,0. ,0.) ;
    //DrawStacked(histoTag+"_SSVHP" ,"SSVHP Discriminator"              ,1 ,1 ,0 ,0. ,0.) ;
    ////DrawStacked(histoTag+"_TCHE_extended1"       ,"TCHE (extended)"   ,1,1 ,0 ,0. ,0.); //commented by rizki
    ////DrawStacked(histoTag+"_TCHP_extended1"       ,"TCHP (extended)"   ,1,1 ,0 ,0. ,0.); //commented by rizki
    //DrawStacked(histoTag+"_discri_ssche0",      "SSVHE Discriminator" ,1,1 ,0 ,0. ,0.);
    //DrawStacked(histoTag+"_discri_sschp0",      "SSVHP Discriminator" ,1,1 ,0 ,0. ,0.);
    //DrawStacked(histoTag+"_TCHE"             ,"TCHE Discriminator"    ,1,1 ,0 ,0. ,0.);
    //DrawStacked(histoTag+"_TCHP"             ,"TCHP Discriminator"    ,1,1 ,0 ,0. ,0.);
  }

  if (Draw_tagRate_plots){
    // DrawTagRate(histoTag+"_TCHE_extended1","TCHE (extended)"     ,1 , 1); //commented by rizki
    // DrawTagRate(histoTag+"_TCHP_extended1"," TCHP (extended)"    ,1 , 1); //commented by rizki
    DrawTagRate(histoTag+"_discri_ssche0","SSVHE (extended)"     ,1 , 1);
    DrawTagRate(histoTag+"_discri_sschp0","SSVHP (extended)"     ,1 , 1);
    // DrawTagRate(histoTag+"_TCHE"	      ,"TCHE Discriminator"   ,1 , 1); //commented by rizki
    // DrawTagRate(histoTag+"_TCHP"	      ,"TCHP Discriminator"   ,1 , 1); //commented by rizki
    DrawTagRate(histoTag+"_JP"	      ,"JP Discriminator"     ,1 , 1);
    DrawTagRate(histoTag+"_JBP"	      ,"JBP Discriminator"    ,1 , 1);
    DrawTagRate(histoTag+"_SSV"	      ,"SSVHE Discriminator"  ,1 , 1);
    DrawTagRate(histoTag+"_SSVHP"         ,"SSVHP Discriminator" ,1 , 1);
    DrawTagRate(histoTag+"_CSV"	      ,"CSV Discriminator"    ,1 , 1);

  }

  if (Draw_2D_plots){
    if( histoTag=="FatJet" ){
      if( !prunedjets) Draw2DPlot(histoTag+"_softdropMass_nsubjettiness", "FatJet softdrop mass vs. Nsubjettiness", "FatJet softdrop mass", "Nsubjettiness", 0, 1, 0);
      if( prunedjets) Draw2DPlot(histoTag+"_prunedMass_nsubjettiness", "FatJet pruned mass vs. Nsubjettiness", "FatJet pruned mass", "Nsubjettiness", 0, 1, 0);

      Draw2DPlot(histoTag+"_BDTGSV_trackSip3dSig_0", "BDTG SV vs IP Sig 1st Track", "BDTG SV", "IP Sig 1st Track",logy,1,0);
      Draw2DPlot(histoTag+"_BDTGSV_trackSip3dSig_1", "BDTG SV vs IP Sig 2nd Track", "BDTG SV", "IP Sig 2nd Track",logy,1,0);
      Draw2DPlot(histoTag+"_BDTGSV_trackSip3dSig_2", "BDTG SV vs IP Sig 3rd Track", "BDTG SV", "IP Sig 3rd Track",logy,1,0);
      Draw2DPlot(histoTag+"_BDTGSV_trackSip3dSig_3", "BDTG SV vs IP Sig 4th Track", "BDTG SV", "IP Sig 4th Track",logy,1,0);

      Draw2DPlot(histoTag+"_BDTGSV_jetNTracks", "BDTG SV vs Number of tracks", "BDTG SV", "Number of tracks",logy,1,0);

      Draw2DPlot(histoTag+"_jetNTracks_trackSip3dSig_0", "Number of tracks vs IP Sig 1st Track", "Number of tracks", "IP Sig 1st Track" ,logy,1,0);
      Draw2DPlot(histoTag+"_seltrack_vs_jetpt", "nr. of selected tracks as a function of the jet p_{T}", "jet p_{T}","nr. of selected tracks",logy,0,1);
      Draw2DPlot(histoTag+"_muon_ptrel_vs_jetpt", "PFMuon_p{T}^{rel} vs jet pt", "jet p_{T}","#mu ptrel",logy,0,1);
      Draw2DPlot(histoTag+"_muon_DeltaR_vs_jetpt", "Muon1 DeltaR vs jet pt", "jet p_{T}","#Delta R(muon,jet)",logy,0,1);
    }
    //Draw2DPlot("sv_mass_vs_flightDist3D", " SV mass as a function of the SV 3D flight distance ","SV 3D flight distance","SV mass",0,1);
    //Draw2DPlot("avg_sv_mass_vs_jetpt","Avg SV mass as a function of the jet p_{T}","jet p_{T}","Avg SV mass",0,1);
    //Draw2DPlot("TagVarCSV_sv_mass_vs_jetpt","Avg SV mass as a function of the jet p_{T}","jet p_{T}","Avg SV mass",0,1);
    //Draw2DPlot("sv_deltar_jet_vs_jetpt","#Delta R between the SV and the jet as a function of the jet p_{T}","jet p_{T}","#Delta R between the SV and the jet",0,1);
    //Draw2DPlot("sv_deltar_sum_jet_vs_jetpt","#Delta R between the SV and the jet sum as a function of the jet p_{T}","jet p_{T}","#Delta R between the SV and the jet sum",0,1);
    //Draw2DPlot("sv_deltar_sum_dir_vs_jetpt","#Delta R between the SV and the jet direction as a function of the jet p_{T}", "jet p_{T}","#Delta R between the SV and the jet direction",0,1);
    //Draw2DPlot("muon_ptrel_vs_jetpt","Muon_p{T}^{rel} as a function of the jet p_{T}","jet p_{T}","Muon_p{T}^{rel}",0,1);
    //Draw2DPlot("muon_DeltaR_vs_jetpt","Muon #Delta R as a function of the jet p_{T}","jet p_{T}","Muon #Delta R",0,1);
  }
}

//--------------------------
void Draw(TString name, TString histotitle, bool log) {

  TFile *myFile     = TFile::Open(filename0,"READ");
  TH1D* hist_mc;
  TH1D* hist_data;

  if (name=="h1_nPV") {
    hist_mc       = (TH1D*)myFile->Get("QCD__"+name+"_mc");
    hist_data     = (TH1D*)myFile->Get("DATA__"+name+"_data");
  }
  else if (name=="h1_nPV_unw"){    
    hist_mc       = (TH1D*)myFile->Get("QCD__h1_nPV_mc_unw");
    hist_data     = (TH1D*)myFile->Get("DATA__h1_nPV_data");
  } 	
  else {
    hist_mc       = (TH1D*)myFile->Get("QCD__"+name);
    hist_data     = (TH1D*)myFile->Get("DATA__"+name);
  }
  float scale_f = (hist_data->Integral())/(hist_mc->Integral());
  if (name=="h1_pt_hat" || "h1_pt_hat_sel") ;
  else hist_mc->Scale(scale_f);
  if (name=="h1_nPV" || name=="h1_nPV_unw") hist_mc->Scale(scale_f);
  beautify(hist_data  , 1 , 1 ,0, 1) ;  

  TH1D* histo_ratio;
  histo_ratio = (TH1D*) hist_data->Clone();
  //histo_ratio->Sumw2();
  histo_ratio->SetName("histo_ratio");
  histo_ratio->SetTitle("");
  histo_ratio->Divide(hist_mc);

  hist_data->SetLineWidth(2);
  hist_data->SetMarkerStyle(20);
  hist_data->SetMarkerSize(0.75);

  hist_mc->SetLineColor(2);
  hist_mc->SetFillColor(2);

  gStyle->SetOptTitle(0);
  gStyle->SetOptStat(0);

  //TCanvas *c1 = new TCanvas("c1", "c1",432,69,782,552);
  TCanvas *c1 = new TCanvas("c1", "c1",441,159,782,552);
  c1->Range(0,0,1,1);
  c1->SetFillColor(10);
  c1->SetBorderMode(0);
  c1->SetBorderSize(2);
  c1->SetFrameFillColor(0);
  c1->SetFrameBorderMode(0);
  c1->cd();

  TPad* pad0 = new TPad("pad0", "pad0",0,0.25,1.0,1.00);
  pad0 ->Draw();
  pad0 ->cd();
  pad0->SetFillColor(0);
  pad0->SetBorderMode(0);
  pad0->SetBorderSize(2);
  pad0->SetTopMargin(0.065);
  pad0->SetFrameBorderMode(0);

  pad0->SetLogy(log);

  hist_mc->GetXaxis()->SetTitle(name);
  hist_mc->GetYaxis()->SetTitle("Entries");
  hist_mc->SetTitleOffset(0.81,"Y");
  hist_mc->GetYaxis()->SetLabelSize( 0.05 );
  hist_mc->GetYaxis()->SetTitleSize( 0.06 );

  hist_data->Draw("E1"); //quick fix to set y-axis according to data.
  hist_mc->Draw("SAMEhist");
  hist_data->Draw("SAMEE1"); //quick fix to have data in front of mc

  TLegend* leg = new TLegend(0.56,0.60,0.86,0.85,NULL,"brNDC");
  leg->SetBorderSize(1);
  leg->SetTextFont(62);
  leg->SetLineColor(1);
  leg->SetLineStyle(1);
  leg->SetLineWidth(1);
  leg->SetFillColor(0);
  leg->SetFillStyle(1001);
  leg->SetBorderSize(0);
  leg->SetTextSize(0.07);

  leg->AddEntry(hist_data,     datacaption,   "ep");
  leg->AddEntry(hist_mc,        "MC "  ,      "f");

  leg->SetFillColor(0);
  leg->Draw();

  TLatex *   tex = new TLatex(0.42,1.00,"CMS Simulation, #sqrt{s} = 13 TeV");
  tex->SetNDC();
  tex->SetTextAlign(13);
  tex->SetTextFont(42);
  tex->SetTextFont(62);
  tex->SetTextSize(0.055);
  tex->SetLineWidth(2);
  tex->Draw();

  pad0->Modified();

  c1->cd();

  TPad* pad1 = new TPad("pad1", "pad1",0,0.,1.0,0.32);
  pad1->Draw();
  pad1->cd();
  pad1->SetFillColor(0);
  pad1->SetBorderMode(0);
  pad1->SetBorderSize(2);
  pad1->SetGridy();
  pad1->SetBottomMargin(0.31);
  pad1->SetFrameBorderMode(0);
  pad1->SetFrameBorderMode(0);

  histo_ratio->SetMarkerStyle(20);
  histo_ratio->SetMarkerSize(0.75);
  histo_ratio->SetLineWidth(2);

  histo_ratio->GetYaxis()->SetTitle("data/MC");
  histo_ratio->SetTitleOffset(0.9,"X");
  histo_ratio->SetTitleOffset(0.31,"Y");
  histo_ratio->GetXaxis()->SetTitle(histotitle);
  histo_ratio->GetYaxis()->SetNdivisions( 505 );

  double labelsizex=0.12;
  double labelsizey=0.12;
  double titlesizex=0.15;
  double titlesizey=0.14;

  histo_ratio->GetXaxis()->SetLabelSize( labelsizex );
  histo_ratio->GetXaxis()->SetTitleSize( titlesizex );
  histo_ratio->GetYaxis()->SetLabelSize( labelsizey );
  histo_ratio->GetYaxis()->SetTitleSize( titlesizey );

  histo_ratio->SetMinimum(0.4);
  histo_ratio->SetMaximum(1.6);
  histo_ratio->Draw("E1X0");

  c1->cd();

  TString name_plot=name+"_Linear"+formata;
  if(log) name_plot=name+"_Log"+formata;
  c1->SaveAs(dir4plots+"/"+name_plot);
  name_plot=name+"_Linear"+formatb;
  if(log) name_plot=name+"_Log"+formatb;
  c1->SaveAs(dir4plots+"/"+name_plot);
  name_plot=name+"_Linear"+formatc;
  if(log) name_plot=name+"_Log"+formatc;
  //c1->SaveAs(dir4plots+"/"+name_plot);

}

//--------------------------
void DrawStacked(TString name, TString histotitle, bool log, bool doData, bool fExtNorm, int nRebin, bool setXRange, double rangeXLow, double rangeXHigh) {

  TH1D* hist_data0;
  TH1D* hist_data1;
  TH1D* hist_data2;
  TH1D* hist_data3;
  TH1D* hist_data4;

  TFile *myFile0  = TFile::Open(filename0,"READ") ;
  TFile *myFile1  = TFile::Open(filename1,"READ") ;
  TFile *myFile2  = TFile::Open(filename2,"READ") ;
  TFile *myFile3  = TFile::Open(filename3,"READ") ;
  TFile *myFile4  = TFile::Open(filename4,"READ") ;

  myFile0->cd();
  if (doData)    hist_data0  = (TH1D*)myFile0->Get("DATA__"+name+"_data");

  myFile1->cd();
  if (doData)    hist_data1  = (TH1D*)myFile1->Get("DATA__"+name+"_data");

  myFile2->cd();
  if (doData)    hist_data2  = (TH1D*)myFile2->Get("DATA__"+name+"_data");

  myFile3->cd();
  if (doData)    hist_data3  = (TH1D*)myFile3->Get("DATA__"+name+"_data");

  myFile4->cd();
  if (doData)    hist_data4  = (TH1D*)myFile4->Get("DATA__"+name+"_data");

  std::cout << " hist_data0 name = " << hist_data0->GetName() << " integral = " << hist_data0->Integral() << endl ;
  std::cout << " hist_data1 name = " << hist_data1->GetName() << " integral = " << hist_data1->Integral() << endl ;
  std::cout << " hist_data2 name = " << hist_data2->GetName() << " integral = " << hist_data2->Integral() << endl ;
  std::cout << " hist_data3 name = " << hist_data3->GetName() << " integral = " << hist_data3->Integral() << endl ;
  std::cout << " hist_data4 name = " << hist_data4->GetName() << " integral = " << hist_data4->Integral() << endl ;

	if (nRebin>1) {
	  if (doData)    hist_data0->Rebin(nRebin);
	  if (doData)    hist_data1->Rebin(nRebin);
	  if (doData)    hist_data2->Rebin(nRebin);
	  if (doData)    hist_data3->Rebin(nRebin);
	  if (doData)    hist_data4->Rebin(nRebin);
	}

  if (!name.Contains("sv_mass")) {
    if (doData)    fix(hist_data0);
    if (doData)    fix(hist_data1);
    if (doData)    fix(hist_data2);
    if (doData)    fix(hist_data3);
    if (doData)    fix(hist_data4);
  }

  int xlow = hist_data0->GetXaxis()->FindBin(rangeXLow);
  int xhigh = hist_data0->GetXaxis()->FindBin(rangeXHigh);

  if (doData)    beautify(hist_data0  , 1    , 1 , 0       , 1) ;
  if (doData)    beautify(hist_data1  , 1    , 2 , 0       , 2) ;
  if (doData)    beautify(hist_data2  , 1    , 3 , 0       , 3) ;
  if (doData)    beautify(hist_data3  , 1    , 4 , 0       , 4) ;
  if (doData)    beautify(hist_data4  , 1    , 5 , 0       , 5) ;

  TString histotitle_ = histotitle;
  TString yaxistitle="" ; 
  histotitle = hist_data0->GetXaxis()->GetTitle() ; 
  if (histotitle=="BP") histotitle = "JBP discriminator" ; 
  if (histotitle=="P") histotitle = "JP discriminator" ; 
  if (histotitle=="decay length") histotitle = "track decay length [cm]" ; 

  if (histotitle=="number of selected tracks in the jets") {
    histotitle = "Number of selected tracks in the jets" ; 
    yaxistitle="jets" ; 
  }
  if (histotitle=="N(SV)") { 
    histotitle = "Number of SVs" ; 
    yaxistitle="jets" ; 
  }
  if (histotitle=="number of hits in the Pixel") {
    histotitle = "Number of pixel hits" ; 
    yaxistitle="Tracks" ; 
  }
  if (histotitle=="3D IP significance of tracks") {
    histotitle = "3D IP significance of tracks" ; 
    yaxistitle="Tracks / 1 units" ; 
  }
  if (histotitle=="Flight distance significance 3D") {
    histotitle = "SV 3D flight distance significance" ; 
    yaxistitle="SVs / 5 units" ; 
  }
  if (histotitle=="CSVIVFv2") {
    histotitle = "CSVv2 Discriminator" ; 
    yaxistitle="jets / 0.02 units" ; 
  }
  if (name.Contains("z_ratio") ){
//     yaxistitle="jets / 1.27 units";
    yaxistitle="jets / 1.3 units";
  }
  if (name.Contains("trackSip") && !name.Contains("BDTG")){
    yaxistitle="Tracks / 8 units";
  }
  if (name.Contains("trackEtaRel")){
    yaxistitle="SVs / 1 units";
  }
  if (name.Contains("vertexMass")){
    yaxistitle="SVs / 1 GeV";
  }
  if (name.Contains("vertexEnergyRatio")){
    yaxistitle="SVs / 0.05 units";
  }
  if (name.Contains("flightDistance2dSig")){
    yaxistitle="SVs / 0.4 units";
  }
  if (name.Contains("vertexDeltaR")){
    yaxistitle="SVs / 0.02 units";
  }
  if (name.Contains("jetNTracks")){
    yaxistitle="Tracks / 1 units";
  }
  if (name.Contains("_nSV")){
    yaxistitle="SVs / 1 units";
  }
  if (name.Contains("vertexDeltaR")){
    yaxistitle="jets / 0.02 units";
  }
  if (name.Contains("BDTG_SV") || name.Contains("DoubleB")){
    yaxistitle="jets / 0.04 units";
	histotitle_ = "double-b discriminator" ; 
  }
  
  //normalize to reference
  float NormToReference = hist_data0->Integral();
  hist_data1->Scale( NormToReference / hist_data1->Integral());
  hist_data2->Scale( NormToReference / hist_data2->Integral());
  hist_data3->Scale( NormToReference / hist_data3->Integral());
  hist_data4->Scale( NormToReference / hist_data4->Integral());

  THStack *stack = new THStack("stack","");
  stack->Add(hist_data0);
  //stack->Add(hist_data1);
  stack->Add(hist_data2);
  stack->Add(hist_data3);
  //stack->Add(hist_data4);
  
  TH1D *histo_ratio1, *histo_ratio2, *histo_ratio3, *histo_ratio4;
  if (doData) {
    histo_ratio1 = (TH1D*) hist_data0->Clone();
    histo_ratio2 = (TH1D*) hist_data0->Clone();
    histo_ratio3 = (TH1D*) hist_data0->Clone();
    histo_ratio4 = (TH1D*) hist_data0->Clone();

    histo_ratio1->SetName("histo_ratio");
    histo_ratio2->SetName("histo_ratio");
    histo_ratio3->SetName("histo_ratio");
    histo_ratio4->SetName("histo_ratio");

    histo_ratio1->SetTitle("");
    histo_ratio2->SetTitle("");
    histo_ratio3->SetTitle("");
    histo_ratio4->SetTitle("");

    histo_ratio1->Divide(hist_data1);
    histo_ratio2->Divide(hist_data2);
    histo_ratio3->Divide(hist_data3);
    histo_ratio4->Divide(hist_data4);
  }

  setTDRStyle();
  gStyle->SetErrorX(0.);

  int iPeriod = 5;    // 1=7TeV, 2=8TeV, 3=7+8TeV, 7=7+8+13TeV 
  int iPos = 11 ;
  int W = 800;
  int H = 600;
  int H_ref = 600;
  int W_ref = 800;
  float T = 0.08*H_ref;
  float B = 0.12*H_ref;
  float L = 0.12*W_ref;
  float R = 0.04*W_ref;

  //TCanvas *c1 = new TCanvas("c1", "c1",432,69,782,552);
  TCanvas *c1 = new TCanvas("c1", "c1",441,159,782,552);
  c1->Range(0,0,1,1);
  c1->SetFillColor(10);
  c1->SetBorderMode(0);
  c1->SetBorderSize(2);
  c1->SetFrameFillColor(0);
  c1->SetFrameBorderMode(0);

  float pad0height = (dodata? 0.25: 0.0) ; //adjust height if no data ie. no histo_ratio - added by rizki

  TPad* pad0 = new TPad("pad0", "pad0",0,pad0height,1.0,1.00);
  pad0 ->Draw();
  pad0 ->cd();
  pad0->SetFillColor(0);
  pad0->SetBorderMode(0);
  pad0->SetBorderSize(2);
  pad0->SetFrameBorderMode(0);
  pad0->SetTopMargin(0.080);
  pad0->SetLeftMargin(0.1); //reduce left white space - rizki

  pad0->SetLogy(log);

  if (!log) {
    if ( name.Contains("_sv_mass")) hist_data0->SetMaximum( doData ? hist_data0->GetMaximum()*2.1 : hist_data0->GetMaximum()*2.1) ;
    else hist_data0->SetMaximum( doData ? hist_data0->GetMaximum()*3.0 : hist_data0->GetMaximum()*3.0) ;
  }
  else {
    if (name.Contains("track_nHit") || name.Contains("track_HPix")) hist_data0->SetMaximum( doData ? hist_data0->GetMaximum()*50000000 : hist_data0->GetMaximum()*50000000) ;
    else if ( name.Contains("_sv_flight3DSig") || name.Contains("_sv_mass") || name.Contains("_track_IP") ) hist_data0->SetMaximum( doData ? hist_data0->GetMaximum()*3000000 : hist_data0->GetMaximum()*3000000) ;
    else if ( name.Contains("sv_multi_0") ) hist_data0->SetMaximum( doData ? hist_data0->GetMaximum()*10000000 : hist_data0->GetMaximum()*10000000) ; 
    else if ( name.Contains("sv_multi_0") ) hist_data0->SetMaximum( doData ? hist_data0->GetMaximum()*10000000 : hist_data0->GetMaximum()*10000000) ; 
    else if ( name.Contains("_DoubleB") ) hist_data0->SetMaximum( doData ? hist_data0->GetMaximum()*10000 : hist_data0->GetMaximum()*10000) ; 
    else if ( name.Contains("_tau1_flightDistance2dSig") ) hist_data0->SetMaximum( doData ? hist_data0->GetMaximum()*1000 : hist_data0->GetMaximum()*1000) ; 
    else if ( name.Contains("_tau2_vertexMass") ) hist_data0->SetMaximum( doData ? hist_data0->GetMaximum()*10 : hist_data0->GetMaximum()*10) ; 
    else if ( name.Contains("_z_ratio") ) hist_data0->SetMaximum( doData ? hist_data0->GetMaximum()*1000 : hist_data0->GetMaximum()*1000) ; 
    else hist_data0->SetMaximum( doData ? hist_data0->GetMaximum()*10000 : hist_data0->GetMaximum()*10000) ;

  }
  if (doData) {
    hist_data0->SetMarkerStyle(20);
    hist_data0->SetMarkerSize(0.75);
//     hist_data0->SetLineWidth(2);
    hist_data0->SetMarkerColor(1);

    hist_data1->SetMarkerStyle(21);
//     hist_data1->SetMarkerSize(0.75);
//     hist_data1->SetLineWidth(2);
    hist_data1->SetMarkerColor(2);

//     hist_data2->SetMarkerStyle(22);
    hist_data2->SetMarkerSize(0.75);
    hist_data2->SetLineStyle(1);
    hist_data2->SetLineWidth(2);
    hist_data2->SetLineColor(kRed);
    hist_data2->SetMarkerColor(kRed);

//     hist_data3->SetMarkerStyle(23);
    hist_data3->SetMarkerSize(0.75);
    hist_data3->SetLineStyle(1);
    hist_data3->SetLineWidth(1);
    hist_data3->SetMarkerColor(4);

    hist_data4->SetMarkerStyle(33);
//     hist_data4->SetMarkerSize(0.75);
//     hist_data4->SetLineWidth(2);
    hist_data4->SetMarkerColor(5);
  }

  //if (name=="jet_phi" || name=="sv_phi" || name=="muon_phi") {
  if (log) hist_data0->SetMinimum(0.5);
  else     hist_data0->SetMinimum(0.);
  //}


  if (setXRange) {
    if (rangeXLow == rangeXHigh) std::cout << "Error: X-axis low and high ranges have same value\n" ;
    else {
      hist_data0->GetXaxis()->SetRangeUser(rangeXLow, rangeXHigh) ;
    }
  }

//   stack->Draw("nostack");

  //if (uncBand) histo_unc->Draw("SAMEE2");

  if (doData) hist_data0->Draw("E1X0");
//   if (doData) hist_data1->Draw("SAMEE1X0");
  if (doData) hist_data2->Draw("hist SAMEE1X0");
  if (doData) hist_data3->Draw("hist SAMEE1X0");
//   if (doData) hist_data4->Draw("SAMEE1X0");

  pad0->RedrawAxis();

  int move_legend=0;
  //  if ( name.Contains("jet_phi") || name.Contains("sv_phi") || name.Contains("muon_phi") ) move_legend=1;
  //if (log && name.Contains("sv_en_ratio") ) move_legend=1;
  TLegend *leg ;
  if (move_legend==1) {
    leg =  new TLegend(0.12,0.55,0.43,.90,NULL,"brNDC");
  }
  else {
    leg = new TLegend(0.65,0.55,0.90,0.90,NULL,"brNDC");
  }
  leg->SetBorderSize(1);
  leg->SetTextFont(62);
  leg->SetLineColor(1);
  leg->SetLineStyle(1);
  leg->SetLineWidth(1);
  leg->SetFillColor(0);
  leg->SetFillStyle(1001);
  leg->SetBorderSize(0);
  leg->SetTextSize( (dodata? 0.05:0.035) ); //added by rizki

  if (doData) leg->AddEntry(hist_data0,     "2016 Prompt H v2,v3 (Ref)",     "e1p");
  //if (doData) leg->AddEntry(hist_data1,     "Case 1",     "e1p");
  if (doData) leg->AddEntry(hist_data2,     "2017 Prompt BC (Case 2)",     "e1pl");
  if (doData) leg->AddEntry(hist_data3,     "2017 Prompt BC (Case 3)",     "e1pl");
  //if (doData) leg->AddEntry(hist_data4,     "Case 1",     "e1p");

  leg->Draw();

  CMS_lumi( pad0, iPeriod, iPos );

  float adjustheight = 0;	

  if (setSampleName) {
    TString sample = "";
    if (filename0.Contains("InclusiveJets") && name.Contains("FatJet") ) sample += "#splitline{Multijet sample}{AK8 jets}" ;  
    else if (filename0.Contains("InclusiveJets") && name.Contains("SoftDropSubJet") ) sample += "#splitline{Multijet sample}{Soft drop subjets of AK8 jets}" ;
    else if (filename0.Contains("InclusiveJets") && name.Contains("PrunedSubJet") ) sample += "#splitline{Multijet sample}{Pruned subjets of AK8 jets}" ;

    else if (filename0.Contains("MuonTaggedFatJets")&& !filename0.Contains("DoubleMuonTaggedFatJets") && filename0.Contains("MuonEnrichedJets") && name.Contains("FatJet")) sample += "#splitline{Muon enriched multijet events}{Muon-tagged AK8 jets}" ;
    else if (filename0.Contains("MuTaggedFatJet")&& !filename0.Contains("DoubleMuonTaggedFatJets") && filename0.Contains("MuEnrichedJet") && name.Contains("FatJet")) sample += "#splitline{Muon enriched multijet events}{Muon-tagged AK8 jets}" ;
    else if (filename0.Contains("MuonTaggedFatJets")&& !filename0.Contains("DoubleMuonTaggedFatJets") && filename0.Contains("MuonEnrichedJets") && name.Contains("SoftDropSubJet") ){ sample += "#splitline{Muon enriched multijet events}{#splitline{Soft drop subjets}{of Muon-tagged AK8 jets}}" ; adjustheight = 0.08;}
    else if (filename0.Contains("MuonTaggedFatJets")&& !filename0.Contains("DoubleMuonTaggedFatJets") && filename0.Contains("MuonEnrichedJets") && name.Contains("PrunedSubJet") ){ sample += "#splitline{Muon enriched multijet events}{#splitline{Pruned subjets}{of Muon-tagged AK8 jets}}" ; adjustheight = 0.08;}

    else if (filename0.Contains("DoubleMuonTaggedFatJets")&& filename0.Contains("MuonEnrichedJets") && name.Contains("FatJet") ) sample += "#splitline{Muon enriched multijet events}{Double-muon-tagged AK8 jets}" ;  
    else if (filename0.Contains("DoubleMuonTaggedFatJets")&& filename0.Contains("MuonEnrichedJets") && name.Contains("SoftDropSubJet") ){ sample += "#splitline{Muon enriched multijet events}{#splitline{Soft drop subjets}{of Double-muon-tagged AK8 jets}}" ;adjustheight = 0.08;}
    else if (filename0.Contains("DoubleMuonTaggedFatJets")&& filename0.Contains("MuonEnrichedJets") && name.Contains("PrunedSubJet") ){ sample += "#splitline{Muon enriched multijet events}{#splitline{Pruned subjets}{of Double-muon-tagged AK8 jets}}" ;adjustheight = 0.08;}

    else if (filename0.Contains("MuonEnrichedJets") && name.Contains("FatJet")) sample += "#splitline{Muon enriched multijet events}{AK8 jets}" ;
    else if (filename0.Contains("MuonEnrichedJets") && name.Contains("SoftDropSubJet") ) sample += "#splitline{Muon enriched multijet events}{Soft drop subjets of AK8 jets}" ;
    else if (filename0.Contains("MuonEnrichedJets") && name.Contains("PrunedSubJet") ) sample += "#splitline{Muon enriched multijet events}{Pruned subjets of AK8 jets}" ;

    else if (filename0.Contains("DoubleMuonTaggedFatJets") && name.Contains("FatJet") ) sample += "#splitline{Multijet sample}{Double-muon-tagged AK8 jets}" ;  
    else if (filename0.Contains("DoubleMuonTaggedFatJets") && name.Contains("SoftDropSubJet") ) sample += "#splitline{Multijet sample}{Soft drop subjets of Double-muon-tagged AK8 jets}" ;
    else if (filename0.Contains("DoubleMuonTaggedFatJets") && name.Contains("PrunedSubJet") ) sample += "#splitline{Multijet sample}{Pruned subjets of Double-muon-tagged AK8 jets}" ;

    else if (filename0.Contains("MuonTaggedFatJets") && !filename0.Contains("DoubleMuonTaggedFatJets") && name.Contains("FatJet") ) sample += "#splitline{Multijet sample}{Muon-tagged AK8 jets}" ;  
    else if (filename0.Contains("MuonTaggedFatJets") && !filename0.Contains("DoubleMuonTaggedFatJets") && name.Contains("SoftDropSubJet") ) sample += "#splitline{Multijet sample}{Soft drop subjets of Muon-tagged AK8 jets}" ;
    else if (filename0.Contains("MuonTaggedFatJets") && !filename0.Contains("DoubleMuonTaggedFatJets") && name.Contains("PrunedSubJet") ) sample += "#splitline{Multijet sample}{Pruned subjets of Muon-tagged AK8 jets}" ;
    else if (filename0.Contains("SubjetMuTagged") && name.Contains("SoftDropSubJet") ) sample += "#splitline{Multijet sample}{Muon-tagged AK8 soft drop subjets}" ; 
    else if (filename0.Contains("SubjetMuTagged") && name.Contains("PrunedSubJet") ) sample += "#splitline{Multijet sample}{Muon-tagged AK8 pruned subjets}" ; 
    else if (filename0.Contains("MuTaggedFatJet") && !filename0.Contains("DoubleMuTaggedFatJet") && name.Contains("SoftDropSubJet") ) sample += "#splitline{Multijet sample}{#splitline{Soft drop subjets of}{Muon-tagged AK8 jets}}" ;
    else if (filename0.Contains("MuTaggedFatJet") && !filename0.Contains("DoubleMuTaggedFatJet") && name.Contains("PrunedSubJet") ) sample += "#splitline{Multijet sample}{Pruned subjets of Muon-tagged AK8 jets}" ;
    else if (filename0.Contains("MuTaggedSJ") && name.Contains("SoftDropSubJet") ) sample += "#splitline{Multijet sample}{Muon-tagged AK8 soft drop subjets}" ; 
    else if (filename0.Contains("MuTaggedSJ") && name.Contains("PrunedSubJet") ) sample += "#splitline{Multijet sample}{Muon-tagged AK8 pruned subjets}" ; 
    else {
      std::cout << " >>>> Error:Check filename0 = " << filename0 << " or name = " << name << "\n" ;
    }

    TLatex *tex1 = new TLatex(0.20,0.72,sample);
//     TLatex *tex1 = new TLatex(0.20,0.72+0.08,sample); //adjust for BTV-16-002 updateStyle_06222017
    tex1->SetNDC();
    tex1->SetTextAlign(13);
    tex1->SetTextFont(42);
    tex1->SetTextSize(0.055);
    tex1->SetLineWidth(2);
    tex1->Draw();

    //     TString jettype="" ; 
    //     if ( name.Contains("FatJet")) jettype+="AK8 jets" ; 
    //     else if  ( name.Contains("SoftDropSubJet")) jettype+="Soft drop subjets of AK8 jets" ;
    //     else if  ( name.Contains("PrunedSubJet")) jettype+="Pruned subjets of AK8 jets" ;

    //     TLatex *tex2 = new TLatex(0.20,0.68,jettype);
    //     tex2->SetNDC();
    //     tex2->SetTextAlign(13);
    //     tex2->SetTextFont(42);
    //     tex2->SetTextSize(0.055);
    //     tex2->SetLineWidth(2);
    //     tex2->Draw();

    TString jetpt=ptcut ; 

//     TLatex *tex3 = new TLatex(0.20,0.53-adjustheight,jetpt);
    TLatex *tex3 = new TLatex(0.20,0.53-adjustheight+0.07,jetpt);
//     TLatex *tex3 = new TLatex(0.20,0.53-adjustheight+0.14,jetpt); //adjust for BTV-16-002 updateStyle_06222017
    tex3->SetNDC();
    tex3->SetTextAlign(13);
    tex3->SetTextFont(42);
    tex3->SetTextSize(0.055);
    tex3->SetLineWidth(2);
    tex3->Draw();

  }

  pad0->Modified();

  c1->cd();

  if (doData) {
    TPad* pad1 = new TPad("pad1", "pad1",0,0.,1.0,0.32);
    pad1->Draw();
    pad1->cd();
    pad1->SetFillColor(0);
    pad1->SetBorderMode(0);
    pad1->SetBorderSize(2);
    pad1->SetGridy();
    pad1->SetBottomMargin(0.31);
    pad1->SetFrameBorderMode(0);
    pad1->SetLeftMargin(0.1); //reduce left white space - rizki

    histo_ratio1->SetMarkerStyle(21);
//     histo_ratio1->SetMarkerSize(0.75);
    histo_ratio1->SetMarkerColor(2);
//     histo_ratio1->SetLineWidth(2);
    histo_ratio1->SetLineStyle(2);
    histo_ratio1->SetLineColor(2);

//     histo_ratio2->SetMarkerStyle(22);
//     histo_ratio2->SetMarkerSize(0.75);
    histo_ratio2->SetMarkerColor(kRed);
    histo_ratio2->SetLineWidth(2);
    histo_ratio2->SetLineStyle(1);
    histo_ratio2->SetLineColor(kRed);

//     histo_ratio3->SetMarkerStyle(23);
//     histo_ratio3->SetMarkerSize(0.75);
    histo_ratio3->SetMarkerColor(4);
    histo_ratio3->SetLineWidth(1);
    histo_ratio3->SetLineStyle(1);
    histo_ratio3->SetLineColor(4);

    histo_ratio4->SetMarkerStyle(33);
//     histo_ratio4->SetMarkerSize(0.75);
    histo_ratio4->SetMarkerColor(5);
//     histo_ratio4->SetLineWidth(2);
    histo_ratio4->SetLineStyle(5);
    histo_ratio4->SetLineColor(5);

    histo_ratio2->GetYaxis()->SetTitle("Ref/Case");
    histo_ratio2->SetTitleOffset(0.9,"X");
    histo_ratio2->SetTitleOffset(0.31,"Y");
    histo_ratio2->GetXaxis()->SetTitle(histotitle_);
    histo_ratio2->GetYaxis()->SetNdivisions( 505 );

    double labelsizex=0.12;
    double labelsizey=0.12;
    double titlesizex=0.15;
    double titlesizey=0.14;

    histo_ratio2->GetXaxis()->SetLabelSize( labelsizex );
    histo_ratio2->GetXaxis()->SetTitleSize( titlesizex );
    histo_ratio2->GetYaxis()->SetLabelSize( labelsizey );
    histo_ratio2->GetYaxis()->SetTitleSize( titlesizey );

    if (setXRange) {
      if (rangeXLow == rangeXHigh) std::cout << "Error: X-axis low and high ranges have same value\n" ;
      else {
        histo_ratio2->GetXaxis()->SetRangeUser(rangeXLow, rangeXHigh) ;
      }
    }

    histo_ratio2->SetMinimum(0.0);
    histo_ratio2->SetMaximum(2.5);

    //histo_ratio1->Draw("E1X0");
    histo_ratio2->Draw("hist E1X0");
    histo_ratio3->Draw("hist SAMEE1X0");
    //histo_ratio4->Draw("E1X0 SAME");
    //if (uncBand) histo_ratio_unc->Draw("sameE2");

    //pad1->Update();
    pad1->Modified();
  }

  c1->cd();

  TLatex *latex = new TLatex();
  latex->SetNDC();
  latex->SetTextSize(0.035);
  latex->SetTextFont(42);
  latex->SetTextAlign(13);
  latex->DrawLatex(0.72, 0.98, title1);

  // c1->Update();
  c1->Modified();
  c1->cd();
  c1->SetSelected(c1) ;

  if( name.Contains("FatJet_phi") && nRebin==40 ) name = name + "_SingleBin";

  TString name_plot=name+"_Linear"+formata;
  if(log) name_plot=name+"_Log"+formata;
  c1->SaveAs(dir4plots+"/"+name_plot);
  name_plot=name+"_Linear"+formatb;
  if(log) name_plot=name+"_Log"+formatb;
  c1->SaveAs(dir4plots+"/"+name_plot);
  name_plot=name+"_Linear"+formatc;
//   if(log) name_plot=name+"_Log"+formatc;
//   c1->SaveAs(dir4plots+"/"+name_plot);

  if (log && web) {  // save also _Linear for web
    pad0 ->cd();
    pad0->SetLogy(false);
    c1->cd();
    c1->SaveAs(dir4plots+"/"+name+"_Linear"+formata);
  }

}

//--------------------------
void DrawTagRate(TString name, TString histotitle, bool log, bool doData){

  TH1D* hist_b;
  TH1D* hist_c;
  TH1D* hist_gsplit;
  TH1D* hist_gsplit_c;
  TH1D* hist_l;
  TH1D* hist_data;

  TFile *myFile  = TFile::Open(filename0,"READ");

  myFile->cd();
  hist_b         = (TH1D*)myFile->Get("QCD__"+name+"_b");
  hist_c         = (TH1D*)myFile->Get("QCD__"+name+"_c");
  hist_gsplit    = (TH1D*)myFile->Get("QCD__"+name+"_bfromg");
  hist_gsplit_c    = (TH1D*)myFile->Get("QCD__"+name+"_cfromg");
  hist_l         = (TH1D*)myFile->Get("QCD__"+name+"_l");
  if (doData) hist_data      = (TH1D*)myFile->Get("DATA__"+name+"_data");

  TH1D* histo_tot = (TH1D*) hist_b->Clone();
  //histo_tot->Sumw2();
  histo_tot ->Add(hist_c);
  histo_tot ->Add(hist_gsplit);
  histo_tot ->Add(hist_gsplit_c);
  histo_tot ->Add(hist_l);

  if (doData) {
    float scale_f = (hist_data->Integral())/(hist_b->Integral() + hist_c ->Integral()+ hist_gsplit->Integral() + hist_gsplit_c->Integral() + hist_l->Integral());
    hist_b       ->Scale(scale_f);
    hist_c       ->Scale(scale_f);
    hist_gsplit  ->Scale(scale_f);
    hist_gsplit_c  ->Scale(scale_f);
    hist_l       ->Scale(scale_f);
    histo_tot    ->Scale(scale_f);
  }

  int   nbinx = hist_data->GetNbinsX();
  float minx  = hist_data->GetXaxis()->GetXmin();
  float maxx  = hist_data->GetXaxis()->GetXmax();

  TH1D * TagRate_Data    = new TH1D ("TagRate_Data",histotitle,nbinx,minx,maxx);
  TH1D * TagRate_MC      = new TH1D ("TagRate_MC",histotitle,nbinx,minx,maxx);
  TH1D * TagRate_MC_b    = new TH1D ("TagRate_MC_b",histotitle,nbinx,minx,maxx);
  TH1D * TagRate_MC_c    = new TH1D ("TagRate_MC_c",histotitle,nbinx,minx,maxx);
  TH1D * TagRate_MC_udsg = new TH1D ("TagRate_MC_udsg",histotitle,nbinx,minx,maxx);
  TH1D * TagRate_MC_gspl = new TH1D ("TagRate_MC_gspl",histotitle,nbinx,minx,maxx);
  TH1D * TagRate_MC_gspl_c = new TH1D ("TagRate_MC_gspl_c",histotitle,nbinx,minx,maxx);

  int nbin_max ;
  if (doData) nbin_max = hist_data->GetNbinsX() ;

  for (int ii=0; ii<nbin_max; ii++) {

    float totdata ;
    float val ;
    float err ;
    if (doData) {
      totdata = hist_data->Integral(0,nbin_max+1);
      val = hist_data->Integral(ii+1,nbin_max+1) / totdata;
      err = sqrt(totdata *val*(1-val))/ totdata;
      TagRate_Data->SetBinContent(ii+1, val);
      TagRate_Data->SetBinError(ii+1, err);
    }

    float totmc   = histo_tot->Integral(0,nbin_max+1);
    float valMC = histo_tot->Integral(ii+1,nbin_max+1)/ totmc;
    float errMC = sqrt(totmc *valMC*(1-valMC))/ totmc;

    TagRate_MC->SetBinContent(ii+1,   histo_tot->Integral(ii+1,nbin_max+1) / totmc);
    TagRate_MC->SetBinError(ii+1, errMC  );
    TagRate_MC_b->SetBinContent(ii+1, hist_b->Integral(ii+1,nbin_max+1) / totmc);
    TagRate_MC_c->SetBinContent(ii+1, hist_c->Integral(ii+1,nbin_max+1) / totmc);
    TagRate_MC_udsg->SetBinContent(ii+1, hist_l->Integral(ii+1,nbin_max+1) / totmc);
    TagRate_MC_gspl->SetBinContent(ii+1, hist_gsplit->Integral(ii+1,nbin_max+1) / totmc);
    TagRate_MC_gspl_c->SetBinContent(ii+1, hist_gsplit_c->Integral(ii+1,nbin_max+1) / totmc);

  }

  double titleoffsety=0.2;
  double titlesizex=0.17;
  double titlesizey=0.2;
  double labelsizex=0.14;
  double labelsizey=0.12;

  if (doData) {
    TagRate_Data  ->GetYaxis()->SetLabelSize(labelsizey);
    TagRate_Data  ->GetYaxis()->SetTitleSize(titlesizey);
    TagRate_Data  ->GetYaxis()->SetTitleOffset(titleoffsety);
  }

  TagRate_MC     ->GetYaxis()->SetLabelSize(labelsizey);
  TagRate_MC     ->GetYaxis()->SetTitleSize(titlesizey);
  TagRate_MC     ->GetYaxis()->SetTitleOffset(titleoffsety);
  TagRate_MC_b   ->GetYaxis()->SetLabelSize(labelsizey);
  TagRate_MC_b   ->GetYaxis()->SetTitleSize(titlesizey);
  TagRate_MC_b   ->GetYaxis()->SetTitleOffset(titleoffsety);

  // MAKE DATA/MC RATIO

  TH1D* histo_ratio;
  if (doData) {
    histo_ratio = (TH1D*) TagRate_Data->Clone();
    histo_ratio->SetName("histo0_ratio");
    histo_ratio->SetTitle("");
    histo_ratio->Divide(TagRate_MC);

    TagRate_Data->SetMarkerStyle(20);
    TagRate_Data->SetMarkerSize(0.75);
    TagRate_Data->GetXaxis()->SetTitle();
  }

  // SET COLORS
  TagRate_MC->SetLineColor(2);
  TagRate_MC_b->SetFillColor(2);
  TagRate_MC_c->SetFillColor(8);
  TagRate_MC_gspl->SetFillColor(7);
  TagRate_MC_gspl_c->SetFillColor(6);
  TagRate_MC_udsg->SetFillColor(4);

  // DO STACK
  THStack* hs= new THStack();

  hs->Add(TagRate_MC_b);
  hs->Add(TagRate_MC_gspl);
  hs->Add(TagRate_MC_gspl_c);
  hs->Add(TagRate_MC_c);
  hs->Add(TagRate_MC_udsg);

  // SET COSMETICS
  gStyle->SetOptTitle(0);

  // CREATE CANVAS
  TCanvas *c1 = new TCanvas("c1", "c1",10,32,782,552);
  c1->cd();

  // FIRST MC & DATA
  TPad *c1_1 = new TPad("pad0", "pad0",0,0.25,1.0,0.98);
  c1_1->Draw();
  c1_1->cd();
  c1_1->SetLogy(log);

  if (doData)
    if (TagRate_Data->GetMaximum() > hs->GetMaximum() ) {
      hs->SetMaximum(TagRate_Data->GetMaximum()*1.1 );
    }
  hs->Draw("hist");

  hs->GetHistogram()->SetTitleSize(0.08,"Y");
  hs->GetHistogram()->SetTitleOffset(0.55,"Y");
  hs->GetHistogram()->GetYaxis()->SetTitle("Tag Rate");
  hs->GetHistogram()->GetXaxis()->SetTitle(histotitle);

  if (doData) TagRate_Data->Draw("e same");
  // ADD LEGEND
  TLegend* leg = 0;
  leg = new TLegend(0.6,0.73,0.95,1.);
  if (doData) leg->AddEntry(TagRate_Data,        datacaption                     ,"p");
  leg->AddEntry(TagRate_MC_b,        "b"        ,"f");
  leg->AddEntry(TagRate_MC_gspl,     "b from gluon splitting" ,"f");
  leg->AddEntry(TagRate_MC_gspl_c,   "c from gluon splitting" ,"f");
  leg->AddEntry(TagRate_MC_c,        "c"        ,"f");
  leg->AddEntry(TagRate_MC_udsg,     "udsg"     ,"f");

  leg->SetFillColor(0);
  leg->Draw();

  TLatex *latex = new TLatex();
  latex->SetNDC();
  latex->SetTextSize(0.055);
  latex->SetTextFont(62);
  latex->SetTextAlign(13);
  latex->DrawLatex(0.42, 0.96, title1);

  c1->cd();

  if (doData) {
    TPad* pad1 = new TPad("pad1", "pad1",0,0.,1.0,0.32);
    pad1->Draw();
    pad1->cd();

    gPad->SetBottomMargin(0.375);
    gPad->SetGridy();

    histo_ratio->SetMarkerStyle(20);
    histo_ratio->SetMarkerSize(0.75);
    histo_ratio->SetLineWidth(2);

    histo_ratio->GetYaxis()->SetTitle("data/MC");
    histo_ratio->GetXaxis()->SetTitle(histotitle);
    histo_ratio->GetYaxis()->SetNdivisions( 505 );

    histo_ratio->GetXaxis()->SetLabelSize( labelsizex);
    histo_ratio->GetXaxis()->SetTitleSize( titlesizex );

    histo_ratio->SetMinimum(0.4);
    histo_ratio->SetMaximum(1.6);
    histo_ratio->Draw("E1X0");
  }

  c1->cd();

  TString name_plot=name+"_Linear"+formata;
  if(log) name_plot=name+"_Log"+formata;
  c1->SaveAs(dir4plots+"/"+name_plot);
  name_plot=name+"_Linear"+formatb;
  if(log) name_plot=name+"_Log"+formatb;
  c1->SaveAs(dir4plots+"/"+name_plot);
  name_plot=name+"_Linear"+formatc;
  if(log) name_plot=name+"_Log"+formatc;
  c1->SaveAs(dir4plots+"/"+name_plot);

  if (log && web) {  // save also _Linear for web
    c1_1 ->cd();
    c1_1->SetLogy(false);
    c1->cd();
    c1->SaveAs(dir4plots+"/tag_"+name+"_Linear"+formata);
  }
}

//--------------------------
void Draw2DPlot(TString name, TString histotitle, TString titleX, TString titleY, bool log, bool doData, bool doProfile) {

  TH2D* hist_b;
  TH2D* hist_c;
  TH2D* hist_gsplit;
  TH2D* hist_gsplit_c;
  TH2D* hist_l;
  TH2D* hist_data;

  TFile *myFile     = TFile::Open(filename0,"READ");
  myFile->cd();

  hist_b         = (TH2D*)myFile->Get("QCD__"+name+"_b");
  hist_c         = (TH2D*)myFile->Get("QCD__"+name+"_c");
  hist_gsplit    = (TH2D*)myFile->Get("QCD__"+name+"_bfromg");
  hist_gsplit_c    = (TH2D*)myFile->Get("QCD__"+name+"_cfromg");
  hist_l         = (TH2D*)myFile->Get("QCD__"+name+"_l");
  hist_data      = (TH2D*)myFile->Get("DATA__"+name+"_data");

  //return ;

  hist_l        -> Scale(norm_lightjets);

  TH2D* histo_tot = (TH2D*) hist_b->Clone();
  histo_tot ->Add(hist_c);
  histo_tot ->Add(hist_gsplit);
  histo_tot ->Add(hist_gsplit_c);
  histo_tot ->Add(hist_l);

  float scale_f = (hist_data->Integral())/(hist_b->Integral() + hist_c ->Integral()+ hist_gsplit->Integral() + hist_gsplit_c->Integral() + hist_l->Integral());

  if (doData) {
    hist_b       ->Scale(scale_f);
    hist_c       ->Scale(scale_f);
    hist_gsplit  ->Scale(scale_f);
    hist_gsplit_c  ->Scale(scale_f);
    hist_l       ->Scale(scale_f);
    histo_tot    ->Scale(scale_f);
  }

  //   histo_tot->RebinX(10) ;
  //   histo_tot->RebinY(50) ;
  //   hist_data->RebinX(10) ;
  //   hist_data->RebinY(50) ;

  histo_tot->RebinX(2) ;
  histo_tot->RebinY(2) ;
  hist_data->RebinX(2) ;
  hist_data->RebinY(2) ;

  TProfile* pro_mc      ;
  TProfile* pro_mc_b    ;
  TProfile* pro_mc_c    ;
  TProfile* pro_mc_udsg ;
  TProfile* pro_mc_gspl ;
  TProfile* pro_mc_gspl_c ;
  TProfile* pro_data    ;

  if (doProfile) {
    pro_mc      = histo_tot->ProfileX(name+"_tot");
    pro_mc_b    = hist_b->ProfileX();
    pro_mc_c    = hist_c->ProfileX();
    pro_mc_udsg = hist_l->ProfileX();
    pro_mc_gspl = hist_gsplit->ProfileX();
    pro_mc_gspl_c = hist_gsplit_c->ProfileX();
    pro_data    = hist_data->ProfileX();

    pro_mc     ->Rebin(5) ;
    pro_mc_b   ->Rebin(5) ;
    pro_mc_c   ->Rebin(5) ;
    pro_mc_udsg->Rebin(5) ;
    pro_mc_gspl->Rebin(5) ;
    pro_mc_gspl_c->Rebin(5) ;
    pro_data   ->Rebin(5) ;

    //beautify(pro_mc       , 0, 0 ,1, 1);
    //beautify(pro_mc_b     , 0, 0 ,1, 1);
    //beautify(pro_mc_c     , 0, 0 ,1, 1);
    //beautify(pro_mc_udsg  , 0, 0 ,1, 1);
    //beautify(pro_mc_gspl  , 0, 0 ,1, 1);
    //beautify(pro_mc_gspl_c, 0, 0 ,1, 1);

    pro_mc->SetLineColor(1);
    pro_mc_b->SetLineColor(2);
    pro_mc_c->SetLineColor(8);
    pro_mc_udsg->SetLineColor(4);
    pro_mc_gspl->SetLineColor(7);
    pro_mc_gspl_c->SetLineColor(5);

    pro_data->SetMarkerStyle(20);
    pro_data->SetMarkerSize(0.75);

    pro_mc_gspl->GetXaxis()->SetTitle(titleX);
    pro_mc_gspl->GetYaxis()->SetTitle(titleY);

    pro_mc_gspl_c->GetXaxis()->SetTitle(titleX);
    pro_mc_gspl_c->GetYaxis()->SetTitle(titleY);

    Double_t titleoffsetx=0.8;
    Double_t titleoffsety=0.8;
    Double_t titlesizex=0.05;
    Double_t titlesizey=0.05;
    Double_t labelsizex=0.035;
    Double_t labelsizey=0.035;

    pro_data->GetYaxis()->SetLabelSize(labelsizey);
    pro_data->GetYaxis()->SetTitleSize(titlesizey);
    pro_data->GetYaxis()->SetTitleOffset(titleoffsety);
    pro_mc->GetYaxis()->SetLabelSize(labelsizey);
    pro_mc->GetYaxis()->SetTitleSize(titlesizey);
    pro_mc->GetYaxis()->SetTitleOffset(titleoffsety);
    pro_mc_b->GetYaxis()->SetLabelSize(labelsizey);
    pro_mc_b->GetYaxis()->SetTitleSize(titlesizey);
    pro_mc_b->GetYaxis()->SetTitleOffset(titleoffsety);
    pro_mc_c->GetYaxis()->SetLabelSize(labelsizey);
    pro_mc_c->GetYaxis()->SetTitleSize(titlesizey);
    pro_mc_c->GetYaxis()->SetTitleOffset(titleoffsety);

    pro_mc_gspl->GetYaxis()->SetLabelSize(labelsizey);
    pro_mc_gspl->GetYaxis()->SetTitleSize(titlesizey);
    pro_mc_gspl->GetYaxis()->SetTitleOffset(titleoffsety);

    pro_mc_gspl_c->GetYaxis()->SetLabelSize(labelsizey);
    pro_mc_gspl_c->GetYaxis()->SetTitleSize(titlesizey);
    pro_mc_gspl_c->GetYaxis()->SetTitleOffset(titleoffsety);

    pro_mc_udsg->GetYaxis()->SetLabelSize(labelsizey);
    pro_mc_udsg->GetYaxis()->SetTitleSize(titlesizey);
    pro_mc_udsg->GetYaxis()->SetTitleOffset(titleoffsety);

    pro_data->GetXaxis()->SetLabelSize(labelsizex);
    pro_data->GetXaxis()->SetTitleSize(titlesizex);
    pro_data->GetXaxis()->SetTitleOffset(titleoffsetx);
    pro_mc->GetXaxis()->SetLabelSize(labelsizex);
    pro_mc->GetXaxis()->SetTitleSize(titlesizex);
    pro_mc->GetXaxis()->SetTitleOffset(titleoffsetx);
    pro_mc_b->GetXaxis()->SetLabelSize(labelsizex);
    pro_mc_b->GetXaxis()->SetTitleSize(titlesizex);
    pro_mc_b->GetXaxis()->SetTitleOffset(titleoffsetx);
    pro_mc_c->GetXaxis()->SetLabelSize(labelsizex);
    pro_mc_c->GetXaxis()->SetTitleSize(titlesizex);
    pro_mc_c->GetXaxis()->SetTitleOffset(titleoffsetx);

    pro_mc_gspl->GetXaxis()->SetLabelSize(labelsizex);
    pro_mc_gspl->GetXaxis()->SetTitleSize(titlesizex);
    pro_mc_gspl->GetXaxis()->SetTitleOffset(titleoffsetx);

    pro_mc_gspl_c->GetXaxis()->SetLabelSize(labelsizex);
    pro_mc_gspl_c->GetXaxis()->SetTitleSize(titlesizex);
    pro_mc_gspl_c->GetXaxis()->SetTitleOffset(titleoffsetx);

    pro_mc_udsg->GetXaxis()->SetLabelSize(labelsizex);
    pro_mc_udsg->GetXaxis()->SetTitleSize(titlesizex);
    pro_mc_udsg->GetXaxis()->SetTitleOffset(titleoffsetx);

    float maxhist= pro_mc_gspl->GetMaximum();
    if (pro_mc_b->GetMaximum() > maxhist) maxhist = pro_mc_b->GetMaximum()*1.1;
    if (pro_mc_c->GetMaximum() > maxhist) maxhist = pro_mc_c->GetMaximum()*1.1;
    if (pro_mc_gspl_c->GetMaximum() > maxhist) maxhist = pro_mc_gspl_c->GetMaximum()*1.1;
    if (pro_mc_udsg->GetMaximum() > maxhist) maxhist = pro_mc_udsg->GetMaximum()*1.1;
    if (pro_mc->GetMaximum() > maxhist) maxhist = pro_mc->GetMaximum()*1.1;
    if (pro_data->GetMaximum() > maxhist) maxhist = pro_data->GetMaximum()*1.1;

    float minhist= pro_mc_gspl->GetMinimum();
    if (pro_mc_b->GetMinimum() < minhist) minhist = pro_mc_b->GetMinimum()*0.9;
    if (pro_mc_c->GetMinimum() < minhist) minhist = pro_mc_c->GetMinimum()*0.9;
    if (pro_mc_gspl_c->GetMinimum() < minhist) minhist = pro_mc_gspl_c->GetMinimum()*0.9;
    if (pro_mc_udsg->GetMinimum() < minhist) minhist = pro_mc_udsg->GetMinimum()*0.9;
    if (pro_mc->GetMinimum() < minhist) minhist = pro_mc->GetMinimum()*0.9;
    if (pro_data->GetMinimum() < minhist) minhist = pro_data->GetMinimum()*0.9;

    if (maxhist> pro_mc_gspl->GetMaximum()) pro_mc_gspl->SetMaximum(maxhist);
    if (pro_mc_gspl->GetMinimum() >minhist) pro_mc_gspl->SetMinimum(minhist);

    pro_mc_gspl->Draw("hist");
    pro_mc_b->Draw("hist,same");
    pro_mc_gspl_c->Draw("hist,same");
    pro_mc_c->Draw("hist,same");
    pro_mc_udsg->Draw("hist,same");
    pro_mc->Draw("hist,same");
    pro_data->Draw("e,same");
  }

  TCanvas *canvas = new TCanvas("c1", "c1",10,32,782,552);
  canvas->cd();
  canvas->SetRightMargin(0.08) ;

  hist_data->SetMarkerStyle(kOpenCircle) ;
  histo_tot->SetMarkerStyle(kOpenCircle) ;
  hist_data->SetMarkerColor(kBlack) ;
  histo_tot->SetMarkerColor(kBlue) ;

  histo_tot->SetMinimum(0) ;
  histo_tot->SetMaximum(10) ;

  TAxis* ax = histo_tot->GetXaxis() ;
  TAxis* ay = histo_tot->GetYaxis() ;
  ax->SetTitle(titleX) ;
  ay->SetTitle(titleY) ;
  ax->SetNoExponent(kTRUE) ;
  ay->SetNoExponent(kTRUE) ;
  beautifyAxis(ax) ;
  beautifyAxis(ay) ;

  histo_tot->Draw("");
  hist_data->Draw("SAME");

  TLegend* leg = 0;
  leg =  new TLegend(0.7,0.82,0.9,.94);
  if (doProfile) {
    leg =  new TLegend(0.6,0.73,0.95,1.);
    leg->AddEntry(pro_data,        datacaption              ,"p") ;
    leg->AddEntry(pro_mc,          "total "                 ,"l") ;
    leg->AddEntry(pro_mc_b,        "b"                ,"l") ;
    leg->AddEntry(pro_mc_gspl,     "b from gluon splitting" ,"l") ;
    leg->AddEntry(pro_mc_c,        "c"                ,"l") ;
    leg->AddEntry(pro_mc_gspl_c,   "c from gluon splitting" ,"l") ;
    leg->AddEntry(pro_mc_udsg,     "udsg"     ,"l") ;
  }
  else {
    leg->AddEntry(hist_data,  datacaption ,"p") ;
    leg->AddEntry(histo_tot,  "QCD MC"    ,"p") ;
  }
  leg->SetBorderSize(2);
  leg->SetFillColor(0);
  leg->Draw();

  TString name_plot=name+"_Linear"+formata;
  if(log) name_plot=name+"_Log"+formata;
  canvas->SaveAs(dir4plots+"/"+name_plot);
  //   name_plot=name+"_Linear"+formatb;
  //   if(log) name_plot=name+"_Log"+formatb;
  //   canvas->SaveAs(dir4plots+"/"+name_plot);
  //   name_plot=name+"_Linear"+formatc;
  //   if(log) name_plot=name+"_Log"+formatc;
  //   canvas->SaveAs(dir4plots+"/"+name_plot);

}
