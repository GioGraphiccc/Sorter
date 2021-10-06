#include <iostream>
#include "insertionsort.h"
using namespace std;

vector<int> InsertionSort::Sort(vector<int> vec)
{
    int SIZE = vec.size();
    int value;
    for(int i = 0; i < SIZE-1; i++)
    {
        value = vec[i+1];
        if(value < vec[i]) 
            {
                for(int k = i; k >= 0; k--)
                {
                    if(value < vec[k] && (value >= vec [k-1] || k-1 < 0)){ 
                        vec[k+1] = vec[k]; //vec[k+1] value placeholder
                        vec[k] = value;
                        k = 0;
                    }
                    else if(k-1 >= 0)
                    {
                        vec[k+1] = vec[k];
                        vec[k] = vec[k-1]; 
                    }
                }
            }
    }
    cout << "Insertion Sort Finished." << endl;
    return vec;
}