#ifndef _ARRAY_MATRIX_
#define _ARRAY_MATRIX_
#include "MatrixEngine.hpp"

/**
   * \file ArrayMatrix.h
   * \author ABNP
   * \date 13 Mai 2014
*/

/**
    * \class     ArrayMatrix
    * \tparam T  Type de donnée
    * \brief     Classe de matrice sous la forme de Tableau
 */
template <typename T>
class ArrayMatrix : public MatrixEngine<T>
{
private:
    // Déclaration d'un double tableau de type T
    // (T est fait pour être nimporte quel type de donnée)
    T **_matrix;
    T *_data;
    unsigned int _width;
    unsigned int _height;

    void allocation()
    {
        if(_matrix != NULL || _data != NULL)
            return;
        _matrix = new T*[_width];
        _data = new T[_width * _height];
        for (unsigned int i = 0; i < _width; ++i)
        {
            _matrix[i] = _data + (i * _height);
        }
    }
public:
    ArrayMatrix(unsigned int width, unsigned int height)
    {
        /**
        	* \brief Sauvegarde des bornes de la matrice.
        */

        _width = width;
        _height = height;

        /**
        	* \brief Allocation de la taille passé en paramettre.
        */

        _matrix = NULL;
        _data = NULL;
        allocation();

        /**
            * \brief Remplissage avec des 0.
        */

        std::fill(_data, _data + (_width * _height), 0);
    }

    ~ArrayMatrix()
    {
        delete [] _matrix;
        delete [] _data;
    }

    /**
        * \fn ArrayMatrix
        * \param m Reference d'une autre ArrayMatrix
        * \brief Constructeur par recopie (plus rapide que le constructeur qui suit qui est général).
    */
    ArrayMatrix(ArrayMatrix &m)
    {
        _width = m._width;
        _height = m._height;

        _matrix = NULL;
        _data = NULL;
        allocation();

        // copie de m._data dans this->_data
        std::copy(m._data, m._data + (_width * _height), _data);
    }

    /**
        * \fn ArrayMatrix
        * \param a Reference d'une MatrixEngine
        * \brief Constructeur par recopie depuis une autre Engine.
    */
    ArrayMatrix(MatrixEngine<T> &a)
    {
        _width = a.getWidth();
        _height = a.getHeight();

        _matrix = NULL;
        _data = NULL;
        allocation();

        // remplissage avec des 0
        std::fill(_data, _data + (_width * _height), 0);

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
        * \brief Permet de recupèrer une valeur a une adresse donnée.
    */
    T get(unsigned int x, unsigned int y)
    {
        if(x < _width && y < _height)
            return _matrix[x][y];
        return 0;
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
        if(x < _width && y < _height)
            _matrix[x][y] = v;
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
        * \param width Entier positif, largeur a assigner à la matrice
        * \brief Défini la largeur de la matrice.
    */
    void setWidth(unsigned int width)
    {
        if(width == getWidth())
            return;

        this->_width = width;

        T *newData = new T[_width * _height];
        std::copy(newData, newData + (_width * _height), _data);

        delete [] _data;
        delete [] _matrix;

        _data = newData;
        _matrix = new T*[_width];
        for (unsigned int i = 0; i < _width; ++i)
        {
            _matrix[i] = _data + (i * _height);
        }
    };

    /**
        * \fn setHeight()
        * \param height Nouvelle hauteur
        * \brief Défini la hauteur de la matrice
    */
    void setHeight(unsigned int height)
    {
        if(height == getHeight())
            return;

        // sauvegarde de l'ancienne matrice
        T *oldData = new T[_width * _height];
        T **ptr_old = new T*[_width];
        std::copy(oldData, oldData + (_width * _height), _data);
        for (unsigned int i = 0; i < _width; ++i)
        {
            ptr_old[i] = oldData + (i * _height);
        }

        delete [] _data;
        delete [] _matrix;

        this->_height = height;

        _data = NULL;
        _matrix = NULL;
        allocation();

        for (unsigned int i = 0; i < _width; ++i)
        {
            for (unsigned int j = 0; j < _height; ++j)
            {
                set(i, j, ptr_old[i][j]);
            }
        }
    };

};

#endif
