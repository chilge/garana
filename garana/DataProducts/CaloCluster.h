/*
 * CaloCluster.h
 *
 *  Created on: Feb 23, 2021
 *      Author: chilgenb
 */

#ifndef GARANA_CALOCLUSTER_H_
#define GARANA_CALOCLUSTER_H_

#include <TLorentzVector.h>
#include <TVector3.h>
#include <TROOT.h>

#include <vector>
#include <climits>

namespace garana {

  class CaloCluster : public TObject {

    public: 

	  CaloCluster();
	  CaloCluster(TLorentzVector& pos, float energy, float energyErr, float timeDiff,
			      float* shape, float theta, float phi, std::vector<TVector3>& eigenVecs );

	  TLorentzVector*        Position();
	  float                  Energy();
	  float                  EnergyError();
	  float                  TimeDifference();
	  float*                 Shape();
	  float                  Theta();
	  float                  Phi();
	  std::vector<TVector3>* EigenVecs();

    private:

	  TLorentzVector fPosition; ///< 4-position of the cluster [cm,ns]
      float fEnergy;            ///< energy of the ECal cluster [GeV]
      float fEnergyError;       ///< uncertainty of the cluster energy [GeV]
      float fTimeDiffFirstLast; ///< time difference between the first and last layer of the cluster [ns]
      float fShape[6];          ///< cluster shape parameters (Ellipsoid r1, r2, r3, vol, width)
      float fTheta;             ///< intrasic direction of the cluster theta
      float fPhi;               ///< intrasic direction of the cluster phi
      std::vector<TVector3> fEigenVecs; ///< Eigenvectors of the cluster in ascending order (principal axis with smallest inertial mass) normalised to 1

    ClassDef(CaloCluster,2)

  }; //class
}//namespace

#endif /* GARANA_CALOCLUSTER_H_ */