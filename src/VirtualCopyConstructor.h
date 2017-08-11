#include <iostream>
#include <cstdio>
#include <string>


class Base {


public:
    virtual void print() const = 0;
    virtual Base * clone () const = 0;

    Base (int value_) : value (value_) {}

protected:
    int value;

};




class Derived1 : public Base 
{
public:

    Derived1 (int value) : Base(value) {}

    void print () const 
    {   std::cout <<"Derived1: value = "<<value<< " \n";  }

    Base * clone() const 
    {   return new Derived1(*this);    }

};

class Derived2 : public Base 
{
public:

    Derived2 (int value) : Base(value) {}

    void print () const 
    {   std::cout <<"Derived2: value = "<<value<< " \n";  }

    Base * clone() const 
    {    return new Derived2(*this);    }
    
};


class Factory 
{
public:
    Base * create(int kind, int value)
    {
        if (kind != 1 && kind != 2) {
            throw "Failed to create object: parameter 'kind' must take value 1 or 2.  Provided value of 'kind': " + std::to_string(kind);;
        }

        switch(kind)
        {
            case 1: return new Derived1(value); 
            case 2: return new Derived2(value); 
        };
    };

    

};


