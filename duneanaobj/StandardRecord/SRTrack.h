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
      SRVector3D dir;        ///< Unit vector representing estimate of track direction *taken from start point*
      SRVector3D enddir;     ///< Unit vector representing estimate of track direction *taken from endpoint*

      float Evis  = -999.;   ///< Visible energy in voxels corresponding to this track

      // Track characteristics
      float len_gcm3 = -999.; ///< Track length in g/cm3
      float E = -999; ///< Track energy in MeV
      float len_cm = -999; ///< Track length in centimeter (actual physical distance)
      float qual = -999; ///< Track quality metric (in TMS, equivalent to "hits in track"/"total hits in event"

      SRParticleTruth truth; ///< Best-match GEANT truth particle for this track
  };

}

#if !defined(__GCCXML__) && !defined(__castxml__)
std::ostream & operator<<(std::ostream & stream, const caf::SRTrack & tr);
#endif

#endif //DUNEANAOBJ_SRTRACK_H
