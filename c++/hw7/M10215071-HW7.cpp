//hw7
#include <iostream>
#include <string.h>

using namespace std;

class Student
{
protected:
	char name[10];
	char dept[5];
	int level;
public:
	Student()
	{
		name[0] = 0;
		dept[0] = 0;
		level = 0;
	}
	Student(char* n, char* sd, int l)
	{
		strcpy(name, n);
		strcpy(dept, sd);
		level = l;
	}
	virtual ~Student()
	{
		//cout<<"~Student()"<<endl;
	}

	//copy constructor------------------------------
	Student(const Student& other)		
	{
		strcpy(name, other.name);
		strcpy(dept, other.dept);
		level = other.level;
	}

	//copy assignment operator-----------------------
	Student& operator=(const Student& m)
	{
		//cout<<"matrix& operator=(const mtarix& m)"<<endl;	
		if(this != &m)
		{
			strcpy(name, m.name);
			strcpy(dept, m.dept);
			level = m.level;
		}

		return *this;
	}
	virtual void print()
	{
		cout<<"Student name = "<<name<<endl;
		cout<<"which deportment is "<<dept<<","<<endl;
		cout<<"which level is "<<level<<endl;
	}
};
class GraduateStudent : public Student
{
protected:
	char lab[10];
public:
	GraduateStudent() : Student(){ lab[0] = 0; }
	GraduateStudent(char* n, char* sd, int l, char* slab)
		: Student(n,sd,l)
	{
		strcpy(lab, slab);
	}
	~GraduateStudent()
	{
		//cout<<"~GraduateStudent()"<<endl;
	}

	//copy constructor------------------------------
	GraduateStudent(const GraduateStudent& other) : Student(other)
	{
		strcpy(lab, other.lab);
	}
	//copy assignment operator-----------------------
	GraduateStudent& operator=(const GraduateStudent& other) 
	{
		//cout<<"matrix& operator=(const mtarix& m)"<<endl;	
		if(this != &other)
		{	
			Student::operator=(other);
			strcpy(lab, other.lab);
		}

		return *this;
	}
	void print()
	{
		cout<<"GraduateStudent name = " <<name<<endl;
		cout<<"which deportment is "<<dept<<","<<endl;
		cout<<"which level is "<<level<<","<<endl;
		cout<<"which Lab is "<<lab<<"."<<endl;
	}
};
class UndergraduateStudent : public Student
{
private:
	int engscore;
public:
	UndergraduateStudent() : Student(){ engscore = 0; }
	UndergraduateStudent(char* n, char* sd, int l, int engpoint)
		: Student(n, sd, l)
	{
		engscore = engpoint;
	}
	~UndergraduateStudent()
	{
		//cout<<"~UndergraduateStudent()"<<endl;
	}

	//copy constructor------------------------------
	UndergraduateStudent(const UndergraduateStudent& other)	: Student(other)
	{
		engscore = other.engscore;
	}
	//copy assignment operator-----------------------
	UndergraduateStudent& operator=(const UndergraduateStudent& other) 
	{
		//cout<<"matrix& operator=(const mtarix& m)"<<endl;	
		if(this != &other)
		{	
			Student::operator=(other);
			engscore = other.engscore;
		}

		return *this;
	}
	int getengscore(){ return engscore; }

	void print()
	{
		cout<<"UndergraduateStudent name = "<<name<<endl;
		cout<<"which deportment is "<<dept<<","<<endl;
		cout<<"which level is "<<level<<","<<endl; 
		cout<<"which English score is "<<engscore<<endl;
	}	
};
class MasterStudent : public GraduateStudent
{
private:
	char research[10];
public:
	MasterStudent() : GraduateStudent(){ research[0] = 0; }
	MasterStudent(char* n, char* sd, int l, char* lab, char* rech)
		: GraduateStudent(n, sd, l, lab)
	{
		strcpy(research, rech);
	}
	~MasterStudent()
	{
		//cout<<"~MasterStudent()"<<endl;
	}

	//copy constructor------------------------------
	MasterStudent(const MasterStudent& other) : GraduateStudent(other)
	{
		strcpy(research, other.research);
	}
	//copy assignment operator-----------------------
	MasterStudent& operator=(const MasterStudent& other)
	{
		//cout<<"matrix& operator=(const mtarix& m)"<<endl;	
		if(this != &other)
		{	
			//Student::operator=(other);
			GraduateStudent::operator=(other);
			strcpy(research, other.research);
		}

		return *this;
	}
	void print()
	{ 
		cout<<"MasterStudent name = " << name <<endl;
		cout<<"which deportment is "<<dept<<","<<endl;
		cout<<"which level is "<<level<<","<<endl;
		cout<<"which Lab is "<<lab<<"."<<endl;
		cout<<"which research is"<<research<<"."<<endl;

	}
};
class PhDStudent : public GraduateStudent
{
protected:
	char mresearch[10];
public:
	PhDStudent() : GraduateStudent(){ mresearch[0] = 0; }
	PhDStudent(char* n,char* sd, int l, char* lab, char* mrech)
		: GraduateStudent(n, sd, l, lab)
	{
		strcpy(mresearch, mrech);
	}
	~PhDStudent()
	{
		//cout<<"~PhDStudent()"<<endl;
	}

