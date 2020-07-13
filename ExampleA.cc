#include <iostream>
#include <TF1.h>
#include <TTree.h>
#include <TFile.h>
#include <TRandom3.h>

#include "Detector.h"
#include "Track.h"
#include "Hit.h"
#include "ExampleData.h"


int main()
{
	std::cout << "Example A - Hello World " << std::endl;

	TRandom3* random = new TRandom3(42);
	// Create example data
	createExampleTree(random);

	// Read data to generate tracks
	TFile* inputFile = new TFile("exampleData.root", "READ");
	TTree* tree = (TTree*)inputFile->Get("tree");

	// Map to tree
	double trackPositionX;
	double trackPositionY;
	double trackMomentum;
	double particleMass;

	tree->SetBranchAddress( "trackPositionX", &trackPositionX);
	tree->SetBranchAddress( "trackPositionY", &trackPositionY);
	tree->SetBranchAddress( "trackMomentum" , &trackMomentum );
	tree->SetBranchAddress( "particleMass"  , &particleMass  );


	// Detectors
	Detector* detectorA = new Detector("Detector A", 10, 10,   1,   1);
	Detector* detectorB = new Detector("Detector B",  5,  5, 0.1, 0.1);
	detectorA->setRandom(random);
	detectorB->setRandom(random);

	TFile* outFile = new TFile("exampleOutput.root", "RECREATE");
	TTree* outTree = new TTree("outTree", "outTree");
	std::vector<double>* detHitA_X = nullptr;
	std::vector<double>* detHitA_Y = nullptr;
	std::vector<double>* detHitB_X = nullptr;
	std::vector<double>* detHitB_Y = nullptr;
	double detTrackA_X;
	double detTrackA_Y;
	double detTrackB_X;
	double detTrackB_Y;
	outTree->Branch("detHitA_X"  , &detHitA_X  );
	outTree->Branch("detHitA_Y"  , &detHitA_Y  );
	outTree->Branch("detHitB_X"  , &detHitB_X  );
	outTree->Branch("detHitB_Y"  , &detHitB_Y  );
	outTree->Branch("detTrackA_X", &detTrackA_X);
	outTree->Branch("detTrackA_Y", &detTrackA_Y);
	outTree->Branch("detTrackB_X", &detTrackB_X);
	outTree->Branch("detTrackB_Y", &detTrackB_Y);

	// Loop trough tree
	for( int i = 0; i < tree->GetEntries(); ++i )
	{
		tree->GetEntry(i);
		Track* track = new Track();
		track->setPositionX(trackPositionX);
		track->setPositionY(trackPositionY);
		track->setEnergy(particleMass, trackMomentum);
		detectorA->addTrack(track);
		detectorB->addTrack(track);

		std::vector<Hit*> hitsA = detectorA->generateHits(track);
		std::vector<Hit*> hitsB = detectorB->generateHits(track);

		// Store data
		for( const auto &hit : hitsA )
		{
			detHitA_X->push_back(hit->getX());
			detHitA_Y->push_back(hit->getY());
			detTrackA_X = hit->getTrack()->getPosX();
			detTrackA_Y = hit->getTrack()->getPosY();
		}
		for( const auto &hit : hitsB )
		{
			detHitB_X->push_back(hit->getX());
			detHitB_Y->push_back(hit->getY());
			detTrackB_X = hit->getTrack()->getPosX();
			detTrackB_Y = hit->getTrack()->getPosY();
		}
		outTree->Fill();
	}

	outTree->Write();
	outFile->Close();
	return 0;
}

