#include <string>
#include <iostream>

using namespace std;

template<typename AnyType>
void swap(AnyType, AnyType);

template<> void swap<string>(string str1, string str2);

template void swap<int>(int, int);



template<typename AnyType>
void swap(AnyType var1, AnyType var2) {
    AnyType temp = var1;
    var1 = var2;
    var2 = temp;
}


template<> void swap<string>(string str1, string str2) {
    string temp = str1;
    str1 = str2;
    str2 = str1;
    cout << "This is explicit specialization for string type" << endl;
}
