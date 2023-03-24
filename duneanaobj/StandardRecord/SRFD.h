////////////////////////////////////////////////////////////////////////
// \file    SRFD.h
// \brief   FD reconstruction output.
// \author  J. Wolcott <jwolcott@fnal.gov>
// \date    Mar. 2023
////////////////////////////////////////////////////////////////////////

#ifndef DUNEANAOBJ_SRFD_H
#define DUNEANAOBJ_SRFD_H

#include "duneanaobj/StandardRecord/SRShower.h"
#include "duneanaobj/StandardRecord/SRTrack.h"

namespace caf
{

  class SRFD
  {
    public:
      // these are just placeholders.
      // need to coordinate w/ FD reco folks to put something sensible in here
      std::vector<SRTrack> tracks;
      std::size_t          ntracks  = 0;    // these counters used by SRProxy

      std::vector<SRShower> showers;
      std::size_t           nshowers = 0;
  };

} // caf

#endif //DUNEANAOBJ_SRFD_H
