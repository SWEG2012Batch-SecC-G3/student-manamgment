//*->C++ PROJECT ON STUDENT MANAGEMENT

#include <iostream>
#include <String.h>
#include<windows.h>

using namespace std;

//ANOTHER BASE CODE TO WORK ON//

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
	int id_no = 1234 ;

	char sex ;
	int course_number;
	int course_amount;
	course c[100];
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

/******OPERATION ADMIN FUNCTIONS******/
int integer_validation();
void freeUpMain();
int getinfo(int );
int display(int);
int searchStudent(int);
void deleteStudent(int);
char calcgrade(float, float);
int modify(int);
string passorfail(char);
void welcomeScreen();
void exiting();
/*****OPERATION STUDENT FCUNTIONS*****/

int currentSemester(int);
int status(int);
int nextSem(int);
int contact(int);

/*main function*/

student s[100];
student stud;
course c;
int main()
{
    system("COLOR 3F");
    welcomeScreen();
    //system("PAUSE");
    freeUpMain();

	return 0;
}


/*defining functions*/

//master menu and other menus//

char masterMenu()
{
    int choice;//variable to store the choice
    system("COLOR 3F");

    //welcome sign
    cout<<endl;

    cout <<"\t\t         WELCOME       \n\n";
    //one box
    cout << "\t\t\t" <<char(218);      for(int i=0; i<21; i++){cout << char(196);}      cout << char(191) << endl;
    cout << "\t\t\t" <<char(179) << " 1.Login as Admin    " << char(179) << endl;
    cout << "\t\t\t" <<char(192);      for(int i=0; i<21; i++){cout << char(196);}      cout << char(217) << endl;
    cout<<endl;
    cout<<endl;
    //one box
    cout << char(218);      for(int i=0; i<21; i++){cout << char(196);}      cout << char(191) << endl;
    cout << char(179) << " 2.Login as Student  " << char(179) << endl;
    cout << char(192);      for(int i=0; i<21; i++){cout << char(196);}      cout << char(217) << endl;
    cout<<endl;
    cout<<endl;
    //one boc
    cout << "\t\t\t" << char(218);      for(int i=0; i<21; i++){cout << char(196);}      cout << char(191) << endl;
    cout << "\t\t\t" << char(179) << "      3.To EXIT      " << char(179) << endl;
    cout << "\t\t\t" << char(192);      for(int i=0; i<21; i++){cout << char(196);}      cout << char(217) << endl;
    cout<<endl;
    cout<<endl;
    cout<<  "\n \t\t->Input Here: " ;//////////////////////////////////
    choice=integer_validation();

    return choice;

}

//admin login

char adminLogin()
{
    system("color 9F");
    string U;
    string P;
    student s;//student object
    loginAdmin L; //login struct object
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

    if(U== L.user && P == L.pass)
    {
        return 1;// for sucess
    }
    else
    {

        cout <<"\t\t->LOGIN FAILED\n\n";
        cout<<"\t\t";system("pause");
        system("CLS");
        main(); // calling back to the main function
    }


}

//admin function menu

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
	cout << "\t"<< char(186) << "   \t\t 4.To Modify  Record            \t     " << char(186) << endl;
	cout << "\t"<< char(186) << "   \t\t 5.To Delete  Record             \t     " << char(186) << endl;
	cout << "\t"<< char(186) << "   \t\t 6.MAIN MENU            \t\t     " << char(186) << endl;
	cout << "\t"<< char(186) << "   \t\t 7.To EXIT            \t\t\t     " << char(186) << endl;
	cout << "\t"<< char(186) << "                    \t\t\t\t\t     " << char(186)<<endl;
	cout << "\t"<< "   \t\t\t ->Input Here: ";cin>>choice;


	return choice;

}


