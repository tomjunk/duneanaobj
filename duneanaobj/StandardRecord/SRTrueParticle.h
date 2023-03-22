////////////////////////////////////////////////////////////////////////
/// \file    SRTrueParticle.h
/// \brief   True particle coming out of a probe particle's interaction w/ detector
/// \author  J. Wolcott <jwolcott@fnal.gov>  [but mostly copied from NOvA/SBN sources]

#ifndef DUNEANAOBJ_SRTRUEPARTICLE_H
#define DUNEANAOBJ_SRTRUEPARTICLE_H

#include <vector>

#include "duneanaobj/StandardRecord/SRLorentzVector.h"
#include "duneanaobj/StandardRecord/SRVector3D.h"

namespace caf
{

  /// GEANT4 creation processes for particles
  enum class G4Process
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
  };// g4_process_

  /// True particle in the particle record.
  /// (Most particles we store come straight from GENIE (so-called "primaries"),
  ///  but occasionally we want info about other intermediaries as well)
  class SRTrueParticle
  {
    private:
      // just to keep the typing under control below
      static constexpr float NaN = std::numeric_limits<float>::signaling_NaN();

    public:
      int      pdg             = 0;     ///< Particle
      int      G4ID            = -1;    ///< ID of the particle (taken from GEANT4 -- -1 if this particle is not propogated by G4)
      int      interaction_id  = -1;    ///< True interaction ID of the source of this particle
      float    time            = NaN;   ///< Generation time at true interaction vertex [ns]

      SRLorentzVector p;                ///< Momentum at generation point [GeV/c]
      SRVector3D      start_pos;        ///< Particle generation position [cm]
      SRVector3D      end_pos;          ///< Particle end position (decay, interaction, stop) [cm]

      unsigned int parent;                 ///< GEANT4 trackID of parent particle from this particle
      std::vector<unsigned int> daughters; ///< GEANT4 trackIDs of daughter particles from this particle

      G4Process   start_process;   ///< GEANT4 process that created this particle (kPrimary means 'came from GENIE')
      G4Process   end_process;     ///< End G4 process of the particle
  };

} // caf

#endif //DUNEANAOBJ_SRTRUEPARTICLE_H
