////////////////////////////////////////////////////////////////////////
/// \file    SRVertexBranch.h
/// \brief   Reconstructed event vertex
/// \author  J. Wolcott <jwolcott@fnal.gov>

#ifndef DUNEANAOBJ_SRVERTEXBRANCH_H
#define DUNEANAOBJ_SRVERTEXBRANCH_H

namespace caf
{

  class SRVertexBranch
  {
    public:
      // these are just guesses, we'll need to fill them in with the actual reco tools we're using ASAP
      SRVector3D dlp;      ///< Vertex location estimated by DeepLearnPhysics machine learning reco stack
      SRVector3D pandora;  ///< Vertex location estimated by Pandora reco stack
  };

} // caf

#endif //DUNEANAOBJ_SRVERTEXBRANCH_H
