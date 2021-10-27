#pragma once
namespace math {
	typedef int T;
	class Interval
	{
	private:
		T Lborn;
		T Rborn;
	public:
		Interval(T, T);
		int Min()const;
		int Max()const;
		Interval& Union(const Interval&);
		bool Includans(const Interval&);
		Interval& Intersection( Interval&);
		bool operator[](T);
		void afficher()const;
		
	};

};