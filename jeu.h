void CorrespondanceInt(int Chiffre);

void Distribution(int *PaquetDeCartes, int *MainJoueur, int *MainOuest, int *MainEst, int *MainNord);
void MelangeCartes(int *PaquetDeCartes);

int EnchereBot(int *MainCartes, int EnchereHaute, int *PointeurPasse);
int EnchereJoueur(int *MainCartes, int EnchereHaute, int *PointeurPasse);

int ComptagePoints(int *Recup, int Atout);
int GagnantPli(int *Carte, int Atout);
int JeuBot(int *MainBot, int Atout, int *CartesJouees);
int JeuJoueur(int *MainJoueur, int Atout, int *CartesJouees);
int MancheGagneePar(int VainqueurManche, int Compteur, int *Pli, int *RecupJoueur, int *RecupOuest, int *RecupEst, int *RecupNord);
