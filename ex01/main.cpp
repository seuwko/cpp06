#include "Serializer.hpp"

int main(void)
{
    Data obj;
    obj.data = "default";

    uintptr_t strct_ptr = Serializer::serializer(&obj);

    std::cout << "obj data : " << obj.data << " / obj address : " << &obj << std::endl;

    Data *obj2;
    obj2 = Serializer::deserialize(strct_ptr);

    std::cout << "obj2 data : " << obj2->data << " / obj2 address : " << obj2 << std::endl;
    return (0);
}