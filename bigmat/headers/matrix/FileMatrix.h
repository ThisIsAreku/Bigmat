#ifndef _FILE_MATRIX_
#define _FILE_MATRIX_
#include "MatrixEngine.h"

#include <fstream>
#include <cstdlib>
#include <cstring>
#include <random>

template <typename T>

/**
   * \file FileMatrix.h
   * \author ABNP
   * \date 13 Mai 2014
*/

class FileMatrix : public MatrixEngine<T>
{
private:

    char id[4];

    std::fstream data;

    unsigned int _width;
    unsigned int _height;
    unsigned long _numcell;

    void createFile(const char* name)
    {
        std::ofstream tmp(name);
        tmp.flush();
        tmp.close();
    }

public:

    /**
        * \fn FileMatrix
        * \param width Entier désignant la largeur
        * \param height Entier désignant la hauteur
        * \param prec Streamsize par défaut égal à 4
        * \brief Constructeur du FileMatrix.
    */

    FileMatrix(unsigned int width, unsigned int height, std::streamsize prec = 4)
    { 
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dis(65, 90);
        // génération d'un ID à 4 caractères aléatoires
        for (int i = 0; i < 4; ++i)
        {
            id[i] = (char)(dis(gen));
        }
        /*
        	Sauvegarde des bornes de la matrice
        */
        _width = width;
        _height = height;
        _numcell = _width*_height;

        char const *folder = getenv("TMPDIR");
        if (folder == 0)
            folder = "/tmp";

        char fname[14];
        int len = strlen(folder);

        strcpy(fname, folder);

        strcpy(fname+len, "/");
        strncpy(fname+len+1, id, 4);

        strcpy(fname+len+5, "_bigmat_filematrix_data.txt");
        createFile(fname);
        data.open(fname);
        data.precision(prec);

        if(!data){
            std::cerr << "FAILURE" << std::endl;
            return;
        }

        T buff = 0;
        for (unsigned long i = 0; i < _numcell; ++i)
        {
            data.write(reinterpret_cast<char*>(&buff), sizeof(T));
        }
    }

    /**
        * \fn ~FileMatrix
        * \brief Destructeur du FileMatrix.
    */

    ~FileMatrix()
    {
        data.flush();
        data.close();
    }

    /**
        * \fn get
        * \param x Entier, première coordonée de l'adresse
        * \param y Entier, seconde coordonnée de l'adresse
        * \brief Permet de recupèrer une valeur a une adresse donnée.
    */
    
    T get(unsigned int x, unsigned int y)
    {
        data.seekg((x*_width+y)*sizeof(T));
        T v;
        data.read(reinterpret_cast<char*>(&v), sizeof(T));
        return v;
    };

    /**
        * \fn set
        * \param x Entier, première coordonée de l'adresse
        * \param y Entier, seconde coordonnée de l'adresse
        * \param v Nouvelle valeur a donner à l'adresse donnée
        * \brief Permet de modifier la valeur de l'adresse donnée.
    */  

    void set(unsigned int x, unsigned int y, T v)
    {
        data.seekp((x*_width+y)*sizeof(T));
        data.write(reinterpret_cast<char*>(&v), sizeof(T));
    };

    /**
        * \fn getWidth()
        * \brief Retourne la largeur de la matrice.
    */

    unsigned int getWidth()
    {
        return _width;
    };

    /**
        * \fn getHeight()
        * \brief Retourne la hauteur de la matrice
    */

    unsigned int getHeight()
    {
        return _height;
    };

    /**
        * \fn setWidth()
        * \param width Nouvelle largeur
        * \brief Défini la largeur de la matrice
    */

    void setWidth(unsigned int width)
    {
        if(width < getWidth())
            _width = width;
    };

    /**
        * \fn setHeight()
        * \param height Nouvelle hauteur
        * \brief Défini la hauteur de la matrice
    */
    void setHeight(unsigned int height)
    {
        if(height < getHeight())
            _height = height;
    };
};

#endif
