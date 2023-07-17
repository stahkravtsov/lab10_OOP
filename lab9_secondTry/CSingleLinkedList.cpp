#include "CSingleLinkedList.h"
#include <numeric>

template <class T>
CSingleLinkedList<T>::CSingleLinkedList(): m_count(0) {}

template <class T>
CSingleLinkedList<T>::CSingleLinkedList(const CSingleLinkedList<T>& other) {
  m_start = other.m_start;
}

template <class T>
CSingleLinkedList<T>::~CSingleLinkedList() {
  this->removeAll();
}

template <class T>
void CSingleLinkedList<T>::addToStart(const T& data) {
  m_start.insert_after(m_start.before_begin(), data);
  m_count++;
}

template <class T>
void CSingleLinkedList<T>::addToEnd(const T& data) {
  m_count++;
  auto t = m_start.begin();
  auto tTemp = t;
  while(t != m_start.end()) {
    tTemp = t;
    t++;
  }
  if(tTemp == m_start.end()) {
    m_start.emplace_front(data);
  } else {
    m_start.emplace_after(tTemp, data);
  }


}

template <class T>
void CSingleLinkedList<T>::removeFirst(void) {
  if(m_count == 0) throw "removeFirst: List are empty";
  m_start.pop_front();
  m_count--;
}

template <class T>
void CSingleLinkedList<T>::removeLast(void) {
  if(m_count == 0) throw "removeFirst: List are empty";
  m_count--;
  auto t = m_start.before_begin();
  for(int i = 0; i < m_count; i++) t++;
  m_start.erase_after(t);
}

template <class T>
void CSingleLinkedList<T>::removeAll(void) {
  m_start.clear();
  m_count = 0;
}

template <class T>
void CSingleLinkedList<T>::reverse(void) {
  m_start.reverse();
}

template <class T>
const T& CSingleLinkedList<T>::getMax(void) const {
  if(m_count == 0) throw "getMax: List are empty";
  return *std::max_element(m_start.begin(), m_start.end());
}

template <class T>
const T& CSingleLinkedList<T>::getMin(void) const {
  if(m_count == 0) throw "getMin: List are empty";
  return *std::min_element(m_start.begin(), m_start.end());
}

template <class T>
int CSingleLinkedList<T>::getCount(void) const {
  return m_count;
}

template <class T>
std::vector<T> CSingleLinkedList<T>::getVector(void) {
  std::vector<T> v;
  for(auto& i : m_start) {
    v.push_back(i);
  }
  return v;
}

template <class T>
const T& CSingleLinkedList<T>::getFirst(void) const {
  if(m_count == 0) throw "getFirst: List are empty";
  return m_start.front();
}

template <class T>
const T& CSingleLinkedList<T>::getLast(void) const {
  if(m_count == 0) throw "getLast: List are empty";
  auto t = m_start.begin();
  auto tTemp = t;
  while(t != m_start.end()) {
    tTemp = t;
    t++;
  }
  return *tTemp;
}

template <class T>
const T& CSingleLinkedList<T>::getAvg(void) const {
  if(m_count == 0) {
    std::cerr << "{" << m_count << "}\n";
    throw "getAvg: List are empty";
  }

  T sum(std::reduce(m_start.begin(), m_start.end()));
  return sum / m_count;
}

template <class T>
std::ostream& operator<<(std::ostream& out, const CSingleLinkedList<T>& data) {
  for(auto& i : data.m_start) {
    out << i << " ";
  }
  return out;
}

template <class T>
std::istream& operator>>(std::istream& in, CSingleLinkedList<T>& data) {
  try {
    char next;
    next = in.peek();
    T temp;
    while(next != '\n') {
      in >> temp;
      // std::cout << temp << std::endl;
      data.addToEnd(temp);
      next = in.peek();
    }
  }
  catch(const std::exception& exc) {
    std::cout << exc.what() << std::endl;
  }
  return in;
}

template <class T>
CSingleLinkedList<T>& operator+(CSingleLinkedList<T>& first, CSingleLinkedList<T>& second) {
  if(first.m_count != second.m_count) throw "the list must have equal size";
  CSingleLinkedList<T>* temp = new CSingleLinkedList<T>;
  auto i = first.m_start.begin();
  auto j = second.m_start.begin();

  while(i != first.m_start.end() && j != second.m_start.end()) {
    temp->addToEnd(( *i ) + ( *j ));
    i++;
    j++;
  }

  return *temp;
}

template <class T>
CSingleLinkedList<T>& operator-(CSingleLinkedList<T>& first, CSingleLinkedList<T>& second) {
  if(first.m_count != second.m_count) throw "the list must have equal size";

  std::transform(first.m_start.cbegin(), first.m_start.cend(), first.m_start.begin(), [](T& i, T k) { i *= k; });

  CSingleLinkedList<T>* temp = new CSingleLinkedList<T>;
  for(int i = 0; i < first.m_count; i++) {
    temp->addToEnd(first.m_start[i] - second.m_start[i]);
  }
  return *temp;
}

template <class T>
CSingleLinkedList<T>& operator*=(CSingleLinkedList<T>& first, T& second) {
  std::transform(first.m_start.begin(), first.m_start.end(), first.m_start.begin(), [&second](T& i) { return i *= second; });
  return first;
}

template <class T>
CSingleLinkedList<T>& operator-=(CSingleLinkedList<T>& first, T& second) {
  std::transform(first.m_start.begin(), first.m_start.end(), first.m_start.begin(), [&second](T& i) { return i -= second; });

  return first;
}

template <class T>
CSingleLinkedList<T>& operator+=(CSingleLinkedList<T>& first, T& second) {
  std::transform(first.m_start.begin(), first.m_start.end(), first.m_start.begin(), [&second](T& i) {  return i += second; });

  return first;
}

template <class T>
CSingleLinkedList<T>& CSingleLinkedList<T>::operator=(const CSingleLinkedList<T>& other) {
  this->removeAll();
  m_start = other.m_start;
  return *this;
}

template <class T>
bool CSingleLinkedList<T>::operator==(const CSingleLinkedList<T>& other) {
  if(m_count != other.m_count) return 0;
  auto it = other.m_start.begin();
  for(auto& i : m_start) {
    if(*it != i) return 0;
    it++;
  }
  return 1;
}

template <class T>
T& CSingleLinkedList<T>::operator[](unsigned int i) {
  if(i > m_count) throw "index incorrect";
  auto it = m_start.begin();
  for(int j = 0; j < i; j++) it++;
  return *it;
}

