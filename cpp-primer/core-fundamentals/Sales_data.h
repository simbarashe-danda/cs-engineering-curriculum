#ifndef SALES_DATA_H
#define SALES_DATA_H
#include <string>
#include <iostream>
struct Sales_data
{
    std::string book_no;
    unsigned units_sold = 0;
    double revenue = 0;

    std::string isbn(void) {
        return book_no;
    }
    unsigned sold() {
        return units_sold;
    }
    void sum(Sales_data bk) {
        units_sold += bk.units_sold;
    }
};
#endif