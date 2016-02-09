// -*- C++ -*-
//
// Package:    BTagValidation
// Class:      BTagValidation
//
/**\class BTagValidation BTagValidation.cc RecoBTag/BTagValidation/src/BTagValidation.cc

Description: [one line class summary]

Implementation:
[Notes on implementation]
*/
//
// Original Author:  Devdatta Majumder,13 2-054,+41227671675,
//         Created:  Fri May 17 13:56:04 CEST 2013
// $Id: BTagValidation.cc,v 1.21 2013/06/13 12:18:56 devdatta Exp $
//
//


// system include files
#include <iostream>
#include <memory>

// user include files
#include "FWCore/Framework/interface/Frameworkfwd.h"
#include "FWCore/Framework/interface/EDAnalyzer.h"

#include "FWCore/Framework/interface/Event.h"
#include "FWCore/Framework/interface/MakerMacros.h"

#include "FWCore/ParameterSet/interface/ParameterSet.h"

#include "FWCore/ServiceRegistry/interface/Service.h"
#include "CommonTools/UtilAlgos/interface/TFileService.h"

#include "PhysicsTools/Utilities/interface/LumiReWeighting.h"
#include "DataFormats/Math/interface/deltaR.h"

#include "RecoBTag/PerformanceMeasurements/interface/JetInfoBranches.h"
#include "RecoBTag/PerformanceMeasurements/interface/EventInfoBranches.h"

#include <TString.h>
#include <TChain.h>
#include <TFile.h>
#include <TH1D.h>
#include <TH2D.h>
#include <TProfile.h>
#include <TLorentzVector.h>
#include <TF1.h>

#include <string>
#include <map>
#include <vector>

//
// class declaration
//

class BTagValidation : public edm::EDAnalyzer {
  public:
    explicit BTagValidation(const edm::ParameterSet&);
    ~BTagValidation();

    static void fillDescriptions(edm::ConfigurationDescriptions& descriptions);

  private:
    virtual void beginJob();
    virtual void analyze(const edm::Event&, const edm::EventSetup&);
    virtual void endJob();

    virtual void beginRun(edm::Run const&, edm::EventSetup const&);
    virtual void endRun(edm::Run const&, edm::EventSetup const&);
    virtual void beginLuminosityBlock(edm::LuminosityBlock const&, edm::EventSetup const&);
    virtual void endLuminosityBlock(edm::LuminosityBlock const&, edm::EventSetup const&);

    bool passTrigger() ;
    bool passMuonSelection(const int muIdx, const JetInfoBranches& JetInfo, const int iJet, const double deltaR=0.4);

    //// Manage histograms
    void createJetHistos(const TString& histoTag);
    void AddHisto(const TString& name, const TString& title, const int nbins, const double min, const double max);

    template <class Type>
      void FillHisto(const TString& name, const int flavour, const bool isGSPbb, const bool isGSPcc ,const Type value, const double weight);

    //// Fill jet histograms
    void fillJetHistos(const JetInfoBranches& JetInfo, const int iJet, const bool isGSPbb, const bool isGSPcc, const TString& histoTag, const int nmu, const int nselmuon, const int idxFirstMuon, const double wt);

    // b-tagging scale factors
    double scaleFactor(const int partonFlavor, const double jetPt, const double jetEta, const bool isCSVM);

    double scaleFactorB_CSVL(const double jetPt, const double jetEta);
    double scaleFactorC_CSVL(const double jetPt, const double jetEta);
    double scaleFactorUDSG_CSVL(const double jetPt, const double jetEta);

    double scaleFactorB_CSVM(const double jetPt, const double jetEta);
    double scaleFactorC_CSVM(const double jetPt, const double jetEta);
    double scaleFactorUDSG_CSVM(const double jetPt, const double jetEta);

    double GetLumiWeightsPVBased (const std::string file, const std::string hist, const int npv) ; 
    double GetLumiWeightsJetPtBased (const std::string file, const std::string hist, const double jetpt) ;
    // ----------member data ---------------------------
    EventInfoBranches EvtInfo;
    JetInfoBranches FatJetInfo;
    SubJetInfoBranches SubJetInfo;

    JetInfoBranches SubJets ;

    TChain* JetTreeEvtInfo;
    TChain* JetTree;

    std::map<TString, TH1D*> HistoBtag_map;
    std::map<TString, TH2D*> HistoBtag2D_map;

    edm::Service<TFileService> fs;

    TH1D *h1_CutFlow;
    TH1D *h1_CutFlow_unw;
    TH1D *h1_nPUtrue_mc;
    TH1D *h1_nPUtrue_mc_unw;
    TH1D *h1_nPV_data;
    TH1D *h1_nPV_mc;
    TH1D *h1_nPV_mc_unw;
    TH1D *h1_pt_hat;
    TH1D *h1_pt_hat_sel;

    TH1D *h1_nFatJet;
    TH1D *h1_fatjet_pt;

    TH1D *h1_nSubJet;
    TH1D *h1_subjet_pt;

    // CSVL scale factors
    TF1  *CSVL_SFb_0to2p4;
    TH1D *CSVL_SFb_errors;

    TF1 *CSVL_SFl_0to0p5;
    TF1 *CSVL_SFl_0p5to1p0;
    TF1 *CSVL_SFl_1p0to1p5;
    TF1 *CSVL_SFl_1p5to2p4;

    TF1 *CSVL_SFl_0to0p5_min;
    TF1 *CSVL_SFl_0p5to1p0_min;
    TF1 *CSVL_SFl_1p0to1p5_min;
    TF1 *CSVL_SFl_1p5to2p4_min;

    TF1 *CSVL_SFl_0to0p5_max;
    TF1 *CSVL_SFl_0p5to1p0_max;
    TF1 *CSVL_SFl_1p0to1p5_max;
    TF1 *CSVL_SFl_1p5to2p4_max;

    // CSVM scale factors
    TF1  *CSVM_SFb_0to2p4;
    TH1D *CSVM_SFb_errors;

    TF1 *CSVM_SFl_0to0p8;
    TF1 *CSVM_SFl_0p8to1p6;
    TF1 *CSVM_SFl_1p6to2p4;

    TF1 *CSVM_SFl_0to0p8_min;
    TF1 *CSVM_SFl_0p8to1p6_min;
    TF1 *CSVM_SFl_1p6to2p4_min;

    TF1 *CSVM_SFl_0to0p8_max;
    TF1 *CSVM_SFl_0p8to1p6_max;
    TF1 *CSVM_SFl_1p6to2p4_max;

    //// Lumi reweighting object
    edm::LumiReWeighting LumiWeights_;

    //// Configurables
    const int                       maxEvents_;
    const int                       reportEvery_;
    const bool                      useJetProbaTree_;
    const std::string               inputTTreeEvtInfo_;
    const std::string               inputTTree_;
    const std::vector<std::string>  inputFiles_;
    const bool                      useFlavorCategories_;
    const bool                      useRelaxedMuonID_;
    const bool                      applyFatJetMuonTagging_;
    const bool                      fatJetDoubleTagging_;
    const bool                      applyFatJetBTagging_;
    const bool                      fatJetDoubleBTagging_;
    const bool                      fatJetDoubleSVBTagging_;
    const bool                      applySubJetMuonTagging_;
    const bool                      applySubJetBTagging_;
    const bool                      dynamicMuonSubJetDR_;
    const double                    fatJetBDiscrCut_;
    const double                    fatJetDoubleSVBDiscrMin_;
    const double                    fatJetDoubleSVBDiscrMax_;
    const double                    subJetBDiscrMin_;
    const double                    subJetBDiscrMax_;
    const double                    fatJetPtMin_;
    const double                    fatJetPtMax_;
    const double                    fatJetAbsEtaMax_;
    const double                    fatJetGroomedMassMin_;
    const double                    fatJetGroomedMassMax_;
    const double		                fatJetTau21Min_;
    const double		                fatJetTau21Max_;
    const double                    SFbShift_;
    const double                    SFlShift_;
    const std::vector<std::string>  triggerSelection_;
    const std::vector<std::string>  triggerPathNames_;
    const std::string               file_PVWt_ ; 
    const std::string               file_PUDistMC_ ;
    const std::string               file_PUDistData_ ;
    const std::string               file_FatJetPtWt_ ;
    const std::string               file_SubJetPtWt_ ;
    const std::string               hist_PVWt_ ; 
    const std::string               hist_PUDistMC_ ;
    const std::string               hist_PUDistData_ ;
    const std::string               hist_FatJetPtWt_ ;
    const std::string               hist_SubJetPtWt_ ;
    const bool                      doPUReweightingOfficial_ ;
    const bool                      doPUReweightingNPV_ ;
    const bool                      doFatJetPtReweighting_ ;
    const bool                      doSubJetPtReweighting_ ;
    const bool                      usePrunedSubjets_ ;
    const bool                      useSoftDropSubjets_ ;

    const bool                      applySFs_;
    const std::string               btagCSVFile_ ; 
    const int                       btagOperatingPoint_ ; 
    const std::string               btagMeasurementType_ ; 
    const std::string               btagSFType_  ; 

    //// Event variables
    bool isData;
    int nEventsAll;
    int nEventsStored;

    static const double ptbinsLow_[4] ; 
    static const double ptbinsHigh_[4] ; 

    static const double CSVv2L_;
    static const double CSVv2M_;
    static const double CMVAv2L_;
    static const double CMVAv2M_;
    static const double DoubleBL_;
    static const double DoubleBM_;

};

//
// constants, enums and typedefs
//

//
// static data member definitions
//
const double BTagValidation::ptbinsLow_[4] = {0.,250.,350.,450.,} ; 
const double BTagValidation::ptbinsHigh_[4] = {250.,350.,450.,2000.} ; 
const double BTagValidation::CSVv2L_ = 0.460 ; 
const double BTagValidation::CSVv2M_ = 0.800 ; 
const double BTagValidation::CMVAv2L_ = -0.715 ; 
const double BTagValidation::CMVAv2M_ = 0.185; 
const double BTagValidation::DoubleBL_ = 0.3 ; 
const double BTagValidation::DoubleBM_ = 0.4; 

