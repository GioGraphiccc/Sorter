#include <vector>
class ArrayFile
{
    public: 
        void GenerateNumbersToFile(int SIZE, std::string name);
        void Read(std::vector<int> *vec, std::string name);
};
