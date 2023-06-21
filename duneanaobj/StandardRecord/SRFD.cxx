#include "duneanaobj/StandardRecord/SRFD.h"

namespace caf
{
  template <typename T>
  const T & SRFD::Reco(const SRFDID& id)
  {
    static_assert(std::is_same_v<T, SRTrack> || std::is_same_v<T, SRShower>,
                  "Reco() only knows about SRTrack and SRShower!");

    const std::vector<SRFDInt> * ints = nullptr;
    if (id.reco == kPandoraFD)
      ints = &pandora;
    else
      throw std::domain_error("Unknown reco stack: " + std::to_string(id.reco));

    if constexpr(std::is_same_v<T, SRTrack>)
      return (*ints)[id.ixn].tracks[id.idx];
    else if constexpr(std::is_same_v<T, SRShower>)
      return (*ints)[id.ixn].showers[id.idx];
  }

  // explicitly instantiate the template
  template const SRTrack & SRFD::Reco<SRTrack>(const SRFDID& id);
  template const SRShower & SRFD::Reco<SRShower>(const SRFDID& id);
}
