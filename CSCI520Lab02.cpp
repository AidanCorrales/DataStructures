/**
* A linked list and bag program where you can add students using a struct
*
* @Corrales, Aidan
* @CSCI 520 lab 02
* @date 09/23/2024
*/

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

struct Student{
	int id;				//Variables for the student struct
	string lname;		//or the "data" section of our linked list
	string fname;
	string city;
	string bday;
	string dep;
	string level;
	Student *next;
						//What values to pass to the variables when calling the student struct
	Student(int i, string& ln, string& fn, string& c, string& b, string& d, string& l, Student* p){
		id = i;
		lname = ln;
		fname = fn;
		city = c;
		bday = b;
		dep = d;
		level = l;
		next = p;
	} 					//Final item in the linked list, you can see by next being NULL
	Student(int i, string& ln, string& fn, string& c, string& b, string& d, string& l){
		id = i;
		lname = ln;
		fname = fn;
		city = c;
		bday = b;
		dep = d;
		level = l;
		next = NULL;
	}
	
};

typedef Student *ptr; 	//Pointer instance initialized

class Bag{				//Class where the function to preform on our bag are defined
	public:
		Bag();
		bool addStudent(int iD, string lname, string fname, string city, string bday, string dep, string level);
		bool idSearch(int iD);
		bool nameSearch(string name);
		bool remove(int iD);
		bool removeLast();
		unsigned short getCap();
		unsigned short getSize();
		void listByCity(string city);
		void listBag();
		void modByID(int iD);
		void removeAll();
	private:
		ptr first;
		ptr last;
		unsigned short size;
		const unsigned short cap = 1000;
};
Bag::Bag(){
	this->size = 0;
	this->first = this->last=NULL;	//Set the pointers to the starting node
	cout<<"A bag of capacity "<<getCap()<<" was created"<<endl<<endl;
}
unsigned short Bag::getCap(){
	return this->cap;
}
unsigned short Bag::getSize(){
	return this->size;
}
bool Bag::addStudent(int num, string lname, string fname, string city, string bday, string dep, string level){
	ptr i, student = new Student(num, lname, fname, city, bday, dep, level);
	//Call student from struct to create new student to add to linked list
	if(student == NULL)
		return false;
		
	if(first == NULL)				//If first node in list
		first = student;			//Set first data to new student data
	else
		last->next = student;		//Add student at next node
		
	last = student;					//Set new last
	size++;							//Increment count
	return true;
}
bool Bag::remove(int num){			//ID passed as num
	ptr after, before;				//make pointers
	
	if(first == NULL)
		return false;
		
	after = before = first;			//Set pointers to beginning of list
	
	if(num == first->id){			//Check first node ID is num
		if(first == last)
			first = last = NULL;	//Set pointers to NULL, removing the point to first node
		else
			first = first->next;	
		delete after;				//Deallocate node
		size --;					//Decrement count
		return true;
	}
	
	after = after->next;			//Set before pointer to next
	
	while(after != NULL){			//Iterates until last node
		if(after->id == num){		//Check if node ID is num being searched
			before->next = after->next;
									
			if(after == last)
				last = before;		
						
			delete after;			//Dealocate item
			size--;					//Decrement count
			return true;
		}
		before = after;				//Rearrange pointers to jump over deleted node
		after = after->next;
	}
	return false;
}
void Bag::removeAll(){
	ptr place;
	
	while(first != NULL){			//Iterate through full list
		place = first;
		first = first->next;		//Jump pointer
		delete place;				//Delete current node
		size--;
	}

	delete first;
	cout << "Bag emptied. " << size << " students remaining.\n" << endl;
}
bool Bag::removeLast(){
	ptr before, current, after;		//I added an extra pointer to make it easier on my brain
	
	current = first;				//Set pointer to first node
	after = first->next;
	
	if(after == NULL){				//Check if first node is last
		first = NULL;				//Set starting pointer
		delete current; 			//Delete node
		size--;						//Decrement bag
		cout<<"Last student cut\n"<<endl;
		return true;
	}
		
	while(after != NULL){			//Iterate through bag until final item
		before = current;			//Rearrange node pointers
		current = after;
		after = after->next;
	}
	before->next = after;			//Node pointers set to jump end item
	delete current;					//Delete node
	size--;							//Decrement bag
	cout<<"Last student cut\n"<<endl;
	return true;
}
bool Bag::idSearch(int num){		
	ptr it = first;					

	if(it == NULL)					//Checks for no items
		return false;
		
	for(int i=0; i<size; i++)		//Iterates through linked list until size
	{
		if(num == (it->id))			//Checks if ID num passed is current node's ID value
			return true;			//Returns true if found
		it = it->next;
	}
	return false;					//Returns false if whole list is iterated with no num
}
bool Bag::nameSearch(string lastname){
	ptr it = first;					//Works the same as ID search, but checks node lastname instead of ID
	
	if(it == NULL)
		return false;
		
	for(int i=0; i<size; i++)
	{
		if(!lastname.compare(it->lname))
			return true;
		it = it->next;
	}
	return false;
}
void Bag::listByCity(string city){	//This works like the search functions, except it prints in the if statement
	ptr it = first;					//instead of return and goes through the full list
	
	cout << "Students who live in " << city << ":" << endl;
	for(int i=0; i<size; i++)
	{
		if(!city.compare(it->city))
			cout << "\t"<< it->id << "\t" << it->fname << "\t" << it->lname << endl;
		it = it->next;
	}
	cout<<endl;
}
void Bag::listBag(){				//Iterates through full bag and prints all attributes of each node
	cout << "\n" << size << " students: " << endl;	//This fulfills the count requirement
	/*ptr it = first;				//Uncomment to print entire bag
	int i=0;						//I used this to test different scenarios
									//such as adding students after removing all
	while(it !=NULL)				//and cutting final student and search/modify functions
	{
		cout << "\t"<< it->id << "\t" << it->fname << "\t" << it->lname << "\t" <<\
		it->city << "\t" << it->bday << "\t" << it->level << "\t" << it->dep << endl;
		it=it->next;
		i++;
	}*/
	cout<<endl;
}

