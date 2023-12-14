#include "Transport.h"

double Transport::getTime(double distance) const
{
	return (distance / speed);
}

double Transport::getPrice_ticket() const
{
	return price_ticket;
}

void Transport::print() const
{
	cout << "Transport: " << "price = " << price_ticket << "\tspeed = " << speed << " km/h" << endl;
}

PublicTransport::~PublicTransport()
{
	delete[] number;
}

void PublicTransport::print() const
{
	cout << "Public Transport: " << number << "\tprice = " << price_ticket << "\tspeed = " << speed << " km/h" << endl;
}

char* PublicTransport::getNumber() const
{
	return number;
}

void FarmTransport::print() const
{
	cout << "Farm Transport: " << "price = " << price_ticket << "\tspeed = " << speed << " km/h" << endl;
}

void PassengerCar::print() const
{
	cout << "Passenger Transport: " << "price = " << price_ticket << "\tspeed = " << speed << " km/h" << endl;
}

void Truck::print() const
{
	cout << "Truck: " << "price = " << price_ticket << "\tspeed = " << speed << " km/h" << endl;
}

void Motorcycle::print() const
{
	cout << "Motorcycle: " << "price = " << price_ticket << "\tspeed = " << speed << " km/h" << endl;
}

void Scooter::print() const
{
	cout << "Scooter: " << "price = " << price_ticket << "\tspeed = " << speed << " km/h" << endl;
}

Transport* CreateTransport() {
	int n = rand() % 6;
	switch (n) {
	case 0: return new PublicTransport(rand() % 100 + 1, rand() % 200, "A1");
	case 1: return new FarmTransport(rand() % 70 + 1, rand() % 200);
	case 2: return new PassengerCar(rand() % 180 + 1, rand() % 200);
	case 3: return new Truck(rand() % 170 + 1, rand() % 200);
	case 4: return new Motorcycle(rand() % 200 + 1, rand() % 200);
	case 5: return new Scooter(rand() % 120 + 1, rand() % 200);
	}
}

double SumPrice(Transport**& transports, size_t size) {
	double sum = 0;
	for (int i = 0; i < size; ++i)
		sum += transports[i]->getPrice_ticket();
	return sum;
}
double Time(Transport**& transports, size_t size, double distance) {
	double time = 0;
	for (int i = 0; i < size; ++i)
		time += transports[i]->getTime(distance);
	return time;
}