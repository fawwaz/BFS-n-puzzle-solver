#include "puzzle.h"

using namespace std;

int main(int argc, char const *argv[]){
	cout << "BIsmillah"<< endl;
	Puzzle P;
	P.LoadFiles();
	P.CetakPuzzle(P.Get_Puzzle_Start());
	P.CetakPuzzle(P.Get_Puzzle_Finish());
	cout << P.ConvertPuzzleToString(P.Get_Puzzle_Finish()) << endl;
	cout << "apakah sama " << P.IsEqual(P.Get_Puzzle_Start(),P.Get_Puzzle_Finish()) << endl;
}