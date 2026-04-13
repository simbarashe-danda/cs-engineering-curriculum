/*Ex 2.42: Write your own version of the Sales_data.h*/

#ifndef SALES_DATA_H
#define SALES_DATA_H
#include <string>
struct Sales_data
{
    std::string book_no;
    unsigned int sold_copies = 0; 
    double book_price = 0.0;
    double revenue = 0.0;
    double avg_price = 0.0;  
};
#endif
