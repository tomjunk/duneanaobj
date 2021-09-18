////////////////////////////////////////////////////////////////////////
// \file    SRNDLAr.h
// \brief   ND-LAr reconstruction output.
// \author  J. Wolcott <jwolcott@fnal.gov>
// \date    Sept. 2021
////////////////////////////////////////////////////////////////////////
#ifndef DUNEANAOBJ_SRNDLAR_H
#define DUNEANAOBJ_SRNDLAR_H

#include "duneanaobj/StandardRecord/SRTrack.h"

namespace caf
{
  /// ND-LAr reconstruction output
  class SRNDLAr
  {
    public:
      std::vector<SRTrack> tracks;
      std::size_t          ntracks  = 0;
  };

}
#endif //DUNEANAOBJ_SRNDLAR_H
