////////////////////////////////////////////////////////////////////////
// \file    StandardRecord.h
// \brief   The StandardRecord is the primary top-level object in the 
//          Common Analysis File trees.   
// \version $Id: StandardRecord.h,v 1.7 2012-12-06 20:18:33 rocco Exp $
// \author  $Author: rocco $
// \date    $Date: 2012-12-06 20:18:33 $
////////////////////////////////////////////////////////////////////////
#ifndef DUNEANAOBJ_STANDARDRECORD_H
#define DUNEANAOBJ_STANDARDRECORD_H

#include <vector>

#include "duneanaobj/StandardRecord/SRNDLAr.h"
#include "duneanaobj/StandardRecord/SRTMS.h"
#include "duneanaobj/StandardRecord/SRVector3D.h"

/// Common Analysis Files
namespace caf
{
  
  /// \brief   The StandardRecord is the primary top-level object in the 
  ///          Common Analysis File trees.   
  
  class StandardRecord  
  {
    
  public:
    StandardRecord();
    ~StandardRecord();

    // Metadata
    int meta_run;
    int meta_subrun;
    double pot;

    // Reco info
    float eRec_FromDep; // Unified parameterized reco that can be used at near and far. Should only be used for missing proton energy fake data studies that cannot use the CVN FD Reco
    float Ev_reco; // for ND?
    float Ev_reco_nue;
    float Ev_reco_numu;
    float mvaresult;
    float mvanue;
    float mvanumu;
    float cvnnue;
    float cvnnumu;
    float cvnnutau;
    float cvnnc;
    int reco_q;
    float Elep_reco;
    float theta_reco;
    int reco_lepton_pdg;

    float RecoLepEnNue;
    float RecoHadEnNue;
    float RecoLepEnNumu;
    float RecoHadEnNumu;

    double pileup_energy;

    SRNDLAr  ndlar;
    SRTMS  ndtms;

    std::vector<caf::SRNDTrackMatch> ndtrkmatches;

    // gas TPC info
    int nFSP;
    std::vector<int> pdg;
    std::vector<float> ptrue;
    std::vector<float> trkLen;
    std::vector<float> trkLenPerp;
    std::vector<float> partEvReco;
    int gastpc_pi_pl_mult;
    int gastpc_pi_min_mult;

    int RecoMethodNue;  // 1 = longest reco track + hadronic, 2 = reco shower with highest charge + hadronic, 3 = all hit charges, -1 = not set
    int RecoMethodNumu; // 1 = longest reco track + hadronic, 2 = reco shower with highest charge + hadronic, 3 = all hit charges, -1 = not set
    int TrackMomMethodNumu;

    // ND pseudo-reconstruction flags
    int reco_numu;
    int reco_nue;
    int reco_nc;

    // CW: added for the ND cuts Chris (M) wants
    // ND containment flags
    int muon_contained;
    int muon_tracker;
    int muon_ecal;
    int muon_exit;
    float Ehad_veto;

    // To prevent errors when compiling DUNENDSysts
    float nue_pid;
    float numu_pid;

    // Containment flag
    int LongestTrackContNumu;

    // Truth info
    float Ev;
    float Elep;
    //  float enu_truth; // so what's this one?
    int isCC;
    //    int ccnc;
    //    int cc;
    //    int beamPdg;
    //    int neu;
    int nuPDG;
    int nuPDGunosc;
    int LepPDG;

    // This mode depends on whether the file is ND/FD
    // See converter in SpectrumLoader.cxx that fills GENIE_ScatteringMode
    int mode;

    /// Modes list:
    /// * QE: 1
    /// * Single Kaon: 2
    /// * DIS: 3
    /// * RES: 4
    /// * COH: 5
    /// * Diffractive: 6
    /// * Nu-e El: 7
    /// * IMD: 8
    /// * AMnuGamma: 9
    /// * MEC: 10
    /// * COHEl: 11
    /// * IBD: 12
    /// * GlashowRES: 13
    /// * IMDAnnihalation: 14
    int GENIE_ScatteringMode;
    int nP;
    int nN;
    int nipi0;
    int nipip;
    int nipim;
    int niem;

    int nikp;
    int nikm;
    int nik0;
    int niother; // charm mesons, strange and charm baryons, antibaryons, etc.
    int nNucleus;
    int nUNKNOWN;

    float Q2;
    float W;
    float Y;
    float X;

    float vtx_x;
    float vtx_y;
    float vtx_z;

    // Near detector offset in m
    float det_x;

    // True energy of particles by species
    float eP;
    float eN;
    float ePip;
    float ePim;
    float ePi0;
    float eOther;

    // Reconstructed energy of particles by species
    float eRecoP;
    float eRecoN;
    float eRecoPip;
    float eRecoPim;
    float eRecoPi0;
    float eRecoOther;

    //At FD
    float eDepP;
    float eDepN;
    float eDepPip;
    float eDepPim;
    float eDepPi0;
    float eDepOther;

    float NuMomX;
    float NuMomY;
    float NuMomZ;
    float LepMomX;
    float LepMomY;
    float LepMomZ;
    float LepE;
    float LepNuAngle;

    SRVector3D LepEndpoint;

    // config
    int run, subrun, event;
    int isFD;
    int isFHC;

    // CVN outputs
    float CVNResultIsAntineutrino;
    float CVNResultNue, CVNResultNumu, CVNResultNutau, CVNResultNC; // flavour
    float CVNResult0Protons, CVNResult1Protons, CVNResult2Protons, CVNResultNProtons; // #protons
    float CVNResult0Pions, CVNResult1Pions, CVNResult2Pions, CVNResultNPions; // #pions
    float CVNResult0Pizeros, CVNResult1Pizeros, CVNResult2Pizeros, CVNResultNPizeros; // #pizeros
    float CVNResult0Neutrons, CVNResult1Neutrons, CVNResult2Neutrons, CVNResultNNeutrons; // #neutrons

    float RegCNNNueE;

    // sigmas
    float sigma_Ev_reco;
    float sigma_Elep_reco;
    float sigma_numu_pid;
    float sigma_nue_pid;

    int nwgt_CrazyFlux;
    std::vector<float> wgt_CrazyFlux;

    // First index is systematic ID
    std::vector<std::vector<float>> xsSyst_wgt;

    float total_xsSyst_cv_wgt;
    std::vector<float> cvwgt;
  };
  
} // end namespace

#endif // DUNEANAOBJ_STANDARDRECORD_H
//////////////////////////////////////////////////////////////////////////////
