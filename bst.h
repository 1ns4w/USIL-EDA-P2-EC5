  
#ifndef __BST_H__
#define __BST_H__ 
#include <iostream>
using namespace std;

//jose terrones

template <typename T>
class CBinaryTree
{
    struct Node
    {
      T data;
      Node *m_pChild[2];
      Node(T &_data, Node *pLeft=nullptr, Node *pRight=nullptr)
        : data(_data)
      {   m_pChild[0] = pLeft;  m_pChild[1] = pRight;   }
      T getData()             { return data; } 
      void setData (T &_data) { data=_data; }  
    };

    Node *m_pRoot = nullptr;
public:
    CBinaryTree() {}
    void insert_old(const T &dato)
    {   
        Node **ppNode = &m_pRoot;
        while(*ppNode != nullptr)      
        { if(dato > (*ppNode)->getData())
            ppNode = &ppNode->m_pChild[1];
          else
            ppNode = &ppNode->m_pChild[0];
        }
        *ppNode = new Node(dato);
    }
    void insert(T &dato)
    {   internal_insert(m_pRoot, dato);   }

    void menor_a_mayor()
    {   void recorrer(Node *&Reference1);  }

    void mayor_a_menor()
    {   void recorrer_inverso(Node *&Reference2);   }

private:
    void internal_insert(Node *&rParent);
    void recorrer(Node *&Reference1);
    void recorrer_inverso(Node *&Reference2);
};

template <typename T>
void CBinaryTree<T>:: internal_insert(Node *&rParent, T &dato) 
{
  if(!rParent)
  {   rParent = new Node(dato);
      return;
  }
  internal_insert(rParent->m_pChild[ dato > rParent->getData() ], dato);
}

template <typename T>
void CBinaryTree<T>:: recorrer(Node *&Reference1)
{
  if (m_pRoot!=nullptr)
  {
    if(!Reference1)
    {   
      Reference1 = new Node;
      return;
    }
    recorrer(Reference1->m_pChild[0]);
    cout<<Reference1->getData();
    recorrer(Reference1->m_pChild[1]);
  }

}

template <typename T>
void CBinaryTree<T>:: recorrer_inverso(Node *&Reference2)
{
  if (m_pRoot!=nullptr)
  {
    if(!Reference2)
    {   
      Reference2 = new Node;
      return;
    }
    recorrer_inverso(Reference2->m_pChild[1]);
    cout<<Reference2->getData();
    recorrer_inverso(Reference2->m_pChild[0]);
  }
}
#endif 
