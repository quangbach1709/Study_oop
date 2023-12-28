#include<iostream>
#include<string>

using namespace std;

class Employee
{
    private:
        int id,phone,employee_type;
        static int employee_count;
        string fullname,eamil,Brithday;
    public:
        Employee()
        {
            employee_count++;
        }
        Employee(int id,string fullname,string eamil,string Brithday,int phone,int employee_type)
        {
            this->id=id;
            this->fullname=fullname;
            this->eamil=eamil;
            this->Brithday=Brithday;
            this->phone=phone;
            this->employee_type=employee_type;
            employee_count++;
        }
        void setId(int id)
        {
            this->id=id;
        }
        int getId()
        {
            return id;
        }
        void setFullname(string fullname)
        {
            this->fullname=fullname;
        }
        string getFullname()
        {
            return fullname;
        }
        void setEamil(string eamil)
        {
            this->eamil=eamil;
        }
        string getEamil()
        {
            return eamil;
        }
        void setBrithday(string Brithday)
        {
            this->Brithday=Brithday;
        }
        string getBrithday()
        {
            return Brithday;
        }
        void setPhone(int phone)
        {
            this->phone=phone;
        }
        int getPhone()
        {
            return phone;
        }
        void setEmployee_type(int employee_type)
        {
            this->employee_type=employee_type;
        }
        int getEmployee_type()
        {
            return employee_type;
        }
        void setEmployee_count(int employee_count)
        {
            this->employee_count=employee_count;
        }
        int getEmployee_count()
        {
            return employee_count;
        }
        
        //nap trong nhap
        friend istream& operator>>(istream& is,Employee &a)
        {
            cout<<"Nhap Id: ";
            is>>a.id;
            cin.ignore();
            cout<<"Nhap Ten: ";
            getline(is,a.fullname);
            cout<<"Nhap Email: ";
            getline(is,a.eamil);
            cout<<"Nhap Ngay Sinh: ";
            getline(is,a.Brithday);
            cout<<"Nhap So Dien Thoai: ";
            is>>a.phone;
            cin.ignore();
            cout<<"Nhap Loai Nhan Vien: ";
            is>>a.employee_type;
            cin.ignore();
            return is;
        }
        //nap trong xuat
        friend ostream& operator<<(ostream& os,Employee &a)
        {
            os<<"Id: "<<a.id<<endl;
            os<<"Ten: "<<a.fullname<<endl;
            os<<"Email: "<<a.eamil<<endl;
            os<<"Ngay Sinh: "<<a.Brithday<<endl;
            os<<"So Dien Thoai: "<<a.phone<<endl;
            os<<"Loai Nhan Vien: "<<a.employee_type<<endl;
            os<<"So Luong Nhan Vien: "<<a.employee_count<<endl;
            return os;
        }
        virtual void showing()=0;

        
};
int Employee::employee_count=0;
class Fresher:public Employee
{
    private:
        int graduation_date;
        string graduation_rank,education;
    public:
        Fresher()
        {
            
        }
        Fresher(int id,string fullname,string eamil,string Brithday,int phone,int employee_type,int graduation_date,string graduation_rank,string education):Employee(id,fullname,eamil,Brithday,phone,employee_type)
        {
            this->graduation_date=graduation_date;
            this->graduation_rank=graduation_rank;
            this->education=education;

        }
        void setGraduation_date(int graduation_date)
        {
            this->graduation_date=graduation_date;
        }
        int getGraduation_date()
        {
            return graduation_date;
        }
        void setGraduation_rank(string graduation_rank)
        {
            this->graduation_rank=graduation_rank;
        }
        string getGraduation_rank()
        {
            return graduation_rank;
        }
        void setEducation(string education)
        {
            this->education=education;
        }
        string getEducation()
        {
            return education;
        }
        
