#ifndef _MATH_MATRIX_H_
#define _MATH_MATRIX_H_

#include "matrix/MatrixEngine.h"

// false : permet l'ajout de matrices de différentes tailles
static bool secured = true;

template <typename K>
MatrixEngine<K> &operator +=(MatrixEngine<K> &a, MatrixEngine<K> &b)
{
    if(secured && (a.getWidth() != b.getWidth() || a.getHeight() != b.getHeight())){
        return a;
    }

    unsigned int maxWidth = a.getWidth();
    unsigned int maxHeight = a.getHeight();

    if(!secured){
        if(b.getWidth() > maxWidth){
            maxWidth = b.getWidth();
        }
        if(b.getHeight() > maxHeight){
            maxHeight = b.getHeight();
        }
    }

    for(unsigned int i = 0; i < maxWidth; i++){
        for(unsigned int j = 0; j < maxHeight; j++){
            a.set(i, j, a.get(i, j) + b.get(i, j));
        }
    }
    return a;
}

template <typename K>
MatrixEngine<K> &operator -=(MatrixEngine<K> &a, MatrixEngine<K> &b)
{
    if(secured && (a.getWidth() != b.getWidth() || a.getHeight() != b.getHeight())){
        return a;
    }
    
    unsigned int maxWidth = a.getWidth();
    unsigned int maxHeight = a.getHeight();
    
    if(!secured){
        if(b.getWidth() > maxWidth){
            maxWidth = b.getWidth();
        }
        if(b.getHeight() > maxHeight){
            maxHeight = b.getHeight();
        }
    }
    
    for(unsigned int i = 0; i < maxWidth; i++){
        for(unsigned int j = 0; j < maxHeight; j++){
            a.set(i, j, a.get(i, j) - b.get(i, j));
        }
    }
    return a;
}

template <typename K>
MatrixEngine<K> &operator *=(MatrixEngine<K> &a, int number)
{
    if(secured && (a.getWidth() != b.getWidth() || a.getHeight() != b.getHeight())){
        return a;
    }
    
    unsigned int maxWidth = a.getWidth();
    unsigned int maxHeight = a.getHeight();
    
    if(!secured){
        if(b.getWidth() > maxWidth){
            maxWidth = b.getWidth();
        }
        if(b.getHeight() > maxHeight){
            maxHeight = b.getHeight();
        }
    }
    
    for(unsigned int i = 0; i < maxWidth; i++){
        for(unsigned int j = 0; j < maxHeight; j++){
            a.set(i, j, a.get(i, j) * number);
        }
    }
    return a;
}

template <typename K>
MatrixEngine<K> &operator *=(MatrixEngine<K> &a, MatrixEngine<K> &b){
    unsigned int maxWidth = b.getWidth();
    unsigned int maxHeight = a.getHeight();
    
    a.setHeight(maxHeight);
    a.setWidth(maxWidth);
    
    K tmp =0;
    K value = 0;
    
    for(unsigned int i = 0; j < maxHeight; i++;){
        for(unsigned int j = 0; i < maxWidth; j++){
            for(unsigned int k = 0; j < maxHeight; k++){
                tmp = a.get(k,i) + b.get(j,k);
                value += tmp;
            }
            a.set(i,j,value);
            value = 0;
        }
    }
    return a;
}



#endif
