////////////////////////////////////////////////////////////////////////
/// \file    SRNeutrinoCandidate.h
/// \brief   Info for a reconstructed neutrino candidate
/// \author  J. Wolcott <jwolcott@fnal.gov>

#ifndef DUNEANAOBJ_SRNEUTRINOCANDIDATE_H
#define DUNEANAOBJ_SRNEUTRINOCANDIDATE_H

#include "duneanaobj/StandardRecord/SRRecoParticle.h"

namespace caf
{

  enum class NuIDMethod
  {
      kUnknown,
      kCVN,
      kPandora,
  };

  enum class NuEnergyMethod
  {
      kUnknown,
      kParticleSum,   ///< Sum of neutrino candidate's constituent particle energies
  };

  /// A reconstructed neutrino candidate
  class SRNeutrinoCandidate
  {
    private:
      static constexpr float NaN = std::numeric_limits<float>::signaling_NaN();

    public:
      /// The beam direction in the usual coordinate system (y vertical, beam axis in yz plane)
      static const SRVector3D kNeutrinoDir;

      float      score      = NaN;                     ///< Identifier algorithm score, if relevant
      NuIDMethod id_method  = NuIDMethod::kUnknown;    ///< Algorithm or method that decided this neutrino candidate (CVN, Pandora, ...)

      float          Enu      = NaN;                          ///< Inferred neutrino energy, if relevant (GeV)
      NuEnergyMethod E_method = NuEnergyMethod::kUnknown;     ///< Algorithm or method that decided the energy

      int nparticles = 0;                     ///< How many reconstructed particles are in this candidate
      std::vector<SRRecoParticle> particles;  ///< Reconstructed particles in this candidate.  Lepton should be first, if any

      ///@{
      /// \brief Convenience methods for lepton to avoid needing to dig around in particles vector.
      /// Searches #particles to find the PDG of the outgoing lepton.  Returns 0 if none found
      int LepPDG() const;

      /// Searches #particles to find angle of outgoing lepton relative to beam direction.  NOTE THAT THIS DOES NOT CORRECT FOR PRISM OFFSET.  Returns NaN if no lepton found
      float CosThetaLep() const;

      /// Searches #particles to find endpoint of outgoing lepton.  Returns an SRVector of NaN if no lepton found.
      const SRVector3D& LepEndpoint() const;

      ///@}

    private:
      /// Internal method that checks that the first particle in the #particles vector has a lepton PDG
      void EnsureLep() const;
  };

} // caf

#endif //DUNEANAOBJ_SRNEUTRINOCANDIDATE_H
