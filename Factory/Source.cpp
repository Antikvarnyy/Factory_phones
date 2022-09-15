#include<iostream>
#include<vector>;
using namespace std;


class Flagman
{
public:
	virtual void info() = 0;
	virtual ~Flagman() {};
};
class Normal
{
public:
	virtual void info() = 0;
	virtual ~Normal() {};
};
class Budget
{
public:
	virtual void info() = 0;
	virtual ~Budget() {};
};

class SamsungS21 : public Flagman
{
public:
	void info() override
	{
		cout << "Samsung S21" << endl;
	}
};
class SamsungA32 :public Normal
{
public:
	void info() override
	{
		cout << "Samsung A32" << endl;
	}

};
class SamsungA02 : public Budget
{
public:
	void info() override
	{
		cout << "Samsung A02" << endl;
	};
};

class Iphone13 : public Flagman
{
public:
	void info() override
	{
		cout << "Iphone 13" << endl;
	}
};
class Iphone10 :public Normal
{
public:
	void info() override
	{
		cout << "Iphone 10" << endl;
	}

};
class Iphone7 : public Budget
{
public:
	void info() override
	{
		cout << "Iphone 7" << endl;
	};
};

class PhoneFactory
{
public:
	virtual	Flagman* createFlagman() = 0;
	virtual	Normal* createNormal() = 0;
	virtual	Budget* createBudget() = 0;
	virtual ~PhoneFactory() {};

};

class SamsungPhoneFactory : public PhoneFactory
{
public:
	Flagman* createFlagman()
	{
		return new SamsungS21;
	}
	Normal* createNormal()
	{
		return new SamsungA32;
	}
	Budget* createBudget() {
		return new SamsungA02;
	}
};


class ApplePhoneFactory : public PhoneFactory
{
public:
	Flagman* createFlagman()
	{
		return new Iphone13;
	}
	Normal* createNormal()
	{
		return new Iphone10;
	}
	Budget* createBudget() {
		return new Iphone7;
	}
};

class Phone
{
public:
	vector<Flagman* > vi;
	vector<Normal* > va;
	vector<Budget* > vh;
	~Phone()
	{
		int i;
		for (i = 0; i < vi.size(); i++) delete vi[i];
		for (i = 0; i < va.size(); i++) delete va[i];
		for (i = 0; i < vh.size(); i++) delete vh[i];

	}
	void info()
	{
		int i;
		for (i = 0; i < vi.size(); i++)  vi[i]->info();
		cout << "\n";
		for (i = 0; i < va.size(); i++)  va[i]->info();
		cout << "\n";
		for (i = 0; i < vh.size(); i++)  vh[i]->info();

	}
};

class Fabric
{
public:
	Phone* createPhone(PhoneFactory& factory, int f, int n, int b)
	{
		Phone* p = new Phone;
		for (int i = 0; i < f; i++) {
			p->vi.push_back(factory.createFlagman());
		}
		for (int i = 0; i < n; i++) {
			p->va.push_back(factory.createNormal());
		}
		for (int i = 0; i < b; i++) {
			p->vh.push_back(factory.createBudget());
		}
		return p;
	}
};

int main()
{
	int fs, ns, bs, fa, na, ba;

	Fabric fabric;
	SamsungPhoneFactory sam_factory;
	ApplePhoneFactory ios_factory;


	cout << "Enter number of Samsung flagmans: ";
	cin >> fs;
	cout << "Enter number of Samsung normal phones: ";
	cin >> ns;
	cout << "Enter number of Samsung budget phones: ";
	cin >> bs;
	cout << "Enter number of Apple flagmans: ";
	cin >> fa;
	cout << "Enter number of Apple normal phones: ";
	cin >> na;
	cout << "Enter number of Apple budget phones: ";
	cin >> ba;

	system("cls");

	Phone* sam = fabric.createPhone(sam_factory, fs, ns, bs);
	Phone* ios = fabric.createPhone(ios_factory, fa, na, ba);

	cout << "Samsung: " << "\n";
	cout << "\n";
	sam->info();
	cout << "\n";
	cout << "\Apple: " << "\n";
	cout << "\n";
	ios->info();
}