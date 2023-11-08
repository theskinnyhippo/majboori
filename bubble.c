#include<iostream>
using namespace std;

void bubble_sort(int* k, int n){
    int greater;

    int sorted = 0;
    for(int j=1; j<n; j++){

        sorted = 1;     //let it is sorted already
        cout << "number of pass worked on : " << j << endl;
        for(int i=0; i<(n-j); i++){
            if(k[i]>k[i+1]){
                greater = k[i];
                k[i] = k[i+1];
                k[i+1] = greater;

                sorted = 0;     //if it doesnt go in the if condition, it is already sorted
            }else{
                continue;
            }
        }
        if(sorted == 1){
            return;
        }
    }
}

void print(int* k, int n){
    for(int i=0; i<n ; i++){
        cout << k[i] << " " ;
    } cout << endl;

}

int main(){
    int k[] = {1,2,3,4,5,0};
    int n = sizeof(k)/sizeof(k[0]);
    print(k, n);
    bubble_sort(k, n);
    
    
cout << endl << "sorted data..." << endl;
    print(k, n);

}
