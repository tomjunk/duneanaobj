////////////////////////////////////////////////////////////////////////
/// \file    SRRecoParticle.h
/// \brief   information for a reco particle
/// \author  L. Di Noto
/// \date    Apr. 2023
////////////////////////////////////////////////////////////////////////

#ifndef DUNEANAOBJ_SRRECOPARTICLE_H
#define DUNEANAOBJ_SRRECOPARTICLE_H

#include "duneanaobj/StandardRecord/SRLorentzVector.h"
#include "duneanaobj/StandardRecord/SRVector3D.h"

namespace caf
{
  class SRRecoParticle
  {
    public:

      bool  IsPrimary=false;      //Primary Particle is a particle coming out from neutrino vertex 
      int   pdg       = 0;   // PDG Code of the reco particle

      SRParticleTruth particle_true; //True particle association

      SRLorentzVector p;       ///< Reco energy 4-vector 
      SRVector3D      start;   ///< Reco start point of the  particle in detector coordinates (cm)
	
  };
}

#endif //DUNEANAOBJ_SRRECOPARTICLE_H
