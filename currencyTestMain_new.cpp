#include "Money.h"
#include <iostream>

int main()
{
    Money yourAmount, myAmount(10, 9);
    std::cout << "Enter an amount of money: ";
    std::cin >> yourAmount;

    std::cout << "Your amount is " << yourAmount << std::endl;
    std::cout << "My amount is " << myAmount << std::endl;

    if (yourAmount == myAmount)
        std::cout << "We have the same amounts." << std::endl;
    else
        std::cout << "One of us is richer." << std::endl;

    return 0;
}
