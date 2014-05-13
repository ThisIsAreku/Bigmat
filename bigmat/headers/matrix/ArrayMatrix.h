#ifndef _ARRAY_MATRIX_
#define _ARRAY_MATRIX_
#include "MatrixEngine.h"

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
        /*
        	Sauvegarde des bornes de la matrice
        */
        _width = width;
        _height = height;

        /*
        	Allocation de la taille passé en paramettre
        */
        _matrix = NULL;
        _data = NULL;
        allocation();

        // remplissage avec des 0
        std::fill(_data, _data + (_width * _height), 0);
    }

    ~ArrayMatrix()
    {
        delete [] _matrix;
        delete [] _data;
    }

    // constructeur par recopie (plus rapide que le ctor d'après qui est général)
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

    // constructeur par recopie depuis autre Engine
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


    /*

    Permet de recupèrer une valuer a une adresse
    */
    T get(unsigned int x, unsigned int y)
    {
        if(x < _width && y < _height)
            return _matrix[x][y];
        return 0;
    };
    /*
    	Permet de recuperer une valeur a une adresse (x et y)
    */
    void set(unsigned int x, unsigned int y, T v)
    {
        if(x < _width && y < _height)
            _matrix[x][y] = v;
    };

    /**
        * \fn getWidth()
        * \brief Retourne la largeur de la matrice
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
        if(width == getWidth())
            return;

        this->_width = width;

        T * newData = new T[_width*_height];
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
        T * oldData = new T[_width*_height];
        T ** ptr_old = new T*[_width];
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
