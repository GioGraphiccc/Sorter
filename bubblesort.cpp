#include "bubblesort.h"
#include <iostream>
using namespace std;

vector<int> BubbleSort::Sort(vector<int> vec)
{
    int SIZE = vec.size();
    int max = vec[0];
    int temp;
    int maxi;
    for(int k = SIZE-1; k > 0; k--)
    {
        for(int i = k-1; i >= 0; i--)
        {
            if(max < vec[i])
            {
                max = vec[i];
                maxi = i;
            }
        }
        if(vec[maxi] == max)
        {
            temp = vec[k];
            vec[k] = max;
            vec[maxi] = temp;
        }
        max = vec[k-1];
    }
    cout << "Bubble Sort Finished." << endl;
    return vec;
}