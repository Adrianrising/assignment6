//
// Created by BMT on 9/29/2022.
//
#include "iostream"
using namespace std;
class Store{
public:
    string catagories[4]={"Fruits","Dairy","Snacks","Drinks"};
    string fruits[10]={"apple","orange","pineapple","lemon","dragonfruit","watermelon","mango","banana","strawberry","blueberry"};
    int fruitPrices[10]={1,2,3,4,5,6,7,8,9,10};
    int fruitInStock[10]={2,6,7,4,3,7,20,13,4,4};
    string dairies[10]={"milk","butter","sourcream","yogurt","cheese","custard","vanilla","casein","whey","heavycream"};
    int dairyPrices[10]={1,2,3,4,5,6,7,8,9,10};
    int dairyInStock[10]={2,6,7,4,3,7,20,13,4,4};
    string snacks[10]={"cookies","waffle","potatochip","humburger","pizza","ramen","chocolate","candy","icepop","croissant"};
    int snackPrices[10]={1,2,3,4,5,6,7,8,9,10};
    int snackInStock[10]={2,6,7,4,3,7,20,13,4,4};
    string drinks[10]={"water","cocacola","pepsi","coffee","icedcoffee","faluda","soda","sprite","orangejuice","lemonjuice"};
    int drinkPrices[10]={1,2,3,4,5,6,7,8,9,10};
    int drinkInStock[10]={2,6,7,4,3,7,20,13,4,4};
    Store(){
        cout<<"Welcome to our store"<<endl;
    }
    int mainMenu();
    void inventory(string goods[],int prices[],int quantity[]);
    void receipt(string goods[],int prices[],int quantity[]);
};

void Store::inventory(string goods[],int prices[],int quantity[]){
    cout<<"This is Inventory!"<<endl;
    for(int i=0;i<10;i++){
        cout<<goods[i];
        for(int j=0;j<1;j++){
            cout<<"   Price:"<<prices[i]<<"   Quantity:"<<quantity[i]<<endl;
        }
    }
}

void Store::receipt(string goods[],int prices[],int quantity[]) {
    int browseOrPurchase;
    int indexOfItem;
    string wantedItem;
    int we_have_it=0;
    int quantity_wanted_item;
    int purchased_item_count=0;
    int array_size_control=1;
    string purchased_items[100];
    int purchased_item_quantity[100];
    int cost[100];
    int totalCost=0;
    cout << "Press 1 to purchase, Press 2 to go back to Catagory:";
    cin >> browseOrPurchase;
    if (browseOrPurchase == 1) {
        int control;
        bool stillPurchasing= true;
        while (stillPurchasing) {
            cout <<"Enter an item: ";
            cin >> wantedItem;
            for (int i = 0; i < 10; i++) {
                if (wantedItem == goods[i]) {
                    indexOfItem = i;
                    we_have_it=1;
                }
            }
            if(we_have_it==0){
                cout<<"sorry we don't have "<<wantedItem<<endl;
                continue;
            }
            cout<<"Enter the quantity you want: ";
            cin>>quantity_wanted_item;
            if(quantity_wanted_item<=quantity[indexOfItem]){
                quantity[indexOfItem]-=quantity_wanted_item;
                purchased_items[purchased_item_count]=wantedItem;
                purchased_item_quantity[purchased_item_count]=quantity_wanted_item;
                cost[purchased_item_count]=quantity_wanted_item*prices[indexOfItem];
                purchased_item_count+=1;
            }else{
                cout<<"Sorry.Insufficient quantity"<<endl;
            }
            cout<<"Press 1 to continue purchasing.Press 2 to stop:";
            cin>>control;
            if(control==2){
                stillPurchasing=false;
            }else{
                array_size_control++;
            }
        }
        cout<<" THE RECEIPT"<<endl;
        for(int j=0;j<array_size_control;j++){
            cout<<purchased_items[j]<<"  ";
            cout<<"qty:"<<purchased_item_quantity[j]<<"  ";
            cout<<"cost:"<<cost[j]<<endl;
        }
        cout<<"TOTAL COST:";
        for (int i = 0; i < array_size_control; ++i) {
            totalCost+=cost[i];
        }
        cout<<totalCost;
   }else{
        mainMenu();
    }
}
int Store::mainMenu(){
    int catagory_choice;
    cout<<"Store Catagories";
    cout<<endl<<"Press 1 for fruits"<<endl;
    cout<<"Press 2 for Dairy"<<endl;
    cout<<"Press 3 for Snacks"<<endl;
    cout<<"Press 4 for Drinks"<<endl;
    cout<<"Press 5 to quit"<<endl;
    cout<<"Please choose>>";
    cin>>catagory_choice;
    if(catagory_choice==1){
        inventory(fruits,fruitPrices,fruitInStock);
        receipt(fruits,fruitPrices,fruitInStock);
    }else if(catagory_choice==2){
        inventory(dairies,dairyPrices,dairyInStock);
        receipt(dairies,dairyPrices,dairyInStock);
    }else if(catagory_choice==3){
        inventory(snacks,snackPrices,snackInStock);
        receipt(snacks,snackPrices,snackInStock);
    }else if(catagory_choice==4){
        inventory(drinks,drinkPrices,drinkInStock);
        receipt(drinks,drinkPrices,drinkInStock);
    }else{
        cout<<"Please come back again!";
        return 0;
    }
}
int main(){
    Store obj;
    int ex=obj.mainMenu();
    if(ex==0){
        exit(1);
    }
}