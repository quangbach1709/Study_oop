#include<iostream>
#include<string>

using namespace std;

class Human
{
	private:
		string HoTen;
		int age;
		bool sex;
	public:
		Human(){
		};
		~Human(){
			cout<<"Da huy Con Nguoi."<<endl;
		}
		virtual void input()
		{
			cout<<"Nhap Ho Ten: ";
			getline(cin,HoTen);
			cout<<"Chon gioi tinh(1:Man,0:Woman): ";
			cin>>sex;
			cout<<"Nhap tuoi: ";
			cin>>age;
			cin.ignore();
		}	
			
		virtual void output()
		{
			cout<<"Ho Ten la: "<<HoTen<<endl;
			cout<<"Gioi tinh la: "<<sex<<endl;
			cout<<"Tuoi la: "<<age<<endl;
		}
		virtual bool khenThuong()=0;
		
};

class Student :public Human
{
	private:
		string Class;
		float dtb;
	public:
		Student(){
		};
		~Student()
		{
			cout<<"Da huy sinh vien."<<endl;
		}
		void input()
		{
			Human::input();
			cout<<"Nhap lop: ";
			getline(cin,Class);
			cout<<"Nhap Diem TB: ";
			cin>>dtb;
			cin.ignore();
		}
		void output()
		{
			Human::output();
			cout<<"Lop: "<<Class<<endl;
			cout<<"Diem TB: "<<dtb<<endl;
		}
		bool khenThuong()
		{
			if(dtb>=8)
				return 1;
			return 0;
		}
		
};

class Teacher :public Human
{
	private:
		string BoMon;
		int SoBaiBao;
	public:
		Teacher(){
		};
		~Teacher()
		{
			cout<<"Da huy giao vien."<<endl;
		}
		void input()
		{
			Human::input();
			cout<<"Nhap Bo Mon: ";
			getline(cin,BoMon);
			cout<<"Nhap So bai bao: ";
			cin>>SoBaiBao;
			cin.ignore();
		}
		void output()
		{
			Human::output();
			cout<<"Bo mon la: "<<BoMon<<endl;
			cout<<"So bai bao: "<<SoBaiBao<<endl;
		}
		
		bool khenThuong()
		{
			if(SoBaiBao>=1)
				return 1;
			return 0;
		}
};
int main()
{
	Human *ptr;
	int n,m;
	cout<<"Nhap so Sinh vien: ";
	cin>>n;
	cin.ignore();
	ptr=new Student[n];
	Student *ptrsv=(Student*)ptr;
	for(int i=0;i<n;i++)
	{
		ptrsv[i].input();
	}
	cout<<"Danh sach Sinh vien la: "<<endl;
	for(int i=0;i<n;i++)
	{
		ptrsv[i].output();
		cout<<"----------"<<endl;
	}
	
	cout<<"Danh sach Sinh vien khen thuong: "<<endl;
	for(int i=0;i<n;i++)
	{
		if(ptrsv[i].khenThuong())
		{
			ptrsv[i].output();
		}
	}
	
	cout<<"Nhap so Giao vien: ";
	cin>>m;
	cin.ignore();
	ptr=new Teacher[m];
	Teacher *ptrgv=(Teacher*)ptr;
	for(int i=0;i<m;i++)
	{
		ptrgv[i].input();
	}
	cout<<"Danh sach giao vien la: "<<endl;
	for(int i=0;i<m;i++)
	{
		ptrgv[i].output();
		cout<<"-----------"<<endl;
	}
	
	cout<<"Danh sach Giao vien khen thuog: "<<endl;
	for(int i=0;i<m;i++)
	{
		if(ptrgv[i].khenThuong())
			ptrgv[i].output();
	}
	
	return 0;
	
	
}
