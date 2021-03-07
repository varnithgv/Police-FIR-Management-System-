#include <iostream>
#include<stdlib.h>
#include <ctime>
#include<ctype.h>
#include<fstream>
#include<sstream>
#include<stdio.h>
//#include<conio.h>
#include<string.h>
#include<string>
#include<chrono> //for sleeping
#include<thread> // --do--
#include<cstdlib>//for random increments
#include<time.h>
#include<unistd.h>
using namespace std;
class creation
{
public:
string name;
string height;
char color[10];
char gender;
long long int No=0;
char crime[10];
12
int age; int act; };
//murder
class murders
{
public:
string mplace;
string mdetails;
string mweapon;
string mtime;
};
//theft
class theft
{
public:
string tplace, tdetails, tthing, ttime;
};
//kidnap
class kidnap
{ public:
string kplace, kdetails, kperson, ktime;
};
int i = 0, n = 0;
string RandomString(int len);
void logout();
void create();
void progressbar();
void view();
13
int main()
{
char user[10], pass[10]; int ch; int w = 0; cout << "\n\n\n *****LOGIN*****\n";
cout << "\nyou have only 3 attempts\n";
y:
cout << "\nEnter username:";
cin >> user;
cout << "Enter password:"; cin >> pass; cout<<"Please Wait While it's loading..... :)\n "; char q1[10]= "user"; char s1[5] = "pass";
if (strcmp(pass, s1) == 0 && strcmp(user,q1)==0)
{
progressbar();
cout<<"\nLogin successfull\n";
x:
cout << "\n\n\n\n\nselect an option \n1. Create a FIR\n2.View FIR\n3.logout\n";
cin >> ch;
switch (ch)
{
case 1: create(); break;
case 2: view(); break;
case 3: logout();
default:
break;
}
goto x;
}
else
14
{
w++;
if (w < 3)
{
if (w == 2)
{
cout << "\n\nLast attempt";
}
cout << "\n\nwrong username or password";
goto y;
}
else { cout << "\n\n\n login unsuccessfull";
exit(0); }
}
return 0;
}
void create()
{ int z; creation obj1; obj1.act = 0;
murders objm;
theft objt;
kidnap objk;
cout << "\nAuthentication..........";
q:
string random_str = RandomString(5);
cout << "\nVerification code : " << random_str << endl;
string check_str;
15
cout << "please enter the authenticator code below:\n";
cin >> check_str;
if (random_str != check_str)
{
cout << "\nwrong input ! try again";
goto q;
}
cout << "Authentication completed.....";
f:
cin.clear();
cout << " \n\n\n\n\n Police FIR \n";
cout << "\nEnter the Convicts name: ";
cin.ignore();
cin.ignore();
cin.ignore();
getline(cin,obj1.name);
cout << "\nEnter the gender(M/F/O): ";
cin >> obj1.gender;
if ((obj1.gender != 'M') && (obj1.gender != 'm') && (obj1.gender != 'f') && (obj1.gender != 'F') && (obj1.gender != 'O') && (obj1.gender != 'o'))
{
cout << "invalid input"; goto f;
} l:
cout << "\nEnter the age: ";
cin>>obj1.age;
if(!cin)
{ cout<<"wrong input";
16
goto f; } cout << "\nEnter the height: "; cin.ignore();
getline(cin,obj1.height);
cout << "\nEnter eyecolor: ";
cin >> obj1.color;
int count = 0;
for (int i = 0; obj1.color[i] != '\0'; i++)
{
if (isalpha(obj1.color[i]) == 0)
{
cout << " wrong input";
goto f;
break;
}
}
i++;
int firno = i;
cout << "\nEnter emegency contact No.";
cin >>obj1.No;
if (obj1.No > 9999999999 || obj1.No < 1000000000)
{
cout << "Invalid no.(too many or tooless numbers)\n";
goto f;
}
cout << "\nEnter the crime: ";
cin>>obj1.crime;
time_t t = time(NULL);
tm* timePtr = localtime(&t);
17
ofstream fout;
n++;
char buffer[16]; // make sure it's big enough snprintf(buffer, sizeof(buffer), "FIR_%d.txt", n);
fout.open(buffer, ios::out); //report display
fout << "\n\n\n ***** POLICE FIR*****\n";
fout << "\n\tDate " << (timePtr->tm_mday) << "/" << (timePtr->tm_mon) + 1 << "/" << (timePtr->tm_year) + 1900;
fout << "\n\tTime " << (timePtr->tm_hour) << ":" << (timePtr->tm_min) << ":" << (timePtr->tm_sec);
fout << "\n\tName : " <<obj1.name;
fout << "\n\tgender :" << obj1.gender; fout << "\n\tage :" << obj1.age; fout << "\n\theight:" << obj1.height;
fout << "\n\teye color :" << obj1.color;
fout << "\n\tcrime :" << obj1.crime;
//fout << "\n\tact :" << act;
fout << "\n\tAdress of police station: Madivala, Banglore, Bengaluru, Karnataka 560068\n";
fout << " \tFIR No.(filename.doc)= " << firno;
fout << "\n\tEmergency Contact no.: " << obj1.No;
// cin >> obj1.crime;
char s2[10] = "murder";
char s3[10] = "theft";
char s4[10] = "kidnap";
//char s5[10] = "bribe";
if (strcmp(obj1.crime, s2) == 0)
{ //murder obj1.act = 303; cout << "\n\nWhere did the murder take place: ";
cin.ignore(); getline(cin,objm.mplace);
18
cout << "\n\nWhen did the murder take place(inlude date and time): ";
cin.ignore(0);
getline(cin, objm.mtime);
cout << "\n\nWepon used: ";
cin.ignore(0);
getline(cin, objm.mweapon);
cout << "\n\nWhat exactly happened ? Who else was present ?"; cin.ignore(0); getline(cin, objm.mdetails);
fout << "\n\t Act: " <<obj1.act; fout << "\n\tCrime spot: "; fout << objm.mplace;
fout << "\n\tTime and date: ";
fout << objm.mtime; fout << "\n\tWeapon: ";
fout << objm.mweapon;
fout << "\n\tDetails: ";
fout << objm.mdetails;
}
else if (strcmp(obj1.crime, s3) == 0) { //theft obj1.act = 378; cin.ignore(0);
cout << "\nWhat was stolen: "; cin.ignore(0); getline(cin, objt.tthing);
cout << "\nWhere did the theft take place: ";
cin.ignore(0);
getline(cin, objt.tplace);
cout << "\n\nWhen did the theft take place(inlude date and time): ";
cin.ignore(0); getline(cin, objt.ttime); cout << "\n\nWhat exactly happened ? Who else was present? ";
19
cin.ignore(0);
getline(cin, objt.tdetails);
fout << "\n\t Act: " <<obj1.act; fout << "\n\tStolen material: ";
fout << objt.tthing;
fout << "\n\tTime and date the theft took place : ";
fout << objt.ttime; fout << "\n\tDetails: "; fout << objt.tdetails; }
else if (strcmp(obj1.crime, s4) == 0)
{ //kidnap
obj1.act = 359;
cin.ignore(0);
cout << "\n\nWho was kidnapped: "; cin.ignore(); getline(cin, objk.kperson); cout << "\n\nWhere did the abduction take place: ";
cin.ignore(0); getline(cin, objk.kplace); cout << "\n\nWhen did the abduction take place(inlude date and time): ";
cin.ignore(0);
getline(cin, objk.ktime);
cout << "\n\nWhat exactly happened ? Who else was present ? ";
cin.ignore(0);
getline(cin,objk.kdetails); fout << "\n Act: " << obj1.act; fout << "\nName of the person who was abducted: ";
fout << objk.kperson;
fout << "\nTime and date the theft took place : ";
fout << objk.kplace; fout << "\nDetails: ";
20
fout << objk.kdetails; }
//report display cout << "\n\n\n \t\t\t\t ***** POLICE FIR*****\n"; cout << "\tDate " << (timePtr->tm_mday) << "/" << (timePtr->tm_mon) + 1 << "/" << (timePtr->tm_year) + 1900; cout << "\n\tTime " << (timePtr->tm_hour) << ":" << (timePtr->tm_min) << ":" << (timePtr->tm_sec);
cout << "\n\tname : " <<obj1.name; cout << "\n\tgender :" << obj1.gender;
cout << "\n\tage :" <<obj1.age; cout << "\n\theight:" <<obj1.height; cout << "\n\teye color :" << obj1.color; cout << "\n\tcrime :" <<obj1.crime; //cout << "\n\tact :" << act; cout << " \n\tAdress of police station: Madivala, Banglore, Bengaluru, Karnataka 560068\n";
cout << " \tFIR No.= " << firno;
cout << "\n\tEmergency Contact no.: " << obj1.No;
fout.close();
if (strcmp(obj1.crime, s2) == 0)
{
cout << "\n\tAct: " << obj1.act;
cout << "\n\tCrime spot";
cout << objm.mplace;
cout << "\n\tTime and date: "; cout << objm.mtime; cout << "\n\tWeapon: "; cout << objm.mweapon;
cout << "\n\tDetails: "; cout << objm.mdetails; }
if (strcmp(obj1.crime, s3) == 0)
{
cout << "\n\t Act: " << obj1.act;
cout << "\n\tStolen material: ";
cout << objt.tthing; cout << "\n\tTime and date the theft took place : "; cout << objt.ttime;
21
cout << "\n\tDetails: ";
cout << objt.tdetails;
} if (strcmp(obj1.crime, s4) == 0)
{ cout << "\n\t Act: " <<obj1.act; cout << "\n\tName of the person who was abducted: "; cout << objk.kperson; cout << "\n\tTime and date the theft took place : "; cout << objk.kplace;
cout << "\n\t Details: "; cout << objk.kdetails;
}
cout<<"\nPlease wait while your file is uploading.....\n"; progressbar(); cout << "\n\n\n\n \t\t****** FILE SUCCESSFULLY CREATED AND STORED******"; return;
}
void view()
{
string text; ifstream inputfile;
string name, filename;
cout << "enter the file name";
cin >> filename;
cout << "\n\t\t\t " << filename << "\n";
cout<<"\n Please wait while we fetch the details....."; progressbar(); inputfile.open(filename, ios::in); if (!inputfile.is_open())
{ cout << "error"; }
else
{
22
while (inputfile.eof() == 0)
{
getline(inputfile, text); cout << text << endl; }
}
inputfile.close();
}
void logout() { cout << "\n\t\t\t\tYou've been logged out\t\n\n\n\n"; exit(0); }
string RandomString(int len)
{ srand(time(0)); string str = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz"; string newstr; int pos; while (newstr.size() != len) {
pos = ((rand() % (str.size() - 1)));
newstr += str.substr(pos, 1); }
return newstr;
}
void progressbar()
{ std::srand(time(NULL)); //seed random for(int progress=0;progress!=100;progress+=std::rand()%20){ //increment progress randomly //Delete the line below and change for loop condition to 'progress<=100' and put something meaningful in for loop progress increment in implementation.
if(progress>100) progress=100; std::cout<<"["; for(int i=0;i<100;i++)
23
if(i<progress)
std::cout<<'=';
else if(i==progress)
std::cout<<'>';
else
std::cout<<' '; std::cout<<"] "<<progress<<" %"<<'\r';
std::cout.flush();
std::this_thread::sleep_for(std::chrono::milliseconds(450)); //sleep
//Delete this line as well in implementation if(progress==100) ;
} std::cout<<std::endl; }