#ifndef ERROR_H
#define ERROR_H
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <string>

using namespace std;

void line(int);

char input();

//string sinput();

int pos_int();

int pos_int(char *);

signed int signed_int();

int pos_float();

int answer(int);

int answer(int ,char *);

float answer(float);

string str_answer(string *, int, bool wait = true);
#endif
