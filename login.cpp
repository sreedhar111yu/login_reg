#include<bits/stdc++.h>
using  namespace std;

void login();
void registration();
void forgot();


int main(){

    int c; //choice
    cout<<"\t\t\t _________________________________________________\n\n\n";
    cout<<"\t\t\t              Welcome to the Login page           \n\n\n";
    cout<<"\t\t\t_________________        MENU       _______________\n\n";
    cout<<"                                                          \n\n";
    cout<<"\t| press 1 to LOGIN                         |"<<endl;
    cout<<"\t| press 2 to REGISTER                      |"<<endl;
    cout<<"\t| press 3 to if you forget your PASSWORD   |"<<endl;
    cout<<"\t| press 4 to EXIT                           |"<<endl;
    cout<<"\n\t\t\t Please enter your choice : ";
    cin>>c;
    cout<<endl;

    switch(c){
        case 1:
          login();
          break;

        case 2:
           registration();
           break;

        case 3:
           forgot();
           break;

        case 4:
            cout<<"\t\t\t THANK YOU! \n\n";

        default:
            system("cls"); 
            cout<<"\t\t\t Please select from the option given above\n"<<endl;
            main();
    }

}
void login(){
    int count;
    string userId, password, id, pass;
    system("cls");
    cout<<"\t\t\t Please  enter the username and password :"<<endl;
    cout<<"t\t\t USERNAME ";
    cin>>userId;
    cout<<"\t\t\t PASSWORD ";
    cin>>password;

    ifstream input("records.txt");  //ifstream will check inside the file` if the login password exist or not 

    while(input>>id>>pass){
        if(id==userId && pass== password){
            count=1;
            system("cls");
        }
    }
    input.close(); // close this file
    if(count==1){
        cout<<userId<<"\n Your LOGIN is successfull \n Thanks for logging in ! \n";
    }
    else{
        cout<<"\n LOGIN ERROR \n please check  your username and password\n";

    }
}

void registration(){
    string ruserid, rpassword, rid, rpass;
    system("cls");
    cout<<"\t\t\t Enter the username :";
    cin>>ruserid;
    cout<<"\t\t\t Enter the password :";
    cin>>rpassword;

    ofstream f1("records.txt",ios::app);//ofstream to write in file  ios app is app mode in the function 
    f1<<ruserid<<' '<<rpassword<<endl;
    system("cls");
    cout<<"\n\n\n registration successfull!\n";
    main();
}
void forgot(){
    int option;
    system("cls");
    cout<<"\t\t\t You forgot the password? No worries \n";
    cout<<"press 1 to search your id username "<<endl;
    cout<<"press 2 to go back to the main menu "<<endl;
    cout<<"\t\t\t Enter your choice :";
    switch(option){
        case 1:
        {
            int count =0;
            string suserid, sid, spass;
            cout<<"\n\t\t\t Enter the username which you remembered :";
            cin>>suserid;

            ifstream f2("records.txt");
            while(f2>>sid>>spass){
                if(sid==suserid){
                    count=1;
                }
            }
            f2.close();
            if(count ==1){
                cout<<"\n\n Your account is found! \n";
                cout<<"\n\n Your password is : "<<spass;
                main();
            }
            else{
                cout<<"\n\t Sorry! your account is not found \n";
                main();
            }
            break;
        }

        case 2:
           {
            main();
           }

           default:
             cout<<"\t\t\t Wrong choice ! Please try again"<<endl;
             forgot();
           
    }
}