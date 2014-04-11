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

    std::ofstream diff;
    std::ofstream data;
    std::ofstream prop;

    unsigned int _width;
    unsigned int _height;

    void createFile(const char* name)
    {
        std::ofstream tmp(name);
        tmp.flush();
        tmp.close();
    }

public:
    FileMatrix(unsigned int width, unsigned int height)
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

        char fname[14];
        strncpy(fname, id, 4);
        strncpy(fname+4, "_diff.txt", 10);
        createFile(fname);
        diff.open(fname);

        strncpy(fname+4, "_data.txt", 10);
        createFile(fname);
        data.open(fname);

        strncpy(fname+4, "_prop.txt", 10);
        createFile(fname);
        prop.open(fname);

        if(!(diff && data && prop))
            std::cerr << "FAILURE" << std::endl;
    }

    ~FileMatrix()
    {
        diff.flush();
        data.flush();
        prop.flush();

        diff.close();
        data.close();
        prop.close();
    }


    /*

    Permet de recupèrer une valuer a une adresse
    */
    T get(unsigned int x, unsigned int y)
    {
        
        return 0;
    };
    /*
    	Permet de recuperer une valeur a une adresse (x et y)
    */
    void set(unsigned int x, unsigned int y, T v)
    {
        
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
};

#endif
