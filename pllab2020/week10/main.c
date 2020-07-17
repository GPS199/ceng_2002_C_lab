#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "precision.c"


int main()
{
high_prec_t *t = malloc(sizeof(high_prec_t));
high_prec_t test;
t = &test;
scanHighPrec(t);
printHighPrec(test);






}
