#ifndef WILD_POCKET_MEN_H
#define WILD_POCKET_MEN_H

#include "../pocket_men_files/pocket_men.h"
#include "event.h"
#include "../game_play_files/player.h"

#include <string>

using namespace std;

class wild_pocket_men: public event{
	protected:
	   	pocket_men *wild;
	public:
		//constructor
		wild_pocket_men();
		~wild_pocket_men();

		//functions
		bool print_info(player &);

		//getters
		pocket_men *get_wild();
};

#endif
