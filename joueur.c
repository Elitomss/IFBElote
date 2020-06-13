#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "jeu.h"

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
        MainCartes[8]=AtoutJoueur;

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

int JeuJoueur(int *MainJoueur, int Atout, int *CartesJouees){

    int i;
    int Card, Renvoi=0;
    int CouleurManche;

    while(Renvoi==0){

        printf("Entrez le numero de la carte que vous voulez jouer : ");

        if(CartesJouees[0]==0){//Si il n'y a aucune carte de jouée le joueur peut prendre n'importe quelle carte
            Card=0;
            scanf("%d",&Card);printf("\n");
            Card=Card-1;

            if(MainJoueur[Card]==0 || Card<0 || Card>7){//Cette ligne vérifie que le joueur ne joue pas une carte qu'il n'a pas
                 printf("Carte Invalide\n");

            }else{
                Renvoi=1;
                return MainJoueur[Card];
                MainJoueur[Card]=0;//On "enlève" la carte de la main du Joueur
            }

        }else{

            CouleurManche=CartesJouees[0]/10;

            scanf("%d",&Card);printf("\n");
            Card=Card-1;

            if(MainJoueur[Card]/10==CouleurManche){ //Si la carte est de la couleur jouée
                Renvoi=1;
                return MainJoueur[Card];
                MainJoueur[Card]=0;//On "enlève" la carte de la main du Joueur

            }else{ //Si la carte n'est pas de la couleur jouée
                for(i=0;i<8;i++){
                    if(MainJoueur[i]/10==CouleurManche){//On vérifie que le joueur n'a pas la couleur dans sa main
                        printf("Vous ne pouvez pas jouer cette carte (Couleur)\n");
                        Card=0;

                    }else if(MainJoueur[i]==Atout && MainJoueur[Card] != Atout){//On vérifie que le joueur n'a pas d'atout dans sa main et n'en joue pas un
                        printf("Vous ne pouvez pas jouer cette carte (Atout)\n");
                        Card=0;

                    }else{//Si il n'a ni couleur ni atout, il jouera cette carte
                        Renvoi=1;
                        return MainJoueur[Card];
                        MainJoueur[Card]=0;//On "enlève" la carte de la main du Joueur
                    }
                }


            }
        }
    }
}
