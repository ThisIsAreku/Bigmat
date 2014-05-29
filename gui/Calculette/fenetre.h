#ifndef FENETRE_H
#define FENETRE_H

#include <QMessageBox>
#include <QWidget>
#include <QGridLayout>
#include <QPushButton>
#include <QLabel>
#include <QString>
#include <QLineEdit>
#include <QFileDialog>

class Fenetre : public QWidget{
Q_OBJECT
protected:

    QGridLayout *layout;

    //les opérandes
    QPushButton *calculate;
    QPushButton *plus;
    QPushButton *moin;
    QPushButton *fois;
    QPushButton *diviser;
    QPushButton *carre;
    QPushButton *cube;
    QPushButton *puissanceN;
    QPushButton *inverse;
    QPushButton * transpo;

    // chiffres

    QPushButton *one;
    QPushButton *two;
    QPushButton *three;
    QPushButton *four;
    QPushButton *five;
    QPushButton *six;
    QPushButton *seven;
    QPushButton *eight;
    QPushButton *nine;
    QPushButton *zero;
    QPushButton *point;

    //input

    QLineEdit *file1;
    QPushButton *parcourirFile1;
    QString file1Name;
    QString file2Name;

    QLineEdit *file2;
    QPushButton *parcourirFile2;

    //autres bouton
    QPushButton *clean;

    //affichage
    QLabel *affichage;
    QString operande;

public:
    Fenetre();
    ~Fenetre();

signals:

public slots:
    void clear();
    void setFile1Name();
    void setFile2Name();
    void setAffichage();
    void showInput2();
    void hideInput2();
    void addition();
    void soustraction();
    void multiplication();
    void division();
    void puissance2();
    void puissance3();
    void calcul();
};

#endif // FENETRE_H
