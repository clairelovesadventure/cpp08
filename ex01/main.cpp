#include "Span.hpp"
#include <iostream>
#include <vector>
#include <list>
#include <cstdlib>
#include <ctime>

void runSubjectTest() {
    std::cout << "=== Subject Test ===" << std::endl;
    Span sp = Span(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    std::cout << "Shortest span: " << sp.shortestSpan() << " (Expected: 2)" << std::endl;
    std::cout << "Longest span:  " << sp.longestSpan() << " (Expected: 14)" << std::endl;
}

void runExceptionTests() {
    std::cout << "\n=== Exception Tests ===" << std::endl;
    Span sp(2);
    
    // Test span on empty
    try {
        sp.shortestSpan();
    } catch (const std::exception& e) {
        std::cout << "Caught expected: " << e.what() << std::endl;
    }

    // Test span on 1 element
    sp.addNumber(42);
    try {
        sp.longestSpan();
    } catch (const std::exception& e) {
        std::cout << "Caught expected: " << e.what() << std::endl;
    }

    // Test adding when full
    sp.addNumber(84);
    try {
        sp.addNumber(100);
    } catch (const std::exception& e) {
        std::cout << "Caught expected: " << e.what() << std::endl;
    }
}

void runRangeTests() {
    std::cout << "\n=== Range Addition Tests ===" << std::endl;
    std::vector<int> vec;
    vec.push_back(100);
    vec.push_back(200);
    vec.push_back(150);
    vec.push_back(50);

    Span sp(10);
    sp.addNumber(10);
    
    // Add elements from vector range
    sp.addNumbers(vec.begin(), vec.end());

    std::cout << "Shortest span: " << sp.shortestSpan() << " (Expected: 40, distance between 10 and 50)" << std::endl;
    std::cout << "Longest span:  " << sp.longestSpan() << " (Expected: 190, distance between 10 and 200)" << std::endl;

    // Test range addition overflow
    std::list<int> lst;
    for (int i = 0; i < 10; ++i) lst.push_back(i);
    try {
        sp.addNumbers(lst.begin(), lst.end());
    } catch (const std::exception& e) {
        std::cout << "Caught expected (range overflow): " << e.what() << std::endl;
    }
}

void runOrthodoxCanonicalTests() {
    std::cout << "\n=== Orthodox Canonical Form Tests ===" << std::endl;
    Span sp1(5);
    sp1.addNumber(1);
    sp1.addNumber(10);
    sp1.addNumber(100);

    // Test copy constructor
    Span sp2(sp1);
    std::cout << "Copy constructor - Shortest: " << sp2.shortestSpan() << " (Expected: 9)" << std::endl;
    std::cout << "Copy constructor - Longest:  " << sp2.longestSpan() << " (Expected: 99)" << std::endl;

    // Test assignment operator
    Span sp3(2);
    sp3 = sp1;
    std::cout << "Assignment operator - Shortest: " << sp3.shortestSpan() << " (Expected: 9)" << std::endl;
    std::cout << "Assignment operator - Longest:  " << sp3.longestSpan() << " (Expected: 99)" << std::endl;

    // Verify they are independent copies
    sp1.addNumber(1000);
    try {
        // sp2 should still have capacity to add numbers, and its span shouldn't change
        sp2.addNumber(2000);
        std::cout << "sp2 updated independently. sp2 longest: " << sp2.longestSpan() << " (Expected: 1999)" << std::endl;
        std::cout << "sp3 longest (unchanged): " << sp3.longestSpan() << " (Expected: 99)" << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Unexpected error: " << e.what() << std::endl;
    }
}

void runLargeTest() {
    std::cout << "\n=== Large Dataset Test (20,000 elements) ===" << std::endl;
    unsigned int size = 20000;
    Span sp(size);

    std::vector<int> randNumbers;
    randNumbers.reserve(size);

    std::srand(std::time(NULL));
    for (unsigned int i = 0; i < size; ++i) {
        randNumbers.push_back(std::rand());
    }

    try {
        sp.addNumbers(randNumbers.begin(), randNumbers.end());
        std::cout << "Successfully added " << size << " numbers!" << std::endl;
        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span:  " << sp.longestSpan() << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Error during large test: " << e.what() << std::endl;
    }
}

int main() {
    runSubjectTest();
    runExceptionTests();
    runRangeTests();
    runOrthodoxCanonicalTests();
    runLargeTest();
    return 0;
}
