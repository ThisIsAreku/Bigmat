#ifndef _FILE_MATRIX_
#define _FILE_MATRIX_
#include "MatrixEngine.h"

#include <fstream>
#include <cstdlib>
#include <cstring>
#include <random>

template <typename T>

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

        char fname[14];
        strncpy(fname, id, 4);

        strcpy(fname+4, "_data.txt");
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

    ~FileMatrix()
    {
        data.flush();
        data.close();
    }


    /*

    Permet de recupèrer une valuer a une adresse
    */
    T get(unsigned int x, unsigned int y)
    {
        data.seekg((x*_width+y)*sizeof(T));
        T v;
        data.read(reinterpret_cast<char*>(&v), sizeof(T));
        return v;
    };
    /*
    	Permet de recuperer une valeur a une adresse (x et y)
    */
    void set(unsigned int x, unsigned int y, T v)
    {
        data.seekp((x*_width+y)*sizeof(T));
        data.write(reinterpret_cast<char*>(&v), sizeof(T));
    };

    // Pemet de recupèrer les tailles de la matrice.
    unsigned int getWidth()
    {
        return _width;
    };
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
