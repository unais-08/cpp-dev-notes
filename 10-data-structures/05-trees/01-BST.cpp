#include <iostream>
using namespace std;

// Node of a Binary Search Tree
class TreeNode
{
   public:
    int data;
    TreeNode* left;
    TreeNode* right;

    // Constructor
    TreeNode(int data)
    {
        this->data = data;
        left = nullptr;
        right = nullptr;
    }
};

// Binary Search Tree class
class BinarySearchTree
{
   private:
    TreeNode* root;

   public:
    // Constructor to initialize tree with root node
    BinarySearchTree(int rootValue) { root = new TreeNode(rootValue); }

    // Insert a new value into the BST
    bool insert(int newValue)
    {
        TreeNode* current = root;

        while (true)
        {
            if (newValue == current->data)
            {
                // Value already exists, insertion not allowed
                return false;
            }

            if (newValue < current->data)
            {
                // Go to left subtree
                if (current->left == nullptr)
                {
                    current->left = new TreeNode(newValue);
                    return true;
                }
                current = current->left;
            }
            else
            {
                // Go to right subtree
                if (current->right == nullptr)
                {
                    current->right = new TreeNode(newValue);
                    return true;
                }
                current = current->right;
            }
        }
    }

    // Getter for root node (for traversal/debugging)
    TreeNode* getRoot() { return root; }
};

int main()
{
    BinarySearchTree bst(10);
    bst.insert(5);
    bst.insert(2);

    bst.insert(15);
    bst.insert(20);

    TreeNode* root = bst.getRoot();

    if (root != nullptr)
    {
        cout << "root: " << root->data;

        cout << endl;

        if (root->left != nullptr)
            cout << "left child: " << root->left->data;
        else
            cout << "left child: nullptr";
        cout << endl;

        if (root->left->left != nullptr)
            cout << "left grandchild: " << root->left->left->data;
        else
            cout << "left grandchild: nullptr ";
        cout << endl;

        if (root->right != nullptr)
            cout << "right child: " << root->right->data;
        else
            cout << "right child: nullptr";
        cout << endl;

        if (root->right->right != nullptr)
            cout << "right grandchild: " << root->right->right->data;
        else
            cout << "right grandchild: nullptr ";
        cout << endl;
    }
    return 0;
}
