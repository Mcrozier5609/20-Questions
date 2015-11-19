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

Animal* run_q(int qnum, bool qans, Animal * head){
	Animal * temp = head;
	Animal * temptrail = NULL;
	while(temp != NULL){
		if (qans == temp->get_trait(qnum)){
			temp->up_rank();
		} else{
			temp->up_strike();
			if (temp->strike_out()){
				// \/ remember to fix memory leaks here \/
				if (temptrail != NULL){
					temptrail->next = temp->next;
				} else{
					head = temp->next;
				}
			}
		}
		temptrail = temp;
		temp = temp->next;
	}
	return head;
}

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
	cout<<"archived"<<endl;

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
}
