#include "duneanaobj/StandardRecord/SRTruthBranch.h"

namespace caf
{
  const SRTrueParticle * SRTruthBranch::Particle(const TrueParticleID & id) const
  {
    if (id.type == TrueParticleID::kUnknown || id.ixn < 0 || id.part < 0)
      return nullptr;

    if (id.type == TrueParticleID::PartType::kPrimary)
      return &nu[id.ixn].prim[id.part];
    else if (id.type == TrueParticleID::PartType::kPrimaryBeforeFSI)
      return &nu[id.ixn].prefsi[id.part];
    else if (id.type == TrueParticleID::PartType::kSecondary)
      return &nu[id.ixn].sec[id.part];
    else
      throw std::domain_error("Unknown PartType: " + std::to_string(id.type));
  }
}
