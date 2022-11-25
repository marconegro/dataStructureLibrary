//
//  List.hpp
//  List
//
//  Created by Marco Negro on 25/11/22.
//

#ifndef List_hpp
#define List_hpp

struct head;
struct node;

head* initializeList();
node* initializeNode();
node* initializeNode(int value);
node* initializeNode(int value, node* next);


void deleteHeadList(head* headList);
void deleteList(head* headList);
void deleteNode(node* nodeToDelete);
void deleteNodeFrom(node* nodeToDelete);

void setQueue(node* queue);

bool isVoid(head* headList);
bool isLast(node* lastNode);
bool isEqual(node* node1, node* node2);
bool isEqual(int value1, node* next1, int value2, node* next2);

int countNode(head* headList);
int countNodeFrom(node* indexNode);

node* getLastNode(head* headList);
node* getLastNode(node* previusNode);

node* getNodeIn(head* headList, int index);
node* getNodeFrom(node* indexNode, int index);

int getIndexOf(head* headList, node* indexNode);

void insertNode(head* headList, node* nodeToInsert);
void insertNode(head* headList, int valueToInsert);

void insertNodeIn(head* headList, node* nodeToInsert, int position);
void insertNodeIn(head* headList, int valueToInsert, int position);

void mergeList(head* headList1, head* headList2);

void removeLastNode(head* headList);
void removeNodeIn(head* headList, int index);
void removeNode(head* headList, node* nodeToRemove);

#endif
