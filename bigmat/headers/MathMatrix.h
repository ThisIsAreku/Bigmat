#ifndef _MATH_MATRIX_H_
#define _MATH_MATRIX_H_

#include "MatrixEngine.h"

// false : permet l'ajout de matrices de différentes tailles
static bool secured = true;

template <typename K, typename S>
MatrixEngine<K> &operator +=(MatrixEngine<K>& a, MatrixEngine<S>& b){
	if(secured && (a.getWidth() != b.getWidth() || a.getHeight() != b.getHeight()))
		return a;

	unsigned int maxWidth = a.getWidth();
	unsigned int maxHeight = a.getHeight();

	if(!secured){
		if(b.getWidth() > maxWidth)
			maxWidth = b.getWidth();
		if(b.getHeight() > maxHeight)
			maxHeight = b.getHeight();
	}

	for(unsigned int i = 0; i < maxWidth; i++)
		for(unsigned int j = 0; j < maxHeight; j++)
			a.set(i, j, a.get(i, j)+b.get(i, j));
	return a;
}
#endif
