////////////////////////////////////////////////////////////////////////
/// \file    SRTrack.h
/// \brief   Reconstructed track object
/// \author  J. Wolcott <jwolcott@fnal.gov>
/// \date    Sept. 2021
////////////////////////////////////////////////////////////////////////
#ifndef DUNEANAOBJ_SRTRACK_H
#define DUNEANAOBJ_SRTRACK_H

#include "duneanaobj/StandardRecord/SRVector3D.h"
#include "duneanaobj/StandardRecord/SRParticleTruth.h"

namespace caf
{
  class SRTrack
  {
    public:
      SRVector3D start;      ///< Track 3D start point
      SRVector3D end;        ///< Track 3D end point
      SRVector3D end_dir;    ///< Unit vector representing estimate of track direction *taken from endpoint*

      SRParticleTruth truth; ///< Best-match GEANT truth particle for this track
  };

}

#endif //DUNEANAOBJ_SRTRACK_H
