#include <iostream>
#include <stdio.h>
#include <string>
#include <fstream>
#include <cstdlib>
#include <unistd.h>
#include "Animals.h"

using namespace std;

int rankAnimal(string info, string attribute_list[]){
	int rank = 0;
	for (int q = 0; q < 20; q++){
		//cout<<info.substr(2*q,1)<<endl;
		if (info.substr(2*q,1)==attribute_list[q]){
			rank++;
		}
	}
	return rank;
}

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

string topAnimal(string attribute_list[]){
	ifstream file;
	file.open("Animals.txt");
	string line;
	int pos;
	string animal = "thing";
	int maxrank = 0;
	int currank;
	getline(file, line);
	while (!file.eof()){
		pos = line.find(",");
		//cout<<line<<endl;
		//cout<<line.substr(pos+1,40)<<endl;
		currank = rankAnimal(line.substr(pos+1,40),attribute_list);
		if (currank>maxrank){
			maxrank = currank;
			animal = line.substr(0,pos);
		}
		getline(file, line);
	}
	file.close();
	return animal;
}

int main(){
	string ans;
	string q[20] = {"Is it alive","Is it big","Is it cute","Is it furry","Can it fly","Is it warm blooded",
			"Is it a reptile","Can it swim","Does it have a tail","Does it hibernate","Is it poisonous",
			"Is it extinct","Is it a pet","Is it a mammal","Is it a carnivor","Does it have legs",
			"Does it have scales","Do people eat it","Is it fictional","Is it four legged"};
	int question_number = 1;
	int animal_count = 46;
	string attribute_list[20];
	int attribute_pos = 0;
	Animal Alist[animal_count];
	cout<<"archiving"<<endl;
	archive(Alist);
	cout<<"archived"<<endl;

	while (question_number <=20){
		cout << "Question " << question_number << ": " << q[question_number-1] << "?" << endl;
		cin >> ans;
		if (ans == "y" || ans == "yes" || ans == "indubitably"){
		
			//add to animal traits
			attribute_list[attribute_pos] = '1';  
			attribute_pos++;
			question_number++;
			
		} else if (ans == "n" || ans == "no" || ans == "nay"){
		
			//add to animal traits
			attribute_list[attribute_pos] = '0';
			attribute_pos++;
			question_number++;
		
		} else{
		
			cout << "invalid response" << endl;
		
		}
	}
	
	cout << endl;
	cout << "it's a..." << endl;
	
	//Use Attribute list to find best animal match
	string best_Animal = topAnimal(attribute_list);	
	
	cout << best_Animal << endl;
}
