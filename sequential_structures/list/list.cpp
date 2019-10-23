#define CATCH_CONFIG_MAIN
#include "../../catch.hpp"

#include<iostream>
#include<stdexcept>

class List {
	int size_ = 0;
	int cap_ = 8;
	int *array_;
 
public:
	List(): size_(0), cap_(8), array_(new int[this->cap_]) {};

	int len() const {
		return size_;
	};

	int at(int i) {
		if (i > this->size_)
			throw std::out_of_range("Cannot acces out of bound value.\n");
		return this->array_[i];
	};

	int operator[](int i) {
		return this->at(i);
	}

	void pushback(int n) {
		this->array_[this->size_] = n;
		this->size_++;

	};

	void remove(int i) {
		this->size_--;
	};
};

TEST_CASE("Basic List tests", "[LIST]") {
	List l{};

	REQUIRE( l.len() == 0 );
	
	l.pushback(5);
	REQUIRE( l.len() == 1 );

	l.remove(0);
	REQUIRE( l.len() == 0 );

}

TEST_CASE("List creation", "[LIST-CREATION]") {
	List l{};

	REQUIRE( l.len() == 0 );	
	REQUIRE( l.at(0) == 0 );
	REQUIRE_THROWS_AS( l.at(12), std::out_of_range );
	REQUIRE( l[0] == 0 );
	REQUIRE_THROWS_AS( l[12], std::out_of_range );
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