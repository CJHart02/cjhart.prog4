class bTree
{
private:
    int nodes;
    int leafs;
	struct node
	{
        int num;
		node *left;
		node *right;
		node *previous;
	};
    	node *root, *current;

public:
	bTree();
	void build(int info);
	int soManyLeafs(node* node);
	void inOrder(node* node);
	void preOrder(node* node);
	void postOrder(node* node);
	void search(int info);
    bool isFull(int count, int max);
    int smallestNode();
    int largestNode();
    int howManyNodes();
    int howManyLeafs();
    void print_inOrder();
    void print_preOrder();
    void print_postOrder();

};
