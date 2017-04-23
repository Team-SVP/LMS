class BOOKS
{
	 private:
                int book_code = 0, copies, avail;
                float price;
                char  book_name[100], author_name[100], publication[100];


        public:

                void delete_book(int);
                void update_book(int, int, int);
                void update_book_name(int , char *, char *, char *);
                void add_book(char *, char *, char *, int, float, int);
                void list();


};

