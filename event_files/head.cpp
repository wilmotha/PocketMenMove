#include "head.h"
#include "../game_play_files/player.h"
#include "event.h"
#include "../error.h"

#include <string>

using namespace std;

bool head::print_info(player &p){
   	string option[1];
	option[0] = "e";
	if(p.finished() == true){
	   	line(1);
	   	cout<<"Nice job bud!"<<endl;
		line(1);
		cout<<"(e)Continue: ";
		string ans = str_answer(option,1);
		return true;
	}else{
		line(1);
		cout<<"What are you doing you have work to do!"<<endl<<"Get to it!"<<endl;
		line(1);
		cout<<"(e)Continue: ";
		string ans = str_answer(option,1);
		return false;
	}
}

head::~head(){

}
