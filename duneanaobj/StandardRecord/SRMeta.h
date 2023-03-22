////////////////////////////////////////////////////////////////////////
/// \file    SRMeta.h
/// \brief   Metadata about the events in this file.
/// \author  J. Wolcott <jwolcott@fnal.gov>

#ifndef DUNEANAOBJ_SRMETA_H
#define DUNEANAOBJ_SRMETA_H

#include <limits>

namespace caf
{
  enum class Detector : std::size_t
  {
    kUnknown = 0,

    // full NDs in Phase I or Phase II
    kND_LAr  = 1,  /// 35-module liquid argon TPC  (forms part of movable PRISM detector concept)
    kND_TMS  = 2,  /// magnetized spectrometer/calorimeter (forms part of movable PRISM detector concept in Phase I)
    kND_SAND = 3, /// scintillator tracker and calorimeter, fixed on-axis in beam
    kND_GAr  = 4,  /// high-pressure gaseous argon TPC (forms part of movable PRISM detector concept in Phase II)

    // ND prototypes (more to add?)
    k2x2     = 5,  /// ND-LAr prototype
    kMINERvA = 6,     /// tracker & muon veto for 2x2; repurposed former MINERvA detector components

    // leaving some space for expansion ...

    // full FDs (Phase II modules TBD...)
    kFD_HD = 10, /// Horizontal drift (a.k.a. module 1)
    kFD_VD = 11,        /// Vertical drift (a.k.a. module 2)

    // space for modules 3 and 4...

    // FD prototypes  (we don't have any ProtoDUNE-VD data that will be CAFfed?)
    kProtoDUNE = 15,  /// Horizontal drift prototype

    _kLastDetector = 24  // to use in bitset sizing.  make it big enough that we'll never have to expand it ---> future-proof CAFs
  };

  class SRDetectorMeta
  {
    public:
      caf::Detector detector = Detector::kUnknown;  ///<   which detector are we describing?

      unsigned int run    = 0;
      unsigned int subrun = 0;
      unsigned int event  = 0;
      unsigned int subevt = 0;

      /// detector-dependent trigger type for the relevant readout window
      int triggertype = -1;

      unsigned long int readoutstart_s   = 0;   ///< GPS time of trigger readout start, seconds part
      unsigned int      readoutstart_ns  = 0;   ///< GPS time of trigger readout start, nanoseconds part
      unsigned long int readoutend_s     = 0;   ///< GPS time of trigger readout end, seconds part
      unsigned int      readoutend_ns    = 0;   ///< GPS time of trigger readout end, nanoseconds part

      double prism_offset = std::numeric_limits<double>::signaling_NaN();  ///< For NDs that are part of the PRISM system, where (in meters relative to the beam center) was the detector center located for this run?

  };

} // caf

#endif //DUNEANAOBJ_SRMETA_H
