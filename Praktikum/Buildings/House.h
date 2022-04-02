#pragma once
#ifndef HOUSE_H
#define HOUSE_H
#include "Building.h"


class House
{
private:
	Building home;
	size_t floors;
	char* owner;
public:
	House()
	{
		this->floors = 1;
		this->owner = new char[8];
		strcpy_s(this->owner, 8, "Unknown");
	}

	~House()
	{
		delete this->owner;
	}

	void setOwner(const char* owner)
	{
		size_t sizeOfString = strlen(owner);
		this->owner = new char[sizeOfString + 1];
		strcpy_s(this->owner, sizeOfString + 1, owner);
	}

	void setFloors(size_t floors)
	{
		this->floors = floors;
	}

	size_t getFloors()const
	{
		return this->floors;
	}

	const char* getOwner()const
	{
		return this->owner;
	}

	void setHouse(const char* adress, size_t height, double size, size_t floors, const char* owner)
	{
		this->home.setAdress(adress);
		this->home.setHeight(height);
		this->home.setSize(size);

		setOwner(owner);
		setFloors(floors);
	}

	double getAvarageFloorHeight () const
	{
		return 1.0*(this->home.getHeight()) / this->floors;
	}

	void printHouse()
	{
		this->home.print();
		std::cout<<"Floors: "<< this->floors << std::endl;
		std::cout<<"Owner: "<< this->owner << std::endl;
	}


};
#endif