//
// constructors and destructor
//
BTagValidation::BTagValidation(const edm::ParameterSet& iConfig) :
  maxEvents_(iConfig.getParameter<int>("MaxEvents")),
  reportEvery_(iConfig.getParameter<int>("ReportEvery")),
  useJetProbaTree_(iConfig.getParameter<bool>("UseJetProbaTree")),
  inputTTreeEvtInfo_(iConfig.getParameter<std::string>("InputTTreeEvtInfo")),
  inputTTree_(iConfig.getParameter<std::string>("InputTTree")),
  inputFiles_(iConfig.getParameter<std::vector<std::string> >("InputFiles")),
  useFlavorCategories_(iConfig.getParameter<bool>("UseFlavorCategories")),
  useRelaxedMuonID_(iConfig.getParameter<bool>("UseRelaxedMuonID")),
  applyFatJetMuonTagging_(iConfig.getParameter<bool>("ApplyFatJetMuonTagging")),
  fatJetDoubleTagging_(iConfig.getParameter<bool>("FatJetDoubleTagging")),
  applyFatJetBTagging_(iConfig.getParameter<bool>("ApplyFatJetBTagging")),
  fatJetDoubleBTagging_(iConfig.exists("FatJetDoubleBTagging") ? iConfig.getParameter<bool>("FatJetDoubleBTagging") : fatJetDoubleTagging_ ),
  fatJetDoubleSVBTagging_(iConfig.getParameter<bool>("FatJetDoubleSVBTagging")),
  applySubJetMuonTagging_(iConfig.getParameter<bool>("ApplySubJetMuonTagging")),
  applySubJetBTagging_(iConfig.getParameter<bool>("ApplySubJetBTagging")),
  dynamicMuonSubJetDR_(iConfig.getParameter<bool>("DynamicMuonSubJetDR")),
  fatJetBDiscrCut_(iConfig.getParameter<double>("FatJetBDiscrCut")),
  fatJetDoubleSVBDiscrMin_(iConfig.getParameter<double>("FatJetDoubleSVBDiscrMin")),
  fatJetDoubleSVBDiscrMax_(iConfig.getParameter<double>("FatJetDoubleSVBDiscrMax")),
  subJetBDiscrMin_(iConfig.getParameter<double>("SubJetBDiscrMin")),
  subJetBDiscrMax_(iConfig.getParameter<double>("SubJetBDiscrMax")),
  fatJetPtMin_(iConfig.getParameter<double>("FatJetPtMin")),
  fatJetPtMax_(iConfig.getParameter<double>("FatJetPtMax")),
  fatJetAbsEtaMax_(iConfig.getParameter<double>("FatJetAbsEtaMax")),
  fatJetGroomedMassMin_(iConfig.getParameter<double>("FatJetGroomedMassMin")),
  fatJetGroomedMassMax_(iConfig.getParameter<double>("FatJetGroomedMassMax")),
  fatJetTau21Min_(iConfig.getParameter<double>("FatJetTau21Min")),
  fatJetTau21Max_(iConfig.getParameter<double>("FatJetTau21Max")),
  SFbShift_(iConfig.getParameter<double>("SFbShift")),
  SFlShift_(iConfig.getParameter<double>("SFlShift")),
  triggerSelection_(iConfig.getParameter<std::vector<std::string> >("TriggerSelection")),
  triggerPathNames_(iConfig.getParameter<std::vector<std::string> >("TriggerPathNames")),
  file_PVWt_(iConfig.getParameter<std::string>("File_PVWt")),
  file_PUDistMC_(iConfig.getParameter<std::string>("File_PUDistMC")),
  file_PUDistData_(iConfig.getParameter<std::string>("File_PUDistData")),
  file_FatJetPtWt_(iConfig.getParameter<std::string>("File_FatJetPtWt")),
  file_SubJetPtWt_(iConfig.getParameter<std::string>("File_SubJetPtWt")),
  hist_PVWt_(iConfig.getParameter<std::string>("Hist_PVWt")),
  hist_PUDistMC_(iConfig.getParameter<std::string>("Hist_PUDistMC")),
  hist_PUDistData_(iConfig.getParameter<std::string>("Hist_PUDistData")),
  hist_FatJetPtWt_(iConfig.getParameter<std::string>("Hist_FatJetPtWt")),
  hist_SubJetPtWt_(iConfig.getParameter<std::string>("Hist_SubJetPtWt")),
  doPUReweightingOfficial_(iConfig.getParameter<bool>("DoPUReweightingOfficial")),
  doPUReweightingNPV_(iConfig.getParameter<bool>("DoPUReweightingNPV")),
  doFatJetPtReweighting_(iConfig.getParameter<bool>("DoFatJetPtReweighting")),
  doSubJetPtReweighting_(iConfig.getParameter<bool>("DoSubJetPtReweighting")),
  usePrunedSubjets_(iConfig.getParameter<bool>("UsePrunedSubjets")),
  useSoftDropSubjets_(iConfig.getParameter<bool>("UseSoftDropSubjets")), 
  applySFs_(iConfig.getParameter<bool>("ApplySFs")),
  btagCSVFile_(iConfig.getParameter<std::string>("btagCSVFile")), 
  btagOperatingPoint_(iConfig.getParameter<int>("btagOperatingPoint")), 
  btagMeasurementType_(iConfig.getParameter<std::string>("btagMeasurementType")), 
  btagSFType_(iConfig.getParameter<std::string>("btagSFType")) 
{
  //now do what ever initialization is needed
  isData = true;
  nEventsAll = 0;
  nEventsStored = 0;

  if (doPUReweightingOfficial_) LumiWeights_ = edm::LumiReWeighting(file_PUDistMC_, file_PUDistData_, hist_PUDistMC_, hist_PUDistData_) ;

  // Pt bins for SFb
  double PtBins[] = {20, 30, 40, 50, 60, 70, 80, 100, 120, 160, 210, 260, 320, 400, 500, 600, 800};

  // CSVL scale factors
  CSVL_SFb_0to2p4 = new TF1("CSVL_SFb_0to2p4","0.997942*((1.+(0.00923753*x))/(1.+(0.0096119*x)))", 20.,800.);

  CSVL_SFb_errors = new TH1D("CSVL_SFb_errors", "CSVL_SFb_errors", 16, PtBins);
  CSVL_SFb_errors->SetBinContent( 0,(2*0.033299));
  CSVL_SFb_errors->SetBinContent( 1,0.033299);
  CSVL_SFb_errors->SetBinContent( 2,0.0146768);
  CSVL_SFb_errors->SetBinContent( 3,0.013803);
  CSVL_SFb_errors->SetBinContent( 4,0.0170145);
  CSVL_SFb_errors->SetBinContent( 5,0.0166976);
  CSVL_SFb_errors->SetBinContent( 6,0.0137879);
  CSVL_SFb_errors->SetBinContent( 7,0.0149072);
  CSVL_SFb_errors->SetBinContent( 8,0.0153068);
  CSVL_SFb_errors->SetBinContent( 9,0.0133077);
  CSVL_SFb_errors->SetBinContent(10,0.0123737);
  CSVL_SFb_errors->SetBinContent(11,0.0157152);
  CSVL_SFb_errors->SetBinContent(12,0.0175161);
  CSVL_SFb_errors->SetBinContent(13,0.0209241);
  CSVL_SFb_errors->SetBinContent(14,0.0278605);
  CSVL_SFb_errors->SetBinContent(15,0.0346928);
  CSVL_SFb_errors->SetBinContent(16,0.0350099);
  CSVL_SFb_errors->SetBinContent(17,(2*0.0350099));

  CSVL_SFl_0to0p5 =   new TF1("CSVL_SFl_0to0p5","((1.01177+(0.0023066*x))+(-4.56052e-06*(x*x)))+(2.57917e-09*(x*(x*x)))", 20.,1000.);
  CSVL_SFl_0p5to1p0 = new TF1("CSVL_SFl_0p5to1p0","((0.975966+(0.00196354*x))+(-3.83768e-06*(x*x)))+(2.17466e-09*(x*(x*x)))", 20.,1000.);
  CSVL_SFl_1p0to1p5 = new TF1("CSVL_SFl_1p0to1p5","((0.93821+(0.00180935*x))+(-3.86937e-06*(x*x)))+(2.43222e-09*(x*(x*x)))", 20.,1000.);
  CSVL_SFl_1p5to2p4 = new TF1("CSVL_SFl_1p5to2p4","((1.00022+(0.0010998*x))+(-3.10672e-06*(x*x)))+(2.35006e-09*(x*(x*x)))", 20.,850.);

  CSVL_SFl_0to0p5_min =   new TF1("CSVL_SFl_0to0p5_min","((0.977761+(0.00170704*x))+(-3.2197e-06*(x*x)))+(1.78139e-09*(x*(x*x)))", 20.,1000.);
  CSVL_SFl_0p5to1p0_min = new TF1("CSVL_SFl_0p5to1p0_min","((0.945135+(0.00146006*x))+(-2.70048e-06*(x*x)))+(1.4883e-09*(x*(x*x)))", 20.,1000.);
  CSVL_SFl_1p0to1p5_min = new TF1("CSVL_SFl_1p0to1p5_min","((0.911657+(0.00142008*x))+(-2.87569e-06*(x*x)))+(1.76619e-09*(x*(x*x)))", 20.,1000.);
  CSVL_SFl_1p5to2p4_min = new TF1("CSVL_SFl_1p5to2p4_min","((0.970045+(0.000862284*x))+(-2.31714e-06*(x*x)))+(1.68866e-09*(x*(x*x)))", 20.,850.);

  CSVL_SFl_0to0p5_max =   new TF1("CSVL_SFl_0to0p5_max","((1.04582+(0.00290226*x))+(-5.89124e-06*(x*x)))+(3.37128e-09*(x*(x*x)))", 20.,1000.);
  CSVL_SFl_0p5to1p0_max = new TF1("CSVL_SFl_0p5to1p0_max","((1.00683+(0.00246404*x))+(-4.96729e-06*(x*x)))+(2.85697e-09*(x*(x*x)))", 20.,1000.);
  CSVL_SFl_1p0to1p5_max = new TF1("CSVL_SFl_1p0to1p5_max","((0.964787+(0.00219574*x))+(-4.85552e-06*(x*x)))+(3.09457e-09*(x*(x*x)))", 20.,1000.);
  CSVL_SFl_1p5to2p4_max = new TF1("CSVL_SFl_1p5to2p4_max","((1.03039+(0.0013358*x))+(-3.89284e-06*(x*x)))+(3.01155e-09*(x*(x*x)))", 20.,850.);

  // CSVM scale factors
  CSVM_SFb_0to2p4 = new TF1("CSVM_SFb_0to2p4","(0.938887+(0.00017124*x))+(-2.76366e-07*(x*x))", 20.,800.);

  CSVM_SFb_errors = new TH1D("CSVM_SFb_errors", "CSVM_SFb_errors", 16, PtBins);
  CSVM_SFb_errors->SetBinContent( 0,(2*0.0415707));
  CSVM_SFb_errors->SetBinContent( 1,0.0415707);
  CSVM_SFb_errors->SetBinContent( 2,0.0204209);
  CSVM_SFb_errors->SetBinContent( 3,0.0223227);
  CSVM_SFb_errors->SetBinContent( 4,0.0206655);
  CSVM_SFb_errors->SetBinContent( 5,0.0199325);
  CSVM_SFb_errors->SetBinContent( 6,0.0174121);
  CSVM_SFb_errors->SetBinContent( 7,0.0202332);
  CSVM_SFb_errors->SetBinContent( 8,0.0182446);
  CSVM_SFb_errors->SetBinContent( 9,0.0159777);
  CSVM_SFb_errors->SetBinContent(10,0.0218531);
  CSVM_SFb_errors->SetBinContent(11,0.0204688);
  CSVM_SFb_errors->SetBinContent(12,0.0265191);
  CSVM_SFb_errors->SetBinContent(13,0.0313175);
  CSVM_SFb_errors->SetBinContent(14,0.0415417);
  CSVM_SFb_errors->SetBinContent(15,0.0740446);
  CSVM_SFb_errors->SetBinContent(16,0.0596716);
  CSVM_SFb_errors->SetBinContent(17,(2*0.0596716));

  CSVM_SFl_0to0p8 =   new TF1("CSVM_SFl_0to0p8","((1.07541+(0.00231827*x))+(-4.74249e-06*(x*x)))+(2.70862e-09*(x*(x*x)))", 20.,1000.);
  CSVM_SFl_0p8to1p6 = new TF1("CSVM_SFl_0p8to1p6","((1.05613+(0.00114031*x))+(-2.56066e-06*(x*x)))+(1.67792e-09*(x*(x*x)))", 20.,1000.);
  CSVM_SFl_1p6to2p4 = new TF1("CSVM_SFl_1p6to2p4","((1.05625+(0.000487231*x))+(-2.22792e-06*(x*x)))+(1.70262e-09*(x*(x*x)))", 20.,850.);

  CSVM_SFl_0to0p8_min =   new TF1("CSVM_SFl_0to0p8_min","((0.964527+(0.00149055*x))+(-2.78338e-06*(x*x)))+(1.51771e-09*(x*(x*x)))", 20.,1000.);
  CSVM_SFl_0p8to1p6_min = new TF1("CSVM_SFl_0p8to1p6_min","((0.946051+(0.000759584*x))+(-1.52491e-06*(x*x)))+(9.65822e-10*(x*(x*x)))", 20.,1000.);
  CSVM_SFl_1p6to2p4_min = new TF1("CSVM_SFl_1p6to2p4_min","((0.956736+(0.000280197*x))+(-1.42739e-06*(x*x)))+(1.0085e-09*(x*(x*x)))", 20.,850.);

  CSVM_SFl_0to0p8_max =   new TF1("CSVM_SFl_0to0p8_max","((1.18638+(0.00314148*x))+(-6.68993e-06*(x*x)))+(3.89288e-09*(x*(x*x)))", 20.,1000.);
  CSVM_SFl_0p8to1p6_max = new TF1("CSVM_SFl_0p8to1p6_max","((1.16624+(0.00151884*x))+(-3.59041e-06*(x*x)))+(2.38681e-09*(x*(x*x)))", 20.,1000.);
  CSVM_SFl_1p6to2p4_max = new TF1("CSVM_SFl_1p6to2p4_max","((1.15575+(0.000693344*x))+(-3.02661e-06*(x*x)))+(2.39752e-09*(x*(x*x)))", 20.,850.);
}


