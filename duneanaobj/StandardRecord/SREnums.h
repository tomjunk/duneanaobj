////////////////////////////////////////////////////////////////////////
// \file    SREnums.h
// \brief   Consolidated headers so that they can be included by Proxy
// \author  J. Wolcott <jwolcott@fnal.gov>
// \date    Mar. 2023
////////////////////////////////////////////////////////////////////////

#ifndef DUNEANAOBJ_SRENUMS_H
#define DUNEANAOBJ_SRENUMS_H

#include <cstddef>

namespace caf
{
  enum Detector : std::size_t
  {
    kUnknownDet = 0,

    // full NDs in Phase I or Phase II
    kND_LAr  = 1,  /// 35-module liquid argon TPC  (forms part of movable PRISM detector concept)
    kND_TMS  = 2,  /// magnetized spectrometer/calorimeter (forms part of movable PRISM detector concept in Phase I)
    kND_SAND = 3, /// scintillator tracker and calorimeter, fixed on-axis in beam
    kND_GAr  = 4,  /// high-pressure gaseous argon TPC (forms part of movable PRISM detector concept in Phase II)

    // ND prototypes (more to add?)
    k2x2     = 5,  /// ND-LAr prototype
    kMINERvA = 6,     /// tracker & muon veto for 2x2; repurposed former MINERvA detector components

    // leaving some space for expansion ...

    // full FDs (Phase II modules TBD...)
    kFD_HD = 10, /// Horizontal drift (a.k.a. module 1)
    kFD_VD = 11,        /// Vertical drift (a.k.a. module 2)

    // space for modules 3 and 4...

    // FD prototypes  (we don't have any ProtoDUNE-VD data that will be CAFfed?)
    kProtoDUNE = 15,  /// Horizontal drift prototype

    _kLastDetector = 24  // to use in bitset sizing.  make it big enough that we'll never have to expand it ---> future-proof CAFs
  };


  /// GEANT4 creation processes for particles
  enum G4Process
  {
    kG4primary=0,
    kG4CoupledTransportation=1,
    kG4FastScintillation=2,
    kG4Decay=3,
    kG4anti_neutronInelastic=4,
    kG4neutronInelastic=5,
    kG4anti_protonInelastic=6,
    kG4protonInelastic=7,
    kG4hadInelastic=8,
    kG4pipInelastic=9,
    kG4pimInelastic=10,
    kG4xipInelastic=11,
    kG4ximInelastic=12,
    kG4kaonpInelastic=13,
    kG4kaonmInelastic=14,
    kG4sigmapInelastic=15,
    kG4sigmamInelastic=16,
    kG4kaon0LInelastic=17,
    kG4kaon0SInelastic=18,
    kG4lambdaInelastic=19,
    kG4anti_lambdaInelastic=20,
    kG4He3Inelastic=21,
    kG4ionInelastic=22,
    kG4xi0Inelastic=23,
    kG4alphaInelastic=24,
    kG4tInelastic=25,
    kG4dInelastic=26,
    kG4anti_neutronElastic=27,
    kG4neutronElastic=28,
    kG4anti_protonElastic=29,
    kG4protonElastic=30,
    kG4hadElastic=31,
    kG4pipElastic=32,
    kG4pimElastic=33,
    kG4kaonpElastic=34,
    kG4kaonmElastic=35,
    kG4conv=36,
    kG4phot=37,
    kG4annihil=38,
    kG4nCapture=39,
    kG4nKiller=40,
    kG4muMinusCaptureAtRest=41,
    kG4muIoni=42,
    kG4eBrem=43,
    kG4CoulombScat=44,
    kG4hBertiniCaptureAtRest=45,
    kG4hFritiofCaptureAtRest=46,
    kG4photonNuclear=47,
    kG4muonNuclear=48,
    kG4electronNuclear=49,
    kG4positronNuclear=50,
    kG4compt=51,
    kG4eIoni=52,
    kG4muBrems=53,
    kG4hIoni=54,
    kG4muPairProd=55,
    kG4hPairProd=56,
    kG4LArVoxelReadoutScoringProcess=57,
    kG4ionIoni=58,
    kG4hBrems=59,
    kG4Transportation=60,
    kG4msc=61,
    kG4StepLimiter=62,
    kG4UNKNOWN=63
  };

  /// Known generators of neutrino interactions (extend as other generators are used)
  enum Generator
  {
    kUnknownGenerator = 0,
    kGENIE            = 1,
    kGIBUU            = 2,
    kNEUT             = 3
  };

  enum PartEMethod
  {
    kUnknownMethod,
    kRange,
    kMCS,
    kCalorimetry,
  };

  /// \brief Neutrino interaction categories.
  /// Periodically synchronized to GENIE (last update: GENIE 3.04.00) to avoid confusion
  /// (but we don't want a GENIE dependency for the StandardRecord so we maintain our own copy here).
  enum ScatteringMode
  {
    kUnknownMode               = -100,
    kQE                        = 1,
    kSingleKaon                = 2,
    kDIS                       = 3,
    kRes                       = 4,
    kCoh                       = 5,
    kDiffractive               = 6,
    kNuElectronElastic         = 7,
    kInvMuonDecay              = 8,
    kAMNuGamma                 = 9,
    kMEC                       = 10,
    kCohElastic                = 11,
    kInverseBetaDecay          = 12,
    kGlashowResonance          = 13,
    kIMDAnnihilation           = 14,
    kPhotonCoh                 = 15,
    kPhotonRes                 = 16,
    kDarkMatterElastic         = 101,
    kDarkMatterDIS             = 102,
    kDarkMatterElectron        = 103,
  };

  // ----------------------------------------------------------------------
  // now some enums that are used internally so one branch can easily refer to another

  struct TrueParticleID
  {
      enum PartType { kUnknown, kPrimary, kPrimaryBeforeFSI, kSecondary };

      int      ixn  = -1;       ///< Index of SRInteraction in the SRTruthBranch
      PartType type = kUnknown; ///< Which of the particle collections this particle lives in
      int      part = -1;       ///< Index of SRParticle in the SRInteraction
  };

  enum FD_RECO_STACK
  {
    kUnknownFDReco,
    kPandoraFD
  };

  enum NDLAR_RECO_STACK
  {
    kUnknownNDLArReco,
    kDeepLearnPhys,
    kPandoraNDLAr
  };

}


#endif //DUNEANAOBJ_SRENUMS_H
