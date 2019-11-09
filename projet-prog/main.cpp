#include "grille.h"
#include "joueur.h"
#include <QApplication>
#include "fenetre.h"

int main(int argc, char *argv[])
{
   /* position* p = new position{0,0};
    std::string nom = "Jean";
    joueur j(nom,p,0,0); */

  // terrain t(1,1,1,5,5,j);
    terrain t;
   // t.afficheGrille();
   // t.ChangerJoueur(j);

   QApplication app{argc,argv};
    fenetre f(t);
    f.show();
    app.exec();


}
