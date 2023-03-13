////////////////////////////////////////////////////////////////////////
/// \file    StandardRecord.h
/// \brief   The StandardRecord is the primary top-level object in the Common Analysis File trees.
/// \author  C. Backhouse, C. Marshall, C. Wilkinson, and many others.  Overhauled in early 2023 by J. Wolcott <jwolcott@fnal.gov>
////////////////////////////////////////////////////////////////////////
#ifndef DUNEANAOBJ_STANDARDRECORD_H
#define DUNEANAOBJ_STANDARDRECORD_H

#include <array>
#include <bitset>
#include <vector>

#include "duneanaobj/StandardRecord/SRVector3D.h"

#include "duneanaobj/StandardRecord/SRBeamBranch.h"
#include "duneanaobj/StandardRecord/SRDetectorMetaBranch.h"
#include "duneanaobj/StandardRecord/SRCommonRecoBranch.h"
#include "duneanaobj/StandardRecord/SRNDBranch.h"
#include "duneanaobj/StandardRecord/SRTruthBranch.h"

/// Common Analysis Files
namespace caf
{
  
  /// \brief   The StandardRecord is the primary top-level object in the 
  ///          Common Analysis File trees.   
  
  class StandardRecord  
  {
    
  public:
    SRDetectorMetaBranch meta;

    SRBeamBranch beam;

    SRTruthBranch mc;

    SRCommonRecoBranch common;



    SRNDBranch nd;

  };
  
} // end namespace

#endif // DUNEANAOBJ_STANDARDRECORD_H
//////////////////////////////////////////////////////////////////////////////
