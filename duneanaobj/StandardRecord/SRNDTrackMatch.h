/// \author  J. Wolcott <jwolcott@fnal.gov> & F. Akbar <fakbar@ur.rochester.edu>
/// \date    Nov. 2021

#ifndef DUNEANAOBJ_SRNDTRACKMATCH_H
#define DUNEANAOBJ_SRNDTRACKMATCH_H

namespace caf
{
  class SRNDTrackMatch
  {
    public:
      int larid         = -1;        ///< index of ND-LAr track
      int tmsid         = -1;        ///< index of TMS track
      float transdispl  = -999.;     ///< perpendicular distance between the two tracks at longitudinal position of matching point
      float angdispl    = -999.;     ///< angular difference between the two tracks at longitudinal position of matching point
  };
}

#endif //DUNEANAOBJ_SRNDTRACKMATCH_H
