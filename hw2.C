
void hw2()
{
    double m_pi0=0.135; //GeV
    //TH2D *hist = new TH2D("hist", "Histogram", 100, 0, 10, );
    TH2D *hist = new TH2D("hist", "Histogram", 100, 0, 10, 100, 0, 1);
    TH1D *hist2 = new TH1D("hist2", "Histogram", 100, 0, 1);
    TGraph *graph1 = new TGraph();
    TCanvas *c1 = new TCanvas();
    TRandom3 *rand = new TRandom3();
    for(int i=0;i<1000000;i++) {
        double Pt_of_Pi0 = rand->Rndm() * 10;//GeV
        double eta_of_Pi0 = rand->Rndm() * 2 - 1;//pseudorapidity
        double phi = rand->Rndm() * 2 * TMath::Pi();
        double Px = Pt_of_Pi0 * TMath::Cos(phi);
        double Py = Pt_of_Pi0 * TMath::Sin(phi);
        double Pz = Pt_of_Pi0 * TMath::SinH(eta_of_Pi0);
        double E = sqrt(Px * Px + Py * Py + Pz * Pz + m_pi0 * m_pi0);
        //cout<<Px/E<<" "<<Py/E<<" "<<Pz/E<<endl;
        TLorentzVector *v_Pi0 = new TLorentzVector(Px, Py, Pz, E);
        TVector3 b = v_Pi0->BoostVector();
        //cout<<b.Px()<<" "<<b.Py()<<" "<<b.Pz()<<endl;
        //double E_pi;
        //Now generate photon;
        //Now generate Pt of photon
        //double Pt_of_Photon1 = rand->Rndm() * m_pi0 / 2;
        //double Pt_of_Photon1 = 0;
        //double eta_of_Photon1 = asinh(sqrt(pow(m_pi0 / 2.0 / Pt_of_Photon1, 2) - 1));
        //cout<<eta_of_Photon1<<endl;
        /*TLorentzVector *pi0 = new TLorentzVector(0, 0,
                                                 0, m_pi0);*/
        double Theta = TMath::ACos(rand->Rndm()*2-1);
        double phi_of_Photon1 = rand->Rndm() * 2.0 * TMath::Pi();
        double Px_of_Photon1 = m_pi0/2.0 * TMath::Sin(Theta) * TMath::Cos(phi_of_Photon1);
        double Py_of_Photon1 = m_pi0/2.0 * TMath::Sin(Theta) * TMath::Sin(phi_of_Photon1);
        double Pz_of_Photon1 = m_pi0/2.0 * TMath::Cos(Theta);
        double s = Py_of_Photon1;
        TLorentzVector *v_Photon1 = new TLorentzVector(Px_of_Photon1, Py_of_Photon1,
                                                       Pz_of_Photon1, m_pi0 / 2.0);
        TLorentzVector *v_Photon2 = new TLorentzVector(-v_Photon1->Px(), -v_Photon1->Py(),
                                                       -v_Photon1->Pz(), m_pi0 / 2.0);
        /*cout<<v_Photon1->Px()<<" "<<v_Photon1->Py()<<" "<<v_Photon1->Pz()<<endl;
        cout<<v_Photon2->Px()<<" "<<v_Photon2->Py()<<" "<<v_Photon2->Pz()<<endl;*/

       /*TLorentzVector v_Photon1(Px_of_Photon1, Py_of_Photon1,
                                 Pz_of_Photon1, m_pi0 / 2);
        TLorentzVector v_*/
        //boost it to lab frame
        v_Photon1->Boost(b);
        v_Photon2->Boost(b);
        //hist->Fill(Pt_of_Pi0, TMath::Abs(v_Photon1->E()-v_Photon2->E())/(v_Photon1->E()+v_Photon2->E()));
        //pi0->Boost(b);
        //double x = v_Photon1->E();
       /* if ((Pt_of_Pi0>0)&&(Pt_of_Pi0<2))
        {*/
       if(s>0) {
           if ((Pt_of_Pi0 > 6) && (Pt_of_Pi0 < 6.3)) {
               hist2->Fill(TMath::Abs(v_Photon1->E() - v_Photon2->E()) / (v_Photon1->E() + v_Photon2->E()));
           }
       }
            //}
        //cout<<Px<<" "<<Py<<" "<<Pz<<" "<<E<<endl;

        //cout<<pi0->Px()<<pi0->Py()<<pi0->Pz()<<pi0->E()<<endl;

        //graph->SetPoint(graph1->getN())
    }
    hist2->Draw();


} 