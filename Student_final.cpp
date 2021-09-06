#include <iostream>
#include <String.h>
#include<windows.h>
#include<iomanip>

using namespace std;

/*declaring structures here*/

//course structure

struct course
{
	string course_name;
    string instructor_name;
    int credit_hour ;
    float assesment , finalResult;
    char grade;
    string passorfail;
};

//student structure

struct student
{
	string studentname;
	int id_no= 10;// auto-increament
    int rankk;
	char sex ;
	string gpa;
	int course_number;
	course *c = new course[100]; // pointer dynamic memory allocation minimum of ten
	char section;
	int student_amount;


	//functions here?


};

//struct to store password and user

struct loginAdmin{

    string user ="admin";
    string pass= "admin";

};

/*Functions declaration*/

/******MENU FUNCTIONS******/
char masterMenu();
char adminLogin();
char functionMenu();
char studentMenu(int);

/******OPERATION FUNCTIONS******/
int getinfo(int );
int display(int);
int searchStudent(int);
int deleteStudent(int);
char calcgrade(float, float);
int rankk(char);
int modify(int);
int sortt();

string passorfail(char);
string gpa(char);
void welcomeScreen();
void exiting();
void aboutUs();

void validate(int);
/*****OPERATION STUDENT FCUNTIONS*****/

int currentSemester(int);
int status(int);
int nextSem(int);
int contact(int);

/***global objects***/
int countt = 1;
student *s = new student[100];
student stud;
course c;
/********************/
/*main function*/
int main()
{

    system("COLOR 3F");
    if(countt == 1)
    {
        welcomeScreen();
    }

    //system("PAUSE");
    system("CLS");

    again: // for goto

    int Choice2 =  masterMenu();
    system("CLS");
    switch(Choice2)
    {
    case 1:
        {
            system("CLS");
            int success = adminLogin();
            if(success == 1)
            {
                system("CLS");
                system("COLOR 3F");
                //getting instructor name

                cout << "\t\t\t" <<char(218);      for(int i=0; i<30; i++){cout << char(196);}      cout << char(191) << endl;
                cout << "\t\t\t"<< "   Admin Name: "; cin.ignore();getline(cin,c.instructor_name);

                system("CLS");
                cout<<"\n\t\t\t WELCOME " <<c.instructor_name <<endl;
                cout<<endl;
                cout<<"\t->"; system("PAUSE");
                system("CLS");

                redo: // for the lable of goto

                int done = functionMenu();

                //getting information//
                if(done == 1)
                {
                    //local vairables
                    system("CLS");

                    cout << "\t\t" <<char(218);      for(int i=0; i<40; i++){cout << char(196);}      cout << char(191) << endl;
                    cout << "\t\t"<< "   Number of students to enter: "; cin>>stud.student_amount;

                    int hold = getinfo(stud.student_amount);

                    if(hold == 1)
                    {
                        goto redo;
                    }

                }
                //display students
                else if(done == 2)
                {
                    system("CLS");

                   int hold = display(stud.student_amount);

                if(hold== 1)
                    goto redo;
                }

                //search student
                else if(done == 3)
                {
                    system("CLS");
                    int id;
                    cout<<"\t->Enter Student ID: ";
                    cin>>id;

                    int hold = searchStudent(id);

                    if(hold == 1)
                    {

                        goto redo;
                    }
                }

                //Delete student
                else if(done == 4)
                {
                    system("CLS");
                    int id;
                    cout<<"\t->Enter Student ID: ";
                    cin>>id;

                    int hold = deleteStudent(id);
                    cout<<"\n\n\t\t-> ";system("PAUSE");
                    if(hold == 1)
                    {
                        system("CLS");
                        goto redo;
                    }
                }

                //sort student
                else if(done == 5)
                {
                  system("CLS");
                   int hold = sortt();
                   if(hold == 1)
                   {
                     system("CLS");
                     goto redo;}
                }
                //modify student
                else if(done == 6)
                {
                   system("CLS");
                   int id;
                   cout<<"\t->Enter Student ID: ";
                   cin>>id;

                   int hold = modify(id);
                   cout<<"\n\n\t\t-> ";system("PAUSE");
                   if(hold == 1)
                   {
                     system("CLS");
                     goto redo;}
                }
                //neither
                else if(done == 7)
                {
                    system("CLS");
                    goto again;

                }
                else
                {
                    exiting();
                }
            }

        }
        break;
    case 2:
        {
            system("CLS");
            int idNew;
            cout << "\t\t\t" <<char(218);      for(int i=0; i<30; i++){cout << char(196);}      cout << char(191) << endl;

            cout << "\t\t\t"<< "   Enter your ID: "; cin>>idNew;

            redo2:

            int done2 = studentMenu(idNew);

            //student conditions from the menu

            //display his/her information
                if(done2 == 1)
                {
                    system("CLS");
                    int hold = status(idNew);

                    if(hold == 1)
                        goto redo2;
                }
            //display current semester grade
                else if(done2 == 2)
                {
                    system("CLS");
                    int hold = currentSemester(idNew);

                    if(hold == 1)
                        goto redo2;
                }

            //Next semester courses
                else if(done2 == 3)
                {
                    system("CLS");
                    int hold = nextSem(idNew);

                     if(hold == 1)
                        goto redo2;

                }

            //Contact teacher
                else if(done2 == 4)
                {
                    system("CLS");
                    int hold = contact(idNew);

                     if(hold == 1)
                        goto redo2;
                }
            //neither

                else if(done2 == 5)
                {
                    system("CLS");
                    countt+=1;
                    main();
                }

                else if(done2 == 6)
                {
                    exiting();
                }

                else if(done2 == 0)
                {
                    cout<<"\t\t\n\n -> NO SUCH STUDENT EXISTS IN DATABASE....\n\n";
                    cout<<"\t\t->";system("pause");
                    system("CLS");
                    countt+=1;//counting so it doesn't load the welcome animation everytime we go to menu
                    main();
                }
        }
        break;
    case 3:
        {
           aboutUs();
           cout<<"\t\t\t->";system("pause");
           system("CLS");
           countt+=1;
           main();
        }
        break;
    case 4:
        {
            exiting();// calling the exiting function when logging out

        }
    }

    delete(s->c);  // deallocate them
    delete(s);

	return 0;
}

