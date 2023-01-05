#include "vending_machine.h"

using namespace std;

int main(int argc, char* argv[])
{
    MenuCard menucard;
    menucard.welcome();
    menucard.listOfItems();

    VendingMachine vm;
    vm.multipleOfCurrency();
    vm.totalAcceptedCoins();
    vm.selectItem();
    vm.compareAmountWithItemValue();
    vm.balanceAmount();
    vm.exactChange();
    vm.isSoldOut();

    return 0;
}
