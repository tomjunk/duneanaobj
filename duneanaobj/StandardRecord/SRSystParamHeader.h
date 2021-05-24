#ifndef DUNEANAOBJ_SRSYSTPARAMHEADER_H
#define DUNEANAOBJ_SRSYSTPARAMHEADER_H

#include <string>
#include <vector>

namespace caf
{
  class SRSystParamHeader
  {
  public:
    SRSystParamHeader();
    ~SRSystParamHeader();

    int nshifts;
    std::string name;
    int id;
  };

} // end namespace

#endif // DUNEANAOBJ_SRSYSTPARAMHEADER_H
//////////////////////////////////////////////////////////////////////////////
