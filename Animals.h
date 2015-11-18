#ifndef ANIMALS_H
#define ANIMALS_H

#include <string>  //Needed for name of object


class Animal
{
	private:
		std::string name;
		bool alive;       //1
		bool big;
		bool cute;
		bool furry;
		bool fly;         //5
		bool warmBlooded;
		bool reptile;
		bool swim;
		bool tail;
		bool hibernate;    //10
		bool poison;
		bool fictional;
		bool extinct;
		bool pet;
		bool mammal;       //15
		bool carnivor;
		bool legs;
		bool scales;
		bool food;
		bool fourLegs;      //20
	public:
		Animal();
		~Animal();
		void populate(std::string,bool,bool,bool,bool,bool,bool,bool,bool,bool,bool,
				   bool,bool,bool,bool,bool,bool,bool,bool,bool,bool);
		bool get_trait(int);
};

#endif
