#include<bits/stdc++.h>
using namespace std;

// int IsEmpty();
// int InFull(); 

// void push();
// void pull();

// void toh(int n, int* S, int* I, int* D){
// 	if (n==1){
// 		pull(1,I);
// 		push(1,D);
// 	}
// 	else{
// 		toh(n-1, S,I,D);
// 		toh()
// 	}

// int main(int argc, char const *argv[])
// {
	
// 	return 0;
// }

/*
 * ======================CS2x1 DSA Course===========================================================                                                                                             
 * Implemeneted as a part of CS2x1 course, Indian Institute of Technology Dharwad, Dharwad, India                                
 * Contacts: k.kondepu@iitdh.ac.in; gayatri.rayar@iitdh.ac.in; 212011003@iitdh.ac.in                                            
 * Copyrigh t (c) 2021 Indian Institute of Technology Dharwad (IITDh)                                               
 * ==================================================================================================
 */

// StackOpsArrays.c:: Stack operations using Arrays. 
// #include "stdio.h"
// #include "stdlib.h"

int StackSize=0;
int* StackA = NULL;
int* StackB = NULL;
int* StackC = NULL;

int TopA= -1;
int TopB= -1;
int TopC= -1;

// void Push();
// void Pop();
// void PrintStack();

int IsStackFull(int Top)
{
	if(Top == StackSize-1)
	{
		return 1;
	}
	else
		return 0;
}

int IsStackEmpty(int Top)
{
	if(Top == -1)
	{
		return 1;
	}
	else
		return 0;
}

int Push(int Stack[], int Top){
	int Element;
	if(!IsStackFull(Top))
	{
		printf("Enter element\n");
		scanf("%d", &Element);

		Top++;
		Stack[Top] = Element;
	}
	else
		printf("Element cannot be pushed as stack is already full \n");
	return Top;
}

int Pop(int Stack[], int Top)
{

	if(!IsStackEmpty(Top))
	{
		printf("Popped out element is: %d \n", Stack[Top]);							
		Stack[Top] = -1;
		Top--;
	}
	else
		printf("Stack is already empty, we cannot pop the element from it\n");
return Top;	
}

// void PrintStack(int* Stack)
// {
// 	int i=0;

// 	for(i=0; i<StackSize; i++)
// 	{
// 		printf("Stack[%d] = %d \n", i, Stack[i]);
// 	}
// 		printf("Top is: %d\n", Top);
// }

int main(int argc, char* argv[])
{
	int Op = 0;

	if(argc < 2)
	{
		printf("Implementing Stack using Arrays, please enter Stack size\n");
		printf("Usage is: %s <Stack Size >\n", argv[0]);
		exit(0);
	}

	StackSize = atoi(argv[1]);

	if((StackA= (int*)malloc(StackSize) ) == NULL)
	{
		perror("malloc(): ");
		exit(0);
	}
	
	if((StackB= (int*)malloc(StackSize) ) == NULL)
	{
		perror("malloc(): ");
		exit(0);
	}

	if((StackC= (int*)malloc(StackSize) ) == NULL)
	{
		perror("malloc(): ");
		exit(0);
	}		

	for (int i = 0; i < StackSize; ++i)
		{
			cout<<i<<endl;
			TopA = Push(StackA, TopA);
			TopA = Push(StackA, TopA);
			TopC = Push(StackC, TopC);
		}	
			
	for (int i = 0; i < StackSize; ++i)
	{
		cout<<StackA[i]<<" "<<StackB[i]<<" "<<StackC[i]<<endl;
	}

}


