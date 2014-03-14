#ifndef _MATRIX_ENGINE_
#define _MATRIX_ENGINE_

template <typename T>
class MatrixEngine
{
public:
	virtual ~MatrixEngine() =0;
	virtual T get(unsigned int, unsigned int) =0;
	virtual void set(unsigned int, unsigned int, T) =0;
};

#endif
