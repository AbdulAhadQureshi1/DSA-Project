#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

template <typename T>
struct AVLNode {
  T data;
  int height;
  AVLNode<T>* left;
  AVLNode<T>* right;

  AVLNode(T data) : data(data), height(1), left(nullptr), right(nullptr) {}
};

template <typename T>
class AVLTree {
public:
  AVLNode<T>* root=nullptr;

  bool search(T data) {
    return search(root, data);
  }

  bool compare(T a, T b) {
    return a < b;
  }
  
  void insert(T data) {
    insert(root, data);
  }

  void inorder() {
    inorder(root);
  }

  void rightRotate(AVLNode<T>*& node) {
    AVLNode<T>* leftChild = node->left;
    node->left = leftChild->right;
    leftChild->right = node;
    node = leftChild;

    // Update heights of the rotated nodes
    node->right->height = 1 + max(height(node->right->left), height(node->right->right));
    node->height = 1 + max(height(node->left), height(node->right));
  }

  void leftRotate(AVLNode<T>*& node) {
    AVLNode<T>* rightChild = node->right;
    node->right = rightChild->left;
    rightChild->left = node;
    node = rightChild;

    // Update heights of the rotated nodes
    node->left->height = 1 + max(height(node->left->left), height(node->left->right));
    node->height = 1 + max(height(node->left), height(node->right));
  }

private:

  void inorder(AVLNode<T>* node) {
    if (node == nullptr) {
      return;
    }
    inorder(node->left);
    cout << node->data << endl;
    inorder(node->right);
  }

  int height(AVLNode<T>* node) {
    if (node == nullptr) {
      return 0;
    }
    return node->height;
  }

  int getBalance(AVLNode<T>* node) {
    if (node == nullptr) {
      return 0;
    }
    return height(node->left) - height(node->right);
  }

  bool search(AVLNode<T>* node, T data) {
    if (node == nullptr) {
      return false;
    }
    if (data < node->data) {
      return search(node->left, data);
    } else if (data > node->data) {
      return search(node->right, data);
    } else {
      return true;
    }
  }

  void insert(AVLNode<T>*& node, T data) {
    if (node == nullptr) {
      node = new AVLNode<T>(data);
      return;
    }

    if (compare(data, node->data)) {
      insert(node->left, data);
    } else if (!compare(data, node->data)) {
      insert(node->right, data);
    }

    // Update height of the current node
    node->height = 1 + max(height(node->left), height(node->right));

    // Check for balance and perform rotations if necessary
    int balance = getBalance(node);
    if (balance > 1 && compare(data, node->left->data)) {
      // Left-left case
      rightRotate(node);
    } else if (balance > 1 && !compare(data, node->left->data)) {
      // Left-right case
      leftRotate(node->left);
      rightRotate(node);
    } else if (balance < -1 && !compare(data, node->right->data)) {
      // Right-right case
      leftRotate(node);
    } else if (balance < -1 && compare(data, node->right->data)) {
      // Right-left case
      rightRotate(node->right);
      leftRotate(node);
    }
  }
};