/******DEFINING THE FUNCTIONS******/

/**master Menu and Other Menu Functions**/

char masterMenu()
{
    int choice;//variable to store the choice
    system("COLOR 3F");

    //welcome sign
    cout<<endl;

    cout <<"\t\t\t\t       MAIN MENU \n\n";
    //one box
    cout << "\t\t\t\t\t" <<char(218);      for(int i=0; i<21; i++){cout << char(196);}      cout << char(191) << endl;
    cout << "\t\t\t\t\t" <<char(179) << " 1.Login as Admin    " << char(179) << endl;
    cout << "\t\t\t\t\t" <<char(192);      for(int i=0; i<21; i++){cout << char(196);}      cout << char(217) << endl;
    cout<<endl;
    cout<<endl;
    //one box
    cout << "\t\t\t\t" << char(218);      for(int i=0; i<21; i++){cout << char(196);}      cout << char(191) << endl;
    cout << "\t\t\t\t" << char(179) << " 2.Login as Student  " << char(179) << endl;
    cout << "\t\t\t\t" << char(192);      for(int i=0; i<21; i++){cout << char(196);}      cout << char(217) << endl;


    //one box
    cout<<endl;
    cout<<endl;
    cout << "\t\t\t\t\t" << char(218);      for(int i=0; i<21; i++){cout << char(196);}      cout << char(191) << endl;
    cout << "\t\t\t\t\t" << char(179) << "      3.About US     " << char(179) << endl;
    cout << "\t\t\t\t\t" << char(192);      for(int i=0; i<21; i++){cout << char(196);}      cout << char(217) << endl;
    cout<<endl;
    cout<<endl;
    cout << "\t\t\t\t\t\t" << char(218);      for(int i=0; i<21; i++){cout << char(196);}      cout << char(191) << endl;
    cout << "\t\t\t\t\t\t" << char(179) << "      4.To Exit      " << char(179) << endl;
    cout << "\t\t\t\t\t\t" << char(192);      for(int i=0; i<21; i++){cout << char(196);}      cout << char(217) << endl;
    cout<<endl;
    cout<<endl;
    cout<<"\n\t\t\t\t->Input Here: " ;cin>>choice;

    countt+=1; //counting so it doesn't load the welcome animation everytime we go to menu
    return choice;

}

