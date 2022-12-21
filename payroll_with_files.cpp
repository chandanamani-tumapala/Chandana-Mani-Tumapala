#include<iostream>
#include<fstream>
#include<bits/stdc++.h>
#include<conio.h>
#include<process.h>
#include<cstdio>
#include<cstring>


using namespace std;
void empdisplay(string);
void manager_display();

class employee{
    public:
    string name,id,password;
    int age;
    double salary;
    int yearsofexp;
    string salarygivenornot;
};


void intro()
{
	cout<<"\n\n\n\t\t  SRM PAYROLL MANAGEMENT PROJECT";
	cout<<"\n\t\t  ------------------------------";
	//cout<<"\n\n\t\t  MANAGEMENT";
	//cout<<"\n\n\t\t  PROJECT";

	cin.get();
}
int emplogin()
{

    int i;
    char c=' ',pword[15];
	string id,pass;
	//char pass[10]="password";

	cout<<" \n                       EMPLOYEE LOGIN";
	cout<<" \n                      --------_ -----";
	cout<<" \n                       ENTER ID:-";
    cin>>id;
	cout<<" \n                       ENTER PASSWORD:-";
    //cin>>pass;
    while (i < 15)
        {
            pword[i] = getch();
            c = pword[i];
            if (c == 13)
                break;
            else
                printf("*");
            i++;
        }
        pword[i] = '\0';



    fstream f1;
    f1.open("data.txt",ios::in);
    string line,idstr;
    bool flag = false;
    while(getline(f1,line)){
        if(line == id){
            idstr=line;
            flag = true;
            getline(f1,line);
            pass=line;
        }
    }


    if(flag==false)
        return 3;


    if(pword==pass)
    	{empdisplay(id);
    	return 2;}
    return 3;
}
int managerlogin()
{
    int i;
    char c=' ',pword[10];
	string uname;
	char pass[10]="password";
	cout<<" \n                       MANAGER LOGIN";
	cout<<" \n                      -------- -----";
	cout<<" \n                       ENTER USERNAME:-";
    cin>>uname;
	cout<<" \n                       ENTER PASSWORD:-";
    //cin>>pass;
    while (i < 10)
        {
            pword[i] = getch();
            c = pword[i];
            if (c == 13)
                break;
            else
                printf("*");
            i++;
        }
        pword[i] = '\0';


    if((uname=="manager") &&strcmp(pword, pass) == 0)
        {manager_display();
    	return 1;}
    return 0;
}
int login()
{

    char inp;

	system("cls");
	cout<<"\n\n\t1.Manager Mode"<<endl;
	cout<<"\n\n\t2.Employee Mode"<<endl;
	cout<<"\n\n\tEnter login mode:";
	cin>>inp;
	if(inp!='1' && inp!='2')
        {cout<<"\tChoose appropriate login mode"<<endl;
        cout<< "\tpress any key to continue...";
        getch();
        login();}

	return inp;
}


void add_employee(){
    employee e;
    string h;
    cout<<"enter the employee details: "<<endl;
    cout<<"id: ";
    cin>>e.id;
    cout<<"name: ";
    cin>>e.name;
    h=e.name;
    cout<<"age: ";
    cin>>e.age;
    cout<<"Years of working together: ";
    cin>>e.yearsofexp;
    cout<<"salary: ";
    cin>>e.salary;
    cout<<"this month salary recieved or not: ";
    cin>>e.salarygivenornot;
    e.password=e.id+to_string(0)+to_string(h.length()+10);
    fflush(stdout);
    fstream f;
    f.open("data.txt",ios::out | ios::app);
    f<<e.id<<endl;
    f<<e.password<<endl;
    f<<e.name<<endl;
    f<<e.age<<endl;
    f<<e.yearsofexp<<endl;
    f<<e.salary<<endl;
    f<<e.salarygivenornot<<endl;
    f.close();
    system("cls");
}



void delete_employee(string id){
    fstream f1;
    f1.open("data.txt",ios::in);
    fstream f2;
    f2.open("tem2.txt",ios::out);
    string line;
    bool flag = false;
    while(getline(f1,line)){
        if(line == id){
            for(int i=0;i<7;i++){

                getline(f1,line);
            }
            flag = true;
        }
        if(line!="")
            f2<<line<<endl;
    }
    if(flag==false){
        cout<<"There is no employee with the given id to delete."<<endl;
    }
    else{
        cout<<"The employee record is deleted from the database."<<endl;
    }
    f1.close();
    f2.close();
    remove("data.txt");
    rename("tem2.txt","data.txt");
    cin.ignore();
    cin.get();
    system("cls");
}



