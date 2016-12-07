class bTree
{
public:
	bTree();
	void build(int info);
	void inOrder();
	void preOrder();
	void postOrder();
	void search(int info);
    bool isFull(int count, int max);
    int smallestNode();
    int largestNode();
    int howManyNodes();
private:
    int nodes;
	struct node
	{
        int num;
		node *left;
		node *right;
		node *previous;
	};
    	node *root, *current;

};