/**Admin login**/

char adminLogin()
{
    system("color 9F");
    string U;
    string P;

    loginAdmin l; //login struct object
    loginAdmin *L = &l ;
    cout<<endl;
	cout << "\t\t" << char(218);      for(int i=0; i<39; i++){cout << char(196);}      cout << char(191) << endl;
    cout << "\t\t" << char(179) << " \t        ADMIN LOGIN PAGE        " << char(179) << endl;
    cout << "\t\t" << char(179) << "                     \t\t\t" << char(179) << endl;
    cout << "\t\t" << char(179) << "  Enter UserName:  "; cin>> U; cout<<"\t\t"<< char(179);
    cout<<"\t\t\t\t\t"<< char(179) << endl;
    cout << "\t\t" << char(179) << "  PASSWORD: "; cin>>P; cout << "\t\t" << char(179);
    cout<<"\t\t\t\t\t"<< char(179) << endl;
    cout << "\t\t" << char(179) << "                 \t\t\t" << char(179) << endl;
    cout << "\t\t" << char(192);      for(int i=0; i<39; i++){cout << char(196);}      cout << char(217) << endl;

    //if statement to check

    if(U== L->user && P == L->pass)
    {
        return 1;// for sucess
    }
    else
    {

        cout <<"\t\t->LOGIN FAILED\n\n";
        cout<<"\t\t";system("pause");
        system("CLS");
        countt+=1; //counting so it doesn't load the welcome animation everytime we go to menu
        main(); // calling back to the main function
    }

}

/**Admin Function Menu**/

char functionMenu()
{
    int choice;
    system("COLOR 3F");
    cout << "\t"<< char(201);      for(int i=0; i<60; i++){cout << char(205);}      cout << char(187) << endl;
	cout << "\t"<< char(186) << "                       \t\t\t\t     " << char(186) << endl;
	cout << "\t"<< char(186) << " \t\t Functions menu                     \t     " << char(186) << endl;
	cout << "\t"<< char(186) << " \t\t\t\t\t\t\t     " << char(186) << endl;
	cout << "\t"<< char(186) << "   \t\t 1.To Insert  Record              \t     " << char(186) << endl;
	cout << "\t"<< char(186) << "   \t\t 2.To Display Record               \t     " << char(186) << endl;
	cout << "\t"<< char(186) << "   \t\t 3.To Search  Record           \t             " << char(186) << endl;
	cout << "\t"<< char(186) << "   \t\t 4.To Delete  Record            \t     " << char(186) << endl;
	cout << "\t"<< char(186) << "   \t\t 5.To Sort  Record(by Rank)     \t     " << char(186) << endl;
	cout << "\t"<< char(186) << "   \t\t 6.To Modify  Record            \t     " << char(186) << endl;
	cout << "\t"<< char(186) << "   \t\t 7.MAIN MENU            \t\t     " << char(186) << endl;
	cout << "\t"<< char(186) << "   \t\t 8.To EXIT            \t\t\t     " << char(186) << endl;
	cout << "\t"<< char(186) << "                    \t\t\t\t\t     " << char(186)<<endl;
	cout << "\t"<< "   \t\t\t ->Input Here: ";cin>>choice;
    validate(choice);

	return choice;

}

/**student menu**/

