#include <array>
#include <vector>
#include <iostream>
using namespace std;
vector<int> Merge(vector<int> &L, vector<int> &R, vector<int> &A)
{
    int nL = L.size();
    int nR = R.size();
    int i=0, j=0, k=0;
    while(i < nL && j < nR) //while i and j has not reached the end
    {
        if(L[i] <= R[j]) // add the smallest of L[] or R[] element to A[]
        {
            A[k] = L[i];
            i++;
            k++;
        }
        else
        {
            A[k] = R[j];
            j++;
            k++;
        }
    }
    while(i < nL)
    {
        A[k] = L[i];
        i++;
        k++;
    }
    while(j < nR)
    {
        A[k] = R[j];
        j++;
        k++;
    }
    return A;
}

vector<int> Sort(vector<int> &A, int nA)
{
    int mid, nL, nR;
    int size = nA / 2;
    vector<int> L;
    vector<int> R;
     if(nA <= 1)
        return A; 
    else
    {
        mid = (nA/2);
        nL = mid;
        nR = (nL - mid);
        for(int i = 0; i < mid; i++) //copy elements from 0 to the mid of A[] onto L[]
        {
            L[i] = A[i]; 
        }
        for(int i = mid; i > nA-1; i--) //copy elements from mid to the end of A[] onto R[] 
        {
            R[i-mid] = A[i];
        }
        MergeSort(L, size);
        MergeSort(R, size);
        return Merge(L,R,A);
    }
}