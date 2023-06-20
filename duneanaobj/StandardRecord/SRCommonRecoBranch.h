////////////////////////////////////////////////////////////////////////
/// \file    SRCommonRecoBranch.h
/// \brief   Top-line reco outputs common to all detectors
/// \author  J. Wolcott <jwolcott@fnal.gov>

#ifndef DUNEANAOBJ_SRCOMMONRECOBRANCH_H
#define DUNEANAOBJ_SRCOMMONRECOBRANCH_H

#include "duneanaobj/StandardRecord/SRInteractionBranch.h"


namespace caf
{

  /// Shared reconstructed info across all (?) detectors
  class SRCommonRecoBranch
  {
    public:
      SRInteractionBranch ixn;
  };

} // caf

#endif //DUNEANAOBJ_SRCOMMONRECOBRANCH_H