class Generator{					//Class for functions to generate random data to fill student
	public:
		//Generator();
		int randNumRange(int a, int b);
		int idGenerator();
		string nameGenerator();
		string cityGenerator();
		string bdayGenerator();
		string depGenerator();
		string levelGenerator();
		const int nameMax = 5;
		const int nameMin = 2;
	    const int idMax = 99999;
	    const int idMin = 10000;
  private:
};

void Bag::modByID(int num){			//This function comes after the Generator class since it uses
	ptr it = first;					//an instance of generator
	Generator g;
	
	if(it == NULL)
		cout<< "No students\n" << endl;
		
	for(int i=0; i<size; i++)		//Iterate through bag
	{
		if(num == (it->id)){		//Until ID found, then generate new student data
			cout << "Old student data:\t" << it->id << "\t" << it->fname << " " << it->lname <<\
			"\t" << it->city << "\t" << it->bday << "\t" << it->level << "\t" << it->dep << endl;
			it->city = g.cityGenerator();
			it->fname = g.nameGenerator();
			it->lname = g.nameGenerator();
			it->city = g.cityGenerator();
			it->bday = g.bdayGenerator();
			it->dep = g.depGenerator();
			it->level = g.levelGenerator();
			cout << "New student data:\t" << it->id << "\t" << it->fname << " " << it->lname <<\
			"\t" << it->city << "\t" << it->bday << "\t" << it->level << "\t" << it->dep << endl << endl;
			break;
		}
		else if(it->next==NULL){
			cout << "Student not found.\n" << endl;
			break;
		}
		it = it->next;
	}
}

int Generator::randNumRange(int low, int high){
  return rand()%(high-low+1)+low;	//Random number function with max and min
}

int Generator::idGenerator(){		//Generates ID using variables assigned in Generator
  return randNumRange(idMin,idMax);
}

string Generator::levelGenerator(){	//Returns random index from an array of 2
  string level[]={"Undergaduate","Graduate"};
  return level[randNumRange(0,1)];
}

string Generator::cityGenerator(){	//Returns random index from an array of 9
  string cities[]={"Commerce,TX", "Dallas,TX", "Austin,TX ", "Houston,TX ", "Paris,TX",
        "Memphis,TN", "Jackson,MI", "Chicago,IL", "Miami,FL", "Seattle,WA"};
  return cities[randNumRange(0,9)];
}

string Generator::depGenerator(){	//Returns random index from an array of 5
  string cities[] = {"Agriculture", "Business", "Education", "Humanities", "Engineering", "Design"};
  return cities[randNumRange(0,5)];
}

