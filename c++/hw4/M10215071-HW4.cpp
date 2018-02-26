//hw4.cpp

#include <iostream>

using namespace std;

// Please provide the matrix class 
class matrix
{
private:
	int size;
	int **mat;
public:
	matrix()
	{
		cout<<"matrix()"<<endl;
		size = 0;
		mat  = new int*[size];
	}
	matrix(int s)
	{
		cout<<"matrix(int s)"<<endl;
		size = s;
		mat   = new int*[size];
	
		for(int i=0; i<size; i++)
			mat[i] = new int[size];
	}
	//copy constructor------------------------------
	matrix(const matrix& m)		
	{
		cout<<"matrix(const matrixr& m)"<<endl;
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
		cout<<"matrix& operator=(const mtarix& m)"<<endl;	
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
		cout<<"~matrix()  size="<<size<<endl;
		for(int i=0; i<size; i++)
			delete [] mat[i];

		delete [] mat;
	}
	
	void setElement(int y, int x, int value);
	int getElement(int y, int x);
	void printSelf();
};


int main()
{
	// obtain the matrix size from user
	int size;
	cout<<"Please input the size of the square matrix."<<endl;
	cin>>size;

	// create the matrix object
	matrix* m = new matrix(size);

	// assign the values to the created matrix
	for(int i=0; i<size; i++)
		for(int j=0; j<size; j++)
		{
			if(i==j)
				m->setElement(i,j,10);	
			else
				m->setElement(i,j,1);	
		}

	// show the matrix on the screen
	cout<<"m = "<<endl;
	for(int i=0; i<size; i++)
	{
		for(int j=0; j<size; j++)
			cout<<m->getElement(i,j)<<" ";

		cout<<endl;
	}

	//testing standard constructors
	matrix* mArr1 = new matrix[10];	//calling default constructor
	matrix mArr2[5];				//calling default constructor
	matrix m1;						//calling default constructor
	matrix* m2 = new matrix(*m);	//calling copy constructor
	matrix m3 = matrix(*m);			//calling copy constructor

	m1 = *m;						//calling copy assignment operator
	
	
	//show the testing matrix objects
	cout<<"m1 = "<<endl;
	m1.printSelf();
	cout<<"*m2 = "<<endl;
	m2->printSelf();
	cout<<"m3 = "<<endl;
	m3.printSelf();


	// delete the dynamic allocated object
	delete m;
	delete [] mArr1;
	delete m2;

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