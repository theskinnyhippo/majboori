#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b){
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(int* arr, int n, int i){
    int largest = i;
    int l = 2*i + 1;
    int r = 2*i + 2;

    if (l < n && arr[l] > arr[largest]){
        largest = l;
    }

    if (r < n && arr[r] > arr[largest]){
        largest = r;
    }

    if (largest != i){
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapsort(int* a, int n){
    for(int i = n / 2 - 1; i >= 0; i--){
        heapify(a, n, i);
    }
    for(int i = n - 1; i > 0; i--){
        swap(&a[0], &a[i]);
        heapify(a, i, 0);
    }
}

void print(int* a, int n){
    for(int i = 0; i < n; i++){
        printf("%d ", a[i]);
    }
    printf("\n");
}

int main(){
    int n, i;
    printf("Enter size of array : ");
        scanf("%d", &n);
    int* m = (int*)malloc(sizeof(int)*n);
    
    printf("Enter data...\n");
    for(i=0; i<n; i++){
        scanf("%d", m+i);
    }

    printf("Original array...\n");
    print(m, n);

    heapsort(m, n);

    printf("Sorted array...\n");
    print(m, n);

    return 0;
}
