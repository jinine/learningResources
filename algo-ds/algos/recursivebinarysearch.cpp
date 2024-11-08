#include <string>
#include <iostream>
#include <cmath>

std::string binary_search(int sorted_arr[], int low, int high, int search){
    if(low > high) return "Not Found";
    int mid = low + (high - low) / 2;
    if(sorted_arr[mid] == search) return "Found";
    if(sorted_arr[mid] < search) return binary_search(sorted_arr, mid + 1, high, search);
    else return binary_search(sorted_arr, low, mid - 1, search);
}

int main(){
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    //search for item inside array
    int x = 5;
    int n = sizeof(arr) / sizeof(arr[0]);
    std::cout << binary_search(arr, 0, n - 1, x) << '\n';
    //search for item outside of array
    int y = 12;
    int m = sizeof(arr) / sizeof(arr[0]);
    std::cout << binary_search(arr, 0, m - 1, y) << '\n';
    return 0;
}