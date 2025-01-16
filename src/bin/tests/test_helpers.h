#ifndef TEST_HELPERS_H
#define TEST_HELPERS_H

#include <iostream>
#include <string>

#define test_assert(exp, func, msg) do { \
    if (!(exp)) { \
        std::cerr << "Test failed in " << func << ": " << msg << std::endl; \
    } else { \
        std::cout << "Test passed in " << func << ": " << msg << std::endl; \
    } \
} while (false)

#endif // TEST_HELPERS_H