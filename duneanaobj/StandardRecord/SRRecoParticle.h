////////////////////////////////////////////////////////////////////////
/// \file    SRRecoParticle.h
/// \brief   A general reconstructed particle container
/// \author  J. Wolcott <jwolcott@fnal.gov>

#ifndef DUNEANAOBJ_SRRECOPARTICLE_H
#define DUNEANAOBJ_SRRECOPARTICLE_H

#include "duneanaobj/StandardRecord/SRLorentzVector.h"
#include "duneanaobj/StandardRecord/SRVector3D.h"

namespace caf
{
  enum class PIDMethod
  {
      kUnknown,
      kCVN,
      kPandora,
      kDeepLearnPhysics,
  };

  enum class PartEMethod
  {
      kUnknown,
      kRange,
      kMCS,
      kCalorimetry,
      kRegCNN,
  };

  /// \brief Reconstructed particle candidate
  class SRRecoParticle
  {
    private:
      // make the uses of it below more readable
      static constexpr float NaN = std::numeric_limits<float>::signaling_NaN();

    public:
      int         pdg       = 0;                      ///< PDG code inferred for this particle.  todo: what if it's a "hadronic blob" type of thing?
      PIDMethod   id_method = PIDMethod::kUnknown;    ///< Method used to determine the PID for the particle

      float       score = NaN;                        ///< PID score for this particle, if relevant

      float       E        = NaN;                     ///< Reconstructed energy for this particle
      PartEMethod E_method = PartEMethod::kUnknown;   ///< Method used to determine energy for the particle
      SRVector3D  p;                                  ///< Reconstructed momentum for this particle

      SRVector3D  start;                              ///< Reconstructed start point of this particle
      SRVector3D  end;                                ///< Reconstructed end point of this particle, if that makes sense

      // todo: would we prefer some kind of "extents" thing so that we can make a decision about containment later?
      //       or should this be the responsibility of the reco module?  (what about stuff that crosses detector boundaries?...)
      bool        contained = false;
  };

} // caf

#endif //DUNEANAOBJ_SRRECOPARTICLE_H
