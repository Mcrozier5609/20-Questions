#include <iostream>
#include <stdio.h>
#include <string>
#include <fstream>
#include <cstdlib>
#include <unistd.h>
using namespace std;

int rankAnimal(string info, int attribute_list[]){
	int rank = 0;
	for (int q = 0; q < 20; q++){
		//cout<<stoi(info.substr(2*q,1));
		//cout<<endl;
		if (stoi(info.substr(2*q,1))==attribute_list[q]){
			rank++;
		}
	}
	return rank;
}

string topAnimal(int attribute_list[]){
	ifstream file;
	file.open("Animals.txt");
	string line;
	int pos;
	string animal = "thing";
	int maxrank = 0;
	int currank;
	while (!file.eof()){
		getline(file, line);
		pos = line.find(",");
		//cout<<line;
		//cout<<endl;
		//cout<<line.substr(pos+1,40);
		//cout<<endl;
		currank = rankAnimal(line.substr(pos+1,40),attribute_list);
		if (currank>maxrank){
			maxrank = currank;
			animal = line.substr(0,pos);
		}
	}
	file.close();
	return animal;
}

int main(){
	string ans;
	string q[20] = {"alive","big","cute","furry","flying","warm_blooded","reptile","swim","tail","hibernate","poisonous","extinct","pet","mammal","carnivor","legs","scales","food","fictional","4legs"};
	int i = 1;
	int attribute_list[20];
	int x = 0;
	
	while (i <=20){
		cout << "question " << i << ": is it " << q[i-1] << "?" << endl;
		cin >> ans;
		if (ans == "y" || ans == "yes" || ans == "indubitably"){
		
			//add to animal traits
			attribute_list[x] = 1;
			x++;
			i++;
			
		} else if (ans == "n" || ans == "no" || ans == "nay"){
		
			//add to animal traits
			attribute_list[x] = 0;
			x++;
			i++;
		
		} else{
		
			cout << "invalid response" << endl;
		
		}
	}
	
	x=0;
	cout <<"Attribute list is:";
	while (x<20){
		cout <<  attribute_list[x];
		x++;
	}
	
	cout << endl;
	
	cout << "it's a..." << endl;
	
	//Use Attribute list to find best animal match
	string thing = topAnimal(attribute_list);	
	
	cout << thing << endl;
}
