#include "TFile.h"
#include "TString.h"
#include "TH1F.h"

using namespace std;

void Rebin_postConvert(TString fin, TString WP, TString pt1low,TString pt1high, TString pt2low, TString pt2high){
		
	system("cp -v SFtemplates/"+fin+".root SFtemplates/"+fin+"_ADDBINNING.root");

	TFile *fout = TFile::Open("SFtemplates/"+fin+"_ADDBINNING.root","UPDATE");
	fout->cd();	
	
	try{
		TH1D *test = (TH1D*)fout->Get("UNWEIGHTED__DATA__FatJet_JP_DoubleBHpass_pt"+pt1low+"to"+pt1high+"_data_opt");
		}
	catch(exception& e){
		cout << "Something is wrong. Check if those pt bins exist! " << e.what() << endl;
		return;
		}

	TH1D *h1 = (TH1D*)fout->Get("UNWEIGHTED__DATA__FatJet_JP_DoubleBHpass_pt"+pt1low+"to"+pt1high+"_data_opt");
	TH1D *h1_ = (TH1D*)fout->Get("UNWEIGHTED__DATA__FatJet_JP_DoubleBHpass_pt"+pt2low+"to"+pt2high+"_data_opt");
	h1->Add(h1_);
	h1->SetName("UNWEIGHTED__DATA__FatJet_JP_DoubleBHpass_pt"+pt1low+"to"+pt2high+"_data_opt");
	h1->SetTitle("");
	h1->Write();
	cout << "	Creating pt"+pt1low+"to"+pt2high+" for :	pass data" << endl;	

	TH1D *h2 = (TH1D*)fout->Get("UNWEIGHTED__DATA__FatJet_JP_DoubleBHfail_pt"+pt1low+"to"+pt1high+"_data_opt");
	TH1D *h2_ = (TH1D*)fout->Get("UNWEIGHTED__DATA__FatJet_JP_DoubleBHfail_pt"+pt2low+"to"+pt2high+"_data_opt");
	h2->Add(h2_);
	h2->SetName("UNWEIGHTED__DATA__FatJet_JP_DoubleBHfail_pt"+pt1low+"to"+pt2high+"_data_opt");
	h2->SetTitle("");
	h2->Write();

	TH1D *h3 = (TH1D*)fout->Get("UNWEIGHTED__DATA__FatJet_JP_all_pt"+pt1low+"to"+pt1high+"_data_opt");
	TH1D *h3_ = (TH1D*)fout->Get("UNWEIGHTED__DATA__FatJet_JP_all_pt"+pt2low+"to"+pt2high+"_data_opt");
	h3->Add(h3_);
	h3->SetName("UNWEIGHTED__DATA__FatJet_JP_all_pt"+pt1low+"to"+pt2high+"_data_opt");
	h3->SetTitle("");
	h3->Write();

	vector<TH1D*> h;
	vector<TH1D*> h_;	
	cout << "	Adding pt"+pt1low+"to"+pt2high+" for :	fail data" << endl;	

	vector<TString> sys = {"","_JES","_NTRACKS","_BFRAG","_CFRAG","_CD","_K0L","_PU"};
	vector<TString> ud = {"up","down"};
	vector<TString> flavor = {"bfromg","b","cfromg","c","l","b_cfromg","c_l","b_cfromg_c_l"};
	vector<TString> tag = {"all","DoubleB"+WP+"pass","DoubleB"+WP+"fail"};
	
	int i = 0;
	for(int iFl = 0; iFl < flavor.size() ; iFl++){
			
		for(int iSys = 0; iSys < sys.size() ; iSys++){

			for(int iUD =0; iUD < ud.size() ; iUD++){

				for(int itag =0; itag < tag.size() ; itag++){
					if(sys.at(iSys)==""){

						cout << "	Adding pt350to2000 for :	" << tag.at(itag)<< " " << flavor.at(iFl)<< " " << sys.at(iSys) << endl;	
	
						h.push_back( (TH1D*)fout->Get("UNWEIGHTED__QCD__FatJet_JP_"+tag.at(itag)+"_pt"+pt1low+"to"+pt1high+"_"+flavor.at(iFl)+"_opt"+sys.at(iSys) ) );
						h_.push_back( (TH1D*)fout->Get("UNWEIGHTED__QCD__FatJet_JP_"+tag.at(itag)+"_pt"+pt2low+"to"+pt2high+"_"+flavor.at(iFl)+"_opt"+sys.at(iSys) ) );
						h.at(i)->Add(h_.at(i));
						h.at(i)->SetName("UNWEIGHTED__QCD__FatJet_JP_"+tag.at(itag)+"_pt"+pt1low+"to"+pt2high+"_"+flavor.at(iFl)+"_opt"+sys.at(iSys) ) ;
						h.at(i)->SetTitle("");
						h.at(i)->Write();
						i++;
					
					}
					else{

						cout << "	Adding pt350to2000 for :	" << tag.at(itag)<< " " << flavor.at(iFl)<< " " << sys.at(iSys)<< " " << ud.at(iUD) << endl;	
	
						h.push_back( (TH1D*)fout->Get("UNWEIGHTED__QCD__FatJet_JP_"+tag.at(itag)+"_pt"+pt1low+"to"+pt1high+"_"+flavor.at(iFl)+"_opt"+sys.at(iSys)+ud.at(iUD) ) );
						h_.push_back( (TH1D*)fout->Get("UNWEIGHTED__QCD__FatJet_JP_"+tag.at(itag)+"_pt"+pt2low+"to"+pt2high+"_"+flavor.at(iFl)+"_opt"+sys.at(iSys)+ud.at(iUD) ) );
						h.at(i)->Add(h_.at(i));
						h.at(i)->SetName("UNWEIGHTED__QCD__FatJet_JP_"+tag.at(itag)+"_pt"+pt1low+"to"+pt2high+"_"+flavor.at(iFl)+"_opt"+sys.at(iSys)+ud.at(iUD) ) ;
						h.at(i)->SetTitle("");
						h.at(i)->Write();
						i++;
					}
					
					
				}
		
			}
		}
	}
	
	fout->Close();
	
// 	fin->Close();

}

