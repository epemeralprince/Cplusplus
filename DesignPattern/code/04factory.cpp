#include <iostream>
#include <string.h>
#include <string>
#include <algorithm>
#include <iterator>
#include <utility>
#include <functional>

template <class T>
class compute {
public:
    virtual T calculate(T n1, T n2) = 0 const;
};

template <class T>
class add : public compute {
public:
    T calculate(T n1, T n2) const {
        return n1+n2;
    }
};

template <class T>
class sub : public compute {
public:
    T calculate(T n1, T n2) const {
        return n1-n2;
    }
};

/*
增加乘、除、取余等计算，只要继承compute类实现calculate方法即可，
不像01simpleFactory.cpp中增加功能要修改switch case的代码
*/