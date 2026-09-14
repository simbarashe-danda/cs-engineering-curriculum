// ex 2.10: what are the initial values, if any, of each of the following variables?

#include <string>

std::string global_str; // empty string, constructor called
int global_int; // zero initialized
int main()
{
 int local_int; // indeterminate(garbage)
 std::string local_str; // empty string
}

// a constructor is a special member function of a class that is automatically called when an object is created.
// its purpose is to initialize the object
// buit-in types(int,double,char) no constructor exist
// class types(string, vector, user-defined classes) constructor always runs