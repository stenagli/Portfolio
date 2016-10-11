template<typename T>
class binary_search_tree {
public:
	binary_search_tree()
private:
	int size;
	tree_node root;

	class tree_node {
	private:
		tree_node *parent;
		tree_node *left;
		tree_node *right;
		T key;
	}
}
