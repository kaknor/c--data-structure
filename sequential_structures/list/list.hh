#include<iostream>
#include<stdexcept>
#include<cstring>

#include "exception.hh"

#define CAP_INIT_SIZE 8

class List {
  int size_ = 0;
  int cap_ = CAP_INIT_SIZE;
  int *array_;

  int* create_and_init_buffer();
 
public:
  List(): size_(0), cap_(8), array_(create_and_init_buffer()) {};

  inline int operator[](int i) const {
    return this->at(i);
  }
  
  inline int len() const {
    return this->size_;
  };
  
  int at(int i) const;
  void pushback(int n);
  void remove(int i);
};
