/// \author  J. Wolcott <jwolcott@fnal.gov> & F. Akbar <fakbar@ur.rochester.edu>
/// \date    Nov. 2021

#ifndef DUNEANAOBJ_SRTMS_H
#define DUNEANAOBJ_SRTMS_H

#include "SRTrack.h"

namespace caf
{
  class SRTMS
  {
    public:
      std::vector<caf::SRTrack> tracks;
      std::size_t               ntracks  = 0;

  };

}
#endif //DUNEANAOBJ_SRTMS_H
