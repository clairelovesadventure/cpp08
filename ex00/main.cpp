#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <list>
#include <deque>

const char* NotFoundException::what() const throw() {
    return "Value not found in container";
}

template <typename T>
void printContainer(const T& container, const std::string& name) {
    std::cout << name << ": [";
    //const_iterator does not allow write like iterator
    for (typename T::const_iterator it = container.begin(); it != container.end(); ++it) {
        if (it != container.begin()) std::cout << ", ";
        std::cout << *it;
    }
    std::cout << "]" << std::endl;
}

int main() {
    std::cout << "=== Test 1: std::vector ===" << std::endl;
    std::vector<int> vec;
    for (int i = 0; i < 5; ++i) vec.push_back(i * 10);
    printContainer(vec, "vector");

    try {
        std::vector<int>::iterator it = easyfind(vec, 20);
        std::cout << "Found 20 at position: " << std::distance(vec.begin(), it) << " (value: " << *it << ")" << std::endl;
        *it = 25; // Modify the value to test non-const iterator return
        std::cout << "Modified value at position: " << *it << std::endl;
        printContainer(vec, "vector after modification");
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    try {
        std::cout << "Searching for 42..." << std::endl;
        easyfind(vec, 42);
    } catch (const std::exception& e) {
        std::cout << "Expected Exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== Test 2: const std::vector ===" << std::endl;
    const std::vector<int> constVec(vec.begin(), vec.end()); //Range Constructor
    try {
        std::vector<int>::const_iterator it = easyfind(constVec, 25);
        std::cout << "Found 25 in const vector at position: " << std::distance(constVec.begin(), it) << std::endl;
        // *it = 30; // This should fail to compile if uncommented
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    std::cout << "\n=== Test 3: std::list ===" << std::endl;
    std::list<int> lst;
    lst.push_back(1);
    lst.push_back(2);
    lst.push_back(3);
    printContainer(lst, "list");

    try {
        std::list<int>::iterator it = easyfind(lst, 1);
        std::cout << "Found 1! (value: " << *it 
              << ") at position: " << std::distance(lst.begin(), it) 
              << std::endl;    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    try {
        std::cout << "Searching for 99..." << std::endl;
        easyfind(lst, 99);
    } catch (const std::exception& e) {
        std::cout << "Expected Exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== Test 4: std::deque ===" << std::endl;
    std::deque<int> deq;
    deq.push_back(-5);
    deq.push_back(0);
    deq.push_back(5);
    printContainer(deq, "deque");

    try {
        std::deque<int>::iterator it = easyfind(deq, 0);
        std::cout << "Found 0! (value: " << *it << ")" << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    try {
        std::cout << "Searching for -10..." << std::endl;
        easyfind(deq, -10);
    } catch (const std::exception& e) {
        std::cout << "Expected Exception: " << e.what() << std::endl;
    }

    return 0;
}
