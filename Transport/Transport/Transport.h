#pragma once
#include <iostream>
using namespace std;

__interface Itransport {
	void print() const;
	double getTime(double distance) const;
};

class Transport :public  Itransport
{
public:
	Transport() : Transport(0,0) {}
	Transport(double speed, double price_ticket) : speed(speed), price_ticket(price_ticket) {}
	double getTime(double distance) const override;
	double getPrice_ticket() const;
	void print() const;
protected:
	double speed; 
	double price_ticket; 
};

class PublicTransport : public Transport {
public:
    PublicTransport(double speed, double price_ticket, const char* number) : Transport(speed, price_ticket), number(_strdup(number)) {}
	~PublicTransport();
	void print() const override;
	char* getNumber() const;
private:
	char* number;
};

class FarmTransport : public Transport {
public:
	FarmTransport(double speed, double price_ticket) : Transport(speed, price_ticket) {}
	void print() const override;
};

class PassengerCar : public Transport {
public:
	PassengerCar(double speed, double price_ticket) : Transport(speed, price_ticket) {}
	void print() const override;
};

class Truck : public Transport {
public:
	Truck(double speed, double price_ticket) : Transport(speed, price_ticket) {}
	void print() const override;
};

class Motorcycle : public Transport {
public:
	Motorcycle(double speed, double price_ticket) : Transport(speed, price_ticket) {}
	void print() const override;
};

class Scooter : public Transport {
public:
	Scooter(double speed, double price_ticket) : Transport(speed, price_ticket) {}
	void print() const override;
};

Transport* CreateTransport();
double SumPrice(Transport**& transports, size_t size);
double Time(Transport**& transports, size_t size, double distance);