#include "Dog.hpp"
#include "Cat.hpp"

// int main( void )
// {
//
// 	const AAnimal* dog = new Dog();
// 	const AAnimal* cat = new Cat();

// 	std::cout << std::endl;

// 	delete dog;
// 	delete cat;
// 	std::cout << std::endl;
// 	std::cout << std::endl;

//
// 	Dog medor;
// 	Cat fifi;

// 	std::cout << std::endl << "creating copies" << std::endl;

//
// 	const AAnimal	*(animal_array[4]);

// 	std::cout << std::endl;
//
// 	for (int i = 0; i < 2; i++)
// 		animal_array[i] = new Dog();
// 	std::cout << std::endl;

//
// 	for (int i = 2; i < 4; i++)
// 		animal_array[i] = new Cat();
// 	std::cout << std::endl;

// 	for (int i = 0; i < 4; i++)
// 		delete animal_array[i];
// 	std::cout << std::endl;

// }

int main()
{
	AAnimal *aanimal1 = new Dog();
	AAnimal *aanimal2 = new Cat();

	aanimal1->makeSound(); 
	aanimal2->makeSound(); 

	delete aanimal1;
	delete aanimal2;
	// AAnimal a;
	return 0;
}
