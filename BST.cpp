#include <iostream>
#include <iomanip>

using namespace std;

#include "BST.h"

//--- Definition of constructor
// constructs empty Binary Tree obj
BST::BST()
: myRoot(0)
{}

//check if BT is empty
bool BST::empty() const
{ return myRoot == 0; }  // return true if the Binary Search Tree
						// is empty & false for anything otherwise

bool BST::search(const int & item) const
{
   return searchRecursive(myRoot, item);
}

// change to search recursive
bool BST::searchRecursive(BinNode *locptr, const int &item) const {
   if (locptr == NULL)
      return false;

   if (item < locptr->data)       // Descend left
      return searchRecursive(locptr->left, item);

   else if (locptr->data < item)  // Descend right
      return searchRecursive(locptr->right, item);

   else                           // Item found
      return true;
}

//add node to BT
void BST::insert(const int & item)
{
   BinNode * locptr = myRoot;   // search pointer
   BinNode * parent = 0;        // pointer to parent of current node
   bool found = false;     // indicates if item already in BST
   while (!found && locptr != 0)
   {
      parent = locptr;
      if (item < locptr->data)       // descend left
         locptr = locptr->left;
      else if (locptr->data < item)  // descend right
         locptr = locptr->right;
      else                           // item found
         found = true;
   }
   if (!found)
   {                                 // construct node containing item
      locptr = new BinNode(item);
      if (parent == 0)               // empty tree
         myRoot = locptr;
      else if (item < parent->data )  // insert to left of parent
         parent->left = locptr;
      else                           // insert to right of parent
         parent->right = locptr;
   }
   else
      cout << "Item already in the tree\n";
}

//inOrder def
void BST::inOrder(ostream & out) const
{
	inOrderBin(out, myRoot);// gives node in non-decreasing order
}

void BST::inOrderBin(ostream &out, BinNode *locptr) const
{
	if(empty())
	{
		cout << "Binary Tree is empty";
	}

	else if (locptr != NULL)
	{
		inOrderBin(out,locptr->left);
		out << locptr ->data << " ";
		inOrderBin(out, locptr->right);
	}
}

//preOrder def
void BST:: preOrder(ostream & out) const
{
	preOrderBin(out, myRoot);
}

void BST:: preOrderBin(ostream &out, BinNode *locptr) const
{
	if(empty())
	{
		cout << "Binary Tree is empty";
	}
	else if (locptr != NULL)
	{
		out << locptr->data << " "; //visit root node
		preOrderBin(out, locptr->left);//traverse left subtree
		preOrderBin(out, locptr->right);//traverse right subtree
	}
}

//count node function to count nodes inserted into tree
int BST::countNode()
{
	return nodeCountBin(myRoot);
}

int BST::nodeCountBin(BinNode *locptr)
{
	if (locptr !=NULL)
	{
		return nodeCountBin(locptr->left)+nodeCountBin(locptr->right)+1;
	}
	else
	{
		return 0;
	}
}
