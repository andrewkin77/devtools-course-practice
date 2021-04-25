// Copyright 2021 Lebedev Andrew

#include <gtest/gtest.h>
#include <utility>
#include <vector>
#include <iostream>
#include "include/DepositCalc.h"

TEST(DepositCalc, setDepositSum) {
    depositCalc x;
    x.setDepositSum(300);
    ASSERT_EQ(300, x.getDepositSum());
}

TEST(DepositCalc, setBadDepositSum) {
    depositCalc x;
    ASSERT_ANY_THROW(x.setDepositSum(-2));
}

TEST(DepositCalc, setNumberOfMonths) {
    depositCalc x;
    x.setNumberOfMonths(25);
    ASSERT_EQ(25, x.getNumberOfMonths());
}

TEST(DepositCalc, setBadNumberOfMonths) {
    depositCalc x;
    ASSERT_ANY_THROW(x.setNumberOfMonths(-12));
}

TEST(DepositCalc, setNumberOfDays) {
    depositCalc x;
    x.setNumberOfDays(267);
    ASSERT_EQ(267, x.getNumberOfDays());
}

TEST(DepositCalc, setBadNumberOfDays) {
    depositCalc x;
    ASSERT_ANY_THROW(x.setNumberOfDays(-20));
}

TEST(DepositCalc, setInterestRate) {
    depositCalc x;
    x.setInterestRate(8);
    ASSERT_EQ(8, x.getInterestRate());
}

TEST(DepositCalc, setBadInterestRate) {
    depositCalc x;
    ASSERT_ANY_THROW(x.setInterestRate(-12));
}

TEST(DepositCalc, setDate) {
    depositCalc x;
    ASSERT_NO_THROW(x.setDate(8, 12, 2021));
}

TEST(DepositCalc, setBadDate) {
    depositCalc x;
    ASSERT_ANY_THROW(x.setDate(-12, 13 , -1));
}

TEST(DepositCalc, setCapitalization) {
    depositCalc x;
    x.setCapitalization(2);
    ASSERT_EQ(2, x.getCapitalization());
}

TEST(DepositCalc, setBadCapitalization) {
    depositCalc x;
    ASSERT_ANY_THROW(x.setCapitalization(-3));
}

TEST(DepositCalc, calcTestNoDeposit) {
    depositCalc x;
    x.setDate(12, 07, 2021);
    x.setInterestRate(8);
    x.setNumberOfMonths(12);
    ASSERT_ANY_THROW(x.calculate());
}

TEST(DepositCalc, calcTestNoDAte) {
    depositCalc x;
    x.setDepositSum(700000);
    x.setInterestRate(8);
    x.setNumberOfMonths(12);
    ASSERT_ANY_THROW(x.calculate());
}

TEST(DepositCalc, calcTestNoInterestRate) {
    depositCalc x;
    x.setDepositSum(700000);
    x.setDate(12, 07, 2021);
    x.setNumberOfMonths(12);
    ASSERT_ANY_THROW(x.calculate());
}

TEST(DepositCalc, calcTestNoDuration) {
    depositCalc x;
    x.setDepositSum(700000);
    x.setDate(12, 07, 2021);
    x.setInterestRate(8);
    ASSERT_ANY_THROW(x.calculate());
}

TEST(DepositCalc, calcTest1) {
    depositCalc x;
    x.setDepositSum(700000);
    x.setDate(12, 07, 2021);
    x.setInterestRate(8);
    x.setNumberOfMonths(12);
    ASSERT_NO_THROW(x.calculate());
    ASSERT_EQ(756000, x.getResult());
}

TEST(DepositCalc, calcTest2) {
    depositCalc x;
    x.setDepositSum(700000);
    x.setDate(12, 07, 2021);
    x.setInterestRate(8);
    x.setNumberOfDays(93);
    ASSERT_NO_THROW(x.calculate());
    ASSERT_EQ(714268, x.getResult());
}

TEST(DepositCalc, calcTest3) {
    depositCalc x;
    x.setDepositSum(200000);
    x.setDate(31, 07, 2021);
    x.setInterestRate(4.5);
    x.setNumberOfMonths(11);
    ASSERT_NO_THROW(x.calculate());
    ASSERT_EQ(208260, x.getResult());
}

TEST(DepositCalc, calcTest4) {
    depositCalc x;
    x.setDepositSum(300000);
    x.setDate(10, 07, 2021);
    x.setInterestRate(7);
    x.setNumberOfMonths(2);
    x.setCapitalization(1);
    ASSERT_NO_THROW(x.calculate());
    ASSERT_EQ(303588, x.getResult());
}

TEST(DepositCalc, calcTest5) {
    depositCalc x;
    x.setDepositSum(750000);
    x.setDate(10, 07, 2021);
    x.setInterestRate(3);
    x.setNumberOfMonths(13);
    x.setCapitalization(3);
    ASSERT_NO_THROW(x.calculate());
    ASSERT_EQ(774781, x.getResult());
}

TEST(DepositCalc, calcTes6) {
    depositCalc x;
    x.setDepositSum(400000);
    x.setDate(10, 07, 2021);
    x.setInterestRate(5);
    x.setNumberOfMonths(4);
    x.setCapitalization(2);
    ASSERT_NO_THROW(x.calculate());
    ASSERT_EQ(406794, x.getResult());
}

TEST(DepositCalc, calcTes7) {
    depositCalc x;
    x.setDepositSum(500000);
    x.setDate(9, 06, 2021);
    x.setInterestRate(7);
    x.setNumberOfMonths(5);
    x.setCapitalization(2);
    ASSERT_NO_THROW(x.calculate());
    ASSERT_EQ(514879, x.getResult());
}

TEST(DepositCalc, calcTes8) {
    depositCalc x;
    x.setDepositSum(500000);
    x.setDate(9, 06, 2021);
    x.setInterestRate(7);
    x.setNumberOfMonths(25);
    x.setCapitalization(4);
    ASSERT_NO_THROW(x.calculate());
    ASSERT_EQ(575744, x.getResult());
}


