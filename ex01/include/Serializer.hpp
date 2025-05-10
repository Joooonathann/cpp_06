#pragma once

#include "./Data.hpp"
#include <iostream>
#include <stdint.h>

class Serializer
{
    private:
        Serializer(void);
        Serializer(const Serializer &copy);
        Serializer &operator=(const Serializer &copy);
        ~Serializer(void);
    public:
        static uintptr_t serialize(Data *data);
        static Data* deserialize(uintptr_t raw);
};