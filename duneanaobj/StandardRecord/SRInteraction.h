////////////////////////////////////////////////////////////////////////
/// \file    SRInteraction.h
/// \brief   Reconstructed top-level particle interaction
/// \author  J. Wolcott <jwolcott@fnal.gov>

#ifndef DUNEANAOBJ_SRINTERACTION_H
#define DUNEANAOBJ_SRINTERACTION_H

#include "duneanaobj/StandardRecord/SRNeutrinoEnergyBranch.h"
#include "duneanaobj/StandardRecord/SRNeutrinoHypothesisBranch.h"
#include "duneanaobj/StandardRecord/SRRecoParticlesBranch.h"

namespace caf
{

  /// Top-level particle interaction.  (Usually neutrinos, but cosmics, etc. can live here too)
  class SRInteraction
  {
    public:
      /// Reconstructed vertex location (if any)
      SRVector3D vtx;

      /// Hypotheses for this interaction's neutrino identity
      SRNeutrinoHypothesisBranch nuhyp;

      /// Hypotheses for this interaction's neutrino energy
      SRNeutrinoEnergyBranch Enu;

      /// Collections of reconstructed particles
      SRRecoParticlesBranch part;

  };

} // caf

#endif //DUNEANAOBJ_SRINTERACTION_H
