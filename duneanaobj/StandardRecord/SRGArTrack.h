////////////////////////////////////////////////////////////////////////
// \file    SRGArTrack.h
// \brief   Reconstructed GAr track object
// \author  F. Martinez <f.martinezlopez@qmul.ac.uk>
// \date    Jan. 2023
////////////////////////////////////////////////////////////////////////
#ifndef DUNEANAOBJ_SRGARTRACK_H
#define DUNEANAOBJ_SRGARTRACK_H

#include "duneanaobj/StandardRecord/SRVector3D.h"
#include "duneanaobj/StandardRecord/SRParticleTruth.h"

namespace caf
{
  class SRGArTrack
  {
    public:
      SRVector3D start;      ///< Track 3D start point
      SRVector3D end;        ///< Track 3D end point
      SRVector3D dir;        ///< Unit vector representing estimate of track direction *taken from start point*
      SRVector3D enddir;     ///< Unit vector representing estimate of track direction *taken from endpoint*

      // Track characteristics
      float dEdx_F = -999.;  ///< dE/dx of track in forward fit
      float dEdx_B = -999.;  ///< dE/dx of track in backward fit

      float p_F = -999.;     ///< Reco momentum of track in forward fit
      float p_B = -999.;     ///< Reco momentum of track in forward fit

      float len_cm_F = -999.; ///< Length of track in forward fit
      float len_cm_B = -999.; ///< Length of track in backward fit

      int clusters_in_track = -999; ///< Total number of TPC clusters in track

      int trk_id = -999;  ///< GArSoft trackId for track

      std::vector<int> pid_F;      ///< PID of track in forward fit
      std::vector<float> pid_prob_F; ///< PID probability vector in forward fit
      std::vector<int> pid_B;      ///< PID of track in backward fit
      std::vector<float> pid_prob_B; ///< PID probability vector in backward fit

      SRParticleTruth truth; ///< Best-match GEANT truth particle for this track
      float truth_fraction;  ///< Contribution of truth particle to reco object
  };

}

#if !defined(__GCCXML__) && !defined(__castxml__)
std::ostream & operator<<(std::ostream & stream, const caf::SRGArTrack & tr);
#endif

#endif //DUNEANAOBJ_SRGARTRACK_H
