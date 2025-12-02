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
        std::ifstream input("Input1");

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

                    int currentZero = zeroCount;

                    current = EvaluateRight(current, value);

                    std::cout << current << ", " << value << ", " << zeroCount - currentZero << std::endl;
                }

                if (line.at(0) == 'L')
                {
                    line.erase(0, 1);
                    value = std::stoi(line);
                    value *= -1;

                    int currentZero = zeroCount;

                    current = EvaluateLeft(current, value);

                    std::cout << current << ", " << value << ", " << zeroCount - currentZero << std::endl;
                }
            }

            std::cout << "Password: " << zeroCount << std::endl;

            input.close();
        }
    }

private:
    int EvaluateRight (int pCurrent, int pValue)
    {
        int currentValue = pCurrent + pValue;

        while (currentValue > 99)
        {
            currentValue -= 100;
            zeroCount++;
        }

        return currentValue;
    }

    int EvaluateLeft(int pCurrent, int pValue)
    {
        bool startedAtZero = false;
        if (pCurrent == 0)
            startedAtZero = true;

        int currentValue = pCurrent + pValue;

        while (currentValue < 0)
        {
            currentValue += 100;

            if (!startedAtZero)
                zeroCount++;
        }

        if (currentValue == 0 && !startedAtZero)
            zeroCount++;

        return currentValue;
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
