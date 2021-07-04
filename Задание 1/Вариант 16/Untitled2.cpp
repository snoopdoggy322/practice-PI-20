#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
 
int main()
{
	setlocale(LC_ALL, "rus");
    std::string line;
    std::ifstream myfile("txt2.txt");
    std::vector<int> v;
    if (myfile.is_open())
    {
        while (getline(myfile, line))
            v.push_back(line.length());
        myfile.close();
        std::vector<int>::iterator result = std::max_element(v.begin(), v.end());
        std::cout << "max element at line: " << std::distance(v.begin(), result) + 1 << std::endl;
    }
    else
        std::cout << "Unable to open file txt.txt" << std::endl;
}
