#include "Serializer.hpp"

int main(void)
{
	Data data;

	data.Value = 42;

	Data* ptr = &data;
	uintptr_t raw = Serializer::serialize(ptr);

	Data* ptr2 = Serializer::deserialize(raw);

	if (ptr == ptr2)
	std::cout << "Same adress: " << ptr << " - " << ptr2 << std::endl;

	if (ptr2->Value == 42)
		std::cout << "Ptr2 value = " << ptr2->Value << std::endl;
	return 0;
}