BTagValidation::~BTagValidation() {

  // do anything here that needs to be done at desctruction time
  // (e.g. close files, deallocate resources etc.)

}


//
// member functions
//

// ------------ method called once each job just before starting event loop  ------------
void BTagValidation::beginJob() {

  JetTreeEvtInfo = new TChain(inputTTreeEvtInfo_.c_str());
  JetTree = new TChain(inputTTree_.c_str());

  for(unsigned i=0; i<inputFiles_.size(); ++i)
  {
    JetTreeEvtInfo->Add(inputFiles_.at(i).c_str());
    JetTree->Add(inputFiles_.at(i).c_str());

    TFile *f = TFile::Open(inputFiles_.at(i).c_str(),"READ");

    TH1D *hEventCountAll    = (TH1D*)f->Get("allEvents/hEventCount");
    TH1D *hEventCountStored = (TH1D*)f->Get("selectedEvents/hEventCount");

    nEventsAll+=hEventCountAll->GetBinContent(1);
    nEventsStored+=hEventCountStored->GetBinContent(1);

    f->Close();
  }


  EvtInfo.ReadTree(JetTreeEvtInfo);
  FatJetInfo.ReadTree(JetTree,"FatJetInfo");
  FatJetInfo.ReadFatJetSpecificTree(JetTree,"FatJetInfo",true);
  FatJetInfo.ReadCSVTagVarTree(JetTree, "FatJetInfo");
  FatJetInfo.ReadJetSVTree(JetTree, "FatJetInfo"); 
  if (useJetProbaTree_) {
    EvtInfo.ReadJetTrackTree(JetTreeEvtInfo);
    FatJetInfo.ReadJetTrackTree(JetTree,"FatJetInfo");
  }

  if (usePrunedSubjets_) {
    SubJetInfo.ReadTree(JetTree,"FatJetInfo","Pruned");
    SubJets.ReadTree(JetTree,"PrunedSubJetInfo") ;
    SubJets.ReadSubJetSpecificTree(JetTree,"PrunedSubJetInfo") ;
    SubJets.ReadCSVTagVarTree(JetTree, "PrunedSubJetInfo");
    SubJets.ReadJetSVTree(JetTree, "PrunedSubJetInfo"); 

    if (useJetProbaTree_) {
      SubJetInfo.ReadTree(JetTree,"FatJetInfo","Pruned");
      SubJets.ReadJetTrackTree(JetTree,"PrunedSubJetInfo");
    }
  }
  else if (useSoftDropSubjets_) {
    SubJetInfo.ReadTree(JetTree,"FatJetInfo","SoftDrop");
    SubJets.ReadTree(JetTree,"SoftDropSubJetInfo") ;
    SubJets.ReadSubJetSpecificTree(JetTree,"SoftDropSubJetInfo") ;
    SubJets.ReadCSVTagVarTree(JetTree, "SoftDropSubJetInfo");
    SubJets.ReadJetSVTree(JetTree, "SoftDropSubJetInfo"); 

    if (useJetProbaTree_) {
      SubJetInfo.ReadTree(JetTree,"FatJetInfo","SoftDrop");
      SubJets.ReadJetTrackTree(JetTree,"SoftDropSubJetInfo");
    }
  }
  else edm::LogInfo("Error") << ">>>> No subjet type specified\n" ;

  double PtMax = 5000.;

  h1_CutFlow        = fs->make<TH1D>("h1_CutFlow",       "h1_CutFlow",        4,-0.5,3.5);
  h1_CutFlow->Sumw2();
  h1_CutFlow->SetDefaultSumw2(kTRUE); 
  h1_CutFlow_unw    = fs->make<TH1D>("h1_CutFlow_unw",   "h1_CutFlow_unw",    4,-0.5,3.5);
  h1_nPUtrue_mc     = fs->make<TH1D>("h1_nPUtrue_mc",    ";N(true PU in MC);;",     60,0.,60.);
  h1_nPUtrue_mc_unw = fs->make<TH1D>("h1_nPUtrue_mc_unw",";N(true PU in MC, unweighted);;", 60,0.,60.);
  h1_nPV_data       = fs->make<TH1D>("h1_nPV_data",      ";N(PV in data);;",       60,0.,60.);
  h1_nPV_mc         = fs->make<TH1D>("h1_nPV_mc",        ";N(PV in MC);;",         60,0.,60.);
  h1_nPV_mc_unw     = fs->make<TH1D>("h1_nPV_mc_unw",    ";N(PV in MC, unweighted)",     60,0.,60.);
  h1_pt_hat         = fs->make<TH1D>("h1_pt_hat",        ";#hat{p}_{T} before selection;;",         1400,0,7000);
  h1_pt_hat_sel     = fs->make<TH1D>("h1_pt_hat_sel",    ";#hat{p}_{T} after selection;;",         1400,0,7000);

  h1_nFatJet        = fs->make<TH1D>("h1_nFatJet",       ";N(AK8 jets);;",     100,0,100);
  h1_fatjet_pt      = fs->make<TH1D>("h1_fatjet_pt",     ";p_{T} (AK8 jets) [GeV];;",   PtMax/10,0,PtMax);

  if( usePrunedSubjets_ ) {
    h1_nSubJet        = fs->make<TH1D>("h1_nPrunedSubJet",       ";N(pruned subjets);;",     100,0,100);
    h1_subjet_pt      = fs->make<TH1D>("h1_PrunedSubjet_pt",     ";p_{T} (pruned subjets) [GeV]",   PtMax/10,0,PtMax);
  }
  else if( useSoftDropSubjets_ ) {
    h1_nSubJet        = fs->make<TH1D>("h1_nSoftDropSubJet",       ";N(soft drop subjets);;",     100,0,100);
    h1_subjet_pt      = fs->make<TH1D>("h1_SoftDropSubjet_pt",     "p_{T} (soft drop subjets) [GeV]",   PtMax/10,0,PtMax);
  }

  //// Common histograms for both fat jets and subjets
  ////DM>>>>ForNow>>>>createJetHistos("FatJet");
  if( usePrunedSubjets_ ) createJetHistos("PrunedSubJet");
  else if( useSoftDropSubjets_ ) createJetHistos("SoftDropSubJet");

}

