import FWCore.ParameterSet.Config as cms

from FWCore.ParameterSet.VarParsing import VarParsing

options = VarParsing('python')

options.register('FileNames', 'FileNames',
    VarParsing.multiplicity.singleton,
    VarParsing.varType.string,
    "Name of list of input files"
    )
options.register('outFilename', 'bTagValPlots.root',
    VarParsing.multiplicity.singleton,
    VarParsing.varType.string,
    "Output file name"
    )
options.register('makeSlimmedTree', True,
    VarParsing.multiplicity.singleton,
    VarParsing.varType.bool,
    "Make slimmed trees for SF measurements"
    )
options.register('reportEvery', 1000,
    VarParsing.multiplicity.singleton,
    VarParsing.varType.int,
    "Report every N events (default is N=1000)"
    )
options.register('triggerSelection', '',
    VarParsing.multiplicity.list,
    VarParsing.varType.string,
    "Trigger selection"
    )
options.register('triggerLogicIsOR', True,
    VarParsing.multiplicity.singleton,
    VarParsing.varType.bool,
    'Trigger logic: True = OR, False = AND'
    )
options.register('useJetProbaTree', False,
    VarParsing.multiplicity.singleton,
    VarParsing.varType.bool,
    "Use jet probability tree"
    )
options.register('applyFatJetMuonTagging', False,
    VarParsing.multiplicity.singleton,
    VarParsing.varType.bool,
    "Apply muon tagging to fat jets (require 1 muon in fatjet)"
    )
options.register('applyFatJetMuonTaggingV2', False,
    VarParsing.multiplicity.singleton,
    VarParsing.varType.bool,
    "Apply muon tagging to fat jets (require at least 1 muon in a subjet)"
    )
options.register('applyFatJetBTagging', False,
    VarParsing.multiplicity.singleton,
    VarParsing.varType.bool,
    "Apply b tagging to fat jets"
    )
options.register('fatJetDoubleTagging', False,
    VarParsing.multiplicity.singleton,
    VarParsing.varType.bool,
    "Require fat jets to be double-tagged"
    )
options.register('fatJetDoubleBTagging', False,
    VarParsing.multiplicity.singleton,
    VarParsing.varType.bool,
    "Require fat jets to be double-b-tagged"
    )
options.register('fatJetDoubleSVBTagging', False,
    VarParsing.multiplicity.singleton,
    VarParsing.varType.bool,
    "Require fat jets to be double-SV-b-tagged"
    )
options.register('usePrunedSubjets', False,
    VarParsing.multiplicity.singleton,
    VarParsing.varType.bool,
    "Process pruned subjets"
    )
options.register('useSoftDropSubjets', False,
    VarParsing.multiplicity.singleton,
    VarParsing.varType.bool,
    "Process soft drop subjets"
    )
options.register('doBFrag', True,
    VarParsing.multiplicity.singleton,
    VarParsing.varType.bool,
    'Do b fragmentation reweighting'
    )
options.register('doBFragUp', True,
    VarParsing.multiplicity.singleton,
    VarParsing.varType.bool,
    'Do b fragmentation reweighting up'
    )
options.register('doBFragDown', True,
    VarParsing.multiplicity.singleton,
    VarParsing.varType.bool,
    'Do b fragmentation reweighting down'
    )
options.register('doCDFrag', True,
    VarParsing.multiplicity.singleton,
    VarParsing.varType.bool,
    'Do c->D fragmentation reweighting'
    )
options.register('doCFrag', True,
    VarParsing.multiplicity.singleton,
    VarParsing.varType.bool,
    'Do c fragmentation reweighting'
    )
options.register('doK0L', True,
    VarParsing.multiplicity.singleton,
    VarParsing.varType.bool,
    'Do K0 and lambda reweighting'
    )
options.register('doNtracksReweighting', False,
    VarParsing.multiplicity.singleton,
    VarParsing.varType.bool,
    'Do ntracks reweighting'
    )
options.register('applySubJetMuonTagging', False,
    VarParsing.multiplicity.singleton,
    VarParsing.varType.bool,
    "Apply muon tagging to subjets"
    )
options.register('applySubJetBTagging', False,
    VarParsing.multiplicity.singleton,
    VarParsing.varType.bool,
    "Apply b tagging to subjets"
    )
options.register('dynamicMuonSubJetDR', False,
    VarParsing.multiplicity.singleton,
    VarParsing.varType.bool,
    "Use dynamic muon-subjet dR requirement"
    )
options.register('useFlavorCategories', True,
    VarParsing.multiplicity.singleton,
    VarParsing.varType.bool,
    "Use flavor categories for MC distributions"
    )
