#include <iostream>
#include <string>
#include "menu.cpp"
#include "payment.cpp"
#include "order.cpp"
#include "customer.cpp"
using namespace std;
#define MAX 10
int num=0;
int num2=0;

void sortMenu(string data[],int listSize){
    int pass; 
    string tempValue;
    for (pass =1; pass < listSize; pass++){ 
        for (int x = 0; x < listSize - pass; x++){ 
            if ( data[x] > data[x+1] ){ 
                tempValue = data[x];
                data[x] = data[x+1];
                data[x+1] = tempValue;}
        }
    }
}

void displayCustInfo(Customer cus[],string name)
{
    for(int i=0;i<MAX;i++){
        if(cus[i].getName() == name){
            cout<<"Customer ID:"<<cus[i].getID()<<endl;
            cout<<"Customer Name:"<<cus[i].getName()<<endl;
        }
    }
}

void customer(Menu menu[],Customer cus[]){
   string name;
   cout<<"========== Customer Information =========="<<endl;
   cout<<"Enter your name: ";
   cin.ignore();
   getline(cin,name);
   cus[num2].set(name);
   cout<<endl;
   system("CLS");
   displayCustInfo(cus,name);
   cus[num2].ordering(menu,num);
   num2++;
}

int searchItem(string search_key,Menu menu[],int array_size){ 
    int p;
    int index = -1;
    for (p = 0; p < array_size; p++){ 
        if(search_key == menu[p].getItem()){ 
            index = p;
            break;} 
        }
        return index;
}

void admin(Menu menu[],Customer cust[]){
    int choice;
    string item,code,modItem;
    double price;
    string sortItem[MAX];
    string search_key;
    first:
    cout<<"Main Menu"<<endl<<"1. Add Items"<<endl<<"2. Modify Items"<<endl<<"3. Display Menu"<<endl<<"4. View Customer"<<endl<<"5. Search Item"<<endl<<"6. Exit"<<endl<<"Choice: ";
    cin>>choice;
    system("CLS");
    switch(choice){
        case 1:
                //add item 
                cout<<"========== Add Item =========="<<endl;
                cout<<"Code: ";cin>>code;
                cin.ignore();
                cout<<"Item: ";getline(cin,item);
                cout<<"Price: RM ";cin>>price;cout<<endl;
                menu[num].setItem(code, item,  price);
                num++;
                cin.ignore();
                cout<<"<< Press any key to continue... >>"<<endl;
                cin.get();
                system("CLS");
                goto first;
        case 2:
                //modify item
                cout<<"========== Modify Item =========="<<endl;
                cin.ignore();
                cout<<"Modified item: ";
                getline(cin,modItem);
                for(int i=0;i<num;i++){
                    if(menu[i].getItem()==modItem)
                    {
                        cout<<"New Code: ";cin>>code;
                        cin.ignore();
                        cout<<"New Item: ";getline(cin,item);
                        cout<<"New Price: RM ";cin>>price;cout<<endl;
                        menu[i].setItem(code, item, price);
                    }
                }
                cin.ignore();
                cout<<"<< Press any key to continue... >>"<<endl;
                cin.get();
                system("CLS");
                goto first;
        case 3:
                //sort and display Menu
                for(int i=0;i<num;i++){
                    sortItem[i]=menu[i].getItem(); 
                }
                sortMenu(sortItem,num);
                cout<<"============ Sorted Menu ============ "<<endl;
                cout<<left<<setw(5)<<"Code"<<setw(15)<<"Name"<<setw(10)<<"Price"<<endl;
                for(int i=0;i<num;i++){
                    for(int j=0;j<num;j++){
                        if(sortItem[i]==menu[j].getItem())
                        {
                            int tempValue;
                            tempValue = j;
                            menu[tempValue].displayMenu();
                        }
                    }
                }
                cin.ignore();
                cout<<"<< Press any key to continue... >>"<<endl;
                cin.get();
                system("CLS");
                goto first;
        case 4:
                cout<<"==========Customer Details=========="<<endl;
                for(int i=0;i<num2;i++){
                    cout<<"Customer "<<i+1<<endl;
                    cout<<"Id   : "<<cust[i].getID()<<endl<<"Name : "<<cust[i].getName()<<endl;
                    cout<<"Order: "<<endl;
                    cust[i].getOrder();
                    cout<<"------------------------------------"<<endl;
                }
                cin.ignore();
                cout<<"<< Press any key to continue... >>"<<endl;
                cin.get();
                system("CLS");
                goto first;
        case 5:
                cout<<"========== Search Item =========="<<endl;
                cout<<"Enter the Item you want to search: ";
                cin.ignore();
                getline(cin,search_key);
                int i;
                i = searchItem(search_key,menu,num);
                if(i)
                  cout<<"\nNo item found"<<endl;
                else{
                cout<<"\nThe Item search is: "<<endl;
                cout<<"Item ID: "<<menu[i].getID()<<endl;
                cout<<"Item name: "<<menu[i].getItem()<<endl;
                cout<<"Item Price: RM "<<menu[i].getPrice()<<endl<<endl;
                }
                cin.ignore();
                cout<<"<< Press any key to continue... >>"<<endl;
                cin.get();
                system("CLS");
                goto first;
        case 6:
                return;
        default:
                cout<<"ERROR!!! Invalid input.Please try again!";
                goto first;
    }
}

bool authenticate()
{
    /*
        Username: sulaiman
        Password: 123456     */
    string username,pass;
    cout<<"--Please enter the following details--"<<endl;
    cout<<"Username: ";
    cin>>username;
    cout<<"Password: ";
    cin>>pass;
    if(username=="sulaiman"&&pass=="123456")
        return true;
    else{
        cout<<"Wrong Username or Password. Please reenter!"<<endl;
        return false;
        }
}

int main() 
{   
    Menu menu[10];
    Customer cust[10];
    int choice;
    bool auth;
    start:
    cout<<"---------- Welcome to Restoran Wau ----------"<<endl;
    cout<<"1. Customer"<<endl<<"2. Admin"<<endl<<"3. Exit"<<endl;
    cout<<"Enter choice: ";
    cin>>choice;
    system("CLS");
    switch(choice){
        case 1:
            customer(menu,cust);
            goto start;
        case 2:
            do{
              auth=authenticate();
            }while(!auth);
            system("CLS");
            admin(menu,cust);
            
            goto start;
        case 3:
            exit(0);
        default:
            cout<<"ERROR!!! Invalid input.Please try again!"<<endl;
            goto start;
    }
    
}

