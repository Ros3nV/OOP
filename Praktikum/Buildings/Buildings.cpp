#include"House.h"

const int maxSize = 25;

struct groupOfHouses
{
	House* houses;
};


int maxAverageFloorHeight(size_t numberOfHouses, groupOfHouses& Collection)
{
	int indexOfMaxAverageFloorHeight = 0;
	if(numberOfHouses!=1)
	{ 
		double maxHeight = Collection.houses[0].getAvarageFloorHeight();

		for (int i = 1; i < numberOfHouses; i++)
		{
			if (maxHeight < Collection.houses[i].getAvarageFloorHeight())
			{
				maxHeight = Collection.houses[i].getAvarageFloorHeight();
				indexOfMaxAverageFloorHeight = i;
			}
		}

	}
	return indexOfMaxAverageFloorHeight;
}



void setHouses(size_t numberOfHouses, groupOfHouses& Collection)
{
	for (int i = 0; i < numberOfHouses; i++)
	{
		char* adress = new char[maxSize];
		char* owner = new char[maxSize];
		std::cout << "Enter adress of house: ";
		std::cin.getline(adress, maxSize);

		std::cout << "Enter height of house: ";
		size_t height;
		std::cin >> height;

		std::cout << "Enter size of house: ";
		double size;
		std::cin >> size;

		std::cout << "Enter floors of house: ";
		size_t floors;
		std::cin >> floors;

		std::cout << "Enter owner of house: ";
		std::cin.ignore();
		std::cin.getline(owner, maxSize);

		Collection.houses[i].setHouse(adress, height, size, floors, owner);
		std::cout << std::endl;
		std::cout << std::endl;
		delete[] owner;
	    delete[] adress;
		
	}
	
}


int main()
{
	groupOfHouses Collection;
	size_t numberOfHouses=0;
	std::cout << "Enter number of Houses: ";
	std::cin >> numberOfHouses;
	while (numberOfHouses == 0)
	{
		std::cout << "Invalid number, try again: ";
		std::cin >> numberOfHouses;
	}
	std::cin.ignore();
	Collection.houses = new House[numberOfHouses];
	setHouses(numberOfHouses, Collection);



	std::cout << std::endl;
	std::cout << std::endl;


	std::cout << "	The most spacious house IS:   " << std::endl;


	Collection.houses[maxAverageFloorHeight(numberOfHouses, Collection)].printHouse();

	
}