#ifndef TREENODE_TPP
#define TREENODE_TPP
#include<iostream>
#include"BaseNode.h"
#include"TreeNode.h"
using namespace std;
template <typename T>
TreeNode<T>::TreeNode(T VALUE) :BaseNode<T>(VALUE) {
	//touple = 0;
	//left_right = 1;
	left = nullptr;
	right = nullptr;
	parent = nullptr;
}
template <typename T> 
TreeNode<T>::~TreeNode() {
	if (left != nullptr)
		delete left;
	if (right != nullptr)
		delete right;
	cout << endl << this->getdata() << "->Removed | ";
}
template <typename T>
void TreeNode<T>::printInfo()const {
	cout << "| " << this->getdata() << " |";
}

template <typename T>
TreeNode<T>* TreeNode<T>::getleft(void) {
	return left;
}
template <typename T>
void TreeNode<T>::SetLeft(TreeNode<T>* node) {
	left = node;
}
template <typename T>
TreeNode<T>* TreeNode<T>::getright(void) {
	return right;
}
template <typename T>
void TreeNode<T>::SetRight(TreeNode<T>* node) {
	right = node;
}
template <typename T>
TreeNode<T> TreeNode<T>::getparent(void) {
	return parent;
}
template <typename T>
void TreeNode<T>::SetParent(TreeNode<T>* node) {
	parent = node;
}

#endif