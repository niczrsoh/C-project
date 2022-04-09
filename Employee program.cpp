//Name : Soh Zen Ren
//Matric No. : A20EC0152
//Lecturer name : Dr Mohd Razak bin Samingan 
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdlib>

using namespace std;
#define MAX 50 
int count =0;
struct Employee {
	string name;
	string department;
	int basic_salary;
	int number_of_overtime ;
	double overtime_pay;
	double total_salary;
};
int readInput(Employee []);
double determineRate(string str);
void displayOutput(Employee [],int );
void displayAnalysis(Employee [],int );
int main(){
	Employee e[MAX];
	int num;
	num= readInput(e);

	displayOutput(e,num);
	displayAnalysis(e,num );
	
	return 0;
} 
int readInput(Employee e[]){
	ifstream infile;
	infile.open("input.txt");
	char word[11];
	char secword[11];
	if(infile){
		while(infile>>word){
			e[count].department=word;
			infile>>word;
			e[count].basic_salary=atoi(word);
			infile>>word;
			e[count].number_of_overtime=atoi(word);
			infile>>word;
				e[count].name=e[count].name+word+" ";
				infile>>word;
			e[count].name=e[count].name+word;
			count++;
		}
	}else{
		cout<<"cannot open file";
	}
	infile.close();
	return count;
}
double determineRate(string str){
	double rate;
		if(str=="Quality"){
			rate=11.5;
		}else if(str=="Production"){
			rate=10.0;
		}else if(str=="Accounting"){
			rate=12.5;
		}else if(str=="Engineering"){
			rate=15.0;
		}
	return rate;	
}
void displayOutput(Employee e[],int num){
	for(int i=0;i<100;i++){
		cout<<"-";
	}
	cout<<endl;
	cout<<setw(20)<<left<<"NAME"<<setw(15)<<left<<"Department"<<setw(15)<<left<<"BASIC(RM)"<<setw(15)
	<<left<<"OT (HOUR)"<<setw(15)<<left<<"OT PAY(RM)"<<setw(15)<<left<<"SALARY(RM)"<<endl;
	for(int i=0;i<100;i++){
		cout<<"-";
	}
	cout<<endl;
	cout<<fixed<<showpoint<<setprecision(2);
	double rate[num];
	for(int i=0;i<num;i++){
		rate[i]=determineRate(e[i].department);
		e[i].overtime_pay=rate[i]*e[i].number_of_overtime;
		e[i].total_salary=e[i].basic_salary + e[i].overtime_pay;
	}
	for(int i=0;i<num;i++){
	cout<<setw(20)<<left<<e[i].name<<setw(15)<<left<<e[i].department<<setw(18)<<left<<(float)e[i].basic_salary<<setw(13)
	<<left<<e[i].number_of_overtime<<setw(15)<<left<<e[i].overtime_pay<<setw(18)<<left<<e[i].total_salary<<endl;
	}
	
}
void displayAnalysis(Employee e[],int num){
	for(int i=0;i<100;i++){
		cout<<"-";
	}
	string type[4]={"Production","Quality","Engineering","Accounting"};
	double total_pay[4]={0.0,0.0,0.0,0.0};
	double total_salary[4]={0.0,0.0,0.0,0.0};
	cout<<endl;
	cout << setw(30) << left << "DEPARTMENT" << setw(30) << left <<"TOT.OT PAY(RM)"<<setw(30)<<left<<"TOT. SALARY(RM)"<<endl;
	for(int i=0;i<num;i++){
		if(e[i].department=="Production"){
		   total_pay[0]+=e[i].overtime_pay;
		   total_salary[0]+=e[i].total_salary;
		}else if(e[i].department=="Quality"){
		    total_pay[1]+=e[i].overtime_pay;
		   total_salary[1]+=e[i].total_salary;
		}else if(e[i].department=="Engineering"){
			 total_pay[2]+=e[i].overtime_pay;
		   total_salary[2]+=e[i].total_salary;
		}else if(e[i].department=="Accounting"){
			 total_pay[3]+=e[i].overtime_pay;
		   total_salary[3]+=e[i].total_salary;
		}} 
	for(int i=0;i<num;i++){
	cout<<setw(31)<<left<<type[i]<<setw(31)<<left<<total_pay[i]<<setw(31)<<left<<total_salary[i]<<endl;
	}
		for(int i=0;i<100;i++){
		cout<<"-";
	}
	
}
