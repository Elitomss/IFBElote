#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "jeu.h"


void EnteteJeu(int CouleurAtout, int PhaseDeJeu) {
    printf("________________________________________________________________________________\n\n");
    /* Section Informations Partie */
    printf(" Phase de jeu :  ");CorrespondanceInt(PhaseDeJeu);printf("\n");
    printf(" Atout        :  ");CorrespondanceInt(CouleurAtout);printf("\n\n\n");

}

void AffichageCartes(int MainJoueur[8]){
    int i;
    for (i=0;i<8;i++){
        printf(" %d. ",i+1);
        CorrespondanceInt(MainJoueur[i]);
        printf("   ");
    }
    printf("\n\n");
}

int main()
{
    //On imprime le super-méga-jolix titre du jeu
    printf("            ______   ______   __   _    _   ______   _    _   ______\n");
    printf("           |  ____| |  __  | |  | | \\  | | |  ____| | |  | | |  ____|\n");
    printf("           | |      | |  | | |  | |  \\ | | | |      | |  | | | |\n");
    printf("           | |      | |  | | |  | |   \\| | | |      | |__| | | |___\n");
    printf("           | |      | |  | | |  | | |\\   | | |      |  __  | |  ___|\n");
    printf("           | |____  | |__| | |  | | | \\  | | |____  | |  | | | |____\n");
    printf("           |______| |______| |__| |_|  \\_| |______| |_|  |_| |______|\n\n");

    char NomJoueur[14]; //Le prénom français le plus long est de 13 lettres (hors composés)
    printf("Entrez votre prenom : ");
    scanf("%s",NomJoueur);
    printf("\n");

    int Reponse;
    printf(" Bonjour ");printf("%s",NomJoueur);printf(" bienvenue dans le jeu de la Coinche !\n");
    printf(" Vous etes ici dans le menu principal du jeu.\n\n");
    printf(" Vous pouvez jouer(1), voir les scores(2) ou quitter(3)\n\n");
    printf(" Que voulez-vous faire : ");
    scanf("%d",&Reponse);

    if (Reponse==3){
        exit(0);
    }else{
        int PaquetDeCartes[32]= {11,12,13,14,15,16,17,18,21,22,23,24,25,26,27,28,31,32,33,34,35,36,37,38,41,42,43,44,45,46,47,48};
        int MainJoueur[9],MainOuest[9],MainEst[9],MainNord[9];
        int PointeurPasse=0;

        //Initialisation du JEU

        int CouleurAtout=9, PhaseDeJeu=60, i;
       // int MultiplicateurScore;
        for (i=0;i<8;i++){
            MainJoueur[i]=0;
            MainOuest[i]=0;
            MainEst[i]=0;
            MainNord[i]=0;
        }

        //Debut

        do{

            MelangeCartes(PaquetDeCartes);
            Distribution(PaquetDeCartes, MainJoueur, MainOuest, MainEst, MainNord);

            EnteteJeu(CouleurAtout,PhaseDeJeu);
            printf("Voici vos cartes : \n");
            AffichageCartes(MainJoueur);

            int EnchereMaitre, ActionJoueur,Compara,VainqueurEnchere[2];

            //Encheres
            int PremierPassage=0;
            while(PointeurPasse<3){

                if (PointeurPasse<3){
                    if(PremierPassage==0){
                        PremierPassage+=1;
                        printf("\n Vous :\n");
                        EnchereMaitre=EnchereJoueur(MainJoueur,EnchereMaitre,&PointeurPasse);printf("\n");
                        if (EnchereMaitre>Compara){
                                Compara=EnchereMaitre;
                                VainqueurEnchere[0]=71;
                                VainqueurEnchere[1]=MainJoueur[9];
                        }
                    }else{
                        printf("\n Jouer(1) ou Passer(2) ou Coincher(3) ? => ");
                        scanf("%d",&ActionJoueur);printf("\n");
                        if (ActionJoueur==1){
                            printf("Vous :\n");
                            EnchereMaitre=EnchereJoueur(MainJoueur,EnchereMaitre,&PointeurPasse);printf("\n");
                            if (EnchereMaitre>Compara){
                                Compara=EnchereMaitre;
                                VainqueurEnchere[0]=71;
                                VainqueurEnchere[1]=MainJoueur[9];
                            }
                        }if(ActionJoueur==3){
                            printf(" Joueur : COINCHE! Le score est multiplie par 2!\n");
                            //MultiplicateurScore=2;
                        }else{
                            printf(" Joueur : Passe");printf("\n");
                            PointeurPasse+=1;
                        }
                    }
                }
                Compara=EnchereMaitre;


                if (PointeurPasse<3){
                    printf("\n Ouest  : ");
                    EnchereMaitre=EnchereBot(MainOuest,EnchereMaitre,&PointeurPasse);printf("\n");
                    if (EnchereMaitre>Compara){
                        Compara=EnchereMaitre;
                        VainqueurEnchere[0]=72;
                        VainqueurEnchere[1]=MainOuest[9];
                    }
                }else{break;}
                if (PointeurPasse<3){
                    printf("\n Nord   : ");
                    EnchereMaitre=EnchereBot(MainNord,EnchereMaitre,&PointeurPasse);printf("\n");
                    if (EnchereMaitre>Compara){
                        Compara=EnchereMaitre;
                        VainqueurEnchere[0]=73;
                        VainqueurEnchere[1]=MainNord[9];
                    }
                }else{break;}
                if (PointeurPasse<3){
                    printf("\n Est    : ");
                    EnchereMaitre=EnchereBot(MainEst,EnchereMaitre,&PointeurPasse);printf("\n");
                    if (EnchereMaitre>Compara){
                        Compara=EnchereMaitre;
                        VainqueurEnchere[0]=74;
                        VainqueurEnchere[1]=MainEst[9];
                    }
                }else{break;}
            }

            printf(" \n                          // FIN DES ENCHERES // ");
            printf("\n                     Le vainqueur de l'enchere est ");CorrespondanceInt(VainqueurEnchere[0]);printf("\n");
            CouleurAtout=VainqueurEnchere[1];
            PhaseDeJeu+=1;

            //Déroulement partie tour par tour

            int VainqueurManche;

            int RecupJoueur[32],RecupOuest[32],RecupEst[32],RecupNord[32],Compteur=0;


            VainqueurManche=VainqueurEnchere[0];
            CorrespondanceInt(VainqueurManche);
            printf(" commence\n");

            for (i=0;i<8;i++){
                EnteteJeu(CouleurAtout,i+61);
                AffichageCartes(MainJoueur);
                int Pli[4]={0,0,0,0};

                if (VainqueurManche==71){
                    Pli[0]=JeuJoueur(MainJoueur, CouleurAtout, Pli);
                        printf("   Joueur joue ");CorrespondanceInt(Pli[0]);printf("\n\n");
                    Pli[1]=JeuBot(MainOuest, CouleurAtout, Pli);
                        printf("   Ouest joue ");CorrespondanceInt(Pli[1]);printf("\n\n");
                    Pli[2]=JeuBot(MainNord, CouleurAtout, Pli);
                        printf("   Nord joue ");CorrespondanceInt(Pli[2]);printf("\n\n");
                    Pli[3]=JeuBot(MainEst, CouleurAtout, Pli);
                        printf("   Est joue ");CorrespondanceInt(Pli[3]);printf("\n\n");
                }
                if (VainqueurManche==72){
                    Pli[0]=JeuBot(MainOuest, CouleurAtout, Pli);
                        printf("   Ouest joue ");CorrespondanceInt(Pli[0]);printf("\n\n");
                    Pli[1]=JeuBot(MainNord, CouleurAtout, Pli);
                        printf("   Nord joue ");CorrespondanceInt(Pli[1]);printf("\n\n");
                    Pli[2]=JeuBot(MainEst, CouleurAtout, Pli);
                        printf("   Est joue ");CorrespondanceInt(Pli[2]);printf("\n\n");
                    Pli[3]=JeuJoueur(MainJoueur, CouleurAtout, Pli);
                        printf("   Joueur joue ");CorrespondanceInt(Pli[3]);printf("\n\n");
                }
                if (VainqueurManche==73){
                    Pli[0]=JeuBot(MainNord, CouleurAtout, Pli);
                        printf("   Nord joue ");CorrespondanceInt(Pli[0]);printf("\n\n");
                    Pli[1]=JeuBot(MainEst, CouleurAtout, Pli);
                        printf("   Est joue ");CorrespondanceInt(Pli[1]);printf("\n\n");
                    Pli[2]=JeuJoueur(MainJoueur, CouleurAtout, Pli);
                        printf("   Joueur joue ");CorrespondanceInt(Pli[2]);printf("\n\n");
                    Pli[3]=JeuBot(MainOuest, CouleurAtout, Pli);
                        printf("   Ouest joue ");CorrespondanceInt(Pli[3]);printf("\n\n");
                }
                if (VainqueurManche==74){
                    Pli[0]=JeuBot(MainEst, CouleurAtout, Pli);
                        printf("   Est joue ");CorrespondanceInt(Pli[0]);printf("\n\n");
                    Pli[1]=JeuJoueur(MainJoueur, CouleurAtout, Pli);
                        printf("   Joueur joue ");CorrespondanceInt(Pli[1]);printf("\n\n");
                    Pli[2]=JeuBot(MainOuest, CouleurAtout, Pli);
                        printf("   Ouest joue ");CorrespondanceInt(Pli[2]);printf("\n\n");
                    Pli[3]=JeuBot(MainNord, CouleurAtout, Pli);
                        printf("   Nord joue ");CorrespondanceInt(Pli[3]);printf("\n\n");
                }

                VainqueurManche=GagnantPli(Pli, CouleurAtout);
                Compteur=MancheGagneePar(VainqueurManche,Compteur,Pli,RecupJoueur,RecupOuest,RecupEst,RecupNord);


            }
        }while(2==2);
    }

}
