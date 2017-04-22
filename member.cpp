#include<stdio.h>
#include<fstream>
#include<iostream>
#include<string>
#include<ctype.h>
#include<cstring>
#include<stdlib.h>
using namespace std;

// Book module for LMS system. Which will store all books record.

class MEMBERS
{
	private:
		int member_id = 1000, year_of_joining, active = 1;
		char member_name[32], member_type[32], phone[15], address[100];
	
	protected:
		
		//void add_book(int, string, string, string, int, float, int);
		//void delete_book(void);
		//void update_book(int, int, int);
		//void update_book(int, char[], char[], char[]);
		
	public:
		
		void delete_member(void);
		void update_member(void);
		void add_member(char[], char[], char[], char [], int, int);
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

void MEMBERS:: delete_member(void)
{
	int m_id, flag_d = 0;
        fstream file, file1;

        file.open("MEMBER.dat", fstream::in);
        file1.open("tmp1.dat",ios::out|ios::binary);
	cout << "Enter ID of Member to be Deleted : ";
	cin >> m_id;

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

void MEMBERS:: update_member(void)
{
        int m_id, year_of_joining1, active1, flag_u = 0;
	char m_name[32], phone1[10], address1[32], member_type1[32];
        fstream file, file1;

        file.open("MEMBER.dat", fstream::in);
        file1.open("tmp1.dat",ios::out|ios::binary);
	
	cout << "Enter ID of Member to be Updated : ";
       	cin >> m_id;

        while(file.read((char *) this, sizeof(MEMBERS))){
                if (member_id == m_id)
                {
                        flag_u = 1;
        		cout << "Enter name of the member : ";
        		cin >> m_name;
        		cout << "Enter phone no of the member : ";
        		cin >> phone1;
        		cout << "Enter address of the member : ";
        		cin >> address1;
        		cout << "Enter joining year of member : ";
        		cin >> year_of_joining1;
        		cout << "Enter member type (Teacher / Student) : ";
        		cin >> member_type1;
        		cout << "Enter member active or not (1/0) : ";
        		cin >> active1;
                        
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
	memberObj.delete_member();
	memberObj.list_members();
	memberObj.update_member();
	memberObj.list_members();

	return 0;
}



