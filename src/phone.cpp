#include <utility>
#include <iostream>
#include <string>
#include <iomanip>
#include "phone.h"
#include "person.h"

Phone::Phone()
{

    clear();
}

Phone::~Phone()
{
    for (auto it = addresBok.begin(); it != addresBok.end(); ++it)
    {
        delete it->second;
    }
}

bool Phone::addPerson()
{
    Person *newPerson;

    std::string contact, number;
    std::cout << "Add contact name: ";
    std::getline(std::cin, contact);

    auto it = addresBok.find(contact);

    if (it != addresBok.end())
    {
        std::cout << "Such a contact already exists" << std::endl;
        return false;
    }
    else
    {
        newPerson = new Person;
        newPerson->setName(contact);
    }

    std::pair<bool, const char *> ret;
    do
    {
        std::cout << "Add number for " << contact << ": ";
        std::getline(std::cin, number);

        ret = newPerson->setNumber(number);
        if (!ret.first)
        {
            std::cout << ret.second << " try again" << std::endl;
        }

    } while (!ret.first);

    auto bok = addresBok.insert(std::make_pair(newPerson->getName(), newPerson));
    if (bok.second)
    {
        std::cout << "The contact was successfully added" << std::endl;
        std::cout << bok.first->first << std::endl;
        std::cout << bok.first->second->getNumberInfo();
    }
    else
    {
        std::cout << "Error: Such a contact already exists" << std::endl;
        std::cout << bok.first->first << std::endl;
        std::cout << bok.first->second->getNumberInfo();
        return false;
    }
    maxName = (maxName > contact.size()) ? maxName : contact.size();
    drawBook();
    return true;
}

void Phone::clear()
{
#if defined(__unix__) || defined(__APPLE__)
    system("clear");
#elif defined(_WIN32) || defined(_WIN64)
    system("cls");
#endif
}

void Phone::drawBook()
{
    std::ios_base::fmtflags ff;
    ff = std::cout.flags();
    ff |= std::ios_base::left;
    std::cout.setf(ff);

    clear();
    std::cout << "PHONE BOOK" << std::endl;

    std::cout << std::setw(maxName + 2) << "[NAME]" << std::setw(14) << "[NUMBER]"
              << "[INFO]" << std::endl;
    for (auto it = addresBok.begin(); it != addresBok.end(); ++it)
    {
        auto ret = it->second->getNumberInfo();
        std::cout << std::setw(maxName + 2) << it->second->getName()
                  << std::setw(14) << it->second->getNumber()
                  << ret->getOperator() << " " << ret->getRegion() << std::endl;
    }
}