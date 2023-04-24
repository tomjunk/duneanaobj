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

  // just a placeholder for the moment
  class SRMINERvA
  {
    public:
      std::vector<SRTrack> tracks;
      std::size_t          ntracks  = 0;
  };

} // caf

#endif //DUNEANAOBJ_SRMINERVA_H
