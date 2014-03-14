#ifndef _MATH_MATRIX_H_
#define _MATH_MATRIX_H_

#include "MatrixEngine.h"

template <typename K, typename S>
MatrixEngine<K> &operator +=(MatrixEngine<K>& a, MatrixEngine<S>& b){
	if(a.getWidth() != b.getWidth() || a.getHeight() != b.getHeight())
		return a;
	for(unsigned int i = 0; i < a.getWidth(); i++)
		for(unsigned int j = 0; j < a.getHeight(); j++)
			a.set(i, j, a.get(i, j)+b.get(i, j));
	return a;
}
#endif
