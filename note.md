# 异常机制
catch()捕捉异常之后，catch块之后的代码仍然会执行
catch捕获只有类型const char*、没有变量str，也可以进入catch内执行代码
```C++
int main() {
    int main() {
    try {
        throw "error happened";
    }
    catch (const char* str) {
        std::cout << str << std::endl;
    }
    std::cout << "after catch block" << std::endl;
}
}
```

# 多线程
句柄地址(稳定)→记载着对象在内存中的地址→对象在内存中的地址(不稳定)→实际对象。

main函数结束，即主线程结束时会调用exit(),因此会终止其他子线程。
但是jthread创建的线程并不会被终止

