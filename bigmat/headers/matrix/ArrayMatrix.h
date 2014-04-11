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
        _matrix = new T*[_width];
        _data = new T[_width * _height];
        for (unsigned int i = 0; i < _width; ++i)
        {
            _matrix[i] = _data + (i * _height);
        }
        std::fill(_data, _data + (_width * _height), 0);
    }

    ~ArrayMatrix()
    {
        delete [] _matrix;
        delete [] _data;
    }

    // constructeur par recopie
    ArrayMatrix(ArrayMatrix &m)
    {
        _width = m._width;
        _height = m._height;

        _matrix = new T*[_width];
        _data = new T[_width * _height];
        for (unsigned int i = 0; i < _width; ++i)
        {
            _matrix[i] = _data + (i * _height);
        }

        std::copy(m._data, m._data + (_width * _height), _data);
    }


    /*

    Permet de recupèrer une valuer a une adresse
    */
    T get(unsigned int x, unsigned int y)
    {
        if(x < _width && y < _height && x >= 0 && y >= 0)
            return _matrix[x][y];
        return 0;
    };
    /*
    	Permet de recuperer une valeur a une adresse (x et y)
    */
    void set(unsigned int x, unsigned int y, T v)
    {
        if(x < _width && y < _height && x >= 0 && y >= 0)
            _matrix[x][y] = v;
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
