#include "duneanaobj/StandardRecord/SRTruthBranch.h"

namespace caf
{
  const SRTrueParticle & SRTruthBranch::Particle(const SRTrueParticle::ID & id) const
  {
    if (id.type == SRTrueParticle::ID::PartType::kPrimary)
      return nu[id.ixn].prim[id.part];
    else if (id.type == SRTrueParticle::ID::PartType::kPrimaryBeforeFSI)
      return nu[id.ixn].prefsi[id.part];
    else if (id.type == SRTrueParticle::ID::PartType::kSecondary)
      return nu[id.ixn].sec[id.part];
    else
      throw std::domain_error("Unknown PartType: " + std::to_string(id.type));
  }
}
