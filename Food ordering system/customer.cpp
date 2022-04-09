#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <cstring>

using namespace std;
#define MaxItem 10

class Customer
{
    private:
        string id;
        string name;
        string orderId[MaxItem];
        string orderName[MaxItem];
        int orderQuantity[MaxItem];
        double orderPrice[MaxItem];
        double totalPrice;
        double totalchange;
        double custPrice;
        bool remove = false;
        Menu *menu;
        Payment payment;
        Order order;
    public: 
        void set(string );
        string getName();
        string getID();
        void ViewMenu(Menu[], int);
        void saveOrder(string[],string[],int[]);
        void pay();
        void receipt();
        void ordering(Menu[],int);
        void getOrder();
};

void Customer::ordering(Menu m[], int size){
   menu = m;
   string id;
   char cont;
   int choice;
   int no=0;
   int quantity;
   string name;
   double price;
   cout<<"========== Restoran Wau =========="<<endl;
   jump:
   cout<<"1. Make Order"<<endl<<"2. Cancel Order"<<endl<<"3. View Order"<<endl<<"4. Make Payment"<<endl<<"5. View Receipt"<<endl<<"6. Exit"<<endl;
   cout<<"Enter choice: ";
   cin>>choice;
   system("CLS");
   switch(choice){
    case 1:
         ViewMenu(menu,size);
         cout<<"========== Making order ========="<<endl;
         cout<<"Enter the food id: ";
         cin>>id;
         for(int i=0;i<size;i++){
             if(menu[i].getID() == id){
                 name=menu[i].getItem();
                 price=menu[i].getPrice();
            }
         }
         cout<<"Quantity: ";
         cin>>quantity;
         system("CLS");
         orderId[no]= id;
         orderName[no]=name;
         orderQuantity[no]=quantity;
         orderPrice[no]=price;
         order.addOrder(id,name,quantity);
         no++;
         goto jump;
    case 2:
         cout<<"========== Cancel Order =========="<<endl;
         for(int i =0;i<no;i++){
            order.removeOrder();
            orderName[i] = " ";
            orderId[i] = " ";
            orderQuantity[i]=0;
            orderPrice[i]=0;
         }
         no=0;
         remove = true;
         cout<<"Your order has been cancelled!"<<endl;
        cin.ignore();
        cout<<"<< Press any key to continue... >>"<<endl;
        cin.get();
        system("CLS");
         goto jump;
    case 3:
         cout<<"========== My order =========="<<endl;
         cout<<left<<setw(5)<<"ID"<<setw(15)<<"Name"<<setw(8)<<"Quantity"<<endl;
         for(int i=0;i<no;i++){
            order.viewOrder(remove);
         }
        //restore
        if(!remove)
         for(int i=0;i<no;i++){
            order.addOrder(orderId[i],orderName[i],orderQuantity[i]);
         }
        remove=false;   
        cin.ignore();
        cout<<"<< Press any key to continue... >>"<<endl;
        cin.get();
        system("CLS");
        goto jump;
    case 4:
        pay();
        cin.ignore();
        cout<<"<< Press any key to continue... >>"<<endl;
        cin.get();
        system("CLS");
        goto jump;
    case 5:
        receipt();
        cin.ignore();
        cout<<"<< Press any key to continue... >>"<<endl;
        cin.get();
        system("CLS");
        goto jump;
    case 6:
        cout<<"Thank you for visit Restoran Wau ordering system"<<endl<<endl;
        cin.ignore();
        cout<<"<< Press any key to continue... >>"<<endl;
        cin.get();
        system("CLS");
        return;
    default:
        cout<<"ERROR!!! Invalid input.Please try again!"<<endl;
        goto jump;
   }
}

 void Customer::pay()
{
    cout<<"========== My Payment =========="<<endl;
    payment.calPrice(orderPrice,orderQuantity);
    cout<<"Total Price: RM "<<payment.getTotalPrice()<<endl;
    cout<<"Paid: RM ";
    cin>>custPrice;
    payment.setCustPrice(custPrice);
    totalchange = payment.calChange();
    cout<<"Total Change: RM "<<totalchange<<endl;
} 

void Customer::receipt(){
    cout<<"================== Restoran Wau =================="<<endl<<endl;
    cout<<"Mr/Mrs : "<<getName();
    cout<<"\t\tReceipt No : "<<"RW"+id+"2022"<<endl<<endl;
    cout<<left<<setw(5)<<"Bil"<<setw(15)<<"Item"<<setw(5)<<"Qty"<<setw(15)<<"UnitPrice(RM)"<<setw(10)<<"Amount(RM)"<<endl;
    for(int i=0;i<MaxItem;i++){
        if(orderQuantity[i]==0){
            break;
        }
        cout<<left<<setw(5)<<i+1<<setw(16)<<orderName[i]<<setw(8)<<
        orderQuantity[i]<<setw(13)<<orderPrice[i]<<setw(6)<<
        (orderPrice[i]*orderQuantity[i])<<endl;
    }
    cout<<"\nSub Total: RM"<<payment.getTotalPrice()<<endl<<endl;
    cout<<"=================================================="<<endl;
}

void Customer::getOrder()
{
    for(int i=0;i<MaxItem;i++)
    {
        if(orderQuantity[i]==0)
            break;
        cout<<left<<setw(5)<<orderId[i]<<setw(15)<<orderName[i]<<setw(8)<<orderQuantity[i]<<endl;
    }
}

void Customer::set(string n)
{
    static int count = 1;
    name = n;
    string str = to_string(count);
    id = "A20E"+str;
    count++;
}

string Customer::getName()
{
    return name;
}

string Customer::getID(){
    return id;
}

void Customer::ViewMenu(Menu m[],int num){
     menu = m;
     cout<<"============ Customer Menu ============ "<<endl;
                cout<<left<<setw(5)<<"Code"<<setw(15)<<"Name"<<setw(10)<<"Price"<<endl;
                for(int i=0;i<num;i++){
                    menu[i].displayMenu();
                }
     cout<<"--------------------------------------- "<<endl;
}
