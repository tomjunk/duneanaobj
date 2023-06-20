////////////////////////////////////////////////////////////////////////
/// \file    SRFDBranch.h
/// \brief   Branch for non-shared FD info.
/// \author  J. Wolcott <jwolcott@fnal.gov>
/// \date    Mar. 2022
////////////////////////////////////////////////////////////////////////

#ifndef DUNEANAOBJ_SRFDBRANCH_H
#define DUNEANAOBJ_SRFDBRANCH_H

#include "duneanaobj/StandardRecord/SRFD.h"

namespace caf
{

  class SRFDBranch
  {
    public:
      SRFD hd;  ///< Horizontal drift, a.k.a. Module 1
      SRFD vd;  ///< Vertical drift, a.k.a. Module 2

      // deal with modules 3 & 4 when we have a better idea what they are?

      SRFD pd_hd;  ///< Horizontal drift ProtoDUNE.  todo: do we really need a separate branch for it?
      SRFD pd_vd;  ///< Vertical drift ProtoDUNE.  todo: do we really need a separate branch for it?

  };

} // caf

#endif //DUNEANAOBJ_SRFDBRANCH_H
