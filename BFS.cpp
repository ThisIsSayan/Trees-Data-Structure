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
//BFS - Iterative implementation
void BFS(Node *root, vector<int>& result)
{
  queue<Node*> q;
  q.push(root);
  while(!q.empty())
  {
    Node *current = q.front();
    q.pop();
    result.push_back(current->val);
    if(current->left != NULL)
    {
      q.push(current->left);
    }
    if(current->right != NULL)
    {
      q.push(current->right);
    }
  }
}
//BFS - Recursive implementation
void BFSRecursive(queue<Node*> q, vector<int>& result)
{
  if(q.empty())
  {
    return;
  }
  Node *current = q.front();
  q.pop();
  result.push_back(current->val);
  if(current->left != NULL)
  {
    q.push(current->left);
  }
  if(current->right != NULL)
  {
    q.push(current->right);
  }
  BFSRecursive(q, result);
}
// Driver function
int main()
{
  Node *root = NULL;
  root = insert(root, 9);
  root = insert(root, 4);
  root = insert(root, 6);
  root = insert(root, 20);
  root = insert(root, 170);
  root = insert(root, 15);
  root = insert(root, 1);
  // root = insert(root, 11);
  // root = insert(root, 20);

  cout << "BFS - Iterative" << endl;
  vector<int> result{};
  BFS(root, result);
  for(int i : result)
  {
    cout << i << " , ";
  }
  cout << endl;

  cout << "BFS - Recursive" << endl;
  result.clear();
  queue<Node*> q;
  q.push(root);
  BFSRecursive(q, result);
  for(int i : result)
  {
    cout << i << " , ";
  }
  cout << endl;

  return 0;
}