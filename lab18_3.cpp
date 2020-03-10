#include<iostream>
#include<string>
#include<fstream>
#include<vector>
#include<cstdlib>
#include<iomanip>

using namespace std;

struct student{
	//Define struct student with four member (name ,id , gender, gpa);
	string name;
	 int id;
	string gender;
	double gpa;
};

struct course{
	string name;
	int id;
	vector<string> lecture_list;
	vector<student *> student_list;
};

student * findstudent(vector<student> &allstudents,int key){ //Correct this line
	for(unsigned int i = 0; i < allstudents.size(); i++){
		if(allstudents[i].id  == key) return &allstudents[i];
	}
}

void printreport(vector<course> allcourses){
	for(unsigned int i = 0;i < allcourses.size(); i++){
		cout << "-----------------------------------------------------------------------------\n";
		cout << "Course:\t\t" << allcourses[i].name << " ("<< allcourses[i].id << ")\n\n";
		cout << "Lecturers:\t";
		for(unsigned int j = 0; j < allcourses[i].lecture_list.size();j++){
			if(j != 0) cout << ", ";
			cout << allcourses[i].lecture_list[j];
		} 
		cout << "\n\nStudents:\t";
		for(unsigned int j = 0; j < allcourses[i].student_list.size();j++){
			if(j != 0) cout << "\t\t";
			cout << setw(20) << left << allcourses[i].student_list[j]->name << "\t\t";
			cout << allcourses[i].student_list[j]->id << "\t";
			cout << allcourses[i].student_list[j]->gender << "\t";
			cout << allcourses[i].student_list[j]->gpa << "\n";
		} 
		
	}
	cout << "-----------------------------------------------------------------------------\n";
}

int main(){
	ifstream student_file("students.txt");
	ifstream course_file("courses.txt");
	vector<student> allstudents;
	vector<course> allcourses;
	
	string textline;
	
	while(getline(student_file,textline)){
		student s; 
		string n,g,i,d;
		//Assign value to the members of struct s;
		int loc=textline.find_first_of(",",0);
		s.name=textline.substr(0,loc);
		string w=textline.substr(loc+1,4);
		s.id=atoi(w.c_str());
		s.gender=textline.substr(loc+6,1);
		string p=textline.substr(loc+8,4);
		s.gpa=atof(p.c_str());
	
		
		allstudents.push_back(s); 		
	}
	
	int state = 1,m=0;
	while(getline(course_file,textline)){
		if(state == 1){
			course c;
			int loc = textline.find_first_of('(');
			c.name = textline.substr(0,loc-1);
			c.id = atof(textline.substr(loc+1,5).c_str());
			getline(course_file,textline);
			allcourses.push_back(c);
			state = 2;			
		}else if(state == 2){
			if(textline == "> Students"){
				state = 3;
			}else{
				//Append lecture_list;
				allcourses[m].lecture_list.push_back(textline);
				
			}			
		}else{
			if(textline == "---------------------------------------"){
				state = 1;m++;
			}else{
				student *p = findstudent(allstudents,atoi(textline.c_str()));
				//Append student_list;
				
				allcourses[m].student_list.push_back(p);
			}
		}
	}
	printreport(allcourses);
	
}
