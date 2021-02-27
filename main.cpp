
#include<string>
#include <iostream>
#include <fstream>
#include <iomanip>
#include "LinkedList.h"
using namespace std;
int main(){
	Person p1;
	string file="input_file.txt";
	string file2="age_sorted.txt";
	string file3="name_sorted.txt";
	p1.loadFile(file);
//	p1.remove();
//	p1.uptade();
	p1.saveToFileByAge(file2);
	p1.saveToFileByName(file3);
	p1.printByAge();
	cout<<endl;
	p1.printByName();
	return 0;
	
}









