import os
import paths

def string(txt):
  ''' str wrapper since cmsRun/python requires string to have "". '''

  ''' RECIPE: If working with special flags e.g.
  'triggerSelection'          : string( ','.join(['HLT_BTagMu_AK8Jet300_Mu5' + "'", "'" + 'HLT_BTagMu_Jet300_Mu5']))
  '''
  return txt.join(["'", "'"])

##############################
##############################
SF_run = 'Run2017SF'
Comm_run = 'Run2017Comm'

samples_data = [  'BTagMu_Run2017B-17Nov2017-v1_v03_20190222',
                  'BTagMu_Run2017C-17Nov2017-v1_v03_20190222',
                  'BTagMu_Run2017D-17Nov2017-v1_v03_20190222',
                  'BTagMu_Run2017E-17Nov2017-v1_v03_20190222',
                  'BTagMu_Run2017F-17Nov2017-v1_v03_20190222'
                  ]
samples_qcd = [
                  'QCD_Pt-170to300_MuEnrichedPt5_TuneCP5_13TeV_pythia8_v03_20190222',
                  'QCD_Pt-300to470_MuEnrichedPt5_TuneCP5_13TeV_pythia8_v03_20190222',
                  'QCD_Pt-470to600_MuEnrichedPt5_TuneCP5_13TeV_pythia8_v03_20190222',
                  'QCD_Pt-600to800_MuEnrichedPt5_TuneCP5_13TeV_pythia8_v03_20190222',
                  'QCD_Pt-800to1000_MuEnrichedPt5_TuneCP5_13TeV_pythia8_v03_20190222',
                  'QCD_Pt-1000toInf_MuEnrichedPt5_TuneCP5_13TeV_pythia8_v03_20190222'
                  ]

# Source for config/general.py
info = {
  SF_run: {
    # Dictionary of all samples with their list of subsamples. They are defined in samples.py
    'samples' :{},
    # Name of the root final with final histograms
    'final_output' : 'Run2017_QCDMuEnriched_DoubleMuonTaggedFatJets_histograms_btagval.root',
    # Dictionary of all variables that need to be changed for each campaign
    'btagvalidation_cfg'  : { },
  },
  Comm_run: {
    # Dictionary of all samples with their list of subsamples. They are defined in samples.py
    'samples' :{},
    # Name of the root final with final histograms
    'final_output' : 'Run2017_QCDMuEnriched_DoubleMuonTaggedFatJets_histograms_btagval.root',
    # Dictionary of all variables that need to be changed for each campaign
    'btagvalidation_cfg'  : { },
  },
}

# FIll SF Run
for name in samples_data + samples_qcd:
      info[SF_run]['samples'][name] = ['0']
      if name in samples_data: _runOnData = True
      else: _runOnData = False
      info[SF_run]['btagvalidation_cfg'][name] = {
            'DEBUG'                      : False
            ,'runOnData'                 : _runOnData
            ,'fatJetPtMin'               : 350.
            ,'triggerSelection'          : string( ','.join(['HLT_BTagMu_AK8Jet300_Mu5' + "'", "'" + 'HLT_BTagMu_Jet300_Mu5']))
            ,'FilePUDistData'            : string( os.path.join( paths.main, 'aux', 'RunII2017Rereco_RunBCDEF_v1v2topUp_25ns_PUXsec69200nb_Feb8-2018.root'))
            ,'produceDDXSFtemplates'     : True
            ,'chooseDDXtagger'           : string('DDBvL')
            }


# FIll Comm Run
for name in samples_data + samples_qcd:
      info[Comm_run]['samples'][name] = ['0']
      if name in samples_data: _runOnData = True
      else: _runOnData = False
      info[Comm_run]['btagvalidation_cfg'][name] = {
            'DEBUG'                      : False
            ,'runOnData'                 : _runOnData
            ,'fatJetPtMin'               : 350.
            ,'doFatJetPtReweighting'     : True
            ,'applyFatJetMuonTaggingV2'  : True
            ,'triggerSelection'          : string( ','.join(['HLT_BTagMu_AK8Jet300_Mu5' + "'", "'" + 'HLT_BTagMu_Jet300_Mu5']))
            ,'FilePUDistData'            : string( os.path.join( paths.main, 'aux', 'RunII2017Rereco_RunBCDEF_v1v2topUp_25ns_PUXsec69200nb_Feb8-2018.root'))
            ,'produceDeepDoubleXCommissioning' : True
            }

# for name in samples_qcd:
#       info[run_name]['samples'][name] = ['0']
#       info[run_name]['btagvalidation_cfg'][name] = {
#             'fatJetPtMin'               : _fatJetPtMin
#             ,'fatJetTau21Max'            : _fatJetTau21Max
#             ,'produceDeepDoubleXCommissioning' : _produceDeepDoubleXCommissioning
#             ,'doNewJEC'                  : _doNewJEC
#             ,'applyFatJetMuonTagging'    : _applyFatJetMuonTagging
#             ,'fatJetDoubleTagging'       : _fatJetDoubleTagging
#             ,'triggerSelection'          : _triggerSelection
#             ,'useRelaxedMuonID'          : _useRelaxedMuonID
#             ,'usePrunedMass'             : _usePrunedMass
#             ,'useSoftDropSubjets'        : _useSoftDropSubjets
#             ,'fatJetGroomedMassMin'      : _fatJetGroomedMassMin
#             ,'useRunRange'               : _useRunRange
#             ,'DEBUG'                     : _DEBUG
#             ,'FilePUDistData'            : _FilePUDistData
#             }


