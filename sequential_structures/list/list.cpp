#define CATCH_CONFIG_MAIN
#include "../../catch.hpp"

#include<iostream>
#include<stdexcept>
#include<cstring>
#define CAP_INIT_SIZE 8

class List {
	int size_ = 0;
	int cap_ = CAP_INIT_SIZE;
	int *array_;

  int* create_and_init_buffer() {
    int* tmp = new int[this->cap_];
    for (std::size_t i = 0; i < (unsigned)this->cap_; ++i)
      tmp[i] = 0;
    return tmp;
  };
 
public:
  List(): size_(0), cap_(8), array_(create_and_init_buffer()) {};

	int len() const {
		return this->size_;
	};

	int at(int i) const {
	  // TODO: Throw empty list exception.
		if (i > this->size_)
			throw std::out_of_range("Cannot acces out of bound value.\n");
		return this->array_[i];
	};

	int operator[](int i) const {
		return this->at(i);
	}

	void pushback(int n) {
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

	void remove(int i) {
		this->size_--;
	};
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
