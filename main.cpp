#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;

int main(){
	char ans;
	string q[20] = {"alive","big","cute","furry","flying","warm_blooded","reptile","swim","tail","hibernate","poisonous","extinct","pet","mammal","carnivor","legs","scales","food","fictional","4legs"};
	for (int i = 1; i <=20; i++){
		cout << "question " << i << ": is it " << q[i-1] << "?" << endl;
		cin >> ans;
		if (ans == 'y'){
			//add to animal traits
		} else if (ans == 'n'){
			//add to animal traits
		} else{
			cout << "invalid response" << endl;
		}
	}
	cout << "it's a..." << endl;
	//do some comparing
	cout << "thing" << endl;
}