options.register('useRelaxedMuonID', True,
    VarParsing.multiplicity.singleton,
    VarParsing.varType.bool,
    "Use relaxed muon ID"
    )
options.register('fatJetAbsEtaMax', 2.4,
    VarParsing.multiplicity.singleton,
    VarParsing.varType.float,
    "Maximum abs(eta)"
    )
options.register('fatJetPtMin', 250.,
    VarParsing.multiplicity.singleton,
    VarParsing.varType.float,
    "Minimum fat jet Pt"
    )
options.register('fatJetPtMax', 1.E6,
    VarParsing.multiplicity.singleton,
    VarParsing.varType.float,
    "Maximum fat jet Pt"
    )
options.register('usePrunedMass', False,
    VarParsing.multiplicity.singleton,
    VarParsing.varType.bool,
    "Use pruned mass cut"
    )
options.register('useSoftDropMass', False,
    VarParsing.multiplicity.singleton,
    VarParsing.varType.bool,
    "Use softdrop mass cut"
    )
options.register('fatJetGroomedMassMin', 0.,
    VarParsing.multiplicity.singleton,
    VarParsing.varType.float,
    "Minimum fat jet softdrop/pruned mass"
    )
options.register('fatJetGroomedMassMax', 1.E6,
    VarParsing.multiplicity.singleton,
    VarParsing.varType.float,
    "Maximum fat jet softdrop/pruned mass"
    )
options.register('fatJetTau21Min', 0.0, #added by rizki
    VarParsing.multiplicity.singleton,
    VarParsing.varType.float,
    "tau2/tau1 jet substructure min cut for fat jets"
    )
options.register('fatJetTau21Max', 1., #added by rizki
    VarParsing.multiplicity.singleton,
    VarParsing.varType.float,
    "tau2/tau1 jet substructure max cut for fat jets"
    )
options.register('fatJetBDiscrCut', 0.244,
    VarParsing.multiplicity.singleton,
    VarParsing.varType.float,
    "B discriminator cut for fat jets"
    )
options.register('fatJetDoubleSVBDiscrMin', -0.20,
    VarParsing.multiplicity.singleton,
    VarParsing.varType.float,
    "Double SV b discriminator cut for fat jets"
    )
options.register('fatJetDoubleSVBDiscrMax', 1.0,
    VarParsing.multiplicity.singleton,
    VarParsing.varType.float,
    "Double SV b discriminator cut for fat jets"
    )
options.register('subJetBDiscrMin', 0.605,
    VarParsing.multiplicity.singleton,
    VarParsing.varType.float,
    "B discriminator min for subjets"
    )
options.register('subJetBDiscrMax', 1.000,
    VarParsing.multiplicity.singleton,
    VarParsing.varType.float,
    "B discriminator max for subjets"
    )
options.register('SFbShift', 0.,
    VarParsing.multiplicity.singleton,
    VarParsing.varType.float,
    "Shift in SFb in units of sigmas"
    )
options.register('SFlShift', 0.,
    VarParsing.multiplicity.singleton,
    VarParsing.varType.float,
    "Shift in SFl in units of sigmas"
    )
options.register('MuonJetPtRatio', 0.5,
    VarParsing.multiplicity.singleton,
    VarParsing.varType.float,
    "pT(muon)/pT(Jet) for Muon Tagging"
    )
options.register('doPUReweightingOfficial', False,
    VarParsing.multiplicity.singleton,
    VarParsing.varType.bool,
    "Do pileup reweighting"
    )
options.register('doPUReweightingNPV', False,
    VarParsing.multiplicity.singleton,
    VarParsing.varType.bool,
    "Do pileup reweighting"
    )
options.register('doFatJetPtReweighting', False,
    VarParsing.multiplicity.singleton,
    VarParsing.varType.bool,
    'Do fat jet pt reweighting'
    )
options.register('doSubJetPtReweighting', False,
    VarParsing.multiplicity.singleton,
    VarParsing.varType.bool,
    'Do subjet pt reweighting'
    )
options.register('applySFs', False,
    VarParsing.multiplicity.singleton,
    VarParsing.varType.bool,
    "Apply b-tagging SFs"
    )
options.register('btagCSVFile', 'CSVv2_4invfb.csv',
    VarParsing.multiplicity.singleton,
    VarParsing.varType.string,
    "CSV file containing b-tagging SFs"
    )
options.register('btagOperatingPoint', 0,
    VarParsing.multiplicity.singleton,
    VarParsing.varType.int,
    "B-tagging opertaint point for CSVv2. Set to 'loose' by default"
    )
options.register('btagMeasurementType', "comb",
    VarParsing.multiplicity.singleton,
    VarParsing.varType.string,
    "Measurement type: combined or ttbar"
    )
