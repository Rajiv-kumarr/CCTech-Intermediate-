#include "vending_machine.h"

using namespace std;

void MenuCard::welcome() const
{
    cout << "Welcome to this Vending machine!!!" << endl;
}

void MenuCard::listOfItems()
{
    itemsList["Cola"]  = 100;
    itemsList["Chips"] = 50;
    itemsList["Candy"] = 65;

    map<string, unsigned int>::iterator itr = itemsList.begin();
    cout << "The items and their rates are :" << endl;
    while (itr != itemsList.end())
    {
        cout << itr->first << " : " << itr->second << " cents"<<endl;
        ++itr;
    }
    cout<<"*****************************"<<endl;

}

void VendingMachine::multipleOfCurrency()
{
    cout<<"Special note!!! coins are only accepted in multiples of nickels, dime, and quarter."
    "\nsingle pennies are not allowed."<<endl;
    cout<<"*****************************"<<endl;

    cout<<"Enter the multiple of nickels(5 cents): ";
    cin>>numberOfCoins_nickel;
    cout<<"Enter the multiple of dime(10 cents): ";
    cin>>numberOfCoins_dime;
    cout<<"Enter the multiple of quarter(25 cents): ";
    cin>>numberOfCoins_quarter;

    totalAmount_nickel=numberOfCoins_nickel*5;
    totalAmount_dimes=numberOfCoins_dime*10;
    totalAmount_quarter=numberOfCoins_quarter*25; 

    cout<<"-----------------------------"<<endl;
}

unsigned int VendingMachine::totalAcceptedCoins()
{
    cout << "MESSAGE: Start inserting your coins inside V.M" << endl;
    totalAmount=totalAmount_nickel+totalAmount_dimes+totalAmount_quarter;
    cout<<"You have inserted a total Amount : "<<totalAmount_nickel<<" + "<<totalAmount_dimes<<" + "<<totalAmount_quarter<<" = "<<totalAmount<<" cents"<<endl;
    cout<<"-----------------------------"<<endl;
    
    return totalAmount;
}

void VendingMachine::selectItem()
{
    cout<<"Select among the following items: COLA, CHIPS, CANDY"<<endl;
    cout<<"Enter the quantity of COLA: ";
    cin>>itemCount_cola;
    itemsLeft_cola=MAX_COLA_COUNT-itemCount_cola;

    cout<<"Enter the quantity of CHIPS: ";
    cin>>itemCount_chips;
    itemsLeft_chips=MAX_CHIPS_COUNT-itemCount_chips;

    cout<<"Enter the quantity of CANDY: ";
    cin>>itemCount_candy;
    itemsLeft_candy=MAX_CANDY_COUNT-itemCount_candy;

    cout<<"-----------------------------"<<endl;
}

bool VendingMachine::isSoldOut()
{
    if (itemCount_cola>itemsLeft_cola)
        cerr << "only " << MAX_COLA_COUNT << " colas are available " << endl;
        if (itemCount_chips>itemsLeft_chips)
            cerr << "only " << MAX_CHIPS_COUNT << " chips are available " << endl;
            if (itemCount_candy>itemsLeft_candy)
                cerr << "only " << MAX_CANDY_COUNT << " candy are available " << endl;

    exit(0);
}

void VendingMachine::compareAmountWithItemValue()
{
    itemsPrice_cola=itemCount_cola*100;
    itemsPrice_chips=itemCount_chips*50;
    itemsPrice_candy=itemCount_candy*65;

    cout << "Calculating your items amount: "<<endl;
    cout<<"For cola: "<<itemsPrice_cola<<endl;
    cout<<"For chips: "<<itemsPrice_chips<<endl;
    cout<<"For candy: "<< itemsPrice_candy<<endl;

    itemsPrice= itemsPrice_cola+itemsPrice_chips+itemsPrice_candy;
    cout<<"The total amount of your items is: "<<itemsPrice<<endl;
    cout<<"You have inserted a total Amount : "<<totalAmount<<" cents"<<endl;

    cout<<"-----------------------------"<<endl;
}

void VendingMachine::balanceAmount()
{
    if(itemsPrice>totalAmount)
    {
        cout<<"You need to insert ("<<itemsPrice<<" - "<<totalAmount<<") = "<< itemsPrice-totalAmount<<" more cents"<<endl;
    }
    else if(itemsPrice<totalAmount)
    {
        cout<<"Returning your balance amount: ("<<totalAmount<<" - "<<itemsPrice<<") = "<<totalAmount-itemsPrice<<" cents"<<endl;
    }

    cout<<"-----------------------------"<<endl;
}

void VendingMachine::exactChange()
{
    totalCurrencyInVendingMachine=(MAX_NICKEL_COUNT_IN_VM * 5)+ (MAX_DIME_COUNT_IN_VM * 10) + (MAX_QUARTER_COUNT_IN_VM * 25);

    if((totalAmount-itemsPrice)>totalCurrencyInVendingMachine)
    {
        cerr<<"Warning: This vending machine does not have change of "<< abs(itemsPrice-totalAmount)<<" cents"<<endl;
        cerr<<"Please insert exact change of: "<<itemsPrice<< " cents"<<endl;
    }
    else if((totalAmount-itemsPrice)<totalCurrencyInVendingMachine)
    {
        totalCurrencyInVendingMachine-(totalAmount-itemsPrice);
    }
}
