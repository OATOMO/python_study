#--------------------------------------------
1.c++之建议:
    1.1尽量少使用宏:
        使用enum去代替多个常量
        使用const去代替一个常量
        使用inline代替带参宏
    1.2使用namespace避免命名冲突
    1.3使用泛型和模板去刻画一组逻辑或类型
    1.4变量随时用随时定义,以保证初始化
    1.5少用malloc free,应为new delete做的更好
    1.6字符串用string来代替
#--------------------------------------------
2.引用类型的成员 --不要返回局部变量的引用 test1.cpp
#--------------------------------------------
3.this指针
    3.1概念
    ->指向当前对象的指针
    ->在构造函数中,这个指针代表正在被构造对象的地址
    ->在成员函数中这个指针指向正在调用这个函数的对象的地址
    3.2 应用
    ->可以区分函数的参数和成员变量重名的问题
    ->作为函数的参数 或者参数的值相关
    ->作为函数的返回值或者返回值相关
#--------------------------------------------
4.template模板
    4.1 template有两种形式
    ->函数模板针对仅 参数 类型不同的函数
    ->类模板针对仅 数据成员 和 成员函数类型 不同的类 
    ***模板的声明或定义只能在全局，命名空间或类范围内进行，不能在局部范围内
    4.2 函数模板通用形式：
        template <class 形参名，class形参名,...>返回类型 函数名(参数列表){
                函数体
                }


