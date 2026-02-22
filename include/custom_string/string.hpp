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
            bool operator!=(const my_string& other) const;
            friend std::ostream& operator<<(std::ostream& os,const my_string& str);

            // below modifies the index too
            char& operator[](std::size_t index);
            // below is for read-only purpose
            char operator[](std::size_t index) const;

            bool operator<(const my_string& other) const;
            bool operator>(const my_string& other) const;
            bool operator>=(const my_string& other) const;
            bool operator<=(const my_string& other) const;

            // Functions
            void print() const;
            std::size_t length() const;
            std::size_t size() const;
            // Read-Only access for front and back
            // That's why no support of char&
            char front_char() const;
            char back_char() const;
            bool empty() const;

            // Destructor
            ~my_string();
        };
}