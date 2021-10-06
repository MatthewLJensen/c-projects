//  tree_extra.hpp

// Draws the binary tree rooted at t.  
// Parameter link is a symbol to print in front of the node to
// which t points indicating the direction of the branch leading 
// to the node.
// Parameter depth is proportional to depth of the node to which p
// points.
template <typename T>
static void draw(TreeNode<T> *t, char link, int depth) {
    //pass in forward slash for right subtree
    //pass in backslash for left subtree

    if (t == nullptr)
        return;

    //print right subtree
    draw(t->right, '/', ++(++depth));
  
    //print node
    for (int i = 0; i < depth; i++){
        std::cout << " ";
    }
    std::cout << link << "[" << t->data << "]\n";

    //print left subtree
    draw(t->left, '\\', ++(++depth));
}


// Frees up the space held by the nodes in a binary tree 
// rooted at t.
template <typename T>
void dispose(TreeNode<T> *t) {
    /**********************************
     * Add your code here
     **********************************/
}


// Builds a binary tree from preorder and inorder traversals.
// Parameter pre_begin is an iterator to the beginning of the
// preorder traveral sequence.
// Parameter pre_end is an iterator to the end of the preorder 
// traveral sequence.
// Parameter in_begin is an iterator to the beginning of the
// inorder traveral sequence.
// Parameter in_end is an iterator to the end of the inorder
// traveral sequence.
// Returns a pointer to the root of the newly created binary tree.
template <typename T>
static TreeNode<T> *build_tree(typename std::vector<T>::const_iterator pre_begin, 
                               typename std::vector<T>::const_iterator pre_end,
                               typename std::vector<T>::const_iterator in_begin, 
                               typename std::vector<T>::const_iterator in_end) {
    //TreeNode *root = TreeNode(pre_begin)
    return nullptr;
}

