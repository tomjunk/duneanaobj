////////////////////////////////////////////////////////////////////////
/// \file    SRTrueInteraction.h
/// \brief   True neutrino/cosmic (or other top-level particle) interaction
/// \author  J. Wolcott <jwolcott@fnal.gov>  [but mostly copied from NOvA/SBN sources]

#ifndef DUNEANAOBJ_SRTRUEINTERACTION_H
#define DUNEANAOBJ_SRTRUEINTERACTION_H

#include <limits>

#include "duneanaobj/StandardRecord/SREnums.h"
#include "duneanaobj/StandardRecord/SRTrueParticle.h"
#include "duneanaobj/StandardRecord/SRVector3D.h"

// This is pretty ugly. The proper fix is to get a new version of castxml that
// is built with at least clang v9.
// See https://github.com/CastXML/CastXML/issues/178
#ifndef __castxml__
#include <string>
#else
namespace std{class string{};}
#endif
#include <vector>

namespace caf
{

   /// \brief True interaction of probe particle with detector.  Usually neutrinos, but occasionally cosmics etc.
   class SRTrueInteraction
   {
     private:
       // just to keep the typing under control below
       static constexpr float NaN = std::numeric_limits<float>::signaling_NaN();

     public:
       bool  isvtxcont = false;   ///< Is true vertex is within detector?  If not, might be a rock particle or cosmic

       int   pdg     = 0;         ///< PDG code of probe particle
       int   pdgorig = 0;         ///< Initial (unoscillated) PDG code of probe neutrino (may be different than `pdg` if this file is a 'swap' file)

       bool           iscc      = false;                          ///< CC (true) or NC/interference (false)
       ScatteringMode mode      = ScatteringMode::kUnknownMode;   ///< Interaction mode
       int            targetPDG = 0;                              ///< PDG code of struck target

       /// PDG code of struck nucleon (or, in the case of MEC, struck nucleon-nucleon pair).
       /// For MEC, the codes are: 2000000200 --> nn,  2000000201 --> np,  2000000202 --> pp
       int   hitnuc = 0;

       float       E         = NaN; ///< True energy [GeV]
       SRVector3D  vtx;             ///< Interaction vertex position in detector coord. [cm]
       SRVector3D  momentum;        ///< Neutrino three-momentum
       SRVector3D  position;        ///< Neutrino interaction position

       float time         = NaN;    ///< True interaction time
       float bjorkenX     = NaN;    ///< Bjorken x = (k-k')^2/(2*p.q) [Dimensionless]
       float inelasticity = NaN;    ///< Inelasticity y = (p.q) / (k.p) = q0 / Enu
       float Q2           = NaN;    ///< Invariant four-momentum transfer from lepton to nuclear system
       float q0           = NaN;    ///< Energy transferred from lepton to nuclear system (in lab frame)
       float modq         = NaN;    ///< Magnitude of three-momentum transferred from lepton to nuclear system, |q| (in lab frame)
       float W            = NaN;    ///< Hadronic invariant mass W [GeV^2]
       float t            = NaN;    ///< Kinematic t
       float baseline     = NaN;    ///< Distance from decay to interaction [m]

       // GENIE truth stuff
       bool  ischarm    = false;    ///< Did neutrino scatter from a charmed quark?
       bool  isseaquark = false;    ///< Did neutrino scatter from a sea quark?
       int   resnum     = 0;        ///< Resonance number, straight from GENIE
       float xsec       = NaN;      ///< xsec for thrown interaction, in 1/GeV^2, straight from GENIE

       float genweight = NaN;       ///< Weight, if any, assigned by the generator

       SRVector3D prod_vtx;              ///< Neutrino production vertex [cm; beam coordinates]
       SRVector3D parent_dcy_mom;        ///< Neutrino parent momentum at decay [GeV; beam coordinates]
       int        parent_dcy_mode = -1;  ///< Parent hadron/muon decay mode
       int        parent_pdg      = 0;   ///< PDG Code of parent particle ID
       float      parent_dcy_E    = NaN; ///< Neutrino parent energy at decay [GeV]
       float      imp_weight      = NaN; ///< Importance weight from flux file


       Generator                   generator = Generator::kUnknownGenerator;  ///< The generator that created this neutrino interaction
       std::vector<unsigned int>   genVersion;                                ///< Version of the generator that created this neutrino interaction
       std::string                 genConfigString;                           ///< String associated with generator configuration. (For GENIE 3+, this is the "Comprehensive Model Configuration".)

       int                         nprim = 0;        ///< Number of primary daughters
       std::vector<SRTrueParticle> prim;             ///< Primary daughters.  The lepton always comes first in this vector.
       int                         nprefsi = 0;      ///< How many primary daughters there were prior to FSI
       std::vector<SRTrueParticle> prefsi;           ///< Primary daughters prior to FSI.

       float                       xsec_cvwgt = NaN; ///<  Central value weight for cross section model

   };

} // caf

#endif //DUNEANAOBJ_SRTRUEINTERACTION_H
