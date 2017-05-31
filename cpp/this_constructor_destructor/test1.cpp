#include <iostream>
using namespace std;

class A{
	int& x;
   	int y;
public:
	A(int x = 0 ,int y = 0):x(x),y(y) //改为x(*(new int(x)))就好了
	{}
	int& getX(){
		return x;
	}
};

int main(){
	A a(200,1); //x引用了临时变量
	cout << a.getX() << endl;
	cout << a.getX() << endl; //第二次调用临时变量就没了
}
