#include "MutantStack.hpp"
#include <iostream>
#include <list>
#include <vector>

void runSubjectTest() {
    std::cout << "=== Subject Test with MutantStack ===" << std::endl;
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    std::cout << mstack.top() << std::endl;
    mstack.pop();
    std::cout << mstack.size() << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    //[...]
    mstack.push(0);
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }
    std::stack<int> s(mstack);
}

void runSubjectListTest() {
    std::cout << "\n=== Subject Test with std::list (for comparison) ===" << std::endl;
    std::list<int> mlist;
    mlist.push_back(5);
    mlist.push_back(17);
    std::cout << mlist.back() << std::endl;
    mlist.pop_back();
    std::cout << mlist.size() << std::endl;
    mlist.push_back(3);
    mlist.push_back(5);
    mlist.push_back(737);
    //[...]
    mlist.push_back(0);
    std::list<int>::iterator it = mlist.begin();
    std::list<int>::iterator ite = mlist.end();
    ++it;
    --it;
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }
}

void runAdditionalTests() {
    std::cout << "\n=== Additional Iterator Tests (Const & Reverse) ===" << std::endl;
    MutantStack<int> mstack;
    mstack.push(10);
    mstack.push(20);
    mstack.push(30);

    // Test const_iterator
    const MutantStack<int>& constStack = mstack;
    std::cout << "Const stack elements: ";
    for (MutantStack<int>::const_iterator cit = constStack.begin(); cit != constStack.end(); ++cit) {
        std::cout << *cit << " ";
    }
    std::cout << std::endl;

    // Test reverse_iterator
    std::cout << "Stack elements in reverse: ";
    for (MutantStack<int>::reverse_iterator rit = mstack.rbegin(); rit != mstack.rend(); ++rit) {
        std::cout << *rit << " ";
    }
    std::cout << std::endl;

    // Test const_reverse_iterator
    std::cout << "Const stack elements in reverse: ";
    for (MutantStack<int>::const_reverse_iterator crit = constStack.rbegin(); crit != constStack.rend(); ++crit) {
        std::cout << *crit << " ";
    }
    std::cout << std::endl;

    // Test with list as the underlying container
    std::cout << "\n=== MutantStack with std::list container ===" << std::endl;
    MutantStack<char, std::list<char> > charStack;
    charStack.push('A');
    charStack.push('B');
    charStack.push('C');
    
    std::cout << "Char stack elements: ";
    for (MutantStack<char, std::list<char> >::iterator it = charStack.begin(); it != charStack.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    // Test with vector as the underlying container
    std::cout << "\n=== MutantStack with std::vector container ===" << std::endl;
    MutantStack<double, std::vector<double> > doubleStack;
    doubleStack.push(1.1);
    doubleStack.push(2.2);
    doubleStack.push(3.3);
    
    std::cout << "Double stack elements: ";
    for (MutantStack<double, std::vector<double> >::iterator it = doubleStack.begin(); it != doubleStack.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

int main() {
    runSubjectTest();
    runSubjectListTest();
    runAdditionalTests();
    return 0;
}
