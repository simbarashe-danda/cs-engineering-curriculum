/* Exercise 7.2: Add the combine and isbn members to the Sales_data class you wrote for the exercises in § 2.6.2 */

#include <string>
struct Sales_data
{
    std::string book_no;
    unsigned units_sold = 0;
    double revenue = 0;

    std::string isbn(void) const {return book_no;}
    Sales_data& combine(const Sales_data& bk) {
        units_sold += bk.units_sold;
        revenue += bk.revenue;
        return *this;
    }
};

#include <iostream>
using std::cin;
using std::cout, std::endl, std::cerr;
/* Exercise 7.3: Revise your transaction-processing program from § 7.1.1 to use these members.*/
int main()
{
    Sales_data total;

    if (cin >> total.book_no >> total.units_sold >> total.revenue) {
        Sales_data trans;
        // read and process
        while (cin >> trans.book_no >> trans.units_sold >> trans.revenue) {
            if (total.isbn() == trans.isbn())
                total.combine(trans); // update the running total
            else {
                // previous book
                cout << "book " << total.isbn() << " has sold  " 
                << total.units_sold << endl;
                total = trans; // total now refers to the next book
            }
        }
    cout << "book " << total.isbn() << " has sold "
    << total.units_sold << std::endl; // print the last transaction
    }
    else {
        // no input
        cerr << "No data?!" << endl;
        return -1; // indicate failure
    }
    return 0;
}