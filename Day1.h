//
// Created by niels on 12/1/25.
//

#ifndef ADVENTOFCODE2025_DAY1_H
#define ADVENTOFCODE2025_DAY1_H
#include <cmath>
#include <fstream>
#include <iosfwd>
#include <iostream>

class Day1
{
    int zeroCount = 0;
    int current = 50;

public:
    Day1()
    {
        std::ifstream input("../Input1");

        if (input.is_open())
        {
            std::string line;

            while (input >> line)
            {
                int value;

                if (line.at(0) == 'R')
                {
                    line.erase(0, 1);
                    value = std::stoi(line);

                    current = EvaluateRight(current, value);

                    std::cout << current << ", " << value << std::endl;
                }

                if (line.at(0) == 'L')
                {
                    line.erase(0, 1);
                    value = std::stoi(line);
                    value *= -1;
                    current = EvaluateLeft(current, value);

                    std::cout << current << ", " << value << std::endl;
                }

                if (current == 0)
                    zeroCount++;
            }

            std::cout << "Password: " << zeroCount << std::endl;

            input.close();
        }
    }

private:
    int EvaluateRight (int pCurrent, int pValue)
    {
        int currentValue = pCurrent;
        int remainder = 100 - pCurrent;

        if (pValue > remainder)
        {
            currentValue = 0;
            pValue -= remainder;

            zeroCount++;
            zeroCount += std::floor(pValue / 100);

            currentValue += pValue % 100;
        }
        else
        {
            currentValue += pValue;
        }

        return currentValue;
    }

    int EvaluateLeft(int pCurrent, int pValue)
    {
        int tempValue = 0;
        pCurrent += pValue;

        if (pCurrent < 0)
        {
            zeroCount += std::floor(pCurrent / -100) + 1;
            tempValue = pCurrent % 100;
            pCurrent = 100 + tempValue;
        }

        return pCurrent;
    }
};

#endif //ADVENTOFCODE2025_DAY1_H


/*void EvaluateValue(int pCurrent, int pValue)
{
    int tempValue = 0;

    pCurrent += pValue;

    if (pCurrent < 0)
    {
        tempValue = pCurrent % 100;
        pCurrent = 100 + tempValue;
    }

    if (pCurrent > 99)
    {
        tempValue = pCurrent % 100;
        pCurrent = 0 + tempValue;
    }

    // return pCurrent;
}*/
