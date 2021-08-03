#include <fstream>
#include <ostream>
#include <utility>
#include "number.h"

std::pair<bool, const char*> Number::setNumber(const std::string &number)
{
    if (number.empty())
    {
        return std::make_pair(false, "The number is not specified");
    }
    else if (number.size() > 16 || number.size() < 10)
    {
        return std::make_pair(false, "Incorrect number of digits in the number");
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
                return std::make_pair(false, "Incorrect number");
            }
            this->number.push_back(number[i]);
        }
    }
    if (this->number.size() !=12)
    {
        this->number.clear();
        return std::make_pair(false, "Incorrect number size");
    }
    
    return findOperator();
}

std::pair<bool, const char*> Number::findOperator()
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
        return std::make_pair(false, "the number is not a cellular number");
    }
    return std::make_pair(true, number.c_str());
}

const char* Number::getNumber()
{
    return (number.size() == 0)? "Number not set" : number.c_str();
}

const char* Number::getOperator()
{
    return (_operator.size() == 0)? "The operator is not defined" : _operator.c_str();
}

const char* Number::getRegion()
{
    return (_region.size() == 0)? "The region is not defined" : _region.c_str();
}

std::ostream& operator<< (std::ostream &out, const Number* _number)
{
    if(_number != nullptr && _number->number.size() != 0)
    {
        out<<_number->number<<std::endl;
        out<<_number->_operator<<std::endl;
        out<<_number->_region<<std::endl;  
 
    }
    
    return out;
}