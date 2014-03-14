#ifndef _ARRAY_MATRIX_
#define _ARRAY_MATRIX_
#include "MatrixEngine.h"

template <typename T>

class ArrayMatrix : public MatrixEngine<T>
{
private:
	struct MatCell
	{
		unsigned int x;
		unsigned int y;
		MatCell(unsigned int x, unsigned int y) : x(x), y(y) {};
	};

	int **_matrix;
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
		return _matrix[x][y];
	};

	void set(unsigned int x, unsigned int y, T v)
	{
		if(x > _width && y > _height)
			std::cout << "Error : matrix overflow" << std::endl;
		_matrix[x][y] = v;
	};

	unsigned int getWidth(){ return width; };
	unsigned int getHeight(){ return height; };
};

#endif
