/*----- treetester.cpp -----------------------------------------------------
                Program for testing BST.
 ------------------------------------------------------------------------*/
#include <iostream>
#include <algorithm>
#include "BST.h"

// change for more/less inputs
#define MAX_INTEGER 500

using namespace std;

void buildBST(int front, int back, BST * tree, int arr[]){

  if(front > back) {return;}

  int tmp = (front + back)/2;
  tree->insert(arr[tmp]);
  buildBST(tmp+1, back, tree, arr);
  buildBST(front, tmp-1, tree, arr);

  return;
}

bool checkExists(int element, int arr[], int size){
  for(int i=0; i<size; i++){
    if(arr[i] == element){
      return true;
    }
  }
  
  return false;
}

int main()
{
   // Testing Constructor and empty()
   BST intBST;            // test the class constructor
   BST sortedBST;
   int acc = 0;
   int inputArray[MAX_INTEGER];

   // Testing insert
   cout << "Now insert integers to be placed in Balance BST" << endl;
   int number;
   for (;;)
   {

     if(acc > MAX_INTEGER - 1){
       cout << "/n ** You have reached the max amount of inputs!" << endl;
       break;
     }

      cout << "Item to insert (-999 to stop): ";
      cin >> number;
      if (number == -999) break;

      intBST.insert(number);

      if(checkExists(number, inputArray, acc)){
        cout << "Element already exists" << endl;
      } else {
        inputArray[acc] = number;
        acc++;
      }
   }
  
   //construct array with correct size for sorting
   int treeArray[acc];
   for(int i=0; i<acc; i++){
     treeArray[i] = inputArray[i];
   }

   //sort array
   sort(treeArray, treeArray+acc);

   int front = 0;
   int back = acc-1;
  
   buildBST(front, back, &sortedBST, treeArray);
  

   cout << "\n Check:";
         cout << endl;
         // Testing inOrder traversal
         cout << "\nTesting inOrder(): " << endl;
         sortedBST.inOrder(cout);
	 cout << endl;
}
