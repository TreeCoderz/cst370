#include <stdlib.h>
#include <iostream>

using namespace std;

void printArr(int arr[], int size){
  cout << "** Printing Sorted Arr **" << endl;
  for(int i=0; i<size; i++){
    cout << arr[i] << " ";
  }
  cout << "\n" << endl;

  return;
}

int* CoolSort(int unsortedArr[], int arrSize, int H[], int hSize)
{
  //Instantiate and Assign Variables
  int* sortedArr = unsortedArr;
  int acc = 0;
  int a, b, tmpB, tmpIndex, tmpVal;

  //Begin sorting
  while(acc < hSize){
    int stepSize = H[acc];

    //Error Check
    if(stepSize > arrSize){
      perror("sequence element larger than number of elements in array");
      exit(1);
    }

    // cout << "\nStep Size: " << stepSize << endl;
    //cout << "Cylce: " << acc << endl;
    for(int i=0; i<stepSize; i++){
	a = i;
	b = a + stepSize;

	tmpB = b;

	//	cout << sortedArr[a] << " ";
	while(b < arrSize){
	  // cout << sortedArr[b] << " ";
	  tmpIndex = a;

	  while(tmpIndex >= i && sortedArr[tmpB] < sortedArr[tmpIndex]){
	    tmpVal = sortedArr[tmpIndex];
	    sortedArr[tmpIndex] = sortedArr[tmpB];
	    sortedArr[tmpB] = tmpVal;

	    tmpB = tmpIndex;
	    tmpIndex -= stepSize;
	  }

	  a = b;
	  b += stepSize;
	  tmpB = b;
	}
	//	cout << endl;
    }

    acc++;
  }

  printArr(sortedArr, arrSize);

  return sortedArr;

} 
