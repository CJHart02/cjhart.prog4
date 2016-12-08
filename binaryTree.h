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
	void inOrder(node* node, std::ostream &out);
	void preOrder(node* node, std::ostream &out);
	void postOrder(node* node, std::ostream &out);
	void search(int info);
    bool isFull(int count, int max);
    int smallestNode();
    int largestNode();
    int howManyNodes();
    int howManyLeafs();
    void print_inOrder(std::ostream &out);
    void print_preOrder(std::ostream &out);
    void print_postOrder(std::ostream &out);

};