void display_all(){

    fstream f;
    string line;
    f.open("data.txt",ios::in);
    getline(f,line);
    if(line==""){
        cout<<"There are no records to display."<<endl;
        f.close();
        cin.ignore();
	    cin.get();
        system("cls");
        return ;
    }
    fstream f1;
    f1.open("data.txt",ios::in);

    cout<<"The total employee list:"<<endl;

    while(getline(f1,line)){
        cout<<"Id: "<<line;
        getline(f1,line);
        getline(f1,line);
        cout<<"\tName: "<<line;

        for(int i = 0;i<2;i++){
            getline(f1,line);}
        getline(f1,line);
        cout<<"\tsalary:"<<line<<endl;
        getline(f1,line);

    }
    f1.close();
    cin.ignore();
	cin.get();
    system("cls");
}



void display_sp(string id){
    fstream f1;
    f1.open("data.txt",ios::in);
    string line;
    bool flag = false;
    while(getline(f1,line)){
        if(line == id){
            flag = true;
            cout<<"The employees details are: "<<endl;
            cout<<"\tId: "<<line<<endl;
            getline(f1,line);
            getline(f1,line);
            cout<<"\tName: "<<line<<endl;
            getline(f1,line);
            cout<<"\tAge: "<<line<<endl;
            getline(f1,line);
            cout<<"\tYear of working together: "<<line<<endl;
            getline(f1,line);
            cout<<"\tSalary: "<<line<<endl;
            getline(f1,line);
            cout<<"\tThis month's Salary recived or not: "<<line<<endl;
            break;
        }
    }
    if(flag==false){
        cout<<"There is no employee with the given id ."<<endl;
    }
    f1.close();
    cin.ignore();
    cin.get();
    system("cls");
}


void modify_employee(string id){
    employee e;
    fstream f1;
    f1.open("data.txt",ios::in);
    fstream f2;
    f2.open("tem2.txt",ios::out);
    string line;
    bool flag = false;
    while(getline(f1,line)){
        if(line == id){
            for(int i=0;i<6;i++){
                getline(f1,line);
            }
            flag = true;
            cout<<"enter the employee details: "<<endl;
            cout<<"id: ";
            e.id=id;
            cout<<e.id<<endl;
            cout<<"name: ";
            cin>>e.name;
            string h=e.name;
            cout<<"age: ";
            cin>>e.age;
            cout<<"Years of working together: ";
            cin>>e.yearsofexp;
            cout<<"salary: ";
            cin>>e.salary;
            cout<<"this month salary recieved or not: ";
            cin>>e.salarygivenornot;
            e.password=e.id+to_string(0)+to_string(h.length()+10);
            f2<<e.id<<endl;
            f2<<e.password<<endl;
            f2<<e.name<<endl;
            f2<<e.age<<endl;
            f2<<e.yearsofexp<<endl;
            f2<<e.salary<<endl;
            f2<<e.salarygivenornot<<endl;
        }
        if(line!="")
            f2<<line<<endl;
    }
    if(flag==false){
        cout<<"There is no employee with the given id to modify."<<endl;
    }
    else{
        cout<<"The employee record is modified from the database."<<endl;
    }
    cin.ignore();
    cin.get();
    f1.close();
    f2.close();
    remove("data.txt");
    rename("tem2.txt","data.txt");
}


void print_payroll(string id){
    system("cls");
    fstream f1;
    f1.open("data.txt",ios::in);
    string line;
    bool flag = false;
    while(getline(f1,line)){
        if(line == id){
            flag = true;
            cout<<"Employee Id: "<<line<<endl;
            getline(f1,line);
            getline(f1,line);
            cout<<"\nName: "<<line<<endl;
            getline(f1,line);
            cout<<"\nAge: "<<line<<endl;
            getline(f1,line);
            cout<<"\nYear of working together: "<<line<<endl;
            getline(f1,line);
            cout<<"\nBasic Salary: "<<line<<endl;

            int x=0;
            for(int i=0;i<line.size();i++){
                x = x*10 + (int(line[i])-48);
            }
            cout<<"\n\t\tAllowances(18%): "<<x*0.18<<endl;
            cout<<"\t\tDeductions(6%): "<<x*0.06<<endl;
            cout<<"\nNet Total Salary is: "<<x+x*0.12<<endl;
            getline(f1,line);
            cout<<"\n\tThis Pay Slip is authorised by SRMAP University. "<<endl;
            break;
        }
    }
    if(flag==false){
        cout<<"There is no employee with the given id."<<endl;
    }
    f1.close();
    cin.ignore();
    cin.get();
    system("cls");
}

void empdisplay_sp(string id){
    fstream f1;
    f1.open("data.txt",ios::in);
    string line;
    bool flag = false;
    while(getline(f1,line)){
        if(line == id){
            flag = true;
            //cout<<"The employees details are: "<<endl;
            cout<<"\tId: "<<line<<endl;
            getline(f1,line);
            getline(f1,line);
            cout<<"\tName: "<<line<<endl;
            getline(f1,line);
            cout<<"\tAge: "<<line<<endl;
            getline(f1,line);
            cout<<"\tYear of working together: "<<line<<endl;
            getline(f1,line);
            cout<<"\tSalary: "<<line<<endl;
            getline(f1,line);
            cout<<"\tThis month's Salary recived or not: "<<line<<endl;
            break;
        }
    }
    if(flag==false){
        cout<<"There is no employee with the given id to delete."<<endl;
    }
    f1.close();
    return;


}
void manager_display()
{
    char inp;
    x:
    do
	{
		system("cls");
		cout<<"\n\n\n\tMAIN MENU";
        cout<<"\n\n\t1.CREATE EMPLOYEE RECORD";
        cout<<"\n\n\t2.DISPLAY ALL EMPLOYEE RECORDS";
        cout<<"\n\n\t3.SEARCH EMPLOYEE RECORD ";
        cout<<"\n\n\t4.MODIFY EMPLOYEE RECORD";
        cout<<"\n\n\t5.DELETE EMPLOYEE RECORD";
        cout<<"\n\n\t6.PRINT PAY SLIP OF THE EMPLOYEE";
        cout<<"\n\n\t7.EXIT";
        cout<<"\n\n\tPlease Enter Your Choice (1-7) ";
        cin>>inp;
        system("cls");
        string idinp;
        switch(inp)
        {
            case '1':	add_employee(); break;
            case '2':	display_all(); break;
            case '3':	cout<<"\n\n\tPlease Enter The id number "; cin>>idinp;
                        display_sp(idinp); break;
            case '4':	cout<<"\n\n\tPlease Enter The id number "; cin>>idinp;
                        modify_employee(idinp);break;
            case '5':	cout<<"\n\n\tPlease Enter The id number "; cin>>idinp;
                        delete_employee(idinp);break;
            case '6':   cout<<"\n\n\tPlease Enter The id number "; cin>>idinp;
                        print_payroll(idinp);break;
            case '7':	break;
            default:	cout<<"\n\n\tPlease enter a vaild option to proceed."<<endl; goto x;
        }
    }while(inp!='7');
}

void empdisplay(string id)
{
    char inp;
    x:
        do
        {
        system("cls");
		//cout<<"\n\n\n\tMAIN MENU";
		empdisplay_sp(id);
        cout<<"\n\n\t1.PRINT PAY SLIP OF THE EMPLOYEE";
        cout<<"\n\n\t2.EXIT";
        cout<<"\n\n\tPlease Enter Your Choice (1-2) ";
        cin>>inp;
        if(inp=='1')
            print_payroll(id);
        }
        while(inp!='2');

}

int main()
{
	employee e;
	intro();
	char ch;
	int con;
	ch=login();
	system("cls");
    int a=0;
    switch(ch)
		{
		case '1': a= managerlogin();break;
		case '2': a=emplogin(); break;


		}
    //con=a;
    //if(a==0){
    while(a==0)
        {
        system("cls");
        cout<<"\n\t\tDetails does not match.....\n";
        cin.get();
        a=managerlogin();
        }

    while(a==3)
        {
        system("cls");
        cout<<"\n\t\tDetails does not match";
        cin.get();
        a=emplogin();
        }


}







