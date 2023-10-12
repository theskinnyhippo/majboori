#include <stdio.h>
#include <stdlib.h>

void conquer(int* a, int i, int mid, int j){
    int* merged = (int*)malloc(sizeof(int) * (j - i + 1));
    int ind1 = i;
    int ind2 = mid + 1;
    int x = 0, y = i;

    while(ind1 <= mid && ind2 <= j){
        if(a[ind1] <= a[ind2]){
            merged[x++] = a[ind1++];
        }else{
            merged[x++] = a[ind2++];
        }
    }
    while(ind1 <= mid){
        merged[x++] = a[ind1++];
    }
    while(ind2 <= j){
        merged[x++] = a[ind2++];
    }

    for(x = 0, y = i; x < (j-i+1); x++, y++){
        a[y] = merged[x];
    }

    free(merged);
}

void divide(int* a, int i, int j){
    if(i < j){
        int mid = i + (j-i)/2;

        divide(a, i, mid);
        divide(a, mid + 1, j);

        conquer(a, i, mid, j);
    }
}

void print(int* a, int n){
    for (int i = 0; i < n; i++){
        printf("%d ", a[i]);
    }
    printf("\n");
}

int main(){
    int n, i;
    printf("Enter size of array : ");
    scanf("%d", &n);
    int* m = (int*)malloc(sizeof(int) * n);

    printf("Enter data...\n");
    for(i = 0; i < n; i++){
        scanf("%d", m + i);
    }

    printf("Original array...\n");
    print(m, n);

    divide(m, 0, n - 1);

    printf("Sorted array...\n");
    print(m, n);

    free(m);

    return 0;
}
