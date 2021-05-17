#ifndef __BST_H__ //Maizo Diego
#define __BST_H__  //kevin de lama
#include <iostream>
#include <algorithm>
#include <string.h>
int main()
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
private:
    void internal_insert(Node *&rParent,const T &dato);//Maizo
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
{
    int matrix[12][12];
    std::generate(matrix, matrix + 12*12,
                  [](){ return 2*(rand() % 256+1); });
    auto min_max =std::minmax_element(matrix, matrix + 12*12);
    std::cout << *min_max.first << ", " << *min_max.second << std::endl;
}
struct ordenamiento
    {int elem ;
    };
void leerarray(int,struct ordenamiento []);
void burbuja (int,struct ordenamiento []);
void muestra (int,struct ordenamiento []);
void main()
{
    int n;
    struct ordenamiento ordenada [MAX];
    cout <<"limite de arreglo:";
    cin>>n;
    leerarray (n,ordenada);
    burbuja (n,ordenada);
    cout<< endl << "arreglo ordenado: " << endl;
    muestra(n,ordenada);
    getch();
}
void leerarray(int n,struct ordenamiento a [])
{for (int i=0;i<n;i++)
}
cout<<"elemento" <<i<<":";
cin>>a[i].elem;
}
void burbuja (int n,struct ordenamiento a [])
{
    int i,j;
    struct ordenamiento temp;
    for(i=1;i<n;i++)
    for(j=n-1;j>=i;j--)
        if(a[j-1].elem>a[j].elem)
        {
            temp=a[j-1];
            a[j-1]=a[j];
            a[j]=temp;
        }
 void muestra(int n,struct ordenamiento a[])
 {
     for(int i=0;<n;i++)
         cout<<" " <<a[i].elem;
 }       
#endif //Maizo Diego  
