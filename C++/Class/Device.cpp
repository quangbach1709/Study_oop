#include<iostream>
#include<string>

using namespace std;

class Device
{
	private:
		int id,dateCheTao;
		string name,nhaCheTao;
	public:
		void setId(int id)
		{
			this->id=id;
		}
		int getId()
		{
			return id;
		}
		void setName(string name)
		{
			this->name=name;
		}
		string getName()
		{
			return name;
		}
		void setNhaCheTao(string nhachetao)
		{
			this->nhaCheTao=nhachetao;
		}
		string getNhaCheTao()
		{
			return nhaCheTao;
		}
		void setDateCheTao(int ngaychetao)
		{
			this->dateCheTao=ngaychetao;
		}
		int getDateCheTao()
		{
			return dateCheTao;
		}
		
		virtual void input()
		{
			cout<<"Nhap Id: ";
			cin>>id;
			cin.ignore();
			cout<<"Nhap Ten: ";
			getline(cin,name);
			cout<<"Nhap Nha che tao: ";
			getline(cin,nhaCheTao);
			cout<<"Nhap ngay che tao: ";
			cin>>dateCheTao;
			cin.ignore();
		}
		friend istream& operator>>(istream& is,Device &a)
		{
			a.input();
			return is;
		}
		
		virtual void output()
		{
			cout<<"Id: "<<id<<endl;
			cout<<"Ten: "<<name<<endl;
			cout<<"Nha che tao: "<<nhaCheTao<<endl;
			cout<<"Ngay che tao: "<<dateCheTao<<endl;
		}
		friend ostream& operator<<(ostream& os,Device &a)
		{
			a.output();
			return os;
		}
//		virtual toString()=0;
		
};

class Computer :public Device
{
	private:
		string cpu,ram;
	public:
		void setCpu(string cpu)
		{
			this->cpu=cpu;
		}
		string getCpu()
		{
			return cpu;
		}
		void setRam(string ram)
		{
			this->ram=ram;
		}
		string getRam()
		{
			return ram;
		}
		void input()
		{
			Device::input();
			cout<<"Nhap Cpu: ";
			getline(cin,cpu);
			cout<<"Nhap Ram: ";
			getline(cin,ram);
		}
		friend istream& operator>>(istream& is,Computer &a)
		{
			a.input();
			return is;
		}
		void output()
		{
			Device::output();
			cout<<"Cpu: "<<cpu<<endl;
			cout<<"Ram: "<<ram<<endl;
		}
		friend ostream& operator<<(ostream& os,Computer &a)
		{
			a.output();
			return os;
		}
};

class Monitor :public Device
{
	private:
		string size;
	public:
		void setSize(string size)
		{
			this->size=size;
		}
		
		string getSize()
		{
			return size;
		}
		void input()
		{
			Device::input();
			cout<<"Nhap size: ";
			cin>>size;
		}
		friend istream& operator>>(istream& is,Monitor &a)
		{
			a.input();
			return is;
		}
		void output()
		{
			Device::output();
			cout<<"Size: "<<size<<endl;
		}
		friend ostream& operator<<(ostream& os,Monitor &a)
		{
			a.output();
			return os;
		}
};

int main()
{
	int dem=0;
	int tmp=0;
	Device **list=new Device*[5];
	while(dem<=5)
	{
		cout<<"Ban muon nhap Computer(1) hay Monitor(2): ";
		cin>>tmp;
		cin.ignore();
		if(tmp==1)
		{
			list[dem]=new Computer;
			cout<<"Nhap thong tin cho thiet bi thu "<<dem+1<<" : "<<endl;
			cin>>*dynamic_cast<Computer*>(list[dem]);
			
		}
		else if(tmp==2)
		{
			list[dem]=new Monitor;
			cout<<"Nhap thong tin cho thiet bi thu "<<dem+1<<" : "<<endl;
			cin>>*dynamic_cast<Monitor*>(list[dem]);
		}
		else
			break;
		dem++;
				
	}
	
	
	cout<<"Danh sach thiet bi:"<<endl;
	for(int i=0;i<dem;i++)
	{
		cout<<"Thong tin thiet bi thu "<<i+1<<" :"<<endl;
		list[i]->output();
		cout<<"------------"<<endl;
	}
	
}
