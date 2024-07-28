#ifndef LIST_H
#define LIST_H

#include <iostream>

namespace dstl {
template<typename T>
class list;

// Iterator
template <typename T>
struct Node 
{
  T data;
  Node *rlink, *llink;
  Node(const T& value = T())
    : data{value}, rlink {nullptr}, llink {nullptr}{};
};

template <typename T>
class Iterator 
{
public:
  Iterator(Node<T> * p): current {p} {};

  // *, ->, 
  T& operator * () const;
  T* operator -> () const;
  // ++
  Iterator<T>& operator++();
  Iterator<T> operator++(int);
  // -- :
  Iterator<T>& operator--();
  Iterator<T> operator--(int);
  // +, -:
  Iterator<T> operator+(int);
  Iterator<T> operator-(int);
  // +=
  Iterator<T>& operator+=(int);
  // -=
  Iterator<T>& operator-=(int);
  //>, >=
  bool operator > (const Iterator& other);
  bool operator >= (const Iterator& other);
  //<, <=
  bool operator < (const Iterator& other);
  bool operator <= (const Iterator& other);
  // ==, !=
  bool operator == (const Iterator<T>& other) const;
  bool operator != (const Iterator<T>& other) const;

private:
  Node<T>* current;
  friend class list<T>;
};

template<typename T>
T& Iterator<T>::operator* () const{
  if(current== nullptr) std::cout << "null pointers dereferenced" << std::endl;
  return current->data;
};
template<typename T>
T* Iterator<T>::operator-> () const{
  return &(current->data);
};

template<typename T>
Iterator<T>& Iterator<T>::operator++()
{
  current= current->rlink;
  return *this;
}

template<typename T>
Iterator<T> Iterator<T>::operator++(int)
{
  Iterator<T> old= Iterator<T>(current);
  ++(*this);
  return old;
}

template<typename T>
bool Iterator<T>::operator==(const Iterator<T> &other) const
{
  return current == other.current;
}

template<typename T>
bool Iterator<T>::operator!=(const Iterator<T> &other) const
{
  return current != other.current;
}

template <typename T>
Iterator<T>& Iterator<T>::operator -- ()
{
  current = current->llink;
  return *this;
};

template <typename T>
Iterator<T> Iterator<T>::operator -- (int)
{
  Iterator<T> old = *this;
  --(*this);
  return old;
};

template<typename T>
Iterator<T> Iterator<T>::operator+(int increment){
  Iterator<T> it= *this;
  it += increment;
  return *this;
}

template <typename T>
Iterator<T> Iterator<T>::operator-(int decrement){
  Iterator<T> it= *this;
  it -= decrement;
  return *this;
}

template <typename T>
Iterator<T>& Iterator<T>::operator+=(int increment)
{
  for(int i = 0; i < increment; i++){
    ++(*this);
  }
  return *this;
};

template <typename T>
Iterator<T>& Iterator<T>::operator-=(int increment)
{
  for(int i = 0; i < increment; i++){
    --(*this);
  }
  return *this;
};

template <typename T>
bool Iterator<T>::operator > (const Iterator& other)
{
  return current->data > other.current->data;  
};
template <typename T>
bool Iterator<T>::operator >= (const Iterator& other)
{
  return current->data >= other.current->data;  
};
template <typename T>
bool Iterator<T>::operator < (const Iterator& other)
{
  return current->data < other.current->data;  
};
template <typename T>
bool Iterator<T>::operator <= (const Iterator& other)
{
  return current->data <= other.current->data;  
};

// Const Iterator
template<typename T>
class ConstIterator
{
public:
  ConstIterator (Node<T>* pos);
  
