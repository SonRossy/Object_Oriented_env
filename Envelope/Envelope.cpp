// Envelope.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

//creating a class for envelope
 class Envelope
 {
 private:
	 float lenght;
	 float width;
 public:
	 //setters and getters
	 void setLength(float L);
	 float getLength();

	 void setWidth(float W);
	 float getWidth();

	 
 };

 // a class to charge customer
 class Charge
 {
 private:
	 float price;
 public:
	 float getPrice();
	 void setPrice( float P);
	 float total();
	 Envelope envelope;//create an instance of Envelope


 };


int main()
{
	//create an object of the charge class:
	Charge charge;

	//get the charge of an envelope
	charge.total();

	//output the final price
	std::cout << " you are charged: " << charge.getPrice()<<" dollars \n";
	system("pause");
    return 0;
}


//function definitions
void Envelope::setLength(float L)
{
	lenght = L;
}

float Envelope::getLength()
{
	return lenght;
}

void Envelope::setWidth(float W)
{
	width = W;
}

float Envelope::getWidth()
{
	return width;
}

float Charge::getPrice()
{
	return price;
}

void Charge::setPrice(float P)
{
	price = P;
}

float Charge::total()
{
	//variables to hold data
	float TLenght, TPrice, TWidth;
	Charge::setPrice(0);
	int numberOfEnvelope;
	std::cout << "you will be charged a dollar and fifty cents for each inch on Lenght and width  of the envelope\n";
	std::cout << "how many envlope would you like to buy: ";
	std::cin >> numberOfEnvelope;

	for (int i = 1; i <= numberOfEnvelope;i++)
	{
		//getting values from users
		std::cout << " Enter the width for the envlope size "<<i<<" : ";
		std::cin >> TWidth;
		std::cout << " Enter the lenght for the envlope size "<<i << " : ";
		std::cin >> TLenght;

		//setting the values from the user to the envlope class
		envelope.setLength(TLenght);
		envelope.setWidth(TWidth);

		//calculate the price
		TPrice = (envelope.getWidth()*1.50) + (envelope.getLength()*1.50);

		//setting the calculated price to the class
		if (Charge::getPrice() ==0)
		{
			Charge::setPrice(TPrice);
		}
		else
		{
			Charge::setPrice(TPrice + Charge::getPrice());
		}
		
	}
	


	
	return Charge::getPrice();
}
