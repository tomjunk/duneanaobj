/// \author  J. Wolcott <jwolcott@fnal.gov> & F. Akbar <fakbar@ur.rochester.edu>
/// \date    Nov. 2021

#ifndef DUNEANAOBJ_SRTMS_H
#define DUNEANAOBJ_SRTMS_H

#include "duneanaobj/StandardRecord/SRTrack.h"

namespace caf
{
  /// A TMS reconstructed neutrino interaction
  class SRTMSInt
  {
    public:
      std::vector<caf::SRTrack> tracks;
      std::size_t               ntracks  = 0;
  };

  class SRTMS
  {
    public:
      /// The information needed to uniquely identify a TMS reco object
      struct ID
      {
        int        ixn  = -1;            ///< interaction ID
        int        idx  = -1;            ///< index in container
      };

      std::vector<SRTMSInt> ixn;       ///< Reconstructed interactions
      std::size_t nixn = 0;

      /// Convenience function for use mainly with SRNDTrackAssn.
      /// Given an interaction index and a track index, return the associated reco object
      const SRTrack & Track(const SRTMS::ID& id)
      {
        return ixn[id.ixn].tracks[id.idx];
      }

  };

}
#endif //DUNEANAOBJ_SRTMS_H
