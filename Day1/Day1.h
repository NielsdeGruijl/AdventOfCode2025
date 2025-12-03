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

            std::cout << "50" << std::endl;

            while (input >> line)
            {
                int value;

                std::cout << "CurrentLine: " << line << " =========" << std::endl;

                if (line.at(0) == 'R')
                {
                    line.erase(0, 1);
                    value = std::stoi(line);

                    int currentZero = zeroCount;

                    current = EvaluateRight(current, value);

                    std::cout << current << ", " << zeroCount - currentZero << std::endl;
                }

                if (line.at(0) == 'L')
                {
                    line.erase(0, 1);
                    value = std::stoi(line);

                    int currentZero = zeroCount;

                    current = EvaluateLeft(current, value);

                    std::cout << current << ", " << zeroCount - currentZero << std::endl;
                }
            }

            std::cout << "Password: " << zeroCount << std::endl;

            input.close();
        }
    }

private:
    int EvaluateRight (int pCurrent, int pValue)
    {
        while (pValue > 0)
        {
            pCurrent++;
            pValue--;

            if (pCurrent > 99)
            {
                pCurrent = 0;
                zeroCount++;
            }
        }

        return pCurrent;
    }

    int EvaluateLeft(int pCurrent, int pValue)
    {
        while (pValue > 0)
        {
            pCurrent--;
            pValue--;

            if (pCurrent == 0)
                zeroCount++;

            if (pCurrent < 0)
                pCurrent = 99;
        }

        return pCurrent;
    }
};

#endif //ADVENTOFCODE2025_DAY1_H