#include "Serialization.hpp"

int main()
{
    Data *myData = new Data;

    myData->str = "muguveli";
    myData->value = 42;


    uintptr_t serializedData = Serialization::serialize(myData);
    std::cout << "long : " << serializedData << std::endl;
    Data* deserializedData = Serialization::deserialize(serializedData);
    std::cout << "adress : " << deserializedData << std::endl;


    std::cout << "Original data: " << myData->str << ", " << myData->value << std::endl;
    std::cout << "Original data address: " << myData << std::endl;
    std::cout << "Deserialized data: " << deserializedData->str << ", " << deserializedData->value << std::endl;
    std::cout << "Deserialized data address: " << deserializedData << std::endl;
    delete myData;
    return 0;
}