void BTagValidation::createJetHistos(const TString& histoTag) {

  double PtMax(5000.) ;
  double pi(TMath::Pi());

  AddHisto(histoTag+"_pt_all"           ,";p_{T}(all jets) [GeV];;"             ,PtMax/10  ,0      ,PtMax );
  AddHisto(histoTag+"_eta"              ,";#eta(all jets);;"              ,50        ,-2.5   ,2.5);
  AddHisto(histoTag+"_phi"              ,";#phi(all jets);;"              ,40        ,-1.*pi ,pi);
  AddHisto(histoTag+"_mass"             ,";M(all jets) [GeV];;"              ,200       ,0      ,400);

  AddHisto(histoTag+"_track_IPs"        ,";3D IP significance of all tracks;;",      200,-50.,50.);
  AddHisto(histoTag+"_track_IPs1tr"     ,";3D IP significance of the first track;;", 200,-50.,50.);
  AddHisto(histoTag+"_track_IPs2tr"     ,";3D IP significance of the second track;;",200,-50.,50.);
  AddHisto(histoTag+"_track_IPs3tr"     ,";3D IP significance of the third track;;", 200,-50.,50.);

  AddHisto(histoTag+"_JP"      ,";JP;;",50,0.,2.5);
  AddHisto(histoTag+"_CSVIVFv2",";CSVIVFv2;;",50,0.,1.);
  AddHisto(histoTag+"_cMVAv2"  ,";cMVAv2;;",50,0.,1.);
  AddHisto(histoTag+"_DoubleB" ,";DoubleB;;",100,-1,1.);

  AddHisto(histoTag+"_JP_all_pt0", ";JP_all_pt0;;", 50, 0., 2.5);
  AddHisto(histoTag+"_JP_all_pt1", ";JP_all_pt1;;", 50, 0., 2.5);
  AddHisto(histoTag+"_JP_all_pt2", ";JP_all_pt2;;", 50, 0., 2.5);
  AddHisto(histoTag+"_JP_all_pt3", ";JP_all_pt3;;", 50, 0., 2.5);

  AddHisto(histoTag+"_JP_CSVv2Lpass_pt0", "JP_CSVv2Lpass_pt0", 50, 0., 2.5);
  AddHisto(histoTag+"_JP_CSVv2Lfail_pt0", "JP_CSVv2Lfail_pt0", 50, 0., 2.5);
                                                            
  AddHisto(histoTag+"_JP_CSVv2Lpass_pt1", "JP_CSVv2Lpass_pt1", 50, 0., 2.5);
  AddHisto(histoTag+"_JP_CSVv2Lfail_pt1", "JP_CSVv2Lfail_pt1", 50, 0., 2.5);
                                                            
  AddHisto(histoTag+"_JP_CSVv2Lpass_pt2", "JP_CSVv2Lpass_pt2", 50, 0., 2.5);
  AddHisto(histoTag+"_JP_CSVv2Lfail_pt2", "JP_CSVv2Lfail_pt2", 50, 0., 2.5);
                                                            
  AddHisto(histoTag+"_JP_CSVv2Lpass_pt3", "JP_CSVv2Lpass_pt3", 50, 0., 2.5);
  AddHisto(histoTag+"_JP_CSVv2Lfail_pt3", "JP_CSVv2Lfail_pt3", 50, 0., 2.5);
                                                            
  AddHisto(histoTag+"_JP_CSVv2Mpass_pt0", "JP_CSVv2Lpass_pt0", 50, 0., 2.5);
  AddHisto(histoTag+"_JP_CSVv2Mfail_pt0", "JP_CSVv2Lfail_pt0", 50, 0., 2.5);
                              
  AddHisto(histoTag+"_JP_CSVv2Mpass_pt1", "JP_CSVv2Lpass_pt1", 50, 0., 2.5);
  AddHisto(histoTag+"_JP_CSVv2Mfail_pt1", "JP_CSVv2Lfail_pt1", 50, 0., 2.5);
                             
  AddHisto(histoTag+"_JP_CSVv2Mpass_pt2", "JP_CSVv2Lpass_pt2", 50, 0., 2.5);
  AddHisto(histoTag+"_JP_CSVv2Mfail_pt2", "JP_CSVv2Lfail_pt2", 50, 0., 2.5);
                            
  AddHisto(histoTag+"_JP_CSVv2Mpass_pt3", "JP_CSVv2Lpass_pt3", 50, 0., 2.5);
  AddHisto(histoTag+"_JP_CSVv2Mfail_pt3", "JP_CSVv2Lfail_pt3", 50, 0., 2.5);

  AddHisto(histoTag+"_JP_CMVAv2Lpass_pt0", "JP_CMVAv2Lpass_pt0", 50., 0., 2.5);
  AddHisto(histoTag+"_JP_CMVAv2Lfail_pt0", "JP_CMVAv2Lfail_pt0", 50., 0., 2.5);
                                                              
  AddHisto(histoTag+"_JP_CMVAv2Lpass_pt1", "JP_CMVAv2Lpass_pt1", 50., 0., 2.5);
  AddHisto(histoTag+"_JP_CMVAv2Lfail_pt1", "JP_CMVAv2Lfail_pt1", 50., 0., 2.5);
                                                              
  AddHisto(histoTag+"_JP_CMVAv2Lpass_pt2", "JP_CMVAv2Lpass_pt2", 50., 0., 2.5);
  AddHisto(histoTag+"_JP_CMVAv2Lfail_pt2", "JP_CMVAv2Lfail_pt2", 50., 0., 2.5);
                                                              
  AddHisto(histoTag+"_JP_CMVAv2Lpass_pt3", "JP_CMVAv2Lpass_pt3", 50., 0., 2.5);
  AddHisto(histoTag+"_JP_CMVAv2Lfail_pt3", "JP_CMVAv2Lfail_pt3", 50., 0., 2.5);
                                                              
  AddHisto(histoTag+"_JP_CMVAv2Mpass_pt0", "JP_CMVAv2Lpass_pt0", 50., 0., 2.5);
  AddHisto(histoTag+"_JP_CMVAv2Mfail_pt0", "JP_CMVAv2Lfail_pt0", 50., 0., 2.5);
                               
  AddHisto(histoTag+"_JP_CMVAv2Mpass_pt1", "JP_CMVAv2Lpass_pt1", 50., 0., 2.5);
  AddHisto(histoTag+"_JP_CMVAv2Mfail_pt1", "JP_CMVAv2Lfail_pt1", 50., 0., 2.5);
                              
  AddHisto(histoTag+"_JP_CMVAv2Mpass_pt2", "JP_CMVAv2Lpass_pt2", 50., 0., 2.5);
  AddHisto(histoTag+"_JP_CMVAv2Mfail_pt2", "JP_CMVAv2Lfail_pt2", 50., 0., 2.5);
                             
  AddHisto(histoTag+"_JP_CMVAv2Mpass_pt3", "JP_CMVAv2Lpass_pt3", 50., 0., 2.5);
  AddHisto(histoTag+"_JP_CMVAv2Mfail_pt3", "JP_CMVAv2Lfail_pt3", 50., 0., 2.5);

  ////DM>>>>ForNow>>>>AddHisto(histoTag+"_JP_DoubleBLpass_pt0", "JP_DoubleBLpass_pt0", 50, 0., 2.5);
  ////DM>>>>ForNow>>>>AddHisto(histoTag+"_JP_DoubleBLfail_pt0", "JP_DoubleBLfail_pt0", 50, 0., 2.5);
  ////DM>>>>ForNow>>>>                                                              
  ////DM>>>>ForNow>>>>AddHisto(histoTag+"_JP_DoubleBLpass_pt1", "JP_DoubleBLpass_pt1", 50, 0., 2.5);
  ////DM>>>>ForNow>>>>AddHisto(histoTag+"_JP_DoubleBLfail_pt1", "JP_DoubleBLfail_pt1", 50, 0., 2.5);
  ////DM>>>>ForNow>>>>                                                              
  ////DM>>>>ForNow>>>>AddHisto(histoTag+"_JP_DoubleBLpass_pt2", "JP_DoubleBLpass_pt2", 50, 0., 2.5);
  ////DM>>>>ForNow>>>>AddHisto(histoTag+"_JP_DoubleBLfail_pt2", "JP_DoubleBLfail_pt2", 50, 0., 2.5);
  ////DM>>>>ForNow>>>>                                                              
  ////DM>>>>ForNow>>>>AddHisto(histoTag+"_JP_DoubleBLpass_pt3", "JP_DoubleBLpass_pt3", 50, 0., 2.5);
  ////DM>>>>ForNow>>>>AddHisto(histoTag+"_JP_DoubleBLfail_pt3", "JP_DoubleBLfail_pt3", 50, 0., 2.5);
  ////DM>>>>ForNow>>>>                                                              
  ////DM>>>>ForNow>>>>AddHisto(histoTag+"_JP_DoubleBLpass_pt0", "JP_DoubleBLpass_pt0", 50, 0., 2.5);
  ////DM>>>>ForNow>>>>AddHisto(histoTag+"_JP_DoubleBLfail_pt0", "JP_DoubleBLfail_pt0", 50, 0., 2.5);
  ////DM>>>>ForNow>>>>                                                              
  ////DM>>>>ForNow>>>>AddHisto(histoTag+"_JP_DoubleBLpass_pt1", "JP_DoubleBLpass_pt1", 50, 0., 2.5);
  ////DM>>>>ForNow>>>>AddHisto(histoTag+"_JP_DoubleBLfail_pt1", "JP_DoubleBLfail_pt1", 50, 0., 2.5);
  ////DM>>>>ForNow>>>>                                                              
  ////DM>>>>ForNow>>>>AddHisto(histoTag+"_JP_DoubleBLpass_pt2", "JP_DoubleBLpass_pt2", 50, 0., 2.5);
  ////DM>>>>ForNow>>>>AddHisto(histoTag+"_JP_DoubleBLfail_pt2", "JP_DoubleBLfail_pt2", 50, 0., 2.5);
  ////DM>>>>ForNow>>>>                                                              
  ////DM>>>>ForNow>>>>AddHisto(histoTag+"_JP_DoubleBLpass_pt3", "JP_DoubleBLpass_pt3", 50, 0., 2.5);
  ////DM>>>>ForNow>>>>AddHisto(histoTag+"_JP_DoubleBLfail_pt3", "JP_DoubleBLfail_pt3", 50, 0., 2.5);

}

