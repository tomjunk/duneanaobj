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


    // Dummy PRISM variables. These are required to make PRISM code in CAFAna
    // compile but are NOT FILLED BY CURRENT CAFMAKER. They should not be used
    // for anything, and should be removed ASAP (effective immediately as of
    // their reluctant addition in September 2022) and replaced with proper
    // variables within the standard structure that /are/ filled.
    double perPOTWeight = -1;
    double NDMassCorrWeight = -1;
    double SpecialRunWeight = -1;
    int SpecialHCRunId = -1;
    int OffAxisFluxBin = -1;
    int OffAxisFluxConfig = -1;
    double abspos_x = -1;
    double EVisReco_ND = -1;
    double EVisReco_numu = -1;
    double EVisReco_nue = -1;
    double HadEVisReco_ND = -1;
    double HadEVisReco_FD = -1;
    double VisTrue_NDFD = -1;
    double ProxyRecoLepE = -1;
    double eRecProxy = -1;
    double HadE = -1;
    double ePipm = -1;
    double eTotalPi0 = -1;
  };
  
} // end namespace

#endif // DUNEANAOBJ_STANDARDRECORD_H
//////////////////////////////////////////////////////////////////////////////
