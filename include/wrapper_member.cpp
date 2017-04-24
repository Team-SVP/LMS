#include<stdio.h>
#include<fstream>
#include<iostream>
#include<string>
#include<ctype.h>
#include<cstring>
#include<stdlib.h>
#include "member.h"
using namespace std;

void wrapper_add_member(MEMBERS obj_member)
{
	char m_name[32], m_type[32], p_no[32], addr[32];
	int yoj, act;

	cout << "Enter Member Name : ";
	cin >> m_name;
	
	cout << "Member type (Student / Teacher): ";
	cin >> m_type;
	
	cout << "Enter phone no : ";
	cin >> p_no;
	
	cout << "Enter address : ";
	cin >> addr;
	
	cout << "Enter year of joining : ";
	cin >> yoj;

	cout << "Enter active or not (1/0) : ";
	cin >> act;

	obj_member.add_member( m_name, m_type, p_no, addr, yoj, act);
	return;
}

void wrapper_list_members(MEMBERS obj_member)
{
	obj_member.list_members();	
}
	
void wrapper_delete_member(MEMBERS obj_member)
{
	int m_id;

	obj_member.list_members();
	
	cout << "Enter the ID of the member to delete : "; 
	cin >> m_id;

	obj_member.delete_member(m_id);
}



void wrapper_update_member(MEMBERS obj_member)
{
        char m_name[32], m_type[32], p_no[32], addr[32];
        int yoj, act, m_id;

        obj_member.list_members();

        cout << "Enter the ID of the member to update : ";
        cin >> m_id;

        cout << "Enter Member Name : ";
        cin >> m_name;

        cout << "Member type (Student / Teacher): ";
        cin >> m_type;

        cout << "Enter phone no : ";
        cin >> p_no;

        cout << "Enter address : ";
        cin >> addr;

        cout << "Enter year of joining : ";
        cin >> yoj;

        cout << "Enter active or not (1/0) : ";
        cin >> act;

        obj_member.update_member( m_id, m_name, p_no, addr, m_type, yoj, act);
        return;
}


// Book module for LMS system. Which will store all books record.
/*
class MEMBERS
{
	private:
		int member_id = 1000, year_of_joining, active = 1;
		char member_name[32], member_type[32], phone[15], address[100];
	
	public:
		
		void delete_member(int);
		void update_member(int, char *, char *, char *, char *, int , int);
		void add_member(char *, char *, char *, char *, int, int);
		void list_members();

};


void MEMBERS::add_member(char *member_name1, char *member_type1, char *phone1, char *address1, int year_of_joining1, int active1)
{
	fstream file;
	
	file.open("MEMBER.dat", fstream::in);
	file.seekg(-sizeof(MEMBERS),std::ios_base::end);
	file.read((char *) this, sizeof(MEMBERS));
	file.close();
	member_id = member_id + 1;
	strcpy(member_name, member_name1);
	strcpy(member_type, member_type1);
	strcpy(phone, phone1);
	strcpy(address, address1);
	year_of_joining = year_of_joining1;
	active = active1;
	
	file.open("MEMBER.dat",ios::out|ios::binary | ios::app);
	file.write((char *) this, sizeof(MEMBERS));
	file.close();	

}

void MEMBERS:: delete_member(int m_id)
{
	int flag_d = 0;
        fstream file, file1;

        file.open("MEMBER.dat", fstream::in);
        file1.open("tmp1.dat",ios::out|ios::binary);

        while(file.read((char *) this, sizeof(MEMBERS))){
		if (member_id == m_id)
			flag_d = 1;
		else  
        		file1.write((char *) this, sizeof(MEMBERS));
	}
        file.close();
        file1.close();
	if (flag_d == 0)
		cout << " ****** Record Not Found ******\n";
	else	
		flag_d = 0;
	remove("MEMBER.dat");
	rename("tmp1.dat", "MEMBER.dat");

}

void MEMBERS:: update_member(int m_id, char *m_name, char *phone1, char *address1, char *member_type1, int year_of_joining1, int active1)
{
        int flag_u = 0;
        fstream file, file1;

        file.open("MEMBER.dat", fstream::in);
        file1.open("tmp1.dat",ios::out|ios::binary);
	
        while(file.read((char *) this, sizeof(MEMBERS))){
                if (member_id == m_id)
                {
                        flag_u = 1;
                        
			strcpy(member_name, m_name);
                        strcpy(phone, phone1);
                        strcpy(address, address1);
                        strcpy(member_type, member_type1);

			year_of_joining = year_of_joining1;
			active = active1;

                        file1.write((char *) this, sizeof(MEMBERS));
                }
                else
                        file1.write((char *) this, sizeof(MEMBERS));
        }
        file.close();
        file1.close();

        if (flag_u == 0)
                cout << " ****** Record Not Found ******\n";
	else
		flag_u = 0;

        remove("MEMBER.dat");
        rename("tmp1.dat", "MEMBER.dat");

}


void MEMBERS:: list_members() {
	fstream file;
        file.open("MEMBER.dat",ios::in|ios::binary);
        file.seekg(0,ios::beg);
	cout << "Member ID \t" << "Memmber Name\t" << "Address\t" << "Phone\t" << "Member type\t" << "Year of Joing\t" << "Active" << endl;
        while(file.read((char *) this, sizeof(MEMBERS))) {
		cout << member_id << "\t\t" << member_name  << "\t\t" << address << "\t\t"  << phone << "\t\t" << member_type << "\t\t" << year_of_joining << "\t\t" << active  <<endl;
	}
        file.close();
	

}


int main() {

	MEMBERS memberObj;

	memberObj.add_member( "Testing", "Student", "93734634434", "Pune", 2016, 1);
	memberObj.add_member( "Testing", "Student", "93734634434", "Pune", 2016, 1);
	memberObj.add_member( "Testing", "Student", "93734634434", "Pune", 2016, 1);
	memberObj.add_member( "Testing", "Student", "93734634434", "Pune", 2016, 1);
	memberObj.list_members();
	memberObj.delete_member(1002);
	memberObj.list_members();
	memberObj.update_member(1003, "Testing123", "9921642540", "Haveli", "Teacher", 2019, 0);
	memberObj.list_members();

	return 0;
}
*/
