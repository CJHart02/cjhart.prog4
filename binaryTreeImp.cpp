#include <iostream>
#include <iomanip>
#include <fstream>
#include "binaryTree.h"

bTree::bTree()
{
	root = nullptr;
	current = nullptr;
}


void bTree::build(int info)
{
    if (root == nullptr)
    {
        node *temp = new node;
        temp -> num = info;
        temp -> left = nullptr;
        temp -> right = nullptr;
        temp -> previous = nullptr;

        root = temp;
        current = temp;
        if (nodes == 0)
        {
            nodes = 1;
        }
        else if (nodes > 1)
        {
            nodes++;
        }
        std::cout << info << " has been inserted at root." << std::endl;
    }
    else if ((info < current -> num) && (current -> left == nullptr))
    {
        node *temp = new node;
        temp -> num = info;
        temp -> left = nullptr;
        temp -> right = nullptr;
        temp -> previous = nullptr;

        current -> left = temp;
        current = root;
        if (nodes == 0)
        {
            nodes = 1;
        }
        else if (nodes > 0)
        {
            nodes++;
        }
        std::cout << info << " has been inserted into the tree." << std::endl;
    }
    else if ((info < current -> num) && (current -> left != nullptr))
    {
        current = current -> left;
        build(info);
    }
    else if ((info > current -> num) && (current -> right == nullptr))
    {
        node *temp = new node;
        temp -> num = info;
        temp -> left = nullptr;
        temp -> right = nullptr;
        temp -> previous = nullptr;

        current -> right = temp;
        current = root;
        if (nodes == 0)
        {
            nodes = 1;
        }
        else if (nodes > 0)
        {
            nodes++;
        }
        std::cout << info << " has been inserted into the tree." << std::endl;
    }
    else if ((info > current -> num) && (current -> right != nullptr))
    {
        current = current -> right;
        build(info);
    }
    else if (info == current -> num)
    {
        current = root;
    }
}
int bTree::soManyLeafs(node* node)
{
    if(node == nullptr)
    {
        return 0;
    }
    if(node -> left == nullptr && node -> right == nullptr)
    {
        return 1;
    }
    else
    {
        return soManyLeafs(node -> left) + soManyLeafs(node -> right);
    }
}

void bTree::inOrder(node* node)
{
    std::ofstream outFile;
    outFile.open("sorted_ints.txt");
    if (node != nullptr)
	{
		if (node -> left)
        {
            inOrder(node -> left);
        }
		std::cout << node -> num << ", ";
		outFile << node -> num << ", ";
		if (node -> right)
        {
            inOrder(node -> right);
        }
	}
	else
        return;

	outFile.close();
}

void bTree::preOrder(node* node)
{
    std::ofstream outFile;
    outFile.open("sorted_ints.txt");
    if (node != nullptr)
	{
		std::cout << node -> num << ", ";
        outFile << node -> num << ", ";
		if (node -> left)
        {
            preOrder(node -> left);
        }
		if (node -> right)
        {
            preOrder(node -> right);
        }
	}
	else
        return;
    outFile.close();
}

void bTree::postOrder(node* node)
{
    std::ofstream outFile;
    outFile.open("sorted_ints.txt");
    if(node != nullptr)
	{
		if (node -> left)
        {
            postOrder(node -> left);
        }
		if (node -> right)
        {
            postOrder(node -> right);
        }
		std::cout << node -> num << ", ";
		outFile << node -> num << ", ";
	}
	else
        return;
    outFile.close();
}

bool bTree::isFull(int count, int max)
{
    if (count == max)
        return true;
    else
        return false;
}

int bTree::smallestNode()
{
    current = root;
    while (current -> left != nullptr)
    {
        current = current -> left;
    }
    if (current -> left == nullptr)
    {
        return current -> num;
    }
}

int bTree::largestNode()
{
    current = root;
    while (current -> right != nullptr)
    {
        current = current -> right;
    }
    if (current -> right == nullptr)
    {
        return current -> num;
    }
}

int bTree::howManyNodes()
{
    return nodes;
}

int bTree::howManyLeafs()
{
    leafs = soManyLeafs(root);
    return leafs;
}

void bTree::print_inOrder()
{
    std::ofstream outFile;
    outFile.open("sorted_ints.txt");
    std::cout << "Inorder" << std::endl;
    outFile << "Inorder" << std::endl;
    inOrder(root);
    std::cout << std::endl;
    outFile.close();
}

void bTree::print_preOrder()
{
    std::ofstream outFile;
    outFile.open("sorted_ints.txt");
    std::cout << "Preorder" << std::endl;
    outFile << "Preorder" << std::endl;
    preOrder(root);
    std::cout << std::endl;
    outFile.close();
}

void bTree::print_postOrder()
{
    std::ofstream outFile;
    outFile.open("sorted_ints.txt");
    std::cout << "Postorder" << std::endl;
    outFile << "Postorder" << std::endl;
    postOrder(root);
    std::cout << std::endl;
    outFile.close();
}
