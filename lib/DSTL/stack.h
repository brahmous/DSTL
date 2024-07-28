#ifndef STACK_H
#define STACK_H

#include "list.h"

namespace dstl {
template <typename T>
class stack
{
private:
    list<T> list;
    /* data */
public:
    void push(const T& val);
    void pop();
    void top();
    int size();
    bool empty();
};

template <typename T>
inline void stack<T>::push(const T &val)
{
    list.push_back(val);
}

template <typename T>
inline void stack<T>::pop()
{
    // TODO: Check if empty.
    list.pop_back();
}

template <typename T>
inline void stack<T>::top()
{
    // TODO: check if empty.
    return list.back();
}

template <typename T>
inline int stack<T>::size()
{
    return list.size();
}

template <typename T>
inline bool stack<T>::empty()
{
    return size() == 0;
}
}
#endif