options.register('btagSFType', "central",
    VarParsing.multiplicity.singleton,
    VarParsing.varType.bool,
    "Apply b-tagging SFs"
    )
options.register('FileFatJetPtWt', "/afs/cern.ch/user/d/devdatta/afswork/CMSREL/BTagging/CMSSW_8_0_12/src/RecoBTag/BTagValidation/test/JetPtWts/FatJet_pt_all_wt.root",
    VarParsing.multiplicity.singleton,
    VarParsing.varType.string,
    "File with data/MC weights for fat jet pT reweighting"
    )
options.register('FileSubJetPtWt', "/afs/cern.ch/user/d/devdatta/afswork/CMSREL/BTagging/CMSSW_8_0_12/src/RecoBTag/BTagValidation/test/JetPtWts/SoftDropSubJet_pt_all_wt.root", 
    VarParsing.multiplicity.singleton,
    VarParsing.varType.string,
    "File with data/MC weights for subjet pT reweighting"
    )
options.register('FileNtracksWt', "/afs/cern.ch/user/r/rsyarif/workHere/HbbTagVal/Mar21-2016_reproduceCommPlotsForPreApproval/CMSSW_7_6_3/src/RecoBTag/BTagValidation/test/rizki_signalMC_GluGLu/dataMCntracks/ntracks_dataMC_weight_single.root",
    VarParsing.multiplicity.singleton,
    VarParsing.varType.string,
    "File with data/MC weights for fat jet ntracks reweighting"
    )

options.parseArguments()

if options.usePrunedSubjets and options.useSoftDropSubjets:
  print "Warning: both pruned and soft drop subjets selected. Only pruned subjets will be processed."
  print "!!!Select either pruned subjets with 'usePrunedSubjets' or soft drop subjets with 'useSoftDropSubjets'."
elif not options.usePrunedSubjets and not options.useSoftDropSubjets:
  print "!!!Warning: no subjets will be processed.!!!"
  print "!!!Select either pruned subjets with 'usePrunedSubjets' or soft drop subjets with 'useSoftDropSubjets'."

#print options

process = cms.Process("BTagVal")

process.load("FWCore.MessageService.MessageLogger_cfi")
process.MessageLogger.cout = cms.untracked.PSet(
    threshold = cms.untracked.string('INFO'),
    )

process.maxEvents = cms.untracked.PSet( input = cms.untracked.int32(1) ) # Keep as such maxEvents == 1

process.source = cms.Source("EmptySource")

## Output file
#ext=""
#if options.usePrunedSubjets: 
#  ext="_WithPrunedSubjets"
#elif options.useSoftDropSubjets: 
#  ext="_withSoftDropSubjets"
#outFilename = options.outFilename+ext+".root"

process.TFileService = cms.Service("TFileService",
    fileName = cms.string(options.outFilename)
    )

from inputFiles_cfi import *
from RecoBTag.PerformanceMeasurements.bTagAnalyzerCommon_cff import *

print bTagAnalyzerCommon.TriggerPathNames 

