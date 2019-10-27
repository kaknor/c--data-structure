#define CATCH_CONFIG_MAIN
#include "../../catch.hpp"

#include "list.hh"

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
