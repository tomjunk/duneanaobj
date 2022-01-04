////////////////////////////////////////////////////////////////////////
// \file    SRGAr.h
// \brief   ND-GAr reconstruction output.
// \author  J. Wolcott <jwolcott@fnal.gov>
// \date    Jan. 2022
////////////////////////////////////////////////////////////////////////
#ifndef DUNEANAOBJ_SRGAR_H
#define DUNEANAOBJ_SRGAR_H

#include "duneanaobj/StandardRecord/SRTrack.h"
#include "duneanaobj/StandardRecord/SRShower.h"

namespace caf
{
  /// ND-GAr reconstruction output
  class SRGAr
  {
    public:
      // for the moment, these "pseudo-reco" fields are just copied from the old ND_CAFMaker branches.
      // once GAr reco is integrated they should be replaced with proper reco

      int nFSP;
      std::vector<int> pdg;
      std::vector<float> ptrue;
      std::vector<float> trkLen;
      std::vector<float> trkLenPerp;
      std::vector<float> partEvReco;
      int gastpc_pi_pl_mult;
      int gastpc_pi_min_mult;
  };

}
#endif //DUNEANAOBJ_SRGAR_H
