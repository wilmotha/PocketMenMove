#include "event.h"
#include "cave.h"

#include "../game_play_files/player.h"

#include "../error.h"

#include <string>

#include <unistd.h>

using namespace std;

cave::cave(){
   	found = false;
	type = "cave";
}

bool cave::print_info(player &p){
   	string option[2];
	option[0] = "e";
	option[1] = "r";
	cout<<"Good lord you have found a cave..."<<endl;
	line(1);
	cout<<"(e)Go in or (r)Run: ";
	string ans = str_answer(option, 2);
	if(ans == "e" && found == false){
	   	system("clear");
	   	line(1);
		cout<<"            \\      |  |      / "<<endl;
		cout<<"              \\   ______   /"<<endl;
		cout<<"                 /      \\"  <<endl;
		cout<<"         \\       |  / / |     /"<<endl;
		cout<<"            \\    |      |  /   "<<endl;
		cout<<"                 \\      /     "<<endl;
		cout<<"~~~~~~~~~~~~~~~~~~‾‾‾‾‾‾~~~~~~~~~~~~~~~~~~"<<endl;
		cout<<"                               "<<endl;
	   	line(1);
		cout<<"Look at that you found a stone, nice!"<<endl;
	   	line(1);
		cout<<"(e)Continue: ";
		ans = str_answer(option, 1);
		p.add_stone();
		found = true;
	}else if(ans == "e" && found == true){
	   	system("clear");
		line(7);
		cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl<<endl;
		line(1);
		cout<<"It is as empty as you left it..."<<endl;
		line(1);
		cout<<"(e)Continue: ";
		ans = str_answer(option, 1);
	}else if(ans == "r" && found == false){
		cout<<"Do to your lack of bravery and fear of spiders you avoid the cave..."<<endl;
		line(1);
		sleep(1);
	}else{
		cout<<"You ignore the already empty cave"<<endl;
		line(1);
		sleep(1);
	}
	return found;
}

cave::~cave(){

}

void cave::set_found(const bool &f){
	found = f;
}
