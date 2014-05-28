#ifndef _FILE_MATRIX_
#define _FILE_MATRIX_
#include "MatrixEngine.hpp"

#include <fstream>
#include <cstdlib>
#include <cstring>
#include <random>

/**
   * \file FileMatrix.h
   * \author ABNP
   * \date 13 Mai 2014
*/

/**
    * \class     FileMatrix
    * \tparam T  Type de donnée
    * \brief     Classe de matrice sous la forme de Fichier
 */
template <typename T>
class FileMatrix : public MatrixEngine<T>
{
private:

    char id[4];

    std::fstream data;

    unsigned int _width;
    unsigned int _height;
    unsigned long _numcell;
    std::streamsize _prec;

    void createFile(const char *name)
    {
        std::ofstream tmp(name);
        tmp.flush();
        tmp.close();
    }

    void allocation()
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
        _numcell = _width * _height;

        char const *folder = getenv("TMPDIR");
        if (folder == 0)
            folder = "/tmp";

        char fname[14];
        int len = strlen(folder);

        strcpy(fname, folder);

        strcpy(fname + len, "/");
        strncpy(fname + len + 1, id, 4);

        strcpy(fname + len + 5, "_bigmat_filematrix_data.txt");
        createFile(fname);
        data.open(fname);
        data.precision(_prec);

        if(!data)
        {
            std::cerr << "FAILURE" << std::endl;
            return;
        }

        T buff = 0;
        for (unsigned long i = 0; i < _numcell; ++i)
        {
            data.write(reinterpret_cast<char *>(&buff), sizeof(T));
        }
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
        _prec = prec;
        _width = width;
        _height = height;
    }

    /**
        * \fn FileMatrix
        * \param a Reference d'une MatrixEngine<T>
        * \brief Constructeur par recopie depuis une autre Engine.
    */
    FileMatrix(MatrixEngine<T> &a, std::streamsize prec = 4)
    {
        _prec = prec;
        _width = a.getWidth();
        _height = a.getHeight();

        allocation();

        for (unsigned int i = 0; i < a.getWidth(); ++i)
        {
            for (unsigned int j = 0; j < a.getHeight(); ++j)
            {
                T v = a.get(i, j);
                if(v != 0)
                    set(i, j, v);
            }
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
        data.seekg((x * _width + y)*sizeof(T));
        T v;
        data.read(reinterpret_cast<char *>(&v), sizeof(T));
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
        data.seekp((x * _width + y)*sizeof(T));
        data.write(reinterpret_cast<char *>(&v), sizeof(T));
    };

    /**
        * \fn getWidth()
        * \brief Retourne la largeur de la matrice
        * \return largeur de la matrice
    */
    unsigned int getWidth()
    {
        return _width;
    };

    /**
        * \fn getHeight()
        * \brief Retourne la hauteur de la matrice
        * \return Hauteur de la matrice
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
