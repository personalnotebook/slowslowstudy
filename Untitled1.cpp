/* #include <iostream>
using namespace std;
int main(){
	while(true){
	
	int a=0;
	cout<<"1.C>F   2.M>YC   3.exit\n";
	cin>>a;
	if (a==1){

	double b=0.0;
	cout<<"shuru\n";
	cin>>b;
	b=1.8*b+32;                //魔法数字，别人不知道1.8和32是什么。
    cout<<b<<endl;
   }else if(a==2){
			double c=0.0;
			cout<<"shuru\n";
	        cin>>c;
	        c=3.28084*c;         //魔法数字
            cout<<c<<'\n';
		}else if(a==3)
		break;
		
	}
	
return 0;	
}
*/

#include <iostream>
#include <limits>
#include <string>

constexpr double Celsius_to_Fahrenheit(double celsius){    //c++对constexpr函数和constexpr变量要求不同
	return celsius*1.8+32.0;
}

constexpr double meters_to_feet(double meters){
	return meters*3.28084;
}

double get_safe_input(const std::string& prompt ){
	while(true){
		double value=0.0;
		std::cout<<prompt;
			if(std::cin>>value)
			return value;           //if里有return、break 或 continue 时，坚决不写 else
			                  
				std::cin.clear() ;
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
				std::cout<<"alaw number";
			
	}
}
int main(){
	while(true){
		std::cout<<"1.Celsius>F   2.M>feets   3.exit\n";
		int choice=0;
		if(!(std::cin>>choice)){
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout<<"again\n";  
			continue;
		}
		
	switch(choice){
		case 1:{
			
			std::cout<<Celsius_to_Fahrenheit(get_safe_input("celsius" ));
			break;
		}
		case 2:{
			std::cout<<meters_to_feet(get_safe_input("meters"));
			break;
		}
		case 3:{
			std::cout<<"exit";
			return 0;
		}
		default:{
			std::cout<<"fku\n";
			break;
		}
	
	}	
		
		
		
		
		
	}
}	






























