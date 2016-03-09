void makeComparisonBackground_3hist(TString var , double low =0., double max =100., TString label="", int rebin=1, TString option="425", bool isLog=0){

gROOT->SetStyle("Plain");
gStyle->SetPadGridX(0);
gStyle->SetPadGridY(0);
gStyle->SetOptStat(0);

TCanvas * c1 = new TCanvas("c1","c1", 700, 700);
TLegend *leg = new TLegend(0.4444465625,0.7021654,0.8365625,0.8603839,NULL,"brNDC");
   leg->SetBorderSize(0);
   leg->SetTextSize(0.045);
   leg->SetLineColor(1);
   leg->SetLineStyle(1);
   leg->SetLineWidth(1);
   leg->SetFillColor(0);
   leg->SetFillStyle(0);

TString massp = "M-1000";

TFile * f ;
f = new TFile("/afs/cern.ch/user/r/rsyarif/workHere/HbbTagVal/Feb06-2016_SubjetPtReweight/CMSSW_7_6_3/src/RecoBTag/BTagValidation/test/rizki_LXBatch_BulkGravTohhTohbbhbb_narrow_"+massp+"_useSoftDrop_fjpt425_50m_DoubleMuTag_merged/Final_histograms_btagval.root");

f->cd();
TH1D *h = new TH1D();
h = (TH1D*) f->Get("SIGNAL__FatJet_"+var);
// cout << "Variable Name = " << var << endl;
h->SetLineColor(kBlue+2);
h->SetLineWidth(3);
int nbin =  h->GetXaxis()->GetNbins();
double Ymax = h->GetMaximum();
// cout << "h max before scale = " << Ymax << endl;
h->SetTitle("");
h->GetXaxis()->SetRangeUser(low, max);
h->Scale(1/(h->Integral(1,nbin)));
h->Rebin(rebin);
// cout << "h max after scale = " << h->GetMaximum() << endl;

//---might be useful for coding reference--- -start
// std::stringstream ss;
// ss << nbin;
// TString strNb = ss.str();
// //float low =  h->GetXaxis()->GetXmin();
// //if( low<0) {low=0; }
// std::stringstream ss1;
// ss1 << low;
// TString strL=(ss1.str());
// //float max = h->GetXaxis()->GetXmax();
// std::stringstream ss2;
// ss2 << max;
// TString strM= (ss2.str());
// //Fjets->Draw(var+">>h("+strNb+","+strL+","+strM+")"," abs(int(flavour))==5 && nbHadrons<2 && massPruned>80 && massPruned<200");//ptPruned>300 & ptPruned<500");
//---might be useful for coding reference--- -end

c1->Update();

leg->AddEntry(h,"Hbb (bfromg flavor)","l");

TFile * f2 ;
if(option=="425_sjptbalancereweight")f2 = new TFile("/afs/cern.ch/work/r/rsyarif/work/HbbTagVal/Feb06-2016_SubjetPtReweight/CMSSW_7_6_3/src/RecoBTag/BTagValidation/test/rizki_LXBatch_QCDMuEnriched_useSoftDrop_fjpt425_50m_DoubleMuTag_reweight_merged/Final_histograms_btagval.root");
if(option=="425_ptreweight")f2= new TFile("/afs/cern.ch/user/r/rsyarif/workHere/HbbTagVal/Feb06-2016_SubjetPtReweight/CMSSW_7_6_3/src/RecoBTag/BTagValidation/test/rizki_signalMC_GluGLu/Final_histograms_btagval_QCD76x_pt425_m50_pTreweighted_fromAlice.root");

f2->cd();

TH1D *h2 = new TH1D();
h2 = (TH1D*) f2->Get("QCD__FatJet_"+var);
// cout << "h2 max = " << h2->GetMaximum() << endl;

h2->SetLineColor(kRed);
h2->SetLineWidth(3);
h2->GetXaxis()->SetTitle(var);
h2->GetXaxis()->SetRangeUser(low, max);
h2->SetTitle("");
c1->cd();
c1->Update();
h2->Scale(1/(h2->Integral(1,nbin)));
h2->Rebin(rebin);
// cout << "h2 max after scale = " << h2->GetMaximum() << endl;

TFile * f3 ;

f3 = new TFile("/afs/cern.ch/work/r/rsyarif/work/HbbTagVal/Feb06-2016_SubjetPtReweight/CMSSW_7_6_3/src/RecoBTag/BTagValidation/test/rizki_LXBatch_QCDMuEnriched_useSoftDrop_fjpt425_50m_DoubleMuTag_merged/Final_histograms_btagval.root");

f3->cd();

TH1D *h3 = new TH1D();
h3 = (TH1D*) f3->Get("QCD__FatJet_"+var);
// cout << "h3 max = " << h3->GetMaximum() << endl;

h3->SetLineColor(kAzure+1);
h3->SetLineWidth(2);
h3->GetXaxis()->SetTitle(var);
h3->GetXaxis()->SetRangeUser(low, max);
h3->SetTitle("");
c1->cd();
c1->Update();
h3->Scale(1/(h3->Integral(1,nbin)));
h3->Rebin(rebin);
// cout << "h3 max after scale = " << h3->GetMaximum() << endl;

leg->AddEntry(h2,"QCDbb (bfromg) weighted","l");
leg->AddEntry(h3,"QCDbb (bfromg) unweighted","l");


// RATIO PLOT

TH1D *hratio = (TH1D*)h->Clone("hratio");
hratio->Divide(h2);

TH1D *hratio2 = (TH1D*)h->Clone("hratio");
hratio2->Divide(h3);

 //*************************************************
  // Variables
  bool topPlotLogY = 1;      // 0 = no log; 1= log
  TString yTitle2 = "Hbb/QCDbb"; // bottom plot y axis title

  vector<int> histColors; 
  histColors.push_back(kBlue);  // change colors as you like
  histColors.push_back(kRed);
//   histColors.push_back(kGreen-1);

//   int histDenominatorColor = kBlack;

  float defaultRatioYmin = -0.5;
  float defaultRatioYmax = 2.5;
  // END of Variables
  //*************************************************

 // Bottom plot
  TPad *c1_1 = new TPad("c1_1", "newpad",0.01,0.01,0.99,0.32);
  c1_1->Draw();
  c1_1->cd();
  c1_1->SetTopMargin(0.01);
  c1_1->SetBottomMargin(0.3);
  c1_1->SetRightMargin(0.1);
  c1_1->SetFillStyle(0);
  c1_1->SetGridy();
	

  hratio->SetLineWidth(1);
  hratio->SetMarkerStyle(1);
  hratio->SetLineColor(histColors[0]);
  hratio->SetMinimum(defaultRatioYmin);
  hratio->SetMaximum(defaultRatioYmax);
  hratio->GetYaxis()->SetNdivisions(5);
  hratio->SetTitle(";"+label+";"+yTitle2);
//   hratio->SetTitle(";"+xTitle+";"+yTitle2);
  hratio->GetXaxis()->SetTitleSize(0.14);
  hratio->GetXaxis()->SetLabelSize(0.14);
  hratio->GetYaxis()->SetLabelSize(0.11);
  hratio->GetYaxis()->SetTitleSize(0.14);
  hratio->GetYaxis()->SetTitleOffset(0.28);
  hratio->GetXaxis()->SetRangeUser(low, max);
  hratio->Draw("same");

  hratio2->SetLineWidth(1);
  hratio2->SetMarkerStyle(1);
  hratio2->SetLineColor(histColors[1]);
  hratio2->SetMinimum(defaultRatioYmin);
  hratio2->SetMaximum(defaultRatioYmax);
  hratio2->GetYaxis()->SetNdivisions(5);
  hratio2->SetTitle(";"+label+";"+yTitle2);
//   hratio2->SetTitle(";"+xTitle+";"+yTitle2);
  hratio2->GetXaxis()->SetTitleSize(0.14);
  hratio2->GetXaxis()->SetLabelSize(0.14);
  hratio2->GetYaxis()->SetLabelSize(0.11);
  hratio2->GetYaxis()->SetTitleSize(0.14);
  hratio2->GetYaxis()->SetTitleOffset(0.28);
  hratio2->GetXaxis()->SetRangeUser(low, max);
  hratio2->Draw("same");


  
  // End bottom plot
  //*************************************************

  //*************************************************
  // Top Plot
  c1->cd();
  c1_2 = new TPad("c1_2", "newpad",0.01,0.33,0.99,0.99);
  c1_2->Draw(); 
  c1_2->cd();
  c1_2->SetTopMargin(0.1);
  c1_2->SetBottomMargin(0.01);
  c1_2->SetRightMargin(0.1);
  c1_2->SetFillStyle(0);

  h2->SetLineWidth(2);
//   h2->Draw("hist");
  h2->SetLabelSize(0.0);
  h2->GetXaxis()->SetTitleSize(0.00);
  h2->GetYaxis()->SetLabelSize(0.07);
  h2->GetYaxis()->SetTitleSize(0.08);
  h2->GetYaxis()->SetTitleOffset(0.76);
//   h2->SetMaximum(1.2*h->GetMaximum());
//   h2->GetYaxis()->SetRangeUser(1e-6, 1.2*h->GetMaximum());
  
  h->SetLineWidth(2);
//   h->Draw("samehist");

THStack *stack = new THStack("stack","");
stack->Add(h,"hist");
stack->Add(h2,"hist");
stack->Add(h3,"hist");
stack->Draw("nostack");
stack->GetXaxis()->SetRangeUser(low, max);
// cout <<"stack maximum = " << stack->GetMaximum("nostack") << endl;
if(isLog==1)stack->SetMaximum(stack->GetMaximum("nostack")*1e4);
if(isLog==0)stack->SetMaximum(stack->GetMaximum("nostack")*1.2);
// if(isLog==0)stack->SetMaximum(0.1);
// stack->GetXaxis()->SetTitle(label);
stack->GetXaxis()->SetLabelSize(0.0);
stack->GetXaxis()->SetLabelOffset(999);


  c1_2->SetLogy(isLog);
  // End top plot

leg->Draw("same");
c1->Modified();
if(isLog==0){
// 	c1->Print(("plots/"+var+"_"+"sig"+massp+"_"+"pt"+option+"_linear_ratio_3hist.png"));
	c1->SaveAs("plots/"+var+"_"+"sig"+massp+"_"+"pt"+option+"_linear_ratio_3hist.pdf");
	}
if(isLog==1){	
	c1->SetLogy();
// 	c1->Print(("plots/"+var+"_"+"sig"+massp+"_"+"pt"+option+"_log_ratio_3hist.png"));
	c1->SaveAs("plots/"+var+"_"+"sig"+massp+"_"+"pt"+option+"_log_ratio_3hist.pdf");
	}


}
