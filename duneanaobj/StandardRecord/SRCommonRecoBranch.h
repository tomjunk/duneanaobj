////////////////////////////////////////////////////////////////////////
/// \file    SRCommonRecoBranch.h
/// \brief   Top-line reco outputs common to all detectors
/// \author  J. Wolcott <jwolcott@fnal.gov>

#ifndef DUNEANAOBJ_SRCOMMONRECOBRANCH_H
#define DUNEANAOBJ_SRCOMMONRECOBRANCH_H

#include "duneanaobj/StandardRecord/SRNeutrinoEnergyBranch.h"
#include "duneanaobj/StandardRecord/SRNeutrinoHypothesisBranch.h"
#include "duneanaobj/StandardRecord/SRRecoParticlesBranch.h"
#include "duneanaobj/StandardRecord/SRVertexBranch.h"


namespace caf
{

  /// Shared reconstructed info across all (?) detectors
  class SRCommonRecoBranch
  {
    public:
      /// Hypotheses for this neutrino interaction's identity
      SRNeutrinoHypothesisBranch nuhyp;

      /// Hypotheses for this neutrino interaction's energy
      SRNeutrinoEnergyBranch Enu;

      /// Reconstructed vertex location
      SRVertexBranch vtx;

      /// Collections of reconstructed particles
      SRRecoParticlesBranch part;
  };

} // caf

#endif //DUNEANAOBJ_SRCOMMONRECOBRANCH_H
