#include "map.h"

#include "location.h"

#include "../event_files/event.h"

#include "../event_files/wild_pocket_men.h"
#include "../event_files/get_nets.h"
#include "../event_files/cave.h"
#include "../event_files/head.h"

#include "../pocket_men_files/pocket_men.h"

#include "../pocket_men_files/frank.h"
#include "../pocket_men_files/devin.h"

#include "../pocket_men_files/dr_murphy.h"
#include "../pocket_men_files/dr_fieri.h"

#include "player.h"

#include "../error.h"

#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <curses.h>

using namespace std;

map::map(int sxx, int syy, string m){//63 X 33 arrays are broken...//83 x 44 // add a tunel and another area!! //124 x 45
  ifstream map;
  ifstream act;
	map.open("game_play_files/map.txt");
  act.open("game_play_files/act.txt");
	sx = sxx;
	sy = syy;

	ppx = 29;
	ppy = 18;

	px = 29;
	py = 18;
	spots = new loc*[sy];
	for(int y = 0; y < sy; y++){
	   	spots[y] = new loc[sx];
		for(int x = 0; x < sx; x++){
		   	char c;
        char a;
        act.get(a);
		   	map.get(c);
			loc temp(c, x, y, a);//loc temp(c, x, y);
			spots[y][x] = temp;
		}
	}
	mode = m;
}

map::~map(){
	for(int y = 0; y < sy; y++){
	   	delete [] spots[y];
	}
	delete [] spots;
}

void map::print_map(){
	int x_start = px-20;
	int x_end = px+20;

	int y_start = py-10;
	int y_end = py+10;

   	system("clear");
	line(1);
	for(int y = y_start; y < y_end; y++){
		cout<<"=";
		for(int x = x_start; x < x_end; x++){
			if(x == px && y == py ){
				cout<<"X";
			}else{
			   	if(mode == "debug"){
			   		cout<<spots[y][x].print_debug();
				}else{
					cout<<spots[y][x].print_loc();
				}
			}
		}
		cout<<"="<<endl;
	}
	line(1);

}

void map::event_occurred(){
   	print_map();
	spots[py][px].land(p);
	bool loop = false;
	int new_x;
	int new_y;
	if(spots[py][px].get_event_name() == "wild_pocket_men"){
		while(loop == false){
			new_x = rand()%sx;
			new_y = rand()%sy;
			if(spots[new_y][new_x].get_event_name() == "empty" && spots[py][px].get_display() == spots[new_y][new_x].get_display()){
				loop = true;
			}else{
				loop = false;
			}
		}
		spots[new_y][new_x].set_event_name(spots[py][px].get_event_name());
		spots[py][px].set_event_name("empty");
		ppx = px;
		ppy = py;
	}
	if(spots[py][px].get_event_name() == "nets"){
		spots[py][px].set_event_name("empty");
		ppx = px;
		ppy = py;
		for(int y = 0; y < sy; y++){
			for(int x = 0; x < sx; x++){
				if(spots[y][x].get_display() == '@' && x != px && y != py){
					int r = rand()%2;
					if(r == 0){
						spots[y][x].set_event_name("nets");
					}
				}
			}
		}
	}
	if(spots[py][px].get_event_name() == "cave" || spots[py][px].get_event_name() == "head"){
		px = ppx;
		py = ppy;
		print_map();
	}
	if(spots[py][px].get_event_name() == "empty"){
		ppx = px;
		ppy = py;
	}
}

void map::print_spot(int x, int y){
	cout<<spots[y][x].print_loc();
}

bool map::pause(){
   	system("clear");
   	line(1);
	cout<<"Use the WASD keys to navigate"<<endl;
	cout<<"Find the employees in tall grass:       #"<<endl;
	cout<<"Find nets at net stations:              @"<<endl;
	cout<<"Find deradiation stones in caves:       0"<<endl;
	cout<<"This is your boss?:                     9"<<endl;
	line(1);
	cout<<"(f)Continue or (q)Quit: ";
	//cout<<"(1/2): ";
	string option[2];
	option[0] = "f";
	option[1] = "q";
	string ans = str_answer(option, 2, false);
	if(ans == "q"){
		return false;
	}else{
		return true;
	}
}

bool map::move(){
   	char arrows;
	bool quit = true;
	cout<<"          Nets: "<<p.get_nets()<<"        Stone: "<<p.get_stone()<<endl;
	cout<<"      (e)To do list     (f)Pause "<<endl;//seperate out
	line(1);
	arrows = input();
	//system("stty cbreak -echo");
	//arrows = getchar();
	//system("stty cooked echo");
	//system("clear");
	if(arrows == 'w'){
	  if(spots[py-1][px].wall()){
			py = py - 1;
		}
	}else if(arrows == 'a'){
	  if(spots[py][px-1].wall()){
			px = px - 1;
		}
	}else if(arrows == 's'){
	  if(spots[py+1][px].wall()){
			py = py + 1;
		}
	}else if(arrows == 'd'){
	  if(spots[py][px+1].wall()){
			px = px + 1;
		}
	}else if(arrows == 'e'){
		p.to_do_list();
	}else if(arrows == 'f'){
		quit = pause();
	}
	event_occurred();
	return quit;

}
