#include <vector>
using namespace std;
vector<int> MaxHeapify(vector<int> &A, int i) //violation at parent i
{
    int l = A[2*i];
    int r = A[(2*i) + 1];
    int largest;

    if(A[l] > A[i] && l <= A.size())
    {
        largest = l;
    }
    else
    {
        largest = i;
    }
    if(A[r] > largest && r <= A.size())
    {
        largest = r;
    }
    if(largest != i)
    {
        int temp = A[i];
        A[i] = A[largest];
        A[largest] = A[i];
    }
    return MaxHeapify(A, largest);
}
vector<int> BuildMaxHeap(vector<int> &A)
{
    for(int i = A.size()/2 ; i >= 1; i--)
    {
        MaxHeapify(A,i);
    }
    return A; //could be wrong
}