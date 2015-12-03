#include <iostream>
#include <stdio.h>
#include <string>
#include <fstream>
#include <cstdlib>
#include <unistd.h>
#include "Animals.h"

using namespace std;

<<<<<<< HEAD
/* returns a bool representative of an int*/
=======
//Used in function archive to read in #'s on file and convert to bool values
>>>>>>> 5beb4c9b885657a2db4b1ba51727f52201a1f9b5
bool tobool(string number){
	bool ret = false;
	if (number == "1"){
		ret = true;
	}
	return ret;
}

<<<<<<< HEAD
/* Uses Animals.txt and resources from Animals.cpp to set up linked list of animal struct */
=======
//Reads in hardcoded file name.  Converts text file into Animal struct's reading until eof
//Reads 1 as true any everything else as false (based upon function tobool) and constructs the animal
//For expansion with further traits, add to end of list to eliminate reordering of constructor and archive.
>>>>>>> 5beb4c9b885657a2db4b1ba51727f52201a1f9b5
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
		info = line.substr(pos+1,40);
		temp = new Animal(line.substr(0,pos),tobool(info.substr(0,1)),tobool(info.substr(2,1)),
				tobool(info.substr(4 ,1)),tobool(info.substr(6 ,1)),tobool(info.substr(8 ,1)),
				tobool(info.substr(10,1)),tobool(info.substr(12,1)),tobool(info.substr(14,1)),
				tobool(info.substr(16,1)),tobool(info.substr(18,1)),tobool(info.substr(20,1)),
				tobool(info.substr(22,1)),tobool(info.substr(24,1)),tobool(info.substr(26,1)),
				tobool(info.substr(28,1)),tobool(info.substr(30,1)),tobool(info.substr(32,1)),
				tobool(info.substr(34,1)),tobool(info.substr(36,1)),tobool(info.substr(38,1)), temp);
		getline(file,line);
	}
	file.close();
	return temp; //returns head of linked list
}

<<<<<<< HEAD
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
=======
//Take anwser input and increase/decrease rank of all animals in linked list.   
//Also strikes animals completely out of the list if they have too many strikes.
>>>>>>> 5beb4c9b885657a2db4b1ba51727f52201a1f9b5
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
				if (temptrail != NULL){
					deltemp = temptrail->next;
					temptrail->next = temp->next;
					delete deltemp;
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

<<<<<<< HEAD
/* Compares linked list of animals for next question(s) and returns int of upcoming unanimous answers */
=======
//Checks if a question is worth skipping????     -----------add what is happenning here
>>>>>>> 5beb4c9b885657a2db4b1ba51727f52201a1f9b5
int skip_q(int qnum, Animal * head){
	Animal * temp;
	bool same = true;
	int skip = 0;
	bool ans;
	int totalqcount = 20;
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

int main(){
	string ans;
	string q[20] = {"Is it alive","Is it big","Is it cute","Is it furry","Can it fly","Is it warm blooded",
			"Is it a reptile","Can it swim","Does it have a tail","Does it hibernate","Is it poisonous",
			"Is it extinct","Is it a pet","Is it a mammal","Is it a carnivor","Does it have legs",
			"Does it have scales","Do people eat it","Is it fictional","Is it four legged"};
	int question_number = 0;
	int ext_q_num = 1; //number printed, everything internal uses 'question_number'

	Animal * head = archive();
	cout<<"Animals archived"<<endl;

	while (question_number < 20 && (head->next != NULL)){
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

	clear_archive(head);
}
