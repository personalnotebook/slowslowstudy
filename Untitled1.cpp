#include <iostream>
#include <stack>

int main(){
	std::stack<char> s{};
	char temp{};
	while(std::cin>>temp){
		if(temp=='('||temp=='['||temp=='{')
		s.push(temp);
		else if(!s.empty()){
			switch(temp){
			
				case ')':{
					if(s.top()=='(')
					{
					s.pop();
				break;}
				return 1;
				}
				case ']':{
					if(s.top()=='[')
					{
					s.pop();
				break;}
				return 1;
				}
				case '}':{
					if(s.top()=='{')
					{
					s.pop();
					break;}
					return 1;
				}
				default:
					return 1;
	}
		
	}else
	return 1;

	}

	
	
	if(s.empty())
	return 0;
	return 1;
	
}

	
	
	
	