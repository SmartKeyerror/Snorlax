
#ifndef __TEMPLATE_BASE_H__
#define __TEMPLATE_BASE_H__

#include <algorithm>
#include <iostream>


template<typename T>
inline const T& maxOfThree(const T& a, const T& b, const T& c) {
    const T& maxValue = a > b ? a : b;
    return maxValue > c ? maxValue : c;
}

template<typename T>
inline const T& maxOfTwo(const T& a, const T& b) {
    return a > b ? a : b;
}

struct Bzz {
    int score;
};

template<>
inline const Bzz& maxOfTwo(const Bzz& a, const Bzz& b) {
    return a.score > b.score ? a : b;
}

class InvisibleAllocator {};

template<typename T, typename Allocator>
class BuzVector{
private:
    Allocator allocator;
public:
    BuzVector() {
        std::cout<<"全特化"<<std::endl;
    }
};

template<typename Allocator>
class BuzVector<bool, Allocator>{
private:
    Allocator allocator;
public:
    BuzVector() {
        std::cout<<"偏特化"<<std::endl;
    }
};

#endif