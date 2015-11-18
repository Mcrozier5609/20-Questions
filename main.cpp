#include <iostream>
#include <stdio.h>
#include <string>
#include <fstream>
#include <cstdlib>
#include <unistd.h>
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
	string q[20] = {"Is it alive","Is it big","Is it cute","Is it furry","Can it fly","Is it warm blooded","Is it a reptile","Can it swim","Does it have a tail","Does it hibernate","Is it poisonous","Is it extinct","Is it a pet","Is it a mammal","Is it a carnivor","Does it have legs","Does it have scales","Do people eat it","Is it fictional","Is it four legged"};
	int question_number = 1;
	string attribute_list[20];
	int attribute_pos = 0;
	
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
	/*
	attribute_pos = 0;
	cout <<"Attribute list is:";
	while (x<20){
		cout <<  attribute_list[x];
		x++;
	}
	*/
	cout << endl;
	
	cout << "it's a..." << endl;
	
	//Use Attribute list to find best animal match
	string best_Animal = topAnimal(attribute_list);	
	
	cout << best_Animal << endl;
}
