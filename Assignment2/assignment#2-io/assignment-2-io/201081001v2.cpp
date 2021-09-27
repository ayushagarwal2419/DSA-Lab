#include<bits/stdc++.h>
using namespace std;

void merge(int A[], int startIndex, int lastIndex){
	int i=0;
	int j=0;
	int k=startIndex;
	int size = lastIndex-startIndex+1;

	int mid= (startIndex+lastIndex)/2;


	cout<<size<<" is the size"<<endl;

	int L[mid];
	int R[lastIndex-mid+1];

	int temp[size];
	// cout<< "printing A"<<endl;
	// for (int i = 0; i < size; ++i)
	// {
	// 	cout<<A[i]<<" ";
	// }
	// cout<<endl;	

	for (int i = 0; i < size; ++i)
	{
		temp[i]=0;
	}

	for (int i = 0; i < mid; ++i)
	{
		L[i]=A[i];
		cout<<"L "<<L[i]<<endl;

	}
	for (int j = 0; j < lastIndex-mid+1; ++j)
	{
		R[j]=A[mid+j];
		cout<<"R "<<R[i]<<endl;		
	}
	for (int k = startIndex; k < lastIndex; ++k)
	{
		if (L[i]<=R[j]){
			temp[k]=L[i];
			i++;
		}
		else{
			temp[k]=R[j];
			j++;
		}
	}

	for (int i = 0; i < size; ++i)
	{
		A[i]=temp[i];
	}

}

void mergesort(int A[], int startIndex, int lastIndex){
	int mid;
	cout<<startIndex<<" "<<lastIndex<<endl;
	if (startIndex<lastIndex){

		mid = (startIndex+lastIndex)/2;

		mergesort(A, startIndex, mid);
		mergesort(A, mid+1, lastIndex);
		merge(A, startIndex, lastIndex);


	}
}

int main(int argc, char* argv[])
{
	

	ifstream infile(argv[1]);

	int a, count=0;
	vector<int> v;

	while(infile>>a){
		v.push_back(a);
		count++;
	}

	for (int i = 0; i < count; ++i)
	{
		cout<<v[i]<<endl;
		/* code */
	}

	int A[count];

	for (int i = 0; i < count; ++i)
	{
		A[i]=v[i];
		cout<<A[i]<<endl;
	}	
	int startIndex = 0;
	int lastIndex = count-1;
	mergesort(A, startIndex, lastIndex);

	for (int i = 0; i < count; ++i)
	{
		cout<<A[i]<<endl;
	}

	return 0;
}
