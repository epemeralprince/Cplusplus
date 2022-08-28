


# 4 顶点缓存区和在现代OpenGL中画一个三角形
缓存区（**VRAM**，显存）和着色器
**缓存区**中存储数据，**着色器**代表某种处理缓存区的数据
嘿，***GPU***，你用某某**着色器**处理某某**缓存区**的数据<br>

创建缓存区
```c++
float positions[6] = {
    -0.5f, -0.5f,
     0.0f,  0.5f,
     0.5f, -0.5f,
};

unsigned int buffer;
glGenBuffer(1, &buffer);
// glGenBuffer返回值void，因此传入一个uint的地址，该uint代表生成的缓存区id
// opengl生成所有的东西都有一个唯一标识符，是一个整数，一般不是0，因为0通常是一种无效状态（缓存区和着色器也有唯一标识，方便使用）
glBindBuffer(GL_ARRAY_BUFFER, buffer);
// 选择（绑定）一个buffer，第一个参数是目标，说明我们的buffer是一个数组
// 第二个参数是要绑定缓存区的id

```
<br>两种方式提供数据给buffer
1、通常在创建缓存区，指定它的大小（上面的方法没有指定缓存区大小）
2、或者像下面这样，直接提供数据
```c++
flBufferData(GL_ARRAY_BUFFER, 6*size0f(float), positions, GL_static_DRAW);
// 第二个参数设置这个缓存区大小（byte）。因为positions在栈上创建的，所以可以直接sizeof（positions）获取positions大小
// 第三个参数一个data指针，数据将被复制到缓存区
// 第四个参数如何访问缓存区数据的方式，包括：STREAM/STATIC/DYNAMIC
/*
STREAM    数据修改一次，使用几次
STATIC    数据修改一次，使用数次
DYNAMIC   数据将被重复修改，，使用数次
*/
// 后面还有DRAW、READ、COPY
```
<br>绘制图形（DrawCall指令）
```c++
glDrawArrays(GL_TRIANGLES, 0, 3);  //不会绘制三角形，因为大约只渲染了30%
// 第一个参数绘制的模式
// 第二个参数数组的起始位置
// 第三个参数要渲染的索引数量

glDrawElements(GL_TRIANGLES, 3, )
// 第一个参数绘制的模式
// 第二个参数要渲染的索引数量
// 第三个参数是indices，我们几乎从不使用，通常填写null
```