// ------------ method called for each event  ------------
void BTagValidation::analyze(const edm::Event& iEvent, const edm::EventSetup& iSetup) {

  using namespace edm;

  if(JetTree == 0 && JetTreeEvtInfo == 0) return;

  Long64_t nEntries = JetTree->GetEntries();
  if(maxEvents_>=0) nEntries = maxEvents_;

  //---------------------------- Start event loop ---------------------------------------//
  for(Long64_t iEntry = 0; iEntry < nEntries; ++iEntry) {
    JetTreeEvtInfo->GetEntry(iEntry);

    JetTree->GetEntry(iEntry);

    int run = EvtInfo.Run ; 
    int lumi = EvtInfo.LumiBlock ; 
    if((iEntry%reportEvery_) == 0) edm::LogInfo("EventNumber") << ">>>>> Processing event with run no. " 
      << run << " and lumisection " << lumi << iEntry << " of " << nEntries;

    if(run < 0) {
      isData = false;
      if ( iEntry == 0) edm::LogInfo("IsMC") << ">>>>> Running on simulation\n" ;
    }
    else if( iEntry == 0 ) edm::LogInfo("IsData") << ">>>>> Running on data\n" ;
    double wtPU = 1.;
    if ( doPUReweightingOfficial_ && !isData ) wtPU *= LumiWeights_.weight(EvtInfo.nPUtrue);
    else if ( doPUReweightingNPV_ && !isData ) wtPU *= GetLumiWeightsPVBased(file_PVWt_, hist_PVWt_, EvtInfo.nPV) ;  
    h1_CutFlow->Fill(2.,wtPU); //// count all events
    h1_CutFlow_unw->Fill(2.);

    if( !isData ) h1_pt_hat->Fill(EvtInfo.pthat,wtPU);

    if( !passTrigger() ) continue; //// apply trigger selection

    h1_CutFlow->Fill(3.,wtPU); //// count events passing trigger selection
    h1_CutFlow_unw->Fill(3.);

    //// pileup distributions
    if( isData ) h1_nPV_data->Fill(EvtInfo.nPV);
    else {
      h1_nPUtrue_mc    ->Fill(EvtInfo.nPUtrue,wtPU);
      h1_nPUtrue_mc_unw->Fill(EvtInfo.nPUtrue);
      h1_nPV_mc        ->Fill(EvtInfo.nPV,wtPU);
      h1_nPV_mc_unw    ->Fill(EvtInfo.nPV);
    }

    if(FatJetInfo.nJet <= 0) continue; //// require at least 1 fat jet in the event

    int nFatJet = 0;
    int nSubJet = 0;

    //---------------------------- Start fat jet loop ---------------------------------------//
    for(int iJet = 0; iJet < FatJetInfo.nJet; ++iJet) {
      if ( FatJetInfo.Jet_pt[iJet] < fatJetPtMin_ ||
          FatJetInfo.Jet_pt[iJet] > fatJetPtMax_ )             continue; //// apply jet pT cut

      if ( fabs(FatJetInfo.Jet_eta[iJet]) > fatJetAbsEtaMax_ ) continue; //// apply jet eta cut

      if ( FatJetInfo.Jet_looseID[iJet]==0 )                   continue; //// apply loose jet ID

      if (usePrunedSubjets_) {
        if ( FatJetInfo.Jet_massPruned[iJet] < fatJetGroomedMassMin_ ||
            FatJetInfo.Jet_massPruned[iJet] > fatJetGroomedMassMax_ )  continue; //// apply pruned jet mass cut
      }
      else if (useSoftDropSubjets_) {
        if ( FatJetInfo.Jet_massSoftDrop[iJet] < fatJetGroomedMassMin_ ||
            FatJetInfo.Jet_massSoftDrop[iJet] > fatJetGroomedMassMax_ )  continue; //// apply softdrop jet mass cut
      }

      float tau1 (FatJetInfo.Jet_tau1[iJet]);
      float tau2 (FatJetInfo.Jet_tau2[iJet]);
      float tau21(tau1 != 0 ? tau2/tau1 : 0.);
      if ( tau21 > fatJetTau21Max_ ||tau21 < fatJetTau21Min_ ) continue ; 

      if ( SubJetInfo.Jet_nSubJets[iJet] != 2 ) continue ;

      int iSubJet1 = SubJetInfo.SubJetIdx[SubJetInfo.Jet_nFirstSJ[iJet]] ; 
      int iSubJet2 = SubJetInfo.SubJetIdx[SubJetInfo.Jet_nFirstSJ[iJet]+1] ;

      //// If  processing subjets, discard fat jet with any one subjet having pt = 0
      if( (usePrunedSubjets_ || useSoftDropSubjets_)
          && (SubJets.Jet_pt[iSubJet1]==0. || SubJets.Jet_pt[iSubJet2]==0.) ) continue;

      TLorentzVector jet_p4, subjet1_p4, subjet2_p4;
      jet_p4.SetPtEtaPhiM(FatJetInfo.Jet_pt[iJet], FatJetInfo.Jet_eta[iJet], FatJetInfo.Jet_phi[iJet], FatJetInfo.Jet_mass[iJet]);
      subjet1_p4.SetPtEtaPhiM(SubJets.Jet_pt[iSubJet1], SubJets.Jet_eta[iSubJet1], SubJets.Jet_phi[iSubJet1], SubJets.Jet_mass[iSubJet1]);
      subjet2_p4.SetPtEtaPhiM(SubJets.Jet_pt[iSubJet2], SubJets.Jet_eta[iSubJet2], SubJets.Jet_phi[iSubJet2], SubJets.Jet_mass[iSubJet2]);

      //// If processing subjets, skip infrared unsafe configurations
      double subjet_dR(subjet1_p4.DeltaR(subjet2_p4)) ;
      if( (usePrunedSubjets_ || useSoftDropSubjets_)
          && subjet_dR < (FatJetInfo.Jet_mass[iJet]/FatJetInfo.Jet_pt[iJet]) ) continue;

      int idxFirstMuon(-1), nselmuon(0), nmu(0) ;
      if (FatJetInfo.nPFMuon>0) {
        for (int iMu=0; iMu<FatJetInfo.nPFMuon; ++iMu) {
          if (FatJetInfo.PFMuon_IdxJet[iMu]==iJet ) {
            ++nmu;
            if (passMuonSelection(iMu, FatJetInfo, iJet)) {
              if(nselmuon == 0) idxFirstMuon = iMu;
              ++nselmuon;
            }
          }
        }
      }

      bool isDoubleMuonTagged(false);
      int idxMuon_inFirstSubjet(-1); //1st Muon tagged (in double muon tagged fatjets) - //added by rizki
      int idxMuon_inSecondSubjet(-1); //2nd Muon tagged (in double muon tagged fatjets) - //added by rizki

      if ( fatJetDoubleTagging_ && SubJets.nPFMuon>0) {
        //// Collect all muons matched to the two subjets
        std::vector<int> selectedMuonIdx1, selectedMuonIdx2;
        for (int iMu=0; iMu<SubJets.nPFMuon; ++iMu) {
          if ( SubJets.PFMuon_IdxJet[iMu]==iSubJet1 ) {
            if (passMuonSelection(iMu, SubJets, iSubJet1, (dynamicMuonSubJetDR_ ? subjet_dR/2 : 0.4 )))
              selectedMuonIdx1.push_back(iMu);
          }
          if ( SubJets.PFMuon_IdxJet[iMu]==iSubJet2 ) {
            if (passMuonSelection(iMu, SubJets, iSubJet2, (dynamicMuonSubJetDR_ ? subjet_dR/2 : 0.4 )))
              selectedMuonIdx2.push_back(iMu);
          }

        }

        //// Check that there are at least two distinct muons matched to the two subjets
        for(unsigned int iMu1=0; iMu1<selectedMuonIdx1.size(); ++iMu1) {
          for(unsigned int iMu2=0; iMu2<selectedMuonIdx2.size(); ++iMu2) {
            if( fabs( SubJets.PFMuon_eta[selectedMuonIdx1.at(iMu1)] - SubJets.PFMuon_eta[selectedMuonIdx2.at(iMu2)] ) > 1.E-03 &&
                fabs( SubJets.PFMuon_phi[selectedMuonIdx1.at(iMu1)] - SubJets.PFMuon_phi[selectedMuonIdx2.at(iMu2)] ) > 1.E-03 &&
                fabs( SubJets.PFMuon_pt[selectedMuonIdx1.at(iMu1)] - SubJets.PFMuon_pt[selectedMuonIdx2.at(iMu2)] ) > 1.E-03 ) {
              isDoubleMuonTagged = true;
              break;
            }
          }
          if( isDoubleMuonTagged ) break;
        }

        if(selectedMuonIdx1.size()>0) idxMuon_inFirstSubjet =  selectedMuonIdx1.at(0); //warning this might not be correct if mu not ordered in pT! // added by rizki
        if(selectedMuonIdx2.size()>0)idxMuon_inSecondSubjet = selectedMuonIdx2.at(0); //warning this might not be correct if mu not ordered in pT! // added by rizki

      }

      if( applyFatJetMuonTagging_ ) { //// if enabled, select muon-tagged fat jets
        if( fatJetDoubleTagging_ && !isDoubleMuonTagged ) continue;
        else if( !fatJetDoubleTagging_ && nselmuon==0)    continue;
      }

      if( applyFatJetBTagging_ ) //// if enabled, select b-tagged fat jets
      {
        if( fatJetDoubleBTagging_ && 
            !( SubJets.Jet_CombIVF[iSubJet1]>subJetBDiscrMin_ && SubJets.Jet_CombIVF[iSubJet1]<subJetBDiscrMax_ 
              && SubJets.Jet_CombIVF[iSubJet2]>subJetBDiscrMin_ && SubJets.Jet_CombIVF[iSubJet2]<subJetBDiscrMax_ ) 
          ) continue;
        else if( !fatJetDoubleBTagging_ && FatJetInfo.Jet_CombIVF[iJet]<=fatJetBDiscrCut_ ) continue;
      }

      if (fatJetDoubleSVBTagging_ && 
          (FatJetInfo.Jet_DoubleSV[iJet] < fatJetDoubleSVBDiscrMin_ || FatJetInfo.Jet_DoubleSV[iJet] > fatJetDoubleSVBDiscrMax_) 
         ) continue ;  

      //// apply b-tagging scale factors
      double wtFatJet = 1.;
      if( applySFs_ && !isData ) {
        if( applyFatJetBTagging_ && fatJetDoubleBTagging_ ) {
          wtFatJet *= ( scaleFactor(SubJets.Jet_flavour[iSubJet1], SubJets.Jet_pt[iSubJet1], SubJets.Jet_eta[iSubJet1], (subJetBDiscrMin_>0.25)) *
              scaleFactor(SubJets.Jet_flavour[iSubJet2], SubJets.Jet_pt[iSubJet2], SubJets.Jet_eta[iSubJet2], (subJetBDiscrMin_>0.25)) );
        }
        else if( applyFatJetBTagging_ && !fatJetDoubleBTagging_ )
          wtFatJet *= scaleFactor(FatJetInfo.Jet_flavour[iJet], FatJetInfo.Jet_pt[iJet], FatJetInfo.Jet_eta[iJet], (fatJetBDiscrCut_>0.25));
      }
      
      double wtFatJetPt = 1.;
      if (doFatJetPtReweighting_ && !isData) {
        wtFatJetPt *= GetLumiWeightsJetPtBased(file_FatJetPtWt_, hist_FatJetPtWt_, FatJetInfo.Jet_pt[iJet]) ;
        wtFatJet *= wtFatJetPt ;
      }

      //// fat jet multiplicity
      ++nFatJet;

      //// test if the jet is a gluon splitting b jet
      bool isGSPbb(false);
      if ( FatJetInfo.Jet_nbHadrons[iJet] > 1 ) isGSPbb = true ;

      //// test if the jet is a gluon splitting c jet
      bool isGSPcc(false);
      if ( FatJetInfo.Jet_ncHadrons[iJet] > 1 ) isGSPcc = true ;

      //// Fill fat jet histograms

      ////DM>>>>ForNow>>>>fillJetHistos(FatJetInfo, iJet, isGSPbb, isGSPcc ,"FatJet", nmu, nselmuon, idxFirstMuon, wtPU*wtFatJet);

      //// Start process subjets 
      if( usePrunedSubjets_ || useSoftDropSubjets_ ) {

        for(int sj=0; sj<2; ++sj) {
          int iSubJet = SubJetInfo.Jet_nFirstSJ[iJet];
          if( sj==1 ) iSubJet = SubJetInfo.Jet_nLastSJ[iJet];

          int idxFirstMuonSubJet = -1;
          int nselmuonSubJet = 0;
          int nmuSubJet = 0;

          if (SubJets.nPFMuon>0) {
            for (int iMu=0; iMu<SubJets.nPFMuon; ++iMu) {
              if (SubJets.PFMuon_IdxJet[iMu]==iSubJet ) {
                ++nmuSubJet;
                if (passMuonSelection(iMu, SubJets, iSubJet, (dynamicMuonSubJetDR_ ? subjet_dR/2 : 0.4 ))) {
                  if(nselmuonSubJet == 0) idxFirstMuonSubJet = iMu;
                  ++nselmuonSubJet;
                }
              }
            }
          }

          if(applySubJetMuonTagging_ && nselmuonSubJet==0) continue;  //// if enabled, select muon-tagged subjets
          if(applySubJetBTagging_ && 
              (SubJets.Jet_CombIVF[iSubJet]<=subJetBDiscrMin_ || SubJets.Jet_CombIVF[iSubJet]>subJetBDiscrMax_) 
            ) continue;  //// if enabled, select b-tagged subjets

          //// apply b-tagging scale factors
          double wtSubJet = 1.;
          if( applySFs_ && !isData ) {
            if( applyFatJetBTagging_ && fatJetDoubleBTagging_ ) wtSubJet *= wtFatJet;
            else wtSubJet *= scaleFactor(SubJets.Jet_flavour[iSubJet], SubJets.Jet_pt[iSubJet], SubJets.Jet_eta[iSubJet], (subJetBDiscrMin_>0.25));
          }

          double wtSubJetPt = 1.;
          if (doSubJetPtReweighting_ && !isData) {
            wtSubJetPt *= GetLumiWeightsJetPtBased(file_SubJetPtWt_, hist_SubJetPtWt_, SubJets.Jet_pt[iSubJet]) ;
            wtSubJet *= wtSubJetPt ;
          }

          //// subjet multiplicity
          ++nSubJet;

          //// fill subjet histograms
          h1_subjet_pt->Fill(SubJets.Jet_pt[iSubJet],wtPU*wtSubJet);

          std::string sjlabel ;
          if (usePrunedSubjets_) sjlabel = "PrunedSubJet" ;
          else if (useSoftDropSubjets_) sjlabel = "SoftDropSubJet" ;
          fillJetHistos(SubJets, iSubJet, false, false ,sjlabel, nmuSubJet, nselmuonSubJet, idxFirstMuonSubJet, wtPU*wtSubJet);

        } //// End subjet loop 
      } //// End process subjet

    } //// End fat jet loop 

    //// Fill jet multiplicity
    h1_nFatJet->Fill(nFatJet, wtPU);
    if( usePrunedSubjets_ || useSoftDropSubjets_ ) h1_nSubJet->Fill(nSubJet, wtPU);

    if( !isData && nFatJet>0 ) h1_pt_hat_sel->Fill(EvtInfo.pthat,wtPU);

  }
  //----------------------------- End event loop ----------------------------------------//
}

