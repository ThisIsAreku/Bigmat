#include "fenetre.h"

Fenetre::Fenetre() : QWidget(){
    layout = new QGridLayout;

    //les opérandes

    calculate = new QPushButton("calculer");
    moin = new QPushButton("-");
    plus = new QPushButton("+");
    fois = new QPushButton("x");
    diviser = new QPushButton("/");
    carre = new QPushButton("M²");
    cube = new QPushButton("M³");
    puissanceN = new QPushButton("Mn");
    inverse = new QPushButton("1/M");

    file1Name = new QString("");
    file1 = new QLineEdit;
    parcourirFile1 = new QPushButton("parcourir");

    file2Name = new QString("");
    file2 = new QLineEdit;
    parcourirFile2 = new QPushButton("parcourir");


    //autre boutons

    clean = new QPushButton("C");

    //affichage

    affichage = new QLabel;
    affichage->setMinimumWidth(350);
    affichage->setMinimumHeight(250);
    affichage->setStyleSheet("QLabel { background-color : white; border-radius: 5px; }");

    //layout
    layout->addWidget(file1,3,0,1,6);
    layout->addWidget(parcourirFile1,3,6);
    layout->addWidget(file2,4,0,1,6);
    layout->addWidget(parcourirFile2,4,6);
    layout->addWidget(clean,3,7);
    layout->addWidget(plus,6,7);
    layout->addWidget(moin,6,8);
    layout->addWidget(fois,5,7);
    layout->addWidget(diviser,5,8);
    layout->addWidget(carre,4,7);
    layout->addWidget(cube,4,8);
    layout->addWidget(inverse,5,9);
    layout->addWidget(calculate,7,7,1,3);
    layout->addWidget(affichage,0,0,2,10);

    setLayout(layout);

    QObject::connect(parcourirFile1, SIGNAL(clicked()), this, SLOT(parcourir()));
}

Fenetre::~Fenetre(){

}

void Fenetre::parcourir(){
    QString fichier = QFileDialog::getSaveFileName(this, "Enregistrer un fichier", QString(), "Images (*.png *.gif *.jpg *.jpeg)");
}
