#include "CListNode.h"
//some changes
template <class T>
CListNode<T>::CListNode(): m_next(nullptr) { }
//some more changes
template <class T>
CListNode<T>::CListNode(const T& data): m_data(data), m_next(nullptr) { }
//;laksdgf;lkjash
template <class T>
CListNode<T>::CListNode(const T& data, CListNode<T>* next): m_data(data), m_next(next) { }

template <class T>
CListNode<T>::~CListNode() { }

template <class T>
const CListNode<T>& CListNode<T>::operator=(const CListNode<T>& other) {
  m_data = other.m_data;
}

template <class T>
CListNode<T>* CListNode<T>::getNext(void) {
  return m_next;
}

template <class T>
T& CListNode<T>::getData(void) {
  return m_data;
}

template <class T>
void CListNode<T>::setNext(CListNode<T>* next) {
  m_next = next;
}
