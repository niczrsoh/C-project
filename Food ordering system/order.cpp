#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <cstring>
using namespace std;
#define SIZE 10

//implement queue
class Order{
    private:
        string *id = new string[SIZE];
        int *quantity = new int[SIZE];
        string *name = new string[SIZE];
        int front;
        int back;
        string deletedItem;
        string deletedQuantity;
        string deletedName;
    public:
        Order();
        ~Order();
        void addOrder(string,string,int);
        void setID();
        bool isEmpty(){return bool(back < front);}
        bool isFull(){return bool(back == SIZE-1);}
        void removeOrder();
        void viewOrder(bool);
        string getName(){ return name[front];}
        string getID(){return id[front];}
        int getQuantity(){return quantity[front];}
};

Order::Order(){
    front = 0;
    back=-1;
}

Order::~Order(){
    delete[] id;
    delete[] quantity;
    delete[] name;
}

//view order
void Order::viewOrder(bool remove){
    cout<<left<<setw(5)<<getID()<<setw(18)<<getName()<<setw(8)<<getQuantity()<<endl;
    if(!remove)
        removeOrder();
}

//insert into a queue
void Order::addOrder(string insertItem,string insertName,int insertQuantity)
{
    if(isFull())
        cout<<"\nCannot Insert. Queue is full!"<<endl;
    else
    {
        //insert at back
        back++;
        id[back] = insertItem;
        quantity[back] = insertQuantity;
        name[back] = insertName;
    }//end else if
}

//delete from a queue
void Order::removeOrder()
{
    if(isEmpty())
        cout<<"\nCannot remove item. Empty Queue!"<<endl;
    else
    {
        //retrieve item at front
        deletedItem = id[front];
        deletedQuantity = quantity[front];
        deletedName = name[front];
        front++;
    } //end else if
}


