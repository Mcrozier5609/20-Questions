#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;

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
	
	cout << "thing" << endl;
}
