#include<fstream.h>
#include<conio.h>
#include<stdio.h>
#include<process.h>
#include<string.h>
#include<iomanip.h>

class member
{
char mno[6];
char mname[50];
int age;
char gender[5];
char type[20];


public:

void create_member()
{
cout<<"\nENTRY OF NEW MEMBER\n";
cout<<"\nENTER MEMBER ID NUMBER:";
cin>>mno;
cout<<"\nENTER NAME OF MEMBER: ";
gets(mname);
cout<<"\nENTER AGE OF MEMBER :";                
cin>>age;                
cout<<"\nENTER GENDER OF MEMBER :";
cin>>gender;
cout<<"\nENTER TYPE OF MEMBER :";
cout<<"\n PLATINUM \n GOLD \n SILVER : ";
gets(type);
                

}

void show_member()
{
cout<<"\nMEMBER ID NUMBER : "<<mno;
cout<<"\nMEMBER NAME : "<<mname;
cout<<"\nAGE OF MEMBER:"<<age;
cout<<"\nGENDER OF MEMBER:"<<gender;
cout<<"\nTYPE OF MEMBER:"<<type;



}

void modify_member()
{
cout<<"\nMEMBER ID NUMBER : "<<mno;
cout<<"\n MODIFY MEMBER NAME : ";
gets(mname);
cout<<"\n MODIFY MEMBER AGE:";
cin>>age;
cout<<"\n MODIFY MEMBER GENDER :";
cin>>gender;
cout<<"\n MODIFY MEMBER TYPE :";
cin>>type;


}

char *getno()
{
return mno;

}
};         


class facility
{
char fno[5];
char fname[20];

public:
void create_facility()
{
cout<<"ENTER FACILITY NUMBER:";
cin>>fno;
cout<<"ENTER FACILITY NAME:";
cin>>fname;

}
void show_facility()
{
cout<<"\n NUMBER OF FACILITY:"<<fno;
cout<<"\n NAME OF FACILITY:"<<fname;
}

void modify_facility()
{
cout<<"\nFACILITY NUMBER : "<<fno;
cout<<"\nMODIFY FACILITY NAME: ";
gets(fname);
}

char *getfno()
{
return fno;
}

};        

fstream fp,fp1;
member mem;
facility f;

void write_member()   //function to add member
{
char ch;
fp.open("member.dat",ios::out|ios::app);
do
{
clrscr();
mem.create_member();
fp.write((char*)&mem,sizeof(member));
cout<<"\n\nDO YOU WANT TO ADD MORE RECORD..(y/n?)";
cin>>ch;
}while(ch=='y'||ch=='Y');
fp.close();
}

void write_facility()    //function to add facility
{
char ch;

fp.open("facility.dat",ios::out|ios::app);
do
{
f.create_facility();
fp.write((char*)&f,sizeof(facility));
cout<<"\n\nDO YOU WANT TO ADD MORE RECORD..(y/n?)";
cin>>ch;
}while(ch=='y'||ch=='Y');
fp.close();
}



void change_member()     
{
char n[6];
int found=0;
clrscr();
cout<<"\n\n\tMODIFY  MEMBER REOCORD.... ";

cout<<"\n\n\tENTER NUMBER OF MEMBER YOU WANT TO MODIFY :";
cin>>n;
fstream fp;
fp.open("member.dat",ios::in|ios::out);
while(fp.read((char*)&mem,sizeof(member)) && found==0)
{
if(strcmpi(n,mem.getno())==0)
{
mem.show_member();
cout<<"\n ENTER DETAILS OF NEW MEMBER: "<<endl;
mem.modify_member();
int pos=fp.tellg()-sizeof(mem);
fp.seekp(pos,ios::beg);
fp.write((char*)&mem,sizeof(member));
cout<<"\n\n\t RECORD UPDATED......";
found=1;
}
}


fp.close();
if(found==0)
cout<<"\n\n RECORD NOT FOUND ";
getch();
}


void change_facility()     
{
char n[6];
int found=0;
clrscr();
cout<<"\n\n\tMODIFY FACILITY RECORD... ";

cout<<"\n\n\tENTER THE FACILITY NUMBER : ";
cin>>n;
fp.open("facility.dat",ios::in|ios::out);
while(fp.read((char*)&f,sizeof(facility)) && found==0)
{
if(strcmpi(n,f.getfno())==0)
{
f.show_facility();
cout<<"\nENTER NEW DETAILS OF FACILITY: "<<endl;
f.modify_facility();
int pos=-1*sizeof(f);
fp.seekp(pos,ios::cur);
fp.write((char*)&f,sizeof(facility));
cout<<"\n\n\t RECORD UPDATED";
found=1;
}
}

fp.close();
if(found==0)
cout<<"\n\n RECORD NOT FOUND ";
getch();
}

void delete_facility()    
{
char n[6];
int flag=0;
clrscr();
cout<<"\n\n\n\tDELETE FACILITY...";
cout<<"\n\nENTER THE FACILITY NUMBER YOU WANT TO DELETE : ";
cin>>n;
fp.open("facility.dat",ios::in|ios::out);
fstream fp2;
fp2.open("Temp.dat",ios::out);
fp.seekg(0,ios::beg);
while(fp.read((char*)&f,sizeof(facility)))
{
if(strcmpi(f.getfno(),n)!=0)
fp2.write((char*)&f,sizeof(facility));
else
flag=1;
}

fp2.close();
fp.close();
remove("facility.dat");
rename("Temp.dat","facility.dat");
if(flag==1)
cout<<"\n\n\tRECORD DELETED ..";
else
cout<<"\n\nRECORD NOT FOUND";
getch();
}


