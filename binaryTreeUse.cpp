#include <iostream>
#include <fstream>
#include <iomanip>
#include "binaryTree.h"

using namespace std;

int main()
{
	bTree bst;

	int count, height, nodesInTree, leafsInTree, smallest, largest;
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
    leafsInTree = bst.howManyLeafs();
    smallest = bst.smallestNode();
    largest = bst.largestNode();
    bst.print_inOrder(outFile);
    bst.print_preOrder(outFile);
    bst.print_postOrder(outFile);

    cout << "\nNumber of Nodes: " << nodesInTree << endl;
    cout << "Number of Leafs: " << leafsInTree << endl;
    cout << "Smallest Number: " << smallest << endl;
    cout << "Largest Number: " << largest << endl;

    inFile.close();
    outFile.close();

    return 0;
}