//student menu//

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

    success = true;
	return choice;
    }
    success = true;

    }

    if (success = false)
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
        s[i].id_no == stud.id_no;

        cout << "\t\t" << char(218);      for(int x=0; x<39; x++){cout << char(196);}      cout << char(191) << endl;
        cout << "\t\t" << char(179) << " \tSTUDENT: " << i+1 << "\t\t        " << char(179) << endl; cout<<endl;
        cout << "\t\t" << char(179) << "  Student ID:  ";cout << s[i].id_no; cout<<"\t\t\t"<< char(179);
        cout<<endl;
        cout<<endl;
        cout << "\t\t" << char(179) << "  Enter the student name: ";cin.ignore(); getline(cin,s[i].studentname);  cout << "\t\t" << char(179);
        cout<<"\t\t\t\t\t"<< char(179) << endl;
        cout << "\t\t" << char(179) << "  Enter Gender of student (M/F): ";cin>>s[i].sex; cout << "\t\t" << char(179);
        cout<<"\t\t\t\t\t"<< char(179) << endl;
        cout << "\t\t" << char(179) << "  Enter SECTION: ";cin>>s[i].section; cout << "\t\t" << char(179);
        cout<<"\t\t\t\t\t"<< char(179) << endl;
        cout << "\t\t" << char(179) << "  Enter Number of Courses: ";cin>>s[i].course_number; cout << "\t\t" << char(179);
        cout<<"\t\t\t\t\t"<< char(179) << endl;

        // creating the course object with array of structure
        for(int j=0;j<s[i].course_number; j++ )
        {
            system("CLS");
            cout << "\t\t" << char(218);      for(int x=0; x<39; x++){cout << char(196);}      cout << char(191) << endl;
            cout << "\t\t" << char(179) << " \tCOURSE: " << j+1 << "\t\t        " << char(179) << endl; cout<<endl;
            cout << "\t\t" << char(179) << "  Enter Course Name:  ";cin.ignore(); getline(cin,s[i].c[j].course_name); cout<<"\t\t"<< char(179);
            cout<<"\t\t\t\t\t"<< char(179) << endl;
            cout << "\t\t" << char(179) << "  Enter credit Hour: ";cin>>s[i].c[j].credit_hour;  cout << "\t\t" << char(179);
            cout<<"\t\t\t\t\t"<< char(179) << endl;
            cout << "\t\t" << char(179) << "  Enter the assessment result: ";cin>> s[i].c[j].assesment; cout<<"\t\t"<< char(179);
            cout<<"\t\t\t\t\t"<< char(179) << endl;
            cout << "\t\t" << char(179) << "  Enter the Final Result: ";cin>>s[i].c[j].finalResult;  cout << "\t\t" << char(179);
            cout<<"\t\t\t\t\t"<< char(179) << endl;
            system("CLS");

            s[i].c[j].grade = calcgrade(s[i].c[j].assesment, s[i].c[j].finalResult); //gpa
            s[i].c[j].passorfail = passorfail(s[i].c[j].grade);

        }
    }



}

/*** display students***/

