#pragma once
#include <map>

class Person;

class Phone
{
    std::map<std::string, Person *> addresBok;
    std::map<std::string, Person *> p_addresBok;
    size_t maxName{10};
    void clear();
    void drawCall(const std::map<std::string, Person *>::iterator &it);
    void drawsendMessage(const std::map<std::string, Person *>::iterator &it, const std::string &message);

public:
    Phone();
    ~Phone();
    void drawBook();
    bool addPerson();
    void callPerson(const std::string &contact);
    void sendMessage(const std::string &contact, const std::string &message);
};