#ifndef HEAD_H
#define HEAD_H

#include "event.h"
#include "player.h"
#include <string>

using namespace std;

class head: public event{
	public:
		~head();
	   	
	   	//functions
		bool print_info(player &);
};

#endif