char studentMenu(int idnumber)
{
    system("CLS");

    bool success = false;
    for(int i =0; i < stud.student_amount;i++)
    {
        if(s[i].id_no == idnumber)
    {

    int choice;
	cout << "\t" << char(201);      for(int i=0; i<60; i++){cout << char(205);}      cout << char(187) << endl;
	cout << "\t"<< char(186) << "                       \t\t\t\t     " << char(186) << endl;
	cout << "\t"<< char(186) << " \t\t FUNCTION MENU                    \t     " << char(186) << endl;
	cout << "\t"<< char(186) << " \t\t\t\t\t\t\t     " << char(186) << endl;
	cout << "\t"<< char(186) << "   \t\t 1.To Display your status                    " << char(186) << endl;
	cout << "\t"<< char(186) << "   \t\t 2.Current Semester Grade                    " << char(186) << endl;
	cout << "\t"<< char(186) << "   \t\t 3.Next Semester Courses                     " << char(186) << endl;
	cout << "\t"<< char(186) << "   \t\t 4.Contact your teacher                      " << char(186) << endl;
	cout << "\t"<< char(186) << "   \t\t 5.MAIN MENU            \t\t     " << char(186) << endl;
	cout << "\t"<< char(186) << "   \t\t 6.TO EXIT           \t\t\t     " << char(186) << endl;
	cout << "\t"<< char(186) << "                    \t\t\t\t\t     " << char(186) << endl;
	cout << "\t"<< char(186) << "   \t\t\t ->Input Here: ";cin>>choice;
	validate(choice);

    success = true;
	return choice;
    }
    success = true;

    }

    if (success == false)  // to know if the login was successfull or not
    {
        return 0;

    }

}

/******Get info function******/

int getinfo(int sizee)
{

    system("CLS");
    system("COLOR 3E");

    cout << "\t\t" << char(218);      for(int i=0; i<39; i++){cout << char(196);}      cout << char(191) << endl;
    cout << "\t\t" << char(179) << " \t        WELCOME                 " << char(179) << endl;
    cout << "\t\t" << char(179) << "                      \t\t\t" << char(179) << endl;

    for(int i=0; i<sizee; i++)
    {
        s[i].id_no +=i;

        cout << "\t\t" << char(218);      for(int x=0; x<39; x++){cout << char(196);}      cout << char(191) << endl;
        cout << "\t\t" << char(179) << " \tSTUDENT: " << i+1 << "\t\t        "<< char(179) ; cout<<endl;
        cout << "\t\t" << char(192);      for(int i=0; i<39; i++){cout << char(196);}      cout << char(217) << endl;
        cout<<endl;
        cout << "\t\t"<< "  Student ID:  ";cout << s[i].id_no ;
        cout<<endl;
        cout<<endl;
        cout << "\t\t"  << "  Enter the student name: ";cin.ignore(); getline(cin,s[i].studentname);
        cout<<"\t\t\t" << endl;
        cout << "\t\t" << "  Enter Gender of student (M/F): ";cin>>s[i].sex;
        cout<<"\t\t\t" << endl;
        cout << "\t\t" << "  Enter SECTION: ";cin>>s[i].section;
        cout<<"\t\t\t" << endl;
        cout << "\t\t" << "  Enter Number of Courses: ";cin>>s[i].course_number;
        cout<<"\t\t\t" << endl;

        // creating the course object with array of structure
        for(int j=0;j<s[i].course_number; j++ )
        {
            system("CLS");
            cout << "\t\t" << char(218);      for(int x=0; x<39; x++){cout << char(196);}      cout << char(191) << endl;
            cout << "\t\t" << " \tCOURSE: " << j+1 << "\t\t        ";cout<<endl;
            cout << "\t\t" << char(192);      for(int x=0; x<39; x++){cout << char(196);}      cout << char(217) << endl;
            cout << "\t\t" <<"  Enter Course Name:  ";cin.ignore(); getline(cin,s[i].c[j].course_name);
            cout<<"\t\t\t"<< endl;
            cout << "\t\t" << "  Enter credit Hour: ";cin>>s[i].c[j].credit_hour;
            cout<<"\t\t\t" << endl;
            cout << "\t\t" <<"  Enter the assessment result: ";cin>> s[i].c[j].assesment; cout<<endl;
            cout << "\t\t" << "  Enter the Final Result: ";cin>>s[i].c[j].finalResult;
            cout<<"\t\t\t" << endl;
            system("CLS");

            s[i].c[j].grade = calcgrade(s[i].c[j].assesment, s[i].c[j].finalResult); //Grade
            s[i].c[j].passorfail = passorfail(s[i].c[j].grade); //passorfail
            s[i].rankk = rankk(s[i].c[j].grade); //rank of student
            s[i].gpa = gpa(s[i].c[j].grade); //actual gpa

        }
        stud.id_no++;
    }
    return 1;
}

