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

void bTree::inOrder(node* node, std::ostream &out)
{
    std::ofstream outFile;
    if (node != nullptr)
	{
		if (node -> left)
        {
            inOrder(node -> left, outFile);
        }
		std::cout << node -> num << ", ";
		out << node -> num << ", ";
		if (node -> right)
        {
            inOrder(node -> right, outFile);
        }
	}
	else
        return;
}

void bTree::preOrder(node* node, std::ostream &out)
{
    std::ofstream outFile;
    if (node != nullptr)
	{
		std::cout << node -> num << ", ";
        out << node -> num << ", ";
		if (node -> left)
        {
            preOrder(node -> left, outFile);
        }
		if (node -> right)
        {
            preOrder(node -> right, outFile);
        }
	}
	else
        return;
}

void bTree::postOrder(node* node, std::ostream &out)
{
    std::ofstream outFile;
    if(node != nullptr)
	{
		if (node -> left)
        {
            postOrder(node -> left, outFile);
        }
		if (node -> right)
        {
            postOrder(node -> right, outFile);
        }
		std::cout << node -> num << ", ";
		out << node -> num << ", ";
	}
	else
        return;
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

void bTree::print_inOrder(std::ostream &out)
{
    std::ofstream outFile;
    std::cout << "Inorder" << std::endl;
    out << "Inorder" << std::endl;
    inOrder(root, outFile);
    std::cout << std::endl;
}

void bTree::print_preOrder(std::ostream &out)
{
    std::ofstream outFile;
    std::cout << "Preorder" << std::endl;
    out << "Preorder" << std::endl;
    preOrder(root, outFile);
    std::cout << std::endl;
}

void bTree::print_postOrder(std::ostream &out)
{
    std::ofstream outFile;
    std::cout << "Postorder" << std::endl;
    out << "Postorder" << std::endl;
    postOrder(root, outFile);
    std::cout << std::endl;
}
