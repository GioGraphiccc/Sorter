#include <vector>
using namespace std;
 int Partition(vector<int> &A, int start, int SIZE)
{
    int temp;
    int p = SIZE;
    int pIndex = A[0];
    for(int i = start; i < SIZE-2; i++) //pivot is last element
    {
        if(A[i] <= A[p]) // find a suitable position to swap A[p] with pIndex
        {
            temp = A[i];
            A[i] = A[pIndex];
            A[pIndex] = A[i];
            pIndex++;
        }
    }
    A[pIndex] = temp; //swap A[pIndex] with A[p]
    A[pIndex] = A[p];
    A[p] = temp;
    return pIndex;
}
vector<int> Sort(vector<int> &A, int left, int right)
{
    int p;
    if(left < right)
    {
        p = Partition(A, left, right);
        Sort(A, left, p-1);
        Sort(A, p+1, right );
    }
    else 
    {
        return A;
    }
}