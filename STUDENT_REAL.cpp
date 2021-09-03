#include <iostream>
#include <String.h>

using namespace std;

//ANOTHER BASE CODE TO WORK ON//

/*declaring structures here*/

//course structure

struct course
{
	string course_name;
    string instructor_name;
    int credit_hour;
    float assesment, finalResult;
    char grade;
};

//student structure

struct student
{
	string studentname;
	int id_no = 1234;
	char sex;
	course c[100];


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

void getinfo(student s[], int sizee);
void display(student s[], int sizee);
void searchStudent(int);
void deleteStudent(int);
char calcgrade(float, float);

/*****OPERATION STUDENT FCUNTIONS*****/

void currentSemester();
void status();
void nextSem();

/*main function*/

int main()
{
    student s;
    course c;

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
                cout << "\t\t\t"<< "   Admin Name: "; cin>>c.instructor_name;

                system("CLS");
                cout<<"\n\t\t\t WELCOME " <<c.instructor_name <<endl;
                cout<<endl;
                cout<<"\t->"; system("PAUSE");
                system("CLS");
                int done = functionMenu();

                //getting information//
                if(done == 1)
                {
                    //local vairables
                    system("CLS");
                    int sizee;
                    cout << "\t\t" <<char(218);      for(int i=0; i<40; i++){cout << char(196);}      cout << char(191) << endl;
                    cout << "\t\t"<< "   Number of students to enter: "; cin>>sizee;

                    student stud[sizee];
                    getinfo(stud, sizee);
                }
                //display students
                else if(done == 2)
                {
                    system("CLS");
                    main();
                }

                //search student
                else if(done == 3)
                {
                    system("CLS");
                    main();

                }

                //modiify student
                else if(done == 4)
                {
                    system("CLS");
                    main();
                }

                //delete student
                else if(done == 5)
                {
                    system("CLS");
                    main();

                }

                //neither
                else
                {
                    cout<<"\t\t->EXITING........\n\n";
                    cout<<"\t\t"<< system("PAUSE");
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
            int done2 = studentMenu(idNew);
            //student conditions from the menu

            //display his/her information
                if(done2 == 1)
                {
                    system("CLS");
                    status();
                    //main();
                }
            //display current semester grade
                else if(done2 == 2)
                {
                    system("CLS");
                    currentSemester();
                    //main();
                }

            //Next semester courses
                else if(done2 == 3)
                {
                    system("CLS");
                    nextSem();
                    //main();

                }

            //Contact teacher
                else if(done2 == 4)
                {
                    system("CLS");
                    main();
                }
            //neither
                else
                {
                    cout<<"\t\t->EXITING........\n\n";
                    cout<<"\t\t"<< system("PAUSE");
                }


        }
        break;
    case 3:
        {
            cout<<"\t\t->EXITING........\n\n";
            cout<<"\t\t"<< system("PAUSE");
        }

    }


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
    cout<<"\n\t\t->Input Here: " ;cin>>choice;

    return choice;

}

//admin login

char adminLogin()
{
    system("color 9A");
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
	cout << "\t"<< char(186) << "   \t\t 6.To EXIT            \t\t\t     " << char(186) << endl;
	cout << "\t"<< char(186) << "                    \t\t\t\t\t     " << char(186)<<endl;
	cout << "\t"<< "   \t\t\t ->Input Here: ";cin>>choice;


	return choice;

}


//student menu//

char studentMenu(int idnumber)
{
    system("CLS");
    student s;
    if(s.id_no == idnumber)
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
	cout << "\t"<< char(186) << "   \t\t 5.To EXIT            \t\t\t     " << char(186) << endl;
	cout << "\t"<< char(186) << "                    \t\t\t\t\t     " << char(186) << endl;
	cout << "\t"<< char(186) << "   \t\t\t ->Input Here: ";cin>>choice;

	return choice;
    }

    else
    {
        cout<<"\t\t\n\n -> NO SUCH STUDENT EXISTS IN DATABASE....\n\n";
        cout<<"\t\t->";system("pause");
        system("CLS");
        main();

        return 0;
    }


}

/******Get info function******/

