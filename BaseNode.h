#ifndef BASENODE_H
#define BASENODE_H
#include<iostream>
using namespace std;
template <typename T>
class BaseNode {
protected:
	T data;
public:
	BaseNode(T value);
	virtual ~BaseNode();
	virtual void printInfo()const = 0;
	T getdata()const;
	void SetData(T value);
};



#include"BaseNode.tpp"











#endif
