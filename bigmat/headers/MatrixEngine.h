#ifndef _MATRIX_ENGINE_
#define _MATRIX_ENGINE_

template <typename T>
class MatrixEngine
{
public:
	virtual ~MatrixEngine();
	virtual T get(unsigned int, unsigned int) =0;
	virtual void set(unsigned int, unsigned int, T) =0;

	virtual unsigned int getWidth() =0;
	virtual unsigned int getHeight() =0;
};

#endif
