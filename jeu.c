#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void CorrespondanceInt(int Chiffre){


    switch(Chiffre)
        {
        case 0  : printf("             ");break;

        // 1-6 Int Atouts
        case 1  : printf("Coeur");        break;
        case 2  : printf("Trefle");       break;
        case 3  : printf("Carreau");      break;
        case 4  : printf("Pique");        break;
        case 5  : printf("Tout Atout");   break;
        case 6  : printf("Sans Atout");   break;
        case 9  : printf("...");          break;

        // 11-48 Int Cartes
        case 11 : printf("| 7  de Coe |");break;
        case 12 : printf("| 8  de Coe |");break;
        case 13 : printf("| 9  de Coe |");break;
        case 14 : printf("| 10 de Coe |");break;
        case 15 : printf("| V  de Coe |");break;
        case 16 : printf("| D  de Coe |");break;
        case 17 : printf("| R  de Coe |");break;
        case 18 : printf("| As de Coe |");break;

        case 21 : printf("| 7  de Tre |");break;
        case 22 : printf("| 8  de Tre |");break;
        case 23 : printf("| 9  de Tre |");break;
        case 24 : printf("| 10 de Tre |");break;
        case 25 : printf("| V  de Tre |");break;
        case 26 : printf("| D  de Tre |");break;
        case 27 : printf("| R  de Tre |");break;
        case 28 : printf("| As de Tre |");break;

        case 31 : printf("| 7  de Car |");break;
        case 32 : printf("| 8  de Car |");break;
        case 33 : printf("| 9  de Car |");break;
        case 34 : printf("| 10 de Car |");break;
        case 35 : printf("| V  de Car |");break;
        case 36 : printf("| D  de Car |");break;
        case 37 : printf("| R  de Car |");break;
        case 38 : printf("| As de Car |");break;

        case 41 : printf("| 7  de Piq |");break;
        case 42 : printf("| 8  de Piq |");break;
        case 43 : printf("| 9  de Piq |");break;
        case 44 : printf("| 10 de Piq |");break;
        case 45 : printf("| V  de Piq |");break;
        case 46 : printf("| D  de Piq |");break;
        case 47 : printf("| R  de Piq |");break;
        case 48 : printf("| As de Piq |");break;

        //Int Phases de Jeu
        case 60 : printf("Encheres");     break;
        case 61 : printf("Tour 1/8");     break;
        case 62 : printf("Tour 2/8");     break;
        case 63 : printf("Tour 3/8");     break;
        case 64 : printf("Tour 4/8");     break;
        case 65 : printf("Tour 5/8");     break;
        case 66 : printf("Tour 6/8");     break;
        case 67 : printf("Tour 7/8");     break;
        case 68 : printf("Tour 8/8");     break;

        //Int ID Joueurs
        case 71 : printf("Joueur");       break;
        case 72 : printf("Ouest");        break;
        case 73 : printf("Nord");         break;
        case 74 : printf("Est");          break;
        }
}

void Distribution(int *PaquetDeCartes, int *MainJoueur, int *MainOuest, int *MainEst, int *MainNord) {

    int OrdreDistribution[3]={3,2,3};

    /* Distribution des Cartes en 3-2-3 */
    int j,k,Compteur=0,CompteurJ=0,CompteurO=0,CompteurN=0,CompteurE=0;

    for(j=0;j<3;j++){

        /* Distribution Joueur */
        for(k=0;k<OrdreDistribution[j];k++){
            MainJoueur[CompteurJ+k]=PaquetDeCartes[Compteur+k];
        }
        CompteurJ=CompteurJ+OrdreDistribution[j];
        Compteur=Compteur+OrdreDistribution[j];

        /* Distribution Adversaires */
        for(k=0;k<OrdreDistribution[j];k++){
            MainOuest[CompteurO+k]=PaquetDeCartes[Compteur+k];
        }
        CompteurO=CompteurO+OrdreDistribution[j];
        Compteur=Compteur+OrdreDistribution[j];

        for(k=0;k<OrdreDistribution[j];k++){
            MainNord[CompteurN+k]=PaquetDeCartes[Compteur+k];
        }
        CompteurN=CompteurN+OrdreDistribution[j];
        Compteur=Compteur+OrdreDistribution[j];

        for(k=0;k<OrdreDistribution[j];k++){
            MainEst[CompteurE+k]=PaquetDeCartes[Compteur+k];
        }
        CompteurE=CompteurE+OrdreDistribution[j];
        Compteur=Compteur+OrdreDistribution[j];

    }

}

void MelangeCartes(int *PaquetDeCartes){

    int i,AleaSourc,AleaDesti,Tampon;

    srand(time(NULL));
    for(i=0; i<100; i++){
        AleaSourc=rand()%31;
        AleaDesti=rand()%31;
        Tampon=PaquetDeCartes[AleaSourc];
        PaquetDeCartes[AleaSourc]=PaquetDeCartes[AleaDesti];
        PaquetDeCartes[AleaDesti]=Tampon;
    }
}