int display(int sizee)
{

    system("CLS");

	cout<<"\t" << char(201);      for(int x=0; x<70; x++){cout << char(205);}      cout << char(187) << endl;
    cout<<"\t"<<"  ID " <<"\t" <<" Student Name" <<"\t   "<< "   Cumulative Grade" <<"\t" << " Rank "<<"     " << " SECTION " << endl;
    cout<<endl;

	for(int i=0;i<sizee;i++)
	{
		cout << "\t"<< char(186); cout <<" " << s[i].id_no<<"\t " << s[i].studentname << "\t\t   " << " 3.9 " <<"\t " <<" 1 " <<"\t\t" << s[i].section<<"      "<< char(186) << endl;
	}
	cout << "\n\t" << char(200);      for(int x=0; x<70; x++){cout << char(205);}      cout << char(188) << endl;

    cout<<endl;
	cout<<"\t-> ";system("PAUSE");
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
        system("PAUSE");
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


void deleteStudent()
{

    /*code here*/
}

/** modify student***/


int modify(int idNew)
{
    student s;
    if(idNew == s.id_no)
    {
        cout << "\t" << char(201);      for(int x=0; x<60; x++){cout << char(205);}      cout << char(187) << endl;
        cout << "\t"<< char(186) << "                       \t\t\t\t     " << char(186) << endl;
        cout << "\t"<< char(186) << " \t\t   Enter New Data                \t     " << char(186) << endl;

    }

    else
    {

    }

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
                cout << "\t\t" << char(179) << " \tSTUDENT: "; cout <<s[i].studentname << "\t        " << char(179) << endl; cout<<endl;
                cout << "\t\t" << char(192);      for(int x=0; x<39; x++){cout << char(196);}      cout << char(217) << endl;
                cout<<endl;
                cout << "\t" << char(218);      for(int x=0; x<60; x++){cout << char(196);}      cout << char(191) << endl;
                cout<<"\t"<<" Course Name" <<"\t\t" <<"Credit hours" <<"\t"<< "Grade" <<"\t" << "    STATUS" << endl;
                cout << "\t"<< char(201);      for(int i=0; i<60; i++){cout << char(205);}      cout << char(187) << endl;

                for(int j=0;j<s[i].course_number;j++)
                {
                    cout << "\t"<< char(186); cout <<"   " << s[i].c[j].course_name<< " "<<"\t\t    " << s[i].c[j].credit_hour << "\t\t" << s[i].c[j].grade << "\t  " << s[i].c[j].passorfail ; cout <<"" <<char(186) << endl;

                }

                cout <<" " <<char(186) << endl;
                cout << "\t"<< char(200);      for(int x=0; x<60; x++){cout << char(205);}      cout << char(188) << endl;
        }
    }


	system("PAUSE");
	system("CLS");
	return 1;


}

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
                cout<<s[i].course_amount<<endl;
                cout << "\t\t" << char(179) << " \tSTUDENT: " <<s[i].studentname << "\t        " << char(179) << endl; cout<<endl;
                cout << "\t\t" << char(192);      for(int x=0; x<39; x++){cout << char(196);}      cout << char(217) << endl;
                cout<<endl;
                cout << "\t" << char(218);      for(int x=0; x<70; x++){cout << char(196);}      cout << char(191) << endl;
                cout<<"\t"<<" Roll Number" <<"\t\t" <<" Current Grade" <<"\t   "<< "   Cumulative Grade" <<"\t" << " Rank " << endl;
                cout << "\t"<< char(201);      for(int i=0; i<70; i++){cout << char(205);}      cout << char(187) << endl;
                cout << "\t"<< char(186); cout <<"   " << i+1<<"\t\t\t" << "    3.9  " << "\t\t" << " 3.9 " << "\t\t";
                for(int j =0;j<s[i].course_number; j++)
                {
                    cout << s[i].c[j].passorfail;

                }
                cout <<" " <<char(186) << endl;
                cout << "\t"<< char(200);      for(int x=0; x<39; x++){cout << char(205);}      cout << char(188) << endl;

        }
    }

    system("PAUSE");
	system("CLS");
	return 1;

}

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
            cout << "\t\t" << char(179) << " \tSTUDENT: "  <<s[i].studentname << "\t        " << char(179) << endl; cout<<endl;
            cout << "\t\t" << char(192);      for(int x=0; x<39; x++){cout << char(196);}      cout << char(217) << endl;
            cout<<endl;

            cout << "\t\t"<< char(201);      for(int x=0; x<40; x++){cout << char(205);}      cout << char(187) << endl;
            cout<<"\t\t\t----NO INFORMATION-----\n";
            cout << "\t\t"<< char(200);      for(int x=0; x<40; x++){cout << char(205);}      cout << char(188) << endl;
        }
    }

	system("PAUSE");
	system("CLS");
	return 1;

}

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
            cout << "\t\t" << char(179) << " \tSTUDENT: " << s[i].studentname << "\t        " << char(179) << endl; cout<<endl;
            cout << "\t\t" << char(192);      for(int x=0; x<39; x++){cout << char(196);}      cout << char(217) << endl;
            cout<<endl;

            cout << "\t\t"<< char(201);      for(int x=0; x<40; x++){cout << char(205);}      cout << char(187) << endl;
            cout<<"\t\t\t--Contact Information--\n\n";
            cout<<"\t\t"<<char(186)<< "\tInstructor Name: " << c.instructor_name <<"     "<<char(186)<<endl;
            cout<<endl;
            cout<<"\t\t"<<char(186)<< "\tPhone Number: " << " +(251)9-154-7845 " <<" "<<char(186)<<endl;
            cout<<endl;
            cout<<"\t\t"<<char(186)<< "\tPhone Number: " << " +(251)9-154-7845 " <<" "<<char(186)<<endl;
            cout<<endl;
            cout << "\t\t"<< char(200);      for(int x=0; x<40; x++){cout << char(205);}      cout << char(188) << endl;

        }
    }


	system("PAUSE");
	system("CLS");
	return 1;

}