void getinfo(student s[], int sizee)
{
    system("CLS");
    system("COLOR 3E");

    cout << "\t\t" << char(218);      for(int i=0; i<39; i++){cout << char(196);}      cout << char(191) << endl;
    cout << "\t\t" << char(179) << " \t        WELCOME                 " << char(179) << endl;
    cout << "\t\t" << char(179) << "                      \t\t\t" << char(179) << endl;
    int a = sizee;
    int b; // storing course numbers
    for(int i=0; i<sizee; i++)
    {
        cout << "\t\t" << char(218);      for(int i=0; i<39; i++){cout << char(196);}      cout << char(191) << endl;
        cout << "\t\t" << char(179) << " \tSTUDENT: " << i+1 << "\t\t        " << char(179) << endl; cout<<endl;
        cout << "\t\t" << char(179) << "  Enter student ID:  ";cin>> s[i].id_no; cout<<"\t\t"<< char(179);
        cout<<"\t\t\t\t\t"<< char(179) << endl;
        cout << "\t\t" << char(179) << "  Enter the student name: ";cin>>s[i].studentname;  cout << "\t\t" << char(179);
        cout<<"\t\t\t\t\t"<< char(179) << endl;
        cout << "\t\t" << char(179) << "  Enter Gender of student (M/F): ";cin>>s[i].sex; cout << "\t\t" << char(179);
        cout<<"\t\t\t\t\t"<< char(179) << endl;
        cout << "\t\t" << char(179) << "  Enter Number of Courses: ";cin>>b; cout << "\t\t" << char(179);
        cout<<"\t\t\t\t\t"<< char(179) << endl;

        // creating the course object with array of structure
        for(int j=0;j<b; j++ )
        {
            system("CLS");
            cout << "\t\t" << char(218);      for(int i=0; i<39; i++){cout << char(196);}      cout << char(191) << endl;
            cout << "\t\t" << char(179) << " \tCOURSE: " << j+1 << "\t\t        " << char(179) << endl; cout<<endl;
            cout << "\t\t" << char(179) << "  Enter Course Name:  ";cin>> s[i].c[j].course_name; cout<<"\t\t"<< char(179);
            cout<<"\t\t\t\t\t"<< char(179) << endl;
            cout << "\t\t" << char(179) << "  Enter credit Hour: ";cin>>s[i].c[j].credit_hour;  cout << "\t\t" << char(179);
            cout<<"\t\t\t\t\t"<< char(179) << endl;
            cout << "\t\t" << char(179) << "  Enter the assessment result: ";cin>> s[i].c[j].assesment; cout<<"\t\t"<< char(179);
            cout<<"\t\t\t\t\t"<< char(179) << endl;
            cout << "\t\t" << char(179) << "  Enter the Final Result: ";cin>>s[i].c[j].finalResult;  cout << "\t\t" << char(179);
            cout<<"\t\t\t\t\t"<< char(179) << endl;
            system("CLS");
            cout << "\t\t" << char(192);      for(int i=0; i<39; i++){cout << char(196);}      cout << char(217) << endl;
            s[i].c[j].grade = calcgrade(s[i].c[j].assesment, s[i].c[j].finalResult);
        }


        a++;
    }

    system("CLS");
    if(a>sizee)
    {
        //another global variables
        int redo;
        cout <<"GO TO MAIN MENU? (1/2)\n";
        cin>>redo;

        if(redo == 1)
        {
            system("CLS");
            main();
        }


    }


}

/****calculate grade*****/

