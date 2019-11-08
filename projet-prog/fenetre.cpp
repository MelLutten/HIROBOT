#include "fenetre.h"

fenetre::fenetre(terrain&t):d_t{t}, d_win{this}
{
    vueCreer(t);

}



void fenetre::vueCreer(terrain&t){




    setWindowTitle("HI ROBOTS");

    if(d_t.nbColonne()==0){
        setFixedWidth(maximumWidth());
    }else{
        setFixedWidth(d_t.nbColonne()*51+138);
    }

    setStyleSheet("QMainWindow{background:#353535;}");

    //Terrain
    d_grille = new grille{t};
    d_grille->setFixedSize(d_t.nbColonne()*51+138,d_t.nbLigne()*51);

    //Titre
    auto label = new QLabel{this};
    QPixmap *logo = new QPixmap ("/Users/Neron/Desktop/hirobot2.png" );
    label->setPixmap(*logo);


    label->setFixedSize(maximumWidth(),100);
    label->setAlignment(Qt::AlignCenter);

    //Boutons niveau
    auto layoutbouton = new QHBoxLayout{};
    auto facile = new QPushButton{"FACILE"};
    auto normal = new QPushButton{"NORMAL"};
    auto difficile = new QPushButton{"DIFFICILE"};
    auto personnalise = new QPushButton{"PERSONNALISE"};
    facile->setStyleSheet("QPushButton{ background-color:#242424;font-size:11px;height:30px;color:#6C6C6C;}");
    normal->setStyleSheet("QPushButton{ background-color:#242424;font-size:11px;height:30px;color:#6C6C6C;}");
    difficile->setStyleSheet("QPushButton{ background-color:#242424;font-size:11px;height:30px;color:#6C6C6C;}");
    personnalise->setStyleSheet("QPushButton{ background-color:#242424;font-size:11px;height:30px;color:#6C6C6C;}");
    layoutbouton->addWidget(facile);
    layoutbouton->addWidget(normal);
    layoutbouton->addWidget(difficile);
    layoutbouton->addWidget(personnalise);


     connect(difficile,&QPushButton::clicked,this,&fenetre::OnDifficile);
     connect(normal,&QPushButton::clicked,this,&fenetre::OnNormal);
     connect(facile,&QPushButton::clicked,this,&fenetre::OnFacile);

     //Boutons deplacements

     auto layoutboutcote = new QHBoxLayout{};
     auto layoutbouthaut = new QHBoxLayout{};
     auto layoutboutbas = new QHBoxLayout{};
     auto haut = new QPushButton{"↑"};
     auto diagoHG = new QPushButton{"↖"};
     auto diagoHD = new QPushButton{"↗"};
     auto bas = new QPushButton{"↓"};
     auto diagoBG = new QPushButton{"↙"};
     auto diagoBD = new QPushButton{"↘"};
     auto droite = new QPushButton{"→"};
     auto gauche = new QPushButton{"←"};
     auto joueur = new QLabel{"J"};

     joueur->setAlignment(Qt::AlignCenter);


     haut->setStyleSheet("QPushButton{ background-color:#242424;font-size:20px;height:30px;color:#6C6C6C;}");
     bas->setStyleSheet("QPushButton{ background-color:#242424;font-size:20px;height:30px;color:#6C6C6C;}");
     droite->setStyleSheet("QPushButton{ background-color:#242424;font-size:20px;height:30px;color:#6C6C6C;}");
     gauche->setStyleSheet("QPushButton{ background-color:#242424;font-size:20px;height:30px;color:#6C6C6C;}");

     diagoHG->setStyleSheet("QPushButton{ background-color:#242424;font-size:20px;height:30px;color:#6C6C6C;}");
     diagoHD->setStyleSheet("QPushButton{ background-color:#242424;font-size:20px;height:30px;color:#6C6C6C;}");
     diagoBG->setStyleSheet("QPushButton{ background-color:#242424;font-size:20px;height:30px;color:#6C6C6C;}");
     diagoBD->setStyleSheet("QPushButton{ background-color:#242424;font-size:20px;height:30px;color:#6C6C6C;}");




     haut->setFixedWidth(50);
     droite->setFixedWidth(50);
     gauche->setFixedWidth(50);
     bas->setFixedWidth(50);
     diagoHG->setFixedWidth(50);
     diagoHD->setFixedWidth(50);
     diagoBG->setFixedWidth(50);
     diagoBD->setFixedWidth(50);
     joueur->setFixedWidth(40);

     layoutbouthaut->addStretch(1);
     layoutbouthaut->addWidget(diagoHG);
     layoutbouthaut->addWidget(haut);
     layoutbouthaut->addWidget(diagoHD);
     layoutbouthaut->addStretch(1);

     layoutboutcote->addStretch(1);
     layoutboutcote->addWidget(gauche);
     layoutboutcote->addWidget(joueur);
     layoutboutcote->addWidget(droite);
     layoutboutcote->addStretch(1);

     layoutboutbas->addStretch(1);
     layoutboutbas->addWidget(diagoBG);
     layoutboutbas->addWidget(bas);
     layoutboutbas->addWidget(diagoBD);
     layoutboutbas->addStretch(1);

     connect(haut,&QPushButton::clicked,this,&fenetre::OnHaut);
     connect(bas,&QPushButton::clicked,this,&fenetre::OnBas);
     connect(droite,&QPushButton::clicked,this,&fenetre::OnDroite);
     connect(gauche,&QPushButton::clicked,this,&fenetre::OnGauche);

     connect(diagoHG,&QPushButton::clicked,this,&fenetre::OnHG);
     connect(diagoHD,&QPushButton::clicked,this,&fenetre::OnHD);
     connect(diagoBG,&QPushButton::clicked,this,&fenetre::OnBG);
     connect(diagoBD,&QPushButton::clicked,this,&fenetre::OnBD);




     //Copyright
     auto layoutcopy = new QLabel{"© Faculté des Sciences et Techniques de Mulhouse <br> Kolokolnikova - Luttenschlager - Moins - Ndaw"};
     layoutcopy->setAlignment(Qt::AlignCenter);




     //Dialogue personnalisé
     d_p = new personnaliserTerrain{};

     connect(personnalise,&QPushButton::clicked,this,&fenetre::OnPerso);


    //Principale
    auto layout = new QVBoxLayout{};
    layout->addWidget(label,Qt::AlignCenter);
    layout->addLayout(layoutbouton);
    layout->addWidget(d_grille,Qt::AlignCenter);
    layout->addLayout(layoutbouthaut,Qt::AlignCenter);

    layout->addLayout(layoutboutcote,Qt::AlignCenter);
    layout->addLayout(layoutboutbas,Qt::AlignCenter);
    layout->addWidget(layoutcopy,Qt::AlignCenter);




    auto Wid = new QWidget;
    Wid->setLayout(layout);


    setCentralWidget(Wid);


}




