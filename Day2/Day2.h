//
// Created by niels on 3-12-2025.
//

#ifndef ADVENTOFCODE2025_DAY2_H
#define ADVENTOFCODE2025_DAY2_H
#include <fstream>
#include <iostream>
#include <vector>

class Day2
{
    std::vector<std::string> firstIndexes;
    std::vector<std::string> lastIndexes;

    std::string firstId;
    std::string secondId;

    int finalValue = 0;

    int first;
    int last;

public:
    Day2()
    {
        std::ifstream input("Day2/TestInput");
        std::string line;

        if (input.is_open())
        {
            char c;

            std::string index;

            while (input.get(c))
            {
                //std::cout << c;

                if (c == '-')
                {
                    std::cout << index << "-";
                    firstIndexes.push_back(std::move(index));
                    index.clear();
                    continue;
                }

                if (c == ',')
                {
                    std::cout << index << std::endl;
                    lastIndexes.push_back(std::move(index));
                    index.clear();
                    continue;
                }

                index.push_back(c);
            }

            std::cout << index << std::endl;
            lastIndexes.push_back(std::move(index));
        }

        for (int i = 0; i < firstIndexes.size(); i++)
        {
            EvaluateIndexRange(std::stoi(firstIndexes[i]), std::stoi(lastIndexes[i]));
        }


        std::cout << finalValue << std::endl;
    }

    void EvaluateIndexRange(int firstIndex, int lastIndex)
    {
        while (firstIndex <= lastIndex)
        {
            // Check indexes

            firstIndex++;
        }
    }

};

#endif //ADVENTOFCODE2025_DAY2_H