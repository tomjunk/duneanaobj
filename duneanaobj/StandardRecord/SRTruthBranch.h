////////////////////////////////////////////////////////////////////////
/// \file    SRTruthBranch.h
/// \brief   Top level truth info
/// \author  J. Wolcott <jwolcott@fnal.gov>


#ifndef DUNEANAOBJ_SRTRUTHBRANCH_H
#define DUNEANAOBJ_SRTRUTHBRANCH_H

#include "duneanaobj/StandardRecord/SRTrueInteraction.h"

namespace caf
{

  class SRTruthBranch
  {
    public:
      std::vector<SRTrueInteraction> nu;   ///< Vector of true nus, cosmics, etc. contributing to this reco interaction candidate
      std::size_t nnu = 0;
  };

} // caf

#endif //DUNEANAOBJ_SRTRUTHBRANCH_H
