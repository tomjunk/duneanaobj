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
#include "duneanaobj/StandardRecord/SRNDAssnBranch.h"
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

      caf::SRNDTrkAssnBranch trkmatch;
      caf::SRNDShwAssnBranch shwmatch;
  };
}

#endif //DUNEANAOBJ_SRNDBRANCH_H
