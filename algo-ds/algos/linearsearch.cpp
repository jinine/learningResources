#include <string>
#include <iostream>

std::string search(int arr[], int length, int search){

    for(int i = 0; i < length; i++){
        if(arr[i] == search){ 
            return "Found";
        }
    }

    return "Not Found";
}


int main(){
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int length = sizeof(arr) / sizeof(arr[0]);
    //check item in list 
    std::cout << search(arr, length, 4) << '\n';
    //check item outside of list 
    std::cout << search(arr, length, 11) << '\n';
    return 0;
}