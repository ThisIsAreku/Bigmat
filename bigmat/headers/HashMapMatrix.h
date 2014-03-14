#ifndef _HASH_MAP_MATRIX_
#define _HASH_MAP_MATRIX_

#include <map>
#include "MatrixEngine.h"

// classe qui utilise une liste de clée-valeurs. une clée est une struct MatCell(x, y), la valeur est la case de la matrice
template <typename T>
class HashMapMatrix : public MatrixEngine<T>
{
private:
	// la structure permet d'écrire rapidement une coordonné x,y
	struct MatCell
	{
		unsigned int x;
		unsigned int y;
		MatCell(unsigned int x, unsigned int y) : x(x), y(y) {};
	};
	// cette classe permet de comparer deux coordonnés,
	// true si a doit etre avant b
	// false si b doit etre avant a
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
	unsigned int width;
	unsigned int height;
public:
	
	// récupère la case à l'indexe x, y
	// renvoit 0 si vide ou hors limite
	T get(unsigned int x, unsigned int y)
	{
		return _matrix[MatCell(x, y)];
	};

	// défini la case à l'index x, y à la valeur v
	// agrandit la taille stocké si l'index est plus grand (extensible)
	void set(unsigned int x, unsigned int y, T v)
	{
		if(x > width)
			width = x;
		if(y > height)
			height = y;
		_matrix[MatCell(x, y)] = v;
	};

	unsigned int getWidth(){ return width; };
	unsigned int getHeight(){ return height; };

};

#endif
