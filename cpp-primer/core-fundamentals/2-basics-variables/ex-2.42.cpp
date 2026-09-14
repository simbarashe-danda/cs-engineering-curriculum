

/* Exercise 2.42: Write your own version of the Sales_data.h header and use it to rewrite the exercise from chapter 2.6.2
Ex Section 2.6.2, Ex 2.41: Write a program that reads several transactions for the same ISBN.
Write the sum of all the transactions that were read
*/

#include <iostream>
#include "Sales_data.h"
int main()
{
    // define Sales_data objects that hold data for isbn number/ transaction
    Sales_data book1, book2;

    // if there is a transaction input
    if (std::cin >> book1.book_no >> book1.sold_copies >> book1.book_price)
    {
        book1.revenue = book1.book_price * book1.sold_copies; // revenue of first transaction
        book1.avg_price = book1.revenue / book1.sold_copies; // average price of first book input

        // loop that checks runs as long as there are transaction inputs
        while (std::cin >> book2.book_no >> book2.sold_copies >> book2.book_price)
        {
            book2.revenue = book2.book_price * book2.sold_copies; // revenue of second book input
        
            // if book numbers match
            if (book1.book_no == book2.book_no)
            {
                book1.sold_copies += book2.sold_copies; // sum the sold copies
                book1.book_price += book2.book_price; // sum price of books
                book1.revenue += book2.revenue; // sum revenues of the books
                book1.avg_price = book1.revenue / book1.sold_copies; // average price all of the books

            }
            else // if book numbers don't match
            {
                // print total sold copies, total revenue, average book price
                std::cout << " \n The book " << book1.book_no << " has a total sold copies of " << book1.sold_copies
                << " and average book price of $" << book1.avg_price
                << " and total revenue of $" << book1.revenue << " \n" << std::endl;

                book1.book_no = book2.book_no; // update book number
                book1.sold_copies = book2.sold_copies; // reset the accumulated total sold copies
                book1.book_price = book2.book_price; // reset and update book price
                book1.revenue = book1.book_price * book1.sold_copies; // reset revenue
                book1.avg_price = book1.revenue / book1.sold_copies; // reset average price
            }
        }
        // the else statement only prints if book numbers don't match
        // but if there nolonger transaction inputs, there's no book2 to compare but we still need to print the sum
        std::cout <<" \n The book " << book1.book_no << " has a total sold copies of " << book1.sold_copies
        << " and average book price of $" << book1.avg_price
        << " and total revenue of $" << book1.revenue << "\n" << std::endl;

        return 0; // program success
    }

    else // if there is no transaction input for the first time
    {
        std::cerr << "No input!!! " << std::endl;
        return -1; // program failure
    }
}
// this program assumes transactions/ book numbers are sorted/grouped according to similarity and then inputed
// the program only checks book numbers according to the input sequence
