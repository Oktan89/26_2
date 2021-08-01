#include <fstream>
#include "number.h"

bool Number::setNumber(const std::string &number)
{
    if (number.empty())
    {
        return false;
    }
    else if (number.size() > 16 || number.size() < 10)
    {
        return false;
    }

    
    for (int i = 0, j = 0; i < number.size(); ++i, ++j)
    {
        if (j == 0)
        {
            if (number[i] == '+')
            {
                this->number.push_back(number[i]);
            }
            else
            {
                this->number.push_back('+');
                ++j;
            }
        }
        if (j == 1)
        {
            if (number[i] == '7' || number[i] == '8')
            {
                this->number.push_back('7');
            }
            else
            {
                this->number.push_back('7');
                ++j;
            }
        }
        if (j >= 2)
        {
            if (number[i] == ' ' || number[i] == '-')
            {
                continue;
            }
            if (!isdigit(number[i]))
            {
                this->number.clear();
                return false;
            }
            this->number.push_back(number[i]);
        }
    }
    if (this->number.size()>12)
    {
        this->number.clear();
        return false;
    }
    
    return findOperator();
}

bool Number::findOperator()
{
    std::ifstream file("DEF-9xx.csv");
    std::string buff;
    std::string cod = number.substr(2, 3);
    std::string num = number.substr(5, 7);
    while(!file.eof())
    {
        std::getline(file, buff);
        if(buff.substr(0,3) == cod)
        {
            if(num > buff.substr(4, 7) && num < buff.substr(12, 7))
            {
                const auto _pos = buff.find_last_of(';');
                _region = buff.substr(_pos+1);
                const auto __pos = buff.rfind(';', _pos-1);
                _operator = buff.substr(__pos+1, _pos-__pos-1);
                //std::cout<<buff<<std::endl;
                break;
            }
        }
        
    }
    
    file.close();
    if(_region.size() == 0)
    {
        number.erase();
        return false;
    }
    return true;
}