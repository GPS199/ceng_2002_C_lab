#include <stdio.h>

void stoogeSort(int arr[],const int low, const int high)
    {
        void swap(int *p, int *k);
        if (low >= high){
            return;
        }



          if (arr[low] > arr[high]) {
              swap(&arr[low],&arr[high]);
          }

          if (high - low + 1 > 2) {
              int t = (high - low + 1) / 3;


              stoogeSort(arr, low, high - t);

              stoogeSort(arr, low + t, high);
              stoogeSort(arr, low, high - t);
          }


}



void printArray(const int arr[],const int size){
    for(int i=0;i<size;i++){
        printf("%d ",arr[i]);

    }


}

void swap(int *p, int *k){
    int a=*p;
    *p=*k;

    *k=a;
}


int main(void){
    int size;
    printf("enter the array size");

    scanf("%d",&size);
    int arr[size];


    printf("enter %d elements",size);

    for (int i=0; i<size; i++){
        scanf("%d",&arr[i]);


    }
    stoogeSort(arr, 0, 10);
    printf("Sorted array : \n");

    printArray(arr,10);

}
