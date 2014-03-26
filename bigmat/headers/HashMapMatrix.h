#ifndef _HASH_MAP_MATRIX_
#define _HASH_MAP_MATRIX_

#include <map>
#include "MatrixEngine.h"

/**
 * \file      HashMapMatrix.h
 * \author    ABNP
 * \version   1.0
 * \date      26 Mars 2014
 * \brief     Classe qui utilise une liste de clée-valeurs. une clée est une struct MatCell(x, y), la valeur est la case de la matrice
 */
template <typename T>
class HashMapMatrix : public MatrixEngine<T>
{
private:
    /**
        * \struct MatCell
        * \brief la structure permet d'écrire rapidement une coordonné x,y
        */ 
    struct MatCell
    {
        unsigned int x;
        unsigned int y;
        MatCell(unsigned int x, unsigned int y) : x(x), y(y) {};
    };
    /**
        * \class compareKeyPair
        * \brief Cette classe permet de comparer deux coordonnés,
        * \true si a doit etre avant b
        * \false si b doit etre avant a
    */
    class compareKeyPair
    {
    public:
        bool operator()(const MatCell &a, const MatCell &b)
        {
            if(a.x > b.x)
                return true;
            else if(a.x < b.x)
                return false;
            else if(a.y > b.y)
                return true;
            return false;
        };
    };

    std::map <MatCell, T, compareKeyPair> _matrix;
    unsigned int width;
    unsigned int height;
public:
    /** 
        * \fn HashMapMatrix()
        * \brief Initialise les dimensions à 0
    */
    HashMapMatrix() : width(0), height(0) {};

    /**
        * \fn get (unsigned int x, unsigned int y)
        * \brief Récupère la case à l'indexe x, y
        * \details Renvoit 0 si vide ou hors limite
    */
    T get(unsigned int x, unsigned int y)
    {
        return _matrix[MatCell(x, y)];
    };

    /** 
        * \fn set(unsigned int x, unsigned int y, T v)
        * \brief Défini la case à l'index x, y à la valeur v
        * \details Agrandit la taille stocké si l'index est plus grand (extensible)
    */
    void set(unsigned int x, unsigned int y, T v)
    {
        /**
        * \brief Taille d'un tableau : index max + 1
        */
        if(x + 1 > width)
            width = x + 1;
        if(y + 1 > height)
            height = y + 1;

        _matrix[MatCell(x, y)] = v;
    };

    unsigned int getWidth()
    {
        return width;
    };
    unsigned int getHeight()
    {
        return height;
    };

};

#endif
