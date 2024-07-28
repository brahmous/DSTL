#ifndef VECTOR_H
#define VECTOR_H

#include <algorithm>
#include <alloca.h>
#include <initializer_list>
#include <iostream>
#include <stdexcept>

namespace dstl {
template<typename T>
class vector
{
public:
  using iterator = T*;

  vector(int ec = 0, const T& i=T()); 
  vector(const vector&);
  vector(std::initializer_list<T>);

  ~vector(){delete [] data;};
  T* data;// TODO: Move to private

  vector<T>& operator = (const vector<T>& other);

  T& operator[](int index); 
  const T& operator[](int index) const; 

  T& front();
  const T& front() const;
  T& back();
  const T& back() const;

  T& at(int index);
  const T& at(int index) const;

  int size() const;
  bool empty() const;
  bool capacity() const;

  void push_back(const T& element);
  void pop_back();
  void clear();
  
  iterator begin();
  iterator end();

private:
  int allocated, occupied;
  void resize(int new_size, const T& init = T());
};

template <typename T>
int vector<T>::size() const
{
  return occupied;
};

template <typename T>
bool vector<T>::empty() const
{
  return size() == 0;
}

template <typename T>
bool vector<T>::capacity() const
{
  return allocated;
}

template<typename  T>
vector<T>::vector(int element_count, const T& init)
{
  if(element_count < 0) throw std::runtime_error("cannot create a vector of a negative number of elements!"); 
  data = new T[element_count];
  allocated = occupied = element_count;
  std::fill(data, data+occupied, init);
}

template <typename T>
vector<T>::vector(const vector<T>& other)
{
  std::cout << "here" << std::endl;
  allocated = other.allocated;
  occupied = other.occupied;
  data = new T[allocated];
  std::copy(other.data, other.data + other.occupied, data);
};

template <typename T>
vector<T>& vector<T>::operator = (const vector<T>& other)
{
  if(&other != this){
    delete [] data;
    allocated = other.allocated;
    occupied = other.occupied;
    data = new T[allocated];
    std::copy(other.data, other.data + other.occupied, data);
  }
  return *this;
};

template <typename T>
T& vector<T>::operator[](int index)
{
  return data[index];
}; 

template <typename T>
const T& vector<T>::operator[](int index) const
{
  return data[index];
};

template <typename T>
T& vector<T>::front()
{
  return data[0];
};
template <typename T>
const T& vector<T>::front() const
{
  return data[0];
};

template <typename T>
T& vector<T>::back()
{
  return data[occupied-1];
};
template <typename T>
const T& vector<T>::back() const
{
  return data[occupied-1];
};

template <typename T>
T& vector<T>::at(int index)
{
  if(index < 0 or index >= occupied)
    throw std::out_of_range("Index out of range");
  return data[index];
};
template <typename T>
const T& vector<T>::at(int index) const
{
  if(index < 0 or index >= occupied)
    throw std::out_of_range("Index out of range");
  return data[index];
};

template <typename T>
void vector<T>::push_back(const T& element)
{
  resize(occupied + 1);
  data[occupied - 1] = element;
};

template <typename T>
void vector<T>::resize(int new_size, const T& init)
{
  if(new_size > allocated){
    T *old_data = data;
    allocated = std::max(new_size, 2*allocated);
    data = new T[allocated];
    std::copy(old_data, old_data+occupied, data);
    delete [] old_data;
  }
  if(new_size > occupied){
    std::fill(data+occupied, data+new_size, init);
  }
};

template <typename T>
void vector<T>::pop_back()
{
  if(occupied > 0) 
  {
    --occupied;
  }
};

template <typename T>
void vector<T>::clear()
{
  occupied = 0;
};

template <typename T>
typename vector<T>::iterator vector<T>::begin()
{
  return data;
};

template <typename T>
typename vector<T>::iterator vector<T>::end()
{
  return data + occupied;
};

template <typename T>
std::ostream& operator << (std::ostream& out, vector<T> vec){
  out << "[ " << vec.data[0] << ", ";
  for(int i=1; i<vec.size()-1; i++){
    out << vec.data[i] << ", ";
  }
  out << vec.data[vec.size()-1] << " ]";
  return out;
}

template <typename T>
vector<T>::vector(std::initializer_list<T> elems)
{
  allocated = occupied = elems.size(); 
  data = new T[occupied];
  std::copy(elems.begin(), elems.end(), data);
};
}
#endif

