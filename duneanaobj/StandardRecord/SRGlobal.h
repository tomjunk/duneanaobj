#ifndef DUNEANAOBJ_SRGLOBAL_H
#define DUNEANAOBJ_SRGLOBAL_H

#include "duneanaobj/StandardRecord/SRWeightGlobal.h"

namespace caf
{
  class SRGlobal
  {
  public:
    SRGlobal();
    ~SRGlobal();

    SRWeightGlobal wgts;
  };

} // end namespace

#endif // DUNEANAOBJ_SRGLOBAL_H
//////////////////////////////////////////////////////////////////////////////
