#include<iostream>
using namespace std;
struct node {
    int data;
    node* right;
    node* left;
};
node* createNode(int data) {
    node* NEW = new node;
    NEW->data = data;
    NEW->left = NULL;
    NEW->right = NULL;
    return NEW;
}
node* buildTree() {
    cout << "\nEnter the data: ";
    int data;
    cin >> data;
    if (data == -1) {
        return NULL;
    }
    node* root = createNode(data);

    cout << "\nEnter the left element of " << data << ": ";
    root->left = buildTree();

    cout << "\nEnter the right element : " << data << ": ";
    root->right = buildTree();

    return root;
}
void preorder(node* root) {
    if (root == NULL) {
        return;
    }
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}
void inorder(node* root) {
    if (root == NULL) {
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}
void postorder(node* root) {
    if (root == NULL) {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}
int main() {
    node* root = buildTree();

    cout << "Preorder traversal: ";
    preorder(root);
    cout << endl;

    cout << "Inorder traversal: ";
    inorder(root);
    cout << endl;

    cout << "Postorder traversal: ";
    postorder(root);

    return 0;
}
