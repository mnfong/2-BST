// bst.cpp
// mnfong
// Fong, Madison

#include <iostream>
#include <queue>
#include <vector>
#include "bst.h"

using namespace std;

// Adds a new node to the tree in the appropriate location
bool BST::insert(string s, TreeNode *&cur_root)
{
  if (find(s))
  {
    cerr << "insert <" << s << "> failed. String already in tree.\n";
    return false;
  }

  else
  {
    if (cur_root == NULL)
    {
      cur_root = new TreeNode(s);
      ++m_size;
      return true;
    }

    else if (s < cur_root -> m_value)
    {
      return insert(s, cur_root -> left);
    }
    else if (s > cur_root -> m_value)
    {
      return insert(s, cur_root -> right);
    }
  }
  
  return false;
}

// Prints out the string entered
void BST::echo(string str)
{
  cout << str << endl;
  return;
}

// Prints out the number of nodes in the tree
void BST::size()
{
  cout << m_size << endl;
  return;
}

// Looks for given string in the tree. Prints if it is or is not in the
// tree
bool BST::find(string s, TreeNode *cur_root)
{
  if (cur_root == NULL)
  {
    return false;
  }

  else if (s == cur_root -> m_value)
  {
    return true;
  }

  else if (s < cur_root -> m_value)
  {
    return find(s, cur_root -> left);
  }

  else
  {
    return find(s, cur_root -> right);
  } 
  
  return true;
}

// Prints out every element in the tree in depth-first order
// (inorder traversal)
void BST::print(vector <string> &values)
{
  if (m_size == 0)
  {
    cout << "{}\n";
    return;
  }

  dft(values, m_root);

  cout << "{";

  for (int i = 0; i < values.size(); ++i)
  {
    cout << values[i];

    if (i < values.size() - 1)
      cout << ", ";
  }
  cout << "}\n";

  return;
}

// Puts each value into a vector using inorder traversal
void BST::dft(vector <string> &values, TreeNode *cur_root)
{
  if (cur_root == NULL)
    return;

  dft(values, cur_root -> left);

  values.push_back(cur_root -> m_value);

  dft(values, cur_root -> right);

  return;
}

// Prints out every element in the tree in breadth order
void BST::breadth(TreeNode *cur_root)
{
  if (m_size == 0)
  {
    cout << "{}\n";
    return;
  }

  queue <TreeNode *> holderQ;

  holderQ.push(cur_root);

  cout << "{";

  while (!holderQ.empty())
  {
    TreeNode *ptr = holderQ.front();
    cout << ptr -> m_value;

    if (holderQ.front() -> left != NULL)
    {
      holderQ.push(holderQ.front() -> left);
    }

    if (holderQ.front() -> right != NULL)
    {
      holderQ.push(holderQ.front() -> right);
    }

    holderQ.pop();

    if (!holderQ.empty())
    {
      cout << ", ";
    }

  }
    cout << "}\n";
  return;
}

// Prints out the average distance from the root to the last node(s)
double BST::distance(TreeNode *cur_root, double &sum, double &count, double &fromRoot)
{

  if ((m_size == 0) || (m_size == 1))
    return 0;

  if (cur_root -> left != NULL)
  {
    ++count;
    ++fromRoot;
    sum += fromRoot;
    distance(cur_root -> left, sum, count, fromRoot);
    --fromRoot;
  }

  if (cur_root -> right != NULL)
  {
    ++count;
    ++fromRoot;
    sum += fromRoot;
    distance(cur_root -> right, sum, count, fromRoot);
    --fromRoot;
  }

  return sum/count;
}

// Prints if the tree is balanced or not and returns the height
// got confused, used https://stackoverflow.com/questions/31977494/logic-check-of-a-function-to-find-if-a-tree-is-balanced-or-unbalanced
bool BST::balanced(TreeNode *cur_root)
{
  if (cur_root == NULL)
    return true;

  int lh = getHeight(cur_root -> left);
  int rh = getHeight(cur_root -> right);

  if (std::abs(lh - rh) > 1)
    return false;

  else
    return true;
}

// Inserts values from the original tree in the vector to the new tree
void BST::insert_from_vector(vector <string> &values, int startIndex, int endIndex)
{
  if (endIndex < startIndex) 
    return;

  if (endIndex - startIndex == 0)
  {
    insert(values[startIndex]);
    return;
  }

  if (endIndex == startIndex)
  {
    insert(values[startIndex]);
    return;
  }

  int midIndex = (startIndex + endIndex) / 2;
  
  insert(values[midIndex]);

  insert_from_vector(values, midIndex + 1, endIndex);

  insert_from_vector(values, startIndex, midIndex - 1);

  return;
}

// Rebalances the tree
void BST::rebalance(vector <string> &values, TreeNode *&cur_root)
{
  if (cur_root == NULL)
    return;

  dft(values, cur_root);

  deleteTree(cur_root);

  insert_from_vector(values,  0, values.size() - 1);

  return;
}
