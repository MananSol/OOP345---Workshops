#ifndef SDDS_RACECAR_H
#define SDDS_RACECAR_H
#include <iostream>
#include "Car.h"

using namespace std;
namespace sdds
{
	class Racecar : public Car
	{
		double m_booster = 0;

	public:
		//constructor
		Racecar(std::istream& in);
		//destructor
		~Racecar();
		//print
		void display(std::ostream& out)const;
		//getter
		double topSpeed()const;
	};
}

#endif // !SDDS_RACECAR_H