#ifndef ANIMALS
#define ANIMALS

#include <string>  //Needed for name of object


struct Animal
{
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
	Animal() {};

	Animal (std::string name_in,bool alive_in,bool big_in,bool cute_in,bool furry_in,bool fly_in,
		bool warmBlooded_in,bool reptile_in,bool swim_in,bool tail_in,
		bool hibernate_in,bool poison_in,bool fictional_in,bool extinct_in,
		bool pet_in,bool mammal_in,bool carnivor_in,bool legs_in,
		bool scales_in,bool food_in,bool fourLegs_in)
	{
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
	}

};



#endif