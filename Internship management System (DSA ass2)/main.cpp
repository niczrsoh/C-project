/*
    Assignment 1
    Name: Soh Zen Ren 	(A20EC0152)
    Name: Wong Hui Shi 	(A20EC0169)
    Lecturer Name: Dr Johanna
    Section: 06
*/
#include <iostream>
#include <fstream>
#include <iomanip>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <cstdlib>
#include <string>
#include "class.cpp"
#include "Payment.cpp"
using namespace std;
void UserMenu();

// BubbleSort for decending order 
void bubbleSort (int data[], int n)
{ 
    int temp;
    bool sorted = false; 
    for (int pass = 1; (pass < n) && !sorted; ++pass){ 
        sorted = true; 
        for (int x = 0; x < n-pass; ++x)
        { 
            if (data[x] < data[x+1]){ 
                temp = data[x];
                data[x] = data[x+1];
                data[x+1] = temp;
                sorted = false; 
            } 
        } 
    } 
}
 
// Sequencial search function
int SequenceSearch(string search_key,string array[],int array_size) {        
    int p,index=-1;
    for ( p = 0; p < array_size; p++ )
    { 
        if ( search_key == array[p] ){ 
        index = p;
        break; }
    } 
        return index;
} 

void testFile(ifstream &file){
      if(file.fail()){
        cout << "ERROR: Cannot open file." << endl;
        exit(0);
    }
}

//Username and Password Login 
UserLogin login(){
    UserLogin ul;
    string uName, pw;
    cout<<"Login"<<endl;
    cout<<"Username: ";
    cin>>uName;
    cout<<"Password: ";
    cin>>pw;
    ul.setNamePw(uName,pw);
    return ul;
}

//Student details
Student stuDetails(){
    int check;
    ifstream studFile;
    studFile.open("students.txt");
    string filemarks[5][5],fileresult[5],name[5],inputmN,matricNo[5];
    testFile(studFile);
    for(int i=0;i<5;i++)
    {
        getline(studFile,matricNo[i],',');
        getline(studFile,name[i],',');
        for(int j=0;j<5;j++)
        {
            getline(studFile,filemarks[i][j],',');
        }
        getline(studFile,fileresult[i]);
    }
     do{
        cout<<"Search matric number: ";
        cin>>inputmN;
        cout<<"Searching...."<<endl;
        sleep(2);
        check=SequenceSearch(inputmN,matricNo,5);
        if(check<0)
            cout<<"Matric number does not exist! Please reenter"<<endl<<endl;
            else
                cout<<"Search successfully !!"<<endl;
    }while(check<0);
     cout<<"Press any key to continue...";
                cin.ignore();
                cin.get();
                system("CLS");
    Student stud(inputmN);
    stud.setName(name[check]);
    return stud;
}

void ViewResult(Student stud){
    Student student[5];
    ifstream studFile;
    int marks[5][5],result[5],temp;
    studFile.open("students.txt");
    testFile(studFile);
    string filemarks[5][5],fileresult[5],matricNo[5],name[5];

    for(int i=0;i<5;i++)
    {
        getline(studFile,matricNo[i],',');
        getline(studFile,name[i],',');
        for(int j=0;j<5;j++)
        {
            getline(studFile,filemarks[i][j],',');
            marks[i][j]=stoi(filemarks[i][j]);
        }
        student[i].setMarks(marks[i]);
        getline(studFile,fileresult[i]);
        result[i]=stoi(fileresult[i]);
        student[i].setResults(result[i]);
    }

    for(int j=0;j<5;j++){
        if(stud.getMatricNo()==matricNo[j]){
            for(int k=0;k<5;k++){  
                temp=j;  
            }
        }
    }
stud.displayResult(marks,temp);
}

// Main menu for student
void mainMenuStudent(Student stud){
    Student student;
    student=stud;
    int choice;
    first:
    cout<<"Main Menu"<<endl<<"1. My Details"<<endl<<"2. My Result"<<endl<<"3. Log out"<<endl<<"choice:";
    cin>>choice;
    system("CLS");
    switch(choice){
        case 1:
                //student internship details
                student.displayDetail();
                cout<<"Press any key to return...";
                cin.ignore();
                cin.get();
                system("CLS");
                goto first;
        case 2:
                //my results function
                ViewResult(student);
                goto first;
        case 3:
                UserMenu();
                break;
        default:
                cout<<"ERROR!!! Invalid input.Please try again!";
                goto first;
    }
}

