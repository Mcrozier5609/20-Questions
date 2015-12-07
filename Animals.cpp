//Animal 20-Questions 2015
//Jonny Schmitt, Michael Crozier, Scott Schubert, Sean Hansberry
#include "Animals.h"

using namespace std;

#include <string>  //Needed for name of object

Animal::~Animal(){
	//destroy things
}

Animal::Animal(std::string name_in,bool alive_in,bool big_in,bool cute_in,bool furry_in,bool fly_in,
	bool warmBlooded_in,bool reptile_in,bool swim_in,bool tail_in,
	bool hibernate_in,bool poison_in,bool fictional_in,bool extinct_in,
	bool pet_in,bool mammal_in,bool carnivor_in,bool legs_in,
	bool scales_in,bool food_in,bool fourLegs_in,bool whiskers_in, bool articLife_in, bool jungleLife_in, 
	bool aquaticLife_in, bool packAnimal_in, Animal*pointer_in)
{
	rank = 0;
	strike = 0;
	next = pointer_in;

	name = name_in;
	alive = alive_in;
	big = big_in;
	cute = cute_in;
	furry = furry_in;
	fly = fly_in;
	warmBlooded = warmBlooded_in;
	reptile = reptile_in;
	swim = swim_in;
	tail = tail_in;
	hibernate = hibernate_in;
	poison = poison_in;
	fictional = fictional_in;
	extinct = extinct_in;
	pet = pet_in;
	mammal = mammal_in;
	carnivor = carnivor_in;
	legs = legs_in;
	scales = scales_in;
	food = food_in;
	fourLegs = fourLegs_in;
	whiskers = whiskers_in;
	articLife = articLife_in;
	jungleLife = jungleLife_in;
	aquaticLife = aquaticLife_in;
	packAnimal = packAnimal_in;
}

bool Animal::get_trait(int slot)
{
	bool ret = true;
	switch (slot){
		case 0:
			ret = alive;
			break;
		case 1:
			ret = big;
			break;
		case 2:
			ret = cute;
			break;
		case 3:
			ret = furry;
			break;
		case 4:
			ret = fly;
			break;
		case 5:
			ret = warmBlooded;
			break;
		case 6:
			ret = reptile;
			break;
		case 7:
			ret = swim;
			break;
		case 8:
			ret = tail;
			break;
		case 9:
			ret = hibernate;
			break;
		case 10:
			ret = poison;
			break;
		case 11:
			ret = fictional;
			break;
		case 12:
			ret = extinct;
			break;
		case 13:
			ret = pet;
			break;
		case 14:
			ret = mammal;
			break;
		case 15:
			ret = carnivor;
			break;
		case 16:
			ret = legs;
			break;
		case 17:
			ret = scales;
			break;
		case 18:
			ret = food;
			break;
		case 19:
			ret = fourLegs;
			break;
		case 20:
			ret = whiskers;
			break;
		case 21:
			ret = articLife;
			break;
		case 22: 
			ret = jungleLife;
			break;
		case 23: 
			ret = aquaticLife;
			break;
		case 24: 
			ret = packAnimal;
			break;
		//etc
	}
	return ret;
}

int Animal::get_rank(){
	return rank;
}

void Animal::up_rank(){
	rank++;
}

void Animal::up_strike(){
	strike++;
}

bool Animal::strike_out(){
	bool ret = false;
	if (strike >= 3){
		ret = true;
	}
	return ret;
}

std::string Animal::get_name(){
	return name;
}
