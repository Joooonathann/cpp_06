#include "./include/Serializer.hpp"
#include "./include/Data.hpp"

int main(void)
{
    //Init data
	Data *data = new Data;

	data->id = 1;
    data->name_product = "E5550";
    data->type = "Tools";
    data->amount = 1;
    data->price = 1.99;


    //Convert to unint and recover to Data
	uintptr_t raw = Serializer::serialize(data);
	Data *serialized = Serializer::deserialize(raw);

    //Print Data infos
	std::cout 
    << "ID: " << serialized->id << "\n"
	<< "Name: " << serialized->name_product << "\n"
	<< "Type: " << serialized->type << "\n"
    << "Amount: " << serialized->amount << "\n"
    << "Price: " << serialized->price <<
    std::endl;

	delete (data);
	return (0);
}