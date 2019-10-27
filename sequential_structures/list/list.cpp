
#include "list.hh"

int* List::create_and_init_buffer() {
  int* tmp = new int[this->cap_];
  for (std::size_t i = 0; i < (unsigned)this->cap_; ++i)
    tmp[i] = 0;
  return tmp;
};

int List::at(int i) const {
  if (this->size_ == 0)
    throw EmptyListException("Cannot access content of an empty list.\n");
  if (i > this->size_)
    throw std::out_of_range("Cannot acces out of bound value.\n");
    
  return this->array_[i];
};

void List::pushback(int n) {
  this->array_[this->size_] = n;
  this->size_++;
  if (this->size_ == this->cap_) {
    int* tmp = new int[this->cap_ * 2];
    std::memcpy(tmp, this->array_, this->cap_ * sizeof(int));
    this->cap_ *= 2;
    delete[] this->array_;
    this->array_ = tmp;
  }  

};

void List::remove(int i) {
  this->size_--;
};

