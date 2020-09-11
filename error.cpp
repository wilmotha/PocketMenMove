/*#ifndef ERROR_H
#define ERROR_H
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <string>*/
#include "error.h"
#include <curses.h>

using namespace std;

void line(int skip = 1){
	cout<<"==========================================";
	for(int x = 0; x < skip; x++){
		cout<<endl;
	}
}

char input(){
 	system("stty cbreak -echo");
 	char in = getchar();
 	system("stty cooked echo");
	return in;
 }

/*string sinput(){
 	system("stty cbreak -echo");
 	string in = getchar();
 	system("stty cooked echo");
	return in;
 }*/

int pos_int(){
	bool loop;
	char ans[10];
	int ians;
	do{
		loop = false;
		cin>>ans;
		for(int x = 0; x < strlen(ans); x++){
			if(!(ans[x] >= '0' && ans[x] <= '9') && loop == false){
				cout<<"Incorrect Input!"<<endl<<endl;
				cout<<"Try again: ";
				loop = true;
			}
		}
	}while(loop == true);
	ians = atoi(ans);
	return ians;
}

int pos_int(char *ans){
	bool loop;
	int ians;
	do{
		loop = false;
		for(int x = 0; x < strlen(ans); x++){
			if(!(ans[x] >= '0' && ans[x] <= '9') && loop == false){
				cout<<"Incorrect Input!"<<endl<<endl;
				cout<<"Try again: ";
				cin>>ans;
				loop = true;
			}
		}
	}while(loop == true);
	ians = atoi(ans);
	return ians;
}

signed int signed_int(){
	bool loop;
	char ans[10];
	signed int ians;
	do{
		loop = false;
		cin>>ans;
		for(int x = 0; x < strlen(ans); x++){
		   	if(ans[0] == '-'){
				
			}else if(!(ans[x] >= '0' && ans[x] <= '9') && loop == false){
				cout<<"Incorrect Input!"<<endl<<endl;
				cout<<"Try again: ";
				loop = true;
			}
		}
	}while(loop == true);
	ians = atoi(ans);
	return ians;
}

int pos_float(){
	bool loop;
	char ans[10];
	float fans;
	do{
	   	bool dec = false;
		loop = false;
		cin>>ans;
		for(int x = 0; x < strlen(ans); x++){
			if(!(ans[x] >= '0' && ans[x] <= '9') || (ans[x] == '.' && dec == false) && loop == false){
				cout<<"Incorrect Input!"<<endl<<endl;
				cout<<"Try again: ";
				loop = true;
			}if(ans[x] == '.'){
				dec = true;
			}
		}
	}while(loop == true);
	fans = atof(ans);
	return fans;
}

/*signed int signed_float(){
	bool loop;
	char ans[10];
	signed float fans;
	do{
	   	bool dec = false;
		loop = false;
		cin>>ans;
		for(int x = 0; x < strlen(ans); x++){
		   	if(ans[0] == '-'){

			}else if(!(ans[x] >= '0' && ans[x] <= '9') || (ans[x] == '.' && dec == false) && loop == false){
				cout<<"Incorrect Input!"<<endl<<endl;
				cout<<"Try again: ";
				loop = true;
			}if(ans[x] == '.'){
				dec = true;
			}
		}
	}while(loop == true);
	fans = atof(ans);
	return fans;
}*/

int answer(int x){
	bool loop = false;
	while(loop == false){
		int ans = pos_int();
		if(ans > x || ans <= 0){
			cout<<"Incorect Input"<<endl<<endl;
			cout<<"Try again: ";
			loop = false;
		}else{
			cout<<endl;
			return ans;
		}
	}

	return -1;
}

int answer(int x, char *ans){
	bool loop = false;
	while(loop == false){
		int ians = pos_int(ans);
		if(ians > x || ians <= 0){
			cout<<"Incorect Input"<<endl<<endl;
			cout<<"Try again: ";
			loop = false;
		}else{
			cout<<endl;
			return ians;
		}
	}

	return -1;
}

float answer(float x){
	bool loop = false;
	while(loop == false){
		float ans = pos_float();
		if(ans > x || ans <= 0){
			cout<<"Incorect Input"<<endl<<endl;
			cout<<"Try again: ";
			loop = false;
		}else{
			cout<<endl;
			return ans;
		}
	}

	return -1.0;
}

string str_answer(string *options, int size, bool wait){
	bool loop = false;
	string ans;
	while(loop == false){
	   	if(wait == true){
			cin>>ans;
		}else{
			char temp = input();
			ans = temp;
			cout<<endl;
		}
		for(int x = 0; x < size; x++){
			if(options[x] == ans){
			  	loop = true;				
			}
			if(loop == true){
				x = 100;
			}
		}
		if(loop == false){
			cout<<"Incorect Input"<<endl<<endl;
			cout<<"Try again: ";
		}else{
		   	string clean_ans;
			clean_ans = ans;
			return clean_ans;
		}
	}

	return "\0";
}
//#endif
