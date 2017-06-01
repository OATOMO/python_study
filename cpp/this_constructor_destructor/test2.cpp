#include "iostream"
using std::cout;
using std::endl;

template <typename T>
T max(T x,T y){
return (x>y)?x:y;
}

template <typename T1,typename T2> class A{
	T1 x;
	T2 y;
public:
	A(T1 x,T2 y):x(x),y(y){};
	void show(void){
	cout << x <<endl;
	cout << y <<endl;
	};
};

int main(int argc,char ** argv){
	char c1 = 'a',c2 = 'b';
	int x1 = 10,x2 = 5;
	//cout << max(c2,c1) << endl;
	//cout << max(x1,x2) << endl;
	A<int,char>  a('a','a');
	a.show();
return 0;
}
