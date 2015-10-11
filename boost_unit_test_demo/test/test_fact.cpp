#define BOOST_TEST_MODULE fact
#include <boost/test/unit_test.hpp>
#include <mylib/fact.h>

BOOST_AUTO_TEST_CASE(fact)
{    
    Fact f;
    BOOST_CHECK(f.fact(0) == 1);
    BOOST_CHECK(f.fact(1) == 1);
    BOOST_CHECK(f.fact(2) == 2);
    BOOST_CHECK(f.fact(3) == 6);
    BOOST_CHECK(f.fact(4) == 24);
    BOOST_CHECK(f.fact(5) == 120);
}