#include "game_play_files/map.h"

#include "game_play_files/location.h"

#include "event_files/event.h"

#include "event_files/wild_pocket_men.h"
#include "event_files/get_nets.h"
#include "event_files/cave.h"
#include "event_files/head.h"

#include "pocket_men_files/pocket_men.h"

#include "pocket_men_files/frank.h"
#include "pocket_men_files/devin.h"

#include "pocket_men_files/dr_murphy.h"
#include "pocket_men_files/dr_fieri.h"

#include "game_play_files/player.h"

#include "error.h"

#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

void start_screen(){//debugmode add
	system("clear");
	line(5);
	cout<<"               Pocket"<<endl;
	cout<<"                    Men"<<endl;
	cout<<"                       Move"<<endl;
	cout<<endl<<endl<<endl<<endl;
	line(1);
	cout<<"            Any key to start..."<<endl;
	input();
}

int main_menu(){
   	system("clear");
        line(1);
	cout<<"             Pocket Men Move"<<endl;
        line(2);
	cout<<"(1)Main Game"<<endl;
	cout<<"(2)No intro"<<endl;
	cout<<"(3)Quit"<<endl<<endl;
        line(1);
	int ans = answer(3);
	return ans;
}

void guy(){
	char mouth;
	int m = rand()%5;
	if(m == 0){
		mouth = '0';
	}else if(m == 1){
		mouth = '^';
	}else if(m == 2){
		mouth = '-';
	}else if(m == 3){
		mouth = 'O';
	}else if(m == 4){
		mouth = '-';
	}
	line(1);
	m = rand()%10;
	if(m < 2){
		cout<<"                        |||||||||||               "<<endl;
		cout<<"    _____/\\             |  /   \\  |  "<<endl;
	   	cout<<"   / ______|            | /     \\ |   "<<endl;
		cout<<"  / / ~ ~~ \\            |_________|"<<endl;
		cout<<"  |/  _  _ |"<<endl;
		cout<<"__(     >  |______________________________ "<<endl;
		cout<<"  /\\~   "<<mouth<<"  /  _"<<endl;
		cout<<"  \\   ~ ~ ~  [ ]"<<endl;
		cout<<"    ̅/  ~  \\  / \\"<<endl;
	}else if(m < 5){
		cout<<"                        |||||||||||               "<<endl;
		cout<<"     _____/\\            |  /   \\  |  "<<endl;
	   	cout<<"    / ______|           | /     \\ |   "<<endl;
		cout<<"   / / ~ ~~ \\           |_________|"<<endl;
		cout<<"   |/  _  _ |"<<endl;
		cout<<"___(     >  |_____________________________ "<<endl;
		cout<<"   /\\~   "<<mouth<<"  /"<<endl;
		cout<<"   \\   ~ ~ ~ "<<endl;
		cout<<"     ̅/  ~  \\"<<endl;
	}else{
		cout<<"                        |||||||||||               "<<endl;
		cout<<"    _____/\\             |  /   \\  |  "<<endl;
	   	cout<<"   / ______|            | /     \\ |   "<<endl;
		cout<<"  / / ~ ~~ \\            |_________|"<<endl;
		cout<<"  |/  _  _ |"<<endl;
		cout<<"__(     >  |______________________________ "<<endl;
		cout<<"  /\\~   "<<mouth<<"  /"<<endl;
		cout<<"  \\   ~ ~ ~ "<<endl;
		cout<<"    ̅/  ~  \\"<<endl;
	}
	line(1);
}

void box(string text){
   	int cut = text.length()/2;
	system("clear");
	guy();
	for(int x = 0; x < text.length(); x++){
		cout<<text.at(x);
		if(x == 41 || x == 82){
		   	cout<<endl;

		}
	}
	cout<<endl;
	cout<<"                           (e)Continue"<<endl;
	line(1);
	input();
}

void intro(){
   	box("");
   	box("OH... uh.. Hello, sorry I forgot your werestarting today...");
	box("but this is perfect time I already have a job for you...");
	box("My name is Prof. Tree.. and let me quicklygive you a long winded run down on what  is going on...");
	box("You see I have been working on some       experiments and one has seemed to gone   wrong...");
	box("I was working on my cloning gun and it    seems to have a side effect of shrinking the particapents...");
	box("And I \"accidentaly\" used it on all my     employees...");
	box("And now they have all escaped their are   hundreds of them running around in the   tall grass outside my office...");
	box("The job I have for you is that I need you to find all of the clones of my employees");
       	box("You \"haveta getum all\"™ or at least a   some of each...");
	box("just enough to put them back togeather to form one person..");
	box("but that is not all.. they seem to be     pretty full of radiation so I want you toderadiate them...");
	box("This will be done with these deradiation  stones, you can find them in the caves   around my office for some reason...");
	box("The other problem is that I know I have   six employees... ");
	box("but that is about it so while you are out there can you fill out this list of all  their names..");
	box("Also add in there battle stats while you  are at it... for an unrelated reason...");
	box("You can try to battle these guys if you   want but it probobly wont do anything,   given it's not programed into the game...");
	box("Here are some nets you can catch them withtoo, just trap them in the nets and stuffthem in your backpack they sould be fine...");
	box("You can find me standing outside my lab   when you have found them all I will be   the number 9 standing there...");
	box("Well goodluck and find them! It is a lot  harder to higher new employees than you  think...");
}

void ending(){
	box("Wow I never though you would find them all... nice job I guess...");
	box("I mean I am not sure how much fun you actually had but...");
	box("and turns out it is not actually that hard to replace your employees...");
	box("I guess you deserve something though... hmmmmmm");
	box("hmmmmmmmmmmm... hmmmmmmmmmmmm... hmmmmmm");
	box("How about I give you...");
	box("I would say a job but I though you would die from the radioation on the other employees...");
	box("So I hired someone else to take your place... ");
	box("How about $100 and you never speak of this again... Okay?");
	box("Perfect now goodbye...");
}

int main(int argc, char *argv[]){
	srand(time(0));
  string arg;u4e$kv7!v9O*@W2
  if(argc < 2){
    arg == "f";
  }else{
    arg == argv[1];
  }
  map game(125,45, arg);

	start_screen();
	int ans = main_menu();

	if(ans == 1){
		intro();
		bool loop = true;
		game.print_map();
		while(loop == true){
			loop = game.move();
		}
	}else if(ans == 2){
		bool loop = true;
		game.print_map();
		while(loop == true){
			loop = game.move();
		}
	}else if(ans == 2){
		cout<<"goodbye!"<<endl;
		exit(0);
	}
	void ending();
	return 0;
}
