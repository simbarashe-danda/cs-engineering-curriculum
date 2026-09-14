/*Exercise 3.36: Write a program to compare two arrays for equality.
Write a similar program to compare two vectors.*/

#include <iostream>
using std::cout, std::endl;

#include <iterator>
using std::begin, std::end;

#include <vector>
using std::vector;

int main()
{
// comparing two arrays like:
// if (arr == arr2)
// is wrong it compares pointers to first element not the array

    int arry[] = {0,2,4,6,8};  // array with 5 elements of type int
    int* start = begin(arry);  // pointer to first element
    int* stop = end(arry);   // off-end pointer
    auto diff = stop - start;
    const auto last_indx = diff - 1; // last index of the array

    int arry2[] = {0,2,4,6,8}; // array with 5 elements
    int *start2 = begin(arry2);    // first element pointer
    int* stop2 = end(arry2);   // off-end pointer
    auto diff2 = stop2 - start2;
    const auto last_indx2 = diff2 - 1; // last index of the array

    size_t cnt = 0; // count tracking
    

    while(start != stop && start < stop)
    {
        if (last_indx != last_indx2)     // if number of elements not equal
        {
            cout << "Not equal" << endl;
            return 0; // terminate
        }
        else // numbers of elements equal
        {
            if (arry[last_indx] != arry2[last_indx2])  // if last elements not equal
            {
                cout << "Not equal!" << endl;
                return 0; // immidiately terminate
            }
            else // meaning ends are equal
            {
                if (*start != *start2)  // current index equality
                {
                    cout << "Not equal!!" << endl;
                    return 0;   // terminate immidiately
                }

                // this clearly implies if the last index elements are equal , then the arrays are equal
                else if (++cnt == last_indx && *start == *start2)
                {
                    cout << "The arrays are equal" << endl;
                }
            }
        }
        ++start;
        ++start2;

    }

// Write a similar program to compare two vectors.
    vector<int> vec{0,2,4,6,8};
    vector<int> vec2{0,2,4,6,8};

    if (vec != vec2)    // check inequality
    {
        cout << "The two vectors not are equal" << endl;
    }
    else{   // else they are equal
        cout << "The two vectors are equal" << endl;
    }

}






