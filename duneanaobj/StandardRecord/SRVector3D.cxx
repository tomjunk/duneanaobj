////////////////////////////////////////////////////////////////////////
// \file    SRLorentzVector.cxx
// \author  Christopher Backhouse - c.backhouse@ucl.ac.uk
////////////////////////////////////////////////////////////////////////

#include "duneanaobj/StandardRecord/SRVector3D.h"

#include <cmath>
#include <limits>

namespace caf
{
  SRVector3D::SRVector3D() :
      x(std::numeric_limits<float>::signaling_NaN()),
      y(std::numeric_limits<float>::signaling_NaN()),
      z(std::numeric_limits<float>::signaling_NaN())
  {}

  SRVector3D::SRVector3D(float _x, float _y, float _z) :
      x(_x), y(_y), z(_z)
  {}

  SRVector3D::SRVector3D(const TVector3& v) :
      x(v.X()), y(v.Y()), z(v.Z())
  {}

  void SRVector3D::SetXYZ(float _x, float _y, float _z)
  {
    x = _x;
    y = _y;
    z = _z;
  }

  SRVector3D::operator TVector3() const
  {
    return TVector3(x, y, z);
  }

  SRVector3D &SRVector3D::operator=(const TVector3& vec)
  {
    SetXYZ(vec.X(), vec.Y(), vec.Z());
    return *this;
  }

}

std::ostream &operator<<(std::ostream &stream, const caf::SRVector3D &vec)
{
  stream << "(" << vec.x << "," << vec.y << "," << vec.z << ")";
  return stream;
}