	//copy constructor------------------------------
	PhDStudent(const PhDStudent& other) : GraduateStudent(other)
	{
		strcpy(mresearch, other.mresearch);
	}
	//copy assignment operator-----------------------
	PhDStudent& operator=(const PhDStudent& other)
	{
		//cout<<"matrix& operator=(const mtarix& m)"<<endl;	
		if(this != &other)
		{	
			//Student::operator=(other);
			GraduateStudent::operator=(other);
			strcpy(mresearch, other.mresearch);
		}

		return *this;
	}
	void print()
	{ 
		cout<<"PhDStudent name = " << name <<endl; 
		cout<<"which deportment is "<<dept<<","<<endl;
		cout<<"which level is "<<level<<","<<endl;
		cout<<"which Lab is "<<lab<<"."<<endl;
		cout<<"which research is "<<mresearch<<endl;
	}
};
class FullTimeStudent : public UndergraduateStudent
{
protected:
	char doubledept[5];
public:
	FullTimeStudent() :UndergraduateStudent(){ doubledept[0] = 0; }
	FullTimeStudent(char* n, char* ddept, char* sd, int l, int epoint) 
		: UndergraduateStudent(n, sd, l, epoint)
	{
		strcpy(doubledept, ddept);
	}
	~FullTimeStudent()
	{
		//cout<<"~FullTimeStudent()"<<endl;
	}

	//copy constructor------------------------------
	FullTimeStudent(const FullTimeStudent& other) : UndergraduateStudent(other)
	{
		strcpy(doubledept, other.doubledept);
	}
	//copy assignment operator-----------------------
	FullTimeStudent& operator=(const FullTimeStudent& other)
	{	
		if(this != &other)
		{
			//Student::operator=(other);
			UndergraduateStudent::operator=(other);
			strcpy(doubledept, other.doubledept);
		}
		return *this;
	}
	void print()
	{
		cout<<"FullTimeStudent name = " << name <<endl; 
		cout<<"which deportment is "<<dept<<","<<endl;
		cout<<"which is "<<doubledept<<"double major,"<<endl;
		cout<<"which level is "<<level<<","<<endl; 
		cout<<"which English score is "<<getengscore()<<endl;
	}
};
class PartTimeStudent : public UndergraduateStudent
{
private:
	char co[20];
protected:
	double salary;
public:
	PartTimeStudent(): UndergraduateStudent(){ co[0] = 0; salary = 0; }
	PartTimeStudent(char* n, char* wco, double s, char* sd, int l, int epoint)
		: UndergraduateStudent(n, sd, l, epoint)
	{
		strcpy(co, wco);
		salary = s;
	}
	~PartTimeStudent()
	{
		//cout<<"~PartTimeStudent()"<<endl;
	}

	//copy constructor------------------------------
	PartTimeStudent(const PartTimeStudent& other) : UndergraduateStudent(other)
	{
		strcpy(co, other.co);
		salary = other.salary;
	}
	//copy assignment operator-----------------------
	PartTimeStudent& operator=(const PartTimeStudent& other)
	{
		//cout<<"matrix& operator=(const mtarix& m)"<<endl;	
		if(this != &other)
		{
			//Student::operator=(other);
			UndergraduateStudent::operator=(other);
			strcpy(co, other.co);
			salary = other.salary;
		}

		return *this;
	}
	//char* getco(){return co;}
	void print()
	{
		cout<<"PartTimeStudent name = " <<name<<endl; 
		cout<<"which deportment is "<<dept<<","<<endl;
		cout<<"which level is "<<level<<","<<endl; 
		cout<<"which English score is "<<getengscore()<<endl;
		cout<<"which company is "<<co<<" and salary is "<<salary<<"."<<endl;
	}
};

int main()
{
	int i;
	UndergraduateStudent p1("AA","BB",1,720);
	GraduateStudent p2("Mark","CSIC",1,"RB505");
	FullTimeStudent p3("Alice","not","MIS",2,550);
	PartTimeStudent p4("Jason","Google",65000,"EMBA",3,880);
	MasterStudent p5("Jay","CSIC",1,"RB303","network");
	PhDStudent p6("Jeff","CSIC",3,"RB305","network");

	p1.print();
	Student* p[6] = {&p1, &p2, &p3, &p4, &p5, &p6};
	for(i=0; i<6; i++)
		p[i]->print();
	cout<<"------------ ------------"<<endl;
	PhDStudent c1 = p6;
	PartTimeStudent c2(p4);
	PartTimeStudent c3;
	c3 = p4;
	c1.print();
	c2.print();
	cout<<"-------------------------"<<endl;
	c3.print();
	return 0;
}