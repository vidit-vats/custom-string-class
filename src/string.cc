#include <custom_string/string.hpp>
#include <cstring>
#include <ostream>
#include <stdexcept>
#include <utility>
#include <iostream>

namespace custom_string {
    my_string::my_string() : len(0){
        data = new char[1];
        data[0] = '\0';
    }
    
    my_string::my_string(const char* str) {
        if(!str){
            data = new char[1];
            len = 0;
            data[0] = '\0';
        }

        else{
            len = std::strlen(str);
            data = new char[len + 1];
            std::strcpy(data,str);
        }
    }

    my_string::my_string(const my_string& other) 
    : len(other.len){
            data = new char[len + 1];
            std::strcpy(data,other.data);
    }
    my_string& my_string::operator=(my_string other){
        std::swap(data, other.data);
        std::swap(len, other.len);
        return *this;
    }

    std::ostream& operator<<(std::ostream& os, const my_string& str) {
        os << str.data;
        return os;
    }

    void my_string::print() const {
            std::cout<<data<<std::endl;
    }

    std::size_t my_string::length() const {
        return len;
    }

    std::size_t my_string::size() const{
        return len;
    }

    my_string& my_string::operator+=(const my_string& other){
        size_t l1 = len;
        size_t l2 = other.len;

        char *appended_string = new char[l1 + l2 + 1];

        size_t i;

        for(i = 0; i < l1; i++)
            appended_string[i] = data[i];
        for(size_t j = 0; j < l2; j++)
            appended_string[i + j] = other.data[j];

        appended_string[l1 + l2] = '\0';

        delete[] data;

        data = appended_string;
        len = l1 + l2;

        return *this;
    }

    my_string my_string::operator+ (const my_string& other){
        // invoking copy constructor
        my_string temp(*this);

        temp += other;
        return temp;
    }

    bool my_string::operator==(const my_string& other) const{
        if(other.len != len)
            return false;

        // this is case when both are same in length
        for(size_t i = 0; i < other.len; i++ )
            if(data[i] != other.data[i])
                return false;
        
        return true;
    }

    char& my_string::operator[](size_t index){
        if(index >= len)
            throw std::out_of_range("Index Out of Bounds");
        return data[index];
    }

    char my_string::operator[](size_t index) const{
        if(index >= len)
            throw std::out_of_range("Index Out of Bounds");
        return data[index];
    }

    my_string :: ~my_string(){
        delete[] data;
    }
}