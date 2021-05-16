#ifndef __BST_H__ //Maizo Diego
#define __BST_H__  //kevin de lama
#include <iostream>
using namespace std;

template <typename T>
class CBinaryTree
{
    struct Node
    {
      T data;//Maizo
      Node *m_pChild[2];
      Node(T &_data, Node *pLeft=nullptr, Node *pRight=nullptr)
        : data(_data)
      {   m_pChild[0] = pLeft;  m_pChild[1] = pRight;   }
      T getData()             { return data; } //Maizo
      void setData (T &_data) { data=_data; }  //Maizo
    };

    Node *m_pRoot = nullptr;
private:
    void internal_insert(Node *&rParent,T &dato);//Maizo
    void internal_print(Node *&rParent, ostream &os);
    bool internal_find(Node *&rParent, T dato);
    void internal_preorden(Node *&rParent, ostream &os);
    void internal_inorden(Node *&rParent, ostream &os);
    void internal_postorden(Node *&rParent, ostream &os);
    Node* minimoNodo(Node* rParent);
    Node* internal_deleteNode(Node *&rParent, T dato);
    void internal_descendente(Node *&rParent, ostream &os);

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
    void print(ostream &os);
    bool find(T dato);
    void recorrido_preorden(ostream &os);
    void recorrido_inorden(ostream &os);
    void recorrido_postorden(ostream &os);
    void deleteNode(T dato);
    void recorrido_descendente(ostream &os);
};

template <typename T>
void CBinaryTree<T>:: internal_insert(Node *&rParent, T &dato) // kevin de lama
{
  if(!rParent)
  {   rParent = new Node(dato);
      return;
  }
  internal_insert(rParent->m_pChild[ dato > rParent->getData() ], dato);
}

template <typename T>
void CBinaryTree<T>::print(ostream &os){
  internal_print(m_pRoot, os);
  os<<endl;
}

template <typename T>
void CBinaryTree<T>::internal_print(Node *&rParent, ostream &os){
  if(rParent){
    internal_print(rParent->m_pChild[0], os);
    os<<rParent->getData()<<" ";
    internal_print(rParent->m_pChild[1], os);
  }
}

template <typename T>
bool CBinaryTree<T>::internal_find(Node *&rParent, T dato){
  if(rParent){
    if(rParent->getData() == dato){
      return true;
    }else{
      return internal_find(rParent->m_pChild[ dato > rParent->getData()], dato);
    }
  }
  return false;
}

template <typename T>
bool CBinaryTree<T>::find(T dato){
  return internal_find(m_pRoot, dato);
}


template <typename T>
void CBinaryTree<T>::recorrido_preorden(ostream &os){
  internal_preorden(m_pRoot, os);
  os<<endl;
}

template <typename T>
void CBinaryTree<T>::internal_preorden(Node *&rParent, ostream &os){
  if(rParent){
    os<<rParent->getData()<<" ";
    internal_preorden(rParent->m_pChild[0], os);
    internal_preorden(rParent->m_pChild[1], os);
  }
}

template <typename T>
void CBinaryTree<T>::recorrido_inorden(ostream &os){
  internal_inorden(m_pRoot, os);
  os<<endl;
}

template <typename T>
void CBinaryTree<T>::internal_inorden(Node *&rParent, ostream &os){
  if(rParent){
    internal_inorden(rParent->m_pChild[0], os);
    os<<rParent->getData()<<" ";
    internal_inorden(rParent->m_pChild[1], os);
  }
}

template <typename T>
void CBinaryTree<T>::recorrido_postorden(ostream &os){
  internal_postorden(m_pRoot, os);
  os<<endl;
}

template <typename T>
void CBinaryTree<T>::internal_postorden(Node *&rParent, ostream &os){
  if(rParent){
    internal_postorden(rParent->m_pChild[0], os);
    internal_postorden(rParent->m_pChild[1], os);
    os<<rParent->getData()<<" ";
  }
}

template <typename T>
typename CBinaryTree<T>::Node* CBinaryTree<T>::internal_deleteNode(Node* &rParent, T dato){
  if(rParent == nullptr){
    return rParent;
  }

  if(dato < rParent->getData()){
    rParent->m_pChild[0] = internal_deleteNode(rParent->m_pChild[0], dato);
  } else if (dato > rParent->getData()){
    rParent->m_pChild[1] = internal_deleteNode(rParent->m_pChild[1], dato);
  } else{
    if(rParent->m_pChild[0] == nullptr && rParent->m_pChild[1] == nullptr){
      return nullptr;
    } else if(rParent->m_pChild[0] == nullptr){
      Node* temp = rParent->m_pChild[1];
      return temp;
    } else if(rParent->m_pChild[1] == nullptr){
      Node* temp = rParent->m_pChild[0];
      return temp;
    }

    Node* temp = minimoNodo(rParent->m_pChild[1]);
    T newDato = temp->getData();
    rParent->setData(newDato);
    rParent->m_pChild[1] = internal_deleteNode(rParent->m_pChild[1], dato);
  }
  return rParent;
}

template <typename T>
typename CBinaryTree<T>::Node* CBinaryTree<T>::minimoNodo(Node* rParent){
  Node* actual = rParent;
  while(actual && actual->m_pChild[0] != nullptr){
    actual = actual->m_pChild[0];
  }
  return actual;
}

template <typename T>
void CBinaryTree<T>::deleteNode(T dato){
  internal_deleteNode(m_pRoot, dato);
}

template <typename T>
void CBinaryTree<T>::recorrido_descendente(ostream &os){
  internal_descendente(m_pRoot, os);
  os<<endl;
}

template <typename T>
void CBinaryTree<T>::internal_descendente(Node *&rParent, ostream &os){
  if(rParent){
    internal_descendente(rParent->m_pChild[1], os);
    os<<rParent->getData()<<" ";
    internal_descendente(rParent->m_pChild[0], os);
  }
}

#endif //Maizo Diego  
