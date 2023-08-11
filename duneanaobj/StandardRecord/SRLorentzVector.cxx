////////////////////////////////////////////////////////////////////////
// \file    SRLorentzVector.cxx
// \author  Christopher Backhouse - c.backhouse@ucl.ac.uk
////////////////////////////////////////////////////////////////////////

#include "duneanaobj/StandardRecord/SRLorentzVector.h"

#include <limits>

#include "TLorentzVector.h"

namespace caf
{
  SRLorentzVector::SRLorentzVector() :
      E (std::numeric_limits<float>::signaling_NaN()),
      px(std::numeric_limits<float>::signaling_NaN()),
      py(std::numeric_limits<float>::signaling_NaN()),
      pz(std::numeric_limits<float>::signaling_NaN())
  {}

  SRLorentzVector::SRLorentzVector(const TLorentzVector& v)
      : E(v.E()), px(v.X()), py(v.Y()), pz(v.Z())
  {
  }

  SRLorentzVector::operator TLorentzVector() const
  {
    return TLorentzVector(px, py, pz, E);
  }

  SRLorentzVector &SRLorentzVector::operator=(const TLorentzVector &vec)
  {
    E = vec.E();
    px = vec.Px();
    py = vec.Py();
    pz = vec.Pz();

    return *this;
  }

} // end namespace caf
////////////////////////////////////////////////////////////////////////
