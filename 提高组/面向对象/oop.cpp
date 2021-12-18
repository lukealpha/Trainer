#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;
//访问属性 public private protected
class people{ //父类
    protected:
        string name; //成员变量
        int age;
        char sex;
    public:
        ~people(){ //析构函数
            //
        }
    
};
class student:public people{
    private:
        int math;
        int chinese;
};
class teacher:public people{
    private:
        string subject;
        int AoT;
};
class employee:public people{
    private:
        int pos;
        int wage;
        double salary;
};