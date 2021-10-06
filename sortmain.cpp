#include <iostream>
#include <vector>
#include <chrono>

#include "selectionsort.h"
#include "bubblesort.h"
#include "insertionsort.h"
//#include "mergesort.h"
//#include "heapsort.h"
//#include "quicksort.h"
#include "ArrayFile.h"

std::vector<int> GenerateArray()
{
   std::vector<int> array{3, 6, 7, 5, 3};
    return array;
}

void printVector(std::vector<double> &vec)
{
    for(int i = 0; i < vec.size(); i++)
    {
        if(i != vec.size()-1)
            std::cout << vec[i] << ", ";
        else    
            std::cout << vec[i] << std::endl;
    }
}
double calcAvg(std::vector<int> vec)
{
    double answer = 1;
    for(int i = 0; i < vec.size(); i++)
    {
        answer = answer * vec[i];
    }
    answer = answer / vec.size();
    return answer;
}
int main() 
{
    using std::chrono::high_resolution_clock;
    using std::chrono::duration_cast;
    using std::chrono::duration;
    using std::chrono::milliseconds;

    std::vector<double> SelectionSortTimes; //sorting times for selection sort
    std::vector<int> numbersRead; //vector to save numbers read from a file

    ArrayFile file;
    SelectionSort Selection;
    BubbleSort Bubble;
    InsertionSort Insertion; 

    

    //Create Files with n numbers and name
    file.GenerateNumbersToFile(1000, "NUMBERS_1"); 
    file.GenerateNumbersToFile(4000, "NUMBERS_2");
    file.GenerateNumbersToFile(8000, "NUMBERS_3"); 
    file.GenerateNumbersToFile(10000, "NUMBERS_4"); 
    file.GenerateNumbersToFile(40000, "NUMBERS_5"); 
    file.GenerateNumbersToFile(80000, "NUMBERS_6"); 
    file.GenerateNumbersToFile(100000, "NUMBERS_7"); 
    file.GenerateNumbersToFile(400000, "NUMBERS_8"); 
    file.GenerateNumbersToFile(800000, "NUMBERS_9");
    file.GenerateNumbersToFile(1000000, "NUMBERS_10");  

    //Read and sort
    std::string fileName;
    for(int i = 1; i <= 10; ++i) //for loop to read files 1 - 10
    {
        fileName = "NUMBERS_" + std::to_string(i);
        file.Read(&numbersRead, fileName);

        auto t1 = high_resolution_clock::now();
        std::vector<int> SortedSelection(Selection.Sort(numbersRead)); //Initialize SortedSelection vector 
        auto t2 = high_resolution_clock::now();
        duration<double, std::milli> sTime = t2 - t1;
        SelectionSortTimes.push_back(sTime.count());
    } 
    printVector(SelectionSortTimes);

    // //Time selection sort
    // auto t1 = high_resolution_clock::now();
    // std::vector<int> SortedSelection(Selection.Sort(numbersRead)); //Initialize SortedSelection vector 
    // auto t2 = high_resolution_clock::now();
    // duration<double, std::milli> sTime = t2 - t1;
    // selectionSortTime = sTime.count(); 
    
    // //Time Bubble Sort
    // t1 = high_resolution_clock::now();
    // std::vector<int> SortedBubble(Bubble.Sort(numbersRead)); //Initialize SortedBubble vector
    // t2 = high_resolution_clock::now();
    // duration<double, std::milli> bTime = t2 - t1;
    // bubbleSortTime = bTime.count();

    // //Time Insertion Sort
    // t1 = high_resolution_clock::now();
    // std::vector<int> SortedInsertion(Insertion.Sort(numbersRead)); //Initialize SortedBubble vector
    // t2 = high_resolution_clock::now();
    // duration<double, std::milli> iTime = t2 - t1;
    // insertionSortTime = iTime.count();

    //RESULTS
    // std::cout << std::endl << "Selection Sort ";
    // //printVector(SortedSelection);
    // std::cout << "Time: " << sTime.count() << std::endl << std::endl;

    // std::cout << "Bubble Sort ";
    // //printVector(SortedBubble);
    // std::cout << "Time: " << bTime.count() << std::endl << std::endl;

    // std::cout << "Insertion Sort ";
    // //printVector(SortedInsertion);
    // std::cout << "Time: " << iTime.count() << std::endl << std::endl;
    return 0;
}