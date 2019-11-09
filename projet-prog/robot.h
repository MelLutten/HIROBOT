#ifndef ROBOT_H
#define ROBOT_H

#include "joueur.h"
#include <iostream>
#include <vector>


class robot {
public :
    robot(position* p);
    position* positionRobot() const;
    bool detecterJoueur(joueur&j)const;
    void deplacerRobot(joueur&j);
    void deplacerRobotAuHasard();

private :
    position* d_case;
};

#endif // ROBOT_H
