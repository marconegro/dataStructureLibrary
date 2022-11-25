//
//  List.cpp
//  List
//
//  Created by Marco Negro on 25/11/22.
//

#include "List.hpp"

struct head{
  node* next = 0x0;
};

struct node{
  int value;
  node* next = 0x0;
};

head* initializeList(){
  return new head;
}

node* initializeNode(){
  return new node;
}

node* initializeNode(int value){
  node* newNode = new node;
  newNode -> value = value;
  return newNode;
}

node* initializeNode(int value, node* next){
  node* newNode = new node;
  newNode -> value = value;
  newNode -> next = next;
  return newNode;
}

void deleteHeadList(head* headList){
  delete headList;
}

void deleteList(head* headList){
  deleteNodeFrom(headList->next);
  deleteHeadList(headList);
}

void deleteNode(node* nodeToDelete){
  delete nodeToDelete;
}

void deleteNodeFrom(node* nodeToDelete){
  if(!isLast(nodeToDelete))deleteNodeFrom(nodeToDelete->next);
  deleteNode(nodeToDelete);
}

void setQueue(node* queue){
  queue->next = 0x0;
}

bool isVoid(head* headList){
  if(headList -> next == 0x0) return true;
  else return false;
}


bool isLast(node* lastNode){
  if(lastNode -> next == 0x0) return true;
  else return false;
}

bool isEqual(node* node1, node* node2){
  if(node1 == node2) return true;
  else return false;
}
bool isEqual(int value1, node* next1, int value2, node* next2){
  if(value1 == value2 && next1 == next2) return true;
  else return false;
}

int countNode(head* headList){
  if(isVoid(headList)) return 0;
  else return countNodeFrom(headList->next);
}

int countNodeFrom(node* indexNode){
  if(isLast(indexNode)) return 1;
  else return 1 + countNodeFrom(indexNode->next);
}

node* getLastNode(head* headList){
  if(isVoid(headList)) return 0x0;
  return getLastNode(headList->next);
}

node* getLastNode(node* previusNode){
  if(isLast(previusNode)) return previusNode;
  return getLastNode(previusNode->next);
}

node* getNodeIn(head* headList, int index){
  if(isVoid(headList) || countNode(headList) > index) return 0x0;
  else return getNodeFrom(headList->next, index);
}

node* getNodeFrom(node* indexNode, int index){
  if(isLast(indexNode) && index > 0) return 0x0;
  else if(index == 0) return indexNode;
  else return getNodeFrom(indexNode->next, index-1);
}

int getIndexOf(head* headList, node* indexNode){
  return countNode(headList) - countNodeFrom(indexNode);
}

int getIndexFrom(node* indexNode1, node* indexNode2){
  return countNodeFrom(indexNode2) - countNodeFrom(indexNode1);
}

void insertNode(head* headList, node* nodeToInsert){
  if(isVoid(headList)) headList->next = nodeToInsert;
  else getLastNode(headList)->next = nodeToInsert;
}

void insertNode(head* headList, int valueToInsert){
  node* nodeToInsert = initializeNode(valueToInsert);
  insertNode(headList, nodeToInsert);
}

void insertNodeIn(head* headList, node* nodeToInsert, int position){
  if(position >= countNode(headList)) insertNode(headList, nodeToInsert);
  else{
    node* previusNode = getNodeIn(headList, position - 1);
    nodeToInsert->next = previusNode->next;
    previusNode->next = nodeToInsert;
  }
}

void insertNodeIn(head* headList, int valueToInsert, int position){
  insertNodeIn(headList, initializeNode(valueToInsert), position);
}

void mergeList(head* headList1, head* headList2){
  getLastNode(headList1)->next = headList2->next;
  deleteHeadList(headList2);
}

void removeLastNode(head* headList){
  node* actualQueue = getLastNode(headList);
  node* newQueue = getNodeIn(headList, countNode(headList)-2);
  deleteNode(actualQueue);
  setQueue(newQueue);
}

void removeNodeIn(head* headList, int index){
  if(index >= countNode(headList)) return;
  else{
    node* previusNode = getNodeIn(headList, index - 1);
    node* nodeToRemove = getNodeIn(headList, index);
    previusNode -> next = nodeToRemove -> next;
    deleteNode(nodeToRemove);
  }
}

void removeNode(head* headList, node* nodeToRemove){
  removeNodeIn(headList, getIndexOf(headList, nodeToRemove));
}
