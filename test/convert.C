#include "TFile.h"
#include "TString.h"
#include "TH1F.h"

bool DEBUG = false;

void convert(TString fin, std::string fout, std::string WP, double kScales[7], std::string kScaleStr)
{
   Float_t nReBin = 2.5;
   
   Float_t kScale_b = kScales[0];
   Float_t kScale_cfromg = kScales[1];
   Float_t kScale_c = kScales[2];
   Float_t kScale_l = kScales[3];

   Float_t kScale_b_cfromg = kScales[4];
   Float_t kScale_c_l = kScales[5];
   
   Float_t kScale = kScales[6];

   TFile *f;

   TFile *fNew;
   
   f = TFile::Open(fin);
   
   TString fout_ = (fout+"_DoubleB"+WP+kScaleStr+".root").c_str();

   fNew = TFile::Open(fout_,"RECREATE");
   std::cout<< "Creating file: "<< fout_ << std::endl;

   std::string tag; 
   tag = "DoubleB"+WP;
   
   std::string var = "JP";
//    const int npt = 8;
//    std::string ptt[npt] = {"pt5","pt4","pt2","pt3","pt0","pt1","pt6","pt7"};

   const int npt = 13;
   std::string ptt[npt] = {"pt5","pt4","pt2","pt3","pt0","pt1","pt6","pt7","pt8","pt9","pt10","pt11","pt12"};

/*
250-300 - pt7
300-350 - pt11
350-400 - pt12
400-450 - pt0
450-500 - pt1

250-350 - pt8
350-450 - pt9

300-400 - pt5
400-500 - pt4
500-600 - pt2
600-2000 - pt3

500-2000 - pt6
450-2000 - pt10
*/

//    const int nSys = 7;
//   std::string sysName[nSys] = {"JES","NTRACKS","BFRAG","CFRAG","CD","K0L","PU"};

//    const int nSys = 6;
//   std::string sysName[nSys] = {"NTRACKS","BFRAG","CFRAG","CD","K0L","PU"};

   const int nSys=0;
   std::string sysName[nSys];

//    const int nSys = 1;
//   std::string sysName[nSys] = {"JES"};


   for(int i=0;i<npt;i++)
     {
	std::string pt = ptt[i];
	
	// data
	std::string hname_data = "UNWEIGHTED__DATA__FatJet_"+var+"_all_"+pt+"_data";
	std::string hname_data_tag = "UNWEIGHTED__DATA__FatJet_"+var+"_"+tag+"pass_"+pt+"_data";
	std::string hname_data_untag = "UNWEIGHTED__DATA__FatJet_"+var+"_"+tag+"fail_"+pt+"_data";
	if(DEBUG)std::cout<< "attempt get data histograms "<< var << ", "<<tag <<", pt = "<<pt<< std::endl;
	TH1F *h_data = (TH1F*)f->Get(hname_data.c_str());
	TH1F *h_data_tag = (TH1F*)f->Get(hname_data_tag.c_str());
	TH1F *h_data_untag = (TH1F*)f->Get(hname_data_untag.c_str());
	if(DEBUG)std::cout<< "got data histograms."<<std::endl;	
	float int_data = h_data->Integral(0,h_data->GetXaxis()->GetNbins()+1);
	float int_data_tag = h_data_tag->Integral(0,h_data_tag->GetXaxis()->GetNbins()+1);
	float int_data_untag = h_data_untag->Integral(0,h_data_untag->GetXaxis()->GetNbins()+1);

	// pre-tag
	std::string hname_bfromg = "UNWEIGHTED__QCD__FatJet_"+var+"_all_"+pt+"_bfromg";
	std::string hname_b = "UNWEIGHTED__QCD__FatJet_"+var+"_all_"+pt+"_b";
	std::string hname_cfromg = "UNWEIGHTED__QCD__FatJet_"+var+"_all_"+pt+"_cfromg";
	std::string hname_c = "UNWEIGHTED__QCD__FatJet_"+var+"_all_"+pt+"_c";
	std::string hname_l = "UNWEIGHTED__QCD__FatJet_"+var+"_all_"+pt+"_l";

	TH1F *h_bfromg = (TH1F*)f->Get(hname_bfromg.c_str());
	h_bfromg->Scale(kScale);
	float int_bfromg = h_bfromg->Integral(0,h_bfromg->GetXaxis()->GetNbins()+1);
	TH1F *h_b = (TH1F*)f->Get(hname_b.c_str());
	h_b->Scale(kScale*kScale_b);
	float int_b = h_b->Integral(0,h_b->GetXaxis()->GetNbins()+1);
	TH1F *h_cfromg = (TH1F*)f->Get(hname_cfromg.c_str());
	h_cfromg->Scale(kScale*kScale_cfromg);
	float int_cfromg = h_cfromg->Integral(0,h_cfromg->GetXaxis()->GetNbins()+1);
	TH1F *h_c = (TH1F*)f->Get(hname_c.c_str());
	h_c->Scale(kScale*kScale_c);
	float int_c = h_c->Integral(0,h_c->GetXaxis()->GetNbins()+1);
	TH1F *h_l = (TH1F*)f->Get(hname_l.c_str());
	h_l->Scale(kScale*kScale_l);
	float int_l = h_l->Integral(0,h_l->GetXaxis()->GetNbins()+1);

	float int_total = int_bfromg+int_b+int_cfromg+int_c+int_l;
	float k_lumi = int_data/int_total;
	
	h_bfromg->Scale(k_lumi);
	h_b->Scale(k_lumi);
	h_cfromg->Scale(k_lumi);
	h_c->Scale(k_lumi);
	h_l->Scale(k_lumi);

	TH1F *h_bfromg_JESup[100];
	TH1F *h_b_JESup[100];
	TH1F *h_cfromg_JESup[100];
	TH1F *h_c_JESup[100];
	TH1F *h_l_JESup[100];

	TH1F *h_bfromg_JESdown[100];
	TH1F *h_b_JESdown[100];
	TH1F *h_cfromg_JESdown[100];
	TH1F *h_c_JESdown[100];
	TH1F *h_l_JESdown[100];
	if(DEBUG)std::cout<< "CHECK A "<< std::endl;

	for(int is=0;is<nSys;is++)
	  {	    
	     // pre-tag SYS up
	     std::string hname_bfromg_JESup = "UNWEIGHTED__QCD__FatJet_"+var+"_all_"+sysName[is]+"up_"+pt+"_bfromg";
	     std::string hname_b_JESup = "UNWEIGHTED__QCD__FatJet_"+var+"_all_"+sysName[is]+"up_"+pt+"_b";
	     std::string hname_cfromg_JESup = "UNWEIGHTED__QCD__FatJet_"+var+"_all_"+sysName[is]+"up_"+pt+"_cfromg";
	     std::string hname_c_JESup = "UNWEIGHTED__QCD__FatJet_"+var+"_all_"+sysName[is]+"up_"+pt+"_c";
	     std::string hname_l_JESup = "UNWEIGHTED__QCD__FatJet_"+var+"_all_"+sysName[is]+"up_"+pt+"_l";
	     
	     if( sysName[is] == "NTRACKS" || sysName[is] == "CFRAG" || sysName[is] == "CD" || sysName[is] == "K0L" )
	       {
		  hname_bfromg_JESup = sysName[is]+"__QCD__FatJet_"+var+"_all_"+pt+"_bfromg";
		  hname_b_JESup = sysName[is]+"__QCD__FatJet_"+var+"_all_"+pt+"_b";
		  hname_cfromg_JESup = sysName[is]+"__QCD__FatJet_"+var+"_all_"+pt+"_cfromg";
		  hname_c_JESup = sysName[is]+"__QCD__FatJet_"+var+"_all_"+pt+"_c";
		  hname_l_JESup = sysName[is]+"__QCD__FatJet_"+var+"_all_"+pt+"_l";
	       }	     

	     if( sysName[is] == "BFRAG" || sysName[is] == "PU" )
	       {
		  hname_bfromg_JESup = sysName[is]+"UP__QCD__FatJet_"+var+"_all_"+pt+"_bfromg";
		  hname_b_JESup = sysName[is]+"UP__QCD__FatJet_"+var+"_all_"+pt+"_b";
		  hname_cfromg_JESup = sysName[is]+"UP__QCD__FatJet_"+var+"_all_"+pt+"_cfromg";
		  hname_c_JESup = sysName[is]+"UP__QCD__FatJet_"+var+"_all_"+pt+"_c";
		  hname_l_JESup = sysName[is]+"UP__QCD__FatJet_"+var+"_all_"+pt+"_l";
	       }	     
	     
	     h_bfromg_JESup[is] = (TH1F*)f->Get(hname_bfromg_JESup.c_str());
	     h_bfromg_JESup[is]->Scale(kScale);
	     float int_bfromg_JESup = h_bfromg_JESup[is]->Integral(0,h_bfromg_JESup[is]->GetXaxis()->GetNbins()+1);
	     h_b_JESup[is] = (TH1F*)f->Get(hname_b_JESup.c_str());
	     h_b_JESup[is]->Scale(kScale);
	     float int_b_JESup = h_b_JESup[is]->Integral(0,h_b_JESup[is]->GetXaxis()->GetNbins()+1);
	     h_cfromg_JESup[is] = (TH1F*)f->Get(hname_cfromg_JESup.c_str());
	     h_cfromg_JESup[is]->Scale(kScale);
	     float int_cfromg_JESup = h_cfromg_JESup[is]->Integral(0,h_cfromg_JESup[is]->GetXaxis()->GetNbins()+1);
	     h_c_JESup[is] = (TH1F*)f->Get(hname_c_JESup.c_str());
	     h_c_JESup[is]->Scale(kScale);
	     float int_c_JESup = h_c_JESup[is]->Integral(0,h_c_JESup[is]->GetXaxis()->GetNbins()+1);
	     h_l_JESup[is] = (TH1F*)f->Get(hname_l_JESup.c_str());
	     h_l_JESup[is]->Scale(kScale);
	     float int_l_JESup = h_l_JESup[is]->Integral(0,h_l_JESup[is]->GetXaxis()->GetNbins()+1);
	     
//	     float int_total_JESup = int_bfromg_JESup+int_b_JESup+int_cfromg_JESup+int_c_JESup+int_l_JESup;
//	     float k_lumi_JESup = int_data/int_total_JESup;
	     
	     h_bfromg_JESup[is]->Scale(k_lumi);
	     h_b_JESup[is]->Scale(k_lumi);
	     h_cfromg_JESup[is]->Scale(k_lumi);
	     h_c_JESup[is]->Scale(k_lumi);
	     h_l_JESup[is]->Scale(k_lumi);

	     // pre-tag JESdown
	     std::string hname_bfromg_JESdown = "UNWEIGHTED__QCD__FatJet_"+var+"_all_"+sysName[is]+"down_"+pt+"_bfromg";
	     std::string hname_b_JESdown = "UNWEIGHTED__QCD__FatJet_"+var+"_all_"+sysName[is]+"down_"+pt+"_b";
	     std::string hname_cfromg_JESdown = "UNWEIGHTED__QCD__FatJet_"+var+"_all_"+sysName[is]+"down_"+pt+"_cfromg";
	     std::string hname_c_JESdown = "UNWEIGHTED__QCD__FatJet_"+var+"_all_"+sysName[is]+"down_"+pt+"_c";
	     std::string hname_l_JESdown = "UNWEIGHTED__QCD__FatJet_"+var+"_all_"+sysName[is]+"down_"+pt+"_l";

	     if( sysName[is] == "NTRACKS" || sysName[is] == "CFRAG" || sysName[is] == "CD" || sysName[is] == "K0L" )
	       {
			  hname_bfromg_JESdown = "UNWEIGHTED__QCD__FatJet_"+var+"_all_"+pt+"_bfromg";
			  hname_b_JESdown = "UNWEIGHTED__QCD__FatJet_"+var+"_all_"+pt+"_b";
			  hname_cfromg_JESdown = "UNWEIGHTED__QCD__FatJet_"+var+"_all_"+pt+"_cfromg";
			  hname_c_JESdown = "UNWEIGHTED__QCD__FatJet_"+var+"_all_"+pt+"_c";
			  hname_l_JESdown = "UNWEIGHTED__QCD__FatJet_"+var+"_all_"+pt+"_l";
	       }	     

	     if( sysName[is] == "BFRAG" || sysName[is] == "PU" )
	       {
			  hname_bfromg_JESdown = sysName[is]+"DOWN__QCD__FatJet_"+var+"_all_"+pt+"_bfromg";
			  hname_b_JESdown = sysName[is]+"DOWN__QCD__FatJet_"+var+"_all_"+pt+"_b";
			  hname_cfromg_JESdown = sysName[is]+"DOWN__QCD__FatJet_"+var+"_all_"+pt+"_cfromg";
			  hname_c_JESdown = sysName[is]+"DOWN__QCD__FatJet_"+var+"_all_"+pt+"_c";
			  hname_l_JESdown = sysName[is]+"DOWN__QCD__FatJet_"+var+"_all_"+pt+"_l";
	       }	     
	     
	     h_bfromg_JESdown[is] = (TH1F*)f->Get(hname_bfromg_JESdown.c_str());
	     h_bfromg_JESdown[is]->Scale(kScale);
	     float int_bfromg_JESdown = h_bfromg_JESdown[is]->Integral(0,h_bfromg_JESdown[is]->GetXaxis()->GetNbins()+1);
	     h_b_JESdown[is] = (TH1F*)f->Get(hname_b_JESdown.c_str());
	     h_b_JESdown[is]->Scale(kScale);
	     float int_b_JESdown = h_b_JESdown[is]->Integral(0,h_b_JESdown[is]->GetXaxis()->GetNbins()+1);
	     h_cfromg_JESdown[is] = (TH1F*)f->Get(hname_cfromg_JESdown.c_str());
	     h_cfromg_JESdown[is]->Scale(kScale);
	     float int_cfromg_JESdown = h_cfromg_JESdown[is]->Integral(0,h_cfromg_JESdown[is]->GetXaxis()->GetNbins()+1);
	     h_c_JESdown[is] = (TH1F*)f->Get(hname_c_JESdown.c_str());
	     h_c_JESdown[is]->Scale(kScale);
	     float int_c_JESdown = h_c_JESup[is]->Integral(0,h_c_JESdown[is]->GetXaxis()->GetNbins()+1);
	     h_l_JESdown[is] = (TH1F*)f->Get(hname_l_JESdown.c_str());
	     h_l_JESdown[is]->Scale(kScale);
	     float int_l_JESdown = h_l_JESup[is]->Integral(0,h_l_JESdown[is]->GetXaxis()->GetNbins()+1);
	     
//	     float int_total_JESdown = int_bfromg_JESdown+int_b_JESdown+int_cfromg_JESdown+int_c_JESdown+int_l_JESdown;
//	     float k_lumi_JESdown = int_data/int_total_JESdown;
	     
	     h_bfromg_JESdown[is]->Scale(k_lumi);
	     h_b_JESdown[is]->Scale(k_lumi);
	     h_cfromg_JESdown[is]->Scale(k_lumi);
	     h_c_JESdown[is]->Scale(k_lumi);
	     h_l_JESdown[is]->Scale(k_lumi);
	  }	
	if(DEBUG)std::cout<< "CHECK B "<< std::endl;

	// tag
	std::string hname_bfromg_tag = "UNWEIGHTED__QCD__FatJet_"+var+"_"+tag+"pass_"+pt+"_bfromg";
	std::string hname_b_tag = "UNWEIGHTED__QCD__FatJet_"+var+"_"+tag+"pass_"+pt+"_b";
	std::string hname_cfromg_tag = "UNWEIGHTED__QCD__FatJet_"+var+"_"+tag+"pass_"+pt+"_cfromg";
	std::string hname_c_tag = "UNWEIGHTED__QCD__FatJet_"+var+"_"+tag+"pass_"+pt+"_c";
	std::string hname_l_tag = "UNWEIGHTED__QCD__FatJet_"+var+"_"+tag+"pass_"+pt+"_l";
	
	TH1F *h_bfromg_tag = (TH1F*)f->Get(hname_bfromg_tag.c_str());	
	h_bfromg_tag->Scale(kScale);
	TH1F *h_b_tag = (TH1F*)f->Get(hname_b_tag.c_str());
	h_b_tag->Scale(kScale*kScale_b);
	TH1F *h_cfromg_tag = (TH1F*)f->Get(hname_cfromg_tag.c_str());
	h_cfromg_tag->Scale(kScale*kScale_cfromg);
	TH1F *h_c_tag = (TH1F*)f->Get(hname_c_tag.c_str());
	h_c_tag->Scale(kScale*kScale_c);
	TH1F *h_l_tag = (TH1F*)f->Get(hname_l_tag.c_str());
	h_l_tag->Scale(kScale*kScale_l);

	h_bfromg_tag->Scale(k_lumi);
	h_b_tag->Scale(k_lumi);
	h_cfromg_tag->Scale(k_lumi);
	h_c_tag->Scale(k_lumi);
	h_l_tag->Scale(k_lumi);

	TH1F *h_bfromg_tag_JESup[100];
	TH1F *h_b_tag_JESup[100];
	TH1F *h_cfromg_tag_JESup[100];
	TH1F *h_c_tag_JESup[100];
	TH1F *h_l_tag_JESup[100];

	TH1F *h_bfromg_tag_JESdown[100];
	TH1F *h_b_tag_JESdown[100];
	TH1F *h_cfromg_tag_JESdown[100];
	TH1F *h_c_tag_JESdown[100];
	TH1F *h_l_tag_JESdown[100];
	if(DEBUG)std::cout<< "CHECK C "<< std::endl;
	
	for(int is=0;is<nSys;is++)
	  {	    	
	     // tag JESup
	     std::string hname_bfromg_tag_JESup = "UNWEIGHTED__QCD__FatJet_"+var+"_"+tag+"pass_"+pt+"_"+sysName[is]+"up_bfromg";
	     std::string hname_b_tag_JESup = "UNWEIGHTED__QCD__FatJet_"+var+"_"+tag+"pass_"+pt+"_"+sysName[is]+"up_b";
	     std::string hname_cfromg_tag_JESup = "UNWEIGHTED__QCD__FatJet_"+var+"_"+tag+"pass_"+pt+"_"+sysName[is]+"up_cfromg";
	     std::string hname_c_tag_JESup = "UNWEIGHTED__QCD__FatJet_"+var+"_"+tag+"pass_"+pt+"_"+sysName[is]+"up_c";
	     std::string hname_l_tag_JESup = "UNWEIGHTED__QCD__FatJet_"+var+"_"+tag+"pass_"+pt+"_"+sysName[is]+"up_l";

	     if( sysName[is] == "NTRACKS" || sysName[is] == "CFRAG" || sysName[is] == "CD" || sysName[is] == "K0L" )
	       {
			  hname_bfromg_tag_JESup = sysName[is]+"__QCD__FatJet_"+var+"_"+tag+"pass_"+pt+"_bfromg";
			  hname_b_tag_JESup = sysName[is]+"__QCD__FatJet_"+var+"_"+tag+"pass_"+pt+"_b";
			  hname_cfromg_tag_JESup = sysName[is]+"__QCD__FatJet_"+var+"_"+tag+"pass_"+pt+"_cfromg";
			  hname_c_tag_JESup = sysName[is]+"__QCD__FatJet_"+var+"_"+tag+"pass_"+pt+"_c";
			  hname_l_tag_JESup = sysName[is]+"__QCD__FatJet_"+var+"_"+tag+"pass_"+pt+"_l";
	       }	     

	     if( sysName[is] == "BFRAG" || sysName[is] == "PU" )
	       {
			  hname_bfromg_tag_JESup = sysName[is]+"UP__QCD__FatJet_"+var+"_"+tag+"pass_"+pt+"_bfromg";
			  hname_b_tag_JESup = sysName[is]+"UP__QCD__FatJet_"+var+"_"+tag+"pass_"+pt+"_b";
			  hname_cfromg_tag_JESup = sysName[is]+"UP__QCD__FatJet_"+var+"_"+tag+"pass_"+pt+"_cfromg";
			  hname_c_tag_JESup = sysName[is]+"UP__QCD__FatJet_"+var+"_"+tag+"pass_"+pt+"_c";
			  hname_l_tag_JESup = sysName[is]+"UP__QCD__FatJet_"+var+"_"+tag+"pass_"+pt+"_l";
	       }	     
	     
	     h_bfromg_tag_JESup[is] = (TH1F*)f->Get(hname_bfromg_tag_JESup.c_str());
	     h_bfromg_tag_JESup[is]->Scale(kScale);
	     float int_bfromg_tag_JESup = h_bfromg_tag_JESup[is]->Integral(0,h_bfromg_tag_JESup[is]->GetXaxis()->GetNbins()+1);
	     h_b_tag_JESup[is] = (TH1F*)f->Get(hname_b_tag_JESup.c_str());
	     h_b_tag_JESup[is]->Scale(kScale);
	     float int_b_tag_JESup = h_b_tag_JESup[is]->Integral(0,h_b_tag_JESup[is]->GetXaxis()->GetNbins()+1);
	     h_cfromg_tag_JESup[is] = (TH1F*)f->Get(hname_cfromg_tag_JESup.c_str());
	     h_cfromg_tag_JESup[is]->Scale(kScale);
	     float int_cfromg_tag_JESup = h_cfromg_tag_JESup[is]->Integral(0,h_cfromg_tag_JESup[is]->GetXaxis()->GetNbins()+1);
	     h_c_tag_JESup[is] = (TH1F*)f->Get(hname_c_tag_JESup.c_str());
	     h_c_tag_JESup[is]->Scale(kScale);
	     float int_c_tag_JESup = h_c_tag_JESup[is]->Integral(0,h_c_tag_JESup[is]->GetXaxis()->GetNbins()+1);
	     h_l_tag_JESup[is] = (TH1F*)f->Get(hname_l_tag_JESup.c_str());
	     h_l_tag_JESup[is]->Scale(kScale);
	     float int_l_tag_JESup = h_l_tag_JESup[is]->Integral(0,h_l_tag_JESup[is]->GetXaxis()->GetNbins()+1);
	     
//	     float int_total_tag_JESup = int_bfromg_tag_JESup+int_b_tag_JESup+int_cfromg_tag_JESup+int_c_tag_JESup+int_l_tag_JESup;
//	     float k_lumi_tag_JESup = int_data_tag/int_total_tag_JESup;
	     
	     h_bfromg_tag_JESup[is]->Scale(k_lumi);
	     h_b_tag_JESup[is]->Scale(k_lumi);
	     h_cfromg_tag_JESup[is]->Scale(k_lumi);
	     h_c_tag_JESup[is]->Scale(k_lumi);
	     h_l_tag_JESup[is]->Scale(k_lumi);
	     
	     // tag JESdown
	     std::string hname_bfromg_tag_JESdown = "UNWEIGHTED__QCD__FatJet_"+var+"_"+tag+"pass_"+pt+"_"+sysName[is]+"down_bfromg";
	     std::string hname_b_tag_JESdown = "UNWEIGHTED__QCD__FatJet_"+var+"_"+tag+"pass_"+pt+"_"+sysName[is]+"down_b";
	     std::string hname_cfromg_tag_JESdown = "UNWEIGHTED__QCD__FatJet_"+var+"_"+tag+"pass_"+pt+"_"+sysName[is]+"down_cfromg";
	     std::string hname_c_tag_JESdown = "UNWEIGHTED__QCD__FatJet_"+var+"_"+tag+"pass_"+pt+"_"+sysName[is]+"down_c";
	     std::string hname_l_tag_JESdown = "UNWEIGHTED__QCD__FatJet_"+var+"_"+tag+"pass_"+pt+"_"+sysName[is]+"down_l";

	     if( sysName[is] == "NTRACKS" || sysName[is] == "CFRAG" || sysName[is] == "CD" || sysName[is] == "K0L" )
	       {
			  hname_bfromg_tag_JESdown = "UNWEIGHTED__QCD__FatJet_"+var+"_"+tag+"pass_"+pt+"_bfromg";
			  hname_b_tag_JESdown = "UNWEIGHTED__QCD__FatJet_"+var+"_"+tag+"pass_"+pt+"_b";
			  hname_cfromg_tag_JESdown = "UNWEIGHTED__QCD__FatJet_"+var+"_"+tag+"pass_"+pt+"_cfromg";
			  hname_c_tag_JESdown = "UNWEIGHTED__QCD__FatJet_"+var+"_"+tag+"pass_"+pt+"_c";
			  hname_l_tag_JESdown = "UNWEIGHTED__QCD__FatJet_"+var+"_"+tag+"pass_"+pt+"_l";
	       }

	     if( sysName[is] == "BFRAG" || sysName[is] == "PU" )
	       {
			  hname_bfromg_tag_JESdown = sysName[is]+"DOWN__QCD__FatJet_"+var+"_"+tag+"pass_"+pt+"_bfromg";
			  hname_b_tag_JESdown = sysName[is]+"DOWN__QCD__FatJet_"+var+"_"+tag+"pass_"+pt+"_b";
			  hname_cfromg_tag_JESdown = sysName[is]+"DOWN__QCD__FatJet_"+var+"_"+tag+"pass_"+pt+"_cfromg";
			  hname_c_tag_JESdown = sysName[is]+"DOWN__QCD__FatJet_"+var+"_"+tag+"pass_"+pt+"_c";
			  hname_l_tag_JESdown = sysName[is]+"DOWN__QCD__FatJet_"+var+"_"+tag+"pass_"+pt+"_l";
	       }
	     
	     h_bfromg_tag_JESdown[is] = (TH1F*)f->Get(hname_bfromg_tag_JESdown.c_str());
	     h_bfromg_tag_JESdown[is]->Scale(kScale);
	     float int_bfromg_tag_JESdown = h_bfromg_tag_JESdown[is]->Integral(0,h_bfromg_tag_JESdown[is]->GetXaxis()->GetNbins()+1);
	     h_b_tag_JESdown[is] = (TH1F*)f->Get(hname_b_tag_JESdown.c_str());
	     h_b_tag_JESdown[is]->Scale(kScale);
	     float int_b_tag_JESdown = h_b_tag_JESdown[is]->Integral(0,h_b_tag_JESdown[is]->GetXaxis()->GetNbins()+1);
	     h_cfromg_tag_JESdown[is] = (TH1F*)f->Get(hname_cfromg_tag_JESdown.c_str());
	     h_cfromg_tag_JESdown[is]->Scale(kScale);
	     float int_cfromg_tag_JESdown = h_cfromg_tag_JESdown[is]->Integral(0,h_cfromg_tag_JESdown[is]->GetXaxis()->GetNbins()+1);
	     h_c_tag_JESdown[is] = (TH1F*)f->Get(hname_c_tag_JESdown.c_str());
	     h_c_tag_JESdown[is]->Scale(kScale);
	     float int_c_tag_JESdown = h_c_tag_JESup[is]->Integral(0,h_c_tag_JESdown[is]->GetXaxis()->GetNbins()+1);
	     h_l_tag_JESdown[is] = (TH1F*)f->Get(hname_l_tag_JESdown.c_str());
	     h_l_tag_JESdown[is]->Scale(kScale);
	     float int_l_tag_JESdown = h_l_tag_JESup[is]->Integral(0,h_l_tag_JESdown[is]->GetXaxis()->GetNbins()+1);
	     
//	     float int_total_tag_JESdown = int_bfromg_tag_JESdown+int_b_tag_JESdown+int_cfromg_tag_JESdown+int_c_tag_JESdown+int_l_tag_JESdown;
//	     float k_lumi_tag_JESdown = int_data_tag/int_total_tag_JESdown;
	     
	     h_bfromg_tag_JESdown[is]->Scale(k_lumi);
	     h_b_tag_JESdown[is]->Scale(k_lumi);
	     h_cfromg_tag_JESdown[is]->Scale(k_lumi);
	     h_c_tag_JESdown[is]->Scale(k_lumi);
	     h_l_tag_JESdown[is]->Scale(k_lumi);
	  }	
	if(DEBUG)std::cout<< "CHECK D "<< std::endl;

	// untag
	std::string hname_bfromg_untag = "UNWEIGHTED__QCD__FatJet_"+var+"_"+tag+"fail_"+pt+"_bfromg";
	std::string hname_b_untag = "UNWEIGHTED__QCD__FatJet_"+var+"_"+tag+"fail_"+pt+"_b";
	std::string hname_cfromg_untag = "UNWEIGHTED__QCD__FatJet_"+var+"_"+tag+"fail_"+pt+"_cfromg";
	std::string hname_c_untag = "UNWEIGHTED__QCD__FatJet_"+var+"_"+tag+"fail_"+pt+"_c";
	std::string hname_l_untag = "UNWEIGHTED__QCD__FatJet_"+var+"_"+tag+"fail_"+pt+"_l";
	
	TH1F *h_bfromg_untag = (TH1F*)f->Get(hname_bfromg_untag.c_str());
	h_bfromg_untag->Scale(kScale);
	TH1F *h_b_untag = (TH1F*)f->Get(hname_b_untag.c_str());
	h_b_untag->Scale(kScale*kScale_b);
	TH1F *h_cfromg_untag = (TH1F*)f->Get(hname_cfromg_untag.c_str());
	h_cfromg_untag->Scale(kScale*kScale_cfromg);
	TH1F *h_c_untag = (TH1F*)f->Get(hname_c_untag.c_str());
	h_c_untag->Scale(kScale*kScale_c);
	TH1F *h_l_untag = (TH1F*)f->Get(hname_l_untag.c_str());
	h_l_untag->Scale(kScale*kScale_l);

	h_bfromg_untag->Scale(k_lumi);
	h_b_untag->Scale(k_lumi);
	h_cfromg_untag->Scale(k_lumi);
	h_c_untag->Scale(k_lumi);
	h_l_untag->Scale(k_lumi);

	TH1F *h_bfromg_untag_JESup[100];
	TH1F *h_b_untag_JESup[100];
	TH1F *h_cfromg_untag_JESup[100];
	TH1F *h_c_untag_JESup[100];
	TH1F *h_l_untag_JESup[100];

	TH1F *h_bfromg_untag_JESdown[100];
	TH1F *h_b_untag_JESdown[100];
	TH1F *h_cfromg_untag_JESdown[100];
	TH1F *h_c_untag_JESdown[100];
	TH1F *h_l_untag_JESdown[100];
	if(DEBUG)std::cout<< "CHECK E "<< std::endl;
	
	for(int is=0;is<nSys;is++)
	  {	    	
	     // untag JESup
	     std::string hname_bfromg_untag_JESup = "UNWEIGHTED__QCD__FatJet_"+var+"_"+tag+"fail_"+pt+"_"+sysName[is]+"up_bfromg";
	     std::string hname_b_untag_JESup = "UNWEIGHTED__QCD__FatJet_"+var+"_"+tag+"fail_"+pt+"_"+sysName[is]+"up_b";
	     std::string hname_cfromg_untag_JESup = "UNWEIGHTED__QCD__FatJet_"+var+"_"+tag+"fail_"+pt+"_"+sysName[is]+"up_cfromg";
	     std::string hname_c_untag_JESup = "UNWEIGHTED__QCD__FatJet_"+var+"_"+tag+"fail_"+pt+"_"+sysName[is]+"up_c";
	     std::string hname_l_untag_JESup = "UNWEIGHTED__QCD__FatJet_"+var+"_"+tag+"fail_"+pt+"_"+sysName[is]+"up_l";

	     if( sysName[is] == "NTRACKS" || sysName[is] == "CFRAG" || sysName[is] == "CD" || sysName[is] == "K0L" )
	       {
			  hname_bfromg_untag_JESup = sysName[is]+"__QCD__FatJet_"+var+"_"+tag+"fail_"+pt+"_bfromg";
			  hname_b_untag_JESup = sysName[is]+"__QCD__FatJet_"+var+"_"+tag+"fail_"+pt+"_b";
			  hname_cfromg_untag_JESup = sysName[is]+"__QCD__FatJet_"+var+"_"+tag+"fail_"+pt+"_cfromg";
			  hname_c_untag_JESup = sysName[is]+"__QCD__FatJet_"+var+"_"+tag+"fail_"+pt+"_c";
			  hname_l_untag_JESup = sysName[is]+"__QCD__FatJet_"+var+"_"+tag+"fail_"+pt+"_l";
	       }	     

	     if( sysName[is] == "BFRAG" || sysName[is] == "PU" )
	       {
			  hname_bfromg_untag_JESup = sysName[is]+"UP__QCD__FatJet_"+var+"_"+tag+"fail_"+pt+"_bfromg";
			  hname_b_untag_JESup = sysName[is]+"UP__QCD__FatJet_"+var+"_"+tag+"fail_"+pt+"_b";
			  hname_cfromg_untag_JESup = sysName[is]+"UP__QCD__FatJet_"+var+"_"+tag+"fail_"+pt+"_cfromg";
			  hname_c_untag_JESup = sysName[is]+"UP__QCD__FatJet_"+var+"_"+tag+"fail_"+pt+"_c";
			  hname_l_untag_JESup = sysName[is]+"UP__QCD__FatJet_"+var+"_"+tag+"fail_"+pt+"_l";
	       }	     
	     
	     h_bfromg_untag_JESup[is] = (TH1F*)f->Get(hname_bfromg_untag_JESup.c_str());
	     h_bfromg_untag_JESup[is]->Scale(kScale);
	     float int_bfromg_untag_JESup = h_bfromg_untag_JESup[is]->Integral(0,h_bfromg_untag_JESup[is]->GetXaxis()->GetNbins()+1);
	     h_b_untag_JESup[is] = (TH1F*)f->Get(hname_b_untag_JESup.c_str());
	     h_b_untag_JESup[is]->Scale(kScale);
	     float int_b_untag_JESup = h_b_untag_JESup[is]->Integral(0,h_b_untag_JESup[is]->GetXaxis()->GetNbins()+1);
	     h_cfromg_untag_JESup[is] = (TH1F*)f->Get(hname_cfromg_untag_JESup.c_str());
	     h_cfromg_untag_JESup[is]->Scale(kScale);
	     float int_cfromg_untag_JESup = h_cfromg_untag_JESup[is]->Integral(0,h_cfromg_untag_JESup[is]->GetXaxis()->GetNbins()+1);
	     h_c_untag_JESup[is] = (TH1F*)f->Get(hname_c_untag_JESup.c_str());
	     h_c_untag_JESup[is]->Scale(kScale);
	     float int_c_untag_JESup = h_c_untag_JESup[is]->Integral(0,h_c_untag_JESup[is]->GetXaxis()->GetNbins()+1);
	     h_l_untag_JESup[is] = (TH1F*)f->Get(hname_l_untag_JESup.c_str());
	     h_l_untag_JESup[is]->Scale(kScale);
	     float int_l_untag_JESup = h_l_untag_JESup[is]->Integral(0,h_l_untag_JESup[is]->GetXaxis()->GetNbins()+1);
	     
//	     float int_total_untag_JESup = int_bfromg_untag_JESup+int_b_untag_JESup+int_cfromg_untag_JESup+int_c_untag_JESup+int_l_untag_JESup;
//	     float k_lumi_untag_JESup = int_data_untag/int_total_untag_JESup;
	     
	     h_bfromg_untag_JESup[is]->Scale(k_lumi);
	     h_b_untag_JESup[is]->Scale(k_lumi);
	     h_cfromg_untag_JESup[is]->Scale(k_lumi);
	     h_c_untag_JESup[is]->Scale(k_lumi);
	     h_l_untag_JESup[is]->Scale(k_lumi);

	     // untag JESdown
	     std::string hname_bfromg_untag_JESdown = "UNWEIGHTED__QCD__FatJet_"+var+"_"+tag+"fail_"+pt+"_"+sysName[is]+"down_bfromg";
	     std::string hname_b_untag_JESdown = "UNWEIGHTED__QCD__FatJet_"+var+"_"+tag+"fail_"+pt+"_"+sysName[is]+"down_b";
	     std::string hname_cfromg_untag_JESdown = "UNWEIGHTED__QCD__FatJet_"+var+"_"+tag+"fail_"+pt+"_"+sysName[is]+"down_cfromg";
	     std::string hname_c_untag_JESdown = "UNWEIGHTED__QCD__FatJet_"+var+"_"+tag+"fail_"+pt+"_"+sysName[is]+"down_c";
	     std::string hname_l_untag_JESdown = "UNWEIGHTED__QCD__FatJet_"+var+"_"+tag+"fail_"+pt+"_"+sysName[is]+"down_l";

	     if( sysName[is] == "NTRACKS" || sysName[is] == "CFRAG" || sysName[is] == "CD" || sysName[is] == "K0L" )
	       {
			  hname_bfromg_untag_JESdown = "UNWEIGHTED__QCD__FatJet_"+var+"_"+tag+"fail_"+pt+"_bfromg";
			  hname_b_untag_JESdown = "UNWEIGHTED__QCD__FatJet_"+var+"_"+tag+"fail_"+pt+"_b";
			  hname_cfromg_untag_JESdown = "UNWEIGHTED__QCD__FatJet_"+var+"_"+tag+"fail_"+pt+"_cfromg";
			  hname_c_untag_JESdown = "UNWEIGHTED__QCD__FatJet_"+var+"_"+tag+"fail_"+pt+"_c";
			  hname_l_untag_JESdown = "UNWEIGHTED__QCD__FatJet_"+var+"_"+tag+"fail_"+pt+"_l";
	       }	     

	     if( sysName[is] == "BFRAG" || sysName[is] == "PU" )
	       {
			  hname_bfromg_untag_JESdown = sysName[is]+"DOWN__QCD__FatJet_"+var+"_"+tag+"fail_"+pt+"_bfromg";
			  hname_b_untag_JESdown = sysName[is]+"DOWN__QCD__FatJet_"+var+"_"+tag+"fail_"+pt+"_b";
			  hname_cfromg_untag_JESdown = sysName[is]+"DOWN__QCD__FatJet_"+var+"_"+tag+"fail_"+pt+"_cfromg";
			  hname_c_untag_JESdown = sysName[is]+"DOWN__QCD__FatJet_"+var+"_"+tag+"fail_"+pt+"_c";
			  hname_l_untag_JESdown = sysName[is]+"DOWN__QCD__FatJet_"+var+"_"+tag+"fail_"+pt+"_l";
	       }	     
	     
	     h_bfromg_untag_JESdown[is] = (TH1F*)f->Get(hname_bfromg_untag_JESdown.c_str());
	     h_bfromg_untag_JESdown[is]->Scale(kScale);
	     float int_bfromg_untag_JESdown = h_bfromg_untag_JESdown[is]->Integral(0,h_bfromg_untag_JESdown[is]->GetXaxis()->GetNbins()+1);
	     h_b_untag_JESdown[is] = (TH1F*)f->Get(hname_b_untag_JESdown.c_str());
	     h_b_untag_JESdown[is]->Scale(kScale);
	     float int_b_untag_JESdown = h_b_untag_JESdown[is]->Integral(0,h_b_untag_JESdown[is]->GetXaxis()->GetNbins()+1);
	     h_cfromg_untag_JESdown[is] = (TH1F*)f->Get(hname_cfromg_untag_JESdown.c_str());
	     h_cfromg_untag_JESdown[is]->Scale(kScale);
	     float int_cfromg_untag_JESdown = h_cfromg_untag_JESdown[is]->Integral(0,h_cfromg_untag_JESdown[is]->GetXaxis()->GetNbins()+1);
	     h_c_untag_JESdown[is] = (TH1F*)f->Get(hname_c_untag_JESdown.c_str());
	     h_c_untag_JESdown[is]->Scale(kScale);
	     float int_c_untag_JESdown = h_c_untag_JESup[is]->Integral(0,h_c_untag_JESdown[is]->GetXaxis()->GetNbins()+1);
	     h_l_untag_JESdown[is] = (TH1F*)f->Get(hname_l_untag_JESdown.c_str());
	     h_l_untag_JESdown[is]->Scale(kScale);
	     float int_l_untag_JESdown = h_l_untag_JESup[is]->Integral(0,h_l_untag_JESdown[is]->GetXaxis()->GetNbins()+1);

//	     float int_total_untag_JESdown = int_bfromg_untag_JESdown+int_b_untag_JESdown+int_cfromg_untag_JESdown+int_c_untag_JESdown+int_l_untag_JESdown;
//	     float k_lumi_untag_JESdown = int_data_untag/int_total_untag_JESdown;
	     
	     h_bfromg_untag_JESdown[is]->Scale(k_lumi);
	     h_b_untag_JESdown[is]->Scale(k_lumi);
	     h_cfromg_untag_JESdown[is]->Scale(k_lumi);
	     h_c_untag_JESdown[is]->Scale(k_lumi);
	     h_l_untag_JESdown[is]->Scale(k_lumi);
	  }	

	if(DEBUG)std::cout<< "CHECK F "<< std::endl;

	// COMBINATIONS
	
	std::string hname_data_opt = hname_data+"_opt";
	TH1F *h_data_opt = (TH1F*)h_data->Rebin(nReBin,hname_data_opt.c_str());
	std::string hname_data_tag_opt = hname_data_tag+"_opt";
	TH1F *h_data_tag_opt = (TH1F*)h_data_tag->Rebin(nReBin,hname_data_tag_opt.c_str());
	std::string hname_data_untag_opt = hname_data_untag+"_opt";
	TH1F *h_data_untag_opt = (TH1F*)h_data_untag->Rebin(nReBin,hname_data_untag_opt.c_str());
	
	std::string hname_bfromg_opt = hname_bfromg+"_opt";
	TH1F *h_bfromg_opt = (TH1F*)h_bfromg->Rebin(nReBin,hname_bfromg_opt.c_str());
	std::string hname_b_opt = hname_b+"_opt";
	TH1F *h_b_opt = (TH1F*)h_b->Rebin(nReBin,hname_b_opt.c_str());
	std::string hname_cfromg_opt = hname_cfromg+"_opt";
	TH1F *h_cfromg_opt = (TH1F*)h_cfromg->Rebin(nReBin,hname_cfromg_opt.c_str());
	std::string hname_c_opt = hname_c+"_opt";
	TH1F *h_c_opt = (TH1F*)h_c->Rebin(nReBin,hname_c_opt.c_str());
	std::string hname_l_opt = hname_l+"_opt";
	TH1F *h_l_opt = (TH1F*)h_l->Rebin(nReBin,hname_l_opt.c_str());
	if(DEBUG)std::cout<< "CHECK G "<< std::endl;

	// combine pre-tag
	std::string hname_b_cfromg_opt = hname_b+"_cfromg_opt";
	TH1F *h_b_cfromg_opt = (TH1F*)h_b_opt->Clone(hname_b_cfromg_opt.c_str());
	h_b_cfromg_opt->Add(h_cfromg_opt);
	h_b_cfromg_opt->Scale(kScale_b_cfromg);
	std::string hname_c_l_opt = hname_c+"_l_opt";
	TH1F *h_c_l_opt = (TH1F*)h_c_opt->Clone(hname_c_l_opt.c_str());
	h_c_l_opt->Add(h_l_opt);
	h_c_l_opt->Scale(kScale_c_l);
	std::string hname_b_cfromg_c_l_opt = hname_b+"_cfromg_c_l_opt";
	TH1F *h_b_cfromg_c_l_opt = (TH1F*)h_b_cfromg_opt->Clone(hname_b_cfromg_c_l_opt.c_str());
	h_b_cfromg_c_l_opt->Add(h_c_l_opt);

	TH1F *h_bfromg_JESup_opt[100];
	TH1F *h_b_JESup_opt[100];
	TH1F *h_cfromg_JESup_opt[100];
	TH1F *h_c_JESup_opt[100];
	TH1F *h_l_JESup_opt[100];

	TH1F *h_bfromg_JESdown_opt[100];
	TH1F *h_b_JESdown_opt[100];
	TH1F *h_cfromg_JESdown_opt[100];
	TH1F *h_c_JESdown_opt[100];
	TH1F *h_l_JESdown_opt[100];
	
	TH1F *h_b_cfromg_JESup_opt[100];
	TH1F *h_c_l_JESup_opt[100];
	TH1F *h_b_cfromg_c_l_JESup_opt[100];

	TH1F *h_b_cfromg_JESdown_opt[100];
	TH1F *h_c_l_JESdown_opt[100];
	TH1F *h_b_cfromg_c_l_JESdown_opt[100];
	if(DEBUG)std::cout<< "CHECK H "<< std::endl;

	for(int is=0;is<nSys;is++)
	  {	    		
	     std::string hname_bfromg_JESup_opt = hname_bfromg+"_opt_"+sysName[is]+"up";
	     h_bfromg_JESup_opt[is] = (TH1F*)h_bfromg_JESup[is]->Rebin(nReBin,hname_bfromg_JESup_opt.c_str());
	     std::string hname_b_JESup_opt = hname_b+"_opt_"+sysName[is]+"up";
	     h_b_JESup_opt[is] = (TH1F*)h_b_JESup[is]->Rebin(nReBin,hname_b_JESup_opt.c_str());
	     std::string hname_cfromg_JESup_opt = hname_cfromg+"_opt_"+sysName[is]+"up";
	     h_cfromg_JESup_opt[is] = (TH1F*)h_cfromg_JESup[is]->Rebin(nReBin,hname_cfromg_JESup_opt.c_str());
	     std::string hname_c_JESup_opt = hname_c+"_opt_"+sysName[is]+"up";
	     h_c_JESup_opt[is] = (TH1F*)h_c_JESup[is]->Rebin(nReBin,hname_c_JESup_opt.c_str());
	     std::string hname_l_JESup_opt = hname_l+"_opt_"+sysName[is]+"up";
	     h_l_JESup_opt[is] = (TH1F*)h_l_JESup[is]->Rebin(nReBin,hname_l_JESup_opt.c_str());
	     
	     std::string hname_bfromg_JESdown_opt = hname_bfromg+"_opt_"+sysName[is]+"down";
	     h_bfromg_JESdown_opt[is] = (TH1F*)h_bfromg_JESdown[is]->Rebin(nReBin,hname_bfromg_JESdown_opt.c_str());
	     std::string hname_b_JESdown_opt = hname_b+"_opt_"+sysName[is]+"down";
	     h_b_JESdown_opt[is] = (TH1F*)h_b_JESdown[is]->Rebin(nReBin,hname_b_JESdown_opt.c_str());
	     std::string hname_cfromg_JESdown_opt = hname_cfromg+"_opt_"+sysName[is]+"down";
	     h_cfromg_JESdown_opt[is] = (TH1F*)h_cfromg_JESdown[is]->Rebin(nReBin,hname_cfromg_JESdown_opt.c_str());
	     std::string hname_c_JESdown_opt = hname_c+"_opt_"+sysName[is]+"down";
	     h_c_JESdown_opt[is] = (TH1F*)h_c_JESdown[is]->Rebin(nReBin,hname_c_JESdown_opt.c_str());
	     std::string hname_l_JESdown_opt = hname_l+"_opt_"+sysName[is]+"down";
	     h_l_JESdown_opt[is] = (TH1F*)h_l_JESdown[is]->Rebin(nReBin,hname_l_JESdown_opt.c_str());

	     std::string hname_b_cfromg_JESup_opt = hname_b+"_cfromg_opt_"+sysName[is]+"up";
	     h_b_cfromg_JESup_opt[is] = (TH1F*)h_b_JESup_opt[is]->Clone(hname_b_cfromg_JESup_opt.c_str());
	     h_b_cfromg_JESup_opt[is]->Add(h_cfromg_JESup_opt[is]);
	     h_b_cfromg_JESup_opt[is]->Scale(kScale_b_cfromg);
	     std::string hname_c_l_JESup_opt = hname_c+"_l_opt_"+sysName[is]+"up";
	     h_c_l_JESup_opt[is] = (TH1F*)h_c_JESup_opt[is]->Clone(hname_c_l_JESup_opt.c_str());
	     h_c_l_JESup_opt[is]->Add(h_l_JESup_opt[is]);
	     h_c_l_JESup_opt[is]->Scale(kScale_c_l);
	     std::string hname_b_cfromg_c_l_JESup_opt = hname_b+"_cfromg_c_l_opt_"+sysName[is]+"up";
	     h_b_cfromg_c_l_JESup_opt[is] = (TH1F*)h_b_cfromg_JESup_opt[is]->Clone(hname_b_cfromg_c_l_JESup_opt.c_str());
	     h_b_cfromg_c_l_JESup_opt[is]->Add(h_c_l_JESup_opt[is]);
	     
	     std::string hname_b_cfromg_JESdown_opt = hname_b+"_cfromg_opt_"+sysName[is]+"down";
	     h_b_cfromg_JESdown_opt[is] = (TH1F*)h_b_JESdown_opt[is]->Clone(hname_b_cfromg_JESdown_opt.c_str());
	     h_b_cfromg_JESdown_opt[is]->Add(h_cfromg_JESdown_opt[is]);
	     h_b_cfromg_JESdown_opt[is]->Scale(kScale_b_cfromg);
	     std::string hname_c_l_JESdown_opt = hname_c+"_l_opt_"+sysName[is]+"down";
	     h_c_l_JESdown_opt[is] = (TH1F*)h_c_JESdown_opt[is]->Clone(hname_c_l_JESdown_opt.c_str());
	     h_c_l_JESdown_opt[is]->Add(h_l_JESdown_opt[is]);
	     h_c_l_JESdown_opt[is]->Scale(kScale_c_l);
	     std::string hname_b_cfromg_c_l_JESdown_opt = hname_b+"_cfromg_c_l_opt_"+sysName[is]+"down";
	     h_b_cfromg_c_l_JESdown_opt[is] = (TH1F*)h_b_cfromg_JESdown_opt[is]->Clone(hname_b_cfromg_c_l_JESdown_opt.c_str());
	     h_b_cfromg_c_l_JESdown_opt[is]->Add(h_c_l_JESdown_opt[is]);
	  }	

	// TAG
	if(DEBUG)std::cout<< "CHECK I "<< std::endl;
	
	std::string hname_bfromg_tag_opt = hname_bfromg_tag+"_opt";
	TH1F *h_bfromg_tag_opt = (TH1F*)h_bfromg_tag->Rebin(nReBin,hname_bfromg_tag_opt.c_str());
	std::string hname_b_tag_opt = hname_b_tag+"_opt";
	TH1F *h_b_tag_opt = (TH1F*)h_b_tag->Rebin(nReBin,hname_b_tag_opt.c_str());
	std::string hname_cfromg_tag_opt = hname_cfromg_tag+"_opt";
	TH1F *h_cfromg_tag_opt = (TH1F*)h_cfromg_tag->Rebin(nReBin,hname_cfromg_tag_opt.c_str());
	std::string hname_c_tag_opt = hname_c_tag+"_opt";
	TH1F *h_c_tag_opt = (TH1F*)h_c_tag->Rebin(nReBin,hname_c_tag_opt.c_str());
	std::string hname_l_tag_opt = hname_l_tag+"_opt";
	TH1F *h_l_tag_opt = (TH1F*)h_l_tag->Rebin(nReBin,hname_l_tag_opt.c_str());
	
	// combine tag
	std::string hname_b_cfromg_tag_opt = hname_b_tag+"_cfromg_opt";
	TH1F *h_b_cfromg_tag_opt = (TH1F*)h_b_tag_opt->Clone(hname_b_cfromg_tag_opt.c_str());
	h_b_cfromg_tag_opt->Add(h_cfromg_tag_opt);
	h_b_cfromg_tag_opt->Scale(kScale_b_cfromg);
	std::string hname_c_l_tag_opt = hname_c_tag+"_l_opt";
	TH1F *h_c_l_tag_opt = (TH1F*)h_c_tag_opt->Clone(hname_c_l_tag_opt.c_str());
	h_c_l_tag_opt->Add(h_l_tag_opt);
	h_c_l_tag_opt->Scale(kScale_c_l);
	std::string hname_b_cfromg_c_l_tag_opt = hname_b_tag+"_cfromg_c_l_opt";
	TH1F *h_b_cfromg_c_l_tag_opt = (TH1F*)h_b_cfromg_tag_opt->Clone(hname_b_cfromg_c_l_tag_opt.c_str());
	h_b_cfromg_c_l_tag_opt->Add(h_c_l_tag_opt);

	TH1F *h_bfromg_tag_JESup_opt[100];
	TH1F *h_b_tag_JESup_opt[100];
	TH1F *h_cfromg_tag_JESup_opt[100];
	TH1F *h_c_tag_JESup_opt[100];
	TH1F *h_l_tag_JESup_opt[100];

	TH1F *h_bfromg_tag_JESdown_opt[100];
	TH1F *h_b_tag_JESdown_opt[100];
	TH1F *h_cfromg_tag_JESdown_opt[100];
	TH1F *h_c_tag_JESdown_opt[100];
	TH1F *h_l_tag_JESdown_opt[100];
	
	TH1F *h_b_cfromg_tag_JESup_opt[100];
	TH1F *h_c_l_tag_JESup_opt[100];
	TH1F *h_b_cfromg_c_l_tag_JESup_opt[100];

	TH1F *h_b_cfromg_tag_JESdown_opt[100];
	TH1F *h_c_l_tag_JESdown_opt[100];
	TH1F *h_b_cfromg_c_l_tag_JESdown_opt[100];
	if(DEBUG)std::cout<< "CHECK J "<< std::endl;
	
	for(int is=0;is<nSys;is++)
	  {
	     std::string hname_bfromg_tag_JESup_opt = hname_bfromg_tag+"_opt_"+sysName[is]+"up";
	     h_bfromg_tag_JESup_opt[is] = (TH1F*)h_bfromg_tag_JESup[is]->Rebin(nReBin,hname_bfromg_tag_JESup_opt.c_str());
	     std::string hname_b_tag_JESup_opt = hname_b_tag+"_opt_"+sysName[is]+"up";
	     h_b_tag_JESup_opt[is] = (TH1F*)h_b_tag_JESup[is]->Rebin(nReBin,hname_b_tag_JESup_opt.c_str());
	     std::string hname_cfromg_tag_JESup_opt = hname_cfromg_tag+"_opt_"+sysName[is]+"up";
	     h_cfromg_tag_JESup_opt[is] = (TH1F*)h_cfromg_tag_JESup[is]->Rebin(nReBin,hname_cfromg_tag_JESup_opt.c_str());
	     std::string hname_c_tag_JESup_opt = hname_c_tag+"_opt_"+sysName[is]+"up";
	     h_c_tag_JESup_opt[is] = (TH1F*)h_c_tag_JESup[is]->Rebin(nReBin,hname_c_tag_JESup_opt.c_str());
	     std::string hname_l_tag_JESup_opt = hname_l_tag+"_opt_"+sysName[is]+"up";
	     h_l_tag_JESup_opt[is] = (TH1F*)h_l_tag_JESup[is]->Rebin(nReBin,hname_l_tag_JESup_opt.c_str());

	     std::string hname_bfromg_tag_JESdown_opt = hname_bfromg_tag+"_opt_"+sysName[is]+"down";
	     h_bfromg_tag_JESdown_opt[is] = (TH1F*)h_bfromg_tag_JESdown[is]->Rebin(nReBin,hname_bfromg_tag_JESdown_opt.c_str());
	     std::string hname_b_tag_JESdown_opt = hname_b_tag+"_opt_"+sysName[is]+"down";
	     h_b_tag_JESdown_opt[is] = (TH1F*)h_b_tag_JESdown[is]->Rebin(nReBin,hname_b_tag_JESdown_opt.c_str());
	     std::string hname_cfromg_tag_JESdown_opt = hname_cfromg_tag+"_opt_"+sysName[is]+"down";
	     h_cfromg_tag_JESdown_opt[is] = (TH1F*)h_cfromg_tag_JESdown[is]->Rebin(nReBin,hname_cfromg_tag_JESdown_opt.c_str());
	     std::string hname_c_tag_JESdown_opt = hname_c_tag+"_opt_"+sysName[is]+"down";
	     h_c_tag_JESdown_opt[is] = (TH1F*)h_c_tag_JESdown[is]->Rebin(nReBin,hname_c_tag_JESdown_opt.c_str());
	     std::string hname_l_tag_JESdown_opt = hname_l_tag+"_opt_"+sysName[is]+"down";
	     h_l_tag_JESdown_opt[is] = (TH1F*)h_l_tag_JESdown[is]->Rebin(nReBin,hname_l_tag_JESdown_opt.c_str());
	
	     std::string hname_b_cfromg_tag_JESup_opt = hname_b_tag+"_cfromg_opt_"+sysName[is]+"up";
	     h_b_cfromg_tag_JESup_opt[is] = (TH1F*)h_b_tag_JESup_opt[is]->Clone(hname_b_cfromg_tag_JESup_opt.c_str());
	     h_b_cfromg_tag_JESup_opt[is]->Add(h_cfromg_tag_JESup_opt[is]);
	     h_b_cfromg_tag_JESup_opt[is]->Scale(kScale_b_cfromg);
	     std::string hname_c_l_tag_JESup_opt = hname_c_tag+"_l_opt_"+sysName[is]+"up";
	     h_c_l_tag_JESup_opt[is] = (TH1F*)h_c_tag_JESup_opt[is]->Clone(hname_c_l_tag_JESup_opt.c_str());
	     h_c_l_tag_JESup_opt[is]->Add(h_l_tag_JESup_opt[is]);
	     h_c_l_tag_JESup_opt[is]->Scale(kScale_c_l);
	     std::string hname_b_cfromg_c_l_tag_JESup_opt = hname_b_tag+"_cfromg_c_l_opt_"+sysName[is]+"up";
	     h_b_cfromg_c_l_tag_JESup_opt[is] = (TH1F*)h_b_cfromg_tag_JESup_opt[is]->Clone(hname_b_cfromg_c_l_tag_JESup_opt.c_str());
	     h_b_cfromg_c_l_tag_JESup_opt[is]->Add(h_c_l_tag_JESup_opt[is]);
	     
	     std::string hname_b_cfromg_tag_JESdown_opt = hname_b_tag+"_cfromg_opt_"+sysName[is]+"down";
	     h_b_cfromg_tag_JESdown_opt[is] = (TH1F*)h_b_tag_JESdown_opt[is]->Clone(hname_b_cfromg_tag_JESdown_opt.c_str());
	     h_b_cfromg_tag_JESdown_opt[is]->Add(h_cfromg_tag_JESdown_opt[is]);
	     h_b_cfromg_tag_JESdown_opt[is]->Scale(kScale_b_cfromg);
	     std::string hname_c_l_tag_JESdown_opt = hname_c_tag+"_l_opt_"+sysName[is]+"down";
	     h_c_l_tag_JESdown_opt[is] = (TH1F*)h_c_tag_JESdown_opt[is]->Clone(hname_c_l_tag_JESdown_opt.c_str());
	     h_c_l_tag_JESdown_opt[is]->Add(h_l_tag_JESdown_opt[is]);
	     h_c_l_tag_JESdown_opt[is]->Scale(kScale_c_l);
	     std::string hname_b_cfromg_c_l_tag_JESdown_opt = hname_b_tag+"_cfromg_c_l_opt_"+sysName[is]+"down";
	     h_b_cfromg_c_l_tag_JESdown_opt[is] = (TH1F*)h_b_cfromg_tag_JESdown_opt[is]->Clone(hname_b_cfromg_c_l_tag_JESdown_opt.c_str());
	     h_b_cfromg_c_l_tag_JESdown_opt[is]->Add(h_c_l_tag_JESdown_opt[is]);
	  }	
	if(DEBUG)std::cout<< "CHECK K "<< std::endl;
	
	std::string hname_bfromg_untag_opt = hname_bfromg_untag+"_opt";
	TH1F *h_bfromg_untag_opt = (TH1F*)h_bfromg_untag->Rebin(nReBin,hname_bfromg_untag_opt.c_str());
	std::string hname_b_untag_opt = hname_b_untag+"_opt";
	TH1F *h_b_untag_opt = (TH1F*)h_b_untag->Rebin(nReBin,hname_b_untag_opt.c_str());
	std::string hname_cfromg_untag_opt = hname_cfromg_untag+"_opt";
	TH1F *h_cfromg_untag_opt = (TH1F*)h_cfromg_untag->Rebin(nReBin,hname_cfromg_untag_opt.c_str());
	std::string hname_c_untag_opt = hname_c_untag+"_opt";
	TH1F *h_c_untag_opt = (TH1F*)h_c_untag->Rebin(nReBin,hname_c_untag_opt.c_str());
	std::string hname_l_untag_opt = hname_l_untag+"_opt";
	TH1F *h_l_untag_opt = (TH1F*)h_l_untag->Rebin(nReBin,hname_l_untag_opt.c_str());
	
	// combine untag
	std::string hname_b_cfromg_untag_opt = hname_b_untag+"_cfromg_opt";
	TH1F *h_b_cfromg_untag_opt = (TH1F*)h_b_untag_opt->Clone(hname_b_cfromg_untag_opt.c_str());
	h_b_cfromg_untag_opt->Add(h_cfromg_untag_opt);
	h_b_cfromg_untag_opt->Scale(kScale_b_cfromg);
	std::string hname_c_l_untag_opt = hname_c_untag+"_l_opt";
	TH1F *h_c_l_untag_opt = (TH1F*)h_c_untag_opt->Clone(hname_c_l_untag_opt.c_str());
	h_c_l_untag_opt->Add(h_l_untag_opt);
	h_c_l_untag_opt->Scale(kScale_c_l);
	std::string hname_b_cfromg_c_l_untag_opt = hname_b_untag+"_cfromg_c_l_opt";
	TH1F *h_b_cfromg_c_l_untag_opt = (TH1F*)h_b_cfromg_untag_opt->Clone(hname_b_cfromg_c_l_untag_opt.c_str());
	h_b_cfromg_c_l_untag_opt->Add(h_c_l_untag_opt);

	TH1F *h_bfromg_untag_JESup_opt[100];
	TH1F *h_b_untag_JESup_opt[100];
	TH1F *h_cfromg_untag_JESup_opt[100];
	TH1F *h_c_untag_JESup_opt[100];
	TH1F *h_l_untag_JESup_opt[100];

	TH1F *h_bfromg_untag_JESdown_opt[100];
	TH1F *h_b_untag_JESdown_opt[100];
	TH1F *h_cfromg_untag_JESdown_opt[100];
	TH1F *h_c_untag_JESdown_opt[100];
	TH1F *h_l_untag_JESdown_opt[100];
	
	TH1F *h_b_cfromg_untag_JESup_opt[100];
	TH1F *h_c_l_untag_JESup_opt[100];
	TH1F *h_b_cfromg_c_l_untag_JESup_opt[100];

	TH1F *h_b_cfromg_untag_JESdown_opt[100];
	TH1F *h_c_l_untag_JESdown_opt[100];
	TH1F *h_b_cfromg_c_l_untag_JESdown_opt[100];
	if(DEBUG)std::cout<< "CHECK L "<< std::endl;
	
	for(int is=0;is<nSys;is++)
	  {	    					
	     std::string hname_bfromg_untag_JESup_opt = hname_bfromg_untag+"_opt_"+sysName[is]+"up";
	     h_bfromg_untag_JESup_opt[is] = (TH1F*)h_bfromg_untag_JESup[is]->Rebin(nReBin,hname_bfromg_untag_JESup_opt.c_str());
	     std::string hname_b_untag_JESup_opt = hname_b_untag+"_opt_"+sysName[is]+"up";
	     h_b_untag_JESup_opt[is] = (TH1F*)h_b_untag_JESup[is]->Rebin(nReBin,hname_b_untag_JESup_opt.c_str());
	     std::string hname_cfromg_untag_JESup_opt = hname_cfromg_untag+"_opt_"+sysName[is]+"up";
	     h_cfromg_untag_JESup_opt[is] = (TH1F*)h_cfromg_untag_JESup[is]->Rebin(nReBin,hname_cfromg_untag_JESup_opt.c_str());
	     std::string hname_c_untag_JESup_opt = hname_c_untag+"_opt_"+sysName[is]+"up";
	     h_c_untag_JESup_opt[is] = (TH1F*)h_c_untag_JESup[is]->Rebin(nReBin,hname_c_untag_JESup_opt.c_str());
	     std::string hname_l_untag_JESup_opt = hname_l_untag+"_opt_"+sysName[is]+"up";
	     h_l_untag_JESup_opt[is] = (TH1F*)h_l_untag_JESup[is]->Rebin(nReBin,hname_l_untag_JESup_opt.c_str());
	     
	     std::string hname_bfromg_untag_JESdown_opt = hname_bfromg_untag+"_opt_"+sysName[is]+"down";
	     h_bfromg_untag_JESdown_opt[is] = (TH1F*)h_bfromg_untag_JESdown[is]->Rebin(nReBin,hname_bfromg_untag_JESdown_opt.c_str());
	     std::string hname_b_untag_JESdown_opt = hname_b_untag+"_opt_"+sysName[is]+"down";
	     h_b_untag_JESdown_opt[is] = (TH1F*)h_b_untag_JESdown[is]->Rebin(nReBin,hname_b_untag_JESdown_opt.c_str());
	     std::string hname_cfromg_untag_JESdown_opt = hname_cfromg_untag+"_opt_"+sysName[is]+"down";
	     h_cfromg_untag_JESdown_opt[is] = (TH1F*)h_cfromg_untag_JESdown[is]->Rebin(nReBin,hname_cfromg_untag_JESdown_opt.c_str());
	     std::string hname_c_untag_JESdown_opt = hname_c_untag+"_opt_"+sysName[is]+"down";
	     h_c_untag_JESdown_opt[is] = (TH1F*)h_c_untag_JESdown[is]->Rebin(nReBin,hname_c_untag_JESdown_opt.c_str());
	     std::string hname_l_untag_JESdown_opt = hname_l_untag+"_opt_"+sysName[is]+"down";
	     h_l_untag_JESdown_opt[is] = (TH1F*)h_l_untag_JESdown[is]->Rebin(nReBin,hname_l_untag_JESdown_opt.c_str());
	     
	     std::string hname_b_cfromg_untag_JESup_opt = hname_b_untag+"_cfromg_opt_"+sysName[is]+"up";
	     h_b_cfromg_untag_JESup_opt[is] = (TH1F*)h_b_untag_JESup_opt[is]->Clone(hname_b_cfromg_untag_JESup_opt.c_str());
	     h_b_cfromg_untag_JESup_opt[is]->Add(h_cfromg_untag_JESup_opt[is]);
	     h_b_cfromg_untag_JESup_opt[is]->Scale(kScale_b_cfromg);
	     std::string hname_c_l_untag_JESup_opt = hname_c_untag+"_l_opt_"+sysName[is]+"up";
	     h_c_l_untag_JESup_opt[is] = (TH1F*)h_c_untag_JESup_opt[is]->Clone(hname_c_l_untag_JESup_opt.c_str());
	     h_c_l_untag_JESup_opt[is]->Add(h_l_untag_JESup_opt[is]);
	     h_c_l_untag_JESup_opt[is]->Scale(kScale_c_l);
	     std::string hname_b_cfromg_c_l_untag_JESup_opt = hname_b_untag+"_cfromg_c_l_opt_"+sysName[is]+"up";
	     h_b_cfromg_c_l_untag_JESup_opt[is] = (TH1F*)h_b_cfromg_untag_JESup_opt[is]->Clone(hname_b_cfromg_c_l_untag_JESup_opt.c_str());
	     h_b_cfromg_c_l_untag_JESup_opt[is]->Add(h_c_l_untag_JESup_opt[is]);
	     
	     std::string hname_b_cfromg_untag_JESdown_opt = hname_b_untag+"_cfromg_opt_"+sysName[is]+"down";
	     h_b_cfromg_untag_JESdown_opt[is] = (TH1F*)h_b_untag_JESdown_opt[is]->Clone(hname_b_cfromg_untag_JESdown_opt.c_str());
	     h_b_cfromg_untag_JESdown_opt[is]->Add(h_cfromg_untag_JESdown_opt[is]);
	     h_b_cfromg_untag_JESdown_opt[is]->Scale(kScale_b_cfromg);
	     std::string hname_c_l_untag_JESdown_opt = hname_c_untag+"_l_opt_"+sysName[is]+"down";
	     h_c_l_untag_JESdown_opt[is] = (TH1F*)h_c_untag_JESdown_opt[is]->Clone(hname_c_l_untag_JESdown_opt.c_str());
	     h_c_l_untag_JESdown_opt[is]->Add(h_l_untag_JESdown_opt[is]);
	     h_c_l_untag_JESdown_opt[is]->Scale(kScale_c_l);
	     std::string hname_b_cfromg_c_l_untag_JESdown_opt = hname_b_untag+"_cfromg_c_l_opt_"+sysName[is]+"down";
	     h_b_cfromg_c_l_untag_JESdown_opt[is] = (TH1F*)h_b_cfromg_untag_JESdown_opt[is]->Clone(hname_b_cfromg_c_l_untag_JESdown_opt.c_str());
	     h_b_cfromg_c_l_untag_JESdown_opt[is]->Add(h_c_l_untag_JESdown_opt[is]);
	  }	
     }
	if(DEBUG)if(DEBUG)std::cout<< "CHECK M "<< std::endl;
   
   fNew->Write();
   fNew->Close();
   
}

