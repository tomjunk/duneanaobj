/// \author  J. Wolcott <jwolcott@fnal.gov>
/// \date    Apr. 2023


#ifndef DUNEANAOBJ_SRNDASSNBRANCH_H
#define DUNEANAOBJ_SRNDASSNBRANCH_H

#include <vector>

#include "duneanaobj/StandardRecord/SRNDShowerAssn.h"
#include "duneanaobj/StandardRecord/SRNDTrackAssn.h"

namespace caf
{
  class SRNDTrkAssnBranch
  {
    public:
      std::size_t nextrap = 0;
      std::vector<SRNDTrackAssn> extrap;  ///<  Associations made using extrapolation of track dirs
  };

  class SRNDShwAssnBranch
  {
    public:
      std::size_t nextrap = 0;
      std::vector<SRNDShowerAssn> extrap;  ///<  Associations made using extrapolation of track dirs
  };

}

#endif //DUNEANAOBJ_SRNDASSNBRANCH_H
