#include "Serializer.hpp"

Serializer::Serializer() {
	std::cout << "Default constructor called" << std::endl;
}

Serializer::Serializer(const Serializer &other) {
	(void)other;
	std::cout << "constructor called" << std::endl;
}

Serializer &Serializer::operator=(const Serializer &other) {
	(void)other;
	std::cout << "Copy assignment operator called" << std::endl;
	return *this;
}

uintptr_t Serializer::serialize(Data* ptr) {
	return reinterpret_cast<uintptr_t>(ptr);
}

Data* Serializer::deserialize(uintptr_t raw)
{
	return reinterpret_cast<Data *>(raw);
}
