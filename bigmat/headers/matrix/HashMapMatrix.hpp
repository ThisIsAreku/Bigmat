#ifndef _HASH_MAP_MATRIX_
#define _HASH_MAP_MATRIX_

#include <map>
#include "MatrixEngine.hpp"

/**
    * \file      HashMapMatrix.h
    * \author    ABNP
    * \date      13 Mai 2014
    * \brief     Classe qui utilise une liste de clée-valeurs. une clée est une struct MatCell(x, y), la valeur est la case de la matrice
 */

/**
    * \class     HashMapMatrix
    * \tparam T  Type de donnée
    * \brief     Classe de matrice sous la forme de HashMap
 */
template <typename T>
class HashMapMatrix : public MatrixEngine<T>
{
private:

    /**
        * \struct MatCell
        * \brief Structure permettant d'écrire rapidement une coordonné x,y
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
        * \brief Constructeur initialisant les dimensions à 0
    */
    HashMapMatrix() : width(0), height(0) {};

    /**
        * \fn FileMatrix
        * \param a Reference d'une MatrixEngine<T>
        * \brief Constructeur par recopie depuis une autre Engine.
    */
    HashMapMatrix(MatrixEngine<T> &a) : width(0), height(0)
    {
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
        * \fn get
        * \param x Entier, première coordonée de l'adresse
        * \param y Entier, seconde coordonnée de l'adresse
        * \brief Permet de recupèrer la case à l'index donné.
        * \details Renvoit 0 si vide ou hors limite
    */
    T get(unsigned int x, unsigned int y)
    {
        return _matrix[MatCell(x, y)];
    };

    /**
        * \fn set
        * \param x Entier, première coordonée de l'adresse
        * \param y Entier, seconde coordonnée de l'adresse
        * \param v Nouvelle valeur a donner à l'index donné
        * \brief Défini la case à l'index donné à la valeur v
        * \details Agrandit la taille stockée si l'index est plus grand (extensible)
    */
    void set(unsigned int x, unsigned int y, T v)
    {
        if(x + 1 > width)
            width = x + 1;
        if(y + 1 > height)
            height = y + 1;

        if(v == 0)
        {
            if(_matrix[MatCell(x, y)] == 0)
            {
                return;
            }
            else
            {
                _matrix.erase(_matrix.find(MatCell(x, y)));
            }
        }

        _matrix[MatCell(x, y)] = v;
    };

    /**
        * \fn getWidth()
        * \brief Retourne la largeur de la matrice
        * \return largeur de la matrice
    */
    unsigned int getWidth()
    {
        return width;
    };

    /**
        * \fn getHeight()
        * \brief Retourne la hauteur de la matrice
        * \return Hauteur de la matrice
    */
    unsigned int getHeight()
    {
        return height;
    };


    /**
        * \fn setWidth()
        * \param width Nouvelle largeur
        * \brief Défini la largeur de la matrice
    */
    void setWidth(unsigned int width)
    {
        if(width < getWidth())
        {
            for (unsigned int i = width; i < getWidth(); ++i)
            {
                for (unsigned int j = 0; j < getHeight(); ++j)
                {
                    set(i, j, 0);
                }
            }
        }
        this->width = width;
    };

    /**
        * \fn setHeight()
        * \param height Nouvelle hauteur
        * \brief Défini la hauteur de la matrice
    */
    void setHeight(unsigned int height)
    {
        if(height < getHeight())
        {
            for (unsigned int i = height; i < getHeight(); ++i)
            {
                for (unsigned int j = 0; j < getWidth(); ++j)
                {
                    set(i, j, 0);
                }
            }
        }
        this->height = height;
    };

};

#endif
