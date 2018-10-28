#include "get_nets.h"
#include <iostream>
#include "player.h"
#include <stdlib.h>
#include "error.h"

using namespace std;

get_nets::get_nets(){
	type = "get_net";
   	srand(time(NULL));
	nets = (rand()%10)+1;
}

bool get_nets::print_info(player &p){
   	string option[1];
	option[0] = "e";
   	cout<<"Oh boy look what we have hear! "<<nets<<" nets!"<<endl;
	line(1);
	cout<<"(e)Take nets!"<<endl;
	string ans = str_answer(option, 1);
	line(1);
	p.add_nets(nets);
	line(1);
}

get_nets::~get_nets(){

}
