////////////////////////////////////////////////////////////////////////
// \file    SRGArTrack.cpp
// \brief   Reconstructed GAr track object
// \author  F. Martinez <f.martinezlopez@qmul.ac.uk>
// \date    Jan. 2023
////////////////////////////////////////////////////////////////////////

#include "duneanaobj/StandardRecord/SRGArTrack.h"

std::ostream &operator<<(std::ostream &stream, const caf::SRGArTrack &tr)
{
  stream << "caf::SRGArTrack with start=" << tr.start << "  end=" << tr.end << "   start dir=" << tr.dir << "  end_dir=" << tr.enddir << std::endl;
  return stream;
}
