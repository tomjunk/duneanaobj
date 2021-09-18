////////////////////////////////////////////////////////////////////////
/// \file    SRTrack.cxx
/// \brief   Reconstructed track object
/// \author  J. Wolcott <jwolcott@fnal.gov>
/// \date    Sept. 2021
////////////////////////////////////////////////////////////////////////

#include "duneanaobj/StandardRecord/SRTrack.h"

std::ostream &operator<<(std::ostream &stream, const caf::SRTrack &tr)
{
  stream << "caf::SRTrack with start=" << tr.start << "  end=" << tr.end << "  end_dir=" << tr.end_dir;
  return stream;
}
