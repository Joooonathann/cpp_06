#include <iostream>
#include <ctime>
#include <cstdlib>
#include "./include/Base.hpp"
#include "./include/A.hpp"
#include "./include/A.hpp"
#include "./include/B.hpp"
#include "./include/C.hpp"

Base    *generate(void)
{
    int randn;

    randn = rand() % 3;
    if (randn == 0)
        return (new A);
    else if (randn == 1)
        return (new B);
    else
        return (new C);
}

void    identify(Base *ptr)
{
    if (dynamic_cast<A *>(ptr))
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B *>(ptr))
        std::cout << "B" << std::endl;
     else if (dynamic_cast<C *>(ptr))
        std::cout << "C" << std::endl;
}

void identify(Base &ref) {
    try {
        A  &a = dynamic_cast<A &>(ref);
        (void)a;
        std::cout << "A" << std::endl;
    }
    catch (std::exception &e) {}
    try {
        B &b = dynamic_cast<B &>(ref);
        (void)b;
        std::cout << "B" << std::endl;
    }
    catch (std::exception &e) {}
    try {
        C &c = dynamic_cast<C &>(ref);
        (void)c;
        std::cout << "C" << std::endl;
    }
    catch (std::exception &e) {}
}

int     main(void)
{
    srand(time(NULL));
    Base    *ptr = generate();;
    Base    &ref = *ptr;;

    identify(ptr);
    identify(ref);
    delete (ptr);
    return (0);
}