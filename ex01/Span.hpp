#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <exception>
#include <algorithm>
#include <iterator>

class Span {
private:
    unsigned int _n;
    std::vector<int> _container;

public:
    // Orthodox Canonical Form
    Span();
    Span(unsigned int n);
    Span(const Span& other);
    Span& operator=(const Span& other);
    ~Span();

    // Member functions
    void addNumber(int number);
    unsigned int shortestSpan() const;
    unsigned int longestSpan() const;

    // Template member function for adding a range of numbers
    template <typename InputIterator>
    void addNumbers(InputIterator begin, InputIterator end) {
        // Calculate the distance/number of elements to add
        typename std::iterator_traits<InputIterator>::difference_type dist = std::distance(begin, end);
        if (dist < 0) {
            throw std::invalid_argument("Invalid iterator range");
        }
        if (_container.size() + static_cast<unsigned int>(dist) > _n) {
            throw SpanFullException();
        }
        _container.insert(_container.end(), begin, end);
    }

    // Exceptions
    class SpanFullException : public std::exception {
    public:
        virtual const char* what() const throw();
    };

    class NoSpanException : public std::exception {
    public:
        virtual const char* what() const throw();
    };
};

#endif
