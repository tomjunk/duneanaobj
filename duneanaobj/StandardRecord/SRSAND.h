////////////////////////////////////////////////////////////////////////
// \file    SRSAND.h
// \brief   SAND reconstruction output.
// \author  L.Di Noto
// \date    Jan. 2023
////////////////////////////////////////////////////////////////////////
#ifndef DUNEANAOBJ_SRSAND_H
#define DUNEANAOBJ_SRSAND_H

#include "duneanaobj/StandardRecord/SRTrack.h"
#include "duneanaobj/StandardRecord/SRShower.h"
#include "duneanaobj/StandardRecord/SRRecoParticle.h"


namespace caf
{
  /// SAND reconstruction output
  class SRSAND
  {
    public:
     
      char reco_target_nucleus;

      std::vector<SRTrack> tracks;
      std::size_t          ntracks  = 0;

      std::vector<SRShower> showers;
      std::size_t           nshowers = 0;
  
      std::vector<SRRecoParticle> recoparticles;
      std::size_t           nparticles = 0;
     
    };

}
#endif //DUNEANAOBJ_SRSAND_H
