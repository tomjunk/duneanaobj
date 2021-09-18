////////////////////////////////////////////////////////////////////////
/// \file    SRParticleTruth.h
/// \brief   Truth information for a true particle
/// \author  J. Wolcott <jwolcott@fnal.gov>
/// \date    Sept. 2021
////////////////////////////////////////////////////////////////////////

#ifndef DUNEANAOBJ_SRPARTICLETRUTH_H
#define DUNEANAOBJ_SRPARTICLETRUTH_H

#include "duneanaobj/StandardRecord/SRLorentzVector.h"
#include "duneanaobj/StandardRecord/SRVector3D.h"

namespace caf
{
  class SRParticleTruth
  {
    public:
      int   trkID     = 0;   ///< GEANT trackId for particle
      int   pdg       = 0;   ///< PDG Code of the best matched truth particle
      int   motherpdg = 0;   ///< PDG Code of the mother of the best matched truth particle

      SRLorentzVector p;       ///< True energy 4-vector of the best matched particle
      SRLorentzVector motherp; ///< True energy 4-vector of the mother particle
      SRVector3D      start;   ///< Start point of true particle in detector coordinates (cm)
  };
}

#endif //DUNEANAOBJ_SRPARTICLETRUTH_H
