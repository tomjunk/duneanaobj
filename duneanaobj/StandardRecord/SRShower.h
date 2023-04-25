////////////////////////////////////////////////////////////////////////
/// \file    SRShower.h
/// \brief   Reconstructed shower object
/// \author  J. Wolcott <jwolcott@fnal.gov>
/// \date    Sept. 2021
////////////////////////////////////////////////////////////////////////

#ifndef DUNEANAOBJ_SRSHOWER_H
#define DUNEANAOBJ_SRSHOWER_H

#include "duneanaobj/StandardRecord/SRRecoObjBase.h"
#include "duneanaobj/StandardRecord/SRVector3D.h"

namespace caf
{
  class SRShower : public SRRecoObjBase
  {
    public:
      SRVector3D start;      ///< Shower 3D start point [cm]
      SRVector3D direction;  ///< Shower 3D end point [cm]
      float Evis = -999.;    ///< Visible energy in voxels corresponding to this shower

      SRTrueParticle truth;  ///< Best-match GEANT truth particle for this shower
  };

}

#endif //DUNEANAOBJ_SRSHOWER_H
