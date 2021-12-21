#pragma once

#include "ArraySequence.h"
#include <string>

template <class T>
class BinaryTree
{
private:
	struct node
	{
		node* parent = nullptr;
		node* left = nullptr;
		node* right = nullptr;
		T elem;
	};
	node* root = nullptr;
	int size = 0;
    bool (*cmp)(T, T);
	
private:
	void destructor(node* nodePtr)
	{
		if (nodePtr == nullptr) return;
		if (nodePtr->left != nullptr)
		{
			destructor(nodePtr->left);
			delete nodePtr->left;
		}

		if (nodePtr->right != nullptr)
		{
			destructor(nodePtr->right);
			delete nodePtr->right;
		}
	}
	
	void erase(node* delNode_)
	{
		node* DelNode = delNode_;
		if (DelNode == nullptr)
			return;
		if (DelNode->right == nullptr && DelNode->left == nullptr)
		{
			if (DelNode == this->root)
			{
				delete DelNode;
				this->root = nullptr;
			}
			else
			{
				if (DelNode->parent->right == DelNode) DelNode->parent->right = nullptr;
				else DelNode->parent->left = nullptr;
				delete DelNode;
			}
		}
		else if (DelNode->right != nullptr && DelNode->left == nullptr)
		{
			if (DelNode == this->root)
			{
				DelNode->right->parent = nullptr;
				this->root = DelNode->right;
			}
			else
			{
				if (DelNode->parent->left == DelNode) DelNode->parent->left = DelNode->right;
				else DelNode->parent->right = DelNode->right;
				DelNode->right->parent = DelNode->parent;
			}
			delete DelNode;
		}
		else if (DelNode->right == nullptr && DelNode->left != nullptr)
		{
			if (DelNode == this->root)
			{
				DelNode->left->parent = nullptr;
				this->root = DelNode->left;
			} else
			{
				if (DelNode->parent->left == DelNode) DelNode->parent->left = DelNode->left;
				else DelNode->parent->right = DelNode->left;
				DelNode->left->parent = DelNode->parent;
			}
			delete DelNode;
		}
		else if (DelNode->right != nullptr && DelNode->left != nullptr)
		{
			node* swapNode = next(DelNode);
			T tmp_value = DelNode->elem;
			DelNode->elem = swapNode->elem;
			swapNode->elem = tmp_value;
			this->erase(swapNode);
		}
	}
	
	node* next(node* nodePtr)
	{
		if (nodePtr == nullptr) return nullptr;
		if (nodePtr->right != nullptr)
		{
			nodePtr = nodePtr->right;
			while (nodePtr->left != nullptr)
				nodePtr = nodePtr->left;
			return nodePtr;
		}
		else 
			if (nodePtr->parent->left == nodePtr)
				return nodePtr->parent;
		else return nullptr;
	}



	void printAll(node* nodePtr)
	{
		if (nodePtr == nullptr) 
			return;
		if (nodePtr->left != nullptr)
			printAll(nodePtr->left);
		std::cout << nodePtr->elem;
        std::cout << endl;
		if (nodePtr->right != nullptr)
			printAll(nodePtr->right);
	}

	void get_all_help(node* nodePtr, ArraySequence<T>* arr)
	{
	    if (nodePtr != nullptr)
	    {
	        get_all_help(nodePtr->left, arr);
	        arr->Append(GetElem(nodePtr));
	        get_all_help(nodePtr->right, arr);
	    }

	}

public:
	BinaryTree() = default;

	BinaryTree(const T rootElem, bool (*cmp) (T, T))
	{
		this->root = new node;
		this->root->elem = rootElem;
		this->size = 1;
		this->cmp = cmp;
	}

	BinaryTree(bool (*cmp)(T, T))
	{
	    this->root = nullptr;
	    this->size = 0;
	    this->cmp = cmp;
	}
	
	~BinaryTree()
	{
		destructor(this->root);
		size = 0;
		delete this->root;
	}
	
	void Add(const T elem)
	{
		node* nodePtr = this->root;
		this->size++;
		if(this->root == nullptr)
		{
			this->root = new node;
			this->root->elem = elem;
			return;
		}
	
		while(nodePtr != nullptr)
		{
			if(!this->cmp(nodePtr->elem, elem))
			{
				if(nodePtr->left != nullptr)
					nodePtr = nodePtr->left;
				else
				{
					nodePtr->left = new node;
					nodePtr->left->elem = elem;
					nodePtr->left->parent = nodePtr;
					break;
				}
			} 
			else
			{
				if(nodePtr->right != nullptr)
					nodePtr = nodePtr->right;
				else
				{
					nodePtr->right = new node;
					nodePtr->right->elem = elem;
					nodePtr->right->parent = nodePtr;
					break;
				}
			}
		}
	}
	
	void Erase(T elem)
	{
		node* delNode = Search(elem);
		if(delNode == nullptr) return;
		
		erase(delNode);
		--this->size;
	}
	
	bool Exist(const T elem)
	{
		if(Search(elem) != nullptr)
			return true;
		else return false;
	}

	void printAll()
	{
		if (this->root == nullptr) return;
		printAll(this->root);
		std::cout << endl;
	}

	ArraySequence<T>* get_all()
	{
	    ArraySequence<T>* all = new ArraySequence<T>;
	    get_all_help(this->root, all);
	    std::cout << endl;
        return all;
	}

	T next(const T elem)
	{
		node* nodePtr = Search(elem);
		nodePtr = next(nodePtr);
		if (nodePtr == nullptr) return 0;
		return nodePtr->elem;
	}
	
	int GetSize() const
	{
		return this->size;
	}

	    
	node* Search(const T elem)
    {
        node* nodePtr = this->root;
        while(nodePtr != nullptr)
        {
            if(!this->cmp(nodePtr->elem, elem))
            {
                nodePtr = nodePtr->left;
            }
            else if(!this->cmp(elem, nodePtr->elem))
            {
                nodePtr = nodePtr->right;
            }
            else
            {
                return nodePtr;
            }
        }
        return nullptr;
    }


    
	T GetElem(node* cur)
    {
        return cur->elem;
    }
    
	void SetElem(node* cur, T elem)
    {
	    cur->elem = elem;
    }

};