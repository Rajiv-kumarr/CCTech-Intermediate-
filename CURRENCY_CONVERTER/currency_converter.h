#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>

class currencyConverter
{
    public:
    currencyConverter():conversionRate(0){};
    void displayInputCurrenciesList();
    void selectInputCurrency();
    void displayOutputCurrenciesList();
    void selectOutputCurrency();
    void readCurrencyRatesFromFile();
    void enterAmount();
    void convertToUSDReference();
    void finalCurrencyConversion();
    void runAllFunctions();

    private:
    unsigned int inputCurrencyType;
    unsigned int outputCurrencyType;
    double conversionRate;
    double amountOfCurrency;
    double referenceToUSD;
};



