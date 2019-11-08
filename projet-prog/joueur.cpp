#include "joueur.h"

joueur::joueur():d_nom{""},d_case{nullptr},d_score{0}, d_dureeVie{0}, d_nbrobotdetruit{0}
{}

joueur::joueur(std::string&nom,position* pos,int score,int dureeVie):d_nom{nom},d_case{pos},d_score{score},d_dureeVie{dureeVie},d_nbrobotdetruit{0}
{}

joueur::~joueur(){
delete d_case;
}

position* joueur::positionJoueur()const{

    return d_case;
}

int joueur::score()const{
    return d_score;

}

int joueur::NombreRobotDetruit()const{
    return d_nbrobotdetruit;
}

void joueur::deplacerJoueur(position*p){
    d_case = new position(p->numColonne(),p->numLigne());
}

void joueur::sauverJoueur(std::ostream&ost)const{

    ost<<"("<<d_nom<<","<<d_case<<","<<d_score<<","<<d_dureeVie<<")";
}

void joueur::LireDepuis(std::istream&ist){
char c;
ist>>c>>d_nom>>c;
d_case->LireDepuis(ist);
ist>>c>>d_score>>c>>d_dureeVie>>c;

}

bool joueur::peutSeDeplacer(const position&p)const{

return((d_case->numLigne()-1<=p.numLigne())&&(p.numLigne()<=d_case->numLigne()+1)&&
((d_case->numColonne()-1<=p.numColonne())&&(p.numColonne()<=d_case->numColonne()+1)));


/*le petit terrain a pour coordonnées
posiActel.ligne-1 et posiActel.ligne+1
posiActel.col-1 posiActel.col+1
et on cherche si la position ou on veut se deplacer  est tdans cette zone
*/


}

std::ostream& operator<<(std::ostream&ost, joueur& j){

    j.sauverJoueur(ost);
    return ost;

}
