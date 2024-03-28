#ifndef __KNIGHT_H__
#define __KNIGHT_H__

#include "main.h"

void display(int HP, int level, int remedy, int maidenkiss, int phoenixdown, int rescue);
int Read_string(int & HP, int & level,int &levelO, int &remedy, int & maidenkiss, int & phoenixdown, int & rescue,int &m,int &Max_HP);
double baseDamage(double &N,int &level,int &levelO);
int New_HP(int&HP,int &level,int levelO);
int New_level(int &HP,int &level,int &levelO,int &remedy,int &maidenkiss,int &phoenixdown,int &rescue);
int Thuocgiai(int &HP,int &level,int &levelO,int &remedy,int &maidenkiss,int &phoenixdown,int &rescue,double &N,int &m,int &Max_HP);
int return_rescue(int &levelO,int &m,int &HP,int &rescue);
int checkPos(int levelO);
int Return_HP(int &HP,int &level,int &levelO,int &phoenixdown,int &remedy,int &maidenkiss,int &rescue);
int compare(int &HP,int &level,int &levelO,int &phoenixdown,int &remedy,int &maidenkiss,int &rescue,int &Max_HP);
int Fibonacci(int n);
int NT(int &HP);
int NTGN(int &HP);
int Select_Mush(int &HP,int &level,int &levelO,int &remedy,int &maidenkiss,int &phoenixdown,int &rescue,int Max_HP);
void DisplayMush(int &n2,string& s);
int Mush_ghostP1(int &HP,int& n2);
int Mush_ghostP2(int &HP,int &n2);
int Mush_ghostP3(int &HP,int &n2);
int Mush_ghostP4(int &HP,int &n2);
int Use_Mush_ghost(int &HP,int &levelO);
void Select_thuoc(int &remedy, int &maidenkiss, int &phoenixdown,int &levelO );
int Dem_thuoc(int &levelO,int &remedy,int &maidenkiss,int &phoenixdown);
int Merlin_SK18(int &HP,int &level,int &levelO,int &remedy,int &maidenkiss,int &phoenixdown,int &rescue,int &Max_HP);
int Display_const(int &HP,int &level,int &levelO,int &remedy,int &maidenkiss,int &phoenixdown,int &rescue);
int Displayno_const(int &HP,int &level,int &levelO,int &remedy,int &maidenkiss,int &phoenixdown,int &rescue);
int Arthur(int &HP,int &level,int &levelO,int &remedy,int &maidenkiss,int &phoenixdown,int &rescue,int &Max_HP);
int Lancelot(int &HP,int &level,int &levelO,int &remedy,int &maidenkiss,int &phoenixdown,int &rescue,int &Max_HP);
int Browser(int &HP,int &level,int &levelO,int &remedy,int &maidenkiss,int &phoenixdown,int &rescue,int &Max_HP);
int Kill_Brower(int &HP,int &level,int &levelO,int &remedy,int &maidenkiss,int &phoenixdown,int &rescue,int &Max_HP);
void adventureToKoopa(string file_input, int & HP, int & level, int & remedy, int & maidenkiss, int & phoenixdown, int & rescue);

#endif // __KNIGHT_H__