//STUDENT RESULTS
void studResult(){
//sort & search
    string matricNo[5],name[5],filemarks[5][5],fileresult[5];
    int marks[5][5],result[5],tempVar;
    ifstream studFile;
    ofstream output;
    Student student[5];
    char choice;
    Lecturer lect;
    studFile.open("students.txt");
    testFile(studFile);
    cout<<left<<setw(15)<<"Matric.No"<<setw(20)<<"Name"<<setw(10)<<right<<"Task 1"<<setw(10)<<"Task 2"<<setw(10)<<"Task 3"<<setw(10)<<"Task 4"<<setw(10)<<"Task 5"<<setw(10)<<"Result"<<endl;

    for(int i=0;i<5;i++)
    {
        getline(studFile,matricNo[i],',');
        student[i].setMatricNo(matricNo[i]);
        cout<<left<<setw(15)<<student[i].getMatricNo();
        getline(studFile,name[i],',');
        student[i].setName(name[i]);
        cout<<left<<setw(20)<<student[i].getName();
        for(int j=0;j<5;j++)
        {
            getline(studFile,filemarks[i][j],',');
            marks[i][j]=stoi(filemarks[i][j]);
            cout<<right<<setw(10)<<marks[i][j];
        }
        student[i].setMarks(marks[i]);
        getline(studFile,fileresult[i]);
        result[i]=student[i].myTotal(marks[i]);
        student[i].setResults(result[i]);
        cout<<right<<setw(10)<<result[i]<<endl;
    }
    
    output.open("students.txt");
    for(int i=0;i<5;i++){
        output<<matricNo[i]<<","<<name[i]<<",";
        
        for(int j=0;j<5;j++)
            output<<marks[i][j]<<",";//marks[1][2]
        output<<result[i]<<endl;
    }
        cout<<"\nSort data based on result "<<endl<<"  yes-y   no-n "<<endl<<"choice:";
        cin>>choice;
        system("cls");
        if(choice=='y'){
            bubbleSort(result,5);
            lect.sortStudent(student,marks,result,tempVar);
        }
}