/*** display students***/

int display(int sizee)
{

    system("CLS");

	cout<<"\t" << char(201);      for(int x=0; x<70; x++){cout << char(205);}      cout << char(187) << endl;
    cout<<"\t" << "  ID "<< "\t" <<" Student Name" <<"\t   "<< "   Cumulative Grade" <<"\t "  << " Rank "<<"     " <<" SECTION " << endl;
    cout << "\n\t" << char(200);      for(int x=0; x<70; x++){cout << char(205);}      cout << char(188) << endl;

	for(int i=0;i<sizee;i++)
	{
		 cout <<"\t" << setw(5)<<s[i].id_no<<"\t " << setw(15)<<s[i].studentname <<"             "<< setw(3)<<s[i].gpa <<"       " << setw(5)<<" " <<s[i].rankk <<setw(2)<<"          " << s[i].section<<"   " << endl;
	}

	cout<<"\n\t\t-> ";system("PAUSE");
	system("CLS");
	return 1;

}
/****calculate grade*****/

char calcgrade(float first, float second)
{
    int total = first  + second;



    if( total>=85 && total <=100)
    {
        return 'A';
    }
    else if( total<70 && total >60)
    {
        return 'B';
    }

    else if( total <=50 && total >=40)
    {
        return 'C';
    }

    else{

        return 'F';
    }
}
/**Calculate rank based on a grade****/
int rankk(char grade)
{
    if(grade == 'A')
        return 1;
    else if(grade == 'B')
        return 2;
    else if(grade == 'C')
        return 3;
    else if(grade =='D')
        return 4;
    else
    {
        return 5;
    }

}
/**pass or fail**/

string passorfail(char a)
{

    if(a == 'B' || a =='A')
    {
        return "PASS";
    }

    else if( a=='C' || a=='D')
    {
        return "WARN";
    }

        else if( a=='F')
    {
        return "DISMISS";
    }
}


string gpa(char grade)
{
    if(grade == 'A')
        return "4";
    else if(grade =='B')
        return "3";
    else if(grade == 'C')
        return "2";
    else if (grade == 'D')
        return "1";
    else if(grade == 'F')
        return "NULL";

}
/**Search student that takes id number as a parameter and returns after completion**/

int searchStudent(int idNew)
{
    system("CLS");
    bool success = false;
    for(int i =0; i< stud.student_amount; i++)
    {
        if(s[i].id_no == idNew)

    {

    int choice;
    cout << "\t" << char(201);      for(int x=0; x<60; x++){cout << char(205);}      cout << char(187) << endl;
	cout << "\t"<< char(186) << "                       \t\t\t\t     " << char(186) << endl;
	cout << "\t"<< char(186) << " \t\t FUNCTION MENU                    \t     " << char(186) << endl;
	cout << "\t"<< char(186) << " \t\t\t\t\t\t\t     " << char(186) << endl;
	cout << "\t"<< char(186) << "   \t\t 1.To Display Current Status                 " << char(186) << endl;
	cout << "\t"<< char(186) << "   \t\t 2.Overall Information                       " << char(186) << endl;
    cout<<endl;
	cout << "\t" << "   \t\t\t ->Input Here: ";cin>>choice;

	if(choice == 1)
    {
        currentSemester(idNew);
        return 1;
    }

    else if(choice == 2 )
    {
        status(idNew);
        return 1;
    }

    else{
        cout<<"Invalid Input\n";
        cout<<"\n\t\t->";system("pause");
        countt+=1;
        main();
    }
        success = true;
    }

    }

    if (success == false)
    {
        cout<<"\t\t\n\n -> NO SUCH STUDENT EXISTS IN DATABASE....\n\n";
        cout<<"\t\t->";system("pause");
        system("CLS");

        return 1;
    }

}


