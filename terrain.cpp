#include "terrain.h"

terrain::terrain():d_nbdebris{0},d_nbrobotFirstG{0},d_nbrobotSecondG{0},d_nbligne{0},d_nbcolonne{0}
{}

terrain::terrain(int nbdebris,int nbrobotfirstG, int nbrobotsecondG, int nbligne, int nbcolonne):d_nbdebris{nbdebris},d_nbrobotFirstG{nbrobotfirstG},d_nbrobotSecondG{nbrobotsecondG},d_nbligne{nbligne},d_nbcolonne{nbcolonne}
{
         sauverTerrain("/Users/Neron/Desktop/premiereSauvegarde.txt");

}

void terrain::sauverTerrain(const std::string&nomFichier){

    std::ofstream f (nomFichier, std::ofstream::out);
    f << d_joueur << "," << d_nbdebris << "," << d_nbrobotFirstG << "," << d_nbrobotSecondG << "," << d_nbligne << "," << d_nbcolonne;
    f.close();

}

int terrain::nbColonne()const{
    return d_nbcolonne;
}

int terrain::nbLigne()const{
    return d_nbligne;
}

int terrain::nbDebris()const{
    return d_nbdebris;

}

int terrain::nbRobot1G()const{
    return d_nbrobotFirstG;
}

int terrain::nbRobot2G()const{
    return d_nbrobotSecondG;
}


void terrain::lireTerrain(const std::string&nomFichier)
{
    std::ifstream f(nomFichier);
    char c;
    f >> d_nbdebris >> c >> d_nbrobotFirstG >> c >> d_nbrobotSecondG >> c >> d_nbligne >> c >> d_nbcolonne;
}

void terrain::changerTailleGrille (int nbligne, int nbcolonne){

 d_nbligne = nbligne;
 d_nbcolonne = nbcolonne;
 d_grille.resize(static_cast<unsigned>(d_nbligne), std::vector<int>(static_cast<unsigned>(d_nbcolonne)));

}

void terrain::changerNb(int nbdebris,int nbRobot1G,int nbRobot2G){

    d_nbdebris = nbdebris;
    d_nbrobotFirstG = nbRobot1G;
    d_nbrobotSecondG = nbRobot2G;

}
