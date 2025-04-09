#include <stdexcept>
#include <iostream>

template<typename T>
class min_heap {
private:
  T* heap;
  int capacity;
  int size;

public: 
  min_heap() {
    capacity = 32;
    heap = new T[capacity];
    size = 0;
  }
  
  ~min_heap() { 
    delete[] heap;
  }


};
