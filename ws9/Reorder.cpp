// Reorder.cpp - main function for reordering an array
// George Paul Robert, 117928226



//!!NOTE: Code compiled and ran fine with clang++ but not with g++ (most errors were in stack.h)
//Including <cstring> and <vector> in stack.h fixed the errors
#include <algorithm>
#include <iostream>
#include "Stack.h"

using namespace std;

void ReOrder(int newarr[], int arr[], int size)
{
	Stack stack;
	Queue queue;
	int track = 0;
	for (int i = 0; i < size ; i++){
		if (arr[i] != 0){
			if (arr[i] < 0){
				queue.enqueue(arr[i]);
			}
			else{
				stack.push(arr[i]);
			}
		}
		if (arr[i] == 0 || arr[i] == arr[size - 1]){
			while (!queue.isEmpty()){
					newarr[track] = queue.front();
					queue.dequeue();
					track++;
			}


			while (!stack.isEmpty()){
				newarr[track] = stack.top();
				stack.pop();
				track++;
			}
		}
	}
}



void Compare(int myArray[], int size){
	vector<int> sortedArray(myArray, myArray + size);
	sort(sortedArray.begin(), sortedArray.end());


	int i = 0;
	while(!sortedArray.empty())
	{
		myArray[i] = sortedArray.back();
		sortedArray.pop_back();
		i++;
	}
	
}



int main()
{
	const int SIZE = 18;
	int array[] = {-3, 2, -1, 5, 1, -4, 0, 11, 12, 13, -11, -12, 0, -1, -2, 6, 8, 7};
	int newArray[SIZE] = {0};

	//Print out the original array
	std::cout << "array:    ";
	for (int i = 0; i < SIZE; ++i) {
		std::cout << array[i] << " ";
	}
	std::cout << std::endl;

	// Reorder this array in newArray
	ReOrder(newArray, array, SIZE);
	// Print out the new array
	std::cout << "newArray: ";
	for (int i = 0; i < SIZE; ++i)
	{
		std::cout << newArray[i] << " ";
	}
	std::cout << std::endl;

	Compare(newArray, SIZE);

	// Print out the sorted new array
	std::cout << "newArray sorted: ";
	for (int i = 0; i < SIZE; ++i)
	{
		std::cout << newArray[i] << " ";
	}
	std::cout << std::endl;

	return 0;
}