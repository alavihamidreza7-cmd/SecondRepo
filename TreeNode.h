#ifndef TREENODE_H
#define TREENODE_H
#include<iostream>
#include"BaseNode.h"
using namespace std;
template <typename T>
class TreeNode :public BaseNode<T> {
private:
	TreeNode<T>* left;
	TreeNode<T>* right;
	TreeNode<T>* parent;
public:
	//  int left_right;
	//	int touple ;
	TreeNode(T VALUE);
	~TreeNode();
	void printInfo()const override;
	TreeNode<T>* getleft(void);
	void SetLeft(TreeNode<T>* node);
	TreeNode<T>* getright(void);
	void SetRight(TreeNode<T>* node);
	TreeNode<T> getparent(void);
	void SetParent(TreeNode<T>* node);

};

#include"TreeNode.tpp"










#endif