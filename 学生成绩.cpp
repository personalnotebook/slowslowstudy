#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>

class Student {
public:
    std::string id{""};     // 学号
    std::string name{""};   // 姓名
    double math{};          // 数学成绩
    double english{};       // 英语成绩
    double cpp{};           // C++成绩

    // 【任务 1】：写一个默认构造函数
	Student()=default;

    // 【任务 2】：写一个带参数的构造函数（接收学号、姓名和三科成绩）
    Student(const std::string& con_id,const std::string& con_name,double con_math,double con_eng,double con_cpp):id(con_id),name(con_name),math(con_math),english(con_eng),cpp(con_cpp){}

    // 【任务 3】：写一个可以从 std::istream (比如 cin 或 ifstream) 自动读取数据的构造函数
    Student(std::istream& in){
    	if(!(in>>id>>name>>math>>english>>cpp)){
			in.clear();
			in.ignore(10000,'\n');  
		
		}
		
	}
    friend std::istream& operator>>(std::istream& in,Student& s){		//友元函数，符号重载
    	in>>s.id>>s.name>>s.math>>s.english>>s.cpp;
    	return in;
	}

    // 【任务 4】：写一个计算并返回总分的函数
    // 注意：因为计算总分不会修改学生的信息，记得在函数名后面加上 const！
    double get_total() const {
        return math+english+cpp;
    }

    // 【任务 5】：写一个计算并返回平均分的函数
    double get_average() const {
        return (math+english+cpp)/3;
    }
};


bool compare_stu(const Student& s_1,const Student& s_2){
	
	if(s_1.get_total()!=s_2.get_total())
		return s_1.get_total()>s_2.get_total();
	
	if(s_1.math!=s_2.math)
		return s_1.math>s_2.math;
	return false;
}


class School{
	public:
	std::vector<Student> sch{};
	std::string sch_name{};
	
	School(std::string& s):sch_name(s){
	
		std::ifstream ifs{sch_name};
		Student temp{};
		while(ifs>>temp){
			
			sch.push_back(temp);
		}
	}
	
	void display(){
		std::cout << "--- 录入顺序（未排序） ---" << '\n';
    	for (const auto& s : sch) {
        	std::cout << "姓名: " << s.name 
                  << " | 总分: " << s.get_total() 
                  << " | 数学: " << s.math << '\n';
    	}
	}
	
	void stu_sort(){
		std::sort(sch.begin(),sch.end(),compare_stu);
		std::cout << "\n--- 最终成绩单（已排序） ---" << '\n';
    int rank = 1;
    for (const auto& s : sch) {
        std::cout << "第 " << rank++ << " 名 | " 
                  << "姓名: " << s.name 
                  << " | 总分: " << s.get_total() 
                  << " | 数学: " << s.math << '\n';
    }

		
	}
	
	
	
	
};
	
	
	int main() {
		std::cout<<"输入来源\n";
		std::string sname;
		std::cin>>sname;
		
   School class_list(sname);
    // 3. 排序前，打印一下乱序的名单
    class_list.display();
   class_list.stu_sort();
    // ==========================================
    // 4. 见证奇迹的时刻：呼叫 C++ 的排序神器！
    // 告诉它：从头排到尾，比较规则听 compare_stu 的。
    // ==========================================
    

    // 5. 排序后，打印最终成绩单
    
    return 0;
}
	
	
	
	
	
	
	
	
