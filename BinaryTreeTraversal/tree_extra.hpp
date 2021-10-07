//  tree_extra.hpp

// Draws the binary tree rooted at t.  
// Parameter link is a symbol to print in front of the node to
// which t points indicating the direction of the branch leading 
// to the node.
// Parameter depth is proportional to depth of the node to which p
// points.
template <typename T>
static void draw(TreeNode<T> *t, char link, int depth) {
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




    int index = find(in_begin, in_end, *pre_begin) - in_begin;
    typename std::vector<T>::const_iterator pre_index_iter = pre_begin + index;
    typename std::vector<T>::const_iterator in_index_iter = find(in_begin, in_end, *pre_begin);



    std::vector<T> left_pre(next(pre_begin), next(pre_index_iter));
    std::vector<T> left_in(in_begin, in_index_iter);
    std::vector<T> right_pre(next(pre_index_iter), pre_end);
    std::vector<T> right_in(next(in_index_iter), in_end);

    // for (auto elem : left_pre) {
    //     std::cout << elem << ' ';
    // }

    // for (auto elem : left_in) {
    //     std::cout << elem << ' ';
    // }

    // for (auto elem : right_pre) {
    //     std::cout << elem << ' ';
    // }

    // for (auto elem : right_in) {
    //     std::cout << elem << ' ';
    // }

    TreeNode<T> *root = new TreeNode(*pre_begin, 
        ( begin(left_pre) == end(left_pre) )   ? nullptr : (build_tree<T>(begin(left_pre), end(left_pre), begin(left_in), end(left_in))),
        ( begin(right_pre) == end(right_pre) ) ? nullptr : (build_tree<T>(begin(right_pre), end(right_pre), begin(right_in), end(right_in)))
        );

        
    return root;


    //build_tree<T>(std::vector<T>(next(pre_begin), next(pre_index_iter)), std::vector<T>(in_begin, in_index_iter));
    //build_tree<T>(std::vector<T>(next(pre_index_iter), pre_end), std::vector<T>(next(in_index_iter), in_end)));
    
    
    //std::cout << "pre_index_iter: " << *pre_index_iter << "\nin_index_iter: " << *in_index_iter; //couts the values at the computed splitting iterators

    // while (*pre_begin != *in_begin){
    //     in_begin++;
    //     index++;
    // }

    // while (*pre_begin != *in_begin){
    //     left_in.push_back(*(in_begin++));
    // }



    //testing array creations
    // for (auto i : std::vector<T>(next(pre_begin), next(pre_index_iter))) //left_pre
    //     std::cout << i << " ";

    // std::cout << "\n";

    // for (auto i : std::vector<T>(in_begin, in_index_iter)) //left_in
    //     std::cout << i << " ";

    // std::cout << "\n";

    // for (auto i : std::vector<T>(next(pre_index_iter), pre_end)) //right_pre
    //     std::cout << i << " ";

    // std::cout << "\n";

    // for (auto i : std::vector<T>(next(in_index_iter), in_end)) //right_in
    //     std::cout << i << " ";
    

}

