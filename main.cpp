#include <stdlib.h>
#include <time.h>
#include <iostream>
#include "bst.h"
using namespace std;
int main() {
  CBinaryTree<int> tree;
  srand(time(NULL));
  //Se agrega valores aleatorios al arbol y se muestra los valores en orden de insercion
  cout<<"Insercion de valores:"<<endl;
  for(int i = 0; i<10; i++){
    int n = rand()%50 + 1;
    cout<<n<<" ";
    tree.insert(n);
  }
  cout<<endl;

  cout<<"Print:"<<endl;
  tree.print(cout);

  cout<<"Recorrido preorden:"<<endl;
  tree.recorrido_preorden(cout);

  cout<<"Recorrido inorden o ascendente:"<<endl;
  tree.recorrido_inorden(cout);

  cout<<"Recorrido postorden:"<<endl;
  tree.recorrido_postorden(cout);

  cout<<"Recorrido descendente: " <<endl;
  tree.recorrido_descendente(cout);

  cout<<"Ingrese un valor para buscar: "; 
  int dato;
  cin>> dato;
  if(tree.find(dato)){
    cout<<"Se encontro el valor: " << dato<<endl;
  } else{
    cout<<"No se encontro el valor: " <<dato <<endl;
  }

  cout<<"Ingrese un valor para eliminar: ";
  int vParaEliminar;
  cin>>vParaEliminar;

  if(tree.find(vParaEliminar)){
    tree.deleteNode(vParaEliminar);
    cout<<"Se elimino el valor: "<<vParaEliminar<<endl;
  } else{
    cout<<"No se encontro el valor: " <<vParaEliminar<<endl;
  }
  cout<<"Despues de eliminar: "<<endl;
  tree.print(cout);

 return 0;
}
