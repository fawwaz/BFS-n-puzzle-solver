#include <iostream>
#include <stdio.h>
#include <vector>
#include <fstream>
#include <string>
#include <cstdio>
#include <queue>
#include <hash_map>
#include "simpul.h"
#ifndef PUZZLE_H
#define PUZZLE_H


using namespace std;
class Puzzle{
private:
	vector<vector<int> > Puzzle_Start;	
	vector<vector<int> > Puzzle_Finish;
	int Puzzle_size;
	queue<Simpul> antrian_simpul;
	Simpul *Root; // Root simpul
	//hash_map<Simpul> Domain_simpul;


public:
	//Ctor dtor
	Puzzle();
	~Puzzle();
	
	//Setter Getter
	void Set_Puzzle_Start(vector<vector<int> > );
	void Set_Puzzle_Start(int,int,int); // input: x,y,value
	void Set_Puzzle_Finish(vector<vector<int> >);
	void Set_Puzzle_Finish(int,int,int); // input: x,y,value
	void Set_Puzzle_size(int); // input:value
	int Get_Puzzle_Start(int,int);// return the value of input: x,y
	vector<vector<int> > Get_Puzzle_Start(); // return the vector
	int Get_Puzzle_Finish(int,int); // return the value of input : x,y
	vector<vector<int> > Get_Puzzle_Finish(); // return the vector
	int Get_Puzzle_Size(); 
	
	//Special Method
	void LoadFiles(); 
	void CetakPuzzle(vector<vector<int> >);
	vector<vector<int> > Swap(int,int,char,vector<vector<int> >);
	bool IsValidSwap(int,char,int); // input: Current position of B, movement type(u/l/d/r), vector<vector<int> > size
	bool IsEqual(vector<vector<int> >,vector<vector<int> >); // return true when both vector<vector<int> > have same size and each element are equal
	string ConvertPuzzleToString(vector<vector<int> >);// Cetak puzzle vector<vector<int> > inpu
	void SolveBFS();

};
#endif