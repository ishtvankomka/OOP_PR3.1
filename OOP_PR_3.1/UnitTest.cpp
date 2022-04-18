#define CATCH_CONFIG_MAIN
#include "catch.h"
#include "RightAngled.cpp"
#include "RightAngled.hpp"
#include "Triangle.cpp"
#include "Triangle.hpp"

TEST_CASE( "Arguments initialized") {
    Triangle t1(3, 4, 5);
    Triangle t2(5, 5, 5);
    Triangle t3(10, 8, 6);

    REQUIRE( t1.perimeter() == 12);
    REQUIRE( t2.perimeter() == 15);
    REQUIRE( t3.perimeter() == 24);
}
