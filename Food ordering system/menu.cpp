#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <cstring>

using namespace std;
#define MAX 10 

class Menu
{
    private:
        string id;
        string item;
        double price;
    public:
        void setItem(string, string, double);
        string getID() ;
        string getItem() ;
        double getPrice() ;
        void displayMenu() ;
        void sortMenu(string[], int) ;
};

void Menu::setItem(string id, string item, double price)
{
    this->id=id;
    this->item=item;
    this->price=price;    
}

string Menu::getID()
{
    return id;
}

string Menu::getItem()
{
    return item;
}

double Menu::getPrice()
{
    return price;
}

void Menu::displayMenu()
{
    cout<<left<<setw(5)<<getID()<<setw(15)<<getItem()<<"RM"<<setprecision(2)<<fixed<<getPrice()<<endl;
}
