#include "wild_pocket_men.h"

#include "../pocket_men_files/pocket_men.h"

#include "../pocket_men_files/frank.h"
#include "../pocket_men_files/devin.h"

#include "../pocket_men_files/prof_johnson.h"
#include "../pocket_men_files/prof_linard.h"

#include "../pocket_men_files/dr_murphy.h"
#include "../pocket_men_files/dr_fieri.h"


#include <string>
#include <iostream>
#include <stdlib.h>
#include <unistd.h>
#include "../error.h"


using namespace std;

wild_pocket_men::wild_pocket_men(){
	type = "wild_pocket_men";
   	srand(time(NULL));
	frank f;
	devin d;
	prof_linard l;
	prof_johnson j;
	dr_murphy m;
	dr_fieri guy;
	bool loop = true;
	while(loop == true){
		int r = rand()%6;
		if(r == 0){
			r = (rand()%10)+1;
			if(r >= f.get_rairness()){
				wild = new frank;
				loop = false;
			}
		}else if(r == 1){
			r = (rand()%10)+1;
			if(r >= d.get_rairness()){
				wild = new devin;
				loop = false;
			}
		}else if(r == 2){
			r = (rand()%10)+1;
			if(r >= l.get_rairness()){
				wild = new prof_linard;
				loop = false;
			}
		}else if(r == 3){
			r = (rand()%10)+1;
			if(r >= j.get_rairness()){
				wild = new prof_johnson;
				loop = false;
			}
		}else if(r == 4){
			r = (rand()%10)+1;
			if(r >= m.get_rairness()){
				wild = new dr_murphy;
				loop = false;
			}
		}else if(r == 5){
			r = (rand()%10)+1;
			if(r >= guy.get_rairness()){
				wild = new dr_fieri;
				loop = false;
			}
		}
		
	}
	wild->set_seen(true);
}

wild_pocket_men::~wild_pocket_men(){
	delete wild;
}

bool wild_pocket_men::print_info(player &p){//alerts the player what they have found!!
	string option[2];
	option[0] = "e";
	option[1] = "r";
   	cout<<"Out of nowhere a wild "<<wild->get_name()<<" appears!"<<endl;
	line(1);
	cout<<"(e)Try to catch it or (r)Run: ";
	string ans = str_answer(option, 2);

	if(ans == "e"){
		wild->stats(0);
		line(1);
		bool ctch = false;
		while(ctch == false){
			system("clear");
			line(1);
			int r = rand()%2;
			if(r == 0){
				cout<<"                    ~~~~~~~           "<<endl;	
				cout<<"    _______        { # # # }         "<<endl;
				cout<<"   / ______|        \\ # # /  "<<endl;
				cout<<"  / /      \\         |   |       "<<endl;
				cout<<"  |/  o  0 |         |   |   "<<endl;
				cout<<"__(     >  |________/____\\_______________ "<<endl;
				cout<<"   \\    o  /    #                  "<<endl;
				cout<<"    \\   ~ /    # #       # # #        "<<endl; 
				cout<<"    /     \\               # #    "<<endl;
			}else{
				cout<<"                    ~~~~~~~           "<<endl;	
				cout<<"     _______       { # # # }         "<<endl;
				cout<<"    / ______|       \\ # # /  "<<endl;
				cout<<"   / /      \\        |   |       "<<endl;
				cout<<"   |/  o  0 |        |   |   "<<endl;
				cout<<"___(     >  |_______/____\\_______________ "<<endl;
				cout<<"    \\    -  /   #                  "<<endl;
				cout<<"     \\   ~ /   # #       # # #        "<<endl; 
				cout<<"     /     \\              # #    "<<endl;
			}
			line(1);
			wild->stats(0);
			cout<<"Nets: "<<p.get_nets()<<endl;
			line(1);
			cout<<"(e)Throw net or (r)Run: ";
			string ans = str_answer(option, 2);
			if(ans == "e"){
		   		ctch = p.shoot_net(*wild);
			}else{
				cout<<"That little dude ran for the hills..."<<endl;
				line(1);
				sleep(1);
				return false;
			}
		}
		return ctch;
	}else{
		cout<<"That little dude ran for the hills..."<<endl;
		line(1);
		sleep(1);
	   	return false;
	}
}

pocket_men *wild_pocket_men::get_wild(){
	return wild;
}
