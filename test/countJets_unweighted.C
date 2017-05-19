#include "TFile.h"
#include "TString.h"
#include "TH1F.h"


using namespace std;

void countJets_unweighted(TString dir,TString fname){


	TFile *f = TFile::Open(dir+"_combined/"+fname+".root");
	cout<< "dir/file: "<< dir<<"/"<< fname<< endl; 

	vector<TString> flavor={"_bfromg","_b","_cfromg","_c","_l"};
	vector<TString> ptrange={
		"pt250to300",
		"pt300to350",
		"pt350to400",
		"pt400to450",
		"pt450to500",
		"pt400to470",
		"pt470to2000",
		"pt350to430",
		"pt430to2000",
		"pt250to350",
		"pt350to450",
		"pt300to400",
		"pt400to500",
		"pt500to600",
		"pt600to2000",
		"pt500to2000",
		"pt450to2000",
	};

	vector<TH1D*> v_h;

	float pt_total = 0;
	for(int j=0; j< ptrange.size(); j++) {
		cout <<"	"<<ptrange.at(j)<<endl;		

		v_h.clear();
		float flavor_total=0;		
		for(int i=0; i< flavor.size(); i++){

			TString hname =  "btagval/FatJet_JP_all_"+ptrange.at(j)+flavor.at(i) ;
			v_h.push_back( (TH1D*) f->Get(hname) );
			cout <<"		"<< flavor.at(i)<< " : "<< v_h.at(i)->Integral() << endl;
			flavor_total=flavor_total+v_h.at(i)->Integral();
		}
		cout <<"		combined flavor total: "<< flavor_total << endl;
		pt_total=pt_total+flavor_total;
	}
// 	cout <<"			combined pt total: "<< pt_total << endl;

}

void countJets_unweighted(){

  vector<TString> dir;
  vector<TString> fname;
  
  dir.push_back("Mu_250_ptReweighted");
  dir.push_back("Mu_350_ptReweighted");
  
  fname={
		"QCD_Pt-120to170_MuEnrichedPt5_TuneCUETP8M1_13TeV_pythia8",// 25190.51514
		"QCD_Pt-120to170_MuEnrichedPt5_TuneCUETP8M1_13TeV_pythia8_backup",// 25190.51514

		"QCD_Pt-170to300_MuEnrichedPt5_TuneCUETP8M1_13TeV_pythia8_ext1",// 8654.49315
		"QCD_Pt-170to300_MuEnrichedPt5_TuneCUETP8M1_13TeV_pythia8_backup",// 8654.49315
		"QCD_Pt-170to300_MuEnrichedPt5_TuneCUETP8M1_13TeV_pythia8",// 8654.49315

		"QCD_Pt-300to470_MuEnrichedPt5_TuneCUETP8M1_13TeV_pythia8_ext1",// 797.3526900 
		"QCD_Pt-300to470_MuEnrichedPt5_TuneCUETP8M1_13TeV_pythia8_ext2",// 797.3526900
		"QCD_Pt-300to470_MuEnrichedPt5_TuneCUETP8M1_13TeV_pythia8",// 797.3526900

		"QCD_Pt-470to600_MuEnrichedPt5_TuneCUETP8M1_13TeV_pythia8",// 79.02553776
		"QCD_Pt-470to600_MuEnrichedPt5_TuneCUETP8M1_13TeV_pythia8_ext1",// 79.02553776
		"QCD_Pt-470to600_MuEnrichedPt5_TuneCUETP8M1_13TeV_pythia8_ext2",// 79.02553776

		"QCD_Pt-600to800_MuEnrichedPt5_TuneCUETP8M1_13TeV_pythia8",// 25.09505908
		"QCD_Pt-600to800_MuEnrichedPt5_TuneCUETP8M1_13TeV_pythia8_ext1",// 25.09505908
		"QCD_Pt-600to800_MuEnrichedPt5_TuneCUETP8M1_13TeV_pythia8_backup",// 25.09505908

		"QCD_Pt-800to1000_MuEnrichedPt5_TuneCUETP8M1_13TeV_pythia8",// 4.707368272
		"QCD_Pt-800to1000_MuEnrichedPt5_TuneCUETP8M1_13TeV_pythia8_ext1",// 4.707368272
		"QCD_Pt-800to1000_MuEnrichedPt5_TuneCUETP8M1_13TeV_pythia8_ext2",// 4.707368272

		"QCD_Pt-1000toInf_MuEnrichedPt5_TuneCUETP8M1_13TeV_pythia8",// 1.621316920
		"QCD_Pt-1000toInf_MuEnrichedPt5_TuneCUETP8M1_13TeV_pythia8_ext1",// 1.621316920  
  };
  
  for(int i=0; i< dir.size();i++){
  	for(int j=0; j< fname.size();j++){
  		countJets_unweighted(dir.at(i),fname.at(j));
  	}
  }
  
  gApplication->Terminate();
	
}












