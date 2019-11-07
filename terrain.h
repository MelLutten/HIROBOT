#ifndef TERRAIN_H
#define TERRAIN_H

#include "joueur.h"
#include "robot.h"
#include "time.h"
#include <iostream>
#include <fstream>
#include <vector>


class terrain
{
    public:
     terrain();
     terrain(int nbdebris, int nbrobotfirstG, int nbrobotsecondG, int nbligne, int nbcolonne);

     int nbColonne()const;
     int nbLigne()const;
     int nbDebris()const;
     int nbRobot1G()const;
     int nbRobot2G()const;

     void lireTerrain(const std::string&nomFichier);
     void sauverTerrain(const std::string&nomFichier);
     void changerTailleGrille(int nbligne, int nbcolonne);
     void changerNb(int nbdebris,int nbRobot1G,int nbRobot2G);

    private :
     int d_nbdebris;
    // joueur d_joueur;
     int d_nbrobotFirstG;
     int d_nbrobotSecondG;
     int d_nbligne;
     int d_nbcolonne;

    // std::vector<std::vector<int>> d_grille; // 0 = vide, 1 = joueur, 2 = robot1G, 3 = robot2G, 4 = debris
    // std::vector<robot*> d_robot1G;
    // std::vector<robot*> d_robot2G;




};

#endif // TERRAIN_H

