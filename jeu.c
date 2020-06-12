#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void CorrespondanceInt(int Chiffre){

    switch(Chiffre)
        {
        case 0  : printf("             ");break; //Cas de débuggage

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


int EnchereBot(int *MainCartes, int EnchereHaute, int *PointeurPasse){

    //Calcul des points de Pli
    int i,ValEnchereBot=0;
    for (i=0;i<8;i++){
        if (MainCartes[i]%10>4){
            ValEnchereBot=ValEnchereBot+20;
        }
    }

    //Recherche de Carrés dans la main
    int Carre9=0,Carre10=0,CarreValet=0,CarreDame=0,CarreRoi=0,CarreAs=0;
    for (i=0;i<8;i++){
        if (MainCartes[i]%10==3){
            Carre9++;
            if (Carre9==4){
                ValEnchereBot=ValEnchereBot+150;
            }
        }
        if (MainCartes[i]%10==4){
            Carre10++;
            if (Carre10==4){
                ValEnchereBot=ValEnchereBot+100;
            }
        }
        if (MainCartes[i]%10==5){
            CarreValet++;
            if (CarreValet==4){
                ValEnchereBot=ValEnchereBot+200;
            }
        }
        if (MainCartes[i]%10==6){
            CarreDame++;
            if (CarreDame==4){
                ValEnchereBot=ValEnchereBot+100;
            }
        }
        if (MainCartes[i]%10==7){
            CarreRoi++;
            if (CarreRoi==4){
                ValEnchereBot=ValEnchereBot+100;
            }
        }
        if (MainCartes[i]%10==8){
            CarreAs++;
            if (CarreAs==4){
                ValEnchereBot=ValEnchereBot+100;
            }
        }
    }

    //Recherche de Suites
    int j,k;
    int MainTriee[8],ValSuite=1;

    //On trie d'abord la main pour éviter 8x8x8x8 itérations
    for(i=0;i<8;i++){
        MainTriee[i]=MainCartes[i];
    }

    int temp;
    for(j=1;j<8;j++){
        for(k=0;k<7;k++){
            if(MainTriee[k]>MainTriee[k+1]){
                temp=MainTriee[k];
                MainTriee[k]=MainTriee[k+1];
                MainTriee[k+1]=temp;
            }
        }
    }

    for (i=0;i<7;i++){
        if (MainTriee[i]==MainTriee[i+1]+1){
            ValSuite++;
        }else{
            if (ValSuite==3){
                ValEnchereBot=ValEnchereBot+20;
            }
            if (ValSuite==4){
                ValEnchereBot=ValEnchereBot+50;
            }
            if (ValSuite==5){
                ValEnchereBot=ValEnchereBot+100;
            }
        }
    }

    //Choix Atout de l'enchere
    int AtoutBot,CoeurFort=0,CarreFort=0,TreflFort=0,PiqueFort=0,AvantageSA=0;
    for (i=0;i<8;i++){
        if (MainCartes[i]==15 || MainCartes[i]==13){
            CoeurFort++;
        }
        if (MainCartes[i]==25 || MainCartes[i]==23){
            TreflFort++;
        }
        if (MainCartes[i]==35 || MainCartes[i]==33){
            CarreFort++;
        }
        if (MainCartes[i]==45 || MainCartes[i]==43){
            PiqueFort++;
        }
        if (MainCartes[i]==18 || MainCartes[i]==28 || MainCartes[i]==38 || MainCartes[i]==48 || MainCartes[i]==14 || MainCartes[i]==24 || MainCartes[i]==34 || MainCartes[i]==44){
            AvantageSA++;
        }
    }

    if (CoeurFort+TreflFort+CarreFort+PiqueFort>4){
        AtoutBot=5;
    }
    if (AvantageSA>4){
        AtoutBot=6;
    }
    if (CoeurFort>TreflFort && CoeurFort>CarreFort && CoeurFort>PiqueFort){
        AtoutBot=1;
    }
    if (TreflFort>CoeurFort && TreflFort>CarreFort && TreflFort>PiqueFort){
        AtoutBot=2;
    }
    if (CarreFort>TreflFort && CarreFort>CoeurFort && CarreFort>PiqueFort){
        AtoutBot=3;
    }
    if (PiqueFort>TreflFort && PiqueFort>CarreFort && PiqueFort>CoeurFort){
        AtoutBot=4;
    }

    MainCartes[9]=AtoutBot;

    if (ValEnchereBot>EnchereHaute){
        EnchereHaute=ValEnchereBot;
        printf("Place une enchere a %d points au ",ValEnchereBot);CorrespondanceInt(AtoutBot);
        *PointeurPasse=0;
        return EnchereHaute;

    }else{
        printf("Passe");
        *PointeurPasse+=1;
        return EnchereHaute;
    }
}

int EnchereJoueur(int *MainCartes, int EnchereHaute, int *PointeurPasse){

    int ValEnchereJoueur,AtoutJoueur;
        printf("   Placez votre enchere : ");
        scanf("%d",&ValEnchereJoueur);printf("\n");
        printf("   Aide : 1=Coeur; 2=Trefle; 3=Carreau; 4=Pique; 5=TA; 6=SA \n");
        printf("   Choisissez un atout : ");
        scanf("%d",&AtoutJoueur);
        while (getchar () != '\n');

        while (AtoutJoueur!=6 && AtoutJoueur!=5 && AtoutJoueur!=4 && AtoutJoueur!=3 && AtoutJoueur!=2 && AtoutJoueur!=1){
            printf("    Atout invalide, reessayez : ");
            scanf("%d",&AtoutJoueur);
            while (getchar () != '\n');
        }
        MainCartes[9]=AtoutJoueur;

        if (ValEnchereJoueur>EnchereHaute){
            EnchereHaute=ValEnchereJoueur;
            printf("\n Joueur : Place une enchere a %d points au ",ValEnchereJoueur);CorrespondanceInt(AtoutJoueur);printf("\n");
            *PointeurPasse=0;
            return EnchereHaute;

        }else{
            printf("\n Passe");printf("\n");
            *PointeurPasse+=1;
            return EnchereHaute;
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

int JeuBot(int *MainBot, int Atout, int *CartesJouees){

    int i,j=0;
    int CouleurManche, BestCard=0,WorstCard,CarteHaute;
    int CartesJouables[8];
    int ForceCarteNA[8]={1,2,3,7,4,5,6,8};
    int ForceCarteA[8]={1,2,7,5,8,3,4,6};

    for(i=0;i<4;i++){//On cherche la valeur la plus haute des Cartes jouées
        if(ForceCarteNA[CartesJouees[i]%10]>CarteHaute){
            CarteHaute=ForceCarteNA[CartesJouees[i]%10];
        }
    }

    if(CartesJouees[0]==0){//Si le bot est le premier à jouer, il pose une carte aléatoirement
        srand(time(NULL));
        while(BestCard==0){
            BestCard=rand()%8;
            BestCard=MainBot[BestCard];
        }
    }else{
        CouleurManche=CartesJouees[0]/10;
        for(i=0;i<8;i++){ // On cherche une carte de la couleur jouée dans la main
            if(MainBot[i]/10==CouleurManche){
                 MainBot[i]=CartesJouables[j];
                 j++;
            }
        }
        for(i=0;i<8;i++){
            if(ForceCarteNA[CartesJouables[i]%10]>BestCard && BestCard<CarteHaute){
                BestCard=ForceCarteNA[CartesJouables[i]%10];
            }
        }

        if(CartesJouables[0]==0){ //Si le joueur n'a pas de cartes de la couleur du jeu, on cherche un atout
            for(i=0;i<8;i++){
                if(MainBot[i]/10==Atout){
                     MainBot[i]=CartesJouables[j];
                     j++;
                }
            }
            for(i=0;i<8;i++){
                if(ForceCarteA[CartesJouables[i]%10]>BestCard){
                    BestCard=ForceCarteA[CartesJouables[i]%10];
                }
            }
        }
        if(CartesJouables==0){//Si le joueur n'a ni couleur ni atout, on prend la plus petite carte
            for(i=0;i<8;i++){
                if(ForceCarteNA[CartesJouables[i]%10]<WorstCard){
                    WorstCard=ForceCarteNA[CartesJouables[i]%10];
                }
            return MainBot[WorstCard];
            }
        }
    }
    return MainBot[BestCard];
}

int JeuJoueur(int *MainJoueur, int Atout, int *CartesJouees){

    int i;
    int Card=0;
    int CouleurManche;

    while(Card==0){

        printf("Entrez le numero de la carte que vous voulez jouer : ");

        if(CartesJouees[0]==0){
            scanf("%d",&Card);printf("\n");

            if(MainJoueur[Card]==0){
                 printf("Carte Invalide\n");
                 Card=0;
                 break;
            }

        }else{

            CouleurManche=CartesJouees[0]/10;

            scanf("%d",&Card);printf("\n");

            if(Card/10!=CouleurManche){ //Si la carte n'est pas de la couleur jouée
                for(i=0;i<8;i++){
                    if(MainJoueur[i]/10==CouleurManche){ // Si une carte de la main est de la couleur jouée
                        printf("Vous ne pouvez pas jouer cette carte\n"); // On doit choisir une autre carte
                        Card=0;
                        break;
                    }else{
                        if(MainJoueur[i]/10==Atout && MainJoueur[Card]/10!=Atout){ //Si le joueur possède un atout et que la carte jouée n'est pas un atout
                            printf("Vous ne pouvez pas jouer cette carte\n"); //On doit choisir une autre carte
                            Card=0;
                            break;
                        }
                    }
                }
            }
        }
    }
    return MainJoueur[Card-1]; //On renvoie la carte jouée et validée
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




