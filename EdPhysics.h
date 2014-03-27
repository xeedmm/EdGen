#ifndef __EdPhysics_h
#define __EdPhysics_h


#include "EdModel.h"
#include "EdOutput.h"
#include <iostream>
#include "TLorentzVector.h"
#include "TF2.h"
#include "TF1.h"
#include "TVector3.h"
#include "TGenPhaseSpace.h"
#include "TDatabasePDG.h"
#include "TParticlePDG.h"
#include "TRandom2.h"



using namespace std;

class EdPhysics: public TGenPhaseSpace{
    public:
	EdPhysics(EdModel *);
	~EdPhysics();

	void MakeEvent(EdOutput * , EdModel *);

    private:

	int n_part;
	int nvertex; // total number of vertexes
	int npvert[10]; // total number of particle at one vertex
	int overt[10];  // particle at origin of one vertex (need to be already existing)
	int    v_type[10]; // vertex type (1= ratio  of probability , 2= cross section
	double v_ratio[10]; // ration to be applied to vertex
	TDatabasePDG *pdg;
	TParticlePDG *part_pdg[MAX_PART];
	double theta[MAX_PART];
	double phi[MAX_PART];
	double Ef[MAX_PART];
	double pf[MAX_PART];
	double px[MAX_PART];
	double py[MAX_PART];
	double pz[MAX_PART];
	double x;
	double W;
	double y;
	double Q2;
	double nu;
	double weight[MAX_PART];

	int particle_id[MAX_PART];
	int charge[MAX_PART];
	int Z_ion;
	int N_ion;
	double vx[MAX_PART];
	double vy[MAX_PART];
	double vz[MAX_PART];
	
	int towrite[MAX_PART];
	double masses[10][10];
	TRandom2 *fRandom;
	TLorentzVector Wtg;
	TLorentzVector beam;
	TLorentzVector target;

	TVector3 Decay_vertex(TLorentzVector *Vp_4, int i, TVector3 vert);
	double GetBeamProfile( double sigma = 1.);

	 
};
#endif//__EdPhysics_h
