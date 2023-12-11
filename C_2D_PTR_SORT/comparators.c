#include "comparators.h"
#include <stdio.h>
#include <stdlib.h>

int comp_min(const int *ptr1, const int *ptr2, int width){
    if(ptr1==NULL || ptr2==NULL || width<1) return 2;
    int min1=*ptr1, min2=*ptr2;
    for(int i=0; i<width; i++){
        if(*(ptr1+i)<min1) min1=*(ptr1+i);
        if(*(ptr2+i)<min2) min2=*(ptr2+i);
    }
    if(min1>min2) return 1;
    else if(min1<min2) return -1;
    return 0;
}
int comp_max(const int *ptr1, const int *ptr2, int width){
    if(ptr1==NULL || ptr2==NULL || width<1) return 2;
    int max1=*ptr1, max2=*ptr2;
    for(int i=0; i<width; i++){
        if(*(ptr1+i)>max1) max1=*(ptr1+i);
        if(*(ptr2+i)>max2) max2=*(ptr2+i);
    }
    if(max1>max2) return 1;
    else if(max1<max2) return -1;
    return 0;
}
int comp_sum(const int *ptr1, const int *ptr2, int width){
    if(ptr1==NULL || ptr2==NULL || width<1) return 2;
    int sum1=0, sum2=0;
    for(int i=0; i<width; i++){
        sum1+=*(ptr1+i);
        sum2+=*(ptr2+i);
    }
    if(sum1>sum2) return 1;
    else if(sum1<sum2) return -1;
    return 0;
}

int sort_rows(int** tab, int width, int height, int (*func)(const int*,const int*, int)){
    if(tab==NULL || width<1 || height<1 || func==NULL) return 1;
    int *hldr;
    for(int i=0; i<height-1; i++){
        for(int y=0; y<height-1; y++){
            if(func(*(tab+y), *(tab+y+1), width)>0){
                hldr=*(tab+y);
                *(tab+y)=*(tab+y+1);
                *(tab+y+1)=hldr;
            }
        }
    }
    return 0;
}

void delete_tab(int** tab, int height){
    for(int i=0; i<height; i++){
        free(*(tab+i));
    }
    free(tab);
}