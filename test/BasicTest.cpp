//
// Created by ich on 1/28/20.
//

#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE "BasicTestModule"

#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(stuff) {
    assert(1 == 1);
}