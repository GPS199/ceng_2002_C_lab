#include <stdio.h>
#include "precision.h"
#include <math.h>

void reverse_arr(int arr[],int size){
    int j = 0;
    int temp;
    for(j=0;j<((size)/2)+1;j++){
        temp = arr[j];
        arr[j] = arr[(size)-j];
        arr[(size)-j] = temp;
    }
}

void scanHighPrec(high_prec_t* h){
    float number;
    int decptt=0;
    int real,temp_real,remaining,new_real,j ;
    int i = 0;
    int remains[10];
    printf("Enter your number:");
    scanf("%f",&number);
        if(number<0){
            h->sign = -1;
            number *= -1;
        }
        else{
            h->sign = 1;
        }
        real = floor(number);
        temp_real = real;
        while(real>10){
            remaining = real % 10;
            real = real/10;
            remains[i] = remaining;
            i++;
        }
        remains[i] = real;
        real = temp_real;
        reverse_arr(remains,i);
        for(j=0;j<i+1;j++){
            h->digits[j] = remains[j];
        }
        real = (float)real;
        number-=real;
        if(real>=1){
            if(real<10){
                h->decpt = 1;
                new_real = number*10;

                for(j;j<20;j++){

                    printf("h->digits[%d]=%d\n",j,new_real);
                    h->digits[j] = new_real;
                    new_real = floor(number);
                    number -= new_real;
                    number *=10;
                }
                        }
            else{
                 decptt=1;
                 while(real>=10){
                    decptt++;
                    real = real/10;

                                }
                h->decpt = decptt;
                number*=10;
                for(j=j;j<20;j++){
                    new_real = floor(number);
                    h->digits[j] = new_real;
                    number -= new_real;
                    number *=10;
                }

            }

        }
        else{
            while(number<=1){
                    number *= 10;
                    decptt--;
            }
            j++;
            h->decpt = decptt+1;
            for(j=j;j<20;j++){
            new_real = floor(number);
            h->digits[j] = new_real;
            number -= new_real;
            number *=10;
            }

        }

}

void printHighPrec(high_prec_t h){
    int i;
    printf("Digits:  ");
    for(i=0;i<20;i++){
        printf("%d,",h.digits[i]);
    }
    printf("\n.decpt:%d",h.decpt);
    printf("\n.sign:%d",h.sign);

}

