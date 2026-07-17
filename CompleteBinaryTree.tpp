#ifndef COMPLETEBINARYTREE_TPP
#define COMPLETEBINARYTREE_TPP
#include<iostream>
#include"BaseNode.h"
#include"TreeNode.h"
#include"CompleteBinaryTree.h"
#include"TreeException.h"
using namespace std;

template<typename T>
CompleteBinaryTree<T>::CompleteBinaryTree() :root(new TreeNode<T>{ 0 }) {
	size_of_BinaryTree = 2;
}
template<typename T> 
CompleteBinaryTree<T>::~CompleteBinaryTree() {
	clear();
	delete root;
}
template<typename T> 
CompleteBinaryTree<T>::CompleteBinaryTree(CompleteBinaryTree<T>& other) {
	if (this->getroot() == nullptr)
		this->root = new TreeNode<T>{ 0 };
	size_of_BinaryTree = other.getsize_of_BinaryTree();
	for (int i = 2; i <= other.getsize_of_BinaryTree(); ++i) {
		copy(other.getroot(), this->getroot(), 1, i);
	}
}
template<typename T>
CompleteBinaryTree<T>& CompleteBinaryTree<T>:: operator=(CompleteBinaryTree<T>& other) {
	size_of_BinaryTree = other.getsize_of_BinaryTree();
	for (int i = 2; i <= other.getsize_of_BinaryTree(); ++i) {
		copy(other.getroot(), root, 1, i);
	}
	return *this;
}
template<typename T>
void CompleteBinaryTree<T>::calculatingsize(void) {
	TreeNode<T>* nroot = root;
	int i = 1;
	while (nroot->getleft() != nullptr) {
		++i;
		nroot = nroot->getleft();
	}
	size_of_BinaryTree = i;
	nroot = root;
	i = 1;
	while (nroot->getright() != nullptr) {
		++i;
		nroot = nroot->getright();
		FIND_2 = 0;
	}

	if (size_of_BinaryTree == i) {
		++size_of_BinaryTree;
		FIND_2 = 1;
	}
}
template<typename T>
void CompleteBinaryTree<T>::insert(T value) {
	calculatingsize();
	FIND_1 = 0;
	TreeNode<T>* NEW = INSERT(root, 1, size_of_BinaryTree);

	if (NEW->getleft() == nullptr)
		NEW->SetLeft(new TreeNode<T>{ value });
	else
		NEW->SetRight(new TreeNode<T>{ value });
	calculatingsize();
}
template<typename T>
TreeNode<T>* CompleteBinaryTree<T>::getroot(void) {
	return root;
}
template<typename T>
void CompleteBinaryTree<T>::removelast(void) {
	if (root->getleft() == nullptr){
		throw TreeException{};
	}
	else {
		calculatingsize();
		FIND_2= 0;
		int HELPER = size_of_BinaryTree;
		if (FLOOR == 1) {
			--HELPER;
		}
		TreeNode<T>* NEW = nullptr;
		NEW = FindLast(root, 1, HELPER);
		if (NEW->getright() != nullptr) {
			cout << endl << "last = ";
			NEW->getright()->printInfo();
			delete NEW->getright();
			NEW->SetRight(nullptr);
		}
		else {
			cout << endl << "last = ";
			NEW->getleft()->printInfo();
			delete NEW->getleft();
			NEW->SetLeft(nullptr);
		}
		calculatingsize();
	}
}
template<typename T>
void CompleteBinaryTree<T>::levelOrderTraversal(void) {
	int HELPER = size_of_BinaryTree;
	if (FLOOR == 1) {
		--HELPER;
	}
	for (int i = HELPER; i >= 1; --i) {
		PRINTING(root, 1, i);
	}

	cout << endl << "size =" << size_of_BinaryTree << endl << "finish";
}
template<typename T>
bool CompleteBinaryTree<T>::isEmpty(void) const {
	if (root->getleft() == nullptr)
		return false;
	else
		return true;

}
template<typename T>
int CompleteBinaryTree<T>::getsize_of_BinaryTree(void)const {
	return size_of_BinaryTree;
}
template<typename T>
void CompleteBinaryTree<T>::clear(void) {
	CLEAR_2(root, 1, size_of_BinaryTree);
	cout << endl << "Tree removed";
}

//Helper Functions

template<typename T>
TreeNode<T>* CompleteBinaryTree<T>::INSERT(TreeNode<T>* insert, int level, int mainsize) {
	TreeNode<T>* request = nullptr;
	if (level == mainsize)
		return nullptr;


	if (FIND_1 == 0) {
		request = INSERT(insert->getleft(), level + 1, mainsize);
	}

	if (insert->getleft() == nullptr && insert == 0) {
		FIND_1 = 1;
		return insert;
	}
	if (FIND_1 == 0) {
		request = INSERT(insert->getright(), level + 1, mainsize);
	}

	if (insert->getright() == nullptr && FIND_1 == 0) {
		FIND_1 = 1;
		return insert;
	}
	return request;
}

template<typename T>
void CompleteBinaryTree<T>::copy(TreeNode<T>* other, TreeNode<T>* second, int level, int mainsize) {

	if (level == mainsize)
		return;

	copy(other->getleft(), second->getleft(), level + 1, mainsize);
	if (other->getleft() != nullptr && (level == mainsize - 1)) {
		TreeNode<T>* NEW = new TreeNode<T>{ other->getleft()->getdata() };
		second->SetLeft(NEW);
	}
	copy(other->getright(), second->getright(), level + 1, mainsize);
	if (other->getright() != nullptr && (level == mainsize - 1)) {
		TreeNode<T>* NEW = new TreeNode<T>{ other->getright()->getdata() };
		second->SetRight(NEW);
	}

}

template<typename T>
TreeNode<T>* CompleteBinaryTree<T>::FindLast(TreeNode<T>* insert, int level, int mainsize) {
	
	TreeNode<T>* request = nullptr;
	if (level == mainsize)
		return nullptr;

	if (FIND_2 == 0) {
		request = FindLast(insert->getright(), level + 1, mainsize);
	}

	if (insert->getright() != nullptr && (FIND_2 == 0 && level == mainsize - 1)) {
		FIND_2 = 1;
		return insert;
	}
	if (FIND_2 == 0) {
		request = FindLast(insert->getleft(), level + 1, mainsize);
	}

	if (insert->getleft() != nullptr && (FIND_2 == 0 && level == mainsize - 1)) {
		FIND_2 = 1;
		return insert;
	}

	return request;
}

template<typename T>
void CompleteBinaryTree<T>::CLEAR_2(TreeNode<T>* other, int s, int mainsize) {

	if (s == mainsize)
		return;

	CLEAR_2(other->getleft(), s + 1, mainsize);
	if (other->getleft() != nullptr) {
		delete other->getleft();
		other->SetLeft(nullptr);
	}

	CLEAR_2(other->getright(), s + 1, mainsize);
	if (other->getright() != nullptr) {
		delete other->getright();
		other->SetRight(nullptr);
	}

}

template<typename T>
void CompleteBinaryTree<T>::PRINTING(TreeNode<T>* other, int level, int mainsize) {
	if (level == mainsize)
		return;

	PRINTING(other->getright(), level + 1, mainsize);
	if (other->getright() != nullptr && (level == mainsize - 1)) {
		other->getright()->printInfo();
	}

	PRINTING(other->getleft(), level + 1, mainsize);
	if (other->getleft() != nullptr && (level == mainsize - 1)) {
		other->getleft()->printInfo();
	}

}

#endif