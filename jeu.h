void CorrespondanceInt(int Chiffre);

void Distribution(int *PaquetDeCartes, int *MainJoueur, int *MainOuest, int *MainEst, int *MainNord);
void MelangeCartes(int *PaquetDeCartes);

int ComptagePoints(int *Recup, int Atout);
int GagnantPli(int *Carte, int Atout);
int MancheGagneePar(int VainqueurManche, int Compteur, int *Pli, int *RecupJoueur, int *RecupOuest, int *RecupEst, int *RecupNord);

void EnteteJeu(int CouleurAtout, int PhaseDeJeu);
void AffichageCartes(int *MainJoueur);
