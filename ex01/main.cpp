#include "Span.hpp"
#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include <list>

void testBasicSpan()
{
    std::cout << "\n=== Basic Span Test ===\n";
    Span sp = Span(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);

    std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
    std::cout << "Longest span: " << sp.longestSpan() << std::endl;
}

void testExceptions()
{
    std::cout << "\n=== Exception Testing ===\n";

    // Test empty span
    Span emptySpan(5);
    try {
        std::cout << "Testing empty span shortestSpan(): ";
        emptySpan.shortestSpan();
        std::cout << "FAILED - Should have thrown exception\n";
    }
    catch (const std::exception &e) {
        std::cout << "OK - Exception caught: " << e.what() << std::endl;
    }

    // Test span with one element
    Span oneElemSpan(5);
    oneElemSpan.addNumber(42);
    try {
        std::cout << "Testing one-element span longestSpan(): ";
        oneElemSpan.longestSpan();
        std::cout << "FAILED - Should have thrown exception\n";
    }
    catch (const std::exception &e) {
        std::cout << "OK - Exception caught: " << e.what() << std::endl;
    }

    // Test full span
    Span fullSpan(2);
    fullSpan.addNumber(1);
    fullSpan.addNumber(2);
    try {
        std::cout << "Testing full span addNumber(): ";
        fullSpan.addNumber(3);
        std::cout << "FAILED - Should have thrown exception\n";
    }
    catch (const std::exception &e) {
        std::cout << "OK - Exception caught: " << e.what() << std::endl;
    }
}

void testAddRange()
{
    std::cout << "\n=== Add Range Test ===\n";
    Span sp = Span(10);

    // Test with vector
    std::vector<int> vec = {1, 5, 10, 15, 20};
    sp.addRange(vec.begin(), vec.end());
    std::cout << "After adding range: shortest=" << sp.shortestSpan()
              << ", longest=" << sp.longestSpan() << std::endl;

    // Add more numbers individually
    sp.addNumber(100);
    sp.addNumber(200);
    std::cout << "After adding more: shortest=" << sp.shortestSpan()
              << ", longest=" << sp.longestSpan() << std::endl;

    // Test with different container, but also adding too many for the 10 span
    std::list<int> lst = {2, 4, 6, 7};
    try {
        std::cout << "Testing addRange() with too many elements: ";
        sp.addRange(lst.begin(), lst.end());
        std::cout << "FAILED - Should have thrown exception\n";
    }
    catch (const std::exception &e) {
        std::cout << "OK - Exception caught: " << e.what() << std::endl;
    }
}

void testLargeSpan()
{
    std::cout << "\n=== Large Span Test (10,000 numbers) ===\n";

    // Create span with large capacity
    const unsigned int SIZE = 10000;
    Span largeSpan(SIZE);

    // Generate random numbers
    std::cout << "Adding " << SIZE << " random numbers..." << std::endl;
    std::vector<int> numbers;
    numbers.reserve(SIZE);

    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    for (unsigned int i = 0; i < SIZE; i++) {
        numbers.push_back(std::rand() % 1000000);
    }

    largeSpan.addRange(numbers.begin(), numbers.end());

    // Calculate spans
    clock_t begin = clock();
    unsigned int shortest = largeSpan.shortestSpan();
    unsigned int longest = largeSpan.longestSpan();
    clock_t end = clock();
    double elapsed = double(end - begin) / CLOCKS_PER_SEC;

    std::cout << "Shortest span: " << shortest << std::endl;
    std::cout << "Longest span: " << longest << std::endl;
    std::cout << "Time elapsed: " << elapsed << " seconds" << std::endl;
}

void testNegativeNumbers()
{
    std::cout << "\n=== Negative Numbers Test ===\n";
    Span sp = Span(5);
    sp.addNumber(-30);
    sp.addNumber(-5);
    sp.addNumber(10);
    sp.addNumber(20);

    std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
    std::cout << "Longest span: " << sp.longestSpan() << std::endl;
}

int main()
{
    testBasicSpan();
    testExceptions();
    testAddRange();
    testNegativeNumbers();
    testLargeSpan();

    return 0;
}
