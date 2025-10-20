#include "TFile.h"
#include "TTree.h"
#include "TH2D.h"
#include "TCanvas.h"
#include "my_class.h"
#include <iostream>


void read() {

    my_class* obj =  new my_class();

    TFile* f = new TFile("tree_file.root","READ");
    TTree* tree = (TTree*)f->Get("tree");
    
    tree->SetBranchAddress("myBranch", &obj);

 
    TH2D* histogram_1 = new TH2D("histogram_1","p_{x} vs p_{y};p_{x};p_{y}",100,-0.1,0.1,100,-0.1,0.1);

    Long64_t n = tree->GetEntries();
    for (Long64_t i = 0; i < n; ++i) {
        tree->GetEntry(i);
        histogram_1->Fill(obj->getPx(), obj->getPy());
    }

    TCanvas* c1 = new TCanvas("c1","px vs py",800,600);
    histogram_1->Draw("COLZ");

    TCanvas* c2 = new TCanvas("c2","px*py vs pz ",800,600);
    tree->Draw("myBranch.pz:(myBranch.px*myBranch.py)", "", "COLZ"); 

    c1 -> Update();
    c2 -> Update();
}