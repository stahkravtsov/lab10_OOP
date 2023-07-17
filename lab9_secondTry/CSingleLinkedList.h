#ifndef CSINGLELINCEDLIST_H
#define CSINGLELINCEDLIST_H

#include <iostream>
#include <string>
#include <vector>
#include <forward_list>
#include <algorithm>
#include <numeric>
#include "CListNode.h"
#include "CListNode.cpp"
#include "CSingleLinkedList.h"


template <class T>
class CSingleLinkedList {
  std::forward_list<T> m_start;
  int m_count;
public:
  CSingleLinkedList();

  CSingleLinkedList(const CSingleLinkedList<T>& other);

  ~CSingleLinkedList();

  void addToStart(const T& data);

  void addToEnd(const T& data);

  void removeLast(void);

  void removeFirst(void);

  void removeAll(void);

  void reverse(void);

  const T& getFirst(void) const;

  const T& getLast(void) const;

  const T& getMax(void) const;

  const T& getMin(void) const;

  const T& getAvg(void) const;

  int getCount(void) const;

  std::vector<T> getVector(void);

  template <class T>
  friend std::ostream& operator<<(std::ostream& out, const CSingleLinkedList<T>& data);

  template <class T>
  friend std::istream& operator>>(std::istream& in, CSingleLinkedList<T>& data);

  template <class T>
  friend CSingleLinkedList<T>& operator+(CSingleLinkedList<T>& first, CSingleLinkedList<T>& second);
  
  template <class T>
  friend CSingleLinkedList<T>& operator+=(CSingleLinkedList<T>& first, T& second);
    
  template <class T>
  friend CSingleLinkedList<T>& operator-=(CSingleLinkedList<T>& first, T& second);
      
  template <class T>
  friend CSingleLinkedList<T>& operator*=(CSingleLinkedList<T>& first, T& second);

  template <class T>
  friend CSingleLinkedList<T>& operator-(CSingleLinkedList<T>& first, CSingleLinkedList<T>& second);

  CSingleLinkedList<T>& operator=(const CSingleLinkedList<T>& other);

  bool operator==(const CSingleLinkedList<T>& other);

  T& operator[](unsigned int i);

};

#endif // !CSINGLELINCEDLIST_H
