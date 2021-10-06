#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string> 
#include <sstream>
#include "ArrayFile.h"

using namespace std;

void ArrayFile::GenerateNumbersToFile(int SIZE, string name)
{
    int max = 1000000;
    int num;
    name = name + ".txt";
    ofstream NUMBERS_1(name);
    for(int i = 0; i < SIZE-1; i++)
    {
        num = rand() % max;
        cout << "Adding " << num << endl;
        NUMBERS_1 << num << ", ";
    }
    NUMBERS_1 << rand() % max;
    NUMBERS_1.close();
}

void ArrayFile::Read(vector<int> *vec , string name)
{
    name = name + ".txt";
    string line;
    string numText;
    int number;
    ifstream MyReadFile(name);
    while(getline(MyReadFile, line))
    {
        stringstream ss(line);
        while(getline(ss,numText, ','))
        {
            //cout << "numText is: " << numText << " numText Size: " << numText.size() << endl;
            number = stoi(numText);
            vec->push_back(number);
        }
        //cout << line << endl;
    }
    MyReadFile.close();
}
