#include <iostream>

#define LENGTH(arr) (sizeof(arr) / sizeof((arr)[0]))

int* mergesort(int arr[]){
    if(LENGTH(arr) <= 1)return arr;

    //divide into sublists 
    
    //recursively sort

    //merge

}

int main(){
    int arr[10] = {2, 6, 1, 7, 8, 34, 6, 1, 4, 3};
    std::cout << mergesort(arr);
    return 0;
}