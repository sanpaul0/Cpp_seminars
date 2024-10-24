#include <iostream>

using namespace std;

void fill_array(int *arr, int size){
    for (int i =0; i<size; i++){
        arr[i] = i;
    }
}

void print_array(int *arr, int size){
    for (int i=0; i<size; i++){
        cout << arr[i] << " ";
    }
}

int main(){
    int arrsize;
    cin >> arrsize;

    #define SIZE arrsize
    #define DINAMYC_MEMORY 1   // 1 если динамческий, если статический - любое другое 

    #if (DINAMYC_MEMORY == 1)
    arr = new int[SIZE]
    fill_array(arr, SIZE);
    print_array(arr, SIZE);
    delete[] arr;

    #else 
    int arr[SIZE];
    fill_array(arr, SIZE);
    print_array(arr, SIZE);
    #endif
}