void Rebin_postConvert(){

	TString WP = 'H';

	vector<TString> f={
		"Final_histograms_btagval_optimized_doublemu_BTagMu_QCDMuEnriched_HLTBTagMuAK8Jet300Mu5_OR_HLTBTagMuJet300Mu5_run2016B-H_pt350_DoubleB"+WP,
		"Final_histograms_btagval_optimized_doublemu_BTagMu_QCDMuEnriched_HLTBTagMuAK8Jet300Mu5_OR_HLTBTagMuJet300Mu5_run2016B-H_pt350_DoubleB"+WP+"_b_0p5",
		"Final_histograms_btagval_optimized_doublemu_BTagMu_QCDMuEnriched_HLTBTagMuAK8Jet300Mu5_OR_HLTBTagMuJet300Mu5_run2016B-H_pt350_DoubleB"+WP+"_b_1p5",
		"Final_histograms_btagval_optimized_doublemu_BTagMu_QCDMuEnriched_HLTBTagMuAK8Jet300Mu5_OR_HLTBTagMuJet300Mu5_run2016B-H_pt350_DoubleB"+WP+"_b_cfromg_0p5",
		"Final_histograms_btagval_optimized_doublemu_BTagMu_QCDMuEnriched_HLTBTagMuAK8Jet300Mu5_OR_HLTBTagMuJet300Mu5_run2016B-H_pt350_DoubleB"+WP+"_b_cfromg_1p5",
		"Final_histograms_btagval_optimized_doublemu_BTagMu_QCDMuEnriched_HLTBTagMuAK8Jet300Mu5_OR_HLTBTagMuJet300Mu5_run2016B-H_pt350_DoubleB"+WP+"_c_0p5",
		"Final_histograms_btagval_optimized_doublemu_BTagMu_QCDMuEnriched_HLTBTagMuAK8Jet300Mu5_OR_HLTBTagMuJet300Mu5_run2016B-H_pt350_DoubleB"+WP+"_c_1p5",
		"Final_histograms_btagval_optimized_doublemu_BTagMu_QCDMuEnriched_HLTBTagMuAK8Jet300Mu5_OR_HLTBTagMuJet300Mu5_run2016B-H_pt350_DoubleB"+WP+"_c_l_0p5",
		"Final_histograms_btagval_optimized_doublemu_BTagMu_QCDMuEnriched_HLTBTagMuAK8Jet300Mu5_OR_HLTBTagMuJet300Mu5_run2016B-H_pt350_DoubleB"+WP+"_c_l_1p5",
		"Final_histograms_btagval_optimized_doublemu_BTagMu_QCDMuEnriched_HLTBTagMuAK8Jet300Mu5_OR_HLTBTagMuJet300Mu5_run2016B-H_pt350_DoubleB"+WP+"_cfromg_0p5",
		"Final_histograms_btagval_optimized_doublemu_BTagMu_QCDMuEnriched_HLTBTagMuAK8Jet300Mu5_OR_HLTBTagMuJet300Mu5_run2016B-H_pt350_DoubleB"+WP+"_cfromg_1p5",
		"Final_histograms_btagval_optimized_doublemu_BTagMu_QCDMuEnriched_HLTBTagMuAK8Jet300Mu5_OR_HLTBTagMuJet300Mu5_run2016B-H_pt350_DoubleB"+WP+"_l_0p5",
		"Final_histograms_btagval_optimized_doublemu_BTagMu_QCDMuEnriched_HLTBTagMuAK8Jet300Mu5_OR_HLTBTagMuJet300Mu5_run2016B-H_pt350_DoubleB"+WP+"_l_1p5",
	};

	for(int i=0; i<f.size();i++){
		cout << "Processing: " << f.at(i) << endl;	
		Rebin_postConvert(f.at(i),WP,"350","450","450","2000");
		cout << "Success " << endl;	
	}

	gApplication->Terminate();

}
