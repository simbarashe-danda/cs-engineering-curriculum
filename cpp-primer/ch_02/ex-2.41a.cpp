/* Ex 2.41: Use your Sales_data class to rewrite the exercises in chapter 1.5.1, and chapter 1.6.
For now, you should define your Sales_data class in the same file as your main function

chapter1.51 Ex 1.21: Write a program that reads two Sales_item objects that
have the same ISBN and produces their sum
*/
#include <string>
#include <iostream>

// define Sales_data class
struct Sales_data
{
    std::string book_number; // isbn/ book identifier
    unsigned int sold_units{0}; // number of copies sold
    double selling_price{0.0}; // price of each book
};
// main function
int main()
{
    // create a Sales_data object
    Sales_data isbn1, isbn2; // isbn1 and isbn2 are like containers of data members for Sales_data
    
    // read first transaction or ISBN input into isbn1
    // reads isbn number, copies sold and price of book
    std::cin >> isbn1.book_number >> isbn1.sold_units >> isbn1.selling_price;

    // read second transaction
    std::cin >> isbn2.book_number >> isbn2.sold_units >> isbn2.selling_price;
    
    if (isbn1.book_number == isbn2.book_number) // checks equality
    {
        // compute total copies sold
        unsigned int total_sold{isbn1.sold_units + isbn2.sold_units};
        // print the sum
        std::cout << isbn1.book_number << " has total sold copies of " << total_sold 
        << " and total revenue is $" << isbn1.selling_price * total_sold << std::endl;
    }
    else // isbn numbers don't match
    {
        std::cout << "isbn numbers don't match, books are not the same" 
        << std::endl;
    }
    return 0;
}



