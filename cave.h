#ifndef CAVE_H
#define CAVE_H

#include "player.h"
#include <string>

using namespace std;

class cave: public event{
	private:
   		bool found;	   
   	public:
		//constructor
		cave();
		~cave();

		//functions
		virtual bool print_info(player &);
		
		void set_found(const bool &);
};

#endif
