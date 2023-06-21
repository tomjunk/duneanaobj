#include "duneanaobj/StandardRecord/SRMINERvA.h"

namespace caf
{
  template <typename T>
  const T & SRMINERvA::Reco(const SRMINERvA& id)
  {
    static_assert(std::is_same_v<T, SRTrack> || std::is_same_v<T, SRShower>,
                  "Reco() only knows about SRTrack and SRShower!");

    if constexpr(std::is_same_v<T, SRTrack>)
      return ixn[id.ixn].tracks[id.idx];
    else if constexpr(std::is_same_v<T, SRShower>)
      return ixn[id.ixn].showers[id.idx];
  }

  // explicitly instantiate the template
  template const SRTrack & SRMINERvA::Reco<SRTrack>(const SRMINERvA& id);
  template const SRShower & SRMINERvA::Reco<SRShower>(const SRMINERvA& id);
}
