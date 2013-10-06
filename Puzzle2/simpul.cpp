#include "simpul.h"

using namespace std;
int Simpul::num_of_node = 0;

Simpul::Simpul(vector<vector<int> > S,int P, char M,char _blank_x,char _blank_y){
	state_id=num_of_node;
	num_of_node++;
	State=S;
	parent_id=P;
	movement=M;
	blank_x=_blank_x;
	blank_y=_blank_y;
}
Simpul::~Simpul(){
}

void Simpul::set_num_of_node(int val){num_of_node = val;}
void Simpul::set_state_id(int val){state_id=val;}
void Simpul::set_parent_id(int val){parent_id=val;}
void Simpul::set_state(vector<vector<int> > P)const{State=P;}
void Simpul::set_movement(char val){movement=val;}
void Simpul::set_blank_x(char val){blank_x=val;}
void Simpul::set_blank_y(char val){blank_y=val;}
	
// Apakah saya sudah layak untuk diuji masuk bikin 
int Simpul::get_num_of_node(){return num_of_node;}
int Simpul::get_state_id(){return state_id;}
int Simpul::get_parent_id(){return parent_id;}
vector<vector<int> > Simpul::get_state(){return State;}
char Simpul::get_movement(){return movement;}
char Simpul::get_blank_x(){return blank_x;}
char Simpul::get_blank_y(){return blank_y;}

bool Simpul::operator<(const Simpul& Other) const{
	/*
	*	Mengoverride operator == untuk digunakan dalam STL set, definisi lebih kecil jika 
	*
	**/
}

bool Simpul::operator==(const Simpul& Other) const{
	/*
	*	Mengoverride operator == untuk digunakan dalam STL set, definisi lebih kecil jika 
	*
	**/
	vector<vector<int> > matrix_other = Other.get_state();
	bool result=true; // asumsi mula mula current simpul sama dengan yang lain
	for (int i = 0; i < this->State.size(); i++)
		for (int j = 0; j < this->State[i].size(); j++)
			if (this->State[i][j] != matrix_other[i][j] ) // result diset false jika ditemukan satu elemen yang berbeda
					result = false;
	return result;		
}
