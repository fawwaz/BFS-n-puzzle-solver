#include "puzzle.h"

using namespace std;

/*
* CONSTRUCTOR DESTRUCTOR
* SETTER GETTER
*
*
*
**/
Puzzle::Puzzle(){
}
Puzzle::~Puzzle(){
}

int Puzzle::Get_Puzzle_Size(){return Puzzle_size;}
vector<vector<int> > Puzzle::Get_Puzzle_Start(){return Puzzle_Start;}
int Puzzle::Get_Puzzle_Start(int x,int y){return Puzzle_Start[x][y];}
vector<vector<int> > Puzzle::Get_Puzzle_Finish(){return Puzzle_Finish;}
int Puzzle::Get_Puzzle_Finish(int x, int y){return Puzzle_Finish[x][y];}


void Puzzle::Set_Puzzle_Start(vector<vector<int> > _P){
	for (int j = 0; j <_P.size(); j++){
		Puzzle_Start[j]=_P[j];
	}
}
void Puzzle::Set_Puzzle_Start(int x,int y,int val){Puzzle_Start[x][y] = val;}
void Puzzle::Set_Puzzle_Finish(vector<vector<int> > _P){
	for (int j = 0; j <_P.size(); j++){
		Puzzle_Finish[j]=_P[j];
	}
}
void Puzzle::Set_Puzzle_Finish(int x,int y,int val){Puzzle_Finish[x][y] = val;}
void Puzzle::Set_Puzzle_size(int val){Puzzle_size=val;}

/*
* FUNGSI LOAD FILES
* input : 
* 	-
* init state : -
* final state : Global variables sudah terisi
**/
void Puzzle::LoadFiles(){	
	string s;
	
	Puzzle_size=0;
	
	//freopen("input.txt","r",stdin);
	freopen("input.txt","r",stdin);
	getline(cin,s);
	/*
	* RETRIEVE PUZZLE SIZE
	**/
	//getline(cin,s);
	//file_input >> s;
	for (int i = 0; i < s.length(); ++i)
		Puzzle_size= (Puzzle_size*10) + (int) (s[i]-'0');
	Puzzle_size=static_cast<int>(sqrt((Puzzle_size)+1)); // Real size is that
	
	/*
	* Set Zero ukuran nxn vector Puzzle start dan Puzzle finish
	**/
	vector<int> vtemp(Puzzle_size,0);
	for (int i = 0; i < Puzzle_size; ++i){
		Puzzle_Start.push_back(vtemp);
		Puzzle_Finish.push_back(vtemp);
		
	}
	
	/*
	* RETRIEVE START STATE 
	**/
	getline(cin,s);
	int m=0,n=0; // dummy var for looping only m:pointer baris, n:pointer kolom, 
	for (int i = 0; i < s.length(); i++){
		if (n==Puzzle_size){
			n=0; // Ganti baris
			m++;
		}

		if (s[i] >= '0' && s[i] <='9'){
			Puzzle_Start[m][n]= (Puzzle_Start[m][n] * 10) + (int) (s[i]-'0');
			//printf("\nm:%d n:%d val:%d",m,n,Puzzle_Start[m][n]);
		}else if (s[i] =='B'){
			Puzzle_Start[m][n]=0;
		}else if (s[i]==','){
			n++;
		}
		
	}
	
	
	/*
	* RETRIEVE FINAL STATE 
	**/
	getline(cin,s);
	
	m=n=0; // dummy var for looping only m:pointer baris, n:pointer kolom, 
	for (int i = 0; i < s.length(); ++i){
		if (n==Puzzle_size){
			n=0; // Ganti baris
			m++;
		}
		
		if (s[i] >= '0' && s[i] <='9'){
			Puzzle_Finish[m][n]= (Puzzle_Finish[m][n] * 10) + (int) (s[i]-'0');
		}else if (s[i] =='B'){
			Puzzle_Finish[m][n]=0;
		}else if (s[i]==','){
			n++;
		}

	}


	fclose(stdin);
	//file_input.close();
	

	/*
	* FUNGSI vector<vector<int> > TO STRING vector<vector<int> >ToString() --> String
	* input : 
	* 	vector<vector<int> >
	* init state : -
	* final state : vector<vector<int> > input diterjemahkan menjadi serentetan String seperti contoh di buku
	**/

	

	/*
	* FUNGSI IS vector<vector<int> > EQUAL
	* input : 
	* 	vector<vector<int> >, vector<vector<int> >
	* init state : -
	* final state : Mengembalikan nilai true jika kedua vector<vector<int> > "sama"(berukuran sama, dan setiap elemenya sama dengan elemen vector<vector<int> > lainya) dan false jika tidak sama
	**/
	
}

void Puzzle::CetakPuzzle(vector<vector<int> > _Puzzle){
	/*
	* FUNGSI CETAK vector<vector<int> >
	* input : 
	* 	vector<vector<int> >
	* init state : -
	* final state : vector<vector<int> > tercetak di layar (untuk debugging)
	**/
	for (int i = 0; i < _Puzzle.size(); ++i){
	 	for (int j = 0; j < _Puzzle[i].size(); ++j){
			printf("%d ",_Puzzle[i][j]);
		}
		printf("\n");
	}
}

bool Puzzle::IsEqual(vector<vector<int> > P1, vector<vector<int> > P2){
	bool equal=true;
	for (int i = 0; i < P1.size(); i++)
		for (int j = 0; j < P1[i].size(); j++)
			if (P1[i][j]!=P2[i][j])
				return false;
	return equal;
	
}

vector<vector<int> > Puzzle::Swap(int x,int y,char movement, vector<vector<int> > _Puzzle){
	vector<vector<int> > Ret_val=_Puzzle; //copy the puzzle 
	/*switch (movement){
	case "u" : //up
		break;
	case "l" : //left
		break;
	case "d" : //down
		break;
	case "r" : //right
		break;
	default:
		break;
	}*/
	return Ret_val;

}