// ------------------------------------------------------------------------------
void BTagValidation::fillJetHistos(const JetInfoBranches& JetInfo, const int iJet, const bool isGSPbb, const bool isGSPcc, const TString& histoTag, const int nmu, const int nselmuon, const int idxFirstMuon, const double wt) {

  float ptjet      = JetInfo.Jet_pt[iJet];
  float etajet     = JetInfo.Jet_eta[iJet];
  float phijet     = JetInfo.Jet_phi[iJet];
  float mass       = JetInfo.Jet_mass[iJet];
  float ntrkjet    = JetInfo.Jet_ntracks[iJet];
  int   flav       = JetInfo.Jet_flavour[iJet];

  FillHisto(histoTag+"_pt_all", flav, isGSPbb , isGSPcc, ptjet , wt) ;

  FillHisto(histoTag+"_eta"         ,flav ,isGSPbb , isGSPcc ,etajet     ,wt) ;
  FillHisto(histoTag+"_phi"         ,flav ,isGSPbb , isGSPcc ,phijet     ,wt) ;
  FillHisto(histoTag+"_mass"        ,flav ,isGSPbb , isGSPcc ,mass       ,wt) ;

  int   n1_ip     = -1;
  int   n2_ip     = -1;
  int   n3_ip     = -1;
  float sig1_ip   = -9999;
  float sig2_ip   = -9999;
  float sig3_ip   = -9999;
  float sig12D_ip = -9999;
  float sig22D_ip = -9999;
  float sig32D_ip = -9999;

  int ntracksel   = 0;

  if ( useJetProbaTree_ ) {
    //// Start tracks loop
    for (int iTrk=JetInfo.Jet_nFirstTrack[iJet]; iTrk<JetInfo.Jet_nLastTrack[iJet] ; ++iTrk) {
      //// Track information
      bool passNhit=false;
      bool passPix= false;
      bool passIPz=false;
      bool passPt=false;
      bool passnormchi2=false;
      bool passtrkdist=false;
      bool passtrklen=false;
      bool passTrackIP2D=false;

      if (JetInfo.Track_nHitAll[iTrk]>=8)      passNhit=true;
      if (JetInfo.Track_nHitPixel[iTrk]>=2)    passPix= true;
      if (fabs(JetInfo.Track_dz[iTrk])<17)     passIPz=true;
      if (JetInfo.Track_pt[iTrk]>1)            passPt=true;
      if (JetInfo.Track_chi2[iTrk]<5)          passnormchi2=true;
      if (fabs(JetInfo.Track_dist[iTrk])<0.07) passtrkdist=true;
      if (JetInfo.Track_length[iTrk]<5)        passtrklen=true;
      if (fabs(JetInfo.Track_IP2D[iTrk])<0.2)  passTrackIP2D=true;

      // Start selected tracks 
      if (passNhit && passPix && passIPz && passPt && passnormchi2 && passtrkdist && passtrklen && passTrackIP2D) {
        ++ntracksel;

        FillHisto(histoTag+"_track_IPs",     flav, isGSPbb , isGSPcc ,JetInfo.Track_IPsig[iTrk]     ,wt);

        // tracks sorted by IP
        float sig   = JetInfo.Track_IP[iTrk]/JetInfo.Track_IPerr[iTrk];
        float sig2D = JetInfo.Track_IP2D[iTrk]/JetInfo.Track_IP2Derr[iTrk];
        if (sig>sig1_ip) {
          sig3_ip   = sig2_ip;
          sig2_ip   = sig1_ip;
          sig1_ip   = sig;
          sig32D_ip = sig22D_ip;
          sig22D_ip = sig12D_ip;
          sig12D_ip = sig2D;
          n3_ip     = n2_ip;
          n2_ip     = n1_ip;
          n1_ip     = iTrk;
        }
        else if (sig>sig2_ip) {
          sig3_ip   = sig2_ip;
          sig2_ip   = sig;
          sig32D_ip = sig22D_ip;
          sig22D_ip = sig2D;
          n3_ip     = n2_ip;
          n2_ip     = iTrk;
        }
        else if (sig>sig3_ip) {
          sig3_ip   = sig;
          sig32D_ip = sig2D;
          n3_ip     = iTrk;
        }
      }
      //// End selected tracks 
    }
    //// End tracks loop 

    if (n1_ip>-1) FillHisto(histoTag+"_track_IPs1tr",    flav, isGSPbb , isGSPcc ,sig1_ip                          , wt) ;

    if (n2_ip>-1) FillHisto(histoTag+"_track_IPs2tr",    flav, isGSPbb , isGSPcc ,sig2_ip                          , wt) ;

    if (n3_ip>-1) FillHisto(histoTag+"_track_IPs3tr",    flav, isGSPbb , isGSPcc ,sig3_ip                          , wt) ;

  } //// end useJetProbaTree

  //// Tagger information 
  float jetproba  = JetInfo.Jet_Proba[iJet];
  float csvivfv2  = JetInfo.Jet_CombIVF[iJet];
  float cmvav2    = JetInfo.Jet_cMVAv2[iJet];
  float doubleb   = JetInfo.Jet_DoubleSV[iJet];

  FillHisto(histoTag+"_CSVIVFv2", flav, isGSPbb, isGSPcc ,csvivfv2  ,wt);
  FillHisto(histoTag+"_cMVAv2",   flav, isGSPbb, isGSPcc ,cmvav2    ,wt);
  FillHisto(histoTag+"_DoubleB",  flav, isGSPbb, isGSPcc ,doubleb   ,wt);

  if (ptjet > 2000.) ptjet = 2000. ; 

  if ( ptjet > ptbinsLow_[0] && ptjet <= ptbinsHigh_[0] ) FillHisto(histoTag+"_JP_all_pt0", flav, isGSPbb, isGSPcc ,jetproba  ,wt); 
  else if ( ptjet > ptbinsLow_[1] && ptjet <= ptbinsHigh_[1] ) FillHisto(histoTag+"_JP_all_pt1", flav, isGSPbb, isGSPcc ,jetproba  ,wt); 
  else if ( ptjet > ptbinsLow_[2] && ptjet <= ptbinsHigh_[2] ) FillHisto(histoTag+"_JP_all_pt2", flav, isGSPbb, isGSPcc ,jetproba  ,wt); 
  else if ( ptjet > ptbinsLow_[3] && ptjet <= ptbinsHigh_[3] ) FillHisto(histoTag+"_JP_all_pt3", flav, isGSPbb, isGSPcc ,jetproba  ,wt); 

  if ( csvivfv2 >= CSVv2L_  ) {
    if ( ptjet > ptbinsLow_[0] && ptjet <= ptbinsHigh_[0] ) FillHisto(histoTag+"_JP_CSVv2Lpass_pt0", flav, isGSPbb, isGSPcc ,jetproba  ,wt); 
    else if ( ptjet > ptbinsLow_[1] && ptjet <= ptbinsHigh_[1] ) FillHisto(histoTag+"_JP_CSVv2Lpass_pt1", flav, isGSPbb, isGSPcc ,jetproba  ,wt); 
    else if ( ptjet > ptbinsLow_[2] && ptjet <= ptbinsHigh_[2] ) FillHisto(histoTag+"_JP_CSVv2Lpass_pt2", flav, isGSPbb, isGSPcc ,jetproba  ,wt); 
    else if ( ptjet > ptbinsLow_[3] && ptjet <= ptbinsHigh_[3] ) FillHisto(histoTag+"_JP_CSVv2Lpass_pt3", flav, isGSPbb, isGSPcc ,jetproba  ,wt); 
  }
  else if ( csvivfv2 < CSVv2L_  ) {
    if ( ptjet > ptbinsLow_[0] && ptjet <= ptbinsHigh_[0] ) FillHisto(histoTag+"_JP_CSVv2Lfail_pt0", flav, isGSPbb, isGSPcc ,jetproba  ,wt); 
    else if ( ptjet > ptbinsLow_[1] && ptjet <= ptbinsHigh_[1] ) FillHisto(histoTag+"_JP_CSVv2Lfail_pt1", flav, isGSPbb, isGSPcc ,jetproba  ,wt); 
    else if ( ptjet > ptbinsLow_[2] && ptjet <= ptbinsHigh_[2] ) FillHisto(histoTag+"_JP_CSVv2Lfail_pt2", flav, isGSPbb, isGSPcc ,jetproba  ,wt); 
    else if ( ptjet > ptbinsLow_[3] && ptjet <= ptbinsHigh_[3] ) FillHisto(histoTag+"_JP_CSVv2Lfail_pt3", flav, isGSPbb, isGSPcc ,jetproba  ,wt); 
  }

  if ( csvivfv2 >= CSVv2M_  ) {
    if ( ptjet > ptbinsLow_[0] && ptjet <= ptbinsHigh_[0] ) FillHisto(histoTag+"_JP_CSVv2Mpass_pt0", flav, isGSPbb, isGSPcc ,jetproba  ,wt); 
    else if ( ptjet > ptbinsLow_[1] && ptjet <= ptbinsHigh_[1] ) FillHisto(histoTag+"_JP_CSVv2Mpass_pt1", flav, isGSPbb, isGSPcc ,jetproba  ,wt); 
    else if ( ptjet > ptbinsLow_[2] && ptjet <= ptbinsHigh_[2] ) FillHisto(histoTag+"_JP_CSVv2Mpass_pt2", flav, isGSPbb, isGSPcc ,jetproba  ,wt); 
    else if ( ptjet > ptbinsLow_[3] && ptjet <= ptbinsHigh_[3] ) FillHisto(histoTag+"_JP_CSVv2Mpass_pt3", flav, isGSPbb, isGSPcc ,jetproba  ,wt); 
  }
  else if ( csvivfv2 < CSVv2M_  ) {
    if ( ptjet > ptbinsLow_[0] && ptjet <= ptbinsHigh_[0] ) FillHisto(histoTag+"_JP_CSVv2Mfail_pt0", flav, isGSPbb, isGSPcc ,jetproba  ,wt); 
    else if ( ptjet > ptbinsLow_[1] && ptjet <= ptbinsHigh_[1] ) FillHisto(histoTag+"_JP_CSVv2Mfail_pt1", flav, isGSPbb, isGSPcc ,jetproba  ,wt); 
    else if ( ptjet > ptbinsLow_[2] && ptjet <= ptbinsHigh_[2] ) FillHisto(histoTag+"_JP_CSVv2Mfail_pt2", flav, isGSPbb, isGSPcc ,jetproba  ,wt); 
    else if ( ptjet > ptbinsLow_[3] && ptjet <= ptbinsHigh_[3] ) FillHisto(histoTag+"_JP_CSVv2Mfail_pt3", flav, isGSPbb, isGSPcc ,jetproba  ,wt); 
  }

  if ( csvivfv2 >= CMVAv2L_  ) {
    if ( ptjet > ptbinsLow_[0] && ptjet <= ptbinsHigh_[0] ) FillHisto(histoTag+"_JP_CMVAv2Lpass_pt0", flav, isGSPbb, isGSPcc ,jetproba  ,wt); 
    else if ( ptjet > ptbinsLow_[1] && ptjet <= ptbinsHigh_[1] ) FillHisto(histoTag+"_JP_CMVAv2Lpass_pt1", flav, isGSPbb, isGSPcc ,jetproba  ,wt); 
    else if ( ptjet > ptbinsLow_[2] && ptjet <= ptbinsHigh_[2] ) FillHisto(histoTag+"_JP_CMVAv2Lpass_pt2", flav, isGSPbb, isGSPcc ,jetproba  ,wt); 
    else if ( ptjet > ptbinsLow_[3] && ptjet <= ptbinsHigh_[3] ) FillHisto(histoTag+"_JP_CMVAv2Lpass_pt3", flav, isGSPbb, isGSPcc ,jetproba  ,wt); 
  }
  else if ( csvivfv2 < CMVAv2L_  ) {
    if ( ptjet > ptbinsLow_[0] && ptjet <= ptbinsHigh_[0] ) FillHisto(histoTag+"_JP_CMVAv2Lfail_pt0", flav, isGSPbb, isGSPcc ,jetproba  ,wt); 
    else if ( ptjet > ptbinsLow_[1] && ptjet <= ptbinsHigh_[1] ) FillHisto(histoTag+"_JP_CMVAv2Lfail_pt1", flav, isGSPbb, isGSPcc ,jetproba  ,wt); 
    else if ( ptjet > ptbinsLow_[2] && ptjet <= ptbinsHigh_[2] ) FillHisto(histoTag+"_JP_CMVAv2Lfail_pt2", flav, isGSPbb, isGSPcc ,jetproba  ,wt); 
    else if ( ptjet > ptbinsLow_[3] && ptjet <= ptbinsHigh_[3] ) FillHisto(histoTag+"_JP_CMVAv2Lfail_pt3", flav, isGSPbb, isGSPcc ,jetproba  ,wt); 
  }

  if ( csvivfv2 >= CMVAv2M_  ) {
    if ( ptjet > ptbinsLow_[0] && ptjet <= ptbinsHigh_[0] ) FillHisto(histoTag+"_JP_CMVAv2Mpass_pt0", flav, isGSPbb, isGSPcc ,jetproba  ,wt); 
    else if ( ptjet > ptbinsLow_[1] && ptjet <= ptbinsHigh_[1] ) FillHisto(histoTag+"_JP_CMVAv2Mpass_pt1", flav, isGSPbb, isGSPcc ,jetproba  ,wt); 
    else if ( ptjet > ptbinsLow_[2] && ptjet <= ptbinsHigh_[2] ) FillHisto(histoTag+"_JP_CMVAv2Mpass_pt2", flav, isGSPbb, isGSPcc ,jetproba  ,wt); 
    else if ( ptjet > ptbinsLow_[3] && ptjet <= ptbinsHigh_[3] ) FillHisto(histoTag+"_JP_CMVAv2Mpass_pt3", flav, isGSPbb, isGSPcc ,jetproba  ,wt); 
  }
  else if ( csvivfv2 < CMVAv2M_  ) {
    if ( ptjet > ptbinsLow_[0] && ptjet <= ptbinsHigh_[0] ) FillHisto(histoTag+"_JP_CMVAv2Mfail_pt0", flav, isGSPbb, isGSPcc ,jetproba  ,wt); 
    else if ( ptjet > ptbinsLow_[1] && ptjet <= ptbinsHigh_[1] ) FillHisto(histoTag+"_JP_CMVAv2Mfail_pt1", flav, isGSPbb, isGSPcc ,jetproba  ,wt); 
    else if ( ptjet > ptbinsLow_[2] && ptjet <= ptbinsHigh_[2] ) FillHisto(histoTag+"_JP_CMVAv2Mfail_pt2", flav, isGSPbb, isGSPcc ,jetproba  ,wt); 
    else if ( ptjet > ptbinsLow_[3] && ptjet <= ptbinsHigh_[3] ) FillHisto(histoTag+"_JP_CMVAv2Mfail_pt3", flav, isGSPbb, isGSPcc ,jetproba  ,wt); 
  }

  ////DM>>>For now>>>>if ( csvivfv2 >= DoubleBL_  ) {
  ////DM>>>For now>>>>  if ( ptjet > ptbinsLow_[0] && ptjet <= ptbinsHigh_[0] ) FillHisto(histoTag+"_JP_DoubleBLpass_pt0", flav, isGSPbb, isGSPcc ,jetproba  ,wt); 
  ////DM>>>For now>>>>  else if ( ptjet > ptbinsLow_[1] && ptjet <= ptbinsHigh_[1] ) FillHisto(histoTag+"_JP_DoubleBLpass_pt1", flav, isGSPbb, isGSPcc ,jetproba  ,wt); 
  ////DM>>>For now>>>>  else if ( ptjet > ptbinsLow_[2] && ptjet <= ptbinsHigh_[2] ) FillHisto(histoTag+"_JP_DoubleBLpass_pt2", flav, isGSPbb, isGSPcc ,jetproba  ,wt); 
  ////DM>>>For now>>>>  else if ( ptjet > ptbinsLow_[3] && ptjet <= ptbinsHigh_[3] ) FillHisto(histoTag+"_JP_DoubleBLpass_pt3", flav, isGSPbb, isGSPcc ,jetproba  ,wt); 
  ////DM>>>For now>>>>}
  ////DM>>>For now>>>>else if ( csvivfv2 < DoubleBL_  ) {
  ////DM>>>For now>>>>  if ( ptjet > ptbinsLow_[0] && ptjet <= ptbinsHigh_[0] ) FillHisto(histoTag+"_JP_DoubleBLfail_pt0", flav, isGSPbb, isGSPcc ,jetproba  ,wt); 
  ////DM>>>For now>>>>  else if ( ptjet > ptbinsLow_[1] && ptjet <= ptbinsHigh_[1] ) FillHisto(histoTag+"_JP_DoubleBLfail_pt1", flav, isGSPbb, isGSPcc ,jetproba  ,wt); 
  ////DM>>>For now>>>>  else if ( ptjet > ptbinsLow_[2] && ptjet <= ptbinsHigh_[2] ) FillHisto(histoTag+"_JP_DoubleBLfail_pt2", flav, isGSPbb, isGSPcc ,jetproba  ,wt); 
  ////DM>>>For now>>>>  else if ( ptjet > ptbinsLow_[3] && ptjet <= ptbinsHigh_[3] ) FillHisto(histoTag+"_JP_DoubleBLfail_pt3", flav, isGSPbb, isGSPcc ,jetproba  ,wt); 
  ////DM>>>For now>>>>}

  ////DM>>>For now>>>>if ( csvivfv2 >= DoubleBM_  ) {
  ////DM>>>For now>>>>  if ( ptjet > ptbinsLow_[0] && ptjet <= ptbinsHigh_[0] ) FillHisto(histoTag+"_JP_DoubleBMpass_pt0", flav, isGSPbb, isGSPcc ,jetproba  ,wt); 
  ////DM>>>For now>>>>  else if ( ptjet > ptbinsLow_[1] && ptjet <= ptbinsHigh_[1] ) FillHisto(histoTag+"_JP_DoubleBMpass_pt1", flav, isGSPbb, isGSPcc ,jetproba  ,wt); 
  ////DM>>>For now>>>>  else if ( ptjet > ptbinsLow_[2] && ptjet <= ptbinsHigh_[2] ) FillHisto(histoTag+"_JP_DoubleBMpass_pt2", flav, isGSPbb, isGSPcc ,jetproba  ,wt); 
  ////DM>>>For now>>>>  else if ( ptjet > ptbinsLow_[3] && ptjet <= ptbinsHigh_[3] ) FillHisto(histoTag+"_JP_DoubleBMpass_pt3", flav, isGSPbb, isGSPcc ,jetproba  ,wt); 
  ////DM>>>For now>>>>}
  ////DM>>>For now>>>>else if ( csvivfv2 < DoubleBM_  ) {
  ////DM>>>For now>>>>  if ( ptjet > ptbinsLow_[0] && ptjet <= ptbinsHigh_[0] ) FillHisto(histoTag+"_JP_DoubleBMfail_pt0", flav, isGSPbb, isGSPcc ,jetproba  ,wt); 
  ////DM>>>For now>>>>  else if ( ptjet > ptbinsLow_[1] && ptjet <= ptbinsHigh_[1] ) FillHisto(histoTag+"_JP_DoubleBMfail_pt1", flav, isGSPbb, isGSPcc ,jetproba  ,wt); 
  ////DM>>>For now>>>>  else if ( ptjet > ptbinsLow_[2] && ptjet <= ptbinsHigh_[2] ) FillHisto(histoTag+"_JP_DoubleBMfail_pt2", flav, isGSPbb, isGSPcc ,jetproba  ,wt); 
  ////DM>>>For now>>>>  else if ( ptjet > ptbinsLow_[3] && ptjet <= ptbinsHigh_[3] ) FillHisto(histoTag+"_JP_DoubleBMfail_pt3", flav, isGSPbb, isGSPcc ,jetproba  ,wt); 
  ////DM>>>For now>>>>}

}

