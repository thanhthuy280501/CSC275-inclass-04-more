#ifndef MONEY_H
#define MONEY_H

#include <iostream>

class Money
{
  public:
    Money();
    Money(double amount);
    Money(int theDollars, int theCents);
    Money(int theDollars);
    double getAmount() const;
    int getDollars() const;
    int getCents() const;

    friend const Money operator +(const Money& amount1, const Money& amount2);
    friend const Money operator -(const Money& amount1, const Money& amount2);
    friend bool operator ==(const Money& amount1, const Money& amount2);
    friend const Money operator -(const Money& amount);

    friend std::ostream& operator <<(std::ostream& outputStream, const Money& amount);
    friend std::istream& operator >>(std::istream& inputStream, Money& amount);

  private:
    int dollars;
    int cents;
};

#endif
