struct Node {
 int data; // Value of interest in the node
 Node *left; // Pointer to this node’s left subtree
 Node *right; // Pointer to this node’s right subtree
};
/*Complete the following function named distance that computes the length of the path from the root to the closest node
that holds the given data value. A client would pass the root of a tree and the value to explore within that tree. The
complexity of your function should be O(n).*/

int distance(const Node *t, int value) {

}

/*
Complete the following function named count that returns number of nodes in a binary tree that contain the given data
value. A client would pass the root of a tree and the value to count within that tree. The complexity of your function should
be O(n).
*/
int count(const Node *t, int value) {
    if (t == NULL) {
        return 0;
    }
    int left = count(t->left, value);
    int right = count(t->right, value);
    if (t->data == value) {
        return left + right + 1;
    }
    return left + right;
}


/*
Complete the following function named equals that returns true if two trees have exactly the same structure; that is, both
trees have the same data values in the same locations. Said another way, if you drew a picture of both trees, they would be
indistinguishable. The function returns false if the trees are different in some way. A client would pass the roots of the two
trees to compare. The complexity of your function should be O(n).
*/
bool equals(const Node *t1, const Node *t2) {
    if (t1 == NULL && t2 == NULL) {
        return true;
    }
    if (t1 == NULL || t2 == NULL) {
        return false;
    }
    if (t1->data != t2->data) {
        return false;
    }
    return equals(t1->left, t2->left) && equals(t1->right, t2->right);
}


/*Given the Node definition from Question #1, now used to build binary search trees, complete the following function that returns
true if the binary search tree to which t points contains the value item; otherwise, the function returns false. The time
complexity of your function should be O(log n).*/
bool find(Node *t, int item) {
    if (t == NULL) {
        return false;
    }
    if (t->data == item) {
        return true;
    }
    if (item < t->data) {
        return find(t->left, item);
    }
    return find(t->right, item);
}


