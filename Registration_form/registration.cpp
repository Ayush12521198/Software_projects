#include<iostream>
#include<fstream>
#include<windows.h>
#include<sstream>
using namespace std;
class Login{
private:
string LoginId,Password;
public:
Login():LoginId(""),Password(""){}
void setId(string id){
    LoginId=id;

}
void setPw(string pw){
Password=pw;
}
string getId(){
    return LoginId;
}
string getPw(){
    return Password;
}


};

int registration(Login log){
   system("cls");
   string id,pw;
   cout<<"\tEnter Login ID: ";
   cin>>id;
   log.setId(id);
  
start:
   cout<<"\tEnter A strong password: ";
   cin>>pw;
   if(pw.length()>=8){
   log.setPw(pw);

   }
   else{
    cout<<"\tEnter Minimum 8 character !"<<endl;
    goto start;
   }
   ofstream outfile("Login.txt",ios::app);

   if(!outfile){
    cout<<"\tError: File Can't Open!"<<endl;
   }
   else{
    outfile<<"\t"<<log.getId()<<" : "<<log.getPw()<<endl<<endl;
    cout<<"\tUser Registered Successfully!"<<endl;
   }
   outfile.close();
 Sleep(3000);
}
 int  login(){
    system("cls");
    string id,pw;
    cout<<"\tEnter Login ID: ";
    cin>>id;
    cout<<"\tEnter Password: ";
    cin>>pw;
    ifstream infile("Login.txt");
    if(!infile){
        cout<<"\tError : File Can't Open!"<<endl;
    }
    else{
        string line;
        bool found=false;
        while(getline(infile,line)){
            stringstream ss;
            ss<<line;
            string userID,userPW;
            char delimiter;
            ss>>userID>>delimiter>>userPW;
            if(id==userID && pw==userPW){
                found=true;
                cout<<"\tPlease Wait";
            
            for(int i=0;i<3;i++){
                cout<<".";
                Sleep(8000);
            }
            system("cls");
 cout<<"\tWelcome to this page!"<<endl;
        }
    }
    if(!found){
        cout<<"\tError: Incorrect Login ID or Password!"<<endl;
    }
    }
    infile.close();
    Sleep(5000);
   } 

int main(){
    Login log;
    bool exit=false;
    while(!exit){
        system("cls");
        int val;
        cout<<"\tWelcome To Register & Login Form"<<endl;
        cout<<"\t********************************"<<endl;
        cout<<"\t1.Register"<<endl;
        cout<<"\t2.Login"<<endl;
        cout<<"\t3.Exit"<<endl;
        cout<<"\tEnter Choice: ";
        cin>>val;
        if(val==1){
            registration(log);
        }
        else if(val==2){
login();
        }
        else if(val==3){
            system("cls");
exit=true;
cout<<"\tGood Luck"<<endl;
Sleep(3000);

        }
        Sleep(3000);


    }
}