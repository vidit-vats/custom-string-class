#pragma once

#include <cstddef>
#include <ostream>
namespace custom_string {
    class my_string {
        private:
            char *data;
            std::size_t len;

        public:
            // Constructors
            my_string();
            my_string(const char* str);
            my_string(const my_string& other);

            // Operators
            my_string& operator=(my_string other);
            my_string& operator+=(const my_string& other);
            my_string operator+(const my_string& other);
            bool operator==(const my_string& other) const;
            friend std::ostream& operator<<(std::ostream& os,const my_string& str);
            char& operator[](std::size_t index);
            char operator[](std::size_t index) const;
            
            // Functions
            void print() const;
            std::size_t length() const;
            std::size_t size() const;

            // Destructor
            ~my_string();
        };
}