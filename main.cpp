// main.cpp
// mnfong
// Fong, Madison

#include <iostream>
#include "bst.h"

using namespace std;

int main()
{
  // Variables used in main
  BST tree;
  string command = "";
  string input = "";
  string ch = "";

  while (cin >> command)
  {
    // Ignores the white space
    cin.ignore();

    // Checks if the command is echo and then calls the public echo 
    // function
    if (command == "echo")
    {
      getline(cin, input); 
      tree.echo(input);
    }

    // Checks if the command is insert then calls the public insert
    // function
    else if (command == "insert")
    {
      getline(cin, input);
      tree.insert(input);
    }

    // Checks if the command is size then calls the size function
    else if (command == "size")
      tree.size();

    // Checks if the command is find then calls the find public
    // function
    else if (command == "find")
    {
      getline(cin, input);

      if (tree.find(input))
        cout << "<" << input << "> is in tree.\n";

      else
        cout << "<" << input << "> is not in tree.\n";
    }

    // Checks if the command is print then calls the public print 
    // function
    else if (command == "print")
      tree.print();

    // Checks if the command is breadth then calls the public breadth
    // function
    else if (command == "breadth")
      tree.breadth();

    // Checks if the command is distance then calls the public distance 
    // function
    else if (command == "distance")
    {
      cout << "Average distance of nodes to root = " << tree.distance() << "\n";
    }

    // Checks if the command is balanced then calls the public balanced
    // function
    else if (command == "balanced")
    {
      if (!tree.balanced())
        cout << "Tree is not balanced.\n";
      else
        cout << "Tree is balanced.\n";
    }

    // Checks if the command is rebalance then calls the public 
    // rebalance function
    else if (command == "rebalance")
      tree.rebalance();

    // If the command is none of the above, it tells the user that the 
    // command is illegal
    else
    {
      cerr << "Illegal command <" << command << ">.\n";

      if (cin.peek() != 'e')
        getline(cin, input);
    }
  }

  return 0;
}
