#include <bits/stdc++.h>
using namespace std;

class node {
 public:
  int data;
  node* left;
  node* right;
};

node* newNode(int data) {
  node* Node = new node();
  Node->data = data;
  Node->left = NULL;
  Node->right = NULL;
  return Node;
}

int maxDepth(node* root) {
  if (!root) return 0;
  return (1 + max(maxDepth(root->left), maxDepth(root->right)));
}
void inorder(node* root) {
  if (!root) return;
  inorder(root->left);
  cout << root->data << " ";
  inorder(root->right);
}
void preorder(node* root) {
  if (!root) return;
  cout << root->data << " ";
  preorder(root->left);
  preorder(root->right);
}
void postorder(node* root) {
  if (!root) return;
  postorder(root->left);
  postorder(root->right);
  cout << root->data << " ";
}
void levelorder(node* root) {
  queue<node*> q;
  if (!root) {
    cout << "empty tree";
    return;
  }
  q.push(root);
  while (!q.empty()) {
    cout << " " << q.front()->data << " ";
    if (q.front()->left != NULL) {
      cout << q.front()->left->data << " ";
      q.push_back(q.front().left);
    }
    if (q.front()->right != NULL) {
      cout << q.front()->right->data << " ";
      cout << endl;
    }
  }
}

int main() {
  node* root = newNode(1);
  root->left = newNode(2);
  root->right = newNode(3);
  root->right->right = newNode(4);
  cout << maxDepth(root) << endl;

  return 0;
}