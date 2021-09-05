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
bool verifyPass(char pw[])
{
 const char pass[30]="admin";
   if(strcmp(pw,pass)==0)
    return true;
   else
    return false;
}
bool verifyUserName(char User[]){
    const char checkUser[30]="admin";
    if(strcmp(User,checkUser)==0)
        return true;
    else
        return false;
}
