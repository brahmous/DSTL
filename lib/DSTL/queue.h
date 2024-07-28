#ifndef QUEUE_H
#define QUEUE_H

#include "list.h"

namespace dstl {
template <typename T>
class queue
{
public:
    void push(const T& val);
    void pop();
    const T& front();
    const T& back();
    int size();
    bool empty();
private:
    List<T> list;
};

template <typename T>
inline void queue<T>::push(const T &val)
{
    list.push_front(val);
}

template <typename T>
inline void queue<T>::pop()
{
    list.pop_back(val);
}

template <typename T>
inline const T &queue<T>::front()
{
    return list.back();
}

template <typename T>
inline const T &queue<T>::back()
{
    return list.front();
}

template <typename T>
inline int queue<T>::size()
{
    return list.size();
}

template <typename T>
inline bool queue<T>::empty()
{
    return size() == empty;
}
}
#endif