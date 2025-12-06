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
        std::ifstream input("../Day2/Input2.txt");
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
            //std::cout << firstIds[i] << ", " << lastIds[i] << std::endl;
            EvaluateIndexRange(std::stoll(firstIds[i]), std::stoll(lastIds[i]));
        }

        std::cout << "Answer: " << finalValue << std::endl;
    }

    void EvaluateIndexRange(long long currentIdValue, long long lastIdValue)
    {
        int currentIdLength = 0;
        int highestSequenceLength = 1;

        while (currentIdValue <= lastIdValue)
        {
            std::string currentId = std::to_string(currentIdValue);

            std::string sequence;
            std::string test;

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

                    //std::cout << "new sequence length: " << highestSequenceLength << std::endl;
                }

                if (sequence.empty())
                {
                    sequence.push_back(currentId[i]);
                    continue;
                }

                /*if (sequence.length() > currentId.length() / 2)
                {
                    std::cout << "Sequence longer than id: " << sequence.length() << ", id length: " << currentId.length() / 2 << std::endl;
                    break;
                }*/

                /*if (currentId.length() % sequence.length() != 0)
                {
                    if (sequence.length() < highestSequenceLength)
                        sequence.push_back(currentId[i]);
                    else
                        break;
                }*/

                if (sequence[0] == currentId[i] && currentId.length() % sequence.length() == 0)
                {
                    //std::cout << "----" << std::endl;

                    bool isSequence = true;
                    for (int j = 0; j < currentId.length(); j++)
                    {
                        int count = std::floor(j / sequence.length());

                        // fix divide by zero
                        int sequenceIndex;
                        if (count > 0)
                            sequenceIndex = j - count * sequence.length();
                        else
                            sequenceIndex = j;


                        if (sequence[sequenceIndex] != currentId[j])
                        {
                            //std::cout << sequence << ", " << currentId << ", " << std::endl;
                            //std::cout << sequence.length() << std::endl;
                            isSequence = false;
                            break;
                        }
                    }

                    if (!isSequence)
                    {
                        if (sequence.length() < highestSequenceLength)
                        {
                            sequence.push_back(currentId[i]);

                            continue;
                        }

                        break;
                    }

                    if (currentId.length() == 3)
                        std::cout << "INVALID: " << currentId << " SEQUENCE: " << sequence << std::endl;

                    finalValue += currentIdValue;
                    break;
                }

                if (sequence.length() < highestSequenceLength)
                    sequence.push_back(currentId[i]);

                //std::cout << "New sequence: " << sequence << std::endl;

                //std::cout << sequence.length() << ", " << highestSequenceLength << std::endl;
            }

            currentIdValue++;
        }
    }
};

#endif //ADVENTOFCODE2025_DAY2_H