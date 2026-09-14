/* from Exercise 7.15 */
/* Update your Person class to hide its implementation.*/

#include <string>
#include <istream>
#include <ostream>

class Person
{
    private:
        std::string my_name;
        std::string location;
        unsigned age = 0;

    public:
        /* constructor */
        Person() = default;
        Person(const std::string& nm, const std::string& lc) :
            my_name(nm), location(lc) {} // newly born baby
        Person(const std::string& nm, const std::string lc,  unsigned ag) :
            my_name(nm), location(lc), age(ag) {}
        Person(std::istream&);

        /* const for both, we dont want to modify (this) */
        std::string name(void) const {return my_name;} 
        std::string address(void) const {return location;}

        /* declaration */
        std::ostream& print(std::ostream&) const;
    };

/* istream constructor def */
Person::Person(std::istream& in) {
    in >> this->my_name >> this->location >> this->age; 
}

std::ostream& Person::print(std::ostream& out) const {
    if ((this->my_name).empty()) {out << "No info!\n"; return out; }
    out << "Name: " << this->my_name << "\tAdress: " << this->location << "\tAge: " << this->age << "\n";
    return out;
}

/* use and testing  */
#include <iostream>
int main()
{
    Person john; // default initialization
    Person mark("mark", "zurich"); // baby
    Person viktor(std::cin);
    Person jack("jack", "zim", 20);

    john.print(std::cout);
    mark.print(std::cout);
    viktor.print(std::cout);
    jack.print(std::cout);
    
    std::cout << jack.name() << std::endl;
}