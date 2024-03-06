void cal_pi() {
    TCanvas *c1 = new TCanvas();

    c1->Divide(3, 2);
    int NofExp = 1000;
    TH1F *hist[6];
    //int bins[6]={10, 32, 50, 316, 1000, 3162};
    int bins = 32;
    double P[6] = {100, 1000, 10000, 100000, 1000000, 10000000};
    //double x[2]={100, 1000};
    double sigma[6];

    TRandom2 *rand = new TRandom2(0);
    TF1 *fit1 = new TF1("fit1", "gaus", 2.4, 3.7);
    TF1 *fit2 = new TF1("fit2", "gaus", 2.4, 3.7);
    TF1 *fit3 = new TF1("fit3", "gaus", 2.4, 3.7);
    TF1 *fit4 = new TF1("fit4", "gaus", 2.4, 3.7);
    TF1 *fit5 = new TF1("fit5", "gaus", 2.4, 3.7);
    TF1 *fit6 = new TF1("fit6", "gaus", 2.4, 3.7);



    hist[0] = new TH1F("hist1", "Histogram; #pi; Entries", bins,
                       2.4, 3.7);
    for (int j = 0; j < NofExp; j++) {
        int n = 0;
        for (int k = 0; k < P[0]; k++) {
            double x = rand->Rndm() * 2 - 1;
            double y = rand->Rndm() * 2 - 1;
            if ((x * x + y * y) < 1)
                n = n + 1;
        }
        double pi = 4.0 * n / P[0];
        hist[0]->Fill(pi);
        n = 0;
    }
    c1->cd(1);
    hist[0]->Draw();
    hist[0]->Fit("fit1");
    sigma[0]=fit1->GetParameter(2);
   /* for (int i = 0; i < 1; i++) {
        int n = 0;
        hist[i] = new TH1F(Form("hist%d", i + 1), "Histogram; #pi; Entries", bins[1],
                           2.9, 3.4);
        for (int j = 0; j < NofExp; j++) {
            for (int k = 0; k < P[i]; k++) {
                double x = rand->Rndm() * 2 - 1;
                double y = rand->Rndm() * 2 - 1;
                if ((x * x + y * y) < 1)
                    n = n + 1;
            }
            double pi = 4.0 * n / P[i];
            hist[i]->Fill(pi);
            n = 0;
        }
        c1->cd(i + 1);
        hist[i]->Draw();
    }*/


//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

    hist[1] = new TH1F("hist2", "Histogram; #pi; Entries", bins,
                       2.9, 3.35);
    for (int j = 0; j < NofExp; j++) {
        int n = 0;
        for (int k = 0; k < P[1]; k++) {
            double x = rand->Rndm() * 2 - 1;
            double y = rand->Rndm() * 2 - 1;
            if ((x * x + y * y) < 1)
                n = n + 1;
        }
        double pi = 4.0 * n / P[1];
        hist[1]->Fill(pi);
        n = 0;
    }
    c1->cd(2);
    hist[1]->Draw();
    hist[1]->Fit("fit2");
    sigma[1]=fit2->GetParameter(2);
//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

    hist[2] = new TH1F("hist3", "Histogram; #pi; Entries", bins,
                       3.08, 3.21);
    for (int j = 0; j < NofExp; j++) {
        int n = 0;
        for (int k = 0; k < P[2]; k++) {
            double x = rand->Rndm() * 2 - 1;
            double y = rand->Rndm() * 2 - 1;
            if ((x * x + y * y) < 1)
                n = n + 1;
        }
        double pi = 4.0 * n / P[2];
        hist[2]->Fill(pi);
        n = 0;
    }
    c1->cd(3);
    hist[2]->Draw();
    hist[2]->Fit("fit3");
    sigma[2]=fit3->GetParameter(2);
//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

    hist[3] = new TH1F("hist4", "Histogram; #pi; Entries", bins,
                       3.12, 3.165);
    for (int j = 0; j < NofExp; j++) {
        int n = 0;
        for (int k = 0; k < P[3]; k++) {
            double x = rand->Rndm() * 2 - 1;
            double y = rand->Rndm() * 2 - 1;
            if ((x * x + y * y) < 1)
                n = n + 1;
        }
        double pi = 4.0 * n / P[3];
        hist[3]->Fill(pi);
        n = 0;
    }
    c1->cd(4);
    hist[3]->Draw();
    hist[3]->Fit("fit4");
    sigma[3]=fit4->GetParameter(2);
//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

    hist[4] = new TH1F("hist5", "Histogram; #pi; Entries", bins,
                       3.134, 3.148);
    for (int j = 0; j < NofExp; j++) {
        int n = 0;
        for (int k = 0; k < P[4]; k++) {
            double x = rand->Rndm() * 2 - 1;
            double y = rand->Rndm() * 2 - 1;
            if ((x * x + y * y) < 1)
                n = n + 1;
        }
        double pi = 4.0 * n / P[4];
        hist[4]->Fill(pi);
        n = 0;
    }
    c1->cd(5);
    hist[4]->Draw();
    hist[4]->Fit("fit5");
    sigma[4]=fit5->GetParameter(2);


//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

    hist[5] = new TH1F("hist6", "Histogram; #pi; Entries", bins,
                       3.1395, 3.1435);
    for (int j = 0; j < NofExp; j++) {
        int n = 0;
        for (int k = 0; k < P[5]; k++) {
            double x = rand->Rndm() * 2 - 1;
            double y = rand->Rndm() * 2 - 1;
            if ((x * x + y * y) < 1)
                n = n + 1;
        }
        double pi = 4.0 * n / P[5];
        hist[5]->Fill(pi);
        n = 0;
    }
    c1->cd(6);
    hist[5]->Draw();
    hist[5]->Fit("fit6");
    sigma[5]=fit6->GetParameter(2);

    TGraph *gr = new TGraph(6,P,sigma);
    TCanvas *c2 = new TCanvas();
    c2->SetLogx(1);
    gr->GetXaxis()->SetTitle("N");
    gr->GetYaxis()->SetTitle("precision");
    gr->SetMarkerStyle(20);
    gr->SetMarkerSize(1.2);
    gr->Draw("AP");

}