  //*, ->
  const T& operator * () const;
  const T* operator -> () const;
  //==, !=
  bool operator == (const ConstIterator<T>& other) const;
  bool operator != (const ConstIterator<T>& other) const;
  //++
  ConstIterator<T>& operator ++ ();
  ConstIterator<T> operator ++ (int);
  //--
  ConstIterator<T>& operator -- ();
  ConstIterator<T> operator -- (int);
  // +, -
  ConstIterator<T> operator + (int); 
  ConstIterator<T> operator - (int); 
  // +=
  ConstIterator<T>& operator+=(int);
  // -=
  ConstIterator<T>& operator-=(int);
  //>, >=
  bool operator > (const ConstIterator& other);
  bool operator >= (const ConstIterator& other);
  //<, <=
  bool operator < (const ConstIterator& other);
  bool operator <= (const ConstIterator& other);

private:
  Node<T>* current;
  friend class list<T>;
};

template<typename T>
const T& ConstIterator<T>::operator* () const{
  return current->data;
};

template<typename T>
ConstIterator<T>::ConstIterator(Node<T>* pos): current(pos){}

template<typename T>
const T* ConstIterator<T>::operator-> () const{
  return &(current->data);
};

template<typename T>
ConstIterator<T>& ConstIterator<T>::operator++()
{
  current = current->rlink;
  return *this;
}

template<typename T>
ConstIterator<T> ConstIterator<T>::operator++(int)
{
  ConstIterator<T> old = ConstIterator<T>(current);
  current = current->rlink;
  return old;
}

template<typename T>
bool ConstIterator<T>::operator==(const ConstIterator<T> &other) const
{
  return current == other.current;
}
template<typename T>
bool ConstIterator<T>::operator!=(const ConstIterator<T> &other) const
{
  return current != other.current;
}

template <typename T>
ConstIterator<T>& ConstIterator<T>::operator -- ()
{
  current= current->llink;
  return *this;
};

template <typename T>
ConstIterator<T> ConstIterator<T>::operator -- (int)
{
  ConstIterator<T> old = *this;
  ++(*this);
  return old;
};

template<typename T>
ConstIterator<T> ConstIterator<T>::operator+(int increment){
  ConstIterator<T> it = *this;
  it+=increment;
  return this;
}

template <typename T>
ConstIterator<T> ConstIterator<T>::operator-(int decrement){
  ConstIterator<T> it = *this;
  it-=decrement;
  return this;
}

template <typename T>
ConstIterator<T>& ConstIterator<T>::operator+=(int increment)
{
  for(int i = 0; i < increment; i++){
    ++(*this);
  }
  return *this;
};

template <typename T>
ConstIterator<T>& ConstIterator<T>::operator-=(int decrement)
{
  for(int i=0; i<decrement; i++){
    --(*this);
  }
  return *this;
};

template <typename T>
bool ConstIterator<T>::operator > (const ConstIterator& other)
{
  return current->data > other.current->data;
};
template <typename T>
bool ConstIterator<T>::operator >= (const ConstIterator& other)
{
  return current->data >= other.current->data;
};
template <typename T>
bool ConstIterator<T>::operator < (const ConstIterator& other)
{
  return current->data < other.current->data;  
};
template <typename T>
bool ConstIterator<T>::operator <= (const ConstIterator& other)
{
  return current->data <= other.current->data;
};


template<typename T>
class list
{
public:

  using iterator = Iterator<T>;
  using const_iterator = ConstIterator<T>;

  //Default
  list(): count(0), first(nullptr), last(nullptr){};
  //Copy
  list(const list<T>&);
  //Construct from list
  list(std::initializer_list<T> init);
  //Assignment
  list<T>& operator = (const list<T>& other);
  //Move
  list(list<T> && other);

  //Accessors
  std::size_t size() const; 
  bool empty() const;

  T& front();
  const T& front() const;

  T& back();
  const T& back() const;

  //Mutators
  void push_front(const T& value);
  void push_back(const T& value);
  void pop_front();
  void pop_back();
  void clear();

  iterator insert(iterator position, const T& value);
  iterator erase(iterator position);

  //Iterators
  iterator begin();
  iterator end();
  const_iterator begin() const;
  const_iterator end() const;

