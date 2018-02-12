#include <iostream>
#include "coolSort.h"

using namespace std;

int main(){

  int testCase1[] = {2,5,6,4,10,9,8,1,10,5};
  int H1[] = {5,3,1};

  int testCase2[] = {2,5,9,4,10,7,8,1,11,5};
  int H2[] = {5,2,1};

  cout << "\nCool Sorting: " << "{2,5,6,4,10,9,8,1,10,5}" << endl;
  CoolSort(testCase1,10, H1, 3);

  cout << "Cool Sorting: " << "{2,5,9,4,10,7,8,1,11,5}" << endl;
  CoolSort(testCase2, 10, H2, 3);

  return 0;
}