int deleteStudent(int idnumber)
{

    bool found = false;
    for(int i=0;i<stud.student_amount;i++)
    {
        if(s[i].id_no == idnumber)
        {
            for(int j=i ; j< (stud.student_amount-1) ;j++)
            {
                s[j].id_no = s[j+1].id_no;
                s[j].studentname = s[j+1].studentname;
                s[j].section = s[j+1].section;
                s[j].rankk = s[j+1].rankk;
            }
            stud.student_amount--;
            i--;
            found = true;
        }
    }

    if(found == false)
        {
            cout<<"\n\t\t->NO STUDENT FOUND\n";
        }
    else if(found == true)
    {
            cout <<"\n\t\t-> SUCCESSFULLY DELETED\n";
    }

    return 1;
}

/** modify student***/

int modify(int idNew)
{
    bool success= false;
    for(int i=0; i<stud.student_amount;i++)
    {
        if(idNew == s[i].id_no)
        {
            getinfo(1);
            success = true;
            return 1;
        }
    }

    if(success == false)
    {
        cout <<"\n\t\t" <<" NO STUDENT FOUND \n ";
        return 1;
    }

}

/**sort by rank**/

int sortt()
{
    student* temp = new student[20];
    //using bubble sort algorithm
    for(int i=0;i <stud.student_amount;i++)
    {
        for(int j =i+1; j< stud.student_amount;j++)
        {
            if(s[i].rankk >= s[j].rankk)
            {
                temp[i].studentname = s[i].studentname;
                temp[i].section= s[i].section;
                temp[i].rankk = s[i].rankk;
                temp[i].id_no= s[i].id_no;

                s[i].studentname = s[j].studentname;
                s[i].section = s[j].section;
                s[i].rankk = s[j].rankk;
                s[i].id_no = s[j].id_no;

                s[j].studentname = temp[i].studentname;
                s[j].section = temp[i].section;
                s[j].rankk = temp[i].rankk;
                s[j].id_no = temp[i].id_no;

            }
        }

    }

    display(stud.student_amount);
    delete(temp);
    return 1;
}

/****Operations for student page***/

int currentSemester(int idnumber)
{

    system("CLS");
    system("COLOR 4E");

    cout << "\t\t" << char(218);      for(int x=0; x<39; x++){cout << char(196);}      cout << char(191) << endl;
    cout << "\t\t" << char(179) << " \t        WELCOME                 " << char(179) << endl;
    cout << "\t\t" << char(179) << "                      \t\t\t" << char(179) << endl;
    for(int i=0;i<stud.student_amount;i++)
    {
        if(s[i].id_no == idnumber)
        {
                cout << "\t\t"  << " \tSTUDENT: "; cout <<s[i].studentname << "\t        " << endl; cout<<endl;
                cout << "\t\t" << char(192);      for(int x=0; x<39; x++){cout << char(196);}      cout << char(217) << endl;
                cout<<endl;
                cout << "    "<< char(201);      for(int i=0; i<63; i++){cout << char(205);}      cout << char(187) << endl;
                cout<<"\t"<<" Course Name" <<"\t\t" <<"Credit hours" <<"\t"<< " Grade " <<"\t" << "    STATUS" << endl;
                cout << "    "<< char(200);      for(int x=0; x<63; x++){cout << char(205);}      cout << char(188) << endl;
                for(int j=0;j<s[i].course_number;j++)
                {
                    cout << "   "<< setw(13)<<s[i].c[j].course_name <<"\t"<< setw(15) << s[i].c[j].credit_hour << "\t" << setw(12) << s[i].c[j].grade << "\t" << setw(13) << s[i].c[j].passorfail ; cout <<"" << endl;

                }

        }
    }
	cout<<"\n\t\t->";system("pause");
	system("CLS");
	return 1;
}

