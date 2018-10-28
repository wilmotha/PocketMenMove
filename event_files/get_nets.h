#ifndef GET_NETS_H
#define GET_NETS_H

#include "../game_play_files/player.h"
#include "event.h"
#include <string>

using namespace std;

class get_nets: public event{
	protected:
	   	int nets;
	public:
		//constructor
		get_nets();
		~get_nets();

		//functions
		bool print_info(player &);

		//getters
};

#endif
