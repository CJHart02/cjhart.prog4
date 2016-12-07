#include <iostream>
#include <iomanip>
#include "binaryTree.h"

bTree::bTree()
{
	root = nullptr;
	current = nullptr;
}

/*void bTree::build(int info[], int count, int max)
{
    while(count < max)
    {
        node *temp = new node;
        temp -> num = info[count];
        temp -> left = nullptr;
        temp -> right = nullptr;
        temp -> previous = nullptr;
    //sets the root of the tree because tree with no root not impress professor
        if (root == nullptr)
        {
            root = temp;
            current = temp;
        }
    //add new left node if data is less than and left ptr is null
        else if ((info[count] < current -> num) && (current -> left == nullptr))
        {
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
                std::cout << info[count] << std::setw(1) <<" has been inserted into the tree." << std::endl;
                count++;
        }
        else if((info[count] < current -> num) && (current -> left != nullptr))
        {
            current = current -> left;
        }
    //add new right node if data is greater and right ptr is null
        else if ((info[count] > current -> num) && (current -> right == nullptr))
        {
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
                std::cout << info[count] << std::setw(1) << " has been inserted into the tree." << std::endl;
                count++;
        }
        else if ((info[count] > current -> num) && (current -> right != nullptr))
        {
            current = current -> right;;
        }
        else if (info[count] == current -> num)
        {
            current = root;
        }
    }
}
*/

void bTree::build(int info)
{
    node *temp = new node;
    temp -> num = info;
    temp -> left = nullptr;
    temp -> right = nullptr;
    temp -> previous = nullptr;

    if (root == nullptr)
    {
        root = temp;
        current = temp;
    }
    else if ((info < current -> num) && (current -> left == nullptr))
    {
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
    }
    else if ((info > current -> num) && (current -> right == nullptr))
    {
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
    }
    else if (info == current -> num)
    {
        current = root;
    }
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

