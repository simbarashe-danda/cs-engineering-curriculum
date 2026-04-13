// ex1.5
#include <iostream>
int main(){
    std::cout << "Enter two numbers:"; // activate console output and feeds data
    std::cout << std::endl; // manipulate console output stream to flush buffer
    int n1 = 0, n2 = 0; // variables
    std::cin >> n1;
    std::cin >> n2; // inputs data to cpu
    std::cout << "The sum of ";
    std::cout << n1;
    std::cout << " and ";
    std::cout << n2;
    std::cout << " is ";
    std::cout << n1 + n2; // math operation
    std::cout << std::endl;
    return 0;
}