        friend istream& operator>>(istream& is,Fresher &a)
        {
            cin>>(Employee&)a;
            cout<<"Nhap Ngay Tot Nghiep: ";
            is>>a.graduation_date;
            cin.ignore();
            cout<<"Nhap Xep Loai Tot Nghiep: ";
            getline(is,a.graduation_rank);
            cout<<"Nhap Truong Tot Nghiep: ";
            getline(is,a.education);
            return is;
        }
        friend ostream& operator<<(ostream& os,Fresher &a)
        {
            os<<(Employee&)a;
            os<<"Ngay Tot Nghiep: "<<a.graduation_date<<endl;
            os<<"Xep Loai Tot Nghiep: "<<a.graduation_rank<<endl;
            os<<"Truong Tot Nghiep: "<<a.education<<endl;
            return os;
        }
        void showing()
        {
            cout<<"Id: "<<getId()<<endl;
            cout<<"Ten: "<<getFullname()<<endl;
            cout<<"Email: "<<getEamil()<<endl;
            cout<<"Ngay Sinh: "<<getBrithday()<<endl;
            cout<<"So Dien Thoai: "<<getPhone()<<endl;
            cout<<"Loai Nhan Vien: "<<getEmployee_type()<<endl;
            cout<<"So Luong Nhan Vien: "<<getEmployee_count()<<endl;
            cout<<"Ngay Tot Nghiep: "<<graduation_date<<endl;
            cout<<"Xep Loai Tot Nghiep: "<<graduation_rank<<endl;
            cout<<"Truong Tot Nghiep: "<<education<<endl;
        }
};

class Intern :public Employee
{
    private:
        int majors;
        string semester,university_name;
    public:
        Intern()
        {
            
        }
        Intern(int id,string fullname,string eamil,string Brithday,int phone,int employee_type,int majors,string semester,string university_name):Employee(id,fullname,eamil,Brithday,phone,employee_type)
        {
            this->majors=majors;
            this->semester=semester;
            this->university_name=university_name;
        }
        void setMajors(int majors)
        {
            this->majors=majors;
        }
        int getMajors()
        {
            return majors;
        }
        void setSemester(string semester)
        {
            this->semester=semester;
        }
        string getSemester()
        {
            return semester;
        }
        void setUniversity_name(string university_name)
        {
            this->university_name=university_name;
        }
        string getUniversity_name()
        {
            return university_name;
        }
        friend istream& operator>>(istream& is,Intern &a)
        {
            cin>>(Employee&)a;
            cout<<"Nhap Chuyen Nganh: ";
            is>>a.majors;
            cin.ignore();
            cout<<"Nhap Hoc Ki: ";
            getline(is,a.semester);
            cout<<"Nhap Ten Truong: ";
            getline(is,a.university_name);
            return is;
        }
        friend ostream& operator<<(ostream& os,Intern &a)
        {
            os<<(Employee&)a;
            os<<"Chuyen Nganh: "<<a.majors<<endl;
            os<<"Hoc Ki: "<<a.semester<<endl;
            os<<"Ten Truong: "<<a.university_name<<endl;
            return os;
        }
        void showing()
        {
            cout<<"Id: "<<getId()<<endl;
            cout<<"Ten: "<<getFullname()<<endl;
            cout<<"Email: "<<getEamil()<<endl;
            cout<<"Ngay Sinh: "<<getBrithday()<<endl;
            cout<<"So Dien Thoai: "<<getPhone()<<endl;
            cout<<"Loai Nhan Vien: "<<getEmployee_type()<<endl;
            cout<<"So Luong Nhan Vien: "<<getEmployee_count()<<endl;
            cout<<"Chuyen Nganh: "<<majors<<endl;
            cout<<"Hoc Ki: "<<semester<<endl;
            cout<<"Ten Truong: "<<university_name<<endl;
        }
};

int main()
{
    Employee **list=new Employee*[6];
    int tmp;
    int tmp1;
    int dem=0;
    do
    {
        cout<<"1.Nhap Fresher(1) or Intern(2):"<<endl;
        cout<<"2.Hien Thi Employee:"<<endl;
        cout<<"3.Hien thi Fresher and Intern: "<<endl;

        cin>>tmp;
        cin.ignore();
        switch (tmp)
        {
        case 1:
            cout<<"Nhap Fresher(1) or Intern(2): ";
            cin>>tmp1;
            if (tmp1==1)
            {
                list[dem]=new Fresher();
                cin>>*dynamic_cast<Fresher*>(list[dem]);
                dem++;
            }
            else if (tmp1==2)
            {
                list[dem]=new Intern();
                cin>>*dynamic_cast<Intern*>(list[dem]);
                dem++;
            }
            break;
        case 2:
            for (int i = 0; i < dem; i++)
            {
                cout<<(*list[i]);
            }
            break;
        case 3:
            for (int i = 0; i < dem; i++)
            {
                if (list[i]->getEmployee_type()==1)
                {
                    cout<<(*dynamic_cast<Fresher*>(list[i]));
                }
                else if (list[i]->getEmployee_type()==2)
                {
                    cout<<(*dynamic_cast<Intern*>(list[i]));
                }
            }
            break;
        default:
            break;
        }
        
    } while (dem<=6);
    
        
    return 0;  


}