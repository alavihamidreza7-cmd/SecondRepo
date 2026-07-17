#include<iostream>
#include"BaseNode.h"
#include"TreeNode.h"
#include"CompleteBinaryTree.h"
#include"CompleteBinaryTree.tpp"
#include"BaseNode.tpp"
#include"TreeNode.tpp"
#include"TreeException.h"
using namespace std;


int main() {
	std::cout << "--- Testing Complete Binary Tree with Integer ---" << std::endl;
	CompleteBinaryTree<int> intTree;

	intTree.insert(10);
	intTree.insert(20);
	intTree.insert(30);
	intTree.insert(40);
	intTree.insert(50);

	std::cout << "Tree Size: " << intTree.getsize_of_BinaryTree() << std::endl;
	std::cout << "Level-Order Traversal: ";
	intTree.levelOrderTraversal(); // خروجی انتظاری: 10 20 30 40 50 


	std::cout << "\nRemoving last node..." << std::endl;
	intTree.removelast();
	std::cout << "Level-Order Traversal after removal: ";
	intTree.levelOrderTraversal(); // خروجی انتظاری: 10 20 30 40

	// ۳. تست سازنده کپی عمیق (Deep Copy)
	std::cout << "\nTesting Copy Constructor (Deep Copy)..." << std::endl;
	CompleteBinaryTree<int> copiedTree = intTree;

	intTree.insert(99); // تغییر در درخت اصلی
	std::cout << "Original Tree after inserting 99: ";
	intTree.levelOrderTraversal(); // خروجی انتظاری: 10 20 30 40 99 

	std::cout << "Copied Tree (should remain unchanged): ";
	copiedTree.levelOrderTraversal(); // خروجی انتظاری: 10 20 30 40

	// ۴. تست درخت با نوع داده متفاوت (Double)
	std::cout << "\n--- Testing Complete Binary Tree with Double ---" << std::endl;
	CompleteBinaryTree<double> doubleTree;
	doubleTree.insert(1.1);
	doubleTree.insert(2.2);
	std::cout << "Double Tree: ";
	doubleTree.levelOrderTraversal();

	std::cout << "\n--- Testing Exception Handling ---" << std::endl;
	CompleteBinaryTree<char> emptyTree;
	try {
		std::cout << "Attempting to remove from an empty tree..." << std::endl;
		emptyTree.removelast();
	}
	catch (const TreeException& e) {
		std::cout << "Caught Expected Exception: " << e.what() << std::endl;
	}

	std::cout << "\nProgram finished successfully!" << std::endl;


	cout << endl << "|||" << emptyTree.isEmpty();


	return 0;




}