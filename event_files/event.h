#ifndef EVENT_H
#define EVENT_H

#include "../game_play_files/player.h"
#include <string>

using namespace std;

class event{
	protected:
	   	string type;
	public:
		virtual ~event();

		//functions
		virtual bool print_info(player &);

		//getters
		string get_type() const;
};

#endif
