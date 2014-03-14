#ifndef _ARRAY_MATRIX_
#define _ARRAY_MATRIX_
#include "MatrixEngine.h"

template <typename T>

class ArrayMatrix : public MatrixEngine<T>
{
private:
	T **_matrix;
	unsigned int _width;
	unsigned int _height;
public:
	ArrayMatrix(unsigned int width, unsigned int height)
	{
		_width = width;
		_height = height;

		for (unsigned int i = 0; i < _width ; i++)
		{
			_matrix = new T[i];
			for (unsigned int y = 0; y < _height; y++)
				_matrix[i][y] = new T;
		}
	}

	T get(unsigned int x, unsigned int y)
	{
		if(x < _width && y < _height && x > 0 && y > 0)
			return _matrix[x][y];
		return 0;
	};

	void set(unsigned int x, unsigned int y, T v)
	{
		if(x < _width && y < _height && x > 0 && y > 0)
			_matrix[x][y] = v;
	};

	unsigned int getWidth(){ return _width; };
	unsigned int getHeight(){ return _height; };
};

#endif
