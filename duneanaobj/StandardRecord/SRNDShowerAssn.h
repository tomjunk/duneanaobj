/// \author  J. Wolcott <jwolcott@fnal.gov>
/// \date    Apr. 2023

#ifndef DUNEANAOBJ_SRNDSHOWERASSN_H
#define DUNEANAOBJ_SRNDSHOWERASSN_H

#include "duneanaobj/StandardRecord/SRShower.h"

namespace caf
{
  class SRNDShowerAssn
  {
    public:
      int larid         = -1;        ///< index of ND-LAr track
      int tmsid         = -1;        ///< index of TMS track
      int minervaid     = -1;        ///< index of MINERvA track

      SRShower shw;                  ///< new shower object generated from synthesis of matched parts
  };
}

#endif //DUNEANAOBJ_SRNDSHOWERASSN_H
