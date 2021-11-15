/// \author  J. Wolcott <jwolcott@fnal.gov> & F. Akbar <fakbar@ur.rochester.edu>
/// \date    Nov. 2021

#ifndef DUNEANAOBJ_SRNDTRACKMATCH_H
#define DUNEANAOBJ_SRNDTRACKMATCH_H

namespace caf
{
  class SRNDTrackMatch
  {
    public:
      int larTrkIdx;
      int tmsTrkIdx;
      float xverseDispl;
      float angularDsipl;
  };
}

#endif //DUNEANAOBJ_SRNDTRACKMATCH_H
