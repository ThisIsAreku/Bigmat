#ifndef _MATH_MATRIX_H_
#define _MATH_MATRIX_H_

#include "matrix/MatrixEngine.h"

class MathMatrix;

// false : permet l'ajout de matrices de différentes tailles
static bool secured = true;

MatrixEngine<bool> &operator +=(MatrixEngine<bool> &a, MatrixEngine<bool> &b)
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

MatrixEngine<bool> &operator -=(MatrixEngine<bool> &a, MatrixEngine<bool> &b)
{
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


MatrixEngine<bool> &operator *=(MatrixEngine<bool> &a, MatrixEngine<bool> &b){
    unsigned int maxWidth = b.getWidth();
    unsigned int maxHeight = a.getHeight();
    
    a.setHeight(maxHeight);
    a.setWidth(maxWidth);
    
    K tmp =0;
    K value = 0;
    
    for(unsigned int i = 0; i < maxHeight; i++){
        for(unsigned int j = 0; j < maxWidth; j++){
            for(unsigned int k = 0; k < maxHeight; k++){
                tmp = a.get(k,i) + b.get(j,k);
                value += tmp;
            }
            a.set(i,j,value);
            value = 0;
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
    
    for(unsigned int i = 0; i < maxHeight; i++){
        for(unsigned int j = 0; j < maxWidth; j++){
            for(unsigned int k = 0; k < maxHeight; k++){
                tmp = a.get(k,i) + b.get(j,k);
                value += tmp;
            }
            a.set(i,j,value);
            value = 0;
        }
    }
    return a;
}

MatrixEngine<bool> &operator /=(MatrixEngine<bool> &a, MatrixEngine<bool> &b){
    unsigned int maxWidth = b.getWidth();
    unsigned int maxHeight = a.getHeight();
    
    b = MathMatrix::inversion(b);
    
    a *= b;
    
    return a;
}

template <typename K>
MatrixEngine<K> &operator /=(MatrixEngine<K> &a, MatrixEngine<K> &b){
    unsigned int maxWidth = b.getWidth();
    unsigned int maxHeight = a.getHeight();
    
    b = MathMatrix::inversion(b);
    
    a *= b;
    
    return a;
}

class MathMatrix{
public:
   
    template <typename K>
    static MatrixEngine<K> inversion(MatrixEngine<K> &a){
        
        int det = det(a);
        
        aPrime = complementAlgebrique(a);
        aPrimeTrans = transpose(aPrime);
        a = aTrans *= (1/det);
        
        return a;
    }
    
    template <typename K>
    static MatrixEngine<K> inversion(MatrixEngine<K> &a){
        
        int det = det(a);
        
        aPrime =
        aPrimeTrans = transpose(aPrime);
        a = aTrans *= (1/det);
        
        return a;
    }
    
    template <typename K>
    MatrixEngine<k> complementAlgebrique(MatrixEngine<K> &a){
        
        
        return a;
    }
    
    template <typename K>
    MatrixEngine<k> transpose(MatrixEngine<K> &a){
        
        
        
        return a;
    }
    
    /*
     
     La matrice doit etre carré et triangulaire
     
     
    */
    
    template <typename K>
    int det(MatrixEngine<K> &a){
        int det = a[0,0];
        
        if(a.getHeight ==  a.getWidth){
            for(int i =1; i < a.getWidth; i++){
                det *= a[i,i];
            }
        }
        
        return det;
    }

};

#endif
