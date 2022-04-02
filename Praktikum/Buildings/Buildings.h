#pragma once
#ifndef BUILDINGS_H
#define BUILDINGS_H
#include <iostream>


class Building
{

private:
	size_t height;
	double size;
	char* adress;

public:

	Building()
	{
		this->height = 2;
		this->size = 20;
		this->adress = new char[8];
		strcpy_s(this->adress, 8, "Unknown");
	}

	~Building()
	{
		delete this->adress;
	}

	void setHeight(size_t height)
	{
		this->height = height;
	}

	void setSize(double size)
	{
		this->size = size;
	}

	void setAdress(const char* adress)
	{
		size_t lenght = strlen(adress);
		this->adress = new char[lenght+1];
		strcpy_s(this->adress, lenght+1, adress);
		std::cout << this->adress;
	}

	const char* getAdress()const
	{
		return this->adress;
	}

	double getSize()const
	{
		return this->size;
	}

	size_t getHeight()const
	{
		return this->height;
	}

	void print()const
	{
		std::cout << "Size: " << this->size<<std::endl;
		std::cout << "Height: " << this->height<< std::endl;
		std::cout << "Adress: " << this->adress << std::endl;
	}

};
#endif

