#include<iostream>
#include<string>

using namespace std;

class TLClass
{
    private:
        string id;
        string name;
        string description;
        string position;
    public:
        void input()
        {
            cout<<"Nhap id: ";
            getline(cin,id);
            cout<<"Nhap name class: ";
            getline(cin,name);
            cout<<"Nhap mo ta lop hoc: ";
            getline(cin,description);
            cout<<"Nhap vi tri lop: ";
            getline(cin,position);
        }
        void output()
        {
            cout<<id<<"\t"<<name<<"\t"<<description<<"\t"<<position<<endl;
        }

        string getId()
        {
            return id;
        }
        
        string getName()
        {
            return name;
        }
        
        string getDescription()
        {
            return description;
        }
        
        string getPosition()
        {
            return position;
        }
        void setPosition(string position)
        {
            this->position = position;
        }
};

class TLStudent
{
    private:
        string id;
        string name;
        string adderss;
        string description;
        double note;
        TLClass tlClass;
    public:
        void input()
        {
            cout<<"Nhap id: ";
            getline(cin,id);
            cout<<"Nhap name student: ";
            getline(cin,name);
            cout<<"Nhap dia chi: ";
            getline(cin,adderss);
            cout<<"Nhap mo ta sinh vien: ";
            getline(cin,description);
            //cin.ignore();
            cout<<"Nhap diem: ";
            //nhap lop
            
            cin>>note;
            cin.ignore();
            cout<<"Nhap lop:"<<endl;
            tlClass.input();
            
        }

        void output()
        {
            cout<<id<<"\t"<<name<<"\t"<<adderss<<"\t"<<description<<"\t"<<note<<"\t";
            tlClass.output();
        }

        string getId()
        {
            return id;
        }
        string getName()
        {
            return name;
        }
        string getAdderss()
        {
            return adderss;
        }
        string getDescription()
        {
            return description;
        }
        double getNote()
        {
            return note;
        }

        TLClass getTlClass()
        {
            return tlClass;
        }
        friend void addStudent(int &count, TLStudent *&newStudent);
};

void addStudent(int &count, TLStudent *&newStudent)
{
    TLStudent tmpStudent;
    cout << "Nhap vao sinh vien thu " << count + 1 << endl;
    tmpStudent.input();

    int newCount = count + 1;
    TLStudent *tmp = new TLStudent[newCount];

    for (int i = 0; i < count; i++)
    {
        tmp[i] = newStudent[i];
    }
    tmp[count] = tmpStudent;

    delete[] newStudent;
    newStudent = tmp;
    count = newCount;

    cout << "Da them sinh vien thanh cong" << endl;
}

int main()
{
    //1 Them moi sinh vien
    TLStudent *newStudent = nullptr;
    string continues;
    int count=0;
    while (1)
    {
        cout<<"Moi ban nhap vao sinh vien(stop or n de dung): ";
         getline(cin,continues);
        if (continues=="stop"||continues=="n")
        {
            break;
        }
        else
        {
            if (count==0)
            {
                newStudent = new TLStudent[1];
            }
            else
            {
                TLStudent *tmp = new TLStudent[count + 1];
                for (int i = 0; i < count; ++i)
                {
                    tmp[i] = newStudent[i];
                }
                delete[] newStudent;
                newStudent = tmp;
            }
            addStudent(count, newStudent);
        }
        

    }
    
    
    //2 xoa sinh vien koi danh sach
    //delete newStudent;
    //3 tim kiem sinh vien theo id
    string tmpid;
    cout<<"Nhap id sinh vien can tim: ";
    getline(cin,tmpid);
    cout<<"Sinh vien co id:"<<tmpid<<" la: "<<endl;
    for (int i = 0; i < count; i++)
    {
        
        if (newStudent[i].getId()==tmpid)
        {
            newStudent[i].output();
        }
        else
        {
            cout<<"Khong tim thay sinh vien"<<endl;
        }
    }
    //4 liet ke danh sach sinh vien
    cout<<"Danh sach sinh vien la: "<<endl;
    for (int i = 0; i < count; i++)
    {
        newStudent[i].output();
    }
    //5 liet ke danh sach sinh vien theo id lop
    string tmpidclass;
    cout<<"Nhap id lop can tim: ";
    getline(cin,tmpidclass);
    cout<<"Sinh vien co id lop:"<<tmpidclass<<" la: "<<endl;
    for (int i = 0; i < count; i++)
    {
        
        if (newStudent[i].getTlClass().getId()==tmpidclass)
        {
            newStudent[i].output();
        }
        else
        {
            cout<<"Khong co sinh vien"<<endl;
        }
    }
    //6 liet ke danh sach sinh vien co diem lon hon 5 va in ra so luong
    cout<<"Danh sach sinh vien co diem lon hon 5 la: "<<endl;
    int demmax5=0;
    for (int i = 0; i < count; i++)
    {
        if (newStudent[i].getNote()>=5)
        {
            newStudent[i].output();
            demmax5++;
        }
    }
    cout<<"So luong sinh vien co diem lon hon 5 la: "<<demmax5<<endl;

    //7 liet ke danh sach sinh vien co diem nho hon 5 va in ra so luong
    int demmin5=0;
    cout<<"Danh sach sinh vien co diem nho hon 5 la: "<<endl;
    for (int i = 0; i < count; i++)
    {
        if (newStudent[i].getNote()<5)
        {
            newStudent[i].output();
            demmin5++;
        }
    }
    cout<<"So luong sinh vien co diem nho hon 5 la: "<<demmin5<<endl;
    //8 liet ke danh sach sinh vien co diem cao nhat va in ra so luong
    //tim diem max
    double max=0;
    int demmax=0;
    for(int i=0;i<count;i++)
    {
        if (newStudent[i].getNote()>max)
        {
            max=newStudent[i].getNote();
        }
    }
    cout<<"Danh sach sinh vien co diem cao nhat la: "<<endl;
    for (int i = 0; i < count; i++)
    {
        if (newStudent[i].getNote()==max)
        {
            newStudent[i].output();
            demmax++;
        }
    }
    cout<<"So luong sinh vien co diem cao nhat la: "<<demmax<<endl;
    
    return 0;
}