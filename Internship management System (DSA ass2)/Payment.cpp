#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

class Node{
	public:
		Node* next;
		string name;
		double salary;
        int num;
};

class List{
	Node *head;
	public:
		List(void){
			head=NULL;
		}
		~List(void);
		Node* InsertNode(int x,double salary,string name);
		int DeleteNode(int x);
		void DisplayNode(void);
};

//Insert Node
Node* List::InsertNode(int x,double salary, string name){
	int currIndex=0;
	Node* currNode = head;
	Node* prevNode = NULL;
	while(currNode && x>currNode->num){
		prevNode = currNode;
		currNode = currNode->next;
		currIndex++;
	}
	Node* newNode = new Node;
	newNode->num = x;
	newNode->name = name;
    newNode->salary = salary;
	if(currIndex==0){
		newNode->next = head;
		head = newNode;
	}else{
		newNode->next = prevNode->next;
		prevNode->next = newNode;
	}
	return newNode;
}

//Payment from supervisor
void Payment(){
    List list;
    char cont;
    string name;
    int num=1;
    double pay;
    char find;
    char choice;
    cin.ignore();
    do{
        cout<<"Please enter the folloting details:"<<endl;
        cout<<"Student name: ";
        getline(cin,name);
        cout<<"Payment: RM ";
        cin>>pay;
        list.InsertNode(num,pay,name);
        system("cls");
        cout<<"Do you want to cancel the payment?"<<endl<<"y - yes      n - no"<<endl;
        cin>>choice;
        if(tolower(choice)=='y'){
            list.DeleteNode(num);
        }
        system("cls");
        cout<<"Do you want to add another payment? if yes press y"<<endl;
        cin>>cont;
        num++;
        cin.ignore();
        system("cls");
    }while(tolower(cont)=='y');
    cout<<"-------Total payment-------"<<endl;
    list.DisplayNode();
}

//DisplayNode
void List::DisplayNode(){
	Node* currNode =head;
	while(currNode!=NULL){
		cout<<left<<currNode->num<<"\t"<<setw(20)<<currNode->name<<"\t"<<"RM "<<setw(7)<<currNode->salary<<endl;
		currNode = currNode->next;
	}
}

//Delete Node
int List::DeleteNode(int x) {
    Node* prevNode =NULL;
    Node* currNode =head;
    int currIndex =1;
    while (currNode && currNode->num != x) {
        prevNode = currNode;
        currNode = currNode->next;
        currIndex++;
    }

    if (currNode) {
        if (prevNode) {
            prevNode->next =currNode->next;
            delete currNode;
        }
        else {
            head =currNode->next;
            delete currNode;
        }
        return currIndex;
        }
    return 0;
}

//Destructor
List::~List(){
	Node* currNode = head;
	Node* nextNode = NULL;
	while(currNode!=NULL){
		nextNode = currNode->next;
		delete currNode;
		currNode = nextNode;
	}
	head=NULL;
}