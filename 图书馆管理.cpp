#include <iostream>
#include <string>
#include <fstream>
#include <vector>

class Book{				//类名开头大写
	public:
		std::string name{""};
		std::size_t num{};
		double price{};
	
		Book()=default;
		Book(const std::string& a,std::size_t b,double c):name(a),num(b),price(c){}		//对于 std::string，使用 const & 是绝对正确的，因为它体积大，避免复印能省内存。
//但是对于 std::size_t（本质是数字）和 double（本质是数字），它们的体积和“引用指针”一样小，甚至更小。对于这种基本数据类型，直接传值即可，不需要加 const &。
		Book(std::istream& in){
			while(!(in>>name>>num>>price)){
				in.clear();
				in.ignore(10000,'\n');  
				std::cout<<"看清楚再输入，沙比\n";
			}
	
		}
};			//类定义后面一定有分号！！！！


class Library{
	private:
		std::vector<Book> lib{};
		std::string txt_name{"books.txt"};
		
		
		
		
	public:
	
		
		void display(){
			for(const auto& bk:lib){
			std::cout<<bk.name<<' '<<bk.num<<' '<<bk.price<<'\n';
			}
			std::cout<<lib.size();	
		}
		
		void search(const std::string& name){
			std::size_t number{};
			for(const auto& bk:lib){
			++number;		//统计在vector序列里的标号
			if(name==bk.name)
			std::cout<<bk.name<<' '<<bk.num<<' '<<bk.price<<' '<<number-1<<'\n';
			
			}	
		}
		
		void add(const Book& bk){
			lib.push_back(bk);
			std::ofstream ofe{txt_name,std::ios::app};
			ofe<<bk.name<<' '<<bk.num<<' '<<bk.price<<'\n';
		}
		
		
		
		
		void del(const std::string& name ){
			std::vector<Book>::iterator p_b{lib.begin()},p_e{lib.end()};
			while(p_b!=p_e){
				if(p_b->name==name){
					lib.erase(p_b);
					break;
				}
				++p_b;
			}
			std::ofstream of{txt_name};
			for(auto& bk:lib){
			
			of<<bk.name<<' '<<bk.num<<' '<<bk.price<<'\n';
			
			
			
			}
		}
	
		Library(const std::string& txtn):txt_name(txtn){
			std::ifstream ifn{txt_name};
			if(!ifn){
				std::cerr<<"没打开蠢猪";
				throw std::runtime_error("文件打开失败");		//标准的 C++ 异常处理机制
			}
			Book temp{};
			while(ifn>>temp.name>>temp.num>>temp.price)
				lib.push_back(temp);
	
		}
	
};






int main(){
	
	std::cout<<"输入文件名\n";
	std::string name{};
	std::cin>>name;
	Library lib_1{name};
	
	while(true){
	
	std::cout<<"选择功能：1.展示书籍   2.搜索   3.加书    4.删书    5.退出\n";
	
	int choice{};
	while(!(std::cin>>choice)){			//输入检测
	
		std::cin.clear();
		std::cin.ignore(10000,'\n');  
		std::cerr<<"fku\n";
	}
	
	
	
	switch(choice){
		
		
	case 1:	{
		
		lib_1.display();
		break;
	}


	case 2:{
		
	
		std::cout<<"输入书名\n";
		std::string name{};
		std::cin>>name;
		lib_1.search(name);
		break;
	}
	
	case 3:{
		
			//append追加模式
		std::cout<<"按顺序输入书名，数量，价格\n";
		Book bk(std::cin);
		lib_1.add(bk);
		
		break;
	}
	
	case 4:{
		
		
		std::cout<<"删除哪一本书\n";
		std::string temp{};
		std::cin>>temp;	
		lib_1.del(temp);
		
		
		
		break;
	}
	default:{

		return 0;
	}
		
	}
}

}







































