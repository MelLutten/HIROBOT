#include "position.h"

position::position():d_numColonne{0},d_numLigne{0}
{}

position::position(int col,int lig):d_numColonne{col},d_numLigne{lig}
{}

position::position(position&p):d_numColonne{p.numColonne()},d_numLigne{p.numLigne()}
{}

int position::numColonne()const{
    return d_numColonne;
}

int position::numLigne()const{
    return d_numLigne;
}

void position::changerPosition(int col,int lig){

    d_numColonne=col;
    d_numLigne=lig;


}

void position::sauverPosition(std::ostream&ost){
    ost<<"["<<d_numLigne<<","<<d_numColonne<<"]";
}

void position::LireDepuis(std::istream&ist){
    char ac;
    ist>>ac>>d_numColonne>>ac;
    ist>>d_numLigne>>ac;
}

void position::afficherPosition(){
    std::cout<<d_numLigne<<";"<<d_numColonne<<std::endl;
}

std::ostream& operator<<(std::ostream&ost, position&p){
    p.sauverPosition(ost);
    return ost;
}
