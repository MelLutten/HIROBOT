#include "robot.h"

robot::robot(position* p):d_case{p}
{}

position* robot::positionRobot() const
{
    return d_case;
}


//detecte si le joueur est present autour de lui
bool robot::detecterJoueur(joueur&j) const
{
    if ((j.positionJoueur()->numColonne()==d_case->numColonne() && j.positionJoueur()->numLigne()==(d_case->numLigne()+1))||
        (j.positionJoueur()->numColonne()==d_case->numColonne() && j.positionJoueur()->numLigne()==(d_case->numLigne()-1))||
         (j.positionJoueur()->numColonne()==(d_case->numColonne()+1) && j.positionJoueur()->numLigne()==d_case->numLigne())||
            (j.positionJoueur()->numColonne()==(d_case->numColonne()-1) && j.positionJoueur()->numLigne()==d_case->numLigne())){
        return true;
    }else{

        return false;
    }
}

void robot::deplacerRobotAuHasard()
{
   /* std::vector<position> vp(4);
    position p1(d_case->numColonne(),d_case->numLigne()+1);
    position p2(d_case->numColonne(),d_case->numLigne()-1);
    position p3(d_case->numColonne()+1,d_case->numLigne());
    position p4(d_case->numColonne()-1,d_case->numLigne());

    vp={p1,p2,p3,p4};

    int indice = rand()%static_cast<int>(vp.size());
    position posalea = vp[static_cast<unsigned>(indice)];


    d_case->changerPosition(posalea.numColonne(), posalea.numLigne());*/
}

// si le robot a detecté un joueur il se deplace sur sa case
//sinon il se deplace sur  une case au hasard se trouvant à coté
void robot::deplacerRobot(joueur&j)
{
    if (detecterJoueur(j))
    {
        d_case = j.positionJoueur();
    }
    else
    {
        deplacerRobotAuHasard();
    }
}
