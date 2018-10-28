/******************************
 * Program: Pocket men
 * Author: Austin Wilmoth
 * Date: 5/28/17
 * Description: base case for pocket men
 * intput: none
 * Output: none
 ****************************/

#ifndef POCKET_MEN_H
#define POCKET_MEN_H

#include <string>

using namespace std;

class pocket_men{
	protected:
		string type;
		string name;
		
		int catchability;
		int rairness;
		bool seen;

		int level;
		int count;
		int upgrade_count;
		
		int pp;
		int hp;
		int max_hp;

		string fun_fact;
	public:
		//functions
		int get_damage();
		void evolve();
		void evolve_2(int &);
		void stats(int, bool ff = false);
		
		//getters these are unnecicary and should not be for every variable that is why you have function otherwise just make a struct... its making the variables public but with extra steps... same with setters... they also stress me out so i might delete them because of that...
		string get_type() const;
		string get_name() const;
		
		int get_catchability() const;
		int get_rairness() const;

		int get_level() const;
		int get_count() const;
		int get_upgrade_count() const;

		int get_pp() const;
		int get_hp() const;
		int get_max_hp() const;

		//setters
		void set_type(const string &);
		void set_name(const string &);
		
		void set_catchability(const int &);
		void set_rairness(const int &);
		void set_seen(const bool &);

		void set_level(const int &);
		void set_count(const int &);
		
		void set_pp(const int &);
		void set_hp(const int &);
		void set_max_hp(const int &);
		
};

#endif
