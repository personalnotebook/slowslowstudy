#include <fstream>
#include <string>
#include <iostream>




int main(){
	std::ifstream file("test.txt");			//创建input file stream类型的变量
	if(!file ){					//检查是否成功打开
		std::cerr<<"没开\n";
		return 1;
	}
	bool now=false;
	char c{'\0'};
	std::size_t chars{0};		//size_t无符号长整型，很大防溢出
	std::size_t words{0};
	std::size_t lines{0};
	
	while(file.get(c)){
		++chars;
		if(c=='\n')
		++lines;
		if(std::isspace(static_cast<unsigned char>(c))){
			now=false;
			
		}else if(now==0){
		
		        words++;
		        now=true;
		        }
			
		                              
	}   
	if(chars>0&&c!='\n')
	++lines;
	std::cout<<chars<<'\n'<<words<<'\n'<<lines;

	return 0;	   
	
	
}
