////////////////////////////////////////////////////////////////////////
/// \file    SRCommonRecoBranch.h
/// \brief   Top-line reco outputs common to all detectors
/// \author  J. Wolcott <jwolcott@fnal.gov>

#ifndef DUNEANAOBJ_SRCOMMONRECOBRANCH_H
#define DUNEANAOBJ_SRCOMMONRECOBRANCH_H

#include "duneanaobj/StandardRecord/SRNeutrinoCandidate.h"
#include "duneanaobj/StandardRecord/SRVector3D.h"


namespace caf
{

  class SRCommonRecoBranch
  {
    public:
      int nnuhyp = 0;  ///< How many neutrino hypotheses were reconstructed
      /// This event reconstructed under various hypotheses.  It's up to the relevant CAFMaker to choose how to fill these.
      std::vector<SRNeutrinoCandidate> nuhyp;

      int bestidx = -1;  ///< Which of the hypotheses had the highest score?
      int numuidx = -1;
      int nueidx = -1;
      int nutauidx = -1;
      int ncidx = -1;

      SRVector3D  vtx;     ///< Reconstructed vertex location


  };

} // caf

#endif //DUNEANAOBJ_SRCOMMONRECOBRANCH_H
