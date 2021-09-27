#include <bits/stdc++.h>
using namespace std;
 
ofstream outfile("toh.txt"); // For output .txt file

int StackSize=0;

int* StackA = NULL;
int* StackB = NULL;
int* StackC = NULL;

int TopA= -1;
int TopB= -1;
int TopC= -1;

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

int Push(int Stack[], int Top, int n)
{
    // int Element;
    if(!IsStackFull(Top))
    {
        // printf("Enter element\n");
        // scanf("%d", &n);

        Top++;
        Stack[Top] = n;
    }
    else
        printf("Element cannot be pushed as stack is already full \n");
    return Top;
}

int Pop(int Stack[], int Top)
{

    if(!IsStackEmpty(Top))
    {
        // printf("Popped out element is: %d \n", Stack[Top]);                         
        Stack[Top] = -1;
        Top--;
    }
    else
        printf("Stack is already empty, we cannot pop the element from it\n");
return Top; 
}



void toh(int n, char from_rod,
                    char to_rod, char aux_rod)
{

   // cout<<n<<" "<<from_rod<<" "<<aux_rod<<" "<<to_rod<<" "<<endl;
    if (n == 1)
    {

    if (from_rod=='A'&&to_rod=='C'){
        TopA=Pop(StackA, TopA);
        TopC=Push(StackC, TopC, n);
    }
    else if (from_rod=='A'&&to_rod=='B')
    {
        TopA=Pop(StackA, TopA);
        TopB=Push(StackB, TopB, n);
    }
    else if (from_rod=='B'&&to_rod=='C')
    {
        TopB=Pop(StackB, TopB);
        TopC=Push(StackC, TopC, n);
    }
    else if (from_rod=='B'&&to_rod=='A')
    {
        TopB=Pop(StackB, TopB);
        TopA=Push(StackA, TopA, n);
    }
    else if (from_rod=='C'&&to_rod=='A')
    {
        TopC=Pop(StackC, TopC);
        TopA=Push(StackA, TopA, n);
    }
    else if (from_rod=='C'&&to_rod=='B')
    {
        TopC=Pop(StackC, TopC);
        TopB=Push(StackB, TopB, n);
    }    

    outfile << "Pop disk " << n << " from Stack " << from_rod<<endl;

    outfile << "Push disk " << n << " to Stack " << to_rod << endl; 

    return;

    }

    toh(n - 1, from_rod, aux_rod, to_rod);
    // cout << "Move disk " << n << " from rod " << from_rod <<
    //                             " to rod " << to_rod << endl;
    if (from_rod=='A'&&to_rod=='C'){
        TopA=Pop(StackA, TopA);
        TopC=Push(StackC, TopC, n);
    }
    else if (from_rod=='A'&&to_rod=='B')
    {
        TopA=Pop(StackA, TopA);
        TopB=Push(StackB, TopB, n);
    }
    else if (from_rod=='B'&&to_rod=='C')
    {
        TopB=Pop(StackB, TopB);
        TopC=Push(StackC, TopC, n);
    }
    else if (from_rod=='B'&&to_rod=='A')
    {
        TopB=Pop(StackB, TopB);
        TopA=Push(StackA, TopA, n);
    }
    else if (from_rod=='C'&&to_rod=='A')
    {
        TopC=Pop(StackC, TopC);
        TopA=Push(StackA, TopA, n);
    }
    else if (from_rod=='C'&&to_rod=='B')
    {
        TopC=Pop(StackC, TopC);
        TopB=Push(StackB, TopB, n);
    }     
    outfile << "Pop disk " << n << " from Stack " << from_rod<<endl;

    outfile << "Push disk " << n << " to Stack " << to_rod << endl;

    toh(n - 1, aux_rod, to_rod, from_rod);
}
 
// Driver code
int main(int argc, char* argv[])
{


    int n = atoi(argv[1]); // Number of disks
    StackSize= n;

    if((StackA= (int*)malloc(n) ) == NULL)
    {
        perror("malloc(): ");
        exit(0);
    }    

    if((StackB= (int*)malloc(n) ) == NULL)
    {
        perror("malloc(): ");
        exit(0);
    }
    if((StackC= (int*)malloc(StackSize) ) == NULL)
    {
        perror("malloc(): ");
        exit(0);
    }
    // if((StackC= (int*)malloc(n ) == NULL)
    // {
    //     perror("malloc(): ");
    //     exit(0);
    // }

    for (int i = 0; i < n; ++i)
    {
        TopA = Push(StackA, TopA, n-i);
        outfile<< "Push disk " << n-i << " to Stack " << "A" << endl; 
    }




    toh(n, 'A', 'C', 'B'); // A, B and C are names of rods


    for (int i = 0; i < StackSize; ++i)
    {
        cout<<StackA[i]<<" "<<StackB[i]<<" "<<StackC[i]<<endl;
    }

    return 0;}