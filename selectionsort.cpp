#include <iostream>
#include <vector>
#include "selectionsort.h"
using namespace std;

vector<int> SelectionSort::Sort(vector<int> vec)
{
    int SIZE = vec.size();
    int min = vec[0];
    int temp;
    int mini = 0;
    for(int k = 0; k < SIZE-1 ; k++)
    {
        for(int i = k+1; i < SIZE; i++)
        {
            if(min > vec[i]){ //search vec for the smallest number
                min = vec[i]; //save the number into min
                mini = i; // save the location of min into mini
            }
        }
        if(vec[mini] == min)
        {
            temp = vec[k];
            vec[k] = min;
            vec[mini] = temp;
        }
        min = vec[k+1];
    }
    cout << "Selection Sort Finished." << endl;
    return vec;
}

