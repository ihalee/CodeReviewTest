// Copyright 2018 <Author>

#include "typing_machine.h"

TypingMachine::TypingMachine() {
	return;
}

void TypingMachine::HomeKey() {

	while (this->left)
		LeftKey();

	return;
}

void TypingMachine::EndKey() {

	while (this->right)
		RightKey();

	return;
}

void TypingMachine::LeftKey() {
	if (this->left)
	{
		char ch;

		ch = (this->left)->ch;
		EraseKey();

		TypingMachine *N = new TypingMachine();
		if (this->right)
		{
			N->right = this->right;
			(this->right)->left = N;
		}

		this->right = N;

		N->ch = ch;
		N->left = this;
	}
	return;
}

void TypingMachine::RightKey() {
	if (this->right)
	{
		TypingMachine *ThisRightRight;
		char ch;
		ch = (this->right)->ch;

		//L = this->right;
		//wmemcpy(L, this->right, sizeof(int));

		if ((this->right)->right)
		{
			ThisRightRight = (this->right)->right;
			delete (this->right);

			this->right = ThisRightRight;
			ThisRightRight->left = this;
		}
		else
		{
			delete (this->right);
			this->right = NULL;
		}
		TypeKey(ch);
	}
	return;
}

bool TypingMachine::TypeKey(char key) {

	if (key < 32 || key > 126)
		return false;

	TypingMachine *Max;
	int count = 0;
	Max = this;

	while (Max)
	{
		if (Max->left == nullptr)
			break;
		Max = Max->left;
	}

	while (Max)
	{
		if (Max != this)
			count++;
		Max = Max->right;
	}
	if (count > 100)
		return false;

	TypingMachine *L = new TypingMachine();
	L->ch = key;

	if (this->left)
	{
		(this->left)->right = L;
		L->left = this->left;
		L->right = this;

		this->left = L;
	}
	else
	{
		this->left = L;
		L->right = this;
		L->left = nullptr;
	}
	return true;
}

bool TypingMachine::EraseKey() {

	TypingMachine *ThisLeftLeft;

	if (this->left)
	{
		if ((this->left)->left)
		{
			ThisLeftLeft = (this->left)->left;
			delete (this->left);
			
			ThisLeftLeft->right = this;
			this->left = ThisLeftLeft;
		}
		else
		{
			delete (this->left);
			this->left = nullptr;
		}
		return true;
	}
	else
	{
		return false;
	}
}
 
std::string TypingMachine::Print(char separator) {
	char str[256] = { 0, };

	TypingMachine *L;
	L = this;

	while (L)
	{
		if (L->left == NULL)
			break;
		L = L->left;
	}

	while (L)
	{
		sprintf(str, "%s%c", str, L->ch);
		if (L == this)
		{
			sprintf(str, "%s%c", str, separator);
		}
		L = L->right;
	}

	return str;
}
