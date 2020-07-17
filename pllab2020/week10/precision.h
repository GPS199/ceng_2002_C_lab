//#ifndef PRECISION_H_INCLUDED
//#define PRECISION_H_INCLUDED

typedef struct{
    int digits[20];
    int decpt;
    int sign;
}high_prec_t;

extern void scanHighPrec(high_prec_t* h);  /* store the given number as high precision number */


extern void printHighPrec(high_prec_t h); /* print number as high precision number */




//#endif // PRECISION_H_INCLUDED
