#ifndef STACK_H
#define STACK_H

#include <vector>
#include <stdexcept>

// Use inheritance from std::vector (choose public/private) as appropriate
template <typename T>
class Stack : private std::vector<T>
{
public:
    Stack();
    ~Stack();
    //done
    bool empty() const;
    //d
    size_t size() const;
    //d
    void push(const T& item);
    //d
    void pop();  // throws std::underflow_error if empty
    const T& top() const; // throws std::underflow_error if empty
    // Add other members only if necessary
};
template <typename T>
Stack<T>::Stack() : std::vector<T>(){
}

template <typename T>
Stack<T>::~Stack(){}

template <typename T>
bool Stack<T>::empty() const{
  if(std::vector::size() == 0){
    return false;
  }
}
template <typename T>
size)_t Stack<T>::size() const{
  return std::vector::size();
}
template <typename T>
void Stack<T>::push(const T& item){
  std::vector<T>::push_back(item);
}
template <typename T>
 void Stack<T>::pop(){
   if(this->empty()){
     throw std::underflow_error("Stack is empty!")
   }
   else{
     std::vector<T>::pop();
   }
 }
template <typename T>
const T& Stack<T>::top() const{
  if(this->empty()){
    throw std::underflow_error("Stack is empty!")
  }
  else{
    return std::vector<T>::at(0);
  }
}

#endif