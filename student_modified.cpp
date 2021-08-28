#include<iostream>
#include<cstring>
using namespace std;

//course variable structure

struct course{
    string course_name;
    string instructor_name;
    int credit_hour;
    float assesment, finalResult;

};

//student variable structure
struct student{

string studentname;
string id_no;
char sex;
char grade;
course c;




//functions
void getinfo();
void menu();
char calcgrade(float , float);
void displayStudent();

};

//functions to work on the operations and menu

int menu(); //for the menu


/*

	functions to work with when file is added
	
	*/

void student::getinfo()
{
			int size, size2; // size of the array of sturtures yemiyez varibales
          cout<<"\t\tWelcome to the Registration page\n";
		  cout<<"\n\n";
	      cout<<"->Enter student ID: ";
          cin>>id_no;
          cout<<endl;
          cout<<"->Enter the student name: ";
          cin.ignore();
          getline(cin, studentname);
          cout<<endl;
          cout<<"->Enter Gender of student (M/F): ";
          cin>>sex;
          cout<<endl;
          cout <<"Enter the numbe of courses the students take: ";
          cin>>size;
          
          //making loops for the courses
          course c[size];
          
          for(int i=0;i<size;i++)
          {
          cout<<"->Enter the course name of: " << i+1;
          cin.ignore();
          getline(cin, c[i].course_name);
          cout<<endl;
          cout<<"->Enter the credit hours: ";
          cin>>c[i].credit_hour;
          cout<<endl;
          cout<<"->Enter the assessment result: ";
          cin>>c[i].assesment;
          cout<<endl;
          cout<<"->Enter the Final result: ";
          cin>>c[i].finalResult;
		  }
          
        //  grade = calcgrade(assesment, finalResult);
        //  cout<<endl;

}


void student::displayStudent()
{
//make the function work with loops to display the students 
	course c[2];
    cout<<"ID" <<"\t" << "Student Name " <<"\t" <<"Gender" <<"\t"<< "Course Name" <<"\t" << "Credit hour" <<"\t"<< "Grade"<<endl;
    cout<<id_no<<"\t"<<studentname <<"\t\t" <<sex<<"\t" <<c[1].course_name<<"\t\t" <<c[1].credit_hour<<"\t\t"<< grade << endl;
}

char student::calcgrade(float a, float b)
{
    int total = a + b;

    if( total>80 && total <=100)
    {
        return 'A';
    }
    else if( total<60 && total >40)
    {
        return 'B';
    }
}
/*defining more functions here*/

int main(){

    student s;
    
    int a; // try
    string username;
    string password;
    cout<<"Enter username"<<endl;
    cin>>username;
    cout<<"Enter a password"<<endl;
    cin>>password;
    if (username=="admin"){
        if (password=="admin"){

        int choice2 = menu();
            if(choice2 == 1)
            {
                s.getinfo();
                cout <<" Enter 1 to display: ";
                cin>>a;
                if(a==1)
                {
                    s.displayStudent();
                }
            }
        }
        else{
            cout<<"Incorrect password"<<endl;
        }}





}

int menu()
{

    int choice, id2;



    cout<<"\t\t  WELCOME\n";
    //one box
    cout << "\t\t\t" <<char(218);      for(int i=0; i<21; i++){cout << char(196);}      cout << char(191) << endl;
    cout << "\t\t\t" <<char(179) << " 1.To Add Student    " << char(179) << endl;
    cout << "\t\t\t" <<char(192);      for(int i=0; i<21; i++){cout << char(196);}      cout << char(217) << endl;
    cout<<"\n\t\tInput Here: " ;cin>>choice;

    return choice;
}

