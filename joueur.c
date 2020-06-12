#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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

            if(MainJoueur[Card-1]/10!=CouleurManche){ //Si la carte n'est pas de la couleur jouée
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
