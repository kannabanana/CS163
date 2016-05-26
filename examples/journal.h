struct node
{
	journal_entry entr;
	node * next;


}

class journal_entry
{

	public:
		journal_entry();
		~journal_entry();
		int create_entry(char * title, char * notes);		//insert
		int display(void);					//display
		int copy_entry(const journal_entry & copy_from);	//copy
		int retrieve(char * matching_title, journal_entry & found);
		journal_entry retrieve(char * match);
	private:
		char * title;
		char * notes;
	};
	bool again();


//main:
//journal_entry match_entry
//match_entry = retrieve("day1 notes");
