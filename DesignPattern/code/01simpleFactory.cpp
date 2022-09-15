#include <iostream>
#include <string.h>
#include <string>
#include <algorithm>
#include <iterator>
#include <utility>
#include <functional>

template <class T>
T operation(std::pair<T, T> p, const char operate) {
    T n1 = p.first, n2 = p.second;
    switch (operate)
    {
    case '+':
        return n1 + n2;
        break;
    case '-':
        return n1 - n2;
        break;
    case '*':
        return n1 * n2;
        break;
    case '/':
        return n1 / n2;
        break;
    default:
        return 0;
        break;
    }
}

/*
增加新的运算功能要修改switch case的代码
*/


int main(int argc, char* argv[]) {
    //if (argc < 3) return 0;
    std::string str = "hello";
    const char* ch = str.c_str();
    char* chars = const_cast<char *>(ch);
    chars[3] = 'w';
    std::ostream_iterator<char, char> out_iter(std::cout, "");
    std::copy(str.cbegin(), str.cend(), out_iter);
    std::copy(str.crbegin(), str.crend(), std::ostreambuf_iterator<char>(std::cout));
    std::cout << std::endl << std::endl;
    char* operates = new char[7] {'+', '-', '*', '/', '+', '-', '*'};
    std::pair<int, int> pairs[4] = {{1, 2}, {3, 4}, {3, 6}, {8, 3}};
    int res[4];
    
    for (int i = 0; i < 4; i++) {
        std::transform(pairs, pairs+4, operates+i, res, operation<int>);
        std::copy(res, res+4, std::ostream_iterator<int, char>(std::cout, " "));
        std::cout << std::endl;
    }
    
    delete [] operates;
    return 0;
}