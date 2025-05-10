#include "../include/Serializer.hpp"

Serializer::Serializer(void) { }

Serializer::Serializer(const Serializer &copy)
{
    *this = copy;
}

Serializer &Serializer::operator=(const Serializer &copy)
{
    if (this != &copy)
        *this = copy;
    return (*this);
}

Serializer::~Serializer(void) { }

uintptr_t   Serializer::serialize(Data *data)
{
    return (reinterpret_cast<uintptr_t>(data));
}

Data        *Serializer::deserialize(uintptr_t raw)
{
    return (reinterpret_cast<Data *>(raw));
}