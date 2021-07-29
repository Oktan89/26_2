#include "number.h"

bool Number::setNumber(const std::string &number)
{
    if (number.empty())
    {
        return false;
    }
    else if (number.size() > 12)
    {
        return false;
    }

    
    for (int i = 0; i < number.size(); ++i)
    {
        if (i == 0)
        {
            if (number[i] == '+')
            {
                this->number.push_back(number[i]);
            }
            else
            {
                this->number.push_back('+');
            }
        }
        if (i == 1)
        {
            if (number[i] != '7')
            {
                return false;
            }
            else
            {
                this->number.push_back(number[i]);
            }
        }
        if (i >= 2)
        {
            if (!isdigit(number[i]))
            {
                return false;
            }
            this->number.push_back(number[i]);
        }
    }

    return true;
}