#  'Run2017BCD_QCDMuEnriched_Pt350': {
#    # Dictionary of all samples with their list of subsamples. They are defined in samples.py
#    'samples' :{
#      'BTagMu': ['0','1','2'],
#      'QCD_Pt-170to300_MuEnrichedPt5_TuneCP5_13TeV_pythia8': ['0'],
#      'QCD_Pt-300to470_MuEnrichedPt5_TuneCP5_13TeV_pythia8': ['0'],
#      'QCD_Pt-470to600_MuEnrichedPt5_TuneCP5_13TeV_pythia8': ['0'],
##       'QCD_Pt-600to800_MuEnrichedPt5_TuneCP5_13TeV_pythia8': ['0'],
##       'QCD_Pt-800to1000_MuEnrichedPt5_TuneCP5_13TeV_pythia8': ['0'],
#      'QCD_Pt-1000toInf_MuEnrichedPt5_TuneCP5_13TeV_pythia8': ['0'],
#    },
#    # Name of the root final with final histograms
#    'final_output'        : 'Run2017BCD_ReReco_QCDMuEnriched_AK8Jet300orAK4Jet300_Pt350_Final_DoubleMuonTaggedFatJets_histograms_btagval.root',
#    # Dictionary of all variables that need to be changed for each campaign
#    'btagvalidation_cfg'  : {
#      'BTagMu': {
#            'fatJetPtMin'               : 350,
#            'fatJetDoubleTagging'       : True,
#            'triggerSelection'          : string( ','.join(['HLT_BTagMu_AK8Jet300_Mu5' + "'", "'" + 'HLT_BTagMu_AK4Jet300_Mu5'])),
#            'triggerLogicIsOR'          : True,
#            'useJetProbaTree'           : True,
#            'useSoftDropSubjets'        : True,
#            'doJECUncert'               : True,
#            'jecUncPayloadName'         : string(os.path.join( paths.main, 'aux', 'JECfiles/Summer16_23Sep2016BCDV3_DATA_Uncertainty_AK8PFchs.txt')),
#            'newJECPayloadNames'        : string(','.join([
#                        os.path.join( paths.main, 'aux', 'JECfiles/Summer16_23Sep2016BCDV3_DATA_L1FastJet_AK8PFchs.txt') + "'",
#                        "'" + os.path.join( paths.main, 'aux', 'JECfiles/Summer16_23Sep2016BCDV3_DATA_L2Relative_AK8PFchs.txt') + "'",
#                        "'" + os.path.join( paths.main, 'aux', 'JECfiles/Summer16_23Sep2016BCDV3_DATA_L3Absolute_AK8PFchs.txt') + "'",
#                        "'" + os.path.join( paths.main, 'aux', 'JECfiles/Summer16_23Sep2016BCDV3_DATA_L2L3Residual_AK8PFchs.txt')]
#                                                          )),
#            'useRunRange'               : False,
#            'DEBUG'                     : False,
#            },
#      'QCD_Pt-170to300_MuEnrichedPt5_TuneCP5_13TeV_pythia8': {
#            'fatJetPtMin'               : 350,
#            'fatJetDoubleTagging'       : True,
#            'triggerSelection'          : string( ','.join(['HLT_BTagMu_AK8Jet300_Mu5' + "'", "'" + 'HLT_BTagMu_AK4Jet300_Mu5'])),
#            'triggerLogicIsOR'          : True,
#            'useJetProbaTree'           : True,
#            'useSoftDropSubjets'        : True,
#            'doJECUncert'               : True,
#            'jecUncPayloadName'         : string(os.path.join( paths.main, 'aux', 'JECfiles/Summer16_23Sep2016V3_MC_Uncertainty_AK8PFchs.txt')),
#            'newJECPayloadNames'        : string(','.join([
#                        os.path.join( paths.main, 'aux', 'JECfiles/Summer16_23Sep2016V3_MC_L1FastJet_AK8PFchs.txt') + "'",
#                        "'" + os.path.join( paths.main, 'aux', 'JECfiles/Summer16_23Sep2016V3_MC_L2Relative_AK8PFchs.txt') + "'",
#                        "'" + os.path.join( paths.main, 'aux', 'JECfiles/Summer16_23Sep2016V3_MC_L3Absolute_AK8PFchs.txt')]
#                                                          )),
#            'useRunRange'               : False,
#            'DEBUG'                     : False,
#            },
#      'QCD_Pt-300to470_MuEnrichedPt5_TuneCP5_13TeV_pythia8': {
#            'fatJetPtMin'               : 350,
#            'fatJetDoubleTagging'       : True,
#            'triggerSelection'          : string( ','.join(['HLT_BTagMu_AK8Jet300_Mu5' + "'", "'" + 'HLT_BTagMu_AK4Jet300_Mu5'])),
#            'triggerLogicIsOR'          : True,
#            'useJetProbaTree'           : True,
#            'useSoftDropSubjets'        : True,
#            'doJECUncert'               : True,
#            'jecUncPayloadName'         : string(os.path.join( paths.main, 'aux', 'JECfiles/Summer16_23Sep2016V3_MC_Uncertainty_AK8PFchs.txt')),
#            'newJECPayloadNames'        : string(','.join([
#                        os.path.join( paths.main, 'aux', 'JECfiles/Summer16_23Sep2016V3_MC_L1FastJet_AK8PFchs.txt') + "'",
#                        "'" + os.path.join( paths.main, 'aux', 'JECfiles/Summer16_23Sep2016V3_MC_L2Relative_AK8PFchs.txt') + "'",
#                        "'" + os.path.join( paths.main, 'aux', 'JECfiles/Summer16_23Sep2016V3_MC_L3Absolute_AK8PFchs.txt')]
#                                                          )),
#            'useRunRange'               : False,
#            'DEBUG'                     : False,
#            },
#      'QCD_Pt-470to600_MuEnrichedPt5_TuneCP5_13TeV_pythia8': {
#            'fatJetPtMin'               : 350,
#            'fatJetDoubleTagging'       : True,
#            'triggerSelection'          : string( ','.join(['HLT_BTagMu_AK8Jet300_Mu5' + "'", "'" + 'HLT_BTagMu_AK4Jet300_Mu5'])),
#            'triggerLogicIsOR'          : True,
#            'useJetProbaTree'           : True,
#            'useSoftDropSubjets'        : True,
#            'doJECUncert'               : True,
#            'jecUncPayloadName'         : string(os.path.join( paths.main, 'aux', 'JECfiles/Summer16_23Sep2016V3_MC_Uncertainty_AK8PFchs.txt')),
#            'newJECPayloadNames'        : string(','.join([
#                        os.path.join( paths.main, 'aux', 'JECfiles/Summer16_23Sep2016V3_MC_L1FastJet_AK8PFchs.txt') + "'",
#                        "'" + os.path.join( paths.main, 'aux', 'JECfiles/Summer16_23Sep2016V3_MC_L2Relative_AK8PFchs.txt') + "'",
#                        "'" + os.path.join( paths.main, 'aux', 'JECfiles/Summer16_23Sep2016V3_MC_L3Absolute_AK8PFchs.txt')]
#                                                          )),
#            'useRunRange'               : False,
#            'DEBUG'                     : False,
#            },
##       'QCD_Pt-600to800_MuEnrichedPt5_TuneCP5_13TeV_pythia8': {
##             'fatJetPtMin'               : 350,
##             'fatJetDoubleTagging'       : True,
##             'triggerSelection'          : string( ','.join(['HLT_BTagMu_AK8Jet300_Mu5' + "'", "'" + 'HLT_BTagMu_AK4Jet300_Mu5'])),
##             'triggerLogicIsOR'          : True,
##             'useJetProbaTree'           : True,
##             'useSoftDropSubjets'        : True,
##             'doJECUncert'               : True,
##             'jecUncPayloadName'         : string(os.path.join( paths.main, 'aux', 'JECfiles/Summer16_23Sep2016V3_MC_Uncertainty_AK8PFchs.txt')),
##             'newJECPayloadNames'        : string(','.join([
##                         os.path.join( paths.main, 'aux', 'JECfiles/Summer16_23Sep2016V3_MC_L1FastJet_AK8PFchs.txt') + "'",
##                         "'" + os.path.join( paths.main, 'aux', 'JECfiles/Summer16_23Sep2016V3_MC_L2Relative_AK8PFchs.txt') + "'",
##                         "'" + os.path.join( paths.main, 'aux', 'JECfiles/Summer16_23Sep2016V3_MC_L3Absolute_AK8PFchs.txt')]
##                                                           )),
##             'useRunRange'               : False,
##             'DEBUG'                     : False,
##             },
##       'QCD_Pt-800to1000_MuEnrichedPt5_TuneCP5_13TeV_pythia8': {
##             'fatJetPtMin'               : 350,
##             'fatJetDoubleTagging'       : True,
##             'triggerSelection'          : string( ','.join(['HLT_BTagMu_AK8Jet300_Mu5' + "'", "'" + 'HLT_BTagMu_AK4Jet300_Mu5'])),
##             'triggerLogicIsOR'          : True,
##             'useJetProbaTree'           : True,
##             'useSoftDropSubjets'        : True,
##             'doJECUncert'               : True,
##             'jecUncPayloadName'         : string(os.path.join( paths.main, 'aux', 'JECfiles/Summer16_23Sep2016V3_MC_Uncertainty_AK8PFchs.txt')),
##             'newJECPayloadNames'        : string(','.join([
##                         os.path.join( paths.main, 'aux', 'JECfiles/Summer16_23Sep2016V3_MC_L1FastJet_AK8PFchs.txt') + "'",
##                         "'" + os.path.join( paths.main, 'aux', 'JECfiles/Summer16_23Sep2016V3_MC_L2Relative_AK8PFchs.txt') + "'",
##                         "'" + os.path.join( paths.main, 'aux', 'JECfiles/Summer16_23Sep2016V3_MC_L3Absolute_AK8PFchs.txt')]
##                                                           )),
##             'useRunRange'               : False,
##             'DEBUG'                     : False,
##             },
#      'QCD_Pt-1000toInf_MuEnrichedPt5_TuneCP5_13TeV_pythia8': {
#            'fatJetPtMin'               : 350,
#            'fatJetDoubleTagging'       : True,
#            'triggerSelection'          : string( ','.join(['HLT_BTagMu_AK8Jet300_Mu5' + "'", "'" + 'HLT_BTagMu_AK4Jet300_Mu5'])),
#            'triggerLogicIsOR'          : True,
#            'useJetProbaTree'           : True,
#            'useSoftDropSubjets'        : True,
#            'doJECUncert'               : True,
#            'jecUncPayloadName'         : string(os.path.join( paths.main, 'aux', 'JECfiles/Summer16_23Sep2016V3_MC_Uncertainty_AK8PFchs.txt')),
#            'newJECPayloadNames'        : string(','.join([
#                        os.path.join( paths.main, 'aux', 'JECfiles/Summer16_23Sep2016V3_MC_L1FastJet_AK8PFchs.txt') + "'",
#                        "'" + os.path.join( paths.main, 'aux', 'JECfiles/Summer16_23Sep2016V3_MC_L2Relative_AK8PFchs.txt') + "'",
#                        "'" + os.path.join( paths.main, 'aux', 'JECfiles/Summer16_23Sep2016V3_MC_L3Absolute_AK8PFchs.txt')]
#                                                          )),
#            'useRunRange'               : False,
#            'DEBUG'                     : False,
#            },
#
#
#      },
#  },
#
#  'Run2017BCD_QCDMuEnriched_Pt250': {
#    # Dictionary of all samples with their list of subsamples. They are defined in samples.py
#    'samples' :{
#      'BTagMu': ['0','1','2'],
#      'QCD_Pt-170to300_MuEnrichedPt5_TuneCP5_13TeV_pythia8': ['0'],
#      'QCD_Pt-300to470_MuEnrichedPt5_TuneCP5_13TeV_pythia8': ['0'],
#      'QCD_Pt-470to600_MuEnrichedPt5_TuneCP5_13TeV_pythia8': ['0'],
##       'QCD_Pt-600to800_MuEnrichedPt5_TuneCP5_13TeV_pythia8': ['0'],
##       'QCD_Pt-800to1000_MuEnrichedPt5_TuneCP5_13TeV_pythia8': ['0'],
#      'QCD_Pt-1000toInf_MuEnrichedPt5_TuneCP5_13TeV_pythia8': ['0'],
#    },
#    # Name of the root final with final histograms
#    'final_output'        : 'Run2017BCD_ReReco_QCDMuEnriched_AK8Jet300orAK4Jet300_Pt250_Final_DoubleMuonTaggedFatJets_histograms_btagval.root',
#    # Dictionary of all variables that need to be changed for each campaign
#    'btagvalidation_cfg'  : {
#      'BTagMu': {
#            'fatJetPtMin'               : 250,
#            'fatJetPtMax'               : 350,
#            'fatJetDoubleTagging'       : True,
#            'triggerSelection'          : string( ','.join(['HLT_BTagMu_AK4DiJet170_Mu5'])),
#            'triggerLogicIsOR'          : True,
#            'useJetProbaTree'           : True,
#            'useSoftDropSubjets'        : True,
#            'doJECUncert'               : True,
#            'jecUncPayloadName'         : string(os.path.join( paths.main, 'aux', 'JECfiles/Summer16_23Sep2016BCDV3_DATA_Uncertainty_AK8PFchs.txt')),
#            'newJECPayloadNames'        : string(','.join([
#                        os.path.join( paths.main, 'aux', 'JECfiles/Summer16_23Sep2016BCDV3_DATA_L1FastJet_AK8PFchs.txt') + "'",
#                        "'" + os.path.join( paths.main, 'aux', 'JECfiles/Summer16_23Sep2016BCDV3_DATA_L2Relative_AK8PFchs.txt') + "'",
#                        "'" + os.path.join( paths.main, 'aux', 'JECfiles/Summer16_23Sep2016BCDV3_DATA_L3Absolute_AK8PFchs.txt') + "'",
#                        "'" + os.path.join( paths.main, 'aux', 'JECfiles/Summer16_23Sep2016BCDV3_DATA_L2L3Residual_AK8PFchs.txt')]
#                                                          )),
#            'useRunRange'               : False,
#            'DEBUG'                     : False,
#            },
#      'QCD_Pt-170to300_MuEnrichedPt5_TuneCP5_13TeV_pythia8': {
#            'fatJetPtMin'               : 250,
#            'fatJetPtMax'               : 350,
#            'fatJetDoubleTagging'       : True,
#            'triggerSelection'          : string( ','.join(['HLT_BTagMu_AK4DiJet170_Mu5'])),
#            'triggerLogicIsOR'          : True,
#            'useJetProbaTree'           : True,
#            'useSoftDropSubjets'        : True,
#            'doJECUncert'               : True,
#            'jecUncPayloadName'         : string(os.path.join( paths.main, 'aux', 'JECfiles/Summer16_23Sep2016V3_MC_Uncertainty_AK8PFchs.txt')),
#            'newJECPayloadNames'        : string(','.join([
#                        os.path.join( paths.main, 'aux', 'JECfiles/Summer16_23Sep2016V3_MC_L1FastJet_AK8PFchs.txt') + "'",
#                        "'" + os.path.join( paths.main, 'aux', 'JECfiles/Summer16_23Sep2016V3_MC_L2Relative_AK8PFchs.txt') + "'",
#                        "'" + os.path.join( paths.main, 'aux', 'JECfiles/Summer16_23Sep2016V3_MC_L3Absolute_AK8PFchs.txt')]
#                                                          )),
#            'useRunRange'               : False,
#            'DEBUG'                     : False,
#            },
#      'QCD_Pt-300to470_MuEnrichedPt5_TuneCP5_13TeV_pythia8': {
#            'fatJetPtMin'               : 250,
#            'fatJetPtMax'               : 350,
#            'fatJetDoubleTagging'       : True,
#            'triggerSelection'          : string( ','.join(['HLT_BTagMu_AK4DiJet170_Mu5'])),
#            'triggerLogicIsOR'          : True,
#            'useJetProbaTree'           : True,
#            'useSoftDropSubjets'        : True,
#            'doJECUncert'               : True,
#            'jecUncPayloadName'         : string(os.path.join( paths.main, 'aux', 'JECfiles/Summer16_23Sep2016V3_MC_Uncertainty_AK8PFchs.txt')),
#            'newJECPayloadNames'        : string(','.join([
#                        os.path.join( paths.main, 'aux', 'JECfiles/Summer16_23Sep2016V3_MC_L1FastJet_AK8PFchs.txt') + "'",
#                        "'" + os.path.join( paths.main, 'aux', 'JECfiles/Summer16_23Sep2016V3_MC_L2Relative_AK8PFchs.txt') + "'",
#                        "'" + os.path.join( paths.main, 'aux', 'JECfiles/Summer16_23Sep2016V3_MC_L3Absolute_AK8PFchs.txt')]
#                                                          )),
#            'useRunRange'               : False,
#            'DEBUG'                     : False,
#            },
#      'QCD_Pt-470to600_MuEnrichedPt5_TuneCP5_13TeV_pythia8': {
#            'fatJetPtMin'               : 250,
#            'fatJetPtMax'               : 350,
#            'fatJetDoubleTagging'       : True,
#            'triggerSelection'          : string( ','.join(['HLT_BTagMu_AK4DiJet170_Mu5'])),
#            'triggerLogicIsOR'          : True,
#            'useJetProbaTree'           : True,
#            'useSoftDropSubjets'        : True,
#            'doJECUncert'               : True,
#            'jecUncPayloadName'         : string(os.path.join( paths.main, 'aux', 'JECfiles/Summer16_23Sep2016V3_MC_Uncertainty_AK8PFchs.txt')),
#            'newJECPayloadNames'        : string(','.join([
#                        os.path.join( paths.main, 'aux', 'JECfiles/Summer16_23Sep2016V3_MC_L1FastJet_AK8PFchs.txt') + "'",
#                        "'" + os.path.join( paths.main, 'aux', 'JECfiles/Summer16_23Sep2016V3_MC_L2Relative_AK8PFchs.txt') + "'",
#                        "'" + os.path.join( paths.main, 'aux', 'JECfiles/Summer16_23Sep2016V3_MC_L3Absolute_AK8PFchs.txt')]
#                                                          )),
#            'useRunRange'               : False,
#            'DEBUG'                     : False,
#            },
##       'QCD_Pt-600to800_MuEnrichedPt5_TuneCP5_13TeV_pythia8': {
##             'fatJetPtMin'               : 250,
##             'fatJetPtMax'               : 350,
##             'fatJetDoubleTagging'       : True,
##             'triggerSelection'          : string( ','.join(['HLT_BTagMu_AK4DiJet170_Mu5'])),
##             'triggerLogicIsOR'          : True,
##             'useJetProbaTree'           : True,
##             'useSoftDropSubjets'        : True,
##             'doJECUncert'               : True,
##             'jecUncPayloadName'         : string(os.path.join( paths.main, 'aux', 'JECfiles/Summer16_23Sep2016V3_MC_Uncertainty_AK8PFchs.txt')),
##             'newJECPayloadNames'        : string(','.join([
##                         os.path.join( paths.main, 'aux', 'JECfiles/Summer16_23Sep2016V3_MC_L1FastJet_AK8PFchs.txt') + "'",
##                         "'" + os.path.join( paths.main, 'aux', 'JECfiles/Summer16_23Sep2016V3_MC_L2Relative_AK8PFchs.txt') + "'",
##                         "'" + os.path.join( paths.main, 'aux', 'JECfiles/Summer16_23Sep2016V3_MC_L3Absolute_AK8PFchs.txt')]
##                                                           )),
##             'useRunRange'               : False,
##             'DEBUG'                     : False,
##             },
##       'QCD_Pt-800to1000_MuEnrichedPt5_TuneCP5_13TeV_pythia8': {
##             'fatJetPtMin'               : 250,
##             'fatJetPtMax'               : 350,
##             'fatJetDoubleTagging'       : True,
##             'triggerSelection'          : string( ','.join(['HLT_BTagMu_AK4DiJet170_Mu5'])),
##             'triggerLogicIsOR'          : True,
##             'useJetProbaTree'           : True,
##             'useSoftDropSubjets'        : True,
##             'doJECUncert'               : True,
##             'jecUncPayloadName'         : string(os.path.join( paths.main, 'aux', 'JECfiles/Summer16_23Sep2016V3_MC_Uncertainty_AK8PFchs.txt')),
##             'newJECPayloadNames'        : string(','.join([
##                         os.path.join( paths.main, 'aux', 'JECfiles/Summer16_23Sep2016V3_MC_L1FastJet_AK8PFchs.txt') + "'",
##                         "'" + os.path.join( paths.main, 'aux', 'JECfiles/Summer16_23Sep2016V3_MC_L2Relative_AK8PFchs.txt') + "'",
##                         "'" + os.path.join( paths.main, 'aux', 'JECfiles/Summer16_23Sep2016V3_MC_L3Absolute_AK8PFchs.txt')]
##                                                           )),
##             'useRunRange'               : False,
##             'DEBUG'                     : False,
##             },
#      'QCD_Pt-1000toInf_MuEnrichedPt5_TuneCP5_13TeV_pythia8': {
#            'fatJetPtMin'               : 250,
#            'fatJetPtMax'               : 350,
#            'fatJetDoubleTagging'       : True,
#            'triggerSelection'          : string( ','.join(['HLT_BTagMu_AK4DiJet170_Mu5'])),
#            'triggerLogicIsOR'          : True,
#            'useJetProbaTree'           : True,
#            'useSoftDropSubjets'        : True,
#            'doJECUncert'               : True,
#            'jecUncPayloadName'         : string(os.path.join( paths.main, 'aux', 'JECfiles/Summer16_23Sep2016V3_MC_Uncertainty_AK8PFchs.txt')),
#            'newJECPayloadNames'        : string(','.join([
#                        os.path.join( paths.main, 'aux', 'JECfiles/Summer16_23Sep2016V3_MC_L1FastJet_AK8PFchs.txt') + "'",
#                        "'" + os.path.join( paths.main, 'aux', 'JECfiles/Summer16_23Sep2016V3_MC_L2Relative_AK8PFchs.txt') + "'",
#                        "'" + os.path.join( paths.main, 'aux', 'JECfiles/Summer16_23Sep2016V3_MC_L3Absolute_AK8PFchs.txt')]
#                                                          )),
#            'useRunRange'               : False,
#            'DEBUG'                     : False,
#            },
#
#
#      },
#  },
#
#}
#
############################### Jan10-2018 - first attempt for comm plots in 2018. QCDinclusive many datasets are in production status, so stats are not full potential.
#
## info = {
##
##   'Run2017BCD_QCDincl_Pt350': {
##     # Dictionary of all samples with their list of subsamples. They are defined in samples.py
##     'samples' :{
##       'BTagMu': ['0','1','2'],
##       'QCD_Pt_170to300_TuneCP5_13TeV_pythia8': ['0'],
##       'QCD_Pt_300to470_TuneCP5_13TeV_pythia8': ['0'],
##       'QCD_Pt_470to600_TuneCP5_13TeV_pythia8': ['0'],
##       'QCD_Pt_600to800_TuneCP5_13TeV_pythia8': ['0'],
##       'QCD_Pt_800to1000_TuneCP5_13TeV_pythia88': ['0'],
##       'QCD_Pt_1000to1400_TuneCP5_13TeV_pythia8': ['0'],
##       'QCD_Pt_1400to1800_TuneCP5_13TeV_pythia8': ['0'],
##       'QCD_Pt_1800to2400_TuneCP5_13TeV_pythia8': ['0'],
##       'QCD_Pt_2400to3200_TuneCP5_13TeV_pythia8': ['0'],
##       'QCD_Pt_3200toInf_TuneCP5_13TeV_pythia8': ['0'],
##     },
##     # Name of the root final with final histograms
##     'final_output'        : 'Run2017BCD_ReReco_QCDMuEnriched_AK8Jet300orAK4Jet300_Pt350_Final_DoubleMuonTaggedFatJets_histograms_btagval.root',
##     # Dictionary of all variables that need to be changed for each campaign
##     'btagvalidation_cfg'  : {
##       'BTagMu': {
##             'fatJetPtMin'               : 350,
##             'fatJetDoubleTagging'       : True,
##             'triggerSelection'          : string( ','.join(['HLT_BTagMu_AK8Jet300_Mu5' + "'", "'" + 'HLT_BTagMu_AK4Jet300_Mu5'])),
##             'triggerLogicIsOR'          : True,
##             'useJetProbaTree'           : True,
##             'useSoftDropSubjets'        : True,
##             'doJECUncert'               : True,
##             'jecUncPayloadName'         : string(os.path.join( paths.main, 'aux', 'JECfiles/Summer16_23Sep2016BCDV3_DATA_Uncertainty_AK8PFchs.txt')),
##             'newJECPayloadNames'        : string(','.join([
##                         os.path.join( paths.main, 'aux', 'JECfiles/Summer16_23Sep2016BCDV3_DATA_L1FastJet_AK8PFchs.txt') + "'",
##                         "'" + os.path.join( paths.main, 'aux', 'JECfiles/Summer16_23Sep2016BCDV3_DATA_L2Relative_AK8PFchs.txt') + "'",
##                         "'" + os.path.join( paths.main, 'aux', 'JECfiles/Summer16_23Sep2016BCDV3_DATA_L3Absolute_AK8PFchs.txt') + "'",
##                         "'" + os.path.join( paths.main, 'aux', 'JECfiles/Summer16_23Sep2016BCDV3_DATA_L2L3Residual_AK8PFchs.txt')]
##                                                           )),
##             'useRunRange'               : False,
##             'DEBUG'                     : False,
##             },
##       'QCD_Pt_170to300_TuneCP5_13TeV_pythia8': {
##             'fatJetPtMin'               : 350,
##             'fatJetDoubleTagging'       : True,
##             'triggerSelection'          : string( ','.join(['HLT_BTagMu_AK8Jet300_Mu5' + "'", "'" + 'HLT_BTagMu_AK4Jet300_Mu5'])),
##             'triggerLogicIsOR'          : True,
##             'useJetProbaTree'           : True,
##             'useSoftDropSubjets'        : True,
##             'doJECUncert'               : True,
##             'jecUncPayloadName'         : string(os.path.join( paths.main, 'aux', 'JECfiles/Summer16_23Sep2016V3_MC_Uncertainty_AK8PFchs.txt')),
##             'newJECPayloadNames'        : string(','.join([
##                         os.path.join( paths.main, 'aux', 'JECfiles/Summer16_23Sep2016V3_MC_L1FastJet_AK8PFchs.txt') + "'",
##                         "'" + os.path.join( paths.main, 'aux', 'JECfiles/Summer16_23Sep2016V3_MC_L2Relative_AK8PFchs.txt') + "'",
##                         "'" + os.path.join( paths.main, 'aux', 'JECfiles/Summer16_23Sep2016V3_MC_L3Absolute_AK8PFchs.txt')]
##                                                           )),
##             'useRunRange'               : False,
##             'DEBUG'                     : False,
##             },
##       'QCD_Pt_300to470_TuneCP5_13TeV_pythia8': {
##             'fatJetPtMin'               : 350,
##             'fatJetDoubleTagging'       : True,
##             'triggerSelection'          : string( ','.join(['HLT_BTagMu_AK8Jet300_Mu5' + "'", "'" + 'HLT_BTagMu_AK4Jet300_Mu5'])),
##             'triggerLogicIsOR'          : True,
##             'useJetProbaTree'           : True,
##             'useSoftDropSubjets'        : True,
##             'doJECUncert'               : True,
##             'jecUncPayloadName'         : string(os.path.join( paths.main, 'aux', 'JECfiles/Summer16_23Sep2016V3_MC_Uncertainty_AK8PFchs.txt')),
##             'newJECPayloadNames'        : string(','.join([
##                         os.path.join( paths.main, 'aux', 'JECfiles/Summer16_23Sep2016V3_MC_L1FastJet_AK8PFchs.txt') + "'",
##                         "'" + os.path.join( paths.main, 'aux', 'JECfiles/Summer16_23Sep2016V3_MC_L2Relative_AK8PFchs.txt') + "'",
##                         "'" + os.path.join( paths.main, 'aux', 'JECfiles/Summer16_23Sep2016V3_MC_L3Absolute_AK8PFchs.txt')]
##                                                           )),
##             'useRunRange'               : False,
##             'DEBUG'                     : False,
##             },
##       'QCD_Pt_470to600_TuneCP5_13TeV_pythia8': {
##             'fatJetPtMin'               : 350,
##             'fatJetDoubleTagging'       : True,
##             'triggerSelection'          : string( ','.join(['HLT_BTagMu_AK8Jet300_Mu5' + "'", "'" + 'HLT_BTagMu_AK4Jet300_Mu5'])),
##             'triggerLogicIsOR'          : True,
##             'useJetProbaTree'           : True,
##             'useSoftDropSubjets'        : True,
##             'doJECUncert'               : True,
##             'jecUncPayloadName'         : string(os.path.join( paths.main, 'aux', 'JECfiles/Summer16_23Sep2016V3_MC_Uncertainty_AK8PFchs.txt')),
##             'newJECPayloadNames'        : string(','.join([
##                         os.path.join( paths.main, 'aux', 'JECfiles/Summer16_23Sep2016V3_MC_L1FastJet_AK8PFchs.txt') + "'",
##                         "'" + os.path.join( paths.main, 'aux', 'JECfiles/Summer16_23Sep2016V3_MC_L2Relative_AK8PFchs.txt') + "'",
##                         "'" + os.path.join( paths.main, 'aux', 'JECfiles/Summer16_23Sep2016V3_MC_L3Absolute_AK8PFchs.txt')]
##                                                           )),
##             'useRunRange'               : False,
##             'DEBUG'                     : False,
##             },
##       'QCD_Pt_600to800_TuneCP5_13TeV_pythia8': {
##             'fatJetPtMin'               : 350,
##             'fatJetDoubleTagging'       : True,
##             'triggerSelection'          : string( ','.join(['HLT_BTagMu_AK8Jet300_Mu5' + "'", "'" + 'HLT_BTagMu_AK4Jet300_Mu5'])),
##             'triggerLogicIsOR'          : True,
##             'useJetProbaTree'           : True,
##             'useSoftDropSubjets'        : True,
##             'doJECUncert'               : True,
##             'jecUncPayloadName'         : string(os.path.join( paths.main, 'aux', 'JECfiles/Summer16_23Sep2016V3_MC_Uncertainty_AK8PFchs.txt')),
##             'newJECPayloadNames'        : string(','.join([
##                         os.path.join( paths.main, 'aux', 'JECfiles/Summer16_23Sep2016V3_MC_L1FastJet_AK8PFchs.txt') + "'",
##                         "'" + os.path.join( paths.main, 'aux', 'JECfiles/Summer16_23Sep2016V3_MC_L2Relative_AK8PFchs.txt') + "'",
##                         "'" + os.path.join( paths.main, 'aux', 'JECfiles/Summer16_23Sep2016V3_MC_L3Absolute_AK8PFchs.txt')]
##                                                           )),
##             'useRunRange'               : False,
##             'DEBUG'                     : False,
##             },
##       'QCD_Pt_800to1000_TuneCP5_13TeV_pythia88': {
##             'fatJetPtMin'               : 350,
##             'fatJetDoubleTagging'       : True,
##             'triggerSelection'          : string( ','.join(['HLT_BTagMu_AK8Jet300_Mu5' + "'", "'" + 'HLT_BTagMu_AK4Jet300_Mu5'])),
##             'triggerLogicIsOR'          : True,
##             'useJetProbaTree'           : True,
##             'useSoftDropSubjets'        : True,
##             'doJECUncert'               : True,
##             'jecUncPayloadName'         : string(os.path.join( paths.main, 'aux', 'JECfiles/Summer16_23Sep2016V3_MC_Uncertainty_AK8PFchs.txt')),
##             'newJECPayloadNames'        : string(','.join([
##                         os.path.join( paths.main, 'aux', 'JECfiles/Summer16_23Sep2016V3_MC_L1FastJet_AK8PFchs.txt') + "'",
##                         "'" + os.path.join( paths.main, 'aux', 'JECfiles/Summer16_23Sep2016V3_MC_L2Relative_AK8PFchs.txt') + "'",
##                         "'" + os.path.join( paths.main, 'aux', 'JECfiles/Summer16_23Sep2016V3_MC_L3Absolute_AK8PFchs.txt')]
##                                                           )),
##             'useRunRange'               : False,
##             'DEBUG'                     : False,
##             },
##       'QCD_Pt_1000to1400_TuneCP5_13TeV_pythia8': {
##             'fatJetPtMin'               : 350,
##             'fatJetDoubleTagging'       : True,
##             'triggerSelection'          : string( ','.join(['HLT_BTagMu_AK8Jet300_Mu5' + "'", "'" + 'HLT_BTagMu_AK4Jet300_Mu5'])),
##             'triggerLogicIsOR'          : True,
##             'useJetProbaTree'           : True,
##             'useSoftDropSubjets'        : True,
##             'doJECUncert'               : True,
##             'jecUncPayloadName'         : string(os.path.join( paths.main, 'aux', 'JECfiles/Summer16_23Sep2016V3_MC_Uncertainty_AK8PFchs.txt')),
##             'newJECPayloadNames'        : string(','.join([
##                         os.path.join( paths.main, 'aux', 'JECfiles/Summer16_23Sep2016V3_MC_L1FastJet_AK8PFchs.txt') + "'",
##                         "'" + os.path.join( paths.main, 'aux', 'JECfiles/Summer16_23Sep2016V3_MC_L2Relative_AK8PFchs.txt') + "'",
##                         "'" + os.path.join( paths.main, 'aux', 'JECfiles/Summer16_23Sep2016V3_MC_L3Absolute_AK8PFchs.txt')]
##                                                           )),
##             'useRunRange'               : False,
##             'DEBUG'                     : False,
##             },
##       'QCD_Pt_1400to1800_TuneCP5_13TeV_pythia8': {
##             'fatJetPtMin'               : 350,
##             'fatJetDoubleTagging'       : True,
##             'triggerSelection'          : string( ','.join(['HLT_BTagMu_AK8Jet300_Mu5' + "'", "'" + 'HLT_BTagMu_AK4Jet300_Mu5'])),
##             'triggerLogicIsOR'          : True,
##             'useJetProbaTree'           : True,
##             'useSoftDropSubjets'        : True,
##             'doJECUncert'               : True,
##             'jecUncPayloadName'         : string(os.path.join( paths.main, 'aux', 'JECfiles/Summer16_23Sep2016V3_MC_Uncertainty_AK8PFchs.txt')),
##             'newJECPayloadNames'        : string(','.join([
##                         os.path.join( paths.main, 'aux', 'JECfiles/Summer16_23Sep2016V3_MC_L1FastJet_AK8PFchs.txt') + "'",
##                         "'" + os.path.join( paths.main, 'aux', 'JECfiles/Summer16_23Sep2016V3_MC_L2Relative_AK8PFchs.txt') + "'",
##                         "'" + os.path.join( paths.main, 'aux', 'JECfiles/Summer16_23Sep2016V3_MC_L3Absolute_AK8PFchs.txt')]
##                                                           )),
##             'useRunRange'               : False,
##             'DEBUG'                     : False,
##             },
##       'QCD_Pt_1800to2400_TuneCP5_13TeV_pythia8': {
##             'fatJetPtMin'               : 350,
##             'fatJetDoubleTagging'       : True,
##             'triggerSelection'          : string( ','.join(['HLT_BTagMu_AK8Jet300_Mu5' + "'", "'" + 'HLT_BTagMu_AK4Jet300_Mu5'])),
##             'triggerLogicIsOR'          : True,
##             'useJetProbaTree'           : True,
##             'useSoftDropSubjets'        : True,
##             'doJECUncert'               : True,
##             'jecUncPayloadName'         : string(os.path.join( paths.main, 'aux', 'JECfiles/Summer16_23Sep2016V3_MC_Uncertainty_AK8PFchs.txt')),
##             'newJECPayloadNames'        : string(','.join([
##                         os.path.join( paths.main, 'aux', 'JECfiles/Summer16_23Sep2016V3_MC_L1FastJet_AK8PFchs.txt') + "'",
##                         "'" + os.path.join( paths.main, 'aux', 'JECfiles/Summer16_23Sep2016V3_MC_L2Relative_AK8PFchs.txt') + "'",
##                         "'" + os.path.join( paths.main, 'aux', 'JECfiles/Summer16_23Sep2016V3_MC_L3Absolute_AK8PFchs.txt')]
##                                                           )),
##             'useRunRange'               : False,
##             'DEBUG'                     : False,
##             },
##       'QCD_Pt_2400to3200_TuneCP5_13TeV_pythia8': {
##             'fatJetPtMin'               : 350,
##             'fatJetDoubleTagging'       : True,
##             'triggerSelection'          : string( ','.join(['HLT_BTagMu_AK8Jet300_Mu5' + "'", "'" + 'HLT_BTagMu_AK4Jet300_Mu5'])),
##             'triggerLogicIsOR'          : True,
##             'useJetProbaTree'           : True,
##             'useSoftDropSubjets'        : True,
##             'doJECUncert'               : True,
##             'jecUncPayloadName'         : string(os.path.join( paths.main, 'aux', 'JECfiles/Summer16_23Sep2016V3_MC_Uncertainty_AK8PFchs.txt')),
##             'newJECPayloadNames'        : string(','.join([
##                         os.path.join( paths.main, 'aux', 'JECfiles/Summer16_23Sep2016V3_MC_L1FastJet_AK8PFchs.txt') + "'",
##                         "'" + os.path.join( paths.main, 'aux', 'JECfiles/Summer16_23Sep2016V3_MC_L2Relative_AK8PFchs.txt') + "'",
##                         "'" + os.path.join( paths.main, 'aux', 'JECfiles/Summer16_23Sep2016V3_MC_L3Absolute_AK8PFchs.txt')]
##                                                           )),
##             'useRunRange'               : False,
##             'DEBUG'                     : False,
##             },
##       'QCD_Pt_3200toInf_TuneCP5_13TeV_pythia8': {
##             'fatJetPtMin'               : 350,
##             'fatJetDoubleTagging'       : True,
##             'triggerSelection'          : string( ','.join(['HLT_BTagMu_AK8Jet300_Mu5' + "'", "'" + 'HLT_BTagMu_AK4Jet300_Mu5'])),
##             'triggerLogicIsOR'          : True,
##             'useJetProbaTree'           : True,
##             'useSoftDropSubjets'        : True,
##             'doJECUncert'               : True,
##             'jecUncPayloadName'         : string(os.path.join( paths.main, 'aux', 'JECfiles/Summer16_23Sep2016V3_MC_Uncertainty_AK8PFchs.txt')),
##             'newJECPayloadNames'        : string(','.join([
##                         os.path.join( paths.main, 'aux', 'JECfiles/Summer16_23Sep2016V3_MC_L1FastJet_AK8PFchs.txt') + "'",
##                         "'" + os.path.join( paths.main, 'aux', 'JECfiles/Summer16_23Sep2016V3_MC_L2Relative_AK8PFchs.txt') + "'",
##                         "'" + os.path.join( paths.main, 'aux', 'JECfiles/Summer16_23Sep2016V3_MC_L3Absolute_AK8PFchs.txt')]
##                                                           )),
##             'useRunRange'               : False,
##             'DEBUG'                     : False,
##             },
##
##
##       },
##   },
##
##   'Run2017BCD_QCDincl_Pt250': {
##     # Dictionary of all samples with their list of subsamples. They are defined in samples.py
##     'samples' :{
##       'BTagMu': ['0','1','2'],
##       'QCD_Pt_170to300_TuneCP5_13TeV_pythia8': ['0'],
##       'QCD_Pt_300to470_TuneCP5_13TeV_pythia8': ['0'],
##       'QCD_Pt_470to600_TuneCP5_13TeV_pythia8': ['0'],
##       'QCD_Pt_600to800_TuneCP5_13TeV_pythia8': ['0'],
##       'QCD_Pt_800to1000_TuneCP5_13TeV_pythia88': ['0'],
##       'QCD_Pt_1000to1400_TuneCP5_13TeV_pythia8': ['0'],
##       'QCD_Pt_1400to1800_TuneCP5_13TeV_pythia8': ['0'],
##       'QCD_Pt_1800to2400_TuneCP5_13TeV_pythia8': ['0'],
##       'QCD_Pt_2400to3200_TuneCP5_13TeV_pythia8': ['0'],
##       'QCD_Pt_3200toInf_TuneCP5_13TeV_pythia8': ['0'],
##     },
##     # Name of the root final with final histograms
##     'final_output'        : 'Run2017BCD_ReReco_QCDMuEnriched_AK8Jet300orAK4Jet300_Pt350_Final_DoubleMuonTaggedFatJets_histograms_btagval.root',
##     # Dictionary of all variables that need to be changed for each campaign
##     'btagvalidation_cfg'  : {
##       'BTagMu': {
##             'fatJetPtMin'               : 250,
##             'fatJetPtMax'               : 350,
##             'fatJetDoubleTagging'       : True,
##             'triggerSelection'          : string( ','.join(['HLT_BTagMu_AK4DiJet170_Mu5'])),
##             'triggerLogicIsOR'          : True,
##             'useJetProbaTree'           : True,
##             'useSoftDropSubjets'        : True,
##             'doJECUncert'               : True,
##             'jecUncPayloadName'         : string(os.path.join( paths.main, 'aux', 'JECfiles/Summer16_23Sep2016BCDV3_DATA_Uncertainty_AK8PFchs.txt')),
##             'newJECPayloadNames'        : string(','.join([
##                         os.path.join( paths.main, 'aux', 'JECfiles/Summer16_23Sep2016BCDV3_DATA_L1FastJet_AK8PFchs.txt') + "'",
##                         "'" + os.path.join( paths.main, 'aux', 'JECfiles/Summer16_23Sep2016BCDV3_DATA_L2Relative_AK8PFchs.txt') + "'",
##                         "'" + os.path.join( paths.main, 'aux', 'JECfiles/Summer16_23Sep2016BCDV3_DATA_L3Absolute_AK8PFchs.txt') + "'",
##                         "'" + os.path.join( paths.main, 'aux', 'JECfiles/Summer16_23Sep2016BCDV3_DATA_L2L3Residual_AK8PFchs.txt')]
##                                                           )),
##             'useRunRange'               : False,
##             'DEBUG'                     : False,
##             },
##       'QCD_Pt_170to300_TuneCP5_13TeV_pythia8': {
##             'fatJetPtMin'               : 250,
##             'fatJetPtMax'               : 350,
##             'fatJetDoubleTagging'       : True,
##             'triggerSelection'          : string( ','.join(['HLT_BTagMu_AK4DiJet170_Mu5'])),
##             'triggerLogicIsOR'          : True,
##             'useJetProbaTree'           : True,
##             'useSoftDropSubjets'        : True,
##             'doJECUncert'               : True,
##             'jecUncPayloadName'         : string(os.path.join( paths.main, 'aux', 'JECfiles/Summer16_23Sep2016V3_MC_Uncertainty_AK8PFchs.txt')),
##             'newJECPayloadNames'        : string(','.join([
##                         os.path.join( paths.main, 'aux', 'JECfiles/Summer16_23Sep2016V3_MC_L1FastJet_AK8PFchs.txt') + "'",
##                         "'" + os.path.join( paths.main, 'aux', 'JECfiles/Summer16_23Sep2016V3_MC_L2Relative_AK8PFchs.txt') + "'",
##                         "'" + os.path.join( paths.main, 'aux', 'JECfiles/Summer16_23Sep2016V3_MC_L3Absolute_AK8PFchs.txt')]
##                                                           )),
##             'useRunRange'               : False,
##             'DEBUG'                     : False,
##             },
##       'QCD_Pt_300to470_TuneCP5_13TeV_pythia8': {
##             'fatJetPtMin'               : 250,
##             'fatJetPtMax'               : 350,
##             'fatJetDoubleTagging'       : True,
##             'triggerSelection'          : string( ','.join(['HLT_BTagMu_AK4DiJet170_Mu5'])),
##             'triggerLogicIsOR'          : True,
##             'useJetProbaTree'           : True,
##             'useSoftDropSubjets'        : True,
##             'doJECUncert'               : True,
##             'jecUncPayloadName'         : string(os.path.join( paths.main, 'aux', 'JECfiles/Summer16_23Sep2016V3_MC_Uncertainty_AK8PFchs.txt')),
##             'newJECPayloadNames'        : string(','.join([
##                         os.path.join( paths.main, 'aux', 'JECfiles/Summer16_23Sep2016V3_MC_L1FastJet_AK8PFchs.txt') + "'",
##                         "'" + os.path.join( paths.main, 'aux', 'JECfiles/Summer16_23Sep2016V3_MC_L2Relative_AK8PFchs.txt') + "'",
##                         "'" + os.path.join( paths.main, 'aux', 'JECfiles/Summer16_23Sep2016V3_MC_L3Absolute_AK8PFchs.txt')]
##                                                           )),
##             'useRunRange'               : False,
##             'DEBUG'                     : False,
##             },
##       'QCD_Pt_470to600_TuneCP5_13TeV_pythia8': {
##             'fatJetPtMin'               : 250,
##             'fatJetPtMax'               : 350,
##             'fatJetDoubleTagging'       : True,
##             'triggerSelection'          : string( ','.join(['HLT_BTagMu_AK4DiJet170_Mu5'])),
##             'triggerLogicIsOR'          : True,
##             'useJetProbaTree'           : True,
##             'useSoftDropSubjets'        : True,
##             'doJECUncert'               : True,
##             'jecUncPayloadName'         : string(os.path.join( paths.main, 'aux', 'JECfiles/Summer16_23Sep2016V3_MC_Uncertainty_AK8PFchs.txt')),
##             'newJECPayloadNames'        : string(','.join([
##                         os.path.join( paths.main, 'aux', 'JECfiles/Summer16_23Sep2016V3_MC_L1FastJet_AK8PFchs.txt') + "'",
##                         "'" + os.path.join( paths.main, 'aux', 'JECfiles/Summer16_23Sep2016V3_MC_L2Relative_AK8PFchs.txt') + "'",
##                         "'" + os.path.join( paths.main, 'aux', 'JECfiles/Summer16_23Sep2016V3_MC_L3Absolute_AK8PFchs.txt')]
##                                                           )),
##             'useRunRange'               : False,
##             'DEBUG'                     : False,
##             },
##       'QCD_Pt_600to800_TuneCP5_13TeV_pythia8': {
##             'fatJetPtMin'               : 250,
##             'fatJetPtMax'               : 350,
##             'fatJetDoubleTagging'       : True,
##             'triggerSelection'          : string( ','.join(['HLT_BTagMu_AK4DiJet170_Mu5'])),
##             'triggerLogicIsOR'          : True,
##             'useJetProbaTree'           : True,
##             'useSoftDropSubjets'        : True,
##             'doJECUncert'               : True,
##             'jecUncPayloadName'         : string(os.path.join( paths.main, 'aux', 'JECfiles/Summer16_23Sep2016V3_MC_Uncertainty_AK8PFchs.txt')),
##             'newJECPayloadNames'        : string(','.join([
##                         os.path.join( paths.main, 'aux', 'JECfiles/Summer16_23Sep2016V3_MC_L1FastJet_AK8PFchs.txt') + "'",
##                         "'" + os.path.join( paths.main, 'aux', 'JECfiles/Summer16_23Sep2016V3_MC_L2Relative_AK8PFchs.txt') + "'",
##                         "'" + os.path.join( paths.main, 'aux', 'JECfiles/Summer16_23Sep2016V3_MC_L3Absolute_AK8PFchs.txt')]
##                                                           )),
##             'useRunRange'               : False,
##             'DEBUG'                     : False,
##             },
##       'QCD_Pt_800to1000_TuneCP5_13TeV_pythia88': {
##             'fatJetPtMin'               : 250,
##             'fatJetPtMax'               : 350,
##             'fatJetDoubleTagging'       : True,
##             'triggerSelection'          : string( ','.join(['HLT_BTagMu_AK4DiJet170_Mu5'])),
##             'triggerLogicIsOR'          : True,
##             'useJetProbaTree'           : True,
##             'useSoftDropSubjets'        : True,
##             'doJECUncert'               : True,
##             'jecUncPayloadName'         : string(os.path.join( paths.main, 'aux', 'JECfiles/Summer16_23Sep2016V3_MC_Uncertainty_AK8PFchs.txt')),
##             'newJECPayloadNames'        : string(','.join([
##                         os.path.join( paths.main, 'aux', 'JECfiles/Summer16_23Sep2016V3_MC_L1FastJet_AK8PFchs.txt') + "'",
##                         "'" + os.path.join( paths.main, 'aux', 'JECfiles/Summer16_23Sep2016V3_MC_L2Relative_AK8PFchs.txt') + "'",
##                         "'" + os.path.join( paths.main, 'aux', 'JECfiles/Summer16_23Sep2016V3_MC_L3Absolute_AK8PFchs.txt')]
##                                                           )),
##             'useRunRange'               : False,
##             'DEBUG'                     : False,
##             },
##       'QCD_Pt_1000to1400_TuneCP5_13TeV_pythia8': {
##             'fatJetPtMin'               : 250,
##             'fatJetPtMax'               : 350,
##             'fatJetDoubleTagging'       : True,
##             'triggerSelection'          : string( ','.join(['HLT_BTagMu_AK4DiJet170_Mu5'])),
##             'triggerLogicIsOR'          : True,
##             'useJetProbaTree'           : True,
##             'useSoftDropSubjets'        : True,
##             'doJECUncert'               : True,
##             'jecUncPayloadName'         : string(os.path.join( paths.main, 'aux', 'JECfiles/Summer16_23Sep2016V3_MC_Uncertainty_AK8PFchs.txt')),
##             'newJECPayloadNames'        : string(','.join([
##                         os.path.join( paths.main, 'aux', 'JECfiles/Summer16_23Sep2016V3_MC_L1FastJet_AK8PFchs.txt') + "'",
##                         "'" + os.path.join( paths.main, 'aux', 'JECfiles/Summer16_23Sep2016V3_MC_L2Relative_AK8PFchs.txt') + "'",
##                         "'" + os.path.join( paths.main, 'aux', 'JECfiles/Summer16_23Sep2016V3_MC_L3Absolute_AK8PFchs.txt')]
##                                                           )),
##             'useRunRange'               : False,
##             'DEBUG'                     : False,
##             },
##       'QCD_Pt_1400to1800_TuneCP5_13TeV_pythia8': {
##             'fatJetPtMin'               : 250,
##             'fatJetPtMax'               : 350,
##             'fatJetDoubleTagging'       : True,
##             'triggerSelection'          : string( ','.join(['HLT_BTagMu_AK4DiJet170_Mu5'])),
##             'triggerLogicIsOR'          : True,
##             'useJetProbaTree'           : True,
##             'useSoftDropSubjets'        : True,
##             'doJECUncert'               : True,
##             'jecUncPayloadName'         : string(os.path.join( paths.main, 'aux', 'JECfiles/Summer16_23Sep2016V3_MC_Uncertainty_AK8PFchs.txt')),
##             'newJECPayloadNames'        : string(','.join([
##                         os.path.join( paths.main, 'aux', 'JECfiles/Summer16_23Sep2016V3_MC_L1FastJet_AK8PFchs.txt') + "'",
##                         "'" + os.path.join( paths.main, 'aux', 'JECfiles/Summer16_23Sep2016V3_MC_L2Relative_AK8PFchs.txt') + "'",
##                         "'" + os.path.join( paths.main, 'aux', 'JECfiles/Summer16_23Sep2016V3_MC_L3Absolute_AK8PFchs.txt')]
##                                                           )),
##             'useRunRange'               : False,
##             'DEBUG'                     : False,
##             },
##       'QCD_Pt_1800to2400_TuneCP5_13TeV_pythia8': {
##             'fatJetPtMin'               : 250,
##             'fatJetPtMax'               : 350,
##             'fatJetDoubleTagging'       : True,
##             'triggerSelection'          : string( ','.join(['HLT_BTagMu_AK4DiJet170_Mu5'])),
##             'triggerLogicIsOR'          : True,
##             'useJetProbaTree'           : True,
##             'useSoftDropSubjets'        : True,
##             'doJECUncert'               : True,
##             'jecUncPayloadName'         : string(os.path.join( paths.main, 'aux', 'JECfiles/Summer16_23Sep2016V3_MC_Uncertainty_AK8PFchs.txt')),
##             'newJECPayloadNames'        : string(','.join([
##                         os.path.join( paths.main, 'aux', 'JECfiles/Summer16_23Sep2016V3_MC_L1FastJet_AK8PFchs.txt') + "'",
##                         "'" + os.path.join( paths.main, 'aux', 'JECfiles/Summer16_23Sep2016V3_MC_L2Relative_AK8PFchs.txt') + "'",
##                         "'" + os.path.join( paths.main, 'aux', 'JECfiles/Summer16_23Sep2016V3_MC_L3Absolute_AK8PFchs.txt')]
##                                                           )),
##             'useRunRange'               : False,
##             'DEBUG'                     : False,
##             },
##       'QCD_Pt_2400to3200_TuneCP5_13TeV_pythia8': {
##             'fatJetPtMin'               : 250,
##             'fatJetPtMax'               : 350,
##             'fatJetDoubleTagging'       : True,
##             'triggerSelection'          : string( ','.join(['HLT_BTagMu_AK4DiJet170_Mu5'])),
##             'triggerLogicIsOR'          : True,
##             'useJetProbaTree'           : True,
##             'useSoftDropSubjets'        : True,
##             'doJECUncert'               : True,
##             'jecUncPayloadName'         : string(os.path.join( paths.main, 'aux', 'JECfiles/Summer16_23Sep2016V3_MC_Uncertainty_AK8PFchs.txt')),
##             'newJECPayloadNames'        : string(','.join([
##                         os.path.join( paths.main, 'aux', 'JECfiles/Summer16_23Sep2016V3_MC_L1FastJet_AK8PFchs.txt') + "'",
##                         "'" + os.path.join( paths.main, 'aux', 'JECfiles/Summer16_23Sep2016V3_MC_L2Relative_AK8PFchs.txt') + "'",
##                         "'" + os.path.join( paths.main, 'aux', 'JECfiles/Summer16_23Sep2016V3_MC_L3Absolute_AK8PFchs.txt')]
##                                                           )),
##             'useRunRange'               : False,
##             'DEBUG'                     : False,
##             },
##       'QCD_Pt_3200toInf_TuneCP5_13TeV_pythia8': {
##             'fatJetPtMin'               : 250,
##             'fatJetPtMax'               : 350,
##             'fatJetDoubleTagging'       : True,
##             'triggerSelection'          : string( ','.join(['HLT_BTagMu_AK4DiJet170_Mu5'])),
##             'triggerLogicIsOR'          : True,
##             'useJetProbaTree'           : True,
##             'useSoftDropSubjets'        : True,
##             'doJECUncert'               : True,
##             'jecUncPayloadName'         : string(os.path.join( paths.main, 'aux', 'JECfiles/Summer16_23Sep2016V3_MC_Uncertainty_AK8PFchs.txt')),
##             'newJECPayloadNames'        : string(','.join([
##                         os.path.join( paths.main, 'aux', 'JECfiles/Summer16_23Sep2016V3_MC_L1FastJet_AK8PFchs.txt') + "'",
##                         "'" + os.path.join( paths.main, 'aux', 'JECfiles/Summer16_23Sep2016V3_MC_L2Relative_AK8PFchs.txt') + "'",
##                         "'" + os.path.join( paths.main, 'aux', 'JECfiles/Summer16_23Sep2016V3_MC_L3Absolute_AK8PFchs.txt')]
##                                                           )),
##             'useRunRange'               : False,
##             'DEBUG'                     : False,
##             },
##
##
##       },
##   },
##
## }
#
#
############################### Nov7-2017 - relaxing muon selection only require 1 muon in fatjet.
#
## info = {
##
##   'Run2017CD_QCDMuEnriched_Pt350_singleMuTag': {
##     # Dictionary of all samples with their list of subsamples. They are defined in samples.py
##     'samples' :{
##       'BTagMu': ['3','4','5','6','7'],
##       'QCD_Pt-170to300_MuEnrichedPt5_TuneCUETP8M1_13TeV_pythia8':['1'],
##       'QCD_Pt-300to470_MuEnrichedPt5_TuneCUETP8M1_13TeV_pythia8':['1'],
##       'QCD_Pt-470to600_MuEnrichedPt5_TuneCUETP8M1_13TeV_pythia8':['0'],
##       'QCD_Pt-600to800_MuEnrichedPt5_TuneCUETP8M1_13TeV_pythia8':['1'],
##       'QCD_Pt-800to1000_MuEnrichedPt5_TuneCUETP8M1_13TeV_pythia8':['1'],
##       'QCD_Pt-1000toInf_MuEnrichedPt5_TuneCUETP8M1_13TeV_pythia8':['0'],
##     },
##     # Name of the root final with final histograms
##     'final_output'        : 'Run2017CD_QCDMuEnriched_Pt350_singleMuTag_Final_DoubleMuonTaggedFatJets_histograms_btagval.root',
##     # Dictionary of all variables that need to be changed for each campaign
##     'btagvalidation_cfg'  : {
##       'BTagMu': {
##             'fatJetPtMin'               : 350,
##             'fatJetDoubleTagging'       : False,
##             'triggerSelection'          : string( ','.join(['HLT_BTagMu_AK8Jet300_Mu5' + "'", "'" + 'HLT_BTagMu_AK4Jet300_Mu5'])),
##             'triggerLogicIsOR'          : True,
##             'useJetProbaTree'           : True,
##             'useSoftDropSubjets'        : True,
##             'doJECUncert'               : True,
##             'jecUncPayloadName'         : string(os.path.join( paths.main, 'aux', 'JECfiles/Summer16_23Sep2016BCDV3_DATA_Uncertainty_AK8PFchs.txt')),
##             'newJECPayloadNames'        : string(','.join([
##                         os.path.join( paths.main, 'aux', 'JECfiles/Summer16_23Sep2016BCDV3_DATA_L1FastJet_AK8PFchs.txt') + "'",
##                         "'" + os.path.join( paths.main, 'aux', 'JECfiles/Summer16_23Sep2016BCDV3_DATA_L2Relative_AK8PFchs.txt') + "'",
##                         "'" + os.path.join( paths.main, 'aux', 'JECfiles/Summer16_23Sep2016BCDV3_DATA_L3Absolute_AK8PFchs.txt') + "'",
##                         "'" + os.path.join( paths.main, 'aux', 'JECfiles/Summer16_23Sep2016BCDV3_DATA_L2L3Residual_AK8PFchs.txt')]
##                                                           )),
##             'useRunRange'               : False,
##             'DEBUG'                     : False,
##             },
##       'QCD_Pt-170to300_MuEnrichedPt5_TuneCUETP8M1_13TeV_pythia8': {
##             'fatJetPtMin'               : 350,
##             'fatJetDoubleTagging'       : False,
##             'triggerSelection'          : string( ','.join(['HLT_BTagMu_AK8Jet300_Mu5' + "'", "'" + 'HLT_BTagMu_AK4Jet300_Mu5'])),
##             'triggerLogicIsOR'          : True,
##             'useJetProbaTree'           : True,
##             'useSoftDropSubjets'        : True,
##             'doJECUncert'               : True,
##             'jecUncPayloadName'         : string(os.path.join( paths.main, 'aux', 'JECfiles/Summer16_23Sep2016V3_MC_Uncertainty_AK8PFchs.txt')),
##             'newJECPayloadNames'        : string(','.join([
##                         os.path.join( paths.main, 'aux', 'JECfiles/Summer16_23Sep2016V3_MC_L1FastJet_AK8PFchs.txt') + "'",
##                         "'" + os.path.join( paths.main, 'aux', 'JECfiles/Summer16_23Sep2016V3_MC_L2Relative_AK8PFchs.txt') + "'",
##                         "'" + os.path.join( paths.main, 'aux', 'JECfiles/Summer16_23Sep2016V3_MC_L3Absolute_AK8PFchs.txt')]
##                                                           )),
##             'useRunRange'               : False,
##             'DEBUG'                     : False,
##             },
##       'QCD_Pt-300to470_MuEnrichedPt5_TuneCUETP8M1_13TeV_pythia8': {
##             'fatJetPtMin'               : 350,
##             'fatJetDoubleTagging'       : False,
##             'triggerSelection'          : string( ','.join(['HLT_BTagMu_AK8Jet300_Mu5' + "'", "'" + 'HLT_BTagMu_AK4Jet300_Mu5'])),
##             'triggerLogicIsOR'          : True,
##             'useJetProbaTree'           : True,
##             'useSoftDropSubjets'        : True,
##             'doJECUncert'               : True,
##             'jecUncPayloadName'         : string(os.path.join( paths.main, 'aux', 'JECfiles/Summer16_23Sep2016V3_MC_Uncertainty_AK8PFchs.txt')),
##             'newJECPayloadNames'        : string(','.join([
##                         os.path.join( paths.main, 'aux', 'JECfiles/Summer16_23Sep2016V3_MC_L1FastJet_AK8PFchs.txt') + "'",
##                         "'" + os.path.join( paths.main, 'aux', 'JECfiles/Summer16_23Sep2016V3_MC_L2Relative_AK8PFchs.txt') + "'",
##                         "'" + os.path.join( paths.main, 'aux', 'JECfiles/Summer16_23Sep2016V3_MC_L3Absolute_AK8PFchs.txt')]
##                                                           )),
##             'useRunRange'               : False,
##             'DEBUG'                     : False,
##             },
##       'QCD_Pt-470to600_MuEnrichedPt5_TuneCUETP8M1_13TeV_pythia8': {
##             'fatJetPtMin'               : 350,
##             'fatJetDoubleTagging'       : False,
##             'triggerSelection'          : string( ','.join(['HLT_BTagMu_AK8Jet300_Mu5' + "'", "'" + 'HLT_BTagMu_AK4Jet300_Mu5'])),
##             'triggerLogicIsOR'          : True,
##             'useJetProbaTree'           : True,
##             'useSoftDropSubjets'        : True,
##             'doJECUncert'               : True,
##             'jecUncPayloadName'         : string(os.path.join( paths.main, 'aux', 'JECfiles/Summer16_23Sep2016V3_MC_Uncertainty_AK8PFchs.txt')),
##             'newJECPayloadNames'        : string(','.join([
##                         os.path.join( paths.main, 'aux', 'JECfiles/Summer16_23Sep2016V3_MC_L1FastJet_AK8PFchs.txt') + "'",
##                         "'" + os.path.join( paths.main, 'aux', 'JECfiles/Summer16_23Sep2016V3_MC_L2Relative_AK8PFchs.txt') + "'",
##                         "'" + os.path.join( paths.main, 'aux', 'JECfiles/Summer16_23Sep2016V3_MC_L3Absolute_AK8PFchs.txt')]
##                                                           )),
##             'useRunRange'               : False,
##             'DEBUG'                     : False,
##             },
##       'QCD_Pt-600to800_MuEnrichedPt5_TuneCUETP8M1_13TeV_pythia8': {
##             'fatJetPtMin'               : 350,
##             'fatJetDoubleTagging'       : False,
##             'triggerSelection'          : string( ','.join(['HLT_BTagMu_AK8Jet300_Mu5' + "'", "'" + 'HLT_BTagMu_AK4Jet300_Mu5'])),
##             'triggerLogicIsOR'          : True,
##             'useJetProbaTree'           : True,
##             'useSoftDropSubjets'        : True,
##             'doJECUncert'               : True,
##             'jecUncPayloadName'         : string(os.path.join( paths.main, 'aux', 'JECfiles/Summer16_23Sep2016V3_MC_Uncertainty_AK8PFchs.txt')),
##             'newJECPayloadNames'        : string(','.join([
##                         os.path.join( paths.main, 'aux', 'JECfiles/Summer16_23Sep2016V3_MC_L1FastJet_AK8PFchs.txt') + "'",
##                         "'" + os.path.join( paths.main, 'aux', 'JECfiles/Summer16_23Sep2016V3_MC_L2Relative_AK8PFchs.txt') + "'",
##                         "'" + os.path.join( paths.main, 'aux', 'JECfiles/Summer16_23Sep2016V3_MC_L3Absolute_AK8PFchs.txt')]
##                                                           )),
##             'useRunRange'               : False,
##             'DEBUG'                     : False,
##             },
##       'QCD_Pt-800to1000_MuEnrichedPt5_TuneCUETP8M1_13TeV_pythia8': {
##             'fatJetPtMin'               : 350,
##             'fatJetDoubleTagging'       : False,
##             'triggerSelection'          : string( ','.join(['HLT_BTagMu_AK8Jet300_Mu5' + "'", "'" + 'HLT_BTagMu_AK4Jet300_Mu5'])),
##             'triggerLogicIsOR'          : True,
##             'useJetProbaTree'           : True,
##             'useSoftDropSubjets'        : True,
##             'doJECUncert'               : True,
##             'jecUncPayloadName'         : string(os.path.join( paths.main, 'aux', 'JECfiles/Summer16_23Sep2016V3_MC_Uncertainty_AK8PFchs.txt')),
##             'newJECPayloadNames'        : string(','.join([
##                         os.path.join( paths.main, 'aux', 'JECfiles/Summer16_23Sep2016V3_MC_L1FastJet_AK8PFchs.txt') + "'",
##                         "'" + os.path.join( paths.main, 'aux', 'JECfiles/Summer16_23Sep2016V3_MC_L2Relative_AK8PFchs.txt') + "'",
##                         "'" + os.path.join( paths.main, 'aux', 'JECfiles/Summer16_23Sep2016V3_MC_L3Absolute_AK8PFchs.txt')]
##                                                           )),
##             'useRunRange'               : False,
##             'DEBUG'                     : False,
##             },
##       'QCD_Pt-1000toInf_MuEnrichedPt5_TuneCUETP8M1_13TeV_pythia8': {
##             'fatJetPtMin'               : 350,
##             'fatJetDoubleTagging'       : False,
##             'triggerSelection'          : string( ','.join(['HLT_BTagMu_AK8Jet300_Mu5' + "'", "'" + 'HLT_BTagMu_AK4Jet300_Mu5'])),
##             'triggerLogicIsOR'          : True,
##             'useJetProbaTree'           : True,
##             'useSoftDropSubjets'        : True,
##             'doJECUncert'               : True,
##             'jecUncPayloadName'         : string(os.path.join( paths.main, 'aux', 'JECfiles/Summer16_23Sep2016V3_MC_Uncertainty_AK8PFchs.txt')),
##             'newJECPayloadNames'        : string(','.join([
##                         os.path.join( paths.main, 'aux', 'JECfiles/Summer16_23Sep2016V3_MC_L1FastJet_AK8PFchs.txt') + "'",
##                         "'" + os.path.join( paths.main, 'aux', 'JECfiles/Summer16_23Sep2016V3_MC_L2Relative_AK8PFchs.txt') + "'",
##                         "'" + os.path.join( paths.main, 'aux', 'JECfiles/Summer16_23Sep2016V3_MC_L3Absolute_AK8PFchs.txt')]
##                                                           )),
##             'useRunRange'               : False,
##             'DEBUG'                     : False,
##             },
##       },
##   },
##
## }
#
#
############################### ~earlyNov-2017
#
## info = {
##
## #   'AK8Jet300orAK4Jet300_Run2017CD': {
## #     # Dictionary of all samples with their list of subsamples. They are defined in samples.py
## #     'samples' :{
## #       'BTagMu': ['3','4','5','6','7'],
## #     },
## #     # Name of the root final with final histograms
## #     'final_output'        : 'Run2017CD_AK8Jet300orAK4Jet300_Pt350_Final_DoubleMuonTaggedFatJets_histograms_btagval.root',
## #     # Dictionary of all variables that need to be changed for each campaign
## #     'btagvalidation_cfg'  : {
## #       'BTagMu': {
## #             'fatJetPtMin'               : 350,
## #             'fatJetDoubleTagging'       : True,
## #             'triggerSelection'          : string( ','.join(['HLT_BTagMu_AK8Jet300_Mu5' + "'", "'" + 'HLT_BTagMu_AK4Jet300_Mu5'])),
## #             'triggerLogicIsOR'          : True,
## #             'useJetProbaTree'           : True,
## #             'useSoftDropSubjets'        : True,
## #             'doJECUncert'               : True,
## #             'jecUncPayloadName'         : string(os.path.join( paths.main, 'aux', 'JECfiles/Summer16_23Sep2016BCDV3_DATA_Uncertainty_AK8PFchs.txt')),
## #             'newJECPayloadNames'        : string(','.join([
## #                         os.path.join( paths.main, 'aux', 'JECfiles/Summer16_23Sep2016BCDV3_DATA_L1FastJet_AK8PFchs.txt') + "'",
## #                         "'" + os.path.join( paths.main, 'aux', 'JECfiles/Summer16_23Sep2016BCDV3_DATA_L2Relative_AK8PFchs.txt') + "'",
## #                         "'" + os.path.join( paths.main, 'aux', 'JECfiles/Summer16_23Sep2016BCDV3_DATA_L3Absolute_AK8PFchs.txt') + "'",
## #                         "'" + os.path.join( paths.main, 'aux', 'JECfiles/Summer16_23Sep2016BCDV3_DATA_L2L3Residual_AK8PFchs.txt')]
## #                                                           )),
## #             'useRunRange'               : False,
## #             'DEBUG'                     : False,
## #             },
## #       },
## #   },
## #
## #   'AK4DiJet110_Run2017CD': {
## #     # Dictionary of all samples with their list of subsamples. They are defined in samples.py
## #     'samples' :{
## #       'BTagMu': ['3','4','5','6','7'],
## #     },
## #     # Name of the root final with final histograms
## #     'final_output'        : 'Run2017CD_AK4DiJet110_Pt350_Final_DoubleMuonTaggedFatJets_histograms_btagval.root',
## #     # Dictionary of all variables that need to be changed for each campaign
## #     'btagvalidation_cfg'  : {
## #       'BTagMu': {
## #             'fatJetPtMin'               : 350,
## #             'fatJetDoubleTagging'       : True,
## #             'triggerSelection'          : string( ','.join(['HLT_BTagMu_AK4DiJet110_Mu5'])),
## #             'triggerLogicIsOR'          : True,
## #             'useJetProbaTree'           : True,
## #             'useSoftDropSubjets'        : True,
## #             'doJECUncert'               : True,
## #             'jecUncPayloadName'         : string(os.path.join( paths.main, 'aux', 'JECfiles/Summer16_23Sep2016BCDV3_DATA_Uncertainty_AK8PFchs.txt')),
## #             'newJECPayloadNames'        : string(','.join([
## #                         os.path.join( paths.main, 'aux', 'JECfiles/Summer16_23Sep2016BCDV3_DATA_L1FastJet_AK8PFchs.txt') + "'",
## #                         "'" + os.path.join( paths.main, 'aux', 'JECfiles/Summer16_23Sep2016BCDV3_DATA_L2Relative_AK8PFchs.txt') + "'",
## #                         "'" + os.path.join( paths.main, 'aux', 'JECfiles/Summer16_23Sep2016BCDV3_DATA_L3Absolute_AK8PFchs.txt') + "'",
## #                         "'" + os.path.join( paths.main, 'aux', 'JECfiles/Summer16_23Sep2016BCDV3_DATA_L2L3Residual_AK8PFchs.txt')]
## #                                                           )),
## #             'useRunRange'               : False,
## #             'DEBUG'                     : False,
## #             },
## #       },
## #   },
##
##   'AK4DiJet170_Run2017CD': {
##     # Dictionary of all samples with their list of subsamples. They are defined in samples.py
##     'samples' :{
##       'BTagMu': ['3','4','5','6','7'],
##     },
##     # Name of the root final with final histograms
##     'final_output'        : 'Run2017CD_AK4DiJet170_Pt250to350_Final_MuonTaggedFatJets_histograms_btagval.root',
##     # Dictionary of all variables that need to be changed for each campaign
##     'btagvalidation_cfg'  : {
##       'BTagMu': {
##             'fatJetPtMin'               : 250,
##             'fatJetPtMax'               : 350,
##             'fatJetDoubleTagging'       : True,
##             'triggerSelection'          : string( ','.join(['HLT_BTagMu_AK4DiJet170_Mu5'])),
##             'triggerLogicIsOR'          : True,
##             'useJetProbaTree'           : True,
##             'useSoftDropSubjets'        : True,
##             'doJECUncert'               : True,
##             'jecUncPayloadName'         : string(os.path.join( paths.main, 'aux', 'JECfiles/Summer16_23Sep2016BCDV3_DATA_Uncertainty_AK8PFchs.txt')),
##             'newJECPayloadNames'        : string(','.join([
##                         os.path.join( paths.main, 'aux', 'JECfiles/Summer16_23Sep2016BCDV3_DATA_L1FastJet_AK8PFchs.txt') + "'",
##                         "'" + os.path.join( paths.main, 'aux', 'JECfiles/Summer16_23Sep2016BCDV3_DATA_L2Relative_AK8PFchs.txt') + "'",
##                         "'" + os.path.join( paths.main, 'aux', 'JECfiles/Summer16_23Sep2016BCDV3_DATA_L3Absolute_AK8PFchs.txt') + "'",
##                         "'" + os.path.join( paths.main, 'aux', 'JECfiles/Summer16_23Sep2016BCDV3_DATA_L2L3Residual_AK8PFchs.txt')]
##                                                           )),
##             'useRunRange'               : False,
##             'DEBUG'                     : False,
##             },
##       },
##   },
##
## }
#
#
############################### Oct25-2017
#
## info = {
##
##   'Run2017CD_QCDMuEnriched_Pt350': {
##     # Dictionary of all samples with their list of subsamples. They are defined in samples.py
##     'samples' :{
##       'BTagMu': ['3','4','5','6','7'],
##       'QCD_Pt-170to300_MuEnrichedPt5_TuneCUETP8M1_13TeV_pythia8':['1'],
##       'QCD_Pt-300to470_MuEnrichedPt5_TuneCUETP8M1_13TeV_pythia8':['1'],
##       'QCD_Pt-470to600_MuEnrichedPt5_TuneCUETP8M1_13TeV_pythia8':['0'],
##       'QCD_Pt-600to800_MuEnrichedPt5_TuneCUETP8M1_13TeV_pythia8':['1'],
##       'QCD_Pt-800to1000_MuEnrichedPt5_TuneCUETP8M1_13TeV_pythia8':['1'],
##       'QCD_Pt-1000toInf_MuEnrichedPt5_TuneCUETP8M1_13TeV_pythia8':['0'],
##     },
##     # Name of the root final with final histograms
##     'final_output'        : 'Run2017CD_QCDMuEnriched_Pt350_Final_DoubleMuonTaggedFatJets_histograms_btagval.root',
##     # Dictionary of all variables that need to be changed for each campaign
##     'btagvalidation_cfg'  : {
##       'BTagMu': {
##             'fatJetPtMin'               : 350,
##             'fatJetDoubleTagging'       : True,
##             'triggerSelection'          : string( ','.join(['HLT_BTagMu_AK8Jet300_Mu5' + "'", "'" + 'HLT_BTagMu_AK4Jet300_Mu5'])),
##             'triggerLogicIsOR'          : True,
##             'useJetProbaTree'           : True,
##             'useSoftDropSubjets'        : True,
##             'doJECUncert'               : True,
##             'jecUncPayloadName'         : string(os.path.join( paths.main, 'aux', 'JECfiles/Summer16_23Sep2016BCDV3_DATA_Uncertainty_AK8PFchs.txt')),
##             'newJECPayloadNames'        : string(','.join([
##                         os.path.join( paths.main, 'aux', 'JECfiles/Summer16_23Sep2016BCDV3_DATA_L1FastJet_AK8PFchs.txt') + "'",
##                         "'" + os.path.join( paths.main, 'aux', 'JECfiles/Summer16_23Sep2016BCDV3_DATA_L2Relative_AK8PFchs.txt') + "'",
##                         "'" + os.path.join( paths.main, 'aux', 'JECfiles/Summer16_23Sep2016BCDV3_DATA_L3Absolute_AK8PFchs.txt') + "'",
##                         "'" + os.path.join( paths.main, 'aux', 'JECfiles/Summer16_23Sep2016BCDV3_DATA_L2L3Residual_AK8PFchs.txt')]
##                                                           )),
##             'useRunRange'               : False,
##             'DEBUG'                     : False,
##             },
##       'QCD_Pt-170to300_MuEnrichedPt5_TuneCUETP8M1_13TeV_pythia8': {
##             'fatJetPtMin'               : 350,
##             'fatJetDoubleTagging'       : True,
##             'triggerSelection'          : string( ','.join(['HLT_BTagMu_AK8Jet300_Mu5' + "'", "'" + 'HLT_BTagMu_AK4Jet300_Mu5'])),
##             'triggerLogicIsOR'          : True,
##             'useJetProbaTree'           : True,
##             'useSoftDropSubjets'        : True,
##             'doJECUncert'               : True,
##             'jecUncPayloadName'         : string(os.path.join( paths.main, 'aux', 'JECfiles/Summer16_23Sep2016V3_MC_Uncertainty_AK8PFchs.txt')),
##             'newJECPayloadNames'        : string(','.join([
##                         os.path.join( paths.main, 'aux', 'JECfiles/Summer16_23Sep2016V3_MC_L1FastJet_AK8PFchs.txt') + "'",
##                         "'" + os.path.join( paths.main, 'aux', 'JECfiles/Summer16_23Sep2016V3_MC_L2Relative_AK8PFchs.txt') + "'",
##                         "'" + os.path.join( paths.main, 'aux', 'JECfiles/Summer16_23Sep2016V3_MC_L3Absolute_AK8PFchs.txt')]
##                                                           )),
##             'useRunRange'               : False,
##             'DEBUG'                     : False,
##             },
##       'QCD_Pt-300to470_MuEnrichedPt5_TuneCUETP8M1_13TeV_pythia8': {
##             'fatJetPtMin'               : 350,
##             'fatJetDoubleTagging'       : True,
##             'triggerSelection'          : string( ','.join(['HLT_BTagMu_AK8Jet300_Mu5' + "'", "'" + 'HLT_BTagMu_AK4Jet300_Mu5'])),
##             'triggerLogicIsOR'          : True,
##             'useJetProbaTree'           : True,
##             'useSoftDropSubjets'        : True,
##             'doJECUncert'               : True,
##             'jecUncPayloadName'         : string(os.path.join( paths.main, 'aux', 'JECfiles/Summer16_23Sep2016V3_MC_Uncertainty_AK8PFchs.txt')),
##             'newJECPayloadNames'        : string(','.join([
##                         os.path.join( paths.main, 'aux', 'JECfiles/Summer16_23Sep2016V3_MC_L1FastJet_AK8PFchs.txt') + "'",
##                         "'" + os.path.join( paths.main, 'aux', 'JECfiles/Summer16_23Sep2016V3_MC_L2Relative_AK8PFchs.txt') + "'",
##                         "'" + os.path.join( paths.main, 'aux', 'JECfiles/Summer16_23Sep2016V3_MC_L3Absolute_AK8PFchs.txt')]
##                                                           )),
##             'useRunRange'               : False,
##             'DEBUG'                     : False,
##             },
##       'QCD_Pt-470to600_MuEnrichedPt5_TuneCUETP8M1_13TeV_pythia8': {
##             'fatJetPtMin'               : 350,
##             'fatJetDoubleTagging'       : True,
##             'triggerSelection'          : string( ','.join(['HLT_BTagMu_AK8Jet300_Mu5' + "'", "'" + 'HLT_BTagMu_AK4Jet300_Mu5'])),
##             'triggerLogicIsOR'          : True,
##             'useJetProbaTree'           : True,
##             'useSoftDropSubjets'        : True,
##             'doJECUncert'               : True,
##             'jecUncPayloadName'         : string(os.path.join( paths.main, 'aux', 'JECfiles/Summer16_23Sep2016V3_MC_Uncertainty_AK8PFchs.txt')),
##             'newJECPayloadNames'        : string(','.join([
##                         os.path.join( paths.main, 'aux', 'JECfiles/Summer16_23Sep2016V3_MC_L1FastJet_AK8PFchs.txt') + "'",
##                         "'" + os.path.join( paths.main, 'aux', 'JECfiles/Summer16_23Sep2016V3_MC_L2Relative_AK8PFchs.txt') + "'",
##                         "'" + os.path.join( paths.main, 'aux', 'JECfiles/Summer16_23Sep2016V3_MC_L3Absolute_AK8PFchs.txt')]
##                                                           )),
##             'useRunRange'               : False,
##             'DEBUG'                     : False,
##             },
##       'QCD_Pt-600to800_MuEnrichedPt5_TuneCUETP8M1_13TeV_pythia8': {
##             'fatJetPtMin'               : 350,
##             'fatJetDoubleTagging'       : True,
##             'triggerSelection'          : string( ','.join(['HLT_BTagMu_AK8Jet300_Mu5' + "'", "'" + 'HLT_BTagMu_AK4Jet300_Mu5'])),
##             'triggerLogicIsOR'          : True,
##             'useJetProbaTree'           : True,
##             'useSoftDropSubjets'        : True,
##             'doJECUncert'               : True,
##             'jecUncPayloadName'         : string(os.path.join( paths.main, 'aux', 'JECfiles/Summer16_23Sep2016V3_MC_Uncertainty_AK8PFchs.txt')),
##             'newJECPayloadNames'        : string(','.join([
##                         os.path.join( paths.main, 'aux', 'JECfiles/Summer16_23Sep2016V3_MC_L1FastJet_AK8PFchs.txt') + "'",
##                         "'" + os.path.join( paths.main, 'aux', 'JECfiles/Summer16_23Sep2016V3_MC_L2Relative_AK8PFchs.txt') + "'",
##                         "'" + os.path.join( paths.main, 'aux', 'JECfiles/Summer16_23Sep2016V3_MC_L3Absolute_AK8PFchs.txt')]
##                                                           )),
##             'useRunRange'               : False,
##             'DEBUG'                     : False,
##             },
##       'QCD_Pt-800to1000_MuEnrichedPt5_TuneCUETP8M1_13TeV_pythia8': {
##             'fatJetPtMin'               : 350,
##             'fatJetDoubleTagging'       : True,
##             'triggerSelection'          : string( ','.join(['HLT_BTagMu_AK8Jet300_Mu5' + "'", "'" + 'HLT_BTagMu_AK4Jet300_Mu5'])),
##             'triggerLogicIsOR'          : True,
##             'useJetProbaTree'           : True,
##             'useSoftDropSubjets'        : True,
##             'doJECUncert'               : True,
##             'jecUncPayloadName'         : string(os.path.join( paths.main, 'aux', 'JECfiles/Summer16_23Sep2016V3_MC_Uncertainty_AK8PFchs.txt')),
##             'newJECPayloadNames'        : string(','.join([
##                         os.path.join( paths.main, 'aux', 'JECfiles/Summer16_23Sep2016V3_MC_L1FastJet_AK8PFchs.txt') + "'",
##                         "'" + os.path.join( paths.main, 'aux', 'JECfiles/Summer16_23Sep2016V3_MC_L2Relative_AK8PFchs.txt') + "'",
##                         "'" + os.path.join( paths.main, 'aux', 'JECfiles/Summer16_23Sep2016V3_MC_L3Absolute_AK8PFchs.txt')]
##                                                           )),
##             'useRunRange'               : False,
##             'DEBUG'                     : False,
##             },
##       'QCD_Pt-1000toInf_MuEnrichedPt5_TuneCUETP8M1_13TeV_pythia8': {
##             'fatJetPtMin'               : 350,
##             'fatJetDoubleTagging'       : True,
##             'triggerSelection'          : string( ','.join(['HLT_BTagMu_AK8Jet300_Mu5' + "'", "'" + 'HLT_BTagMu_AK4Jet300_Mu5'])),
##             'triggerLogicIsOR'          : True,
##             'useJetProbaTree'           : True,
##             'useSoftDropSubjets'        : True,
##             'doJECUncert'               : True,
##             'jecUncPayloadName'         : string(os.path.join( paths.main, 'aux', 'JECfiles/Summer16_23Sep2016V3_MC_Uncertainty_AK8PFchs.txt')),
##             'newJECPayloadNames'        : string(','.join([
##                         os.path.join( paths.main, 'aux', 'JECfiles/Summer16_23Sep2016V3_MC_L1FastJet_AK8PFchs.txt') + "'",
##                         "'" + os.path.join( paths.main, 'aux', 'JECfiles/Summer16_23Sep2016V3_MC_L2Relative_AK8PFchs.txt') + "'",
##                         "'" + os.path.join( paths.main, 'aux', 'JECfiles/Summer16_23Sep2016V3_MC_L3Absolute_AK8PFchs.txt')]
##                                                           )),
##             'useRunRange'               : False,
##             'DEBUG'                     : False,
##             },
##       },
##   },
##
## }

