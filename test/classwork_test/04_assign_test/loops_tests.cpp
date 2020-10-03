#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "catch.hpp"
#include "loops.h"

TEST_CASE("Verify Test Configuration", "verification") {
    REQUIRE(true == true);
}

TEST_CASE("Test factorial") {
    REQUIRE(factorial(3));
    REQUIRE(factorial(4));
    REQUIRE(factorial(5));
}
