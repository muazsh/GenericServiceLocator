# Generic Service Locator

Regardless of all disputes whether service locator is a pattern or anti-pattern, this introduces a generic container which can hold only one instance of a class, so it can be used as a service locator or a generic place holder.  


# Usage:
``` c++
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
        locator.AddService<Service1>(s1);
        auto s2 = std::make_shared<Service2>();
        locator.AddService<Service2>(s2);
    }

    auto& service1 = locator.GetService<Service1>();
    assert("Service1" == service1->WhoAmI());

    auto& service2 = locator.GetService<Service2>();
    assert("Service2" == service2->WhoAmI());

    assert(nullptr == locator.GetService<Service3>());

    locator.RemoveService<Service2>();
    assert(nullptr == locator.GetService<Service2>());
}
```