string Generator::bdayGenerator(){	//Generates two random ints for year and day
	int day = randNumRange(1,31);	//And concatenates with random month as string from and array
	int year = randNumRange(1990,2020);
	string mon[] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun",
	"Jul", "Aug", "Sep", "Oct", "Nov", "Dec",};
	string full = to_string(year) + "-" + mon[randNumRange(0,11)] + "-" + to_string(day);
	return full;
}

string Generator::nameGenerator(){	//Generates string of random letters length 2-5
  int length = randNumRange(nameMin,nameMax);
  string name;
  
  name.reserve(length);				//Found .reserve helps by not adding whitespace
  									//Which makes the lname search a little easier
    name += rand() % 26 + 65;		//Ascii range for capital letter
    for (int i = 1; i < length; ++i) {
        name += rand() % 26 + 97;	//Ascii range for following lowercase letters
    }
  
  return name;
}

int main(){
	srand(static_cast<unsigned int>(time(0)));			//Random seed based on start time
	Bag *myBag = new Bag();								//Bag instance
	Generator use;										//Generator instance for adding students
	int num;
	string n1, n2, c, b, d, l, invalid;					//Variables to pass to student data
	char operation = ' ';								//User input variable for menu
	
	for(int i = 0; i < 100; i++){						//Creates 100 random students with all data filled
		myBag->addStudent(use.idGenerator(),use.nameGenerator(),use.nameGenerator(),\
		use.cityGenerator(),use.bdayGenerator(),use.depGenerator(),use.levelGenerator());
	}
	
	while(operation != 'e'){							//Condition to exit
		while(true){									//While loop to catch invalid inputs
			cout<<"(a)dd, (r)emove, (i)d search, (n)ame search, (l)ist by city,\n(p)rint count, (m)odify, (d)elete all, (c)ut last, or (e)xit: ";
			cin>>invalid;
			operation = invalid[0];						//Had an issue if more than one character is input in menu, this is solution
			if(operation == 'a' || 'd' || 'i' || 'n' || 'l' || 'p' || 'm' || 'd' || 'c' || 'e')
				break;									//Continue if valid input
		}
		switch(operation)								//Switch for menu operations which each call a corresponding bag function
		{
			case 'a':
				//cin >> num; 							//This can be exchanged with following line to test custom IDs
				num = use.idGenerator();
				n1 = use.nameGenerator();
				n2 = use.nameGenerator();
				c = use.cityGenerator();
				b = use.bdayGenerator();
				d = use.depGenerator();
				l = use.levelGenerator();
				
				if(myBag->idSearch(num)){				//Catch for duplicate IDs. It will not be needed due to the random seed, but I have tested it using custom IDs
					cout << "Student already exists.\n" << endl;
					break;
				}

				myBag->addStudent(num,n1,n2,c,b,d,l);	//Add random student to end of list
				
				cout << "Student added: " << num << " " << n2 << " " << n1 << " "\
				<< c << " " << b << " " << l << " " << d <<endl << endl;
				break;
			case 'r':									//Remove student by using ID
				cout<<"Enter ID to be deleted: ";
				cin>>num;
				cout<<endl;
				
				if(myBag->remove(num))
					cout<<"Student deleted"<<endl<<endl;
				else
					cout<<"Student not found"<<endl<<endl;
				break;
			case 'i':									//Search by ID
				cout<<"Enter ID to be searched: ";
				cin>>num;
				cout<<endl;
				
				if(myBag->idSearch(num))
					cout<<"Student found"<<endl<<endl;
				else
					cout<<"Student not found"<<endl<<endl;
				break;
			case 'n':									//Search by last name
				cout<<"Enter name to be searched: ";
				cin>>n1;
				cout<<endl;
				
				if(myBag->nameSearch(n1))
					cout<<"Student found"<<endl<<endl;
				else
					cout<<"Student not found"<<endl<<endl;
				break;
			case 'l':									//List names of students in given city
				cout<<"Enter city (Example: Commerce,TX): ";
				cin>>c;
				cout<<endl;
				
				myBag->listByCity(c);
				break;
			case 'p':									//Print count
				myBag->listBag();						//Uncomment lines 213-222 to print entire bag
				break;
			case 'm':									//Generate new student after entering ID
				cout<<"Enter ID to be edited: ";
				cin>>num;
				cout<<endl;
				
				myBag->modByID(num);
				break;
			case 'd':
				myBag->removeAll();						//Remove all data and nodes
				break;
			case 'c':
				myBag->removeLast();					//Remove last item in list
			default:
				break;
		}
	}
	
	return 0;
}