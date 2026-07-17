#ifndef BASENODE_TPP
#define BASENODE_TPP
#include<iostream>
#include "BaseNode.h"
using namespace std;

template <typename T>
BaseNode<T>::BaseNode(T value) :data(value) {

}
template <typename T>
BaseNode<T>::~BaseNode() {
		
}
template <typename T>
T BaseNode<T>::getdata()const {
	return data;
}
template <typename T>
void BaseNode<T>::SetData(T value) {
	data = value;
}

#endif