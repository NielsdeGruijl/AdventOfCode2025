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
    std::vector<std::string> firstIds;
    std::vector<std::string> lastIds;

    std::string firstId;
    std::string secondId;

    long long finalValue = 0;

    int first;
    int last;

public:
    Day2()
    {
        std::ifstream input("../Day2/TestInput");
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
                    firstIds.push_back(std::move(index));
                    index.clear();
                    continue;
                }

                if (c == ',')
                {
                    std::cout << index << std::endl;
                    lastIds.push_back(std::move(index));
                    index.clear();
                    continue;
                }

                index.push_back(c);
            }

            std::cout << index << std::endl;
            lastIds.push_back(std::move(index));
        }

        for (int i = 0; i < firstIds.size(); i++)
        {
            std::cout << firstIndexes[i] << ", " << lastIndexes[i] << std::endl;
            EvaluateIndexRange(std::stoll(firstIndexes[i]), std::stoll(lastIndexes[i]));
        }

        std::cout << finalValue << std::endl;
    }

    void EvaluateIndexRange(long long currentIdValue, long long lastIdValue)
    {
        while (currentIdValue <= lastIdValue)
        {
            std::string currentId = std::to_string(currentIdValue);
            std::vector<std::string> possibleIds;
            std::string firstHalf;
            std::string secondHalf;

            std::string test;
            for (int i = 0; i < currentId.length(); i++)
            {
                if (test.empty())
                {
                    test.push_back(currentId[i]);
                    continue;
                }

                if (test[0] == currentId[i])
                {
                    test.push_back(currentId[i]);
                    continue;
                }
                else if (test.length() > 1)
                {
                    for (int i = 1; i < test.size(); i++)
                    {
                        if (test[i] != currentId[i])
                            continue;

                        if (i == test.size() && i != currentId.size())
                            test.push_back(currentId[i]);
                    }
                }

                //firstHalf.push_back(currentId[i]);
                //secondHalf.push_back(currentId[i + halfLength]);
            }

            if (test.length() == currentId.length())
            {
                std::cout << "INVALID: " << currentId << std::endl;
                finalValue += currentIdValue;
            }

            currentIdValue++;
        }
    }
};

#endif //ADVENTOFCODE2025_DAY2_H