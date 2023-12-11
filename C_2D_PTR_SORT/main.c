#include <stdio.h>
#include <stdlib.h>
#include "comparators.h"

int main() {
    int width,height, op;
    printf("Enter width and height: ");
    int res=scanf("%d %d", &width, &height);
    if(res!=2){
        printf("Incorrect input");
        return 1;
    }
    if(width<1 || height<1){
        printf("Incorrect input data");
        return 2;
    }
    int **tab=calloc(height, sizeof(int*));
    if(tab==NULL){
        printf("Failed to allocate memory");
        return 8;
    }
    for(int i=0; i<height; i++){
        *(tab+i)=calloc(width, sizeof(int));
        if(*(tab+i)==NULL){
            for(int y=0; y<i; y++){
                free(*(tab+y));
            }
            free(tab);
            printf("Failed to allocate memory");
            return 8;
        }
    }
    printf("Enter data: ");
    for(int i=0; i<height; i++){
        for(int y=0; y<width; y++){
            res=scanf("%d", (*(tab+i)+y));
            if(res!=1){
                printf("Incorrect input");
                delete_tab(tab, height);
                return 1;
            }
        }
    }
    printf("Selection choice: ");
    res=scanf("%d", &op);
    if(res!=1){
        delete_tab(tab, height);
        printf("Incorrect input");
        return 1;
    }
    if(!(op==0 || op==1 || op==2)){
        delete_tab(tab,height);
        printf("Incorrect input data");
        return 2;
    }
    switch (op) {
        case 0:
            sort_rows(tab, width, height, comp_min);
            break;
        case 1:
            sort_rows(tab, width, height, comp_max);
            break;
        case 2:
            sort_rows(tab, width, height, comp_sum);
            break;
    }
    for(int i=0; i<height; i++){
        for(int y=0; y<width; y++){
            printf("%d ", *(*(tab+i)+y));
        }
        printf("\n");
    }
    delete_tab(tab, height);
    return 0;
}
