#include "puzzle.h"

using namespace std;

int main(int argc, char const *argv[]){
	cout << "BIsmillah"<< endl;
	Puzzle P;
	P.LoadFiles();
	P.CetakPuzzle(P.Get_Puzzle_Start());
	P.CetakPuzzle(P.Get_Puzzle_Finish());
}