void delete_member()      
{
char n[6];
int flag=0;
clrscr();
cout<<"\n\n\n\tDELETE MEMBER...";
cout<<"\n\nENTER THE MEMBER NUMBER YOU WANT TO DELETE : ";
cin>>n;
fp.open("member.dat",ios::in|ios::out);
fstream fp2;
fp2.open("Temp.dat",ios::out);
fp.seekg(0,ios::beg);
while(fp.read((char*)&mem,sizeof(member)))
{
if(strcmpi(mem.getno(),n)!=0)
fp2.write((char*)&mem,sizeof(member));
else
flag=1;

}

fp2.close();
fp.close();
remove("member.dat");
rename("Temp.dat","member.dat");
if(flag==1)
cout<<"\n\n\tRECORD DELETED ..";
else
cout<<"\n\n\tRECORD NOT FOUND...";
getch();
}

void fintro()
{
clrscr();
cout<<"1)FACILITIES IN PLATINUM MEMBERSHIP:\n";
cout<<"ALL TRAINING FACILITIES,SWIMMING POOL, ALL GAMES LIKE FOOTBALL\n";
cout<<"BASKETBALL,TABLE TENNIS,COMPLETE DIET AND PRIVATE ASSISTANCE  \n";
cout<<"AND MANY OTHER BENFITS.........................\n";
cout<<"AMOUNT IS RS 10000";
cout<<"\n\n";
cout<<"2)FACILITIES IN GOLD MEMBERSHIP:\n";
cout<<"ALL TRAINING FACILITIES,SWIMMING POOL AND  ALL GAMES LIKE FOOTBALL\n";
cout<<"BASKETBALL,TABLE TENNIS........  \n";
cout<<"AMOUNT IS RS 5000 \n";
cout<<"\n";
cout<<"3)FACILITIES IN SILVER MEMBERSHIP:\n";
cout<<"ALL TRAINING FACILITIES AND SWIMMING POOL \n";
cout<<"AMOUNT IS RS 1000";
cout<<"\n";
}
void display_allm()  
{
clrscr();
fp.open("member.dat",ios::in);
if(!fp)
{
cout<<"ERROR!!! FILE COULD NOT BE OPEN ";
getch();
return;
}

cout<<"\n\n\t\tmember LIST\n\n";


while(fp.read((char*)&mem,sizeof(member)))
{
mem.show_member();
}
fp.close();
getch();
}
void display_allf()   
{
clrscr();
fp.open("facility.dat",ios::in);
if(!fp)
{
cout<<"ERROR!!! FILE COULD NOT BE OPEN ";
getch();
return;
}
cout<<"\n\n\t\tFACILITY LIST\n\n";


while(fp.read((char*)&f,sizeof(facility)))
{
f.show_facility();
}

fp.close();
getch();
}



void intro()
{
clrscr();
cout<<"\t\t\t\t\t\t\t\t\t\t\tULTIMATE SPORTS CLUB";
cout<<"\n\nMADE BY : DARSH TURAKHIA";
getch();
}


void main()
{
char ch;
intro();
do
{
TOP:
clrscr();
cout<<"\n\n\n\tMAIN MENU";
cout<<"\n\n\t01. TYPE OF MEMBERSHIP";
cout<<"\n\n\t02. MEMBER";
cout<<"\n\n\t03. FACILITY";
cout<<"\n\n\t04. REPORT";
cout<<"\n\n\t05. ABOUT US";
cout<<"\n\n\t06. EXIT ";
cout<<"\n\n\tPlease Select Your Option (1-6): ";
ch=getche();
switch(ch)
{
case '1': clrscr();
fintro();
getch();
break;
case '2':clrscr();
char j;

cout<<"ENTER THE CHOICE \n\n ";
cout<<"A)ADD RECORD : \n";
cout<<"B)MODIFY RECORD: \n";
cout<<"C)DELETE RECORD: \n";
cout<<"D)GOTO MAIN MENU:\n";

cin>>j;
if(j=='A'||j=='a')
write_member();
else if(j=='B'||j=='b')
change_member();
else if(j=='C'||j=='c')
delete_member();
else
goto TOP;
break;
case '3': clrscr();
char k;

cout<<"ENTER THE CHOICE \n\n ";
cout<<"A)ADD FACILITY: \n";
cout<<"B)MODIFY FACILITY: \n";
cout<<"C)DELETE FACILITY:  \n";
cout<<"D)GOTO MAIN MENU:\n";

cin>>k;
if(k=='A'||k=='a')
write_facility();
else if(k=='B'||k=='b')
change_facility();
else if(k=='C'||k=='c')
delete_facility();
else
goto TOP;
break;

case '4': clrscr();
char m;
cout<<"A)MEMBER REPORT \n";
cout<<"B)FACILITY REPORT \n";
cin>>m;
if(m=='A'||m=='a')
display_allm();
else if(m=='B'||m=='b')
display_allf();
else
goto TOP;
break;


case '5': clrscr();
cout<<"WELCOME TO ULTIMATE SPORTS CLUB\n";
cout<<"OUR AIM IS FOR EVERYONE TO STAY FIT\n";
cout<<"COME AND JOIN TO GET FIT AND HEALTHY\n";
getch();
goto TOP;

case '6': clrscr();
exit(0);


}
    }while(ch!='5')
}
