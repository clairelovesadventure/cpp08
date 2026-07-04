#include "Span.hpp"
#include <numeric>
#include <limits>
#include <stdexcept>
#include <iostream>

Span::Span() : _n(0) {}

Span::Span(unsigned int n) : _n(n) {
    _container.reserve(n); // Optional optimization
}

Span::Span(const Span& other) : _n(other._n), _container(other._container) {}

Span& Span::operator=(const Span& other) {
    if (this != &other) {
        _n = other._n;
        _container = other._container;
    }
    return *this;
}

Span::~Span() {}

void Span::addNumber(int number) {
    if (_container.size() >= _n) {
        throw SpanFullException();
    }
    _container.push_back(number);
}

unsigned int Span::shortestSpan() const {
    if (_container.size() < 2) {
        throw NoSpanException();
    }

    std::vector<int> sorted = _container;
    std::sort(sorted.begin(), sorted.end());

    unsigned int min_span = std::numeric_limits<unsigned int>::max();
    for (size_t i = 0; i < sorted.size() - 1; ++i) {
        unsigned int span = static_cast<unsigned int>(sorted[i+1]) - static_cast<unsigned int>(sorted[i]);
        if (span < min_span) {
            min_span = span;
        }
    }
    return min_span;
}

unsigned int Span::longestSpan() const {
    if (_container.size() < 2) {
        throw NoSpanException();
    }

    std::vector<int>::const_iterator min_it = std::min_element(_container.begin(), _container.end());
    std::vector<int>::const_iterator max_it = std::max_element(_container.begin(), _container.end());

    return static_cast<unsigned int>(*max_it) - static_cast<unsigned int>(*min_it);
}

const char* Span::SpanFullException::what() const throw(){
    return "Span is full, cannot add more numbers";
}

const char* Span::NoSpanException::what() const throw() {
    return "Cannot find span: not enough elements stored";
}