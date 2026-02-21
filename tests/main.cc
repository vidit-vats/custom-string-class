#include <custom_string/string.hpp>
#include <iostream>

int main() {
    custom_string::my_string s1("vidit");
    custom_string::my_string s2("vats");
    // custom_string::my_string s3;

    // s3 = s1 + s2;

    // operator<<(std::cout,s3);
    // std::cout<<s3<<std::endl;
    // std::cout<<s1<<std::endl;

    std::cout<<s1[2];
    s1[2] = 'A';
    std::cout<<s1[2];
    std::cout<<std::endl;
    std::cout<<s1<<std::endl;
    return 0;
}