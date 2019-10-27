#define CATCH_CONFIG_MAIN
#include "../../catch.hpp"
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

TEST_CASE("List initialization", "[LIST-INIT]") {
  List l{};

  for (std::size_t i = 0; i < CAP_INIT_SIZE; ++i)
    REQUIRE( l[i] == 0 );
  REQUIRE( l.len() == 0 );	
  REQUIRE( l.at(0) == 0 );
  REQUIRE_THROWS_AS( l.at(12), std::out_of_range );
  REQUIRE( l[0] == 0 );
  REQUIRE_THROWS_AS( l[12], std::out_of_range );
}

TEST_CASE("Basic List tests", "[LIST]") {
  List l{};

  REQUIRE( l.len() == 0 );
	
  l.pushback(5);
  REQUIRE( l.len() == 1 );

  l.remove(0);
  REQUIRE( l.len() == 0 );
}

TEST_CASE("Pushback", "[LIST-PUSHBACK]") {
  List l{};

  REQUIRE( l.len() == 0 );
  for (std::size_t i = 0; i < 25; ++i) {
    l.pushback(i);
    REQUIRE( l.len() == i + 1 );
    REQUIRE( l[i] == i );
  }
}

TEST_CASE("List is empty", "[LIST-EMPTY-PUSHBACK]") {
  List l{};
  REQUIRE_THROWS_AS( l.at(0), EmptyListException);
}
