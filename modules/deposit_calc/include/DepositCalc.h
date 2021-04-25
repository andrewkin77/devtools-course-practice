// Copyright 2021 Lebedev Andrew

#ifndef MODULES_DEPOSIT_CALC_INCLUDE_DEPOSITCALC_H_
#define MODULES_DEPOSIT_CALC_INCLUDE_DEPOSITCALC_H_

#include <vector>
#include <utility>

class  depositCalc {
    int depositSum;
    int numberOfMonths;
    int numberOfDays;
    double interestRate;
    int day;
    int month;
    int year;
    std::vector<int> daysInMonths;
    int capitalization;
    int result;

 public:
    depositCalc();
    void setDepositSum(int _depositSum);
    void setNumberOfMonths(int _numberOfMonths);
    void setNumberOfDays(int _numberOfDays);
    void setInterestRate(double _interestRate);
    void setDate(int _day, int _month, int _year);
    void setCapitalization(int _capitalization);
    int getDepositSum();
    int getNumberOfDays();
    int getNumberOfMonths();
    double getInterestRate();
    int getCapitalization();
    int getResult();
    void calculate();
};
#endif  // MODULES_DEPOSIT_CALC_INCLUDE_DEPOSITCALC_H_
