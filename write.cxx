#include "TFile.h"
#include "TTree.h"
#include "TRandom.h"
#include "my_class.h"   // your own class derived from TObject


void write() {
    // Initialize your object
    my_class *obj = new my_class();  // pointer to your class

    // Create the output ROOT file
    TFile *outfile = new TFile("tree_file.root", "RECREATE");

    // Create the TTree
    TTree *tree = new TTree("tree", "Example tree with personal objects");

    // Create branch for your object
    tree->Branch("myBranch", &obj);

    // amount of events 
    const Int_t nEvents = 100;

    // Fill the tree with some random data
    for (Int_t i = 0; i < nEvents; i++) {


        Double_t px = gRandom->Gaus(0,.02);
        Double_t py = gRandom->Gaus(0,.02);
        Double_t pz = gRandom->Gaus(0,.02);

        
        obj = new my_class(px, py, pz);  

        // Fill the tree (adds one “row”)
        tree->Fill();

        // Clean up 
        delete obj;
    }

    // Save tree to file
    tree->Write();
    outfile->Close();

    // Delete file pointer
    delete tree;
    delete outfile;
}
