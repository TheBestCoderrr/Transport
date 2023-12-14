#include "Transport.h"
int main() {
	srand(time(0));
	double distance;
	cout << "Enter distance: ";
	cin >> distance;
	size_t size;
	cout << "Enter count transports: ";
	cin >> size;
	Transport** transports = new Transport * [size];
	for (int i = 0; i < size; ++i) {
		transports[i] = CreateTransport();
		transports[i]->print();
	}
	cout << "Sum = " << SumPrice(transports, size) << endl;
	cout << "Time = " << Time(transports, size, distance) << endl;
	for (int i = 0; i < size; ++i)
		delete transports[i];
	delete[] transports;
}