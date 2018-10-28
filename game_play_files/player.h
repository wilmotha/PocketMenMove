#ifndef PLAYER_H
#define PLAYER_H

#include "../pocket_men_files/pocket_men.h"
#include "../pocket_men_files/frank.h"

#include <iostream>

using namespace std;

class player {
	private:
	   	pocket_men **team; //this is polymorphic baby
		int team_count;
		
		int nets;
		int stone;
	public:
		//constructor
		player();
		~player();

		//functions
		bool shoot_net(pocket_men);
		void upgrade_team();
		void to_do_list();
		bool finished();

		//getters and setter
		int get_nets() const;
		void add_nets(int);
		void add_stone();
		int get_stone() const;
};

#endif
