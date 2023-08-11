////////////////////////////////////////////////////////////////////////
/// \file    SRInteraction.h
/// \brief   Reconstructed top-level particle interaction
/// \author  J. Wolcott <jwolcott@fnal.gov>

#ifndef DUNEANAOBJ_SRINTERACTION_H
#define DUNEANAOBJ_SRINTERACTION_H

#include "duneanaobj/StandardRecord/SRDirectionBranch.h"
#include "duneanaobj/StandardRecord/SRNeutrinoEnergyBranch.h"
#include "duneanaobj/StandardRecord/SRNeutrinoHypothesisBranch.h"
#include "duneanaobj/StandardRecord/SRRecoParticlesBranch.h"

namespace caf
{

  /// Top-level particle interaction.  (Usually neutrinos, but cosmics, etc. can live here too)
  class SRInteraction
  {
    public:
      long int id = -1;

      /// Reconstructed vertex location (if any)
      SRVector3D vtx;

      /// Hypotheses for this interaction's parent particle direction
      SRDirectionBranch dir;

      /// Hypotheses for this interaction's neutrino identity
      SRNeutrinoHypothesisBranch nuhyp;

      /// Hypotheses for this interaction's neutrino energy
      SRNeutrinoEnergyBranch Enu;

      /// Collections of reconstructed particles
      SRRecoParticlesBranch part;

      std::vector<std::size_t>    truth;              ///< Indices of SRTrueInteraction(s), if relevant (use this index in SRTruthBranch::nu to get them)
      std::vector<float>   truthOverlap;              ///< Fractional overlap between this reco interaction and each true interaction

  };

} // caf

#endif //DUNEANAOBJ_SRINTERACTION_H
