#include<iostream>
#include<fstream>
#include <stdlib.h>
using namespace std;



int Length(char S[]){
	
	int count=0; 												
	for(int  i = 0 ; S[i] != '\0' ; i++){										// TO count the character of word //
		count++;
	}
	
	return count;
	
}

	void Data()
	{
		ifstream file("Input.txt");															// Give Daata of file
		
		int r,c,words;																								
		char K[40];
			
		file>>r;
	cout<<"\nRows = "<<r;
	
	file>>c;
	cout<<"\nCols = "<<c;


	file>>words;
	
	cout<<"\nWords = "<<words <<"\n\n";
	for(int i =0 ; i< words ; i++){
	
	file>>K;
	cout<<K<<endl;
	}
	
	
	
	}
	
	void Data2()
	{
		ifstream file2("Data.txt");
		
		int r,c,cases;
		
		file2>>r;
		file2>>c;
		file2>>cases;
		cout<<"\nRows = "<<r;										//Give Data of file 2
		cout<<"\nCols = "<<c;
		cout<<"\nCases = "<<cases;
		cout<<"\n\n\n";
		

		
	}

void Inserting_word( char S[] , char A [40][40] , int &r , int &c , int &value){
	
	
	int count= Length(S);
	
	if(value==1){

	int c1=0;
	for( int i = 2 ; c1<count ; i++){														// Place word1 Vertically //
		 	int j =2;
			A[i][j]=S[c1];
			c1++;
			
									}
	cout<<endl;
	cout<<endl;
	//i++;
	//j++;
			}


if(value==2){
int c2=0;
for( int i = 2 ; c2<count ; i++){														// Place Word2 HOrizontally //
		int  j = 0;
		A[j][i]=S[c2];
		c2++;
		
}
cout<<endl;
	//i++;
	//j++;
}


if(value==3){

int c3=0;
	for( int  i = 17 , j=7 ; c3<count ; i-- ,j++)
{																								// Place word3 RIght Diagonaal //
		
		A[i][j]=S[c3];
		c3++;
}
cout<<endl;
	//i++;
	//j++;
}

if(value==4){
	
int c4=0 ;

for( int i = 11 , j=11 ; c4<count ; j--, i-- ){												// Place word4 Left Diagonally //
	A[i][j]=S[c4];
	c4++;
}
cout<<endl;
	//i++;
	//j++;
	
}

if(value==5){
	int c5=0;
for( int i = 17 ; c5<count ; i--){														// Place word5 Vertically ///
		int  j = 0;
		A[i][j]=S[c5];
		c5++;
		
}
cout<<endl;	
	
}

if(value==6){
int c6=0;
for( int i = 13 ; c6<count ; i++){														// Place Word2 HOrizontally //
		int  j = 3;
		A[j][i]=S[c6];
		c6++;
		
}
	//i++;
	//j++;
}}


void RandomGrid(int r , int c , char A[40][40]){
	cout<<"\n\n------------------------------ RANDOM GRID ---------------------------------- \n\n";
	
		int x ;
	
	for( int i =0 ; i<r ; i++){
		for(int j =0 ; j<c ;j++){	
			 x = rand() % 26; // generate a random number.														// Makes a grid of Random Words  // 
			A[i][j]='A'+x;
			cout<<A[i][j]<<" ";
								}
		cout<<endl;
							  }
	
	
}

void NewGrid(ofstream &file ,int r , int c, char A[40][40]){
	
		cout<<"------------------------------ NEW GRID ---------------------------------- \n\n";
	for( int i =0 ; i<r ; i++){
		for(int j =0 ; j<c ;j++){			
			cout<<A[i][j]<<" ";										// Show new grid after adding name in grid //
			file<<A[i][j]<<" ";
								}																
			cout<<endl;
			file<<endl;
					}
}

int Horizontal (ofstream & file ,char A[40][40], char S[],int r, int c ){
	
	int Len=Length(S);
    int count=0;
    int index =0 , col=0 , col1=0 ;
    
	for(int i=0 ; i<r ; i++){
		for(int j=0 ; j<c ; j++){
		
		
				if( S[0] == A[i][j] )
			{
					count=0;
		             col=j;
			for(int k=0 ; k< Len ; k++)												// HOrizintal CHeck
			{
				if( S[k] == A[i][j] )
				{
					index=i;
 					count++;
	      	        col1=j;
					  j++; 		
				}	
			}
			if(count== Len)
		//	cout<<"found "<<" at {"<<index<<" "<<col<<"}"<<", {"<<index<<" "<<col1<<"}"<<endl;
			file<<"found "<<" at {"<<index<<" "<<col<<"}"<<", {"<<index<<" "<<col1<<"}"<<endl;
			return 0;
			}
		
			
}
}
}





 int Vertical ( ofstream &file , char A[40][40] , char S[] , int r , int c )	{
 	
		int 	count=0,index=0,col=0,col1=0;
		int 	Len=Length(S);
	
		
		for(int j=0; j<c ;j++)
	{
		for(int i=0 ; i<r ; i++)
		{
			count=0;
			if(S[0]==A[i][j])
			{
				col=i;
		      for(int k=0; k<Len ;k++)
			  {
			  	if(S[k]==A[i][j])
			  	{
			  		index=j;	
			  		count++;
			  		col1=i;
			  		i++;	  		                  // Vertical check 
				}
			  }		
				if(Len==count)
				{
		//	cout<<"Found"<<" at{"<<col<<" "<<index<<"}"<<",{"<<col1<<" "<<index<<"}"<<endl;
		file<<"Found"<<" at{"<<col<<" "<<index<<"}"<<",{"<<col1<<" "<<index<<"}"<<endl;
		return 0;
				}
			}	
		}		
	}
		
		
	}
			
			
