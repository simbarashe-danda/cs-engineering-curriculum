// ex 1.4
#include <iostream>
int main(){
    std::cout << "Enter two numbers:"; // activate console output and feeds data
    std::cout << std::endl; // manipulate console output stream to flush buffer
    int n1 = 0, n2 = 0; // variables
    std::cin >> n1;
    std::cin >> n2; // inputs data to cpu
    std::cout << "The product of " << n1 << " and " << n2 << " is " << n1 * n2 << std::endl; // console output and math operation
    return 0;
}