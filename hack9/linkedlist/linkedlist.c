#include<stdio.h>
#include<stdlib.h>
#include"linkedlist.h"

Node* first=NULL;

void add(int x){
  Node* temp=(Node*)malloc(sizeof(Node));
  temp->data=x;
  temp->next=NULL;

  if(first==NULL){
    first=temp;
  }
  /* Stack like implementation
  else{
    temp->next=first;
    first=temp;
  }*/
  /* Queue like implementation */
  else{
    Node* ptr=first;
    while(ptr->next!=NULL){
      ptr=ptr->next;
    }
    ptr->next=temp;
  }
}

void traverse(){
  Node* ptr=first;
  while(ptr!=NULL){
    printf("%d ", ptr->data);
    ptr=ptr->next;
  }
  printf("\n");
}
