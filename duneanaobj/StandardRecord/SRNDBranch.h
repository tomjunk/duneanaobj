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
#include "duneanaobj/StandardRecord/SRMINERvA.h"
#include "duneanaobj/StandardRecord/SRNDTrackAssn.h"
#include "duneanaobj/StandardRecord/SRSAND.h"
#include "duneanaobj/StandardRecord/SRTMS.h"

namespace caf
{
  class SRNDBranch
  {
    public:
      SRNDLAr   lar;
      SRGAr     gar;
      SRTMS     tms;
      SRSAND    sand;

      /// MINERvA detector pieces used in conjunction
      /// with 2x2 prototype in NuMI beam
      SRMINERvA minerva;

      std::size_t ntrkmatch = 0;
      std::vector<caf::SRNDTrackAssn> trkmatch;
  };
}

#endif //DUNEANAOBJ_SRNDBRANCH_H
