////////////////////////////////////////////////////////////////////////
/// \file    SRRecoParticle.h
/// \brief   information for a reco particle
/// \author  L. Di Noto
/// \date    Jan. 2023
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

      int primary=0;              //1 if primary, 0 otherwise
      int   reco_trkid     = 0;   //trackid of reco particle
      int   pdg       = 0;   // PDG Code of the reco particle
      int   mother_trkid = 0;   //  trackid of the mother accordingly to the reco

      int trkid_best_match;           //track id of the best match
      SRParticleTruth particle_true; //Particle best match

      SRLorentzVector p;       ///< Reco energy 4-vector 
      SRVector3D      start;   ///< Reco start point of the  particle in detector coordinates (cm)
	
      //to be added if necessary
      //SRTrack         track_p;     //associated track
      //SRShower        shower_p;    //associated shower

  };
}

#endif //DUNEANAOBJ_SRRECOPARTICLE_H
