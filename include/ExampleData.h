#include <TFile.h>
#include <TRandom3.h>
#include <TTree.h>

void createExampleTree(TRandom3* random)
{
	TFile* outputFile = new TFile("exampleData.root", "RECREATE");
	TTree* tree       = new TTree("tree", "tree");

	int numberOfEvents = 1000;
	int eventNumber;
	double trackPositionX;
	double trackPositionY;
	double trackMomentum;
	double particleMass;
	tree->Branch( "eventNumber"   , &eventNumber   , "eventNumber/I"   );
	tree->Branch( "trackPositionX", &trackPositionX, "trackPositionX/D");
	tree->Branch( "trackPositionY", &trackPositionY, "trackPositionY/D");
	tree->Branch( "trackMomentum" , &trackMomentum , "trackMomentum/D" );
	tree->Branch( "particleMass"  , &particleMass , "particleMass/D" );

	for( unsigned int i = 0; i < numberOfEvents; ++i )
	{
		eventNumber = i;
		trackPositionX = random->Gaus( random->Gaus(   0, 0.2),  5 );
		trackPositionY = random->Gaus( random->Gaus(   0, 0.4),  4 );
		trackMomentum  = random->Gaus( 100, 5 );
		particleMass   = 0.13957018;
		tree->Fill();
	}
	tree->Write();
	outputFile->Close();
}
