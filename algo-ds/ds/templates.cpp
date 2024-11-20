#include <iostream>

using namespace std;

template<typename T>
void Print(T value){
    std::cout << value << std::endl;
}

template <typename T, int N>
class Array{
    private: 
        T m_Array[N];
    public:
        int GetSize() const {return N;}
};

int main(){
    Print(5);
    Print(5.5f);
    Print("Hello");


    Array<int, 5> array;
    std::cout << array.GetSize() << std:: endl;

    return 0;
}