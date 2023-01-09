#include "currency_converter.h"

using namespace std;

vector<string> currenciesTypes={"USD", "GBP", "INR", "EUR", "CHF", "AUD", "SGD", "CNY", "JPY"};

void currencyConverter::displayInputCurrenciesList()
{
    cout<<"Welcome to CCTech Currency converter:"<<endl;
    cout<<"Following are the output currencies"<<endl;

    for(int i=0;i<currenciesTypes.size();++i)
    {
        cout<<i+1<<"."<<currenciesTypes[i]<<endl;
    }
}

void currencyConverter::selectInputCurrency()
{
    cout<<"\nSelect the input currency from the list"<<endl;
    cout<<">";
    cin>>inputCurrencyType;
 
    if(!inputCurrencyType<=currenciesTypes.size())
        cerr<<"Warning: Invalid Input "<<endl;
    else
        cout<<"You have selected : "<<currenciesTypes[inputCurrencyType-1]<<" currency"<<endl;
}

void currencyConverter::displayOutputCurrenciesList()
{
    vector<string>::iterator itr;

    itr=find(currenciesTypes.begin(),currenciesTypes.end(),currenciesTypes[inputCurrencyType-1]);
    currenciesTypes.erase(itr);

    cout<<"\nFollowing are the output currencies:"<<endl;
    for (int i=0;i<currenciesTypes.size();++i)
    {
        cout<<i+1<<"."<<currenciesTypes[i]<<endl;

    }
}

void currencyConverter::selectOutputCurrency()
{
    cout<<"\nSelect the output currency from the list"<<endl;
    cout<<">";
    cin>>outputCurrencyType;

    if(!outputCurrencyType<=currenciesTypes.size())
        cerr<<"Warning: Invalid Input. Please try again!! "<<endl;
    else
        cout<<"You have selected output currency : "<<currenciesTypes[outputCurrencyType-1]<<" currency"<<endl;
}

void currencyConverter::readCurrencyRatesFromFile()
{   
    ifstream file("conversion_rates.txt",ios::in);
    string show_text;
    auto search = currenciesTypes[outputCurrencyType-1];

    if(file.is_open())
    {
        string convertIntoInt;
        stringstream ss;

        while(getline(file,show_text))
        {
            if(show_text.find_last_of(search) != string::npos)
                {
                    for(int i=4;i<12;++i)
                    {
                        show_text.erase(remove(show_text.begin(),show_text.end(),'.'),show_text.end());                    
                        convertIntoInt+=show_text[i];
                    }
                }
        }
        ss<<convertIntoInt;
        ss>>conversionRate;
}
    else
        cerr << "Could not open file conversion_rates.txt" << endl;

    file.close();
}

void currencyConverter::enterAmount()
{
    cout<<"\nEnter the amount you want to convert : ";
    cin>>amountOfCurrency;
}

void currencyConverter::convertToUSDReference()
{
    switch(inputCurrencyType)
    {
        case 1:
            referenceToUSD=amountOfCurrency*1;
            break;
        case 2:
            referenceToUSD=amountOfCurrency*1.2165692 ;
            // cout<<"\n"<<amountOfCurrency <<" GBP to USD : "<<referenceToUSD<<" USD"<<endl;
            break;
        case 3:
            referenceToUSD=amountOfCurrency*0.012143487 ;
            // cout<<"\n"<<amountOfCurrency <<" INR to USD : "<<referenceToUSD<<" USD"<<endl;
            break;
        case 4:
            referenceToUSD=amountOfCurrency*1.0678432;
            // cout<<"\n"<<amountOfCurrency <<" EUR to USD : "<<referenceToUSD<<" USD"<<endl;
            break;
        case 5:
            referenceToUSD=amountOfCurrency*1.0818219 ;
            // cout<<"\n"<<amountOfCurrency <<" CHF to USD : "<<referenceToUSD<<" USD"<<endl;
            break;
        case 6:
            referenceToUSD=amountOfCurrency*0.69282967;
            // cout<<"\n"<<amountOfCurrency <<" AUD to USD : "<<referenceToUSD<<" USD"<<endl;
            break;
        case 7:
            referenceToUSD=amountOfCurrency*0.75029716;
            // cout<<"\n"<<amountOfCurrency <<" SGD to USD : "<<referenceToUSD<<" USD"<<endl;
            break;
        case 8:
            referenceToUSD=amountOfCurrency*0.14743201;
            // cout<<"\n"<<amountOfCurrency <<" CNY to USD : "<<referenceToUSD<<" USD"<<endl;
            break;
        case 9:
            referenceToUSD=amountOfCurrency*0.0075577008;
            // cout<<"\n"<<amountOfCurrency <<" JPY to USD : "<<referenceToUSD<<" USD"<<endl;
            break;
        default:
            cerr<<"Nothing is selected "<<endl;
            break;   
    } 
}

void currencyConverter::finalCurrencyConversion()
{
    if(outputCurrencyType==2) //for INR
    {
        double convertedAmount=(conversionRate/100000)*referenceToUSD;
        cout<<"\nConverted Amount 1: "<<convertedAmount<<" "<<currenciesTypes[outputCurrencyType-1]<<endl;
    }
    else if(outputCurrencyType==8) //for JPY
    {
        double convertedAmount=(conversionRate/10000)*referenceToUSD;
        cout<<"\nConverted Amount 2: "<<convertedAmount<<" "<<currenciesTypes[outputCurrencyType-1]<<endl;
    }
    else
    {
        double convertedAmount=(conversionRate/1000000)*referenceToUSD;
        cout<<"\nConverted Amount 3: "<<convertedAmount<<" "<<currenciesTypes[outputCurrencyType-1]<<endl;
    }
}

void currencyConverter::runAllFunctions()
{
    displayInputCurrenciesList();
    selectInputCurrency();
    displayOutputCurrenciesList();
    selectOutputCurrency();
    readCurrencyRatesFromFile();
    enterAmount();
    convertToUSDReference();
    finalCurrencyConversion();
}


