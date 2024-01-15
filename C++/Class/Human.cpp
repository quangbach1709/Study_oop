#include<iostream>
#include<string>

using namespace std;

class Human{
	private:
		string hoten;
		int year;
	public:
		Human()
		{
			hoten="";
			year=0;
		}
		Human(string hoten,int year)
		{
			this->hoten=hoten;
			this->year=year;
		}
		void setHoTen(string hoten)
		{
			this->hoten=hoten;
		}
		string getHoTen()
		{
			return hoten;
		}
		void setNamSinh(int year)
		{
			this->year=year;
		}
		int getNamSinh()
		{
			return year;
		}
		virtual void input()
		{
			cout<<"Nhap Ho ten: ";
			getline(cin,hoten);
			cout<<"Nhap nam sinh: ";
			cin>>year;
			cin.ignore();
		}
		virtual void output()
		{
			cout<<"Ho ten: "<<hoten<<endl;
			cout<<"Nam sinh: "<<year<<endl;
		}
		friend istream& operator>>(istream& is,Human &a)
		{
			a.input();
			return is;
		}
		friend ostream& operator<<(ostream& os, Human& a)
		{
			a.output();
			return os;
		}
		
};
class BenhNhan :public Human{
	private:
		string tenbenh;
		int date;
		long long gia;
	public:
		BenhNhan()
		{
			tenbenh="";
			date=0;
			gia=0;		
		}
		BenhNhan(string tenbenh,int date,long long gia,string hoten,int year):Human(hoten,year)
		{
			this->tenbenh=tenbenh;
			this->date=date;
			this->gia=gia;
		}
		void setTenBenhAn(string tenbenh)
		{
			this->tenbenh=tenbenh;
		}
		string getTenBenhAn()
		{
			return tenbenh;
		}
		void setNgayNamVien(int date)
		{
			this->date=date;
		}
		int getNgayNamVien()
		{
			return date;
		}
		void setVienPhi(long long gia)
		{
			this->gia=gia;
		}
		long long getVienPhi()
		{
			return gia;
		}
		void input()
		{
			Human::input();
			cout<<"Nhap Ten banh an: ";
			getline(cin,tenbenh);
			cout<<"Nhap So ngay nam vien: ";
			cin>>date;
			cin.ignore();
			cout<<"Nhap gia vien phi: ";
			cin>>gia;
			cin.ignore();
		}
		
		void output()
		{
			Human::output();
			cout<<"Ten benh an: "<<tenbenh<<endl;
			cout<<"So ngay nam vien: "<<date<<endl;
			cout<<"Vien phi:"<<gia<<endl;
		}
		int TuoiHienTai()
		{
			return 2024-getNamSinh();
		}
		long long VienPhi()
		{
			return gia*date;
		}
};

class Bacsi:public Human{
	private:
		string mabs;
		float ngay;
		long long tien;
	public:
		Bacsi()
		{
			mabs="";
			ngay=0;
			tien=0;
		}
		Bacsi(string mabs,float ngay,long long tien,string hoten,int year):Human(hoten,year)
		{
			this->mabs=mabs;
			this->ngay=ngay;
			this->tien=tien;
		}
		void setMaBacSi(string mabs)
		{
			this->mabs=mabs;
		}
		string getMaBacSi()
		{
			return mabs;
		}
		void setNgayLamViec(float ngay)
		{
			this->ngay=ngay;
		}
		float getNgayLamViec()
		{
			return ngay;
		}
		void setTienCong(long long tien)
		{
			this->tien=tien;
		}
		long long getTienCong()
		{
			return tien;
		}
		void input()
		{
			Human::input();
			cout<<"Nhap ma bac si: ";
			getline(cin,mabs);
			cout<<"Nhap ngay lam viec: ";
			cin>>ngay;
			cin.ignore();
			cout<<"Nhap tien cong: ";
			cin>>tien;
			cin.ignore();
		}
		void output()
		{
			Human::output();
			cout<<"Ma bac si: "<<mabs<<endl;
			cout<<"Ngay lam viec: "<<ngay<<endl;
			cout<<"Tien cong: "<<tien<<endl;
		}
		long long TienCongThang()
		{
			return ngay*tien;
		}
		
};

int main()
{
	int dem=0;
	int tmp;
	Human **list =new Human*[100];
	while(dem<100)
	{
		cout<<"Nhap nguoi(1:Benh nhan,2:Bac si,0: thoat): ";
		cin>>tmp;
		cin.ignore();
		if(tmp==1)
		{
			list[dem]=new BenhNhan();
			cin>>(*list[dem]);
			dem++;
		}
		else if(tmp==2)
		{
			list[dem]=new Bacsi();
			cin>>(*list[dem]);
			dem++;
		}
		else
		break;
		
	}
	cout<<"Danh sach nguoi:"<<endl;
	for(int i=0;i<dem;i++)
	{
		cout<<"Nguoi thu "<<i+1<<" la."<<endl;
		cout<<(*list[i]);
	}
	cout<<"Danh sach benh nhan co tuoi >=10:"<<endl;
	for(int i=0;i<dem;i++)
	{
		BenhNhan *bn=dynamic_cast<BenhNhan*>(list[i]);
		if(bn->TuoiHienTai()>=10)
		{
			cout<<*bn;
		}
	}
	
	Bacsi *a=dynamic_cast<Bacsi*>(list[0]);
	for(int i=0;i<dem;i++)
	{
		Bacsi *bs=dynamic_cast<Bacsi*>(list[i]);
		if(a->getNgayLamViec()<bs->getNgayLamViec())
		{
			a=bs;
		}
	}
	cout<<"Bac si co ngay lam viec nhieu nhat la: "<<endl;
	cout<<*a;
	return 0;
}