  //Destructor
  ~list();
  
private:
  std::size_t count;
  Node<T>* first;
  Node<T>* last;
};



template <typename T>
list<T>::list(const list<T>& other): list()
{
  for(auto p=other.begin(); p!= other.end(); p++){
    push_back(*p);
  }
};

template <typename T>
list<T>::list(std::initializer_list<T> init): list()
{
  for(auto p=init.begin(); p!=init.end(); p++){
    push_back(*p);
  }
}

template <typename T>
list<T>& list<T>::operator=(const list<T> &other)
{
  list<T>::iterator src = other.begin();
  list<T>::iterator dist = begin();

  for(; src != other.end() and dist != end(); src++, dist++){
    *dist = *src; 
  }
  
  for(; src != other.end(); src++){
    push_back(*src);
  }

  while(size() > other.size()) {
    pop_back();
  }

}

template <typename T>
typename list<T>::iterator list<T>::begin(){
  return iterator(first);
}

template <typename T>
typename list<T>::iterator list<T>::end(){
  return iterator(nullptr);
}

template <typename T>
typename list<T>::const_iterator  list<T>::begin() const
{
  return ConstIterator<T>(first);
};

template <typename T>
typename list<T>::const_iterator list<T>::end() const
{
  return ConstIterator<T>(nullptr);
};

template<typename T>
std::size_t list<T>::size() const
{
  return count;
};

template<typename T>
bool list<T>::empty() const
{
  return size() == 0;
};

template <typename T>
T& list<T>::front() {
  return first->data;
}
template <typename T>
const T& list<T>::front() const
{
  return first->data;
}

template <typename T>
T& list<T>::back() 
{
  return last->data;
}
template <typename T>
const T& list<T>::back() const 
{
  return last->data;
}

template <typename T> 
void list<T>::push_front(const T& value)
{
  insert(begin(), value);
}

template <typename T> 
void list<T>::push_back(const T& value)
{
  insert(end(), value);
}

template <typename T> 
void list<T>::pop_front()
{
  erase(begin());
}

template <typename  T>
void list<T>::pop_back()
{
  erase(iterator(last));
}

template<typename T>
typename list<T>::iterator list<T>::insert(iterator pos, const T &value)
{
  Node<T> * new_node = new Node<T>(value);
  new_node->rlink = pos.current;
  if(pos.current== nullptr) 
    new_node->llink = last;
  else 
    new_node->llink = pos.current->llink;
  if (new_node->rlink != nullptr) {
    new_node->rlink->llink = new_node;
  }
  if(new_node->llink != nullptr) {
    new_node->llink->rlink = new_node;
  }
  if(pos == begin()) {first = new_node;}
  if(pos == end()) {last = new_node;}
  ++count;
  return iterator(new_node);
}

template<typename T>
typename list<T>::iterator list<T>::erase(iterator pos)
{
  iterator result(pos.current->rlink);
  if(pos == begin()){
    first = first->rlink;
  } else {
    pos.current->llink->rlink = pos.current->rlink;
  }

  if(pos == iterator(last)){
    last = last->llink;
  } else {
    pos.current->rlink->llink = pos.current->llink;
  }

  if(first != nullptr)
  {
    first->llink = last->rlink = nullptr;
  }
  --count;
  return result;
}

template<typename T>
void list<T>::clear()
{
  first = last = nullptr;
  count = 0;
}

template<typename T>
list<T>::~list()
{
  while(first != nullptr){
    Node<T> * todelete= first;
    first = first->rlink;
    delete  todelete;
  }
}

//here
template<typename T>
std::ostream& operator << (std::ostream& out, const list<T>& list)
{
  out << "[ ";
  ConstIterator<T> it = list.begin();
  while(it != list.end()){
    out << *it;
    ++it;
    if(it != list.end()){
      std::cout << ", "; 
    }
  }
  out << " ]"; 
  return out;
};

template <typename T>
list<T>::list(list<T>  && other): first{other.first}, last{other.last}, size {other.size}
{
  other.first = nullptr;
  other.last = nullptr;
  other.size = 0;
}

// int main(int argc, char * argv[])
// {
//   list<int> list;
//   list.push_front(2);
//   list.push_front(1);
//   list.push_back(20);
//   list.push_back(20);
//   list.push_back(20);
//   std::cout << list << "\n";
// }
}
#endif