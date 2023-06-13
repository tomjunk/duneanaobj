////////////////////////////////////////////////////////////////////////
// \file    SRNDBranch.h
// \brief   Branch for ND info.
// \author  J. Wolcott <jwolcott@fnal.gov>
// \date    Jan. 2022
////////////////////////////////////////////////////////////////////////

#ifndef DUNEANAOBJ_SRNDBRANCH_H
#define DUNEANAOBJ_SRNDBRANCH_H

#include "duneanaobj/StandardRecord/SRGAr.h"
#include "duneanaobj/StandardRecord/SRNDLAr.h"
#include "duneanaobj/StandardRecord/SRNDTrackAssn.h"
#include "duneanaobj/StandardRecord/SRTMS.h"
#include "duneanaobj/StandardRecord/SRSAND.h"


namespace caf
{
  class SRNDBranch
  {
    public:
      SRNDLAr lar;
      SRGAr   gar;
      SRTMS   tms;
      SRSAND  sand;

      std::size_t ntrkmatch = 0;
      std::vector<caf::SRNDTrackAssn> trkmatch;
    
      std::size_t LArID = 0;
      std::size_t TMSID = 0;
      float Residual = 0.0;
      float cosTheta = 0.0;
  };
}

#endif //DUNEANAOBJ_SRNDBRANCH_H