/***Over all status function takes idnumber as parameter***/

int  status(int idnumber)
{
    system("CLS");
    system("COLOR 4E");
    cout << "\t\t" << char(218);      for(int x=0; x<39; x++){cout << char(196);}      cout << char(191) << endl;
    cout << "\t\t" << char(179) << " \t        WELCOME                 " << char(179) << endl;
    cout << "\t\t" << char(179) << "                      \t\t\t" << char(179) << endl;

    for(int i=0;i < stud.student_amount; i++)
    {
        if(s[i].id_no ==  idnumber)
        {

                cout << "\t\t" << " \tSTUDENT: " <<s[i].studentname << "\t        "  << endl; cout<<endl;
                cout << "\t\t" << char(192);      for(int x=0; x<39; x++){cout << char(196);}      cout << char(217) << endl;
                cout<<endl;
                cout << "\t"<< char(201);      for(int i=0; i<70; i++){cout << char(205);}      cout << char(187) << endl;
                cout<<"\t"<<" Roll Number" <<"\t\t" <<" Current Grade" <<"\t   "<< "   Cumulative Grade" <<"\t" << " Rank " << endl;
                cout<<endl;
                cout << "\t"<< char(200);      for(int x=0; x<70; x++){cout << char(205);}      cout << char(188) << endl;
                cout << "\t" <<"   " << i+1<<"\t\t\t      " << setw(5)<< s[i].gpa << "\t\t" << setw(3)<<s[i].gpa << "\t\t" <<setw(3)<< s[i].rankk;
        }
    }
    cout<<"\n\t\t->";system("pause");
	system("CLS");
	return 1;
}
/**NEXT semester courses for a student feature**/

int nextSem(int idnumber)
{

    system("CLS");
    system("COLOR 4E");

    for(int i=0; i<stud.student_amount;i++)
    {
        if(s[i].id_no == idnumber)
        {
            cout << "\t\t" << char(218);      for(int x=0; x<39; x++){cout << char(196);}      cout << char(191) << endl;
            cout << "\t\t" << char(179) << " \t        WELCOME                 " << char(179) << endl;
            cout << "\t\t" << char(179) << "                      \t\t\t" << char(179) << endl;
            cout << "\t\t" << " \tSTUDENT: "  <<s[i].studentname << "\t        "  << endl; cout<<endl;
            cout << "\t\t" << char(192);      for(int x=0; x<39; x++){cout << char(196);}      cout << char(217) << endl;
            cout<<endl;

            cout << "\t\t"<< char(201);      for(int x=0; x<40; x++){cout << char(205);}      cout << char(187) << endl;
            cout<<"\t\t\t----NO INFORMATION-----\n";
            cout << "\t\t"<< char(200);      for(int x=0; x<40; x++){cout << char(205);}      cout << char(188) << endl;
        }
    }

	cout<<"\t\t\n->";system("pause");
	system("CLS");
	return 1;

}
/***Contact the office for any complaints***/