//Evaluation System
void evalSystem(){
    ifstream tasksfile, studFile;
    Student student[5];
    Lecturer lect;
    Task task[5],task1[5];
    string tasks[5],duedate[5],matricNo[5],inputmN,name[5],no[5],result[5],fileresult[5],filestudmarks[5][5];
    int marks[5][5],marks1[5][5],check,whereAmI[5],temp,no2[5],number,menu,tempVar,lecMarks[5];
    int* studmarks;
    char want;
    bool sort = false;
    ofstream output;

    tasksfile.open("tasks.txt");
    studFile.open("students.txt");
    
    testFile(studFile);
    testFile(tasksfile);
    
    for(int i=0;i<5;i++)
    {
        getline(studFile,matricNo[i],',');
        student[i].setMatricNo(matricNo[i]);
        getline(studFile,name[i],',');
        student[i].setName(name[i]);
        for(int j=0;j<5;j++)
        {
            getline(studFile,filestudmarks[i][j],',');
            marks[i][j] = stoi(filestudmarks[i][j]);
        }
        getline(studFile,fileresult[i]);
    }

    do{
            cout<<"Search matric number: ";
            cin>>inputmN;
            cout<<"Searching...."<<endl;
            sleep(2);
            check=SequenceSearch(inputmN,matricNo,5);
            if(check<0)
                cout<<"Matric number does not exist! Please reenter"<<endl<<endl;
            else
                cout<<"Search successfully !!"<<endl;
            }while(check<0);  
              cout<<"Press any key to continue...";
                cin.ignore();
                cin.get();
                system("CLS");

    cout<<"Student Name: "<<student[check].getName()<<endl<<"Student Matric.no: "<<student[check].getMatricNo()<<endl;
    cout<<left<<setw(15)<<"No"<<setw(30)<<"Task"<<setw(10)<<"Due date"<<setw(10)<<"Mark"<<endl;

    for(int j=0;j<5;j++){
        if(student[check].getMatricNo()==matricNo[j]){
            for(int k=0;k<5;k++){  
                temp=j;   
            }
        }
    }

    for(int i=0;i<5;i++){
        getline(tasksfile,no[i],',');
        no2[i]=stoi(no[i]);
        task[i].setNo(no2[i]);
        getline(tasksfile,tasks[i],',');
        task[i].setTask(tasks[i]);
        getline(tasksfile,duedate[i]);
        task[i].setDate(duedate[i]);
        cout<<left<<setw(15)<<i+1<<setw(30)<<tasks[i]<<setw(10)<<duedate[i]<<setw(10)<<filestudmarks[temp][i]<<endl;
    }
    cout<<endl;

    x:
    cout<<"Menu"<<endl;
    cout<<"1. Sort the data based on date"<<endl<<"2. Evaluate the marks"<<endl<<"3. Back to main menu"<<endl<<"choice: ";
    cin>>menu;
    system("CLS");
    
    z:
    if(menu==1){
        sort = true;
        bubbleSort(no2,5);
        cout<<left<<setw(15)<<"No"<<setw(30)<<"Task"<<setw(10)<<"Due date"<<setw(10)<<"Mark"<<endl;
        for(int i=4;i>=0;i--){
            for(int k=4;k>=0;k--){
            if(task[k].getNo()==no2[i]){
                tempVar=k;
             cout<<left<<setw(15)<<no[tempVar]+"."<<setw(30)<<tasks[tempVar]<<setw(10)<<duedate[tempVar]<<setw(10)<<filestudmarks[temp][tempVar]<<endl;
             task1[4-i].setTask(tasks[tempVar]);
             task1[4-i].setDate(duedate[tempVar]);
             task1[4-i].setNo(stoi(no[tempVar]));
            }
        }
	}
    cout<<endl;
    sleep(2);
    goto x;
    }else if(menu==2){
        want = 'y';
        goto y;
    }else{
        cout<<"Invalid Input! Please choose again..";
        goto z;
    }

    y:
    studmarks= lect.evaluate(task1,task,temp,want,sort,marks[temp]);
    for(int i =0;i<5;i++)
            marks[temp][i]=studmarks[i];
    output.open("students.txt");
    for(int i=0;i<5;i++){
    output<<matricNo[i]<<","<<name[i]<<",";
        for(int j=0;j<5;j++)
            output<<marks[i][j]<<",";
        output<<fileresult[i]<<endl;
    }
    output.close();
    tasksfile.close();
    studFile.close();
}


//Main menu for lecturer
void mainMenuLect(){
    int choice;
    first:
    cout<<"Main Menu"<<endl<<"1. Evaluation system"<<endl<<"2. Students' results"<<endl<<"3. Log out"<<endl<<"choice: ";
    cin>>choice;
    system("CLS");
    switch(choice){
        case 1:
                //Evaluation system
                evalSystem();
                goto first;
        case 2:
                //Students'results
                studResult();
                goto first;
        case 3:
                UserMenu();
                break;
        default:
                cout<<"ERROR!!! Invalid input.Please try again!";
                goto first;
    }
}

void UserMenu(){
    int choice;
    int number;
    Lecturer lect;
    Student student;
    UserLogin ul;
    back:
    cout<<"User"<<endl<<"1. Student"<<endl<<"2. Lecturer"<<endl<<"3. Supervisor"<<endl<<"4. Exit"<<endl<<"choice: ";
    cin>>choice;
    system("cls");
    switch(choice){
       case 1:
            ul=login();
            ul.verifyStudent();
            student = stuDetails();
            mainMenuStudent(student);
       //student function
             break; 
        case 2:
            ul=login();
            ul.verifyLecturer();
            mainMenuLect();
       //lecturer function
            break;
        case 3:
            ul = login();
            ul.verifySupervisor();
            Payment();
            goto back;
        case 4 :
            exit(0);
            break;
        default:
            cout<<"ERROR!!! Invalid input.Please try again!";
            goto back;  } 
}

int main(){
    UserMenu();
    return 0;
}
