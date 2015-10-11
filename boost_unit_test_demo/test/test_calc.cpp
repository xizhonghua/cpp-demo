// only one test.cpp should define this macro BOOST_TEST_DYN_LINK
#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE calc
#include <boost/test/unit_test.hpp>
#include <mylib/calc.h>

BOOST_AUTO_TEST_CASE(Calc_add)
{    
    Calc c;
    BOOST_CHECK(c.add(1,2) == 3);
    BOOST_CHECK(c.add(2,1) == 3);
}

BOOST_AUTO_TEST_CASE(Calc_sub)
{    
    Calc c;
    BOOST_CHECK(c.sub(1,2) == -1);
    BOOST_CHECK(c.sub(2,1) == 1);
}

BOOST_AUTO_TEST_CASE(Calc_mul)
{    
    Calc c;
    BOOST_CHECK(c.mul(1,2) == 2);
    BOOST_CHECK(c.mul(2,1) == 2);
    BOOST_CHECK(c.mul(2,0) == 0);
    BOOST_CHECK(c.mul(0,-1) == 0);
    BOOST_CHECK(c.mul(3,5) == 15);
}