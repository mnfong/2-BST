// bst.h
// mnfong
// Fong, Madison

#ifndef BST_H
#define BST_H

#include <iostream>
#include <vector>

using namespace std;

class BST
{
  // Private variables and functions for the tree
  private:
    // Makes the tree's nodes
    class TreeNode
    {
      public:
        TreeNode(string val, TreeNode *l = NULL, TreeNode *r = NULL)
        {
          m_value = val;
          left = l;
          right = r;
        }
        string m_value = "";
        TreeNode *left = NULL;
        TreeNode *right = NULL;
    };
    
    // Tree's variables
    TreeNode *m_root = NULL;
    int m_size = 0;

    // Function variables
    double fromRoot = 0;
    double sum = 0;
    double count = 1;
    vector <string> m_values;

    // Inserts a node onto the tree
    bool insert(string s, TreeNode *&cur_root);

    // Find the specified node in the tree
    bool find(string s, TreeNode *cur_root);

    // Prints out every element in the tree in depth-first order
    // (inorder traversal)
    void print(vector <string> &values);

    // Puts each value into a vector in inorder traversal
    void dft(vector <string> &values, TreeNode *cur_root);

    // Prints out every element in breadth order
    void breadth(TreeNode *cur_root);

    // Prints out the average height of the tree
    double distance(TreeNode *cur_root, double &sum, double &count, double &fromRoot);
    
    // Returns the height of the tree
    int getHeight(TreeNode *cur_root)
    {
      if (cur_root == NULL)
        return 0;
      else 
      {
        int lh = getHeight(cur_root -> left);
        int rh = getHeight(cur_root -> right);

        if (lh > rh)
          return (lh + 1);
        else
          return (rh + 1);
      }
    }

    // Prints if the tree is balanced or not and returns the height
    bool balanced(TreeNode *cur_root);

    // Inserts values from the original tree in the vector to the new tree
    void insert_from_vector(vector <string> &values, int startIndex, int endIndex);

    // Rebalances the tree
    void rebalance(vector <string> &values, TreeNode *&cur_root);

    // Deletes the entire tree
    void deleteTree(TreeNode *&cur_root)
    {
      if (cur_root == NULL)
      {
        return;
      }

      deleteTree(cur_root -> left);

      deleteTree(cur_root -> right);
      delete cur_root;

      if (cur_root == m_root)
        m_root = NULL;
      return;
    }

  // Public functions for the tree
  public:

    // Calls the private insertion function
    bool insert(string str) {return insert(str, m_root);}
    
    // Prints out the specified string
    void echo(string str);

    // Prints out the number of nodes in the tree
    void size();

    // Calls the private find function
    bool find(string str) {return find(str, m_root);}

    // Calls the private print function
    void print() {print(m_values); return;}

    // Calls the private breadth function
    void breadth() {breadth(m_root); return;}

    // Calls the private distance function
    double distance() {return distance(m_root, sum, count, fromRoot);}

    // Calls the private getHeight function
    bool getHeight() {return getHeight(m_root);}

    // Calls the private balanced function
    bool balanced() {return balanced(m_root);}

    // Calls the private rebalance function
    void rebalance() {rebalance(m_values, m_root); return;}
};

#endif
