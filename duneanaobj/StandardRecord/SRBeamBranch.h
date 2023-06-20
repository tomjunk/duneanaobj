////////////////////////////////////////////////////////////////////////
/// \file    SRBeamBranch.h
/// \brief   Beam-related information
/// \author  J. Wolcott <jwolcott@fnal.gov>  [but mostly copied from NOvA/SBN sources]

#ifndef DUNEANAOBJ_SRBEAMBRANCH_H
#define DUNEANAOBJ_SRBEAMBRANCH_H

#include <cmath>
#include <limits>

namespace caf
{
  class SRBeamBranch
  {
    private:
      // save on typing below
      constexpr static float NaN = std::numeric_limits<float>::signaling_NaN();

    public:
      bool                 ismc;      ///< data or simulated beam pulse?

      bool                 isgoodpulse         = true;      ///< Was the pot for a pulse good? (only applicable to data)
      unsigned long int    pulsetimesec        = 0;         ///< pulse time in seconds [s]
      unsigned long int    pulsetimensec       = 0;         ///< pulse time in nanoseconds [ns]
      unsigned long int    gpspulsetimesec     = 0;         ///< pulse time from GPS [s]
      unsigned long int    gpspulsetimensec    = 0;         ///< pulse time from GPS [ns]
      signed long long int deltapulsetimensec  = -9999999;  ///< Delta time [ns]
      float                pulsepot            = NaN;       ///< POT in pulse including factor of 1e12 so that a user does not have to apply this correction
      float                hornI               = NaN;       ///< Horn current [kA]

      bool isFHC() const  { return hornI > 0; };                                 ///< Checks #hornI to see if the polarity is positive --> this is FHC
      bool is0HC() const  { return std::abs(hornI) < 1; };                       ///< Checks #hornI to see if the polarity is zero
      bool isRHC() const  { return hornI < 0; }                                  ///< Checks #hornI to see if the polarity is negative --> this is RHC

      // someday when we have real beam we'll have beam parameters here to include.
      // this is just a reminder/placeholder for now.

  };
}

#endif //DUNEANAOBJ_SRBEAMBRANCH_H
