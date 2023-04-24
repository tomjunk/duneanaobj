////////////////////////////////////////////////////////////////////////
// \file    SRNDLAr.h
// \brief   ND-LAr reconstruction output.
// \author  J. Wolcott <jwolcott@fnal.gov>
// \date    Mar. 2023
////////////////////////////////////////////////////////////////////////

#ifndef DUNEANAOBJ_SRMINERVA_H
#define DUNEANAOBJ_SRMINERVA_H

#include <vector>
#include "duneanaobj/StandardRecord/SRTrack.h"

namespace caf
{
  /// A MINERvA reconstructed interaction
  class SRMINERvAInt
  {
    public:
      std::vector<caf::SRTrack> tracks;
      std::size_t               ntracks  = 0;
  };

  // just a placeholder for the moment
  class SRMINERvA
  {
    public:
      /// The information needed to uniquely identify a TMS reco object
      struct ID
      {
        int        ixn  = -1;            ///< interaction ID
        int        idx  = -1;            ///< index in container
      };

      std::vector<SRMINERvAInt> ixn;       ///< Reconstructed interactions
      std::size_t nixn = 0;

      /// Convenience function for use mainly with SRNDTrackAssn.
      /// Given an interaction index and a track index, return the associated reco object
      const SRTrack & Track(const SRMINERvA::ID& id)
      {
        return ixn[id.ixn].tracks[id.idx];
      }
  };

} // caf

#endif //DUNEANAOBJ_SRMINERVA_H
