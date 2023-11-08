#include<iostream>
using namespace std;

void swap(int *a, int *b){
    int temp = *b;
    *b = *a;
    *a = temp;
}

void print(int* k, int n){
    for(int i=0; i<n ; i++){
        printf("%d ", *(k+i));
    } printf("\n");
}

int partition(int* k, int l, int h){
    int pivot = k[l];
    int i = l+1;
    int j = h;

    do{
        while(k[i] <= pivot){
            i++;
        }

        while(k[j] > pivot){
            
            j--;
        }
            
        if(i<j){
            swap(k[i], k[j]);            
        }
    }while(i < j);
            swap(k[l],k[j]);
        return j;
}

void quick_sort(int* k, int l, int h){
    int partition_index;    //index of pivot after partition

    if(l<h){
        partition_index = partition(k, l, h);
            quick_sort(k, l, (partition_index - 1));    //sort left subarray
            quick_sort(k, (partition_index + 1), h);    //sort right subarray
    }
}

int main(){
    int k[] = {1,2,3,4,5,7,6};
    int n = sizeof(k)/sizeof(k[0]);
    print(k, n);
    quick_sort(k, 0, n-1);
        
    cout << endl << "sorted data..." << endl;
    print(k, n);
}
