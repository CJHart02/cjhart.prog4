#include <iostream>
#include <fstream>
#include <iomanip>
#include "binaryTree.h"

using namespace std;

int main()
{
	bTree bst;

	int count, height, nodesInTree, max, smallest, largest;
	//max = 50;
	int info = 0;
    count = 0;
    nodesInTree = 0;

	ifstream inFile;
	ofstream outFile;

    inFile.open("random_ints.txt");
    outFile.open("sorted_ints.txt");

    while (info != -999)
    {
        inFile >> info;
        if (info != -999)
        {
            bst.build(info);
        }
    }

    nodesInTree = bst.howManyNodes();
    smallest = bst.smallestNode();
    largest = bst.largestNode();

    cout << "Number of Nodes: " << nodesInTree << endl;
    cout << "Smallest Number: " << smallest << endl;
    cout << "Largest Number: " << largest << endl;

    return 0;
}