void fenetre::OnDifficile(){

    d_t.changerTailleGrille(8,8);
    d_t.changerNb(10,3,3);
    d_t.InitialisationGrille(10,3,3);
    d_t.afficheGrille(); //Test : affichage console
    d_t.afficherPositionJoueur(); //Test : affichage console
    vueCreer(d_t);

}

void fenetre::OnNormal(){
    d_t.changerTailleGrille(5,5);
    d_t.changerNb(2,2,2);
    d_t.InitialisationGrille(2,2,2);
    d_t.afficheGrille(); //Test : affichage console
    d_t.afficherPositionJoueur(); //Test : affichage console
    vueCreer(d_t);
}

void fenetre::OnFacile(){
    d_t.changerTailleGrille(5,5);
    d_t.changerNb(1,1,1);
    d_t.InitialisationGrille(1,1,1);
    d_t.afficheGrille(); //Test affichage console
    d_t.afficherPositionJoueur(); //Test : affichage console
    vueCreer(d_t);
}

void fenetre::OnPerso(){

    d_p->exec();
    d_t = d_p->terr();
    d_t.afficheGrille(); //Test affichage console
    d_t.afficherPositionJoueur(); //Test : affichage console
    vueCreer(d_t);



}

void fenetre::OnHaut(){

    if(d_t.Joueur().positionJoueur()->numLigne()!=0){

        d_t.changerPosJoueur(new position{d_t.positionJoueur()->numColonne(),d_t.positionJoueur()->numLigne()-1});

        d_t.afficheGrille(); //Test affichage console
        d_t.afficherPositionJoueur(); //Test : affichage console
        vueCreer(d_t);
        if(d_t.JoueurAPerdu()){
            perdu();
        }
    }
}

