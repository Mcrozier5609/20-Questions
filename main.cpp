//
//Animal 20-Questions 2015
//Jonny Schmitt, Michael Crozier, Scott Schubert, Sean Hansberry
// 

#include <iostream>
#include <stdio.h>
#include <string>
#include <fstream>
#include <cstdlib>
#include <unistd.h>
#include "Animals.h"

using namespace std;

/* returns a bool representative of an int*/
bool tobool(string number){
	bool ret = false;
	if (number == "1"){
		ret = true;
	}
	return ret;
}

/*!
  Uses Animals.txt and resources from Animals.cpp to set up linked list of animal struct 
  For expansion with further traits, add to end of list to eliminate reordering of constructor and archive.
 */
Animal* archive(){
	ifstream file;
	file.open("Animals.txt");
	string line;
	string info;
	int pos;
	Animal * temp = NULL;
	getline(file, line);
	while(!file.eof()){
		pos = line.find(",");
		info = line.substr(pos+1,50);
		temp = new Animal(line.substr(0,pos),tobool(info.substr(0,1)),tobool(info.substr(2,1)),
				tobool(info.substr(4 ,1)),tobool(info.substr(6 ,1)),tobool(info.substr(8 ,1)),
				tobool(info.substr(10,1)),tobool(info.substr(12,1)),tobool(info.substr(14,1)),
				tobool(info.substr(16,1)),tobool(info.substr(18,1)),tobool(info.substr(20,1)),
				tobool(info.substr(22,1)),tobool(info.substr(24,1)),tobool(info.substr(26,1)),
				tobool(info.substr(28,1)),tobool(info.substr(30,1)),tobool(info.substr(32,1)),
				tobool(info.substr(34,1)),tobool(info.substr(36,1)),tobool(info.substr(38,1)),
				tobool(info.substr(40,1)),tobool(info.substr(42,1)),tobool(info.substr(44,1)),
				tobool(info.substr(46,1)),tobool(info.substr(48,1)), temp);
		getline(file,line);
	}
	file.close();
	return temp; //returns head of linked list
}

/* Free memory at end of program */
void clear_archive(Animal * head){
	Animal * temp = head;
	Animal * deltemp = NULL;
	while (temp != NULL){
		deltemp = temp;
		temp = temp->next;
		delete deltemp;
	}
}

/* Uses linked list of animals and answer to question to calculate ranks and narrow linked list */
Animal* run_q(int qnum, bool qans, Animal * head){
	Animal * temp = head;
	Animal * deltemp = NULL;
	Animal * temptrail = NULL;
	while(temp != NULL){
		if (qans == temp->get_trait(qnum)){
			temp->up_rank();
		} else{
			temp->up_strike();
			if (temp->strike_out()){
				if (temptrail != NULL){ //not the head
					deltemp = temp;
					temptrail->next = temp->next;
					temp = temptrail;
				} else{
					deltemp = head;
					head = temp->next;
					delete deltemp;
				}
			}
		}
		temptrail = temp;
		temp = temp->next;
	}
	return head;
}

/* Compares linked list of animals for next question(s) and returns int of upcoming unanimous answers */
//Checks if a question is worth skipping????     -----------add what is happenning here
int skip_q(int qnum, Animal * head){
	Animal * temp;
	bool same = true;
	int skip = 0;
	bool ans;
	int totalqcount = 25;
	while (same == true && (qnum+skip < totalqcount)){
		skip++;
		temp = head;
		ans = temp->get_trait(qnum+skip);
		while(temp != NULL){
			if (temp->get_trait(qnum+skip)!=ans){
				same = false;
			}
			temp = temp->next;
		}
	}
	return skip;
}

/* compares values of rank in linked list and returns Animal with highest rank */
Animal * get_max_rank(Animal * head){
	Animal * temp = head;
	int maxrank = temp->get_rank();
	Animal * ret = temp;
	while (temp != NULL){
		if (temp->get_rank() > maxrank){
			maxrank = temp->get_rank();
			ret = temp;
		}
		temp = temp->next;
	}
	return ret;
}

/* Main initializes the animals and prompts the user to play, moves on to each new question, and asks the user if they would like to play again.*/
int main(){
	string ans;
	Animal * head;
	bool play = true;
	string q[25] = {"Is it alive","Is it big","Is it cute","Is it furry","Can it fly","Is it warm blooded",
			"Is it a reptile","Can it swim","Does it have a tail","Does it hibernate","Is it poisonous",
			"Is it extinct","Is it a pet","Is it a mammal","Is it a carnivor","Does it have legs",
			"Does it have scales","Do people eat it","Is it fictional","Is it four legged",
			"Does it have whiskers", "Does it commonly live in artic conditions", "Does it live in jungles/rainforrest",
			"Does it live in aquatic conditions", "In the wild is it a pack/group animal"};
	
	cout<<"=================================================================="<<endl;
	cout<<"| Welcome to Animal 20-Questions!                                |"<<endl;
	cout<<"|                                                                |"<<endl;
	cout<<"| Jonny Schmitt, Michael Crozier, Scott Schubert, Sean Hansberry |"<<endl;
	cout<<"=================================================================="<<endl;
	cout<<""<<endl;
	cout<<"Would you like to play?"<<endl;
	cout<<"Type 'yes', 'y', or 'indubitably' to confirm."<<endl;
	cout<<"Type 'no', 'n', 'nay' to quit."<<endl;
	cin>>ans;
	if (ans == "yes" || ans == "y" || ans == "indubitably"){
	while (play == true){
	int question_number = 0;
	int ext_q_num = 1; //number printed, everything internal uses 'question_number'

	head = archive();
	cout<<"Animals archived"<<endl;

	while (question_number < 25 && (head->next != NULL)){
		cout << "Question " << ext_q_num << ": " << q[question_number] << "?" << endl;
		cin >> ans;
		if (ans == "y" || ans == "yes" || ans == "indubitably"){
		
			//add to animal traits
			head = run_q(question_number, true, head);  
			question_number += skip_q(question_number, head);
			ext_q_num++;
			
		} else if (ans == "n" || ans == "no" || ans == "nay"){
		
			//add to animal traits
			head = run_q(question_number, false, head);
			question_number += skip_q(question_number, head);
			ext_q_num++;
		
		} else{
		
			cout << "invalid response" << endl;
		
		}
	}
	
	cout << endl;
	cout << "it's a ";
	
	//Use Attribute list to find best animal match
	Animal * best_Animal = get_max_rank(head);	
	string guess = best_Animal->get_name();
	cout << guess << endl;
	cout<<"Would you like to play again?"<<endl;
	cin>>ans;
	if (ans == "n" || ans == "no" || ans == "nay"){
	play = false;
	cout<<"Goodbye!"<<endl;
	}
	}

	clear_archive(head);
	}
	else{
	cout<<"Goodbye!"<<endl;
	}
}
