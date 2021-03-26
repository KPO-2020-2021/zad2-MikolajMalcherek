#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "./doctest/doctest.h"
#include "LZespolona.hh"

TEST_CASE("test LZespolona Suma"){
    LZespolona x, y, z;

    x.re = 1;
    x.im = 1;

    y.re = 1;
    y.im = -3;

    z.re = 2;
    z.im = -2;
    
    CHECK(x+y == z);
}

TEST_CASE("LZespolona - wyswietlanie zaokraglane"){
    LZespolona x;
    x.re = 2.0/9.0;
    x.im = 2.0/9.0;

    std::ostringstream out;

    out << x;
    CHECK( "(0.22+0.22i)" == out.str() );
}

TEST_CASE("LZespolona - wczytywanie standard"){
    LZespolona x;

    std::istringstream in("(25.00+13.10i)");
    in >> x;
    std::ostringstream out;
    out << x;

    CHECK( "(25.00+13.10i)" == out.str() );
}