int ComptagePoints(int *Recup, int Atout){
    int i,Score=0;


    for(i=0;i<32;i++){

        if(Recup[i]==11||Recup[i]==12||Recup[i]==21||Recup[i]==22||Recup[i]==31||Recup[i]==32||Recup[i]==41||Recup[i]==42||Recup[i]==0){
            Score+=0;
        }
        if(Recup[i]==26 || Recup[i]==36 || Recup[i]==46 || Recup[i]==16){
            Score+=3;
        }
        if(Recup[i]==17 || Recup[i]==27 || Recup[i]==37 || Recup[i]==47){
            Score+=4;
        }
        if(Recup[i]==18 || Recup[i]==28 || Recup[i]==38 || Recup[i]==48){
            Score+=11;
        }
        if(Recup[i]==15 || Recup[i]==25 || Recup[i]==35 || Recup[i]==45){
            Score+=10;
        }

        switch(Atout)
            {
                case 1 :
                    //Atout Coeur
                        if(Recup[i]==24 || Recup[i]==34 || Recup[i]==44){
                            Score+=0;
                        }
                        if(Recup[i]==14){
                            Score+=14;
                        }
                        if(Recup[i]==26 || Recup[i]==36 || Recup[i]==46){
                            Score+=2;
                        }
                        if(Recup[i]==16){
                            Score+=20;
                        }
                case 2 :
                    //Atout Trefle
                        if(Recup[i]==14 || Recup[i]==34 || Recup[i]==44){
                            Score+=0;
                        }
                        if(Recup[i]==24){
                            Score+=14;
                        }
                        if(Recup[i]==16 || Recup[i]==36 || Recup[i]==46){
                            Score+=2;
                        }
                        if(Recup[i]==26){
                            Score+=20;
                        }
                case 3 :
                    //Atout Carreau
                        if(Recup[i]==24 || Recup[i]==14 || Recup[i]==44){
                            Score+=0;
                        }
                        if(Recup[i]==34){
                            Score+=14;
                        }
                        if(Recup[i]==26 || Recup[i]==16 || Recup[i]==46){
                            Score+=2;
                        }
                        if(Recup[i]==36){
                            Score+=20;
                        }
                case 4 :
                    //Atout Pique
                        if(Recup[i]==24 || Recup[i]==34 || Recup[i]==14){
                            Score+=0;
                        }
                        if(Recup[i]==44){
                            Score+=14;
                        }
                        if(Recup[i]==26 || Recup[i]==36 || Recup[i]==16){
                            Score+=2;
                        }
                        if(Recup[i]==46){
                            Score+=20;
                        }
            }
        }
    return Score;
}

int GagnantPli(int *Carte, int Atout){
    int i,j;
    int NbAtout,BestCard;
    int ForceCarteNA[8]={1,2,3,7,4,5,6,8};
    int ForceCarteA[8]={1,2,7,5,8,3,4,6};
    int Proprio;

    for (i=0;i<4;i++){
        if(Carte[i]/10==Atout){
            NbAtout+=1;
        }
    }
    if(NbAtout>=2){
        int *trumpCard = malloc(sizeof(int)*NbAtout);
        for (i = 0; i < 4; i++){
            if (Carte[i]/10==Atout){
                trumpCard[j] = Carte[i];
                j++;
            }
        }
        for (i = 0; i < NbAtout; i++){
            if (ForceCarteA[trumpCard[i]%10]>BestCard){
                BestCard = ForceCarteA[trumpCard[i]%10];
            }
        }
        free(trumpCard);
        for (i = 0; i < 4; i++){
            if (Carte[i] == BestCard){
                return i+70;
            }
        }
        return -1;

    }else if(NbAtout==1){
        for (i=0;i<4;i++){
            if(Carte[i]/10==Atout){
                return i+70;
            }
        }

    }else{
        for(i=0;i<4;i++){
            if(ForceCarteNA[Carte[i]%10]>BestCard){
                Proprio=i+70;
                BestCard=ForceCarteNA[Carte[i]%10];
            }
        }
    }
    return Proprio;
}

int MancheGagneePar(int VainqueurManche, int Compteur, int *Pli, int *RecupJoueur, int *RecupOuest, int *RecupEst, int *RecupNord){

    int i;

    if(VainqueurManche==71){
        printf("Vous remporter le pli !");
        for(i=0;i<4;i++){
            RecupJoueur[Compteur]=Pli[i];
            Compteur++;
        }
    }
    if(VainqueurManche==72){
        printf("Ouest remporte le pli !");
        for(i=0;i<4;i++){
            RecupOuest[Compteur]=Pli[i];
            Compteur++;
        }
    }
    if(VainqueurManche==73){
        printf("Nord remporte le pli !");
        for(i=0;i<4;i++){
            RecupNord[Compteur]=Pli[i];
            Compteur++;
        }
    }
    if(VainqueurManche==74){
        printf("Est remporte le pli !");
        for(i=0;i<4;i++){
            RecupEst[Compteur]=Pli[i];
            Compteur++;
        }
    }
    return Compteur;
}

void EnteteJeu(int CouleurAtout, int PhaseDeJeu) {
    printf("________________________________________________________________________________\n\n");
    /* Section Informations Partie */
    printf(" Phase de jeu :  ");CorrespondanceInt(PhaseDeJeu);printf("\n");
    printf(" Atout        :  ");CorrespondanceInt(CouleurAtout);printf("\n\n\n");

}

void AffichageCartes(int *MainJoueur){
    int i;
    for (i=0;i<8;i++){
        printf(" %d. ",i+1);
        CorrespondanceInt(MainJoueur[i]);
        printf("   ");
    }
    printf("\n\n");
}