void convert(){
	system("mkdir -v SFtemplates");
	TString fin;
	std::string fout;
	std::string kScaleStr;
/*
	{

	fin = "/afs/cern.ch/work/r/rsyarif/work/HbbTagVal/Jan12_SFCommPlots_NoTreeBTagVal/CMSSW_8_0_23/src/RecoBTag/BTagValidation/test/Mu_350_noSlimmedTrees_merged/Final_histograms_sysMerged.root";
	fout = "SFtemplates/Final_histograms_btagval_optimized_doublemu_BTagMu_QCDMuEnriched_HLTBTagMuAK8Jet300Mu5_run2016G-H_pt350";
	std::cout << "Processing to convert double-Mu-tag file ... " << fin << std::endl; 

	
	{
	double kScales[7] = {1.,1.,1.,1.,1.,1.,1.}; //nominal
	kScaleStr = "";
	convert(fin,fout,"H",kScales,kScaleStr);
	convert(fin,fout,"M1",kScales,kScaleStr);
	convert(fin,fout,"M2",kScales,kScaleStr);
	convert(fin,fout,"L",kScales,kScaleStr);
	}
	
	{
	double kScales[7] = {1.5,1.,1.,1.,1.,1.,1.};
	kScaleStr = "_b_1p5";
	convert(fin,fout,"H",kScales,kScaleStr);
	convert(fin,fout,"M1",kScales,kScaleStr);
	convert(fin,fout,"M2",kScales,kScaleStr);
	convert(fin,fout,"L",kScales,kScaleStr);
	}

	{
	double kScales[7] = {1.,1.5,1.,1.,1.,1.,1.};
	kScaleStr = "_cfromg_1p5";
	convert(fin,fout,"H",kScales,kScaleStr);
	convert(fin,fout,"M1",kScales,kScaleStr);
	convert(fin,fout,"M2",kScales,kScaleStr);
	convert(fin,fout,"L",kScales,kScaleStr);
	}

	{
	double kScales[7] = {1.,1.,1.5,1.,1.,1.,1.};
	kScaleStr = "_c_1p5";
	convert(fin,fout,"H",kScales,kScaleStr);
	convert(fin,fout,"M1",kScales,kScaleStr);
	convert(fin,fout,"M2",kScales,kScaleStr);
	convert(fin,fout,"L",kScales,kScaleStr);
	}

	{
	double kScales[7] = {1.,1.,1.,1.5,1.,1.,1.};
	kScaleStr = "_l_1p5";
	convert(fin,fout,"H",kScales,kScaleStr);
	convert(fin,fout,"M1",kScales,kScaleStr);
	convert(fin,fout,"M2",kScales,kScaleStr);
	convert(fin,fout,"L",kScales,kScaleStr);
	}

	{
	double kScales[7] = {1.,1.,1.,1.,1.5,1.,1.};
	kScaleStr = "_b_cfromg_1p5";
	convert(fin,fout,"H",kScales,kScaleStr);
	convert(fin,fout,"M1",kScales,kScaleStr);
	convert(fin,fout,"M2",kScales,kScaleStr);
	convert(fin,fout,"L",kScales,kScaleStr);
	}

	{
	double kScales[7] = {1.,1.,1.,1.,1.,1.5,1.};
	kScaleStr = "_c_l_1p5";
	convert(fin,fout,"H",kScales,kScaleStr);
	convert(fin,fout,"M1",kScales,kScaleStr);
	convert(fin,fout,"M2",kScales,kScaleStr);
	convert(fin,fout,"L",kScales,kScaleStr);
	}
	

	{
	double kScales[7] = {0.5,1.,1.,1.,1.,1.,1.};
	kScaleStr = "_b_0p5";
	convert(fin,fout,"H",kScales,kScaleStr);
	convert(fin,fout,"M1",kScales,kScaleStr);
	convert(fin,fout,"M2",kScales,kScaleStr);
	convert(fin,fout,"L",kScales,kScaleStr);
	}

	{
	double kScales[7] = {1.,0.5,1.,1.,1.,1.,1.};
	kScaleStr = "_cfromg_0p5";
	convert(fin,fout,"H",kScales,kScaleStr);
	convert(fin,fout,"M1",kScales,kScaleStr);
	convert(fin,fout,"M2",kScales,kScaleStr);
	convert(fin,fout,"L",kScales,kScaleStr);
	}

	{
	double kScales[7] = {1.,1.,0.5,1.,1.,1.,1.};
	kScaleStr = "_c_0p5";
	convert(fin,fout,"H",kScales,kScaleStr);
	convert(fin,fout,"M1",kScales,kScaleStr);
	convert(fin,fout,"M2",kScales,kScaleStr);
	convert(fin,fout,"L",kScales,kScaleStr);
	}

	{
	double kScales[7] = {1.,1.,1.,0.5,1.,1.,1.};
	kScaleStr = "_l_0p5";
	convert(fin,fout,"H",kScales,kScaleStr);
	convert(fin,fout,"M1",kScales,kScaleStr);
	convert(fin,fout,"M2",kScales,kScaleStr);
	convert(fin,fout,"L",kScales,kScaleStr);
	}

	{
	double kScales[7] = {1.,1.,1.,1.,0.5,1.,1.};
	kScaleStr = "_b_cfromg_0p5";
	convert(fin,fout,"H",kScales,kScaleStr);
	convert(fin,fout,"M1",kScales,kScaleStr);
	convert(fin,fout,"M2",kScales,kScaleStr);
	convert(fin,fout,"L",kScales,kScaleStr);
	}

	{
	double kScales[7] = {1.,1.,1.,1.,1.,0.5,1.};
	kScaleStr = "_c_l_0p5";
	convert(fin,fout,"H",kScales,kScaleStr);
	convert(fin,fout,"M1",kScales,kScaleStr);
	convert(fin,fout,"M2",kScales,kScaleStr);
	convert(fin,fout,"L",kScales,kScaleStr);
	}
	
	}

	{

	fin = "/afs/cern.ch/work/r/rsyarif/work/HbbTagVal/Jan12_SFCommPlots_NoTreeBTagVal/CMSSW_8_0_23/src/RecoBTag/BTagValidation/test/Mu_250_noSlimmedTrees_merged/Final_histograms_sysMerged.root";
	fout = "SFtemplates/Final_histograms_btagval_optimized_doublemu_BTagMu_QCDMuEnriched_HLTBTagMuDiJet170Mu5_run2016G-H_pt250";
	std::cout << "Processing to convert double-Mu-tag file ... " << fin << std::endl; 

	
	{
	double kScales[7] = {1.,1.,1.,1.,1.,1.,1.}; //nominal
	kScaleStr = "";
	convert(fin,fout,"H",kScales,kScaleStr);
	convert(fin,fout,"M1",kScales,kScaleStr);
	convert(fin,fout,"M2",kScales,kScaleStr);
	convert(fin,fout,"L",kScales,kScaleStr);
	}
	
	{
	double kScales[7] = {1.5,1.,1.,1.,1.,1.,1.};
	kScaleStr = "_b_1p5";
	convert(fin,fout,"H",kScales,kScaleStr);
	convert(fin,fout,"M1",kScales,kScaleStr);
	convert(fin,fout,"M2",kScales,kScaleStr);
	convert(fin,fout,"L",kScales,kScaleStr);
	}

	{
	double kScales[7] = {1.,1.5,1.,1.,1.,1.,1.};
	kScaleStr = "_cfromg_1p5";
	convert(fin,fout,"H",kScales,kScaleStr);
	convert(fin,fout,"M1",kScales,kScaleStr);
	convert(fin,fout,"M2",kScales,kScaleStr);
	convert(fin,fout,"L",kScales,kScaleStr);
	}

	{
	double kScales[7] = {1.,1.,1.5,1.,1.,1.,1.};
	kScaleStr = "_c_1p5";
	convert(fin,fout,"H",kScales,kScaleStr);
	convert(fin,fout,"M1",kScales,kScaleStr);
	convert(fin,fout,"M2",kScales,kScaleStr);
	convert(fin,fout,"L",kScales,kScaleStr);
	}

	{
	double kScales[7] = {1.,1.,1.,1.5,1.,1.,1.};
	kScaleStr = "_l_1p5";
	convert(fin,fout,"H",kScales,kScaleStr);
	convert(fin,fout,"M1",kScales,kScaleStr);
	convert(fin,fout,"M2",kScales,kScaleStr);
	convert(fin,fout,"L",kScales,kScaleStr);
	}

	{
	double kScales[7] = {1.,1.,1.,1.,1.5,1.,1.};
	kScaleStr = "_b_cfromg_1p5";
	convert(fin,fout,"H",kScales,kScaleStr);
	convert(fin,fout,"M1",kScales,kScaleStr);
	convert(fin,fout,"M2",kScales,kScaleStr);
	convert(fin,fout,"L",kScales,kScaleStr);
	}

	{
	double kScales[7] = {1.,1.,1.,1.,1.,1.5,1.};
	kScaleStr = "_c_l_1p5";
	convert(fin,fout,"H",kScales,kScaleStr);
	convert(fin,fout,"M1",kScales,kScaleStr);
	convert(fin,fout,"M2",kScales,kScaleStr);
	convert(fin,fout,"L",kScales,kScaleStr);
	}
	

	{
	double kScales[7] = {0.5,1.,1.,1.,1.,1.,1.};
	kScaleStr = "_b_0p5";
	convert(fin,fout,"H",kScales,kScaleStr);
	convert(fin,fout,"M1",kScales,kScaleStr);
	convert(fin,fout,"M2",kScales,kScaleStr);
	convert(fin,fout,"L",kScales,kScaleStr);
	}

	{
	double kScales[7] = {1.,0.5,1.,1.,1.,1.,1.};
	kScaleStr = "_cfromg_0p5";
	convert(fin,fout,"H",kScales,kScaleStr);
	convert(fin,fout,"M1",kScales,kScaleStr);
	convert(fin,fout,"M2",kScales,kScaleStr);
	convert(fin,fout,"L",kScales,kScaleStr);
	}

	{
	double kScales[7] = {1.,1.,0.5,1.,1.,1.,1.};
	kScaleStr = "_c_0p5";
	convert(fin,fout,"H",kScales,kScaleStr);
	convert(fin,fout,"M1",kScales,kScaleStr);
	convert(fin,fout,"M2",kScales,kScaleStr);
	convert(fin,fout,"L",kScales,kScaleStr);
	}

	{
	double kScales[7] = {1.,1.,1.,0.5,1.,1.,1.};
	kScaleStr = "_l_0p5";
	convert(fin,fout,"H",kScales,kScaleStr);
	convert(fin,fout,"M1",kScales,kScaleStr);
	convert(fin,fout,"M2",kScales,kScaleStr);
	convert(fin,fout,"L",kScales,kScaleStr);
	}

	{
	double kScales[7] = {1.,1.,1.,1.,0.5,1.,1.};
	kScaleStr = "_b_cfromg_0p5";
	convert(fin,fout,"H",kScales,kScaleStr);
	convert(fin,fout,"M1",kScales,kScaleStr);
	convert(fin,fout,"M2",kScales,kScaleStr);
	convert(fin,fout,"L",kScales,kScaleStr);
	}

	{
	double kScales[7] = {1.,1.,1.,1.,1.,0.5,1.};
	kScaleStr = "_c_l_0p5";
	convert(fin,fout,"H",kScales,kScaleStr);
	convert(fin,fout,"M1",kScales,kScaleStr);
	convert(fin,fout,"M2",kScales,kScaleStr);
	convert(fin,fout,"L",kScales,kScaleStr);
	}
	
	}
*/
	{

	fin = "/afs/cern.ch/work/r/rsyarif/work/HbbTagVal/Jan12_SFCommPlots_NoTreeBTagVal/CMSSW_8_0_23/src/RecoBTag/BTagValidation/test/Mu_350_noSlimmedTrees_dataJPcalib_merged/Final_histograms_sysMerged.root";
	fout = "SFtemplates/Final_histograms_btagval_optimized_doublemu_BTagMu_QCDMuEnriched_HLTBTagMuAK8Jet300Mu5_run2016G-H_pt350_dataJPcalib";
	std::cout << "Processing to convert double-Mu-tag file ... " << fin << std::endl; 

	
	{
	double kScales[7] = {1.,1.,1.,1.,1.,1.,1.}; //nominal
	kScaleStr = "";
	convert(fin,fout,"H",kScales,kScaleStr);
	convert(fin,fout,"M1",kScales,kScaleStr);
	convert(fin,fout,"M2",kScales,kScaleStr);
	convert(fin,fout,"L",kScales,kScaleStr);
	}
	
	{
	double kScales[7] = {1.5,1.,1.,1.,1.,1.,1.};
	kScaleStr = "_b_1p5";
	convert(fin,fout,"H",kScales,kScaleStr);
	convert(fin,fout,"M1",kScales,kScaleStr);
	convert(fin,fout,"M2",kScales,kScaleStr);
	convert(fin,fout,"L",kScales,kScaleStr);
	}

	{
	double kScales[7] = {1.,1.5,1.,1.,1.,1.,1.};
	kScaleStr = "_cfromg_1p5";
	convert(fin,fout,"H",kScales,kScaleStr);
	convert(fin,fout,"M1",kScales,kScaleStr);
	convert(fin,fout,"M2",kScales,kScaleStr);
	convert(fin,fout,"L",kScales,kScaleStr);
	}

	{
	double kScales[7] = {1.,1.,1.5,1.,1.,1.,1.};
	kScaleStr = "_c_1p5";
	convert(fin,fout,"H",kScales,kScaleStr);
	convert(fin,fout,"M1",kScales,kScaleStr);
	convert(fin,fout,"M2",kScales,kScaleStr);
	convert(fin,fout,"L",kScales,kScaleStr);
	}

	{
	double kScales[7] = {1.,1.,1.,1.5,1.,1.,1.};
	kScaleStr = "_l_1p5";
	convert(fin,fout,"H",kScales,kScaleStr);
	convert(fin,fout,"M1",kScales,kScaleStr);
	convert(fin,fout,"M2",kScales,kScaleStr);
	convert(fin,fout,"L",kScales,kScaleStr);
	}

	{
	double kScales[7] = {1.,1.,1.,1.,1.5,1.,1.};
	kScaleStr = "_b_cfromg_1p5";
	convert(fin,fout,"H",kScales,kScaleStr);
	convert(fin,fout,"M1",kScales,kScaleStr);
	convert(fin,fout,"M2",kScales,kScaleStr);
	convert(fin,fout,"L",kScales,kScaleStr);
	}

	{
	double kScales[7] = {1.,1.,1.,1.,1.,1.5,1.};
	kScaleStr = "_c_l_1p5";
	convert(fin,fout,"H",kScales,kScaleStr);
	convert(fin,fout,"M1",kScales,kScaleStr);
	convert(fin,fout,"M2",kScales,kScaleStr);
	convert(fin,fout,"L",kScales,kScaleStr);
	}
	

	{
	double kScales[7] = {0.5,1.,1.,1.,1.,1.,1.};
	kScaleStr = "_b_0p5";
	convert(fin,fout,"H",kScales,kScaleStr);
	convert(fin,fout,"M1",kScales,kScaleStr);
	convert(fin,fout,"M2",kScales,kScaleStr);
	convert(fin,fout,"L",kScales,kScaleStr);
	}

	{
	double kScales[7] = {1.,0.5,1.,1.,1.,1.,1.};
	kScaleStr = "_cfromg_0p5";
	convert(fin,fout,"H",kScales,kScaleStr);
	convert(fin,fout,"M1",kScales,kScaleStr);
	convert(fin,fout,"M2",kScales,kScaleStr);
	convert(fin,fout,"L",kScales,kScaleStr);
	}

	{
	double kScales[7] = {1.,1.,0.5,1.,1.,1.,1.};
	kScaleStr = "_c_0p5";
	convert(fin,fout,"H",kScales,kScaleStr);
	convert(fin,fout,"M1",kScales,kScaleStr);
	convert(fin,fout,"M2",kScales,kScaleStr);
	convert(fin,fout,"L",kScales,kScaleStr);
	}

	{
	double kScales[7] = {1.,1.,1.,0.5,1.,1.,1.};
	kScaleStr = "_l_0p5";
	convert(fin,fout,"H",kScales,kScaleStr);
	convert(fin,fout,"M1",kScales,kScaleStr);
	convert(fin,fout,"M2",kScales,kScaleStr);
	convert(fin,fout,"L",kScales,kScaleStr);
	}

	{
	double kScales[7] = {1.,1.,1.,1.,0.5,1.,1.};
	kScaleStr = "_b_cfromg_0p5";
	convert(fin,fout,"H",kScales,kScaleStr);
	convert(fin,fout,"M1",kScales,kScaleStr);
	convert(fin,fout,"M2",kScales,kScaleStr);
	convert(fin,fout,"L",kScales,kScaleStr);
	}

	{
	double kScales[7] = {1.,1.,1.,1.,1.,0.5,1.};
	kScaleStr = "_c_l_0p5";
	convert(fin,fout,"H",kScales,kScaleStr);
	convert(fin,fout,"M1",kScales,kScaleStr);
	convert(fin,fout,"M2",kScales,kScaleStr);
	convert(fin,fout,"L",kScales,kScaleStr);
	}
	
	}

	{

	fin = "/afs/cern.ch/work/r/rsyarif/work/HbbTagVal/Jan12_SFCommPlots_NoTreeBTagVal/CMSSW_8_0_23/src/RecoBTag/BTagValidation/test/Mu_250_noSlimmedTrees_dataJPcalib_merged/Final_histograms_sysMerged.root";
	fout = "SFtemplates/Final_histograms_btagval_optimized_doublemu_BTagMu_QCDMuEnriched_HLTBTagMuDiJet170Mu5_run2016G-H_pt250_dataJPcalib";
	std::cout << "Processing to convert double-Mu-tag file ... " << fin << std::endl; 

	
	{
	double kScales[7] = {1.,1.,1.,1.,1.,1.,1.}; //nominal
	kScaleStr = "";
	convert(fin,fout,"H",kScales,kScaleStr);
	convert(fin,fout,"M1",kScales,kScaleStr);
	convert(fin,fout,"M2",kScales,kScaleStr);
	convert(fin,fout,"L",kScales,kScaleStr);
	}
	
	{
	double kScales[7] = {1.5,1.,1.,1.,1.,1.,1.};
	kScaleStr = "_b_1p5";
	convert(fin,fout,"H",kScales,kScaleStr);
	convert(fin,fout,"M1",kScales,kScaleStr);
	convert(fin,fout,"M2",kScales,kScaleStr);
	convert(fin,fout,"L",kScales,kScaleStr);
	}

	{
	double kScales[7] = {1.,1.5,1.,1.,1.,1.,1.};
	kScaleStr = "_cfromg_1p5";
	convert(fin,fout,"H",kScales,kScaleStr);
	convert(fin,fout,"M1",kScales,kScaleStr);
	convert(fin,fout,"M2",kScales,kScaleStr);
	convert(fin,fout,"L",kScales,kScaleStr);
	}

	{
	double kScales[7] = {1.,1.,1.5,1.,1.,1.,1.};
	kScaleStr = "_c_1p5";
	convert(fin,fout,"H",kScales,kScaleStr);
	convert(fin,fout,"M1",kScales,kScaleStr);
	convert(fin,fout,"M2",kScales,kScaleStr);
	convert(fin,fout,"L",kScales,kScaleStr);
	}

	{
	double kScales[7] = {1.,1.,1.,1.5,1.,1.,1.};
	kScaleStr = "_l_1p5";
	convert(fin,fout,"H",kScales,kScaleStr);
	convert(fin,fout,"M1",kScales,kScaleStr);
	convert(fin,fout,"M2",kScales,kScaleStr);
	convert(fin,fout,"L",kScales,kScaleStr);
	}

	{
	double kScales[7] = {1.,1.,1.,1.,1.5,1.,1.};
	kScaleStr = "_b_cfromg_1p5";
	convert(fin,fout,"H",kScales,kScaleStr);
	convert(fin,fout,"M1",kScales,kScaleStr);
	convert(fin,fout,"M2",kScales,kScaleStr);
	convert(fin,fout,"L",kScales,kScaleStr);
	}

	{
	double kScales[7] = {1.,1.,1.,1.,1.,1.5,1.};
	kScaleStr = "_c_l_1p5";
	convert(fin,fout,"H",kScales,kScaleStr);
	convert(fin,fout,"M1",kScales,kScaleStr);
	convert(fin,fout,"M2",kScales,kScaleStr);
	convert(fin,fout,"L",kScales,kScaleStr);
	}
	

	{
	double kScales[7] = {0.5,1.,1.,1.,1.,1.,1.};
	kScaleStr = "_b_0p5";
	convert(fin,fout,"H",kScales,kScaleStr);
	convert(fin,fout,"M1",kScales,kScaleStr);
	convert(fin,fout,"M2",kScales,kScaleStr);
	convert(fin,fout,"L",kScales,kScaleStr);
	}

	{
	double kScales[7] = {1.,0.5,1.,1.,1.,1.,1.};
	kScaleStr = "_cfromg_0p5";
	convert(fin,fout,"H",kScales,kScaleStr);
	convert(fin,fout,"M1",kScales,kScaleStr);
	convert(fin,fout,"M2",kScales,kScaleStr);
	convert(fin,fout,"L",kScales,kScaleStr);
	}

	{
	double kScales[7] = {1.,1.,0.5,1.,1.,1.,1.};
	kScaleStr = "_c_0p5";
	convert(fin,fout,"H",kScales,kScaleStr);
	convert(fin,fout,"M1",kScales,kScaleStr);
	convert(fin,fout,"M2",kScales,kScaleStr);
	convert(fin,fout,"L",kScales,kScaleStr);
	}

	{
	double kScales[7] = {1.,1.,1.,0.5,1.,1.,1.};
	kScaleStr = "_l_0p5";
	convert(fin,fout,"H",kScales,kScaleStr);
	convert(fin,fout,"M1",kScales,kScaleStr);
	convert(fin,fout,"M2",kScales,kScaleStr);
	convert(fin,fout,"L",kScales,kScaleStr);
	}

	{
	double kScales[7] = {1.,1.,1.,1.,0.5,1.,1.};
	kScaleStr = "_b_cfromg_0p5";
	convert(fin,fout,"H",kScales,kScaleStr);
	convert(fin,fout,"M1",kScales,kScaleStr);
	convert(fin,fout,"M2",kScales,kScaleStr);
	convert(fin,fout,"L",kScales,kScaleStr);
	}

	{
	double kScales[7] = {1.,1.,1.,1.,1.,0.5,1.};
	kScaleStr = "_c_l_0p5";
	convert(fin,fout,"H",kScales,kScaleStr);
	convert(fin,fout,"M1",kScales,kScaleStr);
	convert(fin,fout,"M2",kScales,kScaleStr);
	convert(fin,fout,"L",kScales,kScaleStr);
	}
	
	}

	{

	fin = "/afs/cern.ch/work/r/rsyarif/work/HbbTagVal/Jan12_SFCommPlots_NoTreeBTagVal/CMSSW_8_0_23/src/RecoBTag/BTagValidation/test/Mu_350_noSlimmedTrees_run2016BtoF_merged/Final_histograms_sysMerged.root";
	fout = "SFtemplates/Final_histograms_btagval_optimized_doublemu_BTagMu_QCDMuEnriched_HLTBTagMuAK8Jet300Mu5_run2016B-F_pt350";
	std::cout << "Processing to convert double-Mu-tag file ... " << fin << std::endl; 

	
	{
	double kScales[7] = {1.,1.,1.,1.,1.,1.,1.}; //nominal
	kScaleStr = "";
	convert(fin,fout,"H",kScales,kScaleStr);
	convert(fin,fout,"M1",kScales,kScaleStr);
	convert(fin,fout,"M2",kScales,kScaleStr);
	convert(fin,fout,"L",kScales,kScaleStr);
	}
	
	{
	double kScales[7] = {1.5,1.,1.,1.,1.,1.,1.};
	kScaleStr = "_b_1p5";
	convert(fin,fout,"H",kScales,kScaleStr);
	convert(fin,fout,"M1",kScales,kScaleStr);
	convert(fin,fout,"M2",kScales,kScaleStr);
	convert(fin,fout,"L",kScales,kScaleStr);
	}

	{
	double kScales[7] = {1.,1.5,1.,1.,1.,1.,1.};
	kScaleStr = "_cfromg_1p5";
	convert(fin,fout,"H",kScales,kScaleStr);
	convert(fin,fout,"M1",kScales,kScaleStr);
	convert(fin,fout,"M2",kScales,kScaleStr);
	convert(fin,fout,"L",kScales,kScaleStr);
	}

	{
	double kScales[7] = {1.,1.,1.5,1.,1.,1.,1.};
	kScaleStr = "_c_1p5";
	convert(fin,fout,"H",kScales,kScaleStr);
	convert(fin,fout,"M1",kScales,kScaleStr);
	convert(fin,fout,"M2",kScales,kScaleStr);
	convert(fin,fout,"L",kScales,kScaleStr);
	}

	{
	double kScales[7] = {1.,1.,1.,1.5,1.,1.,1.};
	kScaleStr = "_l_1p5";
	convert(fin,fout,"H",kScales,kScaleStr);
	convert(fin,fout,"M1",kScales,kScaleStr);
	convert(fin,fout,"M2",kScales,kScaleStr);
	convert(fin,fout,"L",kScales,kScaleStr);
	}

	{
	double kScales[7] = {1.,1.,1.,1.,1.5,1.,1.};
	kScaleStr = "_b_cfromg_1p5";
	convert(fin,fout,"H",kScales,kScaleStr);
	convert(fin,fout,"M1",kScales,kScaleStr);
	convert(fin,fout,"M2",kScales,kScaleStr);
	convert(fin,fout,"L",kScales,kScaleStr);
	}

	{
	double kScales[7] = {1.,1.,1.,1.,1.,1.5,1.};
	kScaleStr = "_c_l_1p5";
	convert(fin,fout,"H",kScales,kScaleStr);
	convert(fin,fout,"M1",kScales,kScaleStr);
	convert(fin,fout,"M2",kScales,kScaleStr);
	convert(fin,fout,"L",kScales,kScaleStr);
	}
	

	{
	double kScales[7] = {0.5,1.,1.,1.,1.,1.,1.};
	kScaleStr = "_b_0p5";
	convert(fin,fout,"H",kScales,kScaleStr);
	convert(fin,fout,"M1",kScales,kScaleStr);
	convert(fin,fout,"M2",kScales,kScaleStr);
	convert(fin,fout,"L",kScales,kScaleStr);
	}

	{
	double kScales[7] = {1.,0.5,1.,1.,1.,1.,1.};
	kScaleStr = "_cfromg_0p5";
	convert(fin,fout,"H",kScales,kScaleStr);
	convert(fin,fout,"M1",kScales,kScaleStr);
	convert(fin,fout,"M2",kScales,kScaleStr);
	convert(fin,fout,"L",kScales,kScaleStr);
	}

	{
	double kScales[7] = {1.,1.,0.5,1.,1.,1.,1.};
	kScaleStr = "_c_0p5";
	convert(fin,fout,"H",kScales,kScaleStr);
	convert(fin,fout,"M1",kScales,kScaleStr);
	convert(fin,fout,"M2",kScales,kScaleStr);
	convert(fin,fout,"L",kScales,kScaleStr);
	}

	{
	double kScales[7] = {1.,1.,1.,0.5,1.,1.,1.};
	kScaleStr = "_l_0p5";
	convert(fin,fout,"H",kScales,kScaleStr);
	convert(fin,fout,"M1",kScales,kScaleStr);
	convert(fin,fout,"M2",kScales,kScaleStr);
	convert(fin,fout,"L",kScales,kScaleStr);
	}

	{
	double kScales[7] = {1.,1.,1.,1.,0.5,1.,1.};
	kScaleStr = "_b_cfromg_0p5";
	convert(fin,fout,"H",kScales,kScaleStr);
	convert(fin,fout,"M1",kScales,kScaleStr);
	convert(fin,fout,"M2",kScales,kScaleStr);
	convert(fin,fout,"L",kScales,kScaleStr);
	}

	{
	double kScales[7] = {1.,1.,1.,1.,1.,0.5,1.};
	kScaleStr = "_c_l_0p5";
	convert(fin,fout,"H",kScales,kScaleStr);
	convert(fin,fout,"M1",kScales,kScaleStr);
	convert(fin,fout,"M2",kScales,kScaleStr);
	convert(fin,fout,"L",kScales,kScaleStr);
	}
	
	}

	{

	fin = "/afs/cern.ch/work/r/rsyarif/work/HbbTagVal/Jan12_SFCommPlots_NoTreeBTagVal/CMSSW_8_0_23/src/RecoBTag/BTagValidation/test/Mu_250_noSlimmedTrees_run2016BtoF_merged/Final_histograms_sysMerged.root";
	fout = "SFtemplates/Final_histograms_btagval_optimized_doublemu_BTagMu_QCDMuEnriched_HLTBTagMuDiJet170Mu5_run2016B-F_pt250";
	std::cout << "Processing to convert double-Mu-tag file ... " << fin << std::endl; 

	
	{
	double kScales[7] = {1.,1.,1.,1.,1.,1.,1.}; //nominal
	kScaleStr = "";
	convert(fin,fout,"H",kScales,kScaleStr);
	convert(fin,fout,"M1",kScales,kScaleStr);
	convert(fin,fout,"M2",kScales,kScaleStr);
	convert(fin,fout,"L",kScales,kScaleStr);
	}
	
	{
	double kScales[7] = {1.5,1.,1.,1.,1.,1.,1.};
	kScaleStr = "_b_1p5";
	convert(fin,fout,"H",kScales,kScaleStr);
	convert(fin,fout,"M1",kScales,kScaleStr);
	convert(fin,fout,"M2",kScales,kScaleStr);
	convert(fin,fout,"L",kScales,kScaleStr);
	}

	{
	double kScales[7] = {1.,1.5,1.,1.,1.,1.,1.};
	kScaleStr = "_cfromg_1p5";
	convert(fin,fout,"H",kScales,kScaleStr);
	convert(fin,fout,"M1",kScales,kScaleStr);
	convert(fin,fout,"M2",kScales,kScaleStr);
	convert(fin,fout,"L",kScales,kScaleStr);
	}

	{
	double kScales[7] = {1.,1.,1.5,1.,1.,1.,1.};
	kScaleStr = "_c_1p5";
	convert(fin,fout,"H",kScales,kScaleStr);
	convert(fin,fout,"M1",kScales,kScaleStr);
	convert(fin,fout,"M2",kScales,kScaleStr);
	convert(fin,fout,"L",kScales,kScaleStr);
	}

	{
	double kScales[7] = {1.,1.,1.,1.5,1.,1.,1.};
	kScaleStr = "_l_1p5";
	convert(fin,fout,"H",kScales,kScaleStr);
	convert(fin,fout,"M1",kScales,kScaleStr);
	convert(fin,fout,"M2",kScales,kScaleStr);
	convert(fin,fout,"L",kScales,kScaleStr);
	}

	{
	double kScales[7] = {1.,1.,1.,1.,1.5,1.,1.};
	kScaleStr = "_b_cfromg_1p5";
	convert(fin,fout,"H",kScales,kScaleStr);
	convert(fin,fout,"M1",kScales,kScaleStr);
	convert(fin,fout,"M2",kScales,kScaleStr);
	convert(fin,fout,"L",kScales,kScaleStr);
	}

	{
	double kScales[7] = {1.,1.,1.,1.,1.,1.5,1.};
	kScaleStr = "_c_l_1p5";
	convert(fin,fout,"H",kScales,kScaleStr);
	convert(fin,fout,"M1",kScales,kScaleStr);
	convert(fin,fout,"M2",kScales,kScaleStr);
	convert(fin,fout,"L",kScales,kScaleStr);
	}
	

	{
	double kScales[7] = {0.5,1.,1.,1.,1.,1.,1.};
	kScaleStr = "_b_0p5";
	convert(fin,fout,"H",kScales,kScaleStr);
	convert(fin,fout,"M1",kScales,kScaleStr);
	convert(fin,fout,"M2",kScales,kScaleStr);
	convert(fin,fout,"L",kScales,kScaleStr);
	}

	{
	double kScales[7] = {1.,0.5,1.,1.,1.,1.,1.};
	kScaleStr = "_cfromg_0p5";
	convert(fin,fout,"H",kScales,kScaleStr);
	convert(fin,fout,"M1",kScales,kScaleStr);
	convert(fin,fout,"M2",kScales,kScaleStr);
	convert(fin,fout,"L",kScales,kScaleStr);
	}

	{
	double kScales[7] = {1.,1.,0.5,1.,1.,1.,1.};
	kScaleStr = "_c_0p5";
	convert(fin,fout,"H",kScales,kScaleStr);
	convert(fin,fout,"M1",kScales,kScaleStr);
	convert(fin,fout,"M2",kScales,kScaleStr);
	convert(fin,fout,"L",kScales,kScaleStr);
	}

	{
	double kScales[7] = {1.,1.,1.,0.5,1.,1.,1.};
	kScaleStr = "_l_0p5";
	convert(fin,fout,"H",kScales,kScaleStr);
	convert(fin,fout,"M1",kScales,kScaleStr);
	convert(fin,fout,"M2",kScales,kScaleStr);
	convert(fin,fout,"L",kScales,kScaleStr);
	}

	{
	double kScales[7] = {1.,1.,1.,1.,0.5,1.,1.};
	kScaleStr = "_b_cfromg_0p5";
	convert(fin,fout,"H",kScales,kScaleStr);
	convert(fin,fout,"M1",kScales,kScaleStr);
	convert(fin,fout,"M2",kScales,kScaleStr);
	convert(fin,fout,"L",kScales,kScaleStr);
	}

	{
	double kScales[7] = {1.,1.,1.,1.,1.,0.5,1.};
	kScaleStr = "_c_l_0p5";
	convert(fin,fout,"H",kScales,kScaleStr);
	convert(fin,fout,"M1",kScales,kScaleStr);
	convert(fin,fout,"M2",kScales,kScaleStr);
	convert(fin,fout,"L",kScales,kScaleStr);
	}
	
	}

	std::cout << "Done. " << std::endl; 
	std::cout << "" << std::endl; 
	
	
	gApplication->Terminate();

}