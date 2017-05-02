#ifndef __MEMBER_H
#define  __MEMBER_H
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
#endif
