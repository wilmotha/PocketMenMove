#include "head.h"
#include "player.h"
#include "event.h"

#include <string>

using namespace std;

bool event::print_info(player &p){
	//cout<<"not even anything!"<<endl;
}

string event::get_type() const{
	return type;
}

event::~event(){

}