// ------------ method called once each job just after ending the event loop  ------------
void BTagValidation::endJob() {

  h1_CutFlow->SetBinContent(1, nEventsAll); //// strictly speaking not correct since event weights not applied
  h1_CutFlow->SetBinContent(2, nEventsStored); //// strictly speaking not correct since event weights not applied
  h1_CutFlow_unw->SetBinContent(1, nEventsAll);
  h1_CutFlow_unw->SetBinContent(2, nEventsStored);
  h1_CutFlow->SetBinError(1, TMath::Sqrt(nEventsAll)); //// strictly speaking not correct since event weights not applied
  h1_CutFlow->SetBinError(2, TMath::Sqrt(nEventsStored)); //// strictly speaking not correct since event weights not applied
  h1_CutFlow_unw->SetBinError(1, TMath::Sqrt(nEventsAll));
  h1_CutFlow_unw->SetBinError(2, TMath::Sqrt(nEventsStored));
}

// ------------ method called when starting to processes a run  ------------
void BTagValidation::beginRun(edm::Run const&, edm::EventSetup const&) {
}

// ------------ method called when ending the processing of a run  ------------
void BTagValidation::endRun(edm::Run const&, edm::EventSetup const&) {
}

// ------------ method called when starting to processes a luminosity block  ------------
void BTagValidation::beginLuminosityBlock(edm::LuminosityBlock const&, edm::EventSetup const&) {
}

// ------------ method called when ending the processing of a luminosity block  ------------
void BTagValidation::endLuminosityBlock(edm::LuminosityBlock const&, edm::EventSetup const&) {
}

// ------------ method fills 'descriptions' with the allowed parameters for the module  ------------
void BTagValidation::fillDescriptions(edm::ConfigurationDescriptions& descriptions) {
  //The following says we do not know what parameters are allowed so do no validation
  // Please change this to state exactly what you do use, even if it is no parameters
  edm::ParameterSetDescription desc;
  desc.setUnknown();
  descriptions.addDefault(desc);
}

// ------------------------------------------------------------------------------
void BTagValidation::AddHisto(const TString& name, const TString& title, const int nbins, const double min, const double max)  {

  TH1D* h_b;
  TH1D* h_bfromg;
  TH1D* h_c;
  TH1D* h_cfromg;
  TH1D* h_l;
  TH1D* h_mc;

  if( useFlavorCategories_ )
  {
    h_b      = fs->make<TH1D>(name+"_b"     ,title+"_b"     ,nbins,min,max);
    h_bfromg = fs->make<TH1D>(name+"_bfromg",title+"_bfromg",nbins,min,max);
    h_c      = fs->make<TH1D>(name+"_c"     ,title+"_c"     ,nbins,min,max);
    h_cfromg = fs->make<TH1D>(name+"_cfromg",title+"_cfromg",nbins,min,max);
    h_l      = fs->make<TH1D>(name+"_l"     ,title+"_l"     ,nbins,min,max);

    h_b      ->Sumw2();
    h_bfromg ->Sumw2();
    h_c      ->Sumw2();
    h_cfromg ->Sumw2();
    h_l      ->Sumw2();

    HistoBtag_map[name+"_b"]      = h_b;
    HistoBtag_map[name+"_bfromg"] = h_bfromg;
    HistoBtag_map[name+"_c"]      = h_c;
    HistoBtag_map[name+"_cfromg"] = h_cfromg;
    HistoBtag_map[name+"_l"]      = h_l;
  }
  else
  {
    h_mc = fs->make<TH1D>(name+"_mc",title+"_mc",nbins,min,max);
    h_mc->Sumw2();
    HistoBtag_map[name+"_mc"] = h_mc;
  }

  TH1D* h_data= fs->make<TH1D>(name+"_data",title+"_data",nbins,min,max);
  h_data->Sumw2();
  HistoBtag_map[name+"_data"] = h_data;
}


// ------------------------------------------------------------------------------
template <class Type>
void BTagValidation::FillHisto(const TString& name, const int flavour, const bool isGSPbb , const bool isGSPcc , const Type value, const double weight) {
  if (!isData) {
    if( useFlavorCategories_ ) {
      if( isGSPbb ) HistoBtag_map[name+"_bfromg"]->Fill(double(value),weight);
      else if( isGSPcc ) HistoBtag_map[name+"_cfromg"]->Fill(double(value),weight);
      //RS>>else if (isGSPcc&&abs(flavour)==4) 		  HistoBtag_map[name+"_cfromg"]->Fill(double(value),weight);
      else {
        if (abs(flavour)==5)                          HistoBtag_map[name+"_b"]->Fill(double(value),weight);
        else if (abs(flavour)==4)                     HistoBtag_map[name+"_c"]->Fill(double(value),weight);
        else if (abs(flavour)< 4 || abs(flavour)==21) HistoBtag_map[name+"_l"]->Fill(double(value),weight);
      }
    }
    else HistoBtag_map[name+"_mc"]->Fill(double(value),weight);
  }
  else {
    HistoBtag_map[name+"_data"]->Fill(double(value));
  }
}

