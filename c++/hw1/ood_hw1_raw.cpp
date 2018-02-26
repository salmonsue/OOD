#include <fstream>
#include <iostream>

using namespace std;

int main(){
	int temp = 0, code = 0, Max = 0, min = 0;
	int data[3];
	int count = 0;
	int cur_num = 0;

	ifstream fcin("input.txt");
	
	while (fcin >> temp){
		data[count] = temp;
		count++;
	}

/*
	while (count!=0){
		count--;
		cout<<data[count]<<endl;
		
	}
*/	
	min  = data[0];
	Max  = data[1];
	code = data[2];

	while(cur_num!=code){

		cout<<"Please guess an integer number between "<<min<<" and "<<Max<<endl;
		cin>>cur_num;
		
		if((cur_num > code) && (cur_num<= Max)){
			Max = cur_num;
		}
		else if((cur_num < code) && (cur_num >= min)){
			min = cur_num;
		}
		else{
			cout<<"Error!"<<endl;
		}
	}

	return 0;
}