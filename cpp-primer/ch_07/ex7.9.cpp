/* Exercise 7.9: Add operations to read and print Person objects to the code
you wrote for the exercises in § 7.1.2 */

#include <string>
#include <istream>
#include <ostream>
struct Person
{
    std::string my_name;
    std::string location;

    /* const for both, we dont want to modify (this) */
    std::string name(void) const {return my_name;} 
    std::string address(void) const {return location;}

    /* declarations */
    std::istream& read(std::istream&, Person);
    std::ostream& print(std::ostream&, const Person);

};

std::istream& Person::read(std::istream& in, Person p) {
    in >> p.my_name >> p.location;
}
std::ostream& Person::print(std::ostream& out, const Person p) {
    out << "Name: " << p.my_name << "\tAdress: " << p.location << " ";
}