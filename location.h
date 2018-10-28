#ifndef LOC_H
#define LOC_H

#include "event.h"

#include <string>

class loc {
	private:
	   	string event_name;
	   	event *e;
		char display;
		int x;
		int y;

		bool seen;
	public:
		//constructor
		loc();
		loc(char, int, int);
		//~loc();
				
		//functions
		void land(player &);
		char print_debug();
		char print_loc();
		bool wall();
		//void operator=(const loc &);
		//loc(const loc &);
		string get_event_name() const;
		void set_event_name(const string &);
		char get_display() const;
};

#endif
