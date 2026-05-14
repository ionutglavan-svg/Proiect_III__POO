#pragma once
#include <exception>
#include <string>
class Eroare:public std::exception
{
protected:
    std::string mesaj;
public:
    Eroare(const std::string& m);
    virtual const char* what() const noexcept override;

};

class NumeProdusInexistentException : public Eroare {
public:
    NumeProdusInexistentException(const std::string& nume);
       
};

class StocInsuficientException : public Eroare {
public:
    StocInsuficientException();
};

class InputInvalidException : public Eroare {
public:
    InputInvalidException();
};

