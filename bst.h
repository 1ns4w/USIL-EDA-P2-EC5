#ifndef __BST_H__ //Maizo Diego
#define __BST_H__  //kevin de lama
#include<conio.h>
#include<string.h>

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
    struct node
  {
   int n;
   struct node*sgte;
   };
   typedef struct node*Tlista;
   void inserta(Tlista &,int);
   void eliminar_inicio(Tlista &);
   void eliminar_fin(Tlista &);
   void eliminar_elemento(Tlista &,int);
   void eliminar_lista(Tlista &);
   void media(Tlista );
   void busqueda(Tlista, int);
   void eliminarepetidos(Tlista &);
   void unelista(Tlista &,Tlista &,Tlista &);
   void mayorlista(Tlista );
   void menorlista(Tlista);
   void eliminarpares(Tlista &);
   void numerosprimos(Tlista);
   void ordenaburbuja(Tlista);
   void imprimeinver(Tlista);
   void imprimir(Tlista);
    void imprimir(Tlista lista)
 {
  if(lista==NULL)
  cout<<"ingresa elementos";
  while(lista!=NULL)
  {
   cout<<lista->n<<endl;
   lista=lista->sgte;
   }
   cout<<endl;
   }
void imprimeinver(Tlista lista)
{
 int x[20],k=0;
 if(lista!=NULL)
 cout<<"lista vacia, ingrese elementos";
 while(lista!=NULL)
 {
  lista=lista->sgte;
   x[k]=lista->n;
    for(int i=0;i>=0;i--)
    cout<<x[i];
    }
    }
void inserta(Tlista &lista,int k)
 {
  int i;
  Tlista q;
  for(i=0;i<k;i++)
   {
    q=new(struct node);
    cout<<"nt ELEMENTO ["<<i<<"] :";
    cin>>q->n;
    q->sgte=lista;
    lista=q;
    }
    }
void eliminar_inicio(Tlista &lista)
 {
  struct node*p;
  if(lista!=NULL)
    {
     p=lista;
     lista=lista->sgte;
     delete(p);
     }
     }
void eliminar_fin(Tlista &lista)
  {
   Tlista p,ant;
   if(lista==NULL) return;
   p=lista;
   if(lista->sgte==NULL)
   lista=lista->sgte;
   else
   {
   while(p->sgte!=NULL)
   {
   ant=p;
   p=p->sgte;
   }
   ant->sgte=NULL;
   }
   delete(p);
  }
void eliminar_elemento(Tlista &lista,int valor)
  {
   Tlista p,ant;
   p=lista;
  while(p!=NULL)
  {
  if(p->n==valor)
  {
  if(p==lista)
  lista=lista->sgte;
  else
  ant->sgte=p->sgte;
  delete(p);
  return;
  }
  ant=p;
  p=p->sgte;
  }
  }
void elimina_lista(Tlista &lista)
  {
  Tlista p;
  while(lista!=NULL)
  {
  p=lista;
  lista=lista->sgte;
  delete(p);
  }
  }
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
#endif //Maizo Diego  
