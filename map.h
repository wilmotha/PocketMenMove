#ifndef MAP_H
#define MAP_H

#include "player.h"
#include "location.h"
#include <string>

class map {
	private:
	   	player p;
		loc **spots;
		
		int px;
		int py;	
		
		int ppx;
		int ppy;

		int sx;
		int sy;

		string mode;
	public: 
		//constructor
		map(int, int, string);
		~map();
		
		//functions
		void print_map();
		void event_occurred();
		bool move();
		void print_spot(int, int);
		bool pause();
};

#endif
