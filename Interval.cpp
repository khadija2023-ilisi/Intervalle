#include "Interval.h"
#include <iostream>
using namespace std;
using namespace math;

math::Interval::Interval(T left, T right)
{
	this->Lborn = left;
	this->Rborn = right;

}

int Interval::Min() const
{
	return this->Lborn;
}

int Interval::Max() const
{
	return this->Rborn;
}

Interval& math::Interval::Union(const Interval& Inte)
{
	Interval *uni = new Interval(min(this->Lborn,Inte.Lborn ),max(this->Rborn,Inte.Rborn ));
	return *uni;
}
bool math::Interval::Includans(const Interval& Inte)
{
	if (this->Lborn >= Inte.Lborn && this->Rborn <= Inte.Rborn)
		return true;
	return false;
}
Interval& math::Interval::Intersection( Interval& Inte)
{
	Interval inter(0,0);
	if (this->Rborn >= Inte.Lborn && Inte.Rborn >= this->Lborn)
	{
		if (this->Includans(Inte))
			inter = *this;
		else if (Inte.Includans(*this))
			inter = Inte;
		else
		{
			inter.Lborn = max(this->Lborn,Inte.Lborn);
			inter.Rborn = min(this->Rborn,Inte.Rborn);
		}
	}
	return inter;
}

bool math::Interval::operator[](T elem)
{
	if(elem <= this->Rborn && elem >= this->Lborn)
		return true;
	return false;
}

void math::Interval::afficher() const
{
	if (this->Lborn == 0 && this->Rborn == 0)
		cout << "l'ensemble vide\n";
	else
		cout << "l'interval courant est : ["<<this->Lborn<< ","<<this->Rborn << "]\n";
}



