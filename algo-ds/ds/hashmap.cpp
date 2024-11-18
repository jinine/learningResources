#include <iostream>
#include <unordered_map>
using namespace std;
int main(){
    

    unordered_map<string, int> hashmap;

    hashmap["item 1"] = 10;
    hashmap["item 2"] = 20;
    hashmap["item 3"] = 30;


    for(auto it : hashmap)
        cout << it.first << ' ' << it.second << endl;
    return 0;
}