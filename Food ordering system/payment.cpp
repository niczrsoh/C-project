#include <iostream>
using namespace std;
#define MaxItem 10

class Payment{
  private:
    double totalPrice;
    double custPrice;
    double change;
  public:
    double getTotalPrice(){return totalPrice;}
    void calPrice(double[],int[]);
    double calChange();
    void setCustPrice(double n){custPrice = n;}
};

void Payment::calPrice(double price[], int quantity[]){
    double total=0;
    for(int i=0;i<MaxItem;i++){
        if(quantity[i]==0)
            break;
        total+=(price[i]*quantity[i]);
    }
    totalPrice=total;
}

double Payment::calChange(){
    return custPrice-totalPrice;
}