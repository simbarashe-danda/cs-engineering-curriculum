/*Exercise 1.22: Write a program that reads several transactions for the same ISBN.
 Write the sum of all the transactions that were read. */

 #include <string>
 #include <iostream>
 // Sales_data class from ex-2.41a
 struct Sales_data
{
    std::string book_number; // isbn/ book identifier
    unsigned int sold_units = 0; // number of copies sold
    double selling_price = 0.0; // price of each book
};

int main()
{
    Sales_data isbn1, isbn2; // define Sales_data objects

    // read the first transaction number input
    // if there is input i.e isbn1
    if (std::cin >> isbn1.book_number >> isbn1.sold_units >> isbn1.selling_price)
    {
        // while there are transaction number inputs
        while (std::cin >> isbn2.book_number >> isbn2.sold_units >> isbn2.selling_price)
        {
            if (isbn1.book_number == isbn2.book_number) // check book number match
            {
                isbn1.sold_units += isbn2.sold_units; // if book numbers match, sum the  number of sold copies
            }
            else // if book numbers don't match
            {
                std::cout << isbn1.book_number << " has total sold copies of " << isbn1.sold_units
                << " and total revenue of $" << isbn1.sold_units * isbn1.selling_price << std::endl;
                
                isbn1.book_number = isbn2.book_number; // update new fixed book number
                isbn1.sold_units = isbn2.sold_units; // reset sum
                isbn1.selling_price = isbn2.selling_price; // update new selling price
            }
        }
        // total copies sold for last count because else{} only prints when two book numbers don't match
        // this time we print when the while loop has exhausted all inputs
        std::cout << isbn1.book_number << " has total sold copies of " << isbn1.sold_units
        << " and total revenue of $" << isbn1.sold_units * isbn1.selling_price << std::endl;

        return 0;
    }
    else // error, no input
    {
        std::cerr << "No transaction inputs" << std::endl;
        return -1;
    }
    
    }

/* MY NOTE: This program works best assuming the user has grouped transactions according to their isbn number similarity
 The program doesn't have the ability to scan all isbn numbers and group according to simialarity and compute the sum
 The program can only compare the input sequence

 this also assumes same isbn means same price */
