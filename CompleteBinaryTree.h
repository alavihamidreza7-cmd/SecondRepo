#ifndef COMPLETEBINARYTREE_H
#define COMPLETEBINARYTREE_H
#include<iostream>
#include"BaseNode.h"
#include"TreeNode.h"
using namespace std;

template<typename T>
class CompleteBinaryTree {
private: 
	TreeNode<T>* root;
	int size_of_BinaryTree;

	int FIND_1;
	int FIND_2;
	int FLOOR;
public:

	CompleteBinaryTree();
	~CompleteBinaryTree();
	CompleteBinaryTree(CompleteBinaryTree<T>& other);
	CompleteBinaryTree<T>& operator=(CompleteBinaryTree<T>& other);
	void calculatingsize(void);
	void insert(T value);
	TreeNode<T>* getroot(void);
	void removelast(void);
	void levelOrderTraversal(void);
	bool isEmpty(void) const;
	int getsize_of_BinaryTree(void)const;
	void clear(void);





	TreeNode<T>* INSERT(TreeNode<T>* insert, int level, int mainsize);
	void copy(TreeNode<T>* other, TreeNode<T>* second, int level, int mainsize);
	TreeNode<T>* FindLast(TreeNode<T>* insert, int level, int mainsize);
	void CLEAR_2(TreeNode<T>* other, int s, int mainsize);
	void PRINTING(TreeNode<T>* other, int level, int mainsize);









};
/*
template<typename T>
TreeNode<T>* INSERT(TreeNode<T>* insert, int level, int mainsize);
template<typename T>
void copy(TreeNode<T>* other, TreeNode<T>* second, int level, int mainsize);
template<typename T>
TreeNode<T>* FindLast(TreeNode<T>* insert, int level, int mainsize);
template<typename T>
void searching4(TreeNode<T>* other, int s, int mainsize);
template<typename T>
void searching6(TreeNode<T>* other, int level, int mainsize);
*/

#include"CompleteBinaryTree.tpp"
#endif
