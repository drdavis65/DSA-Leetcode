#include <stdexcept>
#include <iostream>

class min_heap 
{
private:
  vector<int> heap;
public: 
  min_heap() 
  {
    heap.push_back(0);
  }
  
  void push(int val) 
  {
    heap.push_back(val);
    int i = heap.size() - 1;

    while(heap[i] < heap[i >> 1]) 
    {
      int temp = heap[i];
      heap[i] = heap[i >> 1];
      heap[i >> 1] = temp;
      i = i >> 1;
    }
  }

  int pop() 
  {
    if(heap.size() == 1) 
    {
      return -1;
    }
    if(heap.size() == 2) 
    {
      return heap.pop();
    }
    int ret = heap[1];
    heap[1] = heap.pop();
    i = 1;
    while(2 * i < heap.size()) 
    {
      if(2 * i + 1 < heap.size() && 
        heap[2*i + 1] < heap[2*i] && 
        heap[i] > heap[2*i + 1]) 
      {
        int temp = heap[i];
        heap[i] = heap[2*i+1];
        heap[2*i+1] = temp;
        i = i * 2 + 1;
      }
      else if(heap[i] > heap[2*i])
      {
        heap[i] = heap[2*i];
        heap[2*i] = temp;
        i = i * 2;
      }
      else 
      {
        break;
      }
    }
    return ret;
  }


};
