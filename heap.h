#ifndef HEAP_H
#define HEAP_H
#include <functional>
#include <stdexcept>
#include <vector>

template <typename T, typename PComparator = std::less<T> >
class Heap
{
public:
  /**
   * @brief Construct a new Heap object
   * 
   * @param m ary-ness of heap tree (default to 2)
   * @param c binary predicate function/functor that takes two items
   *          as an argument and returns a bool if the first argument has
   *          priority over the second.
   */
  Heap(int m=2, PComparator c = PComparator());

  /**
  * @brief Destroy the Heap object
  * 
  */
  ~Heap();

  /**
   * @brief Push an item to the heap
   * 
   * @param item item to heap
   */
  void push(const T& item);

  /**
   * @brief Returns the top (priority) item
   * 
   * @return T const& top priority item
   * @throw std::underflow_error if the heap is empty
   */
  T const & top() const;

  /**
   * @brief Remove the top priority item
   * 
   * @throw std::underflow_error if the heap is empty
   */
  void pop();

  /// returns true if the heap is empty

  /**
   * @brief Returns true if the heap is empty
   * 
   */
  bool empty() const;

    /**
   * @brief Returns size of the heap
   * 
   */
  size_t size() const;

private:
  std::vector<T> heapUsed;
  int mAry;
  PComparator comp;
  void heapify(int indx);
  void trickleUp(int loc);
};

//Non default heap of binary tree
template <typename T, typename PComparator> 
Heap<T,PComparator>::Heap(int m, PComparator c){
  mAry= m;
  comp = c;
}

template <typename T, typename PComparator>
Heap<T,PComparator>::~Heap(){}

template<typename T, typename PComparator>
void Heap<T,PComparator>::heapify(int indx){
  int value = indx;
  int bestValue = indx;
//iterate through possible child nodes
  for(int i =1;i <= mAry;i++){
    //possible child 
    unsigned int loc = mAry*indx+i;
    if(loc < heapUsed.size() && comp(heapUsed[loc], heapUsed[value])){
      value = loc;
      if(comp(heapUsed[value], heapUsed[bestValue])){
        bestValue = value;
      }
    }
  }

  if(bestValue != indx){
    std::swap(heapUsed[indx], heapUsed[bestValue]);
    heapify(bestValue);
  }
}

template<typename T, typename PComparator>
void Heap<T,PComparator>::trickleUp(int loc){
  //General form for finding parent
  int parent = (loc-1)/mAry;
  
  if(comp(heapUsed[loc], heapUsed[parent])){
    std::swap(heapUsed[loc],heapUsed[parent]);
    trickleUp(parent);
  }

  //code used from CSCI104 slides, swapping until in correct place
  while(parent >= 1 && comp(heapUsed[loc], heapUsed[parent])){
    std::swap(heapUsed[loc],heapUsed[parent]);
    loc = parent;
    parent = (loc-1)/mAry;
  }

}
template <typename T, typename PComparator>
void Heap<T, PComparator>::push(const T& item){
  //code used from CSCI104 slides, push item and maintain heap property
  heapUsed.push_back(item);
  trickleUp(heapUsed.size()-1);
}

template <typename T, typename PComparator>
size_t Heap<T,PComparator>::size() const{
  return (heapUsed.size());
}


template <typename T, typename PComparator>
bool Heap<T,PComparator>::empty() const{
  if(heapUsed.size() == 0){
    return true;
  }
  else{
    return false;
  }
}
// We will start top() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
T const & Heap<T,PComparator>::top() const
{
  // Here we use exceptions to handle the case of trying
  // to access the top element of an empty heap
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
    throw std::underflow_error("Heap is empty!");
  }
  //top item is at 0-index
  return heapUsed[0];
}


// We will start pop() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
void Heap<T,PComparator>::pop()
{
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
  throw std::underflow_error("Heap is empty!");
  }
  //code used from CSCI104 slides, last item in vector to top, retain heap property
  heapUsed[0] = heapUsed.back();
  heapUsed.pop_back();
  heapify(0);
}

#endif

