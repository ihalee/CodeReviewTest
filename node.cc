// Copyright 2018 <Author>

#include "node.h"

Node::Node(char data) {
	ch = data;
  return;
}

char Node::GetData() {
  return this->ch;
}

Node* Node::GetPreviousNode() {
	if (this->Prev)
		return this->Prev;
	else
		return nullptr;
}

Node* Node::GetNextNode() {

	if (this->Next)
		return this->Next;
	else
		return nullptr;
}

Node* Node::InsertPreviousNode(char data) {
	Node* P = new Node(data);
	if (this->Prev) {
		P->Prev = this->Prev;
		P->Next = this;
		(this->Prev)->Next = P;
		this->Prev = P;
	}
	else {
		this->Prev = P;
		P->Next = this;
	}
	return P;
}

Node* Node::InsertNextNode(char data) {
	Node* N = new Node(data);
	if (this->Next) {
		N->Next = this->Next;
		N->Prev = this;

		(this->Next)->Prev = N;
		this->Next = N; 
	}
	else {
		this->Next = N;
		N->Prev = this;
	}
	return N;
}

bool Node::ErasePreviousNode() {
	if (this->Prev)
	{
		Node * P = this->Prev;

		if ((this->Prev)->Prev)
		{
			((this->Prev)->Prev)->Next = this;
			this->Prev = (this->Prev)->Prev;
		}
		else
		{
			this->Prev = NULL;
		}
		delete P;

		return true;
	}
  return false;
}

bool Node::EraseNextNode() {
	if (this->Next)
	{
		Node * N = this->Next;

		if ((this->Next)->Next)
		{
			((this->Next)->Next)->Prev = this;
			this->Next = (this->Next)->Next;
		}
		else
		{
			this->Next = NULL;
		}
		delete N;

		return true;
	}
	return false;
}
