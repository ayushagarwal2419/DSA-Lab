#include<bits/stdc++.h>
using namespace std;

ofstream outfile("radix.txt"); // For output .txt file


void countSort(int arr[], int N, int pos){
	int count[10];
	for (int i = 0; i < 10; ++i)
	{
		count[i]=0;
	}

	for (int i = 0; i < N; ++i)
	{
		count[(arr[i]/pos)%10]++;
	}
	for (int i = 1; i < 10; ++i)
	{
		count[i]=count[i]+count[i-1];
	}
	int b[N];
	for (int i = 0; i < N; ++i)
	{
		b[i]=0;
	}
	for (int i = N-1; i>=0; i--)
	{
		b[--count[(arr[i]/pos)%10]] = arr[i];
	}

	for (int i = 0; i < N; ++i)
	{
		arr[i]=b[i];
	}

}


void radixSort(int arr[], int maxValue, int N){

	for (int pos = 1; maxValue/pos > 0; pos=pos*10)
	{		
		countSort(arr,N,pos);
	}
}

int main(int argc, char const *argv[])
{
	
	ifstream infile(argv[1]);

	vector<int> v;

	int a, N=0;

	while(infile>>a){
		v.push_back(a);
		N++;
	}

	int arr[N];
	for (int i = 0; i < N; ++i)
	{
		arr[i]=v[i];
	}

	int maxValue = *max_element(v.begin(), v.end());	
	// cout<<maxValue<<endl;

	radixSort(arr, maxValue, N);

	for (int i = 0; i < N-1; ++i)
	{
		outfile<<arr[i]<<endl;
	}
	outfile<<arr[N-1];
	return 0;
}