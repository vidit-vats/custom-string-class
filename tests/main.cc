#include <custom_string/string.hpp>
#include <iostream>

int main() {
    custom_string::my_string s1("vidit");
    custom_string::my_string s2("vats");
    custom_string::my_string s3;

    s3 = s1 + s2;

    s1.print();
    s2.print();
    s3.print();

    std::cout<<s1.length()<<std::endl;
    std::cout<<s1.size()<<std::endl;

    return 0;
}