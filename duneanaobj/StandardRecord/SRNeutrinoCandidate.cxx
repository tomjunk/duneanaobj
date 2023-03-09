////////////////////////////////////////////////////////////////////////
/// \file    SRNeutrinoCandidate.cxx
/// \brief   Info for a reconstructed neutrino candidate
/// \author  J. Wolcott <jwolcott@fnal.gov>

#include "SRNeutrinoCandidate.h"

#include <cmath>
#include <stdexcept>
#include <vector>

namespace caf
{
  // beam is rotated 5.8ish degrees in y-z plane
  static const SRVector3D kNeutrinoDir {0, -std::sinf(0.101), std::cosf(0.101)};

  // ------------------------------------------------------
  float SRNeutrinoCandidate::CosThetaLep() const
  {
    if (nparticles < 1)
      return NaN;

    EnsureLep();

    if (particles[0].p.Mag() <= 1e-6)
      throw std::domain_error("Lepton momentum is 0!  Can't compute its direction relative to beam.");

    return caf::kNeutrinoDir.Dot(particles[0].p) / particles[0].p.Mag();
  }

  // ------------------------------------------------------
  void SRNeutrinoCandidate::EnsureLep() const
  {
    if (nparticles < 1)
      return;

    auto absPDG = std::abs(particles[0].pdg);
    if (absPDG < 11 || absPDG > 16)
      throw std::domain_error("First entry of SRNeutrinoCandidate::particles is not a lepton!  It has PDG: " + std::to_string(particles[0].pdg));
  }

  // ------------------------------------------------------
  const SRVector3D &SRNeutrinoCandidate::LepEndpoint() const
  {
    SRVector3D ret;
    if (nparticles < 1)
      return ret;

    EnsureLep();

    return particles[0].end;
  }

  // ------------------------------------------------------
  int SRNeutrinoCandidate::LepPDG() const
  {
    if (nparticles < 1)
      return 0;

    EnsureLep();

    return particles[0].pdg;
  }

}
