// Copyright 2018 <Author>

#ifndef NODE_H_
#define NODE_H_
#include <string>

class Node {
	char ch;
	Node *Prev;
	Node *Next;
 public:
  explicit Node(char data);
  char GetData();
  Node* InsertPreviousNode(char data);
  Node* InsertNextNode(char data);
  Node* GetPreviousNode();
  Node* GetNextNode();
  bool ErasePreviousNode();
  bool EraseNextNode();
};

#endif  // NODE_H_
