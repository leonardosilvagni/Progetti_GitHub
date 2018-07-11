#include <iostream>
using namespace std;

int main(){
	int array[4][4]={{0,1,2,3},{4,5,6,7},{8,9,10,11},{12,13,14,15}};
	int variable=0;// the first[]is the row
	int compare_array=array;
	string life="";
	while(life!="e"){
		int i,j;//the position of 0
		cin >> life;
		if(life=="w"){
			variable=array[--i][j];
			array[--i][j]=0;
			array[i][j]=variable;
		}else if(life=="a"){
			

			}
	}

} 
