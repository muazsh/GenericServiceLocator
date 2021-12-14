// GenericServiceLocator.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "GenericServiceLocator.h"
#include <assert.h>

class Service1
{
public:
    std::string WhoAmI()
    {
        return "Service1";
    }

};

class Service2
{
public:
    std::string WhoAmI()
    {
        return "Service2";
    }

};

class Service3
{
public:
    std::string WhoAmI()
    {
        return "Service3";
    }

};

int main()
{
    gsl::GenericServiceLocator locator;

    {
        auto s1 = std::make_shared<Service1>();
        locator.AddService(s1);
        auto s2 = std::make_shared<Service2>();
        locator.AddService(s2);
    }

    auto& service1 = locator.GetService<Service1>();
    assert("Service1" == service1->WhoAmI());

    auto& service2 = locator.GetService<Service2>();
    assert("Service2" == service2->WhoAmI());

    assert(nullptr == locator.GetService<Service3>());

    locator.RemoveService<Service2>();
    assert(nullptr == locator.GetService<Service2>());
}
