#include <fstream>
#include <cstdlib>
#include <stdlib.h>
#include <iostream>
using namespace std;

//UserLogin class
class UserLogin{
    int i;
    string name;
    string username;
    string password;
    string testPassword[5]={"1234","5678","9101","2345","6789"};
    string testUsername[5]={"alimohammad","teohwj","diya","eunice","intan"};
    public: 
        UserLogin(){};
        UserLogin(string name, string username, string password){
            this->name=name;
            this->username=username;
            this->password=password;
            };
        string getName(){
            return name;
        }
        void setNamePw(string username,string password){
            this->username=username;
            this->password=password;
        }
        void verifyStudent(){
           for(i=0;i<5;i++){
                if(username==testUsername[i]&&password==testPassword[i]){
                    cout<<"Login Successfully!"<<endl;
                    system("CLS");
                    break;
                }
           }
           if(i==5){
               cout<<"Wrong username or password!"<<endl;
               exit(0);
           }    
        }
        void verifyLecturer(){
            if((username=="ismail")&&(password=="123456")){
                cout<<"Login Successfully!"<<endl;
                system("CLS");}
            else{
                cout<<"Wrong username or password!"<<endl;
                exit(0);
            }
        }
        void verifySupervisor(){
            if((username=="supervisor")&&(password=="7891011")){
                cout<<"Login Successfully!"<<endl;
                system("CLS");}
            else{
                cout<<"Wrong username or password!"<<endl;
                exit(0);
            }
        }
};

//Task class
class Task{
    string task;
    string date;
    int no;
    public:
        Task(){};
        Task(string task){
            this->task=task;
        };
		void setNo(int n){
			no=n;
		};
		
        void setTask(string t){
				task=t;
		};
		
		void setDate(string d){
			date=d;
		}
		
		int getNo(){
    		return no;
		};
		
        string getTask(){
			return task;
		};
		
		string getDate(){
			return date;
		};
};

//class Result
class Result{
    char grade;
    int total;
    public:
        Result(){};
        Result(char g){grade=g;};
        int calculateTotal(int marks[]){
            total = 0;
            for(int i=0;i<5;i++)
                total+=marks[i];
            total=total/5;
            return total;
        }
        void setResult(int marks[]){
            total = calculateTotal(marks);
            if(total>=80)   
                grade='A';
            else if(total>=65)
                grade='B';
            else if(total>=50)
                grade='C';
            else if(total>=40)
                grade='D';
            else
                grade='E';
        };
        char getResult(){
            return grade;
        }
};

//Student class (Compose with result but aggregate with tasks and child for userlogin)
class Student:public UserLogin{
    string name;
    string matricNo;
    int marks[5];
    int result;
    Result myresult;
    Task *mytask[5];
    Task task[5]={Task("1. Build Chatbot"),Task("2. Build Dashboard"),Task("3. Build Login Page"),Task("4. Build Material Page"),Task("5. Build Notification Page")};
    public:
        Student(){};
        Student(string mN){
            matricNo=mN;
        }
        string myTasks(int no){
            for(int i=0;i<5;i++)
                mytask[i]=&task[i];
                return mytask[no]->getTask();
        }
        void displayResult(int marks[][5],int pos){
            cout<<"----------------------RESULT SLIP-----------------------"<<endl
            <<left<<setw(12)<<"Name: "<<name<<endl
            <<left<<setw(12)<<"Matric.No: "<<matricNo<<endl
            <<left<<setw(50)<<"RESULT"<<"MARKS"<<endl;
            for(int i=0;i<5;i++){
                cout<<left<<setw(50)<<myTasks(i)<<marks[pos][i]<<endl;
            }
            cout<<endl;
            myresult.setResult(marks[pos]);
            cout<<"GRADE: "<< myresult.getResult()<<endl;
            cout<<"Press any key to continue...";
                cin.ignore();
                cin.get();
                system("CLS");
        }
        int myTotal(int marks[]){
            return myresult.calculateTotal(marks);
        }
        void displayDetail(){
            //my detail function
                cout<<"------------My Details------------"<<endl
                <<"Name: "<<name<<endl<<
                "Matric No: "<<matricNo
                <<endl<<"Company name: Company RedTech"
                <<endl<<"Job: Front-end app deeloper"
                <<endl<<"Lecturer: Dr Goh"<<endl<<endl;
                
        }
        void setMatricNo(string mN){
            matricNo=mN;
        }

        void setName(string n){
            name=n;
        }
        
        void setMarks(int m[]){
            for(int i=0;i<5;i++)
            {
                marks[i]=m[i];
            }
        }
        
        void setResults(int r){
            for(int i=0;i<5;i++)
            result=r;
        }
        
        int getResults(){
            return result;
        }

        string getMatricNo(){
            return matricNo;
        }

        string getName(){
            return name;
        }
        
};

//class Lecturer (Aggregate with student , task and child for user login)
class Lecturer :public UserLogin{
    string lectID;
    int number;
    Student *stu[5];
    Task *studtask[5];
    public:
        Lecturer(){};
        Lecturer(string lID){lectID=lID;};
        string getLectID(){return lectID;};
        void sortStudent(Student student[5],int marks[][5],int result[],int tempVar){
             cout<<left<<setw(15)<<"Matric.No"<<setw(20)<<"Name"<<right<<setw(10)<<"Task 1"<<setw(10)<<"Task 2"<<setw(10)<<"Task 3"<<setw(10)<<"Task 4"<<setw(10)<<"Task 5"<<setw(10)<<"Result"<<endl;
            for(int i=0;i<5;i++){
            for(int k=0;k<5;k++){
                stu[k]=&student[k];
            if(stu[k]->getResults()==result[i]){
                tempVar=k;
                stu[tempVar]=&student[tempVar];
            cout<<left<<setw(15)<<stu[tempVar]->getMatricNo();
             cout<<left<<setw(20)<<stu[tempVar]->getName();
            for(int j=0;j<5;j++)
            {
                cout<<right<<setw(10)<<marks[tempVar][j];
            }
            cout<<right<<setw(10)<<result[i]<<endl;
            }
            
    } }
    cout<<endl;
    };
        int* evaluate(Task task1[],Task task[],int temp,char want,bool sort,int m[]){
            int* marks=new int[5];
            marks=m;
            while(tolower(want) =='y'){
                cout<<"\nPlease select the task's number to evaluate: ";
                 cin>>number;
                 int t;
                if(sort){
                    studtask[number-1] = &task1[number-1];
                    cout<<number<<".\t"<<studtask[number-1]->getTask()<<endl;
                        for(int i=0;i<5;i++){
                         if(task1[number-1].getTask() == task[i].getTask()){
                          t=i;
                         break;
                         }}
                    cout<<"Mark given : ";
                     cin>>marks[t];//marks[1][2]
                    }
                else{
                    studtask[number-1] = &task[number-1];
                    cout<<number<<".\t"<<studtask[number-1]->getTask()<<endl;
                    cout<<"Mark given : ";
                    cin>>marks[number-1];
                }
                cout<<"\nDo you still want to continue? if yes press y.. ";
                cin>>want;
                system("CLS");
                }
                return marks;
                    }
};

