////////////////////////////////////////////////////////////////////////
// \file    SRGArTrack.h
// \brief   Reconstructed GAr track object
// \author  F. Martinez <f.martinezlopez@qmul.ac.uk>
// \date    Jan. 2023
////////////////////////////////////////////////////////////////////////
#ifndef DUNEANAOBJ_SRGARTRACK_H
#define DUNEANAOBJ_SRGARTRACK_H

#include "duneanaobj/StandardRecord/SRTrack.h"

namespace caf
{
  class SRGArTrack: public SRTrack
  {
    public:

      // GAr track characteristics
      float dEdx_fwd = -999.;   ///< dE/dx of track in forward fit
      float dEdx_bkwd = -999.;  ///< dE/dx of track in backward fit

      float p_fwd = -999.;      ///< Reco momentum of track in forward fit
      float p_bkwd = -999.;     ///< Reco momentum of track in forward fit

      float len_cm_fwd  = -999.; ///< Length of track in forward fit
      float len_cm_bkwd = -999.; ///< Length of track in backward fit

      int clusters_in_track = -999; ///< Total number of TPC clusters in track

      int garsoft_trk_id = -999;  ///< GArSoft trackId for track

      std::vector<int> pid_fwd;         ///< PID of track in forward fit
      std::vector<float> pid_prob_fwd;  ///< PID probability vector in forward fit
      std::vector<int> pid_bkwd;        ///< PID of track in backward fit
      std::vector<float> pid_prob_bkwd; ///< PID probability vector in backward fit

      float truth_fraction;  ///< Contribution of truth particle to reco object
  };

}

#if !defined(__GCCXML__) && !defined(__castxml__)
std::ostream & operator<<(std::ostream & stream, const caf::SRGArTrack & tr);
#endif

#endif //DUNEANAOBJ_SRGARTRACK_H
