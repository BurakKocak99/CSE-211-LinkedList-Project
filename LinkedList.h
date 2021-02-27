#include<string.h>
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;
class Node{
public:
	Node(){
		age_next=0;
		name_next=0;
	}
	Node(string str,int num){
		name=str;age=num;
		age_next=0;name_next=0;
	}
	Node(Node* ptr1,Node* ptr2){
		age_next=ptr1;name_next=ptr2;
	}
	int age;
	string name;
	Node* age_next;
	Node* name_next;	
};
class Person{
public:
	Person(){
		name_head=0;age_head=0;
		name_tail=0;age_tail=0;
	}
	void add(string str,int num);
	bool remove(string str); 	
	void uptade(string name,int num);
	void printByAge();
	void printByName();
	void loadFile(string filename);
	void saveToFileByAge(string filename);
	void saveToFileByName(string filename);
private:
	Node* age_head;
	Node* age_tail;
	Node* name_head;
	Node* name_tail;	
};


void Person::add(string str,int num){//ADD
	if(name_head  == 0){
		Node* tmp=new Node(str,num);
		age_head=tmp;name_head=tmp;
		age_tail=age_head;
		name_tail=name_head;
		
	}
	else{
		
		Node* tmp=new Node(str,num);
		tmp->age_next=age_head;tmp->name_next=name_head;
		Node* tmp2;
		Node* tmp3;
		if((tmp->age_next == age_head)&&(tmp->age < age_head->age)){
		
			age_head=tmp;	
			}
		while(age_head != tmp){//Adding age.
			if(tmp->age_next->age_next == 0){		
				
				age_tail=tmp;
				tmp->age_next->age_next=tmp;
				tmp->age_next=0;
				break;
			}
			if(tmp->age < tmp->age_next->age_next->age){
				
				tmp2=tmp->age_next->age_next;
				tmp->age_next->age_next=tmp;
				tmp->age_next=tmp2;
				break;
			}
			tmp->age_next=tmp->age_next->age_next;
		}
		if((tmp->name_next == name_head)&&(tmp->name_next->name > tmp->name )){		
			name_head=tmp;
			}
		while(name_head != tmp){//Adding name.
		
			if(tmp->name_next->name_next == 0){
				name_tail=tmp;
				tmp->name_next->name_next=tmp;
				tmp->name_next=0;
				break;
			}
			if( tmp->name_next->name_next->name > tmp->name ){
				tmp3=tmp->name_next->name_next;
				tmp->name_next->name_next=tmp;
				tmp->name_next=tmp3;
				break;
			}	
			tmp->name_next=tmp->name_next->name_next;
	}
	tmp2=0;tmp3=0;
	delete tmp2;delete tmp3;//Deleting temporary pointers
	}
	}
	
	
	
bool Person::remove(string str){//Remove
	bool isRemoved=false;
	if(age_head == 0){
		return false;
	}
	if((age_head == age_tail)&&(age_head->name == str)){
		age_head=age_tail=0;
		name_head=name_tail=0;
		return true;
	}
	else if(age_head==age_tail){
		return false;
	}
	Node* current=age_head;
	Node* next=age_head;
	Node* prev;
	
	
	
	while(current != 0){//deletin age_next pointer
		next=next->age_next;
		if(str == current->name){	
			isRemoved=true;	
		
			if(age_head==current){
				age_head=current->age_next;
				current->age_next=0;
				break;
			}
			
			
			if(next == 0){
				prev->age_next=0;
				age_tail=prev;
				break;
			}
			prev->age_next=next;
			current->age_next=0;
			break;
			}
			prev=current;
			current=next;
					
	}
	current=name_head;next=name_head;
	while(current != 0){//deleting name_next pointer
		
		next=next->name_next;
		if(str == current->name){	
			if(name_head==current){
				name_head=current->name_next;
				current->name_next=0;
				break;
			}
			
			if(name_tail==current){
				prev->name_next=0;
				name_tail=prev;
				break;
			}
		
		    prev->name_next=next;
			current->name_next=0;
			break;
			}
			
			prev=current;
			current=next;
			
	}
	prev=0;current=0;next=0;
	delete prev;delete current;delete next;//deleting temporary pointers
	return isRemoved;	
}




void Person::uptade(string str,int data){
	if(remove(str))
		add(str,data);
	else
		cout<<"There is no person who has name as "<<str<<endl;	
}	

void Person::printByAge(){
	if(age_head == 0){
		cout<<"List is Empty."<<endl;	
	}
	else{	
		Node* tmp_age;
		tmp_age=age_head;
		while(tmp_age != 0){
			cout<<tmp_age->name<<"\t";
			cout<<tmp_age->age<<endl;
			tmp_age=tmp_age->age_next;
}
	delete tmp_age;//deleting temporary pointer
}
}


void Person::printByName(){
	if(name_head == 0){
		cout<<"List is Empty."<<endl;	
	}
	else{
		Node* tmp_name;
		tmp_name=name_head;
		while(tmp_name != 0){
			cout<<tmp_name->name<<"\t";
			cout<<tmp_name->age<<endl;
			tmp_name=tmp_name->name_next;
		}
		delete tmp_name;//deleting temporary pointer
	}
}	
	
	
	
	
void Person::loadFile(string str){//LOAD FILE 
	fstream file;
	file.open(str.c_str());
	int a;
	string s;
	while(file >> s){
			file >> a;
			add(s,a);
	}
	file.close();
}



void Person::saveToFileByAge(string filename){//SAVE FILE BY INTEGER

	ofstream file;
	file.open(filename.c_str(),std::ios_base::app);

	
	if(age_head == 0){
		cout<<"List is Empty."<<endl;	
	}
	else{	
		Node* tmp_file1;
		tmp_file1=age_head;
		while(tmp_file1 != 0){
			file<<tmp_file1->name<<"\t"<<tmp_file1->age<<"\n";
			tmp_file1=tmp_file1->age_next;
	}
	delete tmp_file1;//deleting temporary pointer
	}
	file.close();	
	
	}





void Person::saveToFileByName(string filename){//SAVE FILE BY STRING
	ofstream file;
	file.open(filename.c_str(),std::ios_base::app);
	if(name_head == 0){
	cout<<"List is Empty."<<endl;	
	}
	else{
		Node* tmp_file2;
		tmp_file2=name_head;
		while(tmp_file2 != 0){
			file<<tmp_file2->name<<"\t"<<tmp_file2->age<<"\n";
			tmp_file2=tmp_file2->name_next;
		}
		delete tmp_file2;//deleting temporary pointer
	}
	file.close();
	
}