/*pass or fail*/

string passorfail(char a)
{

    if(a >= 'B' && a <='A')
    {
        return "PASS";
    }

    else if( a=='C')
    {
        return "WARN";
    }

        else if( a=='F')
    {
        return "DISMISS";
    }
}


void welcomeScreen()
{

    cout << "\n\n\n";
    Sleep(200);
    cout << "\t\t\t\t * * *  **** *      ****  ***   ***   ****   " << endl;
    Sleep(200);
    cout << "\t\t\t\t * * * *     *     *     *   * * * * *        "<< endl;
    Sleep(200);
    cout << "\t\t\t\t * * * ***** *     *     *   * * * * *****    " << endl;
    Sleep(200);
    cout << "\t\t\t\t * * * *     *     *     *   * * * * *         " << endl;
    Sleep(200);
    cout << "\t\t\t\t  ***   **** *****  ****  ***  * * *  ****     " << endl;
    Sleep(200);
    cout<<endl;
    cout<<"\t\t\t\t============================================="<<endl;
    Sleep(200);
    cout<<"\t\t\t\t\tSTUDENT MANEGEMENT SYSTEM  "<<endl;
    Sleep(200);
    cout<<"\t\t\t\t============================================="<<endl;
    Sleep(200);
    cout<<endl;
    cout<<"\t\t\t\t\t->";system("pause");

}


void exiting()
{
    cout<<"\n";
    cout<<"\t\t->EXITING ";Sleep(200);cout<<".";
    Sleep(200);cout<<".";Sleep(200);cout<<".";
    Sleep(200);cout<<".";Sleep(200);cout<<".";

}

int integer_validation(){
    int a;
    cin>>a;

    while(!cin.good()){
        cin.clear();
        cin.ignore(INT_MAX,'\n');
        cout<<"Error try again: ";
        cin>>a;
    }
    return a;
}
void freeUpMain(){
    system("CLS");
    again:
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

                     getinfo(stud.student_amount);
                     goto redo;
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

                //modiify student
                else if(done == 4)
                {
                    system("CLS");
                    int id;
                    cout<<"\t->Enter Student ID: ";
                    cin>>id;

                    int hold = modify(id);

                    if(hold == 1)
                    {

                        goto redo;
                    }


                }

                //delete student
                else if(done == 5)
                {
                    system("CLS");
                    goto again;

                }

                //neither
                else if(done == 6)
                {
                    system("CLS");
                    goto again;
                }
                else
                {
                    exiting();
                    cout<<"\t\t"<< system("PAUSE");
                }
            }

        }

        break;

    case 2:
        {
            //again;
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
                   // again;
                }

                else
                {
                    cout<<"\t\t\n\n -> NO SUCH STUDENT EXISTS IN DATABASE....\n\n";
                    cout<<"\t\t->";system("pause");
                    system("CLS");
                    //again;
                }


        }
        break;
    case 3:
        {
           exiting();
           cout<<"\t\t\t\t\t->";system("pause");

        }

    }


}
