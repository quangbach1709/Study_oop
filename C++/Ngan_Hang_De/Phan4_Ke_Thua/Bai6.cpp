#include<iostream>

using namespace std;

class Oxy
{
	private:
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
			cout<<"Nhap x = ";
			

			
			
			return is;
		}
		friend Oxyz trungDiem(Oxyz &tmp1,Oxyz &tmp2);
};

Oxyz trungDiem(Oxyz &tmp1,Oxyz &tmp2)
{
	cout<<"Trung diem Oxyz la: "<<endl;
	cout<<"X = "<<(tmp1.getX()+tmp2.getX())/2<<endl;
	cout<<"Y = "<<(tmp1.getY()+tmp2.getY())/2<<endl;
	cout<<"Z = "<<(tmp1.getZ()+tmp2.getZ())/2<<endl;
	
	
}

int main()
{
	
}
