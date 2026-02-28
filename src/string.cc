#include <algorithm>
#include <cstring>
#include <custom_string/string.hpp>
#include <iostream>
#include <ostream>
#include <stdexcept>
#include <utility>

namespace custom_string {
my_string::my_string() : len(0) {
  data = new char[1];
  data[0] = '\0';
}

my_string::my_string(const char *str) {
  if (!str) {
    data = new char[1];
    len = 0;
    data[0] = '\0';
  }

  else {
    len = std::strlen(str);
    data = new char[len + 1];
    std::strcpy(data, str);
  }
}

my_string::my_string(const my_string &other) : len(other.len) {
  data = new char[len + 1];
  std::strcpy(data, other.data);
}

my_string &my_string::operator=(my_string other) {
  std::swap(data, other.data);
  std::swap(len, other.len);
  return *this;
}

std::ostream &operator<<(std::ostream &os, const my_string &str) {
  os << str.data;
  return os;
}

void my_string::print() const { std::cout << data << std::endl; }

std::size_t my_string::length() const { return len; }

std::size_t my_string::size() const { return len; }

my_string &my_string::operator+=(const my_string &other) {
  size_t l1 = len;
  size_t l2 = other.len;

  char *appended_string = new char[l1 + l2 + 1];

  size_t i;

  for (i = 0; i < l1; i++)
    appended_string[i] = data[i];
  for (size_t j = 0; j < l2; j++)
    appended_string[i + j] = other.data[j];

  appended_string[l1 + l2] = '\0';

  delete[] data;

  data = appended_string;
  len = l1 + l2;

  return *this;
}

my_string my_string::operator+(const my_string &other) {
  // invoking copy constructor
  my_string temp(*this);

  temp += other;
  return temp;
}

bool my_string::operator==(const my_string &other) const {
  if (other.len != len)
    return false;

  // this is case when both are same in length
  for (size_t i = 0; i < other.len; i++)
    if (data[i] != other.data[i])
      return false;

  return true;
}

bool my_string::operator!=(const my_string &other) const {
  return !(*this == other);
}

char &my_string::operator[](size_t index) {
  if (index >= len)
    throw std::out_of_range("Index Out of Bounds");
  return data[index];
}

char my_string::operator[](size_t index) const {
  if (index >= len)
    throw std::out_of_range("Index Out of Bounds");
  return data[index];
}

bool my_string::operator<(const my_string &other) const {
  size_t minimum_length = std::min(len, other.len);

  for (size_t i = 0; i < minimum_length; i++)
    if (data[i] < other.data[i])
      return true;
    else if (data[i] > other.data[i])
      return false;

  return len < other.len;
}

bool my_string::operator>(const my_string &other) const {
  return other < *this;
}

bool my_string::operator>=(const my_string &other) const {
  return *this > other or * this == other;
}

bool my_string::operator<=(const my_string &other) const {
  return *this < other or * this == other;
}

bool my_string::empty() const { return len == 0 ? true : false; }

char my_string::front_char() const {
  if (empty())
    throw std::out_of_range("my_string::front_char(): empty string");

  return data[0];
}

char my_string::back_char() const {
  if (empty())
    throw std::out_of_range("my_string::back_char(): empty string");

  return data[len - 1];
}

my_string my_string::substring(size_t start,size_t cnt) const {
  if(start > len)
    throw std::out_of_range("my_string::substr() Out of Bounds Index Supplied");

  if(start == len)
    return my_string();

  size_t remaining_chars = len - start;
  cnt = std::min(remaining_chars,cnt);

  char *temp_str = new char[cnt + 1];


  for(size_t i = 0; i < cnt; i++)
    temp_str[i] = data[start + i];
  temp_str[cnt] = '\0';
    
  my_string new_res(temp_str);
  
  delete[]temp_str;
  return new_res;
}

my_string ::~my_string() { delete[] data; }
} // namespace custom_string