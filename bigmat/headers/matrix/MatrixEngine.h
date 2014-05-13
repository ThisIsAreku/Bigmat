#ifndef _MATRIX_ENGINE_
#define _MATRIX_ENGINE_

template <typename T>

/**
   * \file MatrixEngine.h
   * \author ABNP
   * \date 13 Mai 2014
*/

class MatrixEngine
{
public:
    virtual T get(unsigned int, unsigned int) = 0;
    virtual void set(unsigned int, unsigned int, T) = 0;

    virtual unsigned int getWidth() = 0;
    virtual unsigned int getHeight() = 0;

    virtual void setWidth(unsigned int) = 0;
    virtual void setHeight(unsigned int) = 0;
};

#endif
