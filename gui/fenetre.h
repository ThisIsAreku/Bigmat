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

public:
    Fenetre();
    ~Fenetre();

signals:

public slots:
    void clear();
    void setFile1Name();
    void setFile2Name();
};

#endif // FENETRE_H
