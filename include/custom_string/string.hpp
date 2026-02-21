#pragma once

#include <cstddef>
namespace custom_string {
    class my_string {
        private:
            char *data;
            std::size_t len;

        public:
            my_string();
            my_string(const char* str);
            my_string(const my_string& other);
            my_string& operator=(my_string other);
            my_string& operator+=(const my_string& other);
            my_string operator+(const my_string& other);

            ~my_string();

            void print() const;
            std::size_t length() const;
            std::size_t size() const;
        };
}