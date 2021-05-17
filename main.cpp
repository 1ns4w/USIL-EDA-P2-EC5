#include <iostream>
#include "bst.h"

using namespace std;

typedef int T1;

int main()
{
  CBinaryTree<T1>(obj);

  T1 arr[] = {4, 30, 25, 20, 60, 10};

  int len = sizeof(arr)/sizeof(arr[0]);

  for (int i=0; i<len;i++) {
    obj.insert(arr[i]);
  }
  obj.printDesc();
  obj.printAsc();
}