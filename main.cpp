#include <iostream>
#include <stdio.h>
#include <string>
#include <fstream>
#include <cstdlib>
#include <unistd.h>
#include "Animals.h"

using namespace std;

bool tobool(string number){
	bool ret = false;
	if (number == "1"){
		ret = true;
	}
	return ret;
}

Animal* archive(Animal Alist[]){
	ifstream file;
	file.open("Animals.txt");
	string line;
	string info;
	int pos;
	int count = 0;
	getline(file, line);
	while(!file.eof()){
		pos = line.find(",");
		info = line.substr(pos+1,40);
		Alist[count].populate(line.substr(0,pos),tobool(info.substr(0,1)),tobool(info.substr(2,1)),
				tobool(info.substr(4 ,1)),tobool(info.substr(6 ,1)),tobool(info.substr(8 ,1)),
				tobool(info.substr(10,1)),tobool(info.substr(12,1)),tobool(info.substr(14,1)),
				tobool(info.substr(16,1)),tobool(info.substr(18,1)),tobool(info.substr(20,1)),
				tobool(info.substr(22,1)),tobool(info.substr(24,1)),tobool(info.substr(26,1)),
				tobool(info.substr(28,1)),tobool(info.substr(30,1)),tobool(info.substr(32,1)),
				tobool(info.substr(34,1)),tobool(info.substr(36,1)),tobool(info.substr(38,1)));
		getline(file,line);
		count++;
	}
	file.close();
	return Alist;
}

Animal* run_q(int qnum, Animal Alist[], int anum, bool qans){
	for (int i = 0; i < anum; i++){
		if (qans == Alist[i].get_trait(qnum)){
			Alist[i].up_rank();
		}
	}
}

Animal get_max_rank(Animal Alist[], int anum){
	int maxrank = Alist[0].get_rank();
	Animal ret = Alist[0];
	for (int i = 1; i < anum; i ++){
		if (Alist[i].get_rank() > maxrank){
			maxrank = Alist[i].get_rank();
			ret = Alist[i];
		}
	}
	return ret;
}

int main(){
	string ans;
	string q[20] = {"Is it alive","Is it big","Is it cute","Is it furry","Can it fly","Is it warm blooded",
			"Is it a reptile","Can it swim","Does it have a tail","Does it hibernate","Is it poisonous",
			"Is it extinct","Is it a pet","Is it a mammal","Is it a carnivor","Does it have legs",
			"Does it have scales","Do people eat it","Is it fictional","Is it four legged"};
	int question_number = 0;
	int animal_count = 46;
	Animal Alist[animal_count];
	archive(Alist);
	cout<<"archived"<<endl;

	while (question_number <20){
		cout << "Question " << (question_number+1) << ": " << q[question_number] << "?" << endl;
		cin >> ans;
		if (ans == "y" || ans == "yes" || ans == "indubitably"){
		
			//add to animal traits
			run_q(question_number, Alist, animal_count, true);  
			question_number++;
			
		} else if (ans == "n" || ans == "no" || ans == "nay"){
		
			//add to animal traits
			run_q(question_number, Alist, animal_count, false);
			question_number++;
		
		} else{
		
			cout << "invalid response" << endl;
		
		}
	}
	
	cout << endl;
	cout << "it's a..." << endl;
	
	//Use Attribute list to find best animal match
	Animal best_Animal = get_max_rank(Alist, animal_count);	
	string guess = best_Animal.get_name();
	cout << guess << endl;
}
