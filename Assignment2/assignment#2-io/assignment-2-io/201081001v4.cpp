#include<bits/stdc++.h>
using namespace std;
 ///////////////////  merge took help from GfG ////////////////

// void merge(vector<int> &arr, int startIndex, int mid, int endIndex){

// 	int N=endIndex-startIndex+1;
	
// 	int i=startIndex,j=mid+1,k=startIndex;
// 	int temp[N];

// 	while(i<=mid&&j<=endIndex){
// 		if (arr[i]<arr[j])
// 		{
// 			temp[k]=arr[i];
// 			i++;
// 			k++;
// 		}
// 		else{
// 			temp[k]=arr[j];
// 			j++;
// 			k++;
// 		}}

// 	if (i>mid)
// 		{
// 			while(j<=endIndex)
// 			{
// 				temp[k]=arr[j];
// 				j++;
// 				k++;
// 			}
// 		}
// 	else
// 	{
// 		while(i<=mid){
// 			temp[k]=arr[i];
// 			i++;
// 			k++;
// 		}
// 	}

// 	for (int i = startIndex; i <= endIndex; ++i)
// 	{
// 		arr[i]=temp[i];
// 	}


// }

ofstream outfile("mergesort.txt"); // For output .txt file

void merge(vector<int> &array, int left, int mid, int right)
{
	auto const subArrayOne = mid - left + 1;
	auto const subArrayTwo = right - mid;

	// Create temp arrays
	auto *leftArray = new int[subArrayOne],
		*rightArray = new int[subArrayTwo];

	// Copy data to temp arrays leftArray[] and rightArray[]
	for (auto i = 0; i < subArrayOne; i++)
		leftArray[i] = array[left + i];
	for (auto j = 0; j < subArrayTwo; j++)
		rightArray[j] = array[mid + 1 + j];

	auto indexOfSubArrayOne = 0, // Initial index of first sub-array
		indexOfSubArrayTwo = 0; // Initial index of second sub-array
	int indexOfMergedArray = left; // Initial index of merged array

	// Merge the temp arrays back into array[left..right]
	while (indexOfSubArrayOne < subArrayOne && indexOfSubArrayTwo < subArrayTwo) {
		if (leftArray[indexOfSubArrayOne] <= rightArray[indexOfSubArrayTwo]) {
			array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
			indexOfSubArrayOne++;
		}
		else {
			array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
			indexOfSubArrayTwo++;
		}
		indexOfMergedArray++;
	}
	// Copy the remaining elements of
	// left[], if there are any
	while (indexOfSubArrayOne < subArrayOne) {
		array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
		indexOfSubArrayOne++;
		indexOfMergedArray++;
	}
	// Copy the remaining elements of
	// right[], if there are any
	while (indexOfSubArrayTwo < subArrayTwo) {
		array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
		indexOfSubArrayTwo++;
		indexOfMergedArray++;
	}
}

void mergesort(vector<int> &arr, int startIndex, int endIndex){

	
	
	if (startIndex<endIndex)
	{

		int mid=(startIndex+endIndex)/2;

		mergesort(arr,startIndex,mid);

		mergesort(arr,mid+1,endIndex);

		merge(arr,startIndex,mid,endIndex);

	}

}

int main(int argc, char* argv[])
{

	ifstream infile(argv[1]);

	vector<int> v;

	int a, N=0;

	while(infile>>a){
		v.push_back(a);
		N++;
	}	

	// cout<<N<<endl;

	// int arr[N];

	// for (int i = 0; i < N; ++i)
	// {
	// 	arr[i]=v[i];
	// }

	// int arr[4]={1,1,3,2};
	// int N=4;

	mergesort(v, 0, N-1);

	for (int i = 0; i < N-1; ++i)
	{
		outfile<<v[i]<<endl;
	}
	outfile<<v[N-1];
	return 0;
}