char calcgrade(float first, float second)
{
    int total = first + second;

    if( total>80 && total <=100)
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

void display()
{

    /*code here*/
}

void searchStudent()
{

    /*code here*/
}

void deleteStudent()
{

    /*code here*/
}


/****Operations for student page***/

void currentSemester()
{
    string user = "EYUEL KETEMA";//garbage variable
    system("CLS");
    system("COLOR 4E");
    cout << "\t\t" << char(218);      for(int i=0; i<39; i++){cout << char(196);}      cout << char(191) << endl;
    cout << "\t\t" << char(179) << " \t        WELCOME                 " << char(179) << endl;
    cout << "\t\t" << char(179) << "                      \t\t\t" << char(179) << endl;
    cout << "\t\t" << char(179) << " \tSTUDENT: "; cout <<user << "\t        " << char(179) << endl; cout<<endl;
    cout << "\t\t" << char(192);      for(int i=0; i<39; i++){cout << char(196);}      cout << char(217) << endl;
    cout<<endl;
    cout << "\t" << char(218);      for(int i=0; i<60; i++){cout << char(196);}      cout << char(191) << endl;
    cout<<"\t"<<" Course Name" <<"\t\t" <<"Credit hours" <<"\t\t\t"<< "Grade" <<endl;
    cout << "\t"<< char(201);      for(int i=0; i<60; i++){cout << char(205);}      cout << char(187) << endl;

    for(int i=0;i<1;i++)
    {
    	cout << "\t"<< char(186); cout <<" BIOLOGY"<<"\t\t" << "    5  " << "\t\t\t\t" << "   A "; cout <<"" <<char(186) << endl;
    	cout << "\t"<< char(186); cout <<" BIOLOGY"<<"\t\t" << "    5  " << "\t\t\t\t" << "   A "; cout <<"" <<char(186) << endl;
    	cout << "\t"<< char(186); cout <<" BIOLOGY"<<"\t\t" << "    5  " << "\t\t\t\t" << "   A "; cout <<"" <<char(186) << endl;

	}

	system("PAUSE");
	system("CLS");
	main();


}

void  status()
{

    string user = "EYUEL KETEMA";//garbage variable
    system("CLS");
    system("COLOR 4E");
    cout << "\t\t" << char(218);      for(int i=0; i<39; i++){cout << char(196);}      cout << char(191) << endl;
    cout << "\t\t" << char(179) << " \t        WELCOME                 " << char(179) << endl;
    cout << "\t\t" << char(179) << "                      \t\t\t" << char(179) << endl;
    cout << "\t\t" << char(179) << " \tSTUDENT: " <<user << "\t        " << char(179) << endl; cout<<endl;
    cout << "\t\t" << char(192);      for(int i=0; i<39; i++){cout << char(196);}      cout << char(217) << endl;
    cout<<endl;

	cout << "\t" << char(218);      for(int i=0; i<70; i++){cout << char(196);}      cout << char(191) << endl;
    cout<<"\t"<<" Roll Number" <<"\t\t" <<" Current Grade" <<"\t   "<< "   Cumlative Grade" <<"\t" << " Status " << endl;

    cout << "\t"<< char(201);      for(int i=0; i<70; i++){cout << char(205);}      cout << char(187) << endl;

    for(int i=0;i<1;i++)
    {
    	cout << "\t"<< char(186); cout <<"   " << i+1<<"\t\t\t" << "    3.9  " << "\t\t" << " 3.9 " << "\t\t" << " PASS "; cout <<" " <<char(186) << endl;
    	cout << "\t"<< char(186); cout <<"   " << i+1+1<<"\t\t\t" << "    3.9  " << "\t\t" << " 3.9 " << "\t\t" << " PASS "; cout <<" " <<char(186) << endl;


	}
	cout << "\t"<< char(200);      for(int i=0; i<70; i++){cout << char(205);}      cout << char(188) << endl;

}

void nextSem()
{

    string user = "EYUEL KETEMA";//garbage variable
    system("CLS");
    system("COLOR 4E");
    cout << "\t\t" << char(218);      for(int i=0; i<39; i++){cout << char(196);}      cout << char(191) << endl;
    cout << "\t\t" << char(179) << " \t        WELCOME                 " << char(179) << endl;
    cout << "\t\t" << char(179) << "                      \t\t\t" << char(179) << endl;
    cout << "\t\t" << char(179) << " \tSTUDENT: "  <<user << "\t        " << char(179) << endl; cout<<endl;
    cout << "\t\t" << char(192);      for(int i=0; i<39; i++){cout << char(196);}      cout << char(217) << endl;
    cout<<endl;

    cout << "\t\t"<< char(201);      for(int i=0; i<40; i++){cout << char(205);}      cout << char(187) << endl;
    cout<<"\t\t\t----NO INFORMATION-----\n";
	cout << "\t\t"<< char(200);      for(int i=0; i<40; i++){cout << char(205);}      cout << char(188) << endl;


	system("PAUSE");
	system("CLS");
	main();

}

void contact()
{


}
