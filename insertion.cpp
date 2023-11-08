#include<iostream>
using namespace std;

void insertion_sort(int* k, int n){
    int c = 1;
    for(int i=1; i<n; i++){
        int key = k[i];
        int j = i-1; 
        while(j>=0 && k[j] > key){
            cout << endl << "count of shiftings/swaps : " << c << endl;
            k[j+1] = k[j];
            j--;
            c++;
        }    
        k[j+1] = key;
    }
}

void print(int* k, int n){
    for(int i=0; i<n ; i++){
        cout << k[i] << " " ;
    } cout << endl;

}

int main(){
    int k[] = {9,8,7,6,5,4};
    int n = sizeof(k)/sizeof(k[0]);
    print(k, n);
    insertion_sort(k, n);
    
    
    cout << endl << "sorted data..." << endl;
    print(k, n);

}
