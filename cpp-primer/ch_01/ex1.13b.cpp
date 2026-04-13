// There is a decrement operator (--) that subtracts 1 write a while that prints the numbers from ten down to zero
#include <iostream>
int main(){
    for (int val = 10; val >= 0; --val){
        std::cout << val << std::endl;
    }
    return 0;
}