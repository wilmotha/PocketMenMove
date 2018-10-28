#include "../event_files/event.h"
#include "player.h"
#include "location.h"
#include <iostream>
#include "../event_files/wild_pocket_men.h"
#include "../event_files/get_nets.h"
#include "../event_files/cave.h"
#include "../event_files/head.h"
#include "time.h"

#include <string>
#include <stdlib.h>

using namespace std;

loc::loc(){
	display = ' ';
	x = 0;
	y = 0;
	event null;
	e = &null;
	seen = false;
}

loc::loc(char d, int i, int j){
	display = d;
	x = i;
	y = j;
	
	seen = false;	
	int r;
	if(d == '#'){
		int r = rand()%4;
		if(r == 0){
			event_name = "wild_pocket_men";
		}else{
			event_name = "empty";
		}
	}else if(d == '0'){
		//int r = rand()%8;
		//if(r == 0){
		event_name = "cave";
		//}else{
		//	event_name = "empty";
		//}
	}else if(d == '@'){
		event_name = "nets";
	}else if(d == '9'){
		event_name = "head";
	}else{
		event_name = "empty";
	}
	//e = new event;
	//wild_pocket_men w;//set a ranom thing to pick a random event title and then set it actuall in land...
	//e = &w;//add some randome thing that sets this!
}

void loc::land(player &p){
   	wild_pocket_men w;
	cave c;
	get_nets n;
	event v;
	head h;
	if(event_name == "wild_pocket_men"){
		//e = new wild_pocket_men;
	   	e = &w;
	}else if(event_name == "cave"){
	   	//e = new cave;
		c.set_found(seen);
		e = &c;
	}else if(event_name == "nets"){
	   	//e = new get_nets;
   		e = &n;
	}else if(event_name == "empty"){
	   	//e = new event;
		e = &v;
	}else if(event_name == "head"){
		e = &h;
	}
   	seen = e->print_info(p);
}

bool loc::wall(){
	if(display == '}' || display == '{' || display == '*' || display == '\\' || display == '|' || display == '/' || display == '_'){
		return false;
	}else{
		return true;
	}
}

char loc::print_debug(){
	if(event_name == "wild_pocket_men"){
		return 'w';
	}else{
		return display;
	}
	
}

char loc::print_loc(){
	return display;
}

/*loc::loc(const loc &temp){
	display = temp.display;
	y = temp.y;
	x = temp.x;
	e = temp.e;
}

void loc::operator=(const loc &temp){
	display = temp.display;
	y = temp.y;
	x = temp.x;
	e = temp.e;
}*/

string loc::get_event_name() const{
	return event_name;	
}

void loc::set_event_name(const string &en){
	event_name = en;
}

char loc::get_display() const{
	return display;
}

//loc::~loc(){
	//delete e;
//}
