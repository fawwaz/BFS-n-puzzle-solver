#include <vector>
#ifndef SIMPUL_H
#define SIMPUL_H
using namespace std;

class Simpul{
private:
	static int num_of_node;
	int state_id;
	int parent_id;
	vector<vector<int> > State;
	char movement;
	char blank_x,blank_y; // disimpan untuk menyimpan posisi yang blank
public:
	typedef Simpul simpul;  // typedef simpul as simpul
	//ctor
	Simpul(vector<vector<int> >,int,char,char,char);//input:The state, parent node and the movement that generate that
	~Simpul();
	//Setter Getter
	void set_num_of_node(int);
	void set_state_id(int);
	void set_parent_id(int);
	void set_state(vector<vector<int> >) const;
	void set_movement(char);
	void set_blank_x(char);
	void set_blank_y(char);
	
	int get_num_of_node();
	int get_state_id();
	int get_parent_id();
	vector<vector<int> > get_state();
	char get_movement();
	char get_blank_x();
	char get_blank_y();

	// Custom method used for set comparation
	bool operator==(const Simpul&) const;
	bool operator<(const Simpul&) const;
};
#endif
