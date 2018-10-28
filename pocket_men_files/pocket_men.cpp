#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <string>
#include "../error.h"
#include "pocket_men.h"
#include <unistd.h>

using namespace std;

//constructor

//functions
int pocket_men::get_damage(){
   	srand(time(NULL));
	int damage = rand()%(pp+1);
	return damage;
}

void pocket_men::evolve(){
      	if(count >= upgrade_count && level == 1){
	   	level = 2;
		pp = pp + (pp*.1);
		hp = max_hp + (pp*.1);
		max_hp = hp;
		system("clear");
		line(1);
		stats(1, true);
		line(1);
	   	cout<<"It's evolving time baby!"<<endl;
		cout<<name<<"has now reach their second form!"<<endl;
		line(1);
		sleep(3);
	}else{
	   	if(count > 0 && level == 1){
			cout<<"You need at least "<<upgrade_count<<" to evovle "<<name<<" to its next stage"<<endl;
			line(1);
		}else if(level < 2){
			cout<<"How are you suposed to upgrade something you do not have..."<<endl;
			line(1);
		}else{
			if(level == 2){
				cout<<"Why don't you look in a cave for a stone..."<<endl;
				line(1);
			}else{
				cout<<"This employee is maxed out, nice work bud..."<<endl;
				line(1);
			}
		}
		sleep(1);
	}
}

void pocket_men::evolve_2(int &stone){
	if(stone > 0){
	   	stone = stone - 1;
   		level = 3;
		pp = pp + (pp*.2);
		hp = max_hp + (pp*.2);
		max_hp = hp;
		system("clear");
		line(1);
		stats(1, true);
		line(1);
	   	cout<<"The stars aline with the gods who then "<<endl<<"stike lightnig down on the stone passing its "<<endl<<"energy to "<<name<<", who has now reached their final form!"<<endl;
		line(3);
		sleep(3);
	}else if(level == 2){
		cout<<"You need a stone to evolve to final evelution!"<<endl;
		line(1);
		sleep(1);
	}else if(level == 3){
		cout<<"This employee is maxed out, nice work bud..."<<endl;
		line(1);
		sleep(1);
	}
	
}

void pocket_men::stats(int x, bool ff){ 
   	if(count == 0){
	   	if(seen == true){
			cout<<"("<<x+1<<")"<<name<<"     lv: "<<level<<endl;
		}else{
			cout<<"("<<x+1<<")?????"<<"      lv: ??"<<endl;
		}
		cout<<"       ??pp     ??"<<"/??hp"<<endl;
		if(seen == false){
			cout<<"    Status: Unknown"<<endl;
		}else{
			cout<<"    Status: Seen"<<endl;
		}

	}else{
		cout<<"("<<x+1<<")"<<name<<"    lv: "<<level<<endl;
		cout<<"       "<<pp<<"pp     "<<hp<<"/"<<max_hp<<endl;
		cout<<"    Status: "<<count<<" in party"<<endl;
		if(ff == true){
			cout<<endl<<"     "<<fun_fact<<endl;
		}
	}if(x != 5){
		cout<<endl;
	}
}

//getters
int pocket_men::get_level() const{
	return level;
}

string pocket_men::get_type() const{
	return type;
}

string pocket_men::get_name() const{
	return name;
}

int pocket_men::get_pp() const{
	return pp;
}

int pocket_men::get_hp() const{
	return hp;
}	

int pocket_men::get_max_hp() const{
	return max_hp;
}

int pocket_men::get_catchability() const{
	return catchability;
}

int pocket_men::get_count() const{
	return count;
}

int pocket_men::get_upgrade_count() const{
	return upgrade_count;
}

int pocket_men::get_rairness() const{
	return rairness;
}

//setters
void pocket_men::set_type(const string &t){
	type = t;
}

void pocket_men::set_name(const string &n){
	name = n;
}

void pocket_men::set_pp(const int &s){
	pp = s;
}

void pocket_men::set_hp(const int &h){
	hp = h;
}

void pocket_men::set_max_hp(const int &m){
	max_hp = m;
}

void pocket_men::set_count(const int &c){
	count = c;
}

void pocket_men::set_seen(const bool &s){
	seen = s;
}
