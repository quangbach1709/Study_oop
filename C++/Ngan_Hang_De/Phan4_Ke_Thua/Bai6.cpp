#include<iostream>

using namespace std;

class Oxy
{
	protected:
		float x,y;
	public:
		Oxy(){
		};
		~Oxy()
		{
			cout<<"Da huy Oxy>"<<endl;
		}
		float getX()
		{
			return x;
		}
		void setX(float x)
		{
			this->x = x;
		}
		float getY()
		{
			return y;
		}
		void setY(float y)
		{
			this->y = y;
		}
		friend ostream& operator<<(ostream& os,Oxy &tmp)
		{
			os<<"x = "<<tmp.x<<endl;
			os<<"y = "<<tmp.y<<endl;
			return os;
		}
		friend istream& operator>>(istream& is,Oxy &tmp)
		{
			cout<<"Nhap x = ";
			is>>tmp.x;
			cout<<"Nhap y = ";
			is>>tmp.y;
		
			return is;
		}
		friend void trungDiem(Oxy &tmp1,Oxy &tmp2);
};

void trungDiem(Oxy &tmp1,Oxy &tmp2)
{
	cout<<"Trung diem cua 2 Oxy la: "<<endl;
	cout<<"X = "<<(tmp1.getX()+tmp2.getX())/2<<endl;
	cout<<"Y = "<<(tmp1.getY()+tmp2.getY())/2<<endl;
}

class Oxyz:public Oxy
{
	private:
		float z;
	public:
		Oxyz(){
		};
		~Oxyz()
		{
			cout<<"Huy Oxyz."<<endl;
		}
		float getZ()
		{
			return z;
		}
		friend ostream& operator<<(ostream& os,Oxyz &tmp)
		{
			os<<"X = "<<tmp.getX()<<endl;
			os<<"Y = "<<tmp.getY()<<endl;
			os<<"Z = "<<tmp.getZ()<<endl;
			
			return os;
		}
		friend istream& operator>>(istream& is, Oxyz &tmp)
		{
			cout << "Nhap x = ";
			is >> tmp.x;
			cout << "Nhap y = ";
			is >> tmp.y;
			cout << "Nhap z = ";
			is >> tmp.z;
			
			return is;
		}
		friend void trungDiem(Oxyz &tmp1,Oxyz &tmp2);
};

void trungDiem(Oxyz &tmp1,Oxyz &tmp2)
{
	cout<<"Trung diem Oxyz la: "<<endl;
	cout<<"X = "<<(tmp1.getX()+tmp2.getX())/2<<endl;
	cout<<"Y = "<<(tmp1.getY()+tmp2.getY())/2<<endl;
	cout<<"Z = "<<(tmp1.getZ()+tmp2.getZ())/2<<endl;
	
	
}

int main()
{
	int n;
	cout<<"Nhap so luong diem: ";
	cin>>n;
	cin.ignore();
	Oxyz *ptr=new Oxyz[n];
	for(int i=0;i<n;i++)
	{
		cout<<"Nhap toa do diem thu "<<i+1<<": "<<endl;
		cin>>ptr[i];
	}
	cout<<"Danh sach diem la: "<<endl;
	for(int i=0;i<n;i++)
	{
		cout<<"Toa do diem thu "<<i+1<<" la: "<<endl;
		cout<<ptr[i];
		cout<<"-----------------"<<endl;
	}
	cout<<"Cac cap diem doi xung qua tam O la: "<<endl;
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(ptr[i].getX()==-ptr[j].getX()&&ptr[i].getY()==-ptr[j].getY()&&ptr[i].getZ()==-ptr[j].getZ())
			{
				cout<<"Cap diem thu "<<i+1<<" va diem thu "<<j+1<<" la cap diem doi xung."<<endl;
			}
		}
	}
	return 0;
}
