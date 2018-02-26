//hw6.cpp

#include <iostream>
#include <assert.h>

using namespace std;

class vector;
// Please provide the matrix class 
class matrix
{
private:
	int size;
	int **mat;
	static int count;
public:
	matrix()
	{	
		count++;
		//cout<<"matrix()"<<endl;
		size = 0;
		mat  = new int*[size];
	}
	matrix(int s)
	{
		count++;
		//cout<<"matrix(int s)"<<endl;
		size = s;
		mat   = new int*[size];
	
		for(int i=0; i<size; i++)
			mat[i] = new int[size];
	}
	//copy constructor------------------------------
	matrix(const matrix& m)		
	{
		count++;
		//cout<<"matrix(const matrixr& m)"<<endl;
		size = m.size;

		mat   = new int*[size];
		for(int i=0; i<size; i++)
			mat[i] = new int[size];
		
		for(int i=0; i<size; i++)
		{
				for(int j=0; j<size; j++)
					mat[i][j] = m.mat[i][j];
		}
	}
	//-----------------------------------------------

	//copy assignment operator-----------------------
	matrix& operator=(const matrix& m)		
	{
		//cout<<"matrix& operator=(const mtarix& m)"<<endl;	
		if(this != &m)
		{
			for(int i=0; i<size; i++)
				delete [] mat[i];

			delete [] mat;
			size = m.size;
			
			mat  = new int*[size];
			for(int i=0; i<size; i++)
				mat[i] = new int[size];
			
			for(int i=0; i<size; i++)
			{
				for(int j=0; j<size; j++)
					mat[i][j] = m.mat[i][j];
			}
			
		}

		return *this;
	}
	//-----------------------------------------------
	~matrix()
	{
		--count;
		//cout<<"~matrix()  size="<<size<<endl;
		for(int i=0; i<size; i++)
			delete [] mat[i];

		delete [] mat;
	}
	static int getCount(){return count;}
	void setElement(int y, int x, int value);
	int getElement(int y, int x);
	void printSelf();

	friend vector VmultM(vector& v, matrix& m);
	friend vector MmultV(matrix& m, vector& v);
};
int matrix::count = 0;

// Please provide the vector class 
class vector
{
private:
	int size;
	int *vec;
	static int count;
public:
	vector()
	{	
		count++;
		//cout<<"matrix()"<<endl;
		size = 0;
		vec  = new int[size];
	}
	vector(int s)
	{
		count++;
		//cout<<"matrix(int s)"<<endl;
		size = s;
		vec  = new int[size];
	
	}
	//copy constructor------------------------------
	vector(const vector& v)		
	{
		count++;
		//cout<<"matrix(const matrixr& m)"<<endl;
		size = v.size;

		vec  = new int[size];
		
		for(int i=0; i<size; i++)
		{
					vec[i] = v.vec[i];
		}
	}
	//-----------------------------------------------

	//copy assignment operator-----------------------
	vector& operator=(const vector& v)		
	{
		//cout<<"matrix& operator=(const mtarix& m)"<<endl;	
		if(this != &v)
		{

			delete [] vec;
			size = v.size;
			
			vec  = new int[size];
			
			for(int i=0; i<size; i++)
			{
					vec[i] = v.vec[i];
			}
			
		}

		return *this;
	}
	//-----------------------------------------------
	~vector()
	{
		--count;
		//cout<<"~matrix()  size="<<size<<endl;
		delete [] vec;
	}
	static int getCount(){return count;}
	static void fixedcount(){--count;}
	void setElement(int x, int value);
	int getElement(int x);
	void printSelf();
	friend vector VmultM(vector& v, matrix& m);
	friend vector MmultV(matrix& m, vector& v);
};
int vector::count = 0;

vector VmultM(vector& v, matrix& m)
{
	vector* vt = new vector(v.size);
	int sum=0;
	for(int y=0; y<v.size; y++){
		for(int x=0; x<v.size; x++)
			sum += v.vec[x] * m.mat[y][x];
		vt->vec[y]=sum;
		sum=0;
	}
	vector::fixedcount();
	return *vt;
}
vector MmultV(matrix& m, vector& v)
{	
	vector* vt = new vector(v.size);
	int sum=0;
	for(int y=0; y<v.size; y++){
		for(int x=0; x<v.size; x++)
			sum += v.vec[x] * m.mat[y][x];
		vt->vec[y] = sum;
		sum=0;
	}
	vector::fixedcount();
	return *vt;
}

int main()
{
	// obtain the matrix size from user
	int size;
	cout<<"Please input the size of the matrix and vector."<<endl;
	cin>>size;

	// create the matrix and vector object
	matrix* m = new matrix(size);
	vector* v = new vector(size);

	// assign the values to the created matrix and vector
	for(int i=0; i<size; i++)
		for(int j=0; j<size; j++)
		{
			if(i==j)
				m->setElement(i,j,10);	
			else
				m->setElement(i,j,1);	
		}

	for(int i=0; i<size; i++)
		v->setElement(i,i+1);


	//show the matrix and vector on the screen
	cout<<"m = "<<endl;
	for(int i=0; i<size; i++)
	{
		for(int j=0; j<size; j++)
			cout<<m->getElement(i,j)<<" ";

		cout<<endl;
	}

	cout<<"v = "<<endl;
	for(int i=0; i<size; i++)
		cout<<v->getElement(i)<<" ";

	cout<<endl;

	//test the standard constructors
	matrix* mArr1 = new matrix[10];	//calling default constructor
	matrix mArr2[5];				//calling default constructor
	matrix m1;						//calling default constructor
	//cout<<"-----------"<<endl;
	matrix* m2 = new matrix(*m);	//calling copy constructor
	matrix m3 = matrix(*m);			//calling copy constructor
	m1 = *m;						//calling copy assignment operator
	vector* vArr1 = new vector[10];	//calling default constructor
	vector vArr2[5];				//calling default constructor
	vector v1;						//calling default constructor
	vector* v2 = new vector(*v);	//calling copy constructor
	vector v3 = vector(*v);			//calling copy constructor
	v1 = *v;						//calling copy assignment operator
	
	//test MmultV and VmultM
	vector ans1 = MmultV(*m,*v);
	cout<<"ans1="<<endl;
	ans1.printSelf();

	vector ans2 = VmultM(*v,*m);
	cout<<"ans2="<<endl;
	ans2.printSelf();

	//test counting object
	cout<<"You have create "<<matrix::getCount()<<" matrices and "
		<<vector::getCount()<<" vectors in this program."<<endl;


	// delete the dynamic allocated object
	delete m;
	delete [] mArr1;
	delete m2;
	delete v;
	delete [] vArr1;
	delete v2;

	//test counting object
	cout<<"After deleting, there are "<<matrix::getCount()<<" matrices and "
		<<vector::getCount()<<" vectors in this program."<<endl;

	return 0;
}

void matrix::setElement(int y, int x, int value)
{
	mat[y][x] = value;
}
int matrix::getElement(int y, int x)
{
	return mat[y][x];
}
void matrix::printSelf()
{
	for(int i=0; i<size; i++)
	{
		for(int j=0; j<size; j++)
			cout<<mat[i][j]<<" ";	//this will not work. correct it

		cout<<endl;
	}
}
void vector::setElement(int x, int value)
{
	vec[x] = value;
}
int vector::getElement(int x)
{
	return vec[x];
}
void vector::printSelf()
{
	for(int i=0; i<size; i++)
	{
		cout<<vec[i]<<" ";	//this will not work. correct it

		cout<<endl;
	}
}