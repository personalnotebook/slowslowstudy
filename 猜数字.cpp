/*
#include <iostream>
#include <cstdlib>     #c语言里的头文件，c++不用这个了
#include <ctime>

using namespace std;
int main(){
	srand(time(0));        #系统时间作为随机种子
	
	int a=rand()%100+1;
	int b=0;
	cout<<"guess number"<<endl;     #endl有换行和立刻刷新缓冲区功能
	cin>>b;               #cin也会立刻刷新缓冲区
	while (b!=a)
	{
	if (b>a)
	cout<<"big"<<endl;
	else
	cout<<"small"<<endl;
	cin>>b;
	}
	cout<<"success."<<endl;
	
	return 0;
	
	
}
*/
#include <iostream>
#include <random>


using namespace std;
int main(){
	random_device rd;    //类型：std::random_device 类的实例（对象）。含义：它代表你电脑系统里的“硬件随机数生成设备”。
	mt19937 gen(rd());    //当你写 rd() 时，你并不是在调用一个名为 rd 的普通函数，而是在调用 rd 这个对象的 operator() 方法。它的动作是向硬件设备“抽取”一个真正的随机数，用来给后面的引擎当种子。
	                      //gen 类型：std::mt19937 类的实例（对象）。（mt19937 实际上是一个复杂的梅森旋转算法引擎模板类的类型别名）。含义：它是你的核心“伪随机数生成引擎”。它内部维护着当前随机序列的复杂状态。初始化 gen(rd())：这里不是函数调用，而是对象的构造函数。它接收刚才 rd() 抽出来的那个数字，作为自己运算的初始种子。
	uniform_int_distribution<> dist(1,100);   //类型：std::uniform_int_distribution<int> 类的实例（对象）。
	
	int a=dist(gen);    //这同样是调用了 dist 对象的 operator() 方法
	int b=0;
	cout<<"shuru\n";
	cin>>b;
	while(b!=a){
		if(b>a)
		cout<<"big\n";
		else
		cout<<"small\n";
		cin>>b;
	}
	cout<<"ok\n";
	return 0;
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
}