process.btagval = cms.EDAnalyzer('BTagValidation',
    MaxEvents              = cms.int32(options.maxEvents),
    ReportEvery            = cms.int32(options.reportEvery),
    makeSlimmedTree        = cms.bool(options.makeSlimmedTree), 
    UseJetProbaTree        = cms.bool(options.useJetProbaTree),
    InputTTreeEvtInfo      = cms.string('btaganaFatJets/ttree'),
    InputTTree             = cms.string('btaganaFatJets/ttree'),
    InputFiles             = cms.vstring(FileNames[options.FileNames]),
    UseFlavorCategories    = cms.bool(options.useFlavorCategories),
    UseRelaxedMuonID       = cms.bool(options.useRelaxedMuonID),
    ApplyFatJetMuonTagging = cms.bool(options.applyFatJetMuonTagging),
    ApplyFatJetMuonTaggingV2 = cms.bool(options.applyFatJetMuonTaggingV2),
    ApplyFatJetBTagging    = cms.bool(options.applyFatJetBTagging),
    FatJetDoubleTagging    = cms.bool(options.fatJetDoubleTagging),
    FatJetDoubleBTagging   = cms.bool(options.fatJetDoubleBTagging),
    FatJetDoubleSVBTagging = cms.bool(options.fatJetDoubleSVBTagging),
    UsePrunedSubjets       = cms.bool(options.usePrunedSubjets),
    UseSoftDropSubjets     = cms.bool(options.useSoftDropSubjets),
    DoBFrag                = cms.bool(options.doBFrag),
    DoBFragUp              = cms.bool(options.doBFragUp),
    DoBFragDown            = cms.bool(options.doBFragDown),                                 
    DoCDFrag               = cms.bool(options.doCDFrag),
    DoCFrag                = cms.bool(options.doCFrag),
    DoK0L                  = cms.bool(options.doK0L),         
    ApplySubJetMuonTagging = cms.bool(options.applySubJetMuonTagging),
    ApplySubJetBTagging    = cms.bool(options.applySubJetBTagging),
    DynamicMuonSubJetDR    = cms.bool(options.dynamicMuonSubJetDR),
    FatJetBDiscrCut        = cms.double(options.fatJetBDiscrCut),
    FatJetDoubleSVBDiscrMin= cms.double(options.fatJetDoubleSVBDiscrMin), 
    FatJetDoubleSVBDiscrMax= cms.double(options.fatJetDoubleSVBDiscrMax), 
    SubJetBDiscrMin        = cms.double(options.subJetBDiscrMin),
    SubJetBDiscrMax        = cms.double(options.subJetBDiscrMax),
    FatJetPtMin            = cms.double(options.fatJetPtMin),
    FatJetPtMax            = cms.double(options.fatJetPtMax),
    UsePrunedMass          = cms.bool(options.usePrunedMass),
    UseSoftDropMass        = cms.bool(options.useSoftDropMass),
    FatJetGroomedMassMin  = cms.double(options.fatJetGroomedMassMin),
    FatJetGroomedMassMax  = cms.double(options.fatJetGroomedMassMax),
    File_PVWt              = cms.string(''),
    Hist_PVWt              = cms.string(''),
    File_PUDistMC          = cms.string('PUDistMC_2016_25ns_SpringMC_PUScenarioV1_PoissonOOTPU.root'),
    Hist_PUDistMC          = cms.string('pileup'),
    File_PUDistData        = cms.string('RunII2016_PUXsec69000nb.root'),
    File_PUDistDataLow     = cms.string('RunII2016_PUXsec65550nb.root'),
    File_PUDistDataHigh    = cms.string('RunII2016_PUXsec72450nb.root'),
    Hist_PUDistData        = cms.string('pileup'),
    File_FatJetPtWt        = cms.string(options.FileFatJetPtWt), 
    Hist_FatJetPtWt        = cms.string('FatJet_pt_all_wt'),
    File_SubJetPtWt        = cms.string(options.FileSubJetPtWt), 
    Hist_SubJetPtWt        = cms.string('SoftDropSubJet_pt_all_wt'),
    File_NtracksWt         = cms.string(options.FileNtracksWt), 
    Hist_NtracksWt         = cms.string('nTracksweight_mc_data'),
    FatJetTau21Min         = cms.double(options.fatJetTau21Min), #added by rizki
    FatJetTau21Max         = cms.double(options.fatJetTau21Max), #added by rizki
FatJetAbsEtaMax            = cms.double(options.fatJetAbsEtaMax), #added by rizki
    SFbShift               = cms.double(options.SFbShift),
    SFlShift               = cms.double(options.SFlShift),
MuonJetPtRatio             = cms.double(options.MuonJetPtRatio),
    DoPUReweightingOfficial= cms.bool(options.doPUReweightingOfficial),
    DoPUReweightingNPV     = cms.bool(options.doPUReweightingNPV),
    DoNtracksReweighting  = cms.bool(options.doNtracksReweighting),
    DoFatJetPtReweighting  = cms.bool(options.doFatJetPtReweighting),
    DoSubJetPtReweighting  = cms.bool(options.doSubJetPtReweighting),
    TriggerSelection       = cms.vstring( # OR of all listed triggers applied, empty list --> no trigger selection applied
        options.triggerSelection
        ),
    TriggerPathNames       = bTagAnalyzerCommon.TriggerPathNames,
    triggerLogicIsOR      = cms.bool(options.triggerLogicIsOR),
    ApplySFs               = cms.bool(options.applySFs),
    btagCSVFile            = cms.string(options.btagCSVFile),
    btagOperatingPoint     = cms.int32(options.btagOperatingPoint),
    btagMeasurementType    = cms.string(options.btagMeasurementType),
    btagSFType             = cms.string(options.btagSFType), 
)

#process.btagvalsubjetmu = process.btagval.clone(
    #ApplySubJetMuonTagging = cms.bool(not options.applySubJetMuonTagging),
#)

#process.btagvalsubjetbtag = process.btagval.clone(
    #ApplySubJetMuonTagging = cms.bool(not options.applySubJetMuonTagging),
    #ApplySubJetBTagging = cms.bool(True),
#)

process.p = cms.Path(process.btagval)
#process.p = cms.Path(process.btagval + process.btagvalsubjetmu + process.btagvalsubjetbtag)
