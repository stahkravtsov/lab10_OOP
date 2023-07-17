#ifndef CLISTNODE_H
#define CLISTNODE_H

template <class T>
class CListNode {
  T m_data;
  CListNode* m_next;
public:
  CListNode();

  CListNode(const T& data);

  CListNode(const T& data, CListNode<T>* next);

  ~CListNode();

  const CListNode<T>& operator=(const CListNode& other);

  CListNode<T>* getNext(void);

  T& getData(void);

  void setNext(CListNode<T>* next);

};

#endif // !CLISTNODE_H