int Diagonal (ofstream &file , char A[40][40]  , char S[] , int r , int c){
				
		int col2;
	 	int count=0,index=0,col=0,col1=0;
		int Len=Length(S);
		
		for( int i =0 ; i<r ; i++){
			for( int j=0 ; j<c ; j++){
			
		
		int m=0;
		int na=0;
		m=i;
	
			na=j;
			count=0;																						// Diagonal CHeck 
			if(S[0] == A[i][j])
			{
				col=i;
				index=j;	
		      for(int k=0 ; k<Len ;k++)
			  {
			  	if( S[k] == A[i][j])
			  	{
			  	
			  		count++;
			  		col1=i;
			  		col2=j;
			  		i++;
			  		j++;
				}  	
				  if(S[k]==A[i][j] && S[k+1]==A[i-1][j-1] )
			  	{
			  	
			  		count++;
			  		col1=i;
			  		col2=j;
			  		i--;
			  		j--;
				}
			  	  if(S[k]==A[i][j] && S[k+1]==A[i+1][j-1])
			  	{
			  	
			  		count++;
			  		col1=i;
			  		col2=j;
			  		i++;
			  		j--;
				}		  	
					  }		
				if(Len==count)
				{
	//		cout<<"Coordinates are: "<<" {"<<col<<" "<<index<<"}"<<", {"<<col1<<" "<<col2<<"}"<<endl;
		file<<"Coordinates are: "<<" {"<<col<<" "<<index<<"}"<<", {"<<col1<<" "<<col2<<"}"<<endl;	
			return 0;
				
				}
			
				}
			}
			}
				
		}	
		
		void ReadGrid(ifstream &fin , int r , int c , char A[40][40] ){
			for(int i=0 ; i<r ;i++){
		for(int j=0 ; j<c ;j++){
			fin>>A[i][j];
			cout<<A[i][j]<<" ";
		}
		cout<<endl;
		
	}
	
		}

int main(){
	

	
	
	
	
		cout<<"------------------------------------------------------------------------------------------------------------------------\n\n";
		cout<<"------------------------------------------------------------------------------------------------------------------------\n";
		cout<<"\n\n";
		cout<<"                                ~~~~~~~~ WORD SEARCH GAME !!!!  ~~~~~~~~~~                                                                                     ";
		cout<<"\n\n------------------------------------------------------------------------------------------------------------------------\n\n";
		cout<<"------------------------------------------------------------------------------------------------------------------------\n";
	
	cout<<"\n Choose one option ";
	
			cout<<"\n\n                      1- Create a Grid(Enter C)      \n";
			cout<<"\n\n                      2- Search a Word(Enter S)      \n";
			cout<<"\n\n                      3- Exit(Enter Q)     \n";
	
		char Menu;
		cout<<"\nEnter : ";
		cin>>Menu;	
		cout<<endl<<endl;
	if(Menu=='C'){



	int r,c,words;
	char A[40][40];
	char S[30];
	char K[30];
	
	ifstream fin ;
	char filename[50];																		// Asking file naeme from user
	cout<<"Enter Input File name : ";
	cin>>filename;
	
	fin.open(filename);																						// open file
	Data();														// Gives Data like rows cols 
	cout<<endl;
	ofstream file;
	char filename2[50];
	cout<<"Enter Output File name : ";
	cin>>filename2;
	file.open(filename2);
	
	
	
	int wordcount=1;
	fin>>r;
	fin>>c;
	fin>>words;
	
	

	
	RandomGrid(r,c,A);									// mAKES RANDOM GRID
	while(!fin.eof()){
		fin>>S;
		Inserting_word(S,A,r,c,wordcount);																// Read NAme from file and PUt into grids // 
		wordcount++;
					}
	NewGrid(file,r,c,A);										// mAKE NEW GRID AFTER INSRETON OF WORDS
	
				}			
					
					
					
					
					
	else	if(Menu=='S'){
						
	ifstream fin;
	
	char filename[50];
	cout<<"Enter Input File name : ";																					// Asking file name
	cin>>filename;
	
	fin.open(filename);																								/// open file
	
	int r,c,TWords,count=0;
	char A[40][40];
	char S[30];
	int size=Length(S);
	
	Data2();																// gives data
	
	cout<<endl;
	ofstream file;
	char filename2[50];
	cout<<"Enter Output File name : ";
	cin>>filename2;
	file.open(filename2);
	
	fin>>r;
	
	fin>>c;

	fin>>TWords;

	
	ReadGrid(fin,r,c,A);															// Read grid from file n print it
				int x =0 ;		
						cout<<"\n\n------------------------------ SERACHING WORD ----------------------------- \n\n";
	
	while(x<=TWords){
	
	
	cin.getline(S,30);
	Horizontal(file,A,S,r,c);											/// Searching horizonatlly vertically diagnallly
	Vertical(file,A,S,r,c);
	Diagonal(file,A,S,r,c);
	cout<<endl<<endl;
	x++;

}



					}
					
					
					
					

	else	if( Menu=='Q')
	{
		cout<<" ---------------------------------- Exiting ------------------------------------- \n";
		return 0;
		
	}
	
	else{
		cout<<"          Inavlid Option selected from menu !!          ";
		return -1;
	}
	
	
	
	
	
	
}