bool BTagValidation::passTrigger() {
  bool ret = false;

  if(triggerSelection_.size()==0) ret = true;
  else {
    for(unsigned i=0; i<triggerSelection_.size(); ++i) {
      std::string trigpath = triggerSelection_.at(i) ; 
      std::vector<std::string>::const_iterator it ;
      for ( it = triggerPathNames_.begin(); it != triggerPathNames_.end(); ++it) {
        if ( it->find(trigpath) < std::string::npos ) {
          //int triggerIdx = ( it - triggerPathNames_.begin() );
          //int bitIdx = int(triggerIdx/32);
          ret = true;
          break;
        }
      }
    }
  }

  return ret;
}

bool BTagValidation::passMuonSelection(const int muIdx, const JetInfoBranches& JetInfo, const int iJet, const double deltaR) {
  TLorentzVector muon, jet;

  jet.SetPtEtaPhiM(JetInfo.Jet_pt[iJet], JetInfo.Jet_eta[iJet], JetInfo.Jet_phi[iJet], JetInfo.Jet_mass[iJet]);
  muon.SetPtEtaPhiM(JetInfo.PFMuon_pt[muIdx], JetInfo.PFMuon_eta[muIdx], JetInfo.PFMuon_phi[muIdx], 0);

  bool cut_mu_pass = false;
  if (JetInfo.PFMuon_pt[muIdx] > 7 && fabs(JetInfo.PFMuon_eta[muIdx]) < 2.4 
      && JetInfo.PFMuon_isGlobal[muIdx] == 1 
      && JetInfo.PFMuon_nMuHit[muIdx] > 0 
      && JetInfo.PFMuon_nMatched[muIdx] > 1 
      && JetInfo.PFMuon_nTkHit[muIdx] > (useRelaxedMuonID_ ? 7 : 10) 
      && JetInfo.PFMuon_nPixHit[muIdx] > (useRelaxedMuonID_ ? 0 : 1) 
      && JetInfo.PFMuon_nOutHit[muIdx] < (useRelaxedMuonID_ ? 99 : 3) 
      && JetInfo.PFMuon_chi2Tk[muIdx] < 10 
      && JetInfo.PFMuon_chi2[muIdx] < 10  
      && (jet.DeltaR(muon) < deltaR && muon.Pt()/jet.Pt() < 0.5 )
      //&& JetInfo.PFMuon_vz[muIdx]< 2 
      //DM&& fabs(JetInfo.PFMuon_vz[muIdx]-EvtInfo.PVz) < 2.
     )
    cut_mu_pass = true ;

  return cut_mu_pass;
}

// ------------ method that returns pT- and eta-dependent b-tag efficiency scale factor  ------------
double BTagValidation::scaleFactor(const int partonFlavor, const double jetPt, const double jetEta, const bool isCSVM) {
  if( isCSVM ) {
    if( abs(partonFlavor)==5 ) return scaleFactorB_CSVM(jetPt,jetEta);
    else if( abs(partonFlavor)==4 ) return scaleFactorC_CSVM(jetPt,jetEta);
    else return scaleFactorUDSG_CSVM(jetPt,jetEta);
  }
  else {
    if( abs(partonFlavor)==5 ) return scaleFactorB_CSVL(jetPt,jetEta);
    else if( abs(partonFlavor)==4 ) return scaleFactorC_CSVL(jetPt,jetEta);
    else return scaleFactorUDSG_CSVL(jetPt,jetEta);
  }
}

// ------------ method that returns pT- and eta-dependent b-tag efficiency scale factor for b-jets and CSVL tagger  ------------
double BTagValidation::scaleFactorB_CSVL(const double jetPt, const double jetEta) {
  double Pt = jetPt;
  // for scale factor extrapolation
  if(Pt<20.) Pt = 20.;
  if(Pt>800.) Pt = 800.;

  return CSVL_SFb_0to2p4->Eval(Pt) + SFbShift_*CSVL_SFb_errors->GetBinContent(CSVL_SFb_errors->GetXaxis()->FindBin(jetPt));
}

// ------------ method that returns pT- and eta-dependent b-tag efficiency scale factor for c-jets and CSVL tagger  ------------
double BTagValidation::scaleFactorC_CSVL(const double jetPt, const double jetEta) {
  double Pt = jetPt;
  // for scale factor extrapolation
  if(Pt<20.) Pt = 20.;
  if(Pt>800.) Pt = 800.;

  return CSVL_SFb_0to2p4->Eval(Pt) + 2*SFbShift_*CSVL_SFb_errors->GetBinContent(CSVL_SFb_errors->GetXaxis()->FindBin(jetPt));
}

// ------------ method that returns pT- and eta-dependent b-tag efficiency scale factor for light flavor jets and CSVL tagger ------------
double BTagValidation::scaleFactorUDSG_CSVL(const double jetPt, const double jetEta) {
  double SF = 1.;
  double Pt = jetPt;
  double absEta = fabs(jetEta);
  // for scale factor extrapolation
  if(Pt<20.) Pt = 20.;

  if(absEta<0.5) {
    if(Pt>1000.) Pt = 1000.;

    SF = CSVL_SFl_0to0p5->Eval(Pt) + ( (jetPt<20. || jetPt>1000.) ? 2. : 1. )*fabs(SFlShift_)*( SFlShift_ >= 0. ? (CSVL_SFl_0to0p5_max->Eval(Pt) - CSVL_SFl_0to0p5->Eval(Pt)) : (CSVL_SFl_0to0p5_min->Eval(Pt) - CSVL_SFl_0to0p5->Eval(Pt)) );
  }
  else if(absEta>=0.5 && absEta<1.) {
    if(Pt>1000.) Pt = 1000.;

    SF = CSVL_SFl_0p5to1p0->Eval(Pt) + ( (jetPt<20. || jetPt>1000.) ? 2. : 1. )*fabs(SFlShift_)*( SFlShift_ >= 0. ? (CSVL_SFl_0p5to1p0_max->Eval(Pt) - CSVL_SFl_0p5to1p0->Eval(Pt)) : (CSVL_SFl_0p5to1p0_min->Eval(Pt) - CSVL_SFl_0p5to1p0->Eval(Pt)) );
  }
  else if(absEta>=1. && absEta<1.5) {
    if(Pt>1000.) Pt = 1000.;

    SF = CSVL_SFl_1p0to1p5->Eval(Pt) + ( (jetPt<20. || jetPt>1000.) ? 2. : 1. )*fabs(SFlShift_)*( SFlShift_ >= 0. ? (CSVL_SFl_1p0to1p5_max->Eval(Pt) - CSVL_SFl_1p0to1p5->Eval(Pt)) : (CSVL_SFl_1p0to1p5_min->Eval(Pt) - CSVL_SFl_1p0to1p5->Eval(Pt)) );
  }
  else {
    if(Pt>850.) Pt = 850.;

    SF = CSVL_SFl_1p5to2p4->Eval(Pt) + ( (jetPt<20. || jetPt>850.) ? 2. : 1. )*fabs(SFlShift_)*( SFlShift_ >= 0. ? (CSVL_SFl_1p5to2p4_max->Eval(Pt) - CSVL_SFl_1p5to2p4->Eval(Pt)) : (CSVL_SFl_1p5to2p4_min->Eval(Pt) - CSVL_SFl_1p5to2p4->Eval(Pt)) );
  }

  return SF;
}

// ------------ method that returns pT- and eta-dependent b-tag efficiency scale factor for b-jets and CSVM tagger  ------------
double BTagValidation::scaleFactorB_CSVM(const double jetPt, const double jetEta) {
  double Pt = jetPt;
  // for scale factor extrapolation
  if(Pt<20.) Pt = 20.;
  if(Pt>800.) Pt = 800.;

  return CSVM_SFb_0to2p4->Eval(Pt) + SFbShift_*CSVM_SFb_errors->GetBinContent(CSVM_SFb_errors->GetXaxis()->FindBin(jetPt));
}

// ------------ method that returns pT- and eta-dependent b-tag efficiency scale factor for c-jets and CSVM tagger  ------------
double BTagValidation::scaleFactorC_CSVM(const double jetPt, const double jetEta) {
  double Pt = jetPt;
  // for scale factor extrapolation
  if(Pt<20.) Pt = 20.;
  if(Pt>800.) Pt = 800.;

  return CSVM_SFb_0to2p4->Eval(Pt) + 2*SFbShift_*CSVM_SFb_errors->GetBinContent(CSVM_SFb_errors->GetXaxis()->FindBin(jetPt));
}

// ------------ method that returns pT- and eta-dependent b-tag efficiency scale factor for light flavor jets and CSVM tagger ------------
double BTagValidation::scaleFactorUDSG_CSVM(const double jetPt, const double jetEta) {
  double SF = 1.;
  double Pt = jetPt;
  double absEta = fabs(jetEta);
  // for scale factor extrapolation
  if(Pt<20.) Pt = 20.;

  if(absEta<0.8) {
    if(Pt>1000.) Pt = 1000.;

    SF = CSVM_SFl_0to0p8->Eval(Pt) + ( (jetPt<20. || jetPt>1000.) ? 2. : 1. )*fabs(SFlShift_)*( SFlShift_ >= 0. ? (CSVM_SFl_0to0p8_max->Eval(Pt) - CSVM_SFl_0to0p8->Eval(Pt)) : (CSVM_SFl_0to0p8_min->Eval(Pt) - CSVM_SFl_0to0p8->Eval(Pt)) );
  }
  else if(absEta>=0.8 && absEta<1.6) {
    if(Pt>1000.) Pt = 1000.;

    SF = CSVM_SFl_0p8to1p6->Eval(Pt) + ( (jetPt<20. || jetPt>1000.) ? 2. : 1. )*fabs(SFlShift_)*( SFlShift_ >= 0. ? (CSVM_SFl_0p8to1p6_max->Eval(Pt) - CSVM_SFl_0p8to1p6->Eval(Pt)) : (CSVM_SFl_0p8to1p6_min->Eval(Pt) - CSVM_SFl_0p8to1p6->Eval(Pt)) );
  }
  else {
    if(Pt>850.) Pt = 850.;

    SF = CSVM_SFl_1p6to2p4->Eval(Pt) + ( (jetPt<20. || jetPt>850.) ? 2. : 1. )*fabs(SFlShift_)*( SFlShift_ >= 0. ? (CSVM_SFl_1p6to2p4_max->Eval(Pt) - CSVM_SFl_1p6to2p4->Eval(Pt)) : (CSVM_SFl_1p6to2p4_min->Eval(Pt) - CSVM_SFl_1p6to2p4->Eval(Pt)) );
  }

  return SF;
}

// ---- Method returns MC event weight for for reweighting to the NPV distribution in the data: substitute for official PU reweighting ----
double BTagValidation::GetLumiWeightsPVBased (const std::string file, const std::string hist, const int npv) { 
  double wtPU(1) ;
  TFile* f = new TFile(file.c_str()) ;
  TH1D* hwt = new TH1D( *(static_cast<TH1D*>(f->Get( hist.c_str() )->Clone() )) ); 
  wtPU = npv > 0 && npv <= 60 ? hwt->GetBinContent(npv) : 1.; 
  f->Close() ; 
  delete f ;
  delete hwt ; 
  return wtPU ;
}

// ----For calculating MC event weight for reweighting to the jetPt distribution in the data
double BTagValidation::GetLumiWeightsJetPtBased (const std::string file, const std::string hist, const double jetpt) {
  double wtPt(1) ;
  TFile* f = new TFile(file.c_str()) ;
  TH1D* hwt = new TH1D( *(static_cast<TH1D*>(f->Get( hist.c_str() )->Clone() )) );
  wtPt = jetpt > 0 && jetpt <= 5000 ? hwt->GetBinContent(hwt->GetXaxis()->FindBin(jetpt)) : 1.;
  f->Close() ;
  delete f ;
  delete hwt ;
  return wtPt ;
}

//define this as a plug-in
DEFINE_FWK_MODULE(BTagValidation);
