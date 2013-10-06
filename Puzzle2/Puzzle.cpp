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

vector<vector<int> > Puzzle::Swap(int x,int y,char movement, vector<vector<int> > P){
	/*
	* Sistem koordinat mengacu kiri atas sebagai titik 0,0 lalu x ke bawah dan y ke kanan
	**/
	vector<vector<int> > Ret_val=P; //copy the puzzle 
	switch (movement){
	case 1 : //up
		//validate bisa di naikin ke atas gak jangan jangan udah paling atas lagi blank spacenya
		if (x>0) 
		{
			Ret_val[x][y] = Ret_val[x-1][y]; // lakukan swapping
			Ret_val[x][y] = 0;
		}else{
			Ret_val.clear(); // hapus elemen retval
		}
		break;
	case 2 : //right , ulangi seperti case 1 ...
		if (y<Puzzle_size-1) 
		{
			Ret_val[x][y] = Ret_val[x][y+1]; 
			Ret_val[x][y] = 0;
		}else{
			Ret_val.clear(); 
		}
		break;
	case 3 : //down
		if (x>Puzzle_size-1) 
		{
			Ret_val[x][y] = Ret_val[x+1][y]; 
			Ret_val[x][y] = 0;
		}else{
			Ret_val.clear(); 
		}
		break;
	case 4 : //left
		if (y>0) 
		{
			Ret_val[x][y] = Ret_val[x][y-1]; 
			Ret_val[x][y] = 0;
		}else{
			Ret_val.clear(); 
		}
		break;
	default:
		break;
	}
	return Ret_val;

}

/*
* FUNGSI vector<vector<int> > TO STRING vector<vector<int> >ToString() --> String
* input : 
* 	vector<vector<int> >
* init state : -
* final state : vector<vector<int> > input diterjemahkan menjadi serentetan String seperti contoh di buku
**/
string PuzzleToString(vector<vector<int> > P){
	string temp="";
	for (int i = 0; i < P.size(); i++)
	{
		for (int j = 0; j < P[i].size(); j++)
		{
			string stemp = to_string(P[i][j]);
			temp = temp + stemp + ",";
		}
	}
	temp = temp.substr(0,temp.length()-1);
	return temp;
}





void Puzzle::SolveBFS(){
	
	// Mencari posisi blank x dan blank y pada puzzle start untuk kemudian digunakan selanjutnya
	bool founded=false;char blankx,blanky;
	for (int i = 0; (i < Puzzle_Start.size() && !founded); i++){
		for (int j = 0; (j < Puzzle_Finish[i].size() && !founded); j++){
			if (Puzzle_Start[i][j]==0){
				blankx=i;
				blanky=j;
				founded=true;
			}
		}
	}
	
	
	// Sesuai dengan konstruktor yang sudah dibuat , 
	// Buatlah sebuah "simpul" dengan elemen elemen root node, yaitu statenya adalah kondisi mula mula puzzle, root node nya di set 0
	// Movement yang digunakan untuk ke state ini 0 (0 khusus root 1 untuk atas, 2 untuk kanan, 3 untuk bawah, 4 untuk kiri - clockwise rule)
	Simpul *Root = new Simpul(Puzzle_Start,0,0,blankx,blanky);
	bool isSolved=false;

	Simpul SimpulAktif=*Root; 
	while(!IsEqual(SimpulAktif.get_state(),Puzzle_Finish)){
		HimpunanRuangSolusi.insert(SimpulAktif);

		//Mencari semua simpul yang mungkin di generate dari titik aktif node
	}
}

vector<Simpul> Puzzle::GenerateSimpulAnak(Simpul Parent){
	// Setup awal awal terlebih dahulu
	vector<vector<int> > StateParent=Parent.get_state();
	int blankx,blanky;
	blankx = Parent.get_blank_x();
	blanky = Parent.get_blank_y();

	// Gunakan fungsi swap untuk mencoba seluruh state yang bisa digenerate dengan memainkan variable input urutan ke 3 milik fungsi swap
	// 1 untuk atas, 2 untuk kanan, 3 untuk bawah, 4 untuk kiri
	vector<Simpul> vtemp;
	vtemp.clear();
	for (int i = 0; i < 4; i++){
		swa
	}
}


