import java.util.*;
import java.io.*;

class test
{
	public static void main(String[] args)
	{
		try
		{
			
			FileReader inputFile = new FileReader("input.txt");			
			Scanner ifile = new Scanner(inputFile);
				
			int[] buffer = new int[3];
			int code = 0, Max = 0, min = 0;
			int count = 0;
 
			while( ifile.hasNext() )
			{
				buffer[count] = ifile.nextInt(); 
				System.out.println(count+"is"+buffer[count]);
				count++;
			}
			
			min  = buffer[0];
			Max  = buffer[1];
			code = buffer[2];

			int cur_num = 0;

			Scanner in = new Scanner(System.in);
			
			while(cur_num!=code){

				System.out.println("Please guess an integer number between "+min+" and "+Max);
				cur_num = in.nextInt();
		
				if((cur_num > code) && (cur_num<= Max)){
					Max = cur_num;
				}
				else if((cur_num < code) && (cur_num >= min)){
					min = cur_num;
				}
				else{
					System.out.println("Error!");
				}

			}
			
		}catch(IOException e)
		{}
	
	}
}