////////////////////////////////////////////////////////////////////////
/// \file    SRVector3D.h
/// \brief   3-vector class with more efficient storage than TVector3.
///          Ported from NOvA StandardRecord.
/// \author  C. Backhouse <c.backhouse@ucl.ac.uk>
/// \date    Sept. 2021
////////////////////////////////////////////////////////////////////////

#ifndef DUNEANAOBJ_SRVECTOR3D_H
#define DUNEANAOBJ_SRVECTOR3D_H

#if !defined(__GCCXML__) && !defined(__castxml__)

#include <cmath>
#include <iostream>

#include "TVector3.h"

#endif


namespace caf
{
  /// A 3-vector with more efficient storage than TVector3
  class SRVector3D
  {
    public:
      SRVector3D();
      SRVector3D(float x, float y, float z);

#if !defined(__GCCXML__) && !defined(__castxml__)
      /// Easy conversion from TVector3
      explicit SRVector3D(const TVector3& v);
#endif

      virtual ~SRVector3D() = default;

      void SetXYZ(float x, float y, float z);

#if !defined(__GCCXML__) && !defined(__castxml__)
      /// Easy conversion to and from TVector3
      operator TVector3() const;
      SRVector3D & operator=(const TVector3& vec);

      void SetX(float _x){x = _x;}
      void SetY(float _y){y = _y;}
      void SetZ(float _z){z = _z;}

      float X() const {return x;}
      float Y() const {return y;}
      float Z() const {return z;}

      // The more common TVector3 operations, mostly for use with TTree::Draw
      //
      // NB: you need to specify the initial "rec." when using these
      float Mag2() const {return x*x+y*y+z*z;}
      float Mag() const {return sqrt(Mag2());}
      float Dot(const SRVector3D& v) const {return x*v.x + y*v.y + z*v.z;}
      SRVector3D Unit() const
      {
        const float m = Mag();
        return SRVector3D(x/m, y/m, z/m);
      }

      // a few more of them...
      SRVector3D operator+(const SRVector3D & other) const { return SRVector3D(x + other.x, y + other.y, z + other.z); }
      SRVector3D operator-(const SRVector3D & other) const {return SRVector3D(x - other.x, y - other.y, z - other.z); }
#endif

      // -----------------------------

      float x;
      float y;
      float z;
  };

}

#if !defined(__GCCXML__) && !defined(__castxml__)
// make writing these out easier
std::ostream & operator<<(std::ostream & stream, const caf::SRVector3D & vec);
#endif

#endif //DUNEANAOBJ_SRVECTOR3D_H
