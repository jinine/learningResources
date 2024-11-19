#include <iostream>

using namespace std;

template<typename T>
void Print(T value){
    std::cout << value << std::endl;
}

int main(){
    Print(5);
    Print(5.5f);
    Print("Hello");

    return 0;
}