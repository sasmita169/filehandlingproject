#include<iostream>
#include<fstream>
using namespace std;
int ID;
class student
{
    private:
        int id;
        string name;
        int age;
        string stream;
     public:
        void setvalue(int id, string name ,int age ,string stream)
        {
            this->id=id;
            this->name=name;
            this->age=age;
            this->stream=stream;
            delete this;
         
        }
    void Addstudent()
        {
            cout<<" Enter student name :"<<endl;
            cin.get();// to clean buffer
            getline(cin,name);
            cout<<" Enter student age:"<<endl;
            cin>>age;
            cout<<" Enter student stream:"<<endl;
            cin>>stream;
            ID++;
            ofstream fout;
            fout.open("c:/file/student.txt",ios::app);
            fout<<"\n"<<ID;
            fout<<"\n"<<name;
            fout<<"\n"<<age;
            fout<<"\n"<<stream;
            fout.close();
            fout.open("c:/file/id.txt",ios::app);
            fout<<"\n"<<ID;
            fout.close();
            cout<<" Record added succesfully "<<endl;

        }
    void PrintAllstudent()
        {
           ifstream fin;
           fin.open("c:/file/student.txt");
           student s;
           while(!fin.eof())
           {
            fin>>s.id;
            fin.ignore();//to clean  file  buffer
            getline(fin,s.name);
            fin>>s.age;
            fin>>s.stream;
            s.print();

           }
           fin.close();
        }

    void print()
          {
            cout<<"ID ="<<id<<endl;
            cout<<"Name ="<<name<<endl;
            cout<<"Age ="<<age<<endl;
            cout<<"Stream ="<<stream<<endl;
            cout<<"......................................."<<endl;
           }
    void SearchStudent(int id)
        {
           ifstream fin;
           fin.open("c:/file/student.txt");
           student s;
           while(!fin.eof())
           {
            fin>>s.id;
            fin.ignore();//to clean  file  buffer
            getline(fin,s.name);
            fin>>s.age;
            fin>>s.stream;
            if(s.id==id)
            {
                s.print();
                break;
            }
         }
         fin.close();
        }
    void DeleteStudent(int id )
        {
           ifstream fin;
        fin.open("c:/file/student.txt");

        ofstream fout;
        fout.open("c:/file/temp.txt",ios::app);

        student s;
        while(!fin.eof())
        {
            fin>>s.id;
            fin.ignore();
            getline(fin,s.name);
            fin>>s.age;
            fin>>s.stream;

           if(s.id != id)
           {
            fout<<"\n"<<s.id;
            fout<<"\n"<<s.name;
            fout<<"\n"<<s.age;
            fout<<"\n"<<s.stream;
           }
        }

        fin.close();
        fout.close();

        remove("c:/file/student.txt");
        rename("c:/file/temp.txt","c:/file/student.txt");

        cout<<"Record Deleted Successfully"<<endl;
        }
    void UpdateStudent(int id)
        {
          DeleteStudent(id);

        cout<<"Enter your name"<<endl;
        cin.get();
        getline(cin,name);
        cout<<"Enter your age"<<endl;
        cin>>age;
        cout<<"Enter your stream"<<endl;
        cin>>stream;
        ID++;

        ofstream fout;
        fout.open("c:/file/student.txt",ios::app);
        fout<<"\n"<<id;
        fout<<"\n"<<name;
        fout<<"\n"<<age;
        fout<<"\n"<<stream;
        fout.close();

        cout<<"Record Added Successfully"<<endl; 
        }
};
int main()
{
int choice;
ifstream fin;
fin.open("c:/file/id.txt");
if(!fin)
{
    cout<<"File not created !"<<endl;
}
else
{
    while(!fin.eof())
    {
        fin>>ID;
    }
}
fin.close();
cout<<endl<<"ID= "<<ID<<endl;
while(1)
{
    cout<<endl<<"Enter your choice :"<<endl;
    cout<<"1. Add student "<<endl;
    cout<<"2.Print all the students "<<endl;
    cout<<"3.Serach a student "<<endl;
    cout<<"4.Delete a student "<<endl;
    cout<<"5.Update a student "<<endl;
    cout<<"6.Exit"<<endl;
    cin>>choice;
    student s;
    int id;
    switch(choice)
    {
        case 1:s.Addstudent();
                break;
        case 2:s.PrintAllstudent();
                break;
        case 3:cout<<" Enter student id "<<endl;
               cin>>id;
               s.SearchStudent(id);
                break;
        case 4:cout<<"Enter Student id "<<endl;
               cin>>id;
              s.DeleteStudent(id);
                break;
        case 5:cout<<"Enter Student id "<<endl;
               cin>>id;
               s.UpdateStudent(id);
                break;   
        case 6: exit(0);
        default:
         cout<<" Wrong choice please try agin !";

    }
}
return 0;
}