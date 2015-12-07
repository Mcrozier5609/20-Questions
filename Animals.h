/**
   20-Questions 2015
   Jonny Schmitt, Michael Crozier, Scott Schubert, Sean Hansberry
*/
#ifndef ANIMALS_H
#define ANIMALS_H

#include <string>  //Needed for name of object


class Animal
{
	private:
		std::string name;
		int rank;
		int strike;
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
		bool whiskers;
		bool articLife;
		bool jungleLife;
		bool aquaticLife;
		bool packAnimal;	//25
	public:
		~Animal();
		Animal(std::string,bool,bool,bool,bool,bool,bool,bool,bool,bool,bool,
		    		   bool,bool,bool,bool,bool,bool,bool,bool,bool,bool,bool,bool,bool,bool,bool,Animal*);
		bool get_trait(int);
		int get_rank();
		void up_rank();
		void up_strike();
		bool strike_out();
		std::string get_name();

		Animal * next;
};

#endif
