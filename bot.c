#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "jeu.h"

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
    }else if (CoeurFort>TreflFort && CoeurFort>CarreFort && CoeurFort>PiqueFort){
        AtoutBot=1;
    }else if (TreflFort>CoeurFort && TreflFort>CarreFort && TreflFort>PiqueFort){
        AtoutBot=2;
    }else if (CarreFort>TreflFort && CarreFort>CoeurFort && CarreFort>PiqueFort){
        AtoutBot=3;
    }else if (PiqueFort>TreflFort && PiqueFort>CarreFort && PiqueFort>CoeurFort){
        AtoutBot=4;
    }else{
        AtoutBot=6;
    }

    MainCartes[8]=AtoutBot;

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

int JeuBot(int *MainBot, int Atout, int *CartesJouees){

    int PresenceAtout=0;
    int i,ii,j=0;
    int CouleurManche,BestCardManche,Card=0,WorstCard;
    int CartesJouables[8],CarteRenvoyee;

    if(CartesJouees[0]==0){//Si le bot est le premier à jouer, il pose une carte aléatoirement
        srand(time(NULL));
        while(MainBot[Card]==0){
            Card=rand()%8;
        }
        return MainBot[Card];

    }else{//Si le bot n'est pas le premier

        CouleurManche=CartesJouees[0]/10; //il cherche la couleur jouée
        BestCardManche=CartesJouees[0]; //par défaut la meilleure carte est la première

        //On cherche la meilleure carte du pli
        for(i=1;i<4;i++){
            if(CartesJouees[i]/10==BestCardManche/10 && CartesJouees[i]%10>BestCardManche%10){
                BestCardManche=CartesJouees[i];
            }else if(CartesJouees[i]/10==Atout && CartesJouees[i]%10>BestCardManche%10){
                BestCardManche=CartesJouees[i];
            }
        }

        if(BestCardManche/10==Atout){
            for(i=0;i<8;i++){
                if(MainBot[i]/10==Atout && MainBot[i]>BestCardManche){
                    Card=MainBot[i];
                }
            }
        }else if(BestCardManche/10==CouleurManche){
            for(i=0;i<8;i++){
                if(MainBot[i]/10==CouleurManche && MainBot[i]>BestCardManche){
                    Card=MainBot[i];
                }
            }
        }
        if(Card==0){
            WorstCard=MainBot[0];
            for(i=1;i<8;i++){
                if(MainBot[i]%10<WorstCard%10){
                    WorstCard=MainBot[i];
                }
            }
        }
        return MainBot[Card];
        MainBot[Card]=0;
    }
}

