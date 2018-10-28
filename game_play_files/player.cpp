#include "../pocket_men_files/pocket_men.h"

#include "../pocket_men_files/frank.h"
#include "../pocket_men_files/devin.h"

#include "../pocket_men_files/prof_johnson.h"
#include "../pocket_men_files/prof_linard.h"

#include "../pocket_men_files/dr_murphy.h"
#include "../pocket_men_files/dr_fieri.h"

#include "player.h"

#include "../error.h"

#include <iostream>
#include <string>
#include <stdlib.h>
#include <unistd.h>

using namespace std;

//constructor
player::player(){//figure out what to do here i think this is causeing a memory leak... revert back to new pocket men and delete each aspect of the array try this in other classes! hopfully this works...
   	team = new pocket_men*[6];
	//frank f;
	team[0] = new frank;
	//devin d;
	team[1] = new devin;
	//prof_johnson pj;
	team[2] = new prof_johnson;
	//prof_linard pl;
	team[3] = new prof_linard;
	//dr_murphy dm;
	team[4] =new dr_murphy;
	//dr_fieri df;
	team[5] = new dr_fieri;
	//create each specific poket man
	nets = 5;
	stone = 0;
	team_count = 0;
}

player::~player(){
   	for(int x = 0; x < 6; x++){
		delete team[x];
	}
	delete [] team;
}

//functions
bool player::shoot_net(pocket_men c){
	srand(time(NULL));
	int shoot = rand()%100;
	if(nets < 1){
		cout<<"You do not have enough nets..."<<endl;
		line(1);
		sleep(1);
		return false;
	}
	nets = nets - 1;
	if(shoot <= c.get_catchability()){
	   	cout<<"You caught that rascle!"<<endl;
		for(int x = 0; x < 6; x++){
			if(c.get_name() == team[x]->get_name()){
				team[x]->set_count((team[x]->get_count())+1);
			}
		}
		line(1);
		sleep(1);
		return true;
	}else{
		cout<<"That bad boy escaped your nets..."<<endl;
		for(int x = 0; x < 6; x++){
			if(c.get_name() == team[x]->get_name()){
				team[x]->set_seen(true);
			}
		}
		line(1);
		sleep(1);
		return false;
	}
}

void player::upgrade_team(){

}

void player::to_do_list(){
   	bool loop = true;
   	while(loop == true){
	   	system("clear");
		line(1);
	   	string option[7];
		char temp = '1';
		for(int x = 0; x < 6; x++){
			team[x]->stats(x);
			option[x] = temp;
			temp = temp+1;
		}
		line(1);
		cout<<"Nets:"<<nets<<"    Stones: "<<stone<<"            (r)Return"<<endl;
		line(1);
		cout<<"Choose who to evolve: ";
		option[6] = "r";
		string ans;
		ans = str_answer(option, 7, false);
		if(ans != "r"){
		   	int ians = (atoi(ans.c_str())) - 1;
		   	system("clear");
			line(1);
		   	team[ians]->stats(ians, true);
			line(1);
			cout<<"(e)Evolve or (r)Return: ";
			option[0] = "e";
			option[1] = "r";
			ans = str_answer(option, 7, false);
			if(ans == "e"){
			   	if(team[ians]->get_count() >= team[ians]->get_upgrade_count() && team[ians]->get_level() == 2){
					team[ians]->evolve_2(stone);
				}else{
					team[ians]->evolve();
				}
			}
		}else{
			loop = false;
		}
	}
}

bool player::finished(){
	int complete = 0;
	for(int x = 0; x < 6; x++){
		if(team[x]->get_level() == 3){
			complete++;
		}
	}
	if(complete == 6){
		return true;
	}else{
		return false;
	}
}

void player::add_nets(int n){
   	nets = nets + n;
	cout<<"You now have "<<nets<<" nets!"<<endl;
}

void player::add_stone(){
   	stone = stone + 1;
	//cout<<"You now have "<<stone<<" stones!"<<endl;
}

int player::get_nets() const{//dont really need this i dont think
	return nets;
}

int player::get_stone() const{
	return stone;
}
