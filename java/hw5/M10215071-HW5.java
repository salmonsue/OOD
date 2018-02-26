import java.util.*;
import java.io.*;

class matrix
{
	private int size;
	private int[][] matrix;

	public matrix()//default constructor
	{
		//System.out.println("matrix()");
		size = 0;
		int[] matrix = new int[size];
	}

	public matrix(int s)
	{
		//System.out.println("matrix(int s)");
		size = s;
		matrix = new int[size][];
		for(int row = 0; row < size; row++)
		{
			matrix[row] = new int[size];
		}
	}
	//copy constructor----------------
	public matrix(final matrix M)
	{
		//System.out.println("matrix(const matrix& M)");
		size = M.size;

		matrix = new int[size][];
		for(int row = 0; row < size; row++)
		{
			matrix[row] = new int[size];
		}
		for(int i=0; i<size; i++)
		{
			for(int j=0; j<size; j++)
				matrix[i][j] = M.matrix[i][j];
		}

	}
	//--------------------------------
	
	//method--------------------------
	public void setElement(int y, int x, int value)
	{
		matrix[y][x] = value;
	}
	public int getElement(int y, int x)
	{
		return matrix[y][x];
	}
	public void printSelf()
	{
		for(int i = 0; i < size; i++){
			for(int j = 0; j < size; j++)
				System.out.print(matrix[i][j]+" ");
			System.out.println();
		}
	}
	void printDataAdd()
	{
		System.out.println(matrix);
	}
}

class HW5
{
	public static void main(String[] args)
	{
		try
		{
			// obtain the matrix size from user
			Scanner in = new Scanner(System.in);
			
			System.out.println("Please input the size of the square matrix.");
			int size = in.nextInt();
			//System.out.println("Input value "+size);
            
            // create the matrix object
			matrix m = new matrix(size);

			// assign the values to the created matrix
			for(int i = 0; i < size; i++)
				for(int j = 0; j < size; j++)
				{
					if(i == j)
						m.setElement(i, j, 10);
					else
						m.setElement(i, j, 1);
				}

			// show the matrix on the screen
			System.out.println("m = ");
			for(int i = 0; i < size; i++)
			{
				for(int j = 0; j < size; j++)
					System.out.print(m.getElement(i, j)+" ");
				
				System.out.println();
			}

			//testing standard constructors
            matrix[] mArr1 = new matrix[10];	//calling default constructor
            for(int i = 0; i < 10; i++)
                mArr1[i] = new matrix();
            matrix m1 = new matrix();			//calling default constructor
			matrix m3 = new matrix(m);			//calling copy constructor
			
			//show the testing matrix objects
            System.out.println("m1= ");
			m.printSelf();
            System.out.println("m3= ");
			m3.printSelf();
			
			
		}catch(InputMismatchException e)
		{
			System.out.println("error");
		}
			
	}
}