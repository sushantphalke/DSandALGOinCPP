
#include <bits/stdc++.h>
using namespace std;

class node {
 public:
  int data;
  node* left;
  node* right;
};

class nod {
 public:
  int data;
  nod* left;
  nod* right;

};

int
maxDepth(node* node) {
  if (node == NULL)
    return 0;
  else {
    /* compute the depth of each subtree */
    int lDepth = maxDepth(node->left);
    int rDepth = maxDepth(node->right);

    /* use the larger one */
    if (lDepth > rDepth)
      return (lDepth + 1);
    else
      return (rDepth + 1);
  }
}

node* newNode(int data) {
  node* Node = new node();
  Node->data = data;
  Node->left = NULL;
  Node->right = NULL;

  return (Node);
}
nod* newNod(int data) {
  nod* Nod = new nod();
  Nod->data = data;
  Nod->left = NULL;
  Nod->right = NULL;
  return Nod;
}

int maxdept(nod* nod) {
  if (node == NULL)
    return 0;
  else {
    int lDepth = maxDepth(node->left);
    int rDepth = maxDepth(node->right);
    if (lDepth > rDepth)
      return (lDepth + 1);
    else
      return (rDepth + 1);
  }
}

// Driver code
int main() {
  nod* root = newNod(1);

  root->left = newNod(2);
  root->right = newNod(3);
  root->left->left = newNod(4);
  root->left->right = newNod(5);
  int mxdept=0;
  cout << "Height of tree is " << maxdept(root,mxdept);
  return 0;
}
