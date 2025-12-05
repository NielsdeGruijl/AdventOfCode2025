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

    long long finalValue = 0;

    int first;
    int last;

public:
    Day2()
    {
        std::ifstream input("Day2/Input2.txt");
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
            std::cout << firstIndexes[i] << ", " << lastIndexes[i] << std::endl;
            EvaluateIndexRange(std::stoll(firstIndexes[i]), std::stoll(lastIndexes[i]));
        }

        std::cout << "Answer: " << finalValue << std::endl;
    }

    void EvaluateIndexRange(long long currentIdValue, long long lastIdValue)
    {
        while (currentIdValue <= lastIdValue)
        {
            std::string currentId = std::to_string(currentIdValue);

            std::string sequence;
            std::string test;

            int highestSequenceLength = 1;
            int currentIdLength = 0;

            for (int i = 0; i < currentId.length(); i++)
            {
                //std::cout << "lengts " << currentId.length() << ", " << currentIdLength << std::endl;
                if (currentId.length() != currentIdLength)
                {
                    currentIdLength = currentId.length();

                    int a = 0;
                    for (int i = 1; i <= currentIdLength / 2; i++)
                    {
                        if (currentIdLength % i == 0)
                            a = i;
                    }

                    highestSequenceLength = a;
                }

                if (test.empty())
                {
                    test.push_back(currentId[i]);
                    sequence.push_back(currentId[i]);
                    continue;
                }

                if (sequence.length() > currentId.length() / 2)
                    break;

                if (currentId.length() % sequence.length() != 0)
                {
                    if (i < highestSequenceLength)
                        sequence.push_back(currentId[i]);
                    else
                        break;
                }

                if (sequence[0] == currentId[i])
                {
                    bool isSequence = true;
                    for (int j = 0; j < currentId.length(); j++)
                    {
                        int count = std::floor(j / sequence.length());

                        // fix divide by zero
                        int sequenceIndex;
                        if (count > 0)
                            sequenceIndex = j - (count * sequence.length());
                        else sequenceIndex = j;

                        if (sequence[sequenceIndex] != currentId[j])
                        {
                            isSequence = false;
                            break;
                        }
                    }

                    if (!isSequence)
                    {
                        if (i < currentId.length() / 2)
                        {
                            sequence.push_back(currentId[i]);
                            continue;
                        }

                        break;
                    }

                    std::cout << "INVALID: " << currentId << " SEQUENCE: " << sequence << ", sequencelength: " << highestSequenceLength << std::endl;
                    finalValue += currentIdValue;
                    break;
                }
                else
                {
                    sequence.push_back(currentId[i]);
                }
            }

            currentIdValue++;
        }
    }
};

#endif //ADVENTOFCODE2025_DAY2_H