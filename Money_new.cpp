#include "Money.h"
#include <cmath>

Money::Money() : dollars(0), cents(0) {}

Money::Money(double amount)
{
    dollars = static_cast<int>(amount);
    cents = static_cast<int>((amount - dollars) * 100);
}

Money::Money(int theDollars, int theCents) : dollars(theDollars), cents(theCents) {}

Money::Money(int theDollars) : dollars(theDollars), cents(0) {}

double Money::getAmount() const
{
    return dollars + cents / 100.0;
}

int Money::getDollars() const
{
    return dollars;
}

int Money::getCents() const
{
    return cents;
}

const Money operator +(const Money& amount1, const Money& amount2)
{
    int totalCents1 = amount1.getDollars() * 100 + amount1.getCents();
    int totalCents2 = amount2.getDollars() * 100 + amount2.getCents();
    int sumCents = totalCents1 + totalCents2;

    return Money(sumCents / 100, sumCents % 100);
}

const Money operator -(const Money& amount1, const Money& amount2)
{
    int totalCents1 = amount1.getDollars() * 100 + amount1.getCents();
    int totalCents2 = amount2.getDollars() * 100 + amount2.getCents();
    int diffCents = totalCents1 - totalCents2;

    return Money(diffCents / 100, diffCents % 100);
}

bool operator ==(const Money& amount1, const Money& amount2)
{
    return (amount1.getDollars() == amount2.getDollars() && amount1.getCents() == amount2.getCents());
}

const Money operator -(const Money& amount)
{
    return Money(-amount.getDollars(), -amount.getCents());
}

std::ostream& operator <<(std::ostream& outputStream, const Money& amount)
{
    int absDollars = std::abs(amount.getDollars());
    int absCents = std::abs(amount.getCents());
    if (amount.getDollars() < 0 || amount.getCents() < 0)
        outputStream << "-";
    outputStream << "$" << absDollars << '.';
    if (absCents < 10)
        outputStream << '0';
    outputStream << absCents;

    return outputStream;
}

std::istream& operator >>(std::istream& inputStream, Money& amount)
{
    double inputAmount;
    inputStream >> inputAmount;
    amount = Money(inputAmount);
    return inputStream;
}
