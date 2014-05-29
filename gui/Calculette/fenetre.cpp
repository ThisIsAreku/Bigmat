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
    transpo = new QPushButton("T");

    // chiffres

    one = new QPushButton("1");
    two = new QPushButton("2");
    three = new QPushButton("3");
    four = new QPushButton("4");
    five = new QPushButton("5");
    six = new QPushButton("6");
    seven = new QPushButton("7");
    eight = new QPushButton("8");
    nine = new QPushButton("9");
    zero = new QPushButton("0");
    point = new QPushButton(".");

    //input

    file1 = new QLineEdit;
    parcourirFile1 = new QPushButton("parcourir");

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
    layout->addWidget(transpo,3,8);
    layout->addWidget(plus,6,7);
    layout->addWidget(moin,6,8);
    layout->addWidget(fois,5,7);
    layout->addWidget(diviser,5,8);
    layout->addWidget(carre,4,7);
    layout->addWidget(cube,4,8);
    layout->addWidget(inverse,5,9);
    layout->addWidget(calculate,7,7,1,3);
    layout->addWidget(one,5,0);
    layout->addWidget(two,5,1);
    layout->addWidget(three,5,2);
    layout->addWidget(four,5,3);
    layout->addWidget(five,6,0);
    layout->addWidget(six,6,1);
    layout->addWidget(seven,6,2);
    layout->addWidget(eight,6,3);
    layout->addWidget(nine,7,0);
    layout->addWidget(zero,7,1);
    layout->addWidget(point,7,2);
    layout->addWidget(affichage,0,0,2,10);

    setLayout(layout);

    file2->hide();
    parcourirFile2->hide();

    QObject::connect(clean, SIGNAL(clicked()), this, SLOT(clear()));
    QObject::connect(parcourirFile1, SIGNAL(clicked()), this, SLOT(setFile1Name()));
    QObject::connect(parcourirFile2, SIGNAL(clicked()), this, SLOT(setFile2Name()));
    QObject::connect(plus, SIGNAL(clicked()), this, SLOT(addition()));
    QObject::connect(moin, SIGNAL(clicked()), this, SLOT(soustraction()));
    QObject::connect(fois, SIGNAL(clicked()), this, SLOT(multiplication()));
    QObject::connect(diviser, SIGNAL(clicked()), this, SLOT(division()));
    QObject::connect(carre, SIGNAL(clicked()), this, SLOT(puissance2()));
    QObject::connect(cube, SIGNAL(clicked()), this, SLOT(puissance3()));
}

Fenetre::~Fenetre(){

}

void Fenetre::clear(){
    file1Name = "";
    file1->setText(file1Name);
    file2Name = "";
    file2->setText(file2Name);
    affichage->setText("");
    hideInput2();

}

void Fenetre::setFile1Name(){
    QString fichier = QFileDialog::getSaveFileName(this, "Enregistrer un fichier", QString(), "Text (*.txt)");
    file1Name = fichier;
    file1->setText(file1Name);
    operande = "";
    setAffichage();
}

void Fenetre::setFile2Name(){
    QString fichier = QFileDialog::getSaveFileName(this, "Enregistrer un fichier", QString(), "Text (*.txt)");
    file2Name = fichier;
    file2->setText(file2Name);
    setAffichage();
}

void Fenetre::setAffichage(){

    QString TextShow("");
    if(file1Name != ""){
        TextShow += " A";
        if(operande != ""){
            TextShow += operande;
            if(file2Name != ""){
               TextShow += "B";
            }
        }
    }
    affichage->setText(TextShow);
}

void Fenetre::showInput2(){
    file2->show();
    parcourirFile2->show();
}

void Fenetre::hideInput2(){
    file2->hide();
    parcourirFile2->hide();
}

void Fenetre::addition(){
    operande = " + ";
    showInput2();
    setAffichage();
}

void Fenetre::soustraction(){
    operande = " - ";
    showInput2();
    setAffichage();
}

void Fenetre::multiplication(){
    operande = " * ";
    showInput2();
    setAffichage();
}

void Fenetre::division(){
    operande = " / ";
    showInput2();
    setAffichage();
}

void Fenetre::puissance2(){
    operande = "²";
    setAffichage();
}

void Fenetre::puissance3(){
    operande = "³";
    setAffichage();
}

void Fenetre::calcul(){

}
