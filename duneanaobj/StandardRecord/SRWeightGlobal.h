#ifndef DUNEANAOBJ_SRWEIGHTGLOBAL_H
#define DUNEANAOBJ_SRWEIGHTGLOBAL_H

#include "duneanaobj/StandardRecord/SRSystParamHeader.h"

#include <vector>

namespace caf
{
  class SRWeightGlobal
  {

  public:
    SRWeightGlobal();
    ~SRWeightGlobal();

    std::vector<SRSystParamHeader> params;
  };

} // end namespace

#endif // DUNEANAOBJ_SRWEIGHTGLOBAL_H
//////////////////////////////////////////////////////////////////////////////
