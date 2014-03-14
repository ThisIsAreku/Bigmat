#ifndef _HASH_MAP_MATRIX_
#define _HASH_MAP_MATRIX_

#include <map>
#include "MatrixEngine.h"

template <typename T>
class HashMapMatrix : public MatrixEngine<T>
{
private:
	struct MatCell
	{
		unsigned int x;
		unsigned int y;
		MatCell(unsigned int x, unsigned int y) : x(x), y(y) {};
	};
	class compareKeyPair
	{
	public:
		bool operator()(const MatCell& a, const MatCell& b)
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
public:
	T get(unsigned int x, unsigned int y)
	{
		return _matrix[MatCell(x, y)];
	};

	void set(unsigned int x, unsigned int y, T v)
	{
		_matrix[MatCell(x, y)] = v;
	};

};

#endif
