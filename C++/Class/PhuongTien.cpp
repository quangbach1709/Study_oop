#include<iostream>
#include<string>

using namespace std;

class Phuongtien{
	protected:
		int tocdo;
	public:
		Phuongtien()
		{
			tocdo=0;
		}
		Phuongtien(int v)
		{
			tocdo=v;
		}
		void setTocDo(int v)
		{
			tocdo=v;
		}
		int getTocDo()
		{
			return tocdo;
		}
		virtual void input()
		{
			cout<<"Nhap toc do: ";
			cin>>tocdo;
			cin.ignore();
			
		}
		
		
};
