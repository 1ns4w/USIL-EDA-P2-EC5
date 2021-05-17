#include <iostream>
#include<stdio.h>

int main()
{
  int i,j,aux,c,vector[c];
  i=1;
  j=1; 
  aux=0;
  printf("Cantida de numeros: ");
  scanf("%i" ,&c);
  printf("Escribe los numero: \n");
  for (i=1;i<=c;i++){
	printf("%i numero: ",i);
	scanf("%i",&vector[i]);
}
  
 
 for(i=0;i<c ;i++){
   for(j=i+1;j<=c;j++){
     if(vector[i]>vector[j]){
       aux=vector[i];
       vector[i]=vector[j];
       vector[j]=aux;
   }
 }
}
  printf("\n Numeros ordenados: \n");
for (i=1;i<=c;i++){
  printf("&i|" ,vector[i]);
} 
  return 0;
}