void fenetre::OnBas(){

   if(d_t.positionJoueur()->numLigne()!=d_t.nbLigne()-1){

     d_t.changerPosJoueur(new position{d_t.positionJoueur()->numColonne(),d_t.positionJoueur()->numLigne()+1});
     d_t.afficheGrille(); //Test affichage console
     d_t.afficherPositionJoueur(); //Test : affichage console
     vueCreer(d_t);
     if(d_t.JoueurAPerdu()){
         perdu();
     }

   }

}

void fenetre::OnDroite(){

    if(d_t.positionJoueur()->numColonne()!=d_t.nbColonne()-1){

         d_t.changerPosJoueur(new position{d_t.positionJoueur()->numColonne()+1,d_t.positionJoueur()->numLigne()});
         d_t.afficheGrille(); //Test affichage console
         d_t.afficherPositionJoueur(); //Test : affichage console
         vueCreer(d_t);
         if(d_t.JoueurAPerdu()){
             perdu();
         }
    }

}

void fenetre::OnGauche(){

     if(d_t.positionJoueur()->numColonne()!=0){

         d_t.changerPosJoueur(new position{d_t.positionJoueur()->numColonne()-1,d_t.positionJoueur()->numLigne()});
         d_t.afficheGrille(); //Test affichage console
         d_t.afficherPositionJoueur(); //Test : affichage console
         vueCreer(d_t);
         if(d_t.JoueurAPerdu()){
             perdu();
         }

     }

}

void fenetre::OnHG(){

    if(d_t.positionJoueur()->numColonne()!=0 && d_t.positionJoueur()->numLigne()!=0){

          d_t.changerPosJoueur(new position{d_t.positionJoueur()->numColonne()-1,d_t.positionJoueur()->numLigne()-1});
          d_t.afficheGrille(); //Test affichage console
          d_t.afficherPositionJoueur(); //Test : affichage console

          vueCreer(d_t);
          if(d_t.JoueurAPerdu()){
              perdu();
          }
    }

}

void fenetre::OnHD(){

    if(d_t.positionJoueur()->numColonne()!=d_t.nbColonne()-1 && d_t.positionJoueur()->numLigne()!=d_t.nbLigne()-1){

         d_t.changerPosJoueur(new position{d_t.positionJoueur()->numColonne()+1,d_t.positionJoueur()->numLigne()-1});
         d_t.afficheGrille(); //Test affichage console
         d_t.afficherPositionJoueur(); //Test : affichage console

         vueCreer(d_t);
         if(d_t.JoueurAPerdu()){
             perdu();
         }
    }

}

void fenetre::OnBG(){
    if(d_t.positionJoueur()->numColonne()!=0 && d_t.positionJoueur()->numLigne()!=0){
         d_t.changerPosJoueur(new position{d_t.positionJoueur()->numColonne()-1,d_t.positionJoueur()->numLigne()+1});
         d_t.afficheGrille(); //Test affichage console
         d_t.afficherPositionJoueur(); //Test : affichage console
         vueCreer(d_t);
         if(d_t.JoueurAPerdu()){
            perdu();
         }
    }
}

void fenetre::OnBD(){

    if(d_t.positionJoueur()->numColonne()!=d_t.nbColonne()-1 && d_t.positionJoueur()->numLigne()!=d_t.nbLigne()-1){

        d_t.changerPosJoueur(new position{d_t.positionJoueur()->numColonne()+1,d_t.positionJoueur()->numLigne()+1});
        d_t.afficheGrille(); //Test affichage console
        d_t.afficherPositionJoueur(); //Test : affichage console

        vueCreer(d_t);
        if(d_t.JoueurAPerdu()){
            perdu();
        }

    }

}

void fenetre::perdu(){

    QMessageBox perdu;
    perdu.setText("Vous avez perdu");
    perdu.exec();
    terrain t;
    vueCreer(t);

}