int contact(int idnumber)
{

    system("COLOR 4E");

    for(int i=0;i<stud.student_amount;i++)
    {

        if(s[i].id_no== idnumber)
        {
            cout << "\t\t" << char(218);      for(int x=0; x<39; x++){cout << char(196);}      cout << char(191) << endl;
            cout << "\t\t" << char(179) << " \t        WELCOME                 " << char(179) << endl;
            cout << "\t\t" << char(179) << "                      \t\t\t" << char(179) << endl;
            cout << "\t\t" << " \tSTUDENT: " << s[i].studentname << "\t        " << endl; cout<<endl;
            cout << "\t\t" << char(192);      for(int x=0; x<39; x++){cout << char(196);}      cout << char(217) << endl;
            cout<<endl;

            cout << "\t\t"<< char(201);      for(int x=0; x<40; x++){cout << char(205);}      cout << char(187) << endl;
            cout<<"\t\t\t--Contact Information--\n\n";
            cout<<"\t\t"<< "\tInstructor Name: " << c.instructor_name <<"     "<<endl;
            cout<<endl;
            cout<<"\t\t"<< "\tPhone Number: " << " +(251)9-154-7845 " <<" "<<endl;
            cout << "\t\t"<< char(200);      for(int x=0; x<40; x++){cout << char(205);}      cout << char(188) << endl;

        }
    }


	cout<<"\n\t\t->";system("pause");
	system("CLS");
	return 1;

}

/**Welcome Screen Animation**/

void welcomeScreen()
{

    cout << "\n\n\n";
    Sleep(150);
    cout << "\t\t\t\t * * *  **** *      ****  ***   ***   ****   " << endl;
    Sleep(150);
    cout << "\t\t\t\t * * * *     *     *     *   * * * * *        "<< endl;
    Sleep(150);
    cout << "\t\t\t\t * * * ***** *     *     *   * * * * *****    " << endl;
    Sleep(150);
    cout << "\t\t\t\t * * * *     *     *     *   * * * * *         " << endl;
    Sleep(150);
    cout << "\t\t\t\t  ***   **** *****  ****  ***  * * *  ****     " << endl;
    Sleep(150);
    cout<<endl;
    cout<<"\t\t\t\t============================================="<<endl;
    Sleep(150);
    cout<<"\t\t\t\t\tSTUDENT MANEGEMENT SYSTEM  "<<endl;
    Sleep(150);
    cout<<"\t\t\t\t============================================="<<endl;
    Sleep(150);
    cout<<endl;
    cout<<"\a";
    cout<<"\t\t\t\t\t->";system("pause");

}
/**EXITING Animation Function using built in function Sleep()**/
void exiting()
{
    cout<<"\n";
    cout<<"\t\t->EXITING";
    Sleep(200);cout<<".";Sleep(200);cout<<".";Sleep(200);cout<<".";Sleep(200);cout<<".";Sleep(200);cout<<".";cout<<"\a";
}

/**About Us**/

void aboutUs()
{

    cout << "\t" << char(201);      for(int i=0; i<60; i++){cout << char(205);}      cout << char(187) << endl;
	cout << "\t"<< char(186) << "                       \t\t\t\t     " << char(186) << endl;
	cout << "\t"<< char(186) << " \t\t GROUP MEMBERS                     ID        " << char(186) << endl;
	cout << "\t"<< char(186) << " \t\t\t\t\t\t\t     " << char(186) << endl;
	cout << "\t"<< char(186) << "   \t 1.EYUEL KETEMA                  \t0280/12      " << char(186) << endl;
	Sleep(200);
	cout << "\t"<< char(186) << "   \t 2.ERMIAS SIRAYE                  \t0253/12      " << char(186) << endl;
	Sleep(200);
	cout << "\t"<< char(186) << "   \t 3.ERMIAS TIRUNEH                 \t0251/12      " << char(186) << endl;
	Sleep(200);
	cout << "\t"<< char(186) << "   \t 4.MINTESNOT MARKOS               \t1025/12      " << char(186) << endl;
	Sleep(150);
	cout << "\t"<< char(186) << "   \t 5.ESTIFANOS GASHEWTENA           \t0260/12      " << char(186) << endl;
	Sleep(150);
	cout << "\t"<< char(186) << "                    \t\t\t\t\t     " << char(186) << endl;
	cout << "\t"<< char(200);      for(int x=0; x<60; x++){cout << char(205);}      cout << char(188) << endl;

}
/**Validate the input**/

void validate(int choice)
{
    while(!cin.good())
    {
        cin.clear();
    }
}
                            /********* PHASE 1 COMPLETED**********/
