////////////////////////////////////////////////////////////////////////
/// \file    SRTrueParticle.h
/// \brief   True particle coming out of a probe particle's interaction w/ detector
/// \author  J. Wolcott <jwolcott@fnal.gov>  [but mostly copied from NOvA/SBN sources]

#ifndef DUNEANAOBJ_SRTRUEPARTICLE_H
#define DUNEANAOBJ_SRTRUEPARTICLE_H

#include <vector>

#include "duneanaobj/StandardRecord/SREnums.h"
#include "duneanaobj/StandardRecord/SRLorentzVector.h"
#include "duneanaobj/StandardRecord/SRVector3D.h"

namespace caf
{

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

      TrueParticleID  ancestor_id;      ///< The primary particle this particle descended from, if relevant

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
