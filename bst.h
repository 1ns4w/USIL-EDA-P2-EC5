#ifndef __BST_H__ //Maizo Diego
#define __BST_H__  //kevin de lama

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
    void printAsc() {
      cout << "Ascendente:\n";
      print(m_pRoot, true);
    }
    void printDesc() {
      cout << "Descendente:\n";
      print(m_pRoot, false);
    }
private:
    void internal_insert(Node *&rParent, T &dato);//Maizo
    void print(Node *&parent, bool asc = true) {
      // Node *current = &parent;
      int index = asc ? 0 : 1;
      if (parent->m_pChild[index] != nullptr) {
          print(parent->m_pChild[index], asc);
        }
        cout << parent->getData() << "\n";
        index = asc ? 1 : 0;
        if (parent->m_pChild[index] != nullptr) {
          print(parent->m_pChild[index], asc);
        }
    }
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
#endif //Maizo Diego  