#include<bits/stdc++.h>
using namespace std;

class Node
{
  public:  
    int val;
    Node *right;
    Node *left;  
    Node(int val)
    {
      this->val = val;
      this->right = NULL;
      this->left = NULL;
    }
};
//Insert Node Implementation
Node* insert(Node *root, int val)
{
  Node *newNode = new Node(val);
  if(root == NULL)
  {
    root = newNode;
    return root;
  }
  Node *current = root;
  while(true)
  {
    if(current->val < newNode->val)
    {
      if(current->right == NULL)
      {
        current->right = newNode;
        return root;
      }
      else
      {
        current = current->right;
      }
    }
    else if(current->val > newNode->val)
    {
      if(current->left == NULL)
      {
        current->left = newNode;
        return root;
      }
      else
      {
        current = current->left;
      }
    }
  }
}
  //DFS-Inorder Implimentation [left, root, right]
vector<int> DFSInorder(Node *root, vector<int>& result)
{
  if(root->left != NULL)
  {
    DFSInorder(root->left, result);
  }
  result.push_back(root->val);
  if(root->right != NULL)
  {
    DFSInorder(root->right, result);
  }
  return result;
}
  
// Driver function
int main()
{
  Node *root = NULL;
  root = insert(root, 9);
  root = insert(root, 6);
  root = insert(root, 3);
  root = insert(root, 7);
  root = insert(root, 14);
  root = insert(root, 11);
  root = insert(root, 20);

  vector<int> result{};
  DFSInorder(root, result);

  for(int i : result)
  {
    cout << i << " , ";
  }

  return 0;
}