#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int main(){

	int Strsize = 0, Strcont = 0;
	
	cout<<"Please input the max number of words to be stored."<<endl;
	cin>>Strsize;
	if(Strsize == 0) return 0;

	char (*strarray)[20] = new char[Strsize][20];
	
	string str,temp;

	cout<<"Please input the word, or the command (print/exit):";

	while(cin>>str){
		
		if(str == "print"){
			
			for(int i = 0; i < Strcont; i++){
				for(int j = 0; j < Strsize; j++){
					cout<<strarray[i][j];
				}
				cout<<" ";
			}
			cout<<endl;
			
		}
		else if(str == "exit"){
			break;
		}
		else if(Strcont == Strsize){
			cout<<"The array is full!"<<endl;
			
		}
		else{
			//store
			if(str.size() <= 20){
				for(int j = 0; j < Strsize; j++){
					strarray[Strcont][j]=str[j];
				}
			}
			
			Strcont++;
			//sort
			int i, j;
			for (j = Strcont - 1; j > -1; j--) {
				for (i = 0; i < j; i++)
					if (strarray[i][0] > strarray[i + 1][0] ){
						for(int z = 0; z < Strsize; z++){
							temp[z] = strarray[i][z];
							strarray[i][z] = strarray[i+1][z];
                			strarray[i+1][z] = temp[z];
						}
					}
			}
			/*for (i = Strcont - 1; i > 0; i--){
        		for (j = 0; j <= i - 1; j++){

        			cout<<"before if "<<strarray[j][0] << strarray[j+1][0]<<endl;
            		if (strarray[j][0] < strarray[j+1][0]){
                		
                		for(int z = 0; z < Strsize; z++){
							temp[z] = strarray[j][z];
							strarray[j][z] = strarray[j+1][z];
                			strarray[j+1][z] = temp[z];
						}
						cout<<"in if "<<strarray[j][0] << strarray[j+1][0]<<endl;
                		//temp = strarray[j];
                		//strarray[j] = strarray[j+1];
                		//strarray[j+1] = temp;
            		}

        		}
    		}
			*/
    		
			
		}

		cout<<"Please input the word, or the command (print/exit):";
	}

	delete [] strarray;

	return 0;
}