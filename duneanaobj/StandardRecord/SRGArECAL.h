////////////////////////////////////////////////////////////////////////
// \file    SRGArECAL.h
// \brief   Reconstructed GAr ECAL cluster object
// \author  F. Martinez <f.martinezlopez@qmul.ac.uk>
// \date    Jan. 2023
////////////////////////////////////////////////////////////////////////

#ifndef DUNEANAOBJ_SRGARECAL_H
#define DUNEANAOBJ_SRGARECAL_H

#include "duneanaobj/StandardRecord/SRVector3D.h"
#include "duneanaobj/StandardRecord/SRParticleTruth.h"

namespace caf
{
  class SRGArECAL
  {
    public:
      SRVector3D position;  ///< ECAL cluster 3D position
      float E = -999.;      ///< Energy in MeV corresponding to this cluster

      int hits_in_cluster = -999; ///< Total number of ECAL hits in cluster

      int ecal_id = -999;  ///< GArSoft ECALId for ECAL cluster

      int trk_assn = -999;

      SRParticleTruth truth; ///< Best-match GEANT truth particle for this ECAL cluster
      float truth_fraction;  ///< 
  };

}

#endif //DUNEANAOBJ_SRGARECAL_H
