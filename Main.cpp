#include <iostream>
#include<fstream>
#include<conio.h>
using namespace std;
struct di {
	int x;
	int y;
}d;
int pcount = 0;
class c {
protected:
	int**board;
	string n;
public:
	c() :board(0) {}
	c(int p1,string n1){
	  board=newfile(board);    // for new game
	}
	c(int p) {                      // for saved game
		board = file(board);
	}
	c(char k) {}
	void out() {
		//5 for hook
		//4 for knights
		//3 for bishops
		//1 for kings
		//2 for queen
		//6 for pawn

		for(int i=7;i>=0;i--){
			cout<<endl;
			int j;
			for(int k=0;k<=13;k++){
			
			cout<<"___";
			}
			cout<<i;
			cout<<endl;
			for( j=7;j>=0;j--){
				if(board[i][j]==5){
				
				cout<<"| "<<"wR"<<" ";
				}
				else if(board[i][j]==-5){
				
				cout<<"| "<<"bR"<<" ";
				}
				else if(board[i][j]==-4){
				
				cout<<"| "<<"bN"<<" ";
				}
				else if(board[i][j]==4){
				
				cout<<"| "<<"wN"<<" ";
				}
				else if(board[i][j]==-3){
				
				cout<<"| "<<"bB"<<" ";
				}
				else if(board[i][j]==3){
				
				cout<<"| "<<"wB"<<" ";
				}
				else if(board[i][j]==-2){
				
				cout<<"| "<<"bQ"<<" ";
				}
			else if(board[i][j]==2){
				
				cout<<"| "<<"wQ"<<" ";
				}
			else if(board[i][j]==-1){
				
				cout<<"| "<<"bK"<<" ";
				}
			else if(board[i][j]==1){
				
				cout<<"| "<<"wK"<<" ";
				}
			else if(board[i][j]==-6){
				
				cout<<"| "<<"bP"<<" ";
				}
			else if(board[i][j]==6){
				
				cout<<"| "<<"wP"<<" ";
				}
			//cout<<"| "<<board[i][j]<<" ";
			else if(board[i][j]==0){
			
			    cout<<"| "<<"  "<<" ";
			}
			}
			
			cout<<"|";
		   	
		}
		cout<<endl;
		
		for(int j=0;j<=10;j++){
			
			cout<<"___";
			}
       	
		cout << endl;

		for (int j = 0;j <= 10;j++) {

			cout << "_____";
		}
		cout<<endl;
	}
	void empty(int**b) {

		cout << endl;
		cout << "Empty Postions:";
		for (int i = 0;i <= 7;i++) {

			for (int j = 0;j <= 7;j++) {

				if (b[i][j] == 0) {

					cout << "(" << i << "," << j << ")";
				}
			}

		}


	}
	void savefilecaller(){
	    savefile(board);
	}
	friend void savefile(int**b);
	friend int**file(int**b);
	friend int**newfile(int**b1);
};
void savefile(int**b2){
	remove("chess.txt");
    ofstream output;
	output.open("chess.txt");
	for (int i = 0;i <= 7;i = i + 7) {

		 output<<b2[0][i]<<" ";       // rooks white
	}
	output<<" ";
	for (int i = 1;i <= 6;i = i + 5) {
		output<<b2[0][i]<<" ";          //knights white
	}
	output<<" ";
    for (int i = 2;i <= 5;i = i + 3) {
		output<<b2[0][i]<<" ";		// bishops white
	}
	output<<" ";
	output<<b2[0][3]<<" ";                    // white king
	output<<b2[0][4]<<" ";                     //white queen
	for (int i = 0;i <= 7;i++) {
		output<<b2[1][i]<<" ";              // white pawns
	}
	output<<" ";

	for (int i = 0;i <= 7;i = i + 7) {
		output<<b2[7][i]<<" ";       // rooks black
	}
	output<<" ";
	for (int i = 1;i <= 6;i = i + 5) {
	 output<<b2[7][i]<<" ";          //black knight
	}
	output<<" ";
	for (int i = 2;i <= 5;i = i + 3) {
		output<<b2[7][i]<<" "; // bishops black
	}
	output<<" ";
	 output<<b2[7][3]<<" ";                    // black King
     output<<b2[7][4]<<" ";		                             //black Queen
	 for (int i = 0;i <= 7;i++) {

		output<<b2[6][i]<<" ";              // black pawns
	}
	 output<<" ";
	for (int i = 2;i <= 5;i = i + 1) {
		for (int j = 0;j <= 7;j++) {
			
			output<<b2[i][j]<<" ";
		}
	}


}
int**newfile(int**b1){
    b1=new int*[8];
	for (int i = 0;i<8;i++) {
		b1[i] = new int[8];
	}
	for (int i = 0;i <= 7;i = i + 7) {

		 b1[0][i]=5;;       // rooks white
	}
	for (int i = 1;i <= 6;i = i + 5) {
		b1[0][i]=4;          //knights white
	}
    for (int i = 2;i <= 5;i = i + 3) {
		b1[0][i]=3;		// bishops white
	}
	b1[0][3]=1;                    // white king
	b1[0][4]=2;                     //white queen
	for (int i = 0;i <= 7;i++) {
		b1[1][i]=6;              // white pawns
	}


	for (int i = 0;i <= 7;i = i + 7) {
		b1[7][i]=-5;       // rooks black
	}
	for (int i = 1;i <= 6;i = i + 5) {
	 b1[7][i]=-4;          //black knight
	}
	for (int i = 2;i <= 5;i = i + 3) {
		b1[7][i]=-3; // bishops black
	}
	 b1[7][3]=-1;                    // black King
     b1[7][4]=-2;		                             //black Queen
	 for (int i = 0;i <= 7;i++) {

		b1[6][i]=-6;              // black pawns
	}

	for (int i = 2;i <= 5;i = i + 1) {
		for (int j = 0;j <= 7;j++) {
			b1[i][j] = 0;
		}
	}
	return b1;
}
int**file(int**b) {
	ifstream   input;
	input.open("chess.txt");
	b = new int*[8];
	for (int i = 0;i<8;i++) {
		b[i] = new int[8];
	}
	for (int i = 0;i <= 7;i = i + 7) {

		input >> b[0][i];       // rooks white
	}
	for (int i = 1;i <= 6;i = i + 5) {
		input >> b[0][i];          //knights white
	}
	for (int i = 2;i <= 5;i = i + 3) {

		input >> b[0][i];		// bishops white
	}
	input >> b[0][3];                    // white queen
	input >> b[0][4];		                             //white king

	for (int i = 0;i <= 7;i++) {

		input >> b[1][i];              // white pawns
	}

	for (int i = 0;i <= 7;i = i + 7) {
		input >> b[7][i];       // rooks black
	}
	for (int i = 1;i <= 6;i = i + 5) {
		input >> b[7][i];          //black white
	}
	for (int i = 2;i <= 5;i = i + 3) {
		input >> b[7][i];	// bishops black
	}
	input >> b[7][3];                    // black queen
	input >> b[7][4];		                             //black king


	for (int i = 0;i <= 7;i++) {

		input >> b[6][i];              // black pawns
	}

	for (int i = 2;i <= 5;i = i + 1) {
		for (int j = 0;j <= 7;j++) {
			input>>b[i][j];
		}
	}

	return b;
}
class checkmate{

  
public:
	checkmate(){}
	int**checkmateblackpawn(int i,int j,int**t){
	     
	      t[i][j]=-6;
			  return t;
	
	
	} 

     int**checkmatewhitepawn(int i,int j,int**t){
	     
	      t[i][j]=+6;
			  return t;
	
	
	} 

	 int**checkmatewhitequeen(int i,int j,int**t1){
	           t1[i][j]=+2;
	              return t1;
	 }





};


class players :public checkmate,public c {
	int play;


public:
	~players(){
	
	cout<<"Destructor called"<<endl;
	}
	players(int p) :play(p), c(play) {
	}
	players(int p1,string n):play(p1),c(p1,n){}
	players() {
	}
	void plays() {
		out();
			 char sel;
		cout << "Enter E to end game" << endl;
		cout << "White Player Turn:" << endl;
		cout << "For Selecting Pawn Press 6:" << endl;
		cout << "For Selecting Hook  Press 5:" << endl;
		cout << "For Selecting Knight Press 4:" << endl;
		cout << "For Selecting Bishop Press 3:" << endl;
		cout << "For Selecting Queen Press 2;" << endl;
		cout << "For Selecting King Press 1:" << endl;
		sel = _getch();

		if (sel == '6') {
			wpawn(pcount);
		}
		pcount++;
		if(sel=='5'){
		  whook();
		}
		if(sel=='3'){
		    wbis();
		}
			if(sel=='2'){
		    wqueen();
		}
	}
	void wpawn(int pc){
	
	int wpcount=0;
	int checkpc=0;
		cout<<endl<<"White Pawns are present at positions:"<<endl;
		for(int i=0;i<=7;i++){
			for(int j=0;j<=7;j++){
				if(board[i][j]==+6){
				cout<<"("<<i<<","<<j<<")";
				wpcount++;
				}
			}
		}
		cout<<endl;
		int**wpc=new int*[wpcount];
		for(int i=0;i<wpcount;i++){
		  wpc[i]=new int[2];
		}
		cout<<"Moveable White Pawns:"<<endl;
		int k=0;
		for(int i=0;i<=7;i++){
			for(int j=0;j<=7;j++){
				if(board[i][j]==+6){
					if(board[i+1][j]==0){
					cout<<"("<<i<<","<<j<<")"<<" ";
					   wpc[k][0]=i;
					   wpc[k][1]=j;
					   k++;
					}


					if(board[i+1][j+1]<-1 && i!=7 && j!=7){
					
					/*cout<<"Positions to knockout Opponent piece"<<endl;
			
					cout<<"("<<i-1<<","<<j-1<<")";*/
		            checkpc++;
					}
					if (board[i+1][j-1]<-1  && i!=7 && j!=7)
					{
					//	cout<<"("<<i-1<<","<<j+1<<")";
		//			cout<<endl;
		            checkpc++;
					
					}

		
				
				}
			

			}
		}
		cout<<endl;
		di*bo=new di[checkpc]; // to store coordinates required to kockout opponent piece
		int x=0;
		cout<<endl;
		for(int i=0;i<=7;i++){
			for(int j=0;j<=7;j++){
				if(board[i][j]==6){

					if(board[i+1][j+1]<-1 && i!=7 && j!=7){
				
						cout<<"Positions to knockout Opponent piece:";
			
					cout<<"("<<i+1<<","<<j+1<<")"<<" ";

						bo[x].x=i+1;
					bo[x].y=j+1;
				   x++;	
					}
					if(board[i+1][j-1]<-1 && i!=7 && j!=7 && j!=0){
						cout<<"("<<i+1<<","<<j-1<<")";
						bo[x].x=i+1;
					bo[x].y=j-1;
					x++;
					}}}}

		di bd[8];
		cout<<endl<<"Enter Coordinates from above mentioned movable postions:"<<endl;
		cout<<"X:";
		cin>>bd[0].x;
		cout<<endl<<"Y:";
		cin>>bd[0].y;
		bool check3=false;
		bool check4=false;
		bool check1=false;
		bool check2=false;
		int ground=1;
		//cout<<bpcount<<endl;
		for(int j=0;j<checkpc;j++)
		{
		
			if(bo[j].x==bd[0].x){
			  check3=true;
			}
			if(bo[j].y==bd[0].y){
			  check4=true;
			}

			if(check3==true && check4==true){
		
		     board=checkmatewhitepawn(bo[j].x,bo[j].y,board);  
			 ground=0;
		}

		}

			if(ground!=0){



					bool check1=false;
		bool check2=false;
		//cout<<bpcount<<endl;
		for(int j=0;j<wpcount;j++)
		{
		
			if(wpc[j][0]==bd[0].x){
			  check1=true;
			}
			if(wpc[j][1]==bd[0].y){//i love you 
			  check2=true;
			}

		}
		if(check1==false  || check2==false){
		  cout<<"Enter Correct Values. You have enter wrong coordinates:"<<endl;
		  cout<<"Enter Coordinates from above mentioned movable postions:"<<endl;
		cout<<"X:";
		cin>>bd[0].x;
		cout<<endl<<"Y:";
		cin>>bd[0].y;
		check1=false;
		check2=false;
		for(int j=0;j<wpcount;j++)
		{
		
			if(wpc[j][0]==bd[0].x){
			 
				check1=true;
			}
			if(wpc[j][1]==bd[0].y){
			  
				check2=true;
			}

		}
		}

		if(check1==false  || check2==false){
		  cout<<"Enter Correct Values. You have enter wrong coordinates:"<<endl;
		  cout<<"Enter Coordinates from above mentioned movable postions:"<<endl;
		cout<<"X:";
		cin>>bd[0].x;
		cout<<endl<<"Y:";
		cin>>bd[0].y;
		check1=false;
		check2=false;

		for(int j=0;j<wpcount;j++)
		{
		
			if(wpc[j][0]==bd[0].x){
			 
				check1=true;
			}
			if(wpc[j][1]==bd[0].y){
			  				  
				check2=true;
			}

		}
		}
			
		//cout<<bpcount<<endl;
		for(int j=0;j<wpcount;j++)
		{
		
			if(wpc[j][0]==bd[0].x){
			  check1=true;
			}
			if(wpc[j][1]==bd[0].y){
			  check2=true;
			}

		}
		if(check1==false  || check2==false){
		  cout<<"Enter Correct Values. You have enter wrong coordinates:"<<endl;
		  cout<<"Enter Coordinates from above mentioned movable postions:"<<endl;
		cout<<"X:";
		cin>>bd[0].x;
		cout<<endl<<"Y:";
		cin>>bd[0].y;
		check1=false;
		check2=false;
		for(int j=0;j<wpcount;j++)
		{
		
			if(wpc[j][0]==bd[0].x){
			 
				check1=true;
			}
			if(wpc[j][1]==bd[0].y){
			  
				check2=true;
			}

		}
		}


		if(check1==true && check2==true){
		
		board[bd[0].x+1][bd[0].y]=board[bd[0].x][bd[0].y];
		board[bd[0].x][bd[0].y]=0;
		 
		}
		}

    out();
	
	}
	
	

	void bplays(){
		cout<<endl;
	   cout<<"Black Player Turn"<<endl;
	   char select;
		cout << "Enter E to end game" << endl;
		//cout << "White Player Turn:" << endl;
		cout << "For Selecting Pawn Press 6:" << endl;
		cout << "For Selecting Hook  Press 5:" << endl;
		cout << "For Selecting Knight Press 4:" << endl;
		cout << "For Selecting Bishop Press 3:" << endl;
		cout << "For Selecting King Press 2;" << endl;
		cout << "For Selecting Queen Press 1:" << endl;
		//select = _getch();
		cin>>select;

		if(select=='6'){
	
		bpawn();
		}
	    
	
	}

	void bpawn(){
		int bpcount=0;
		cout<<endl<<"Black Pawns are present at positions:"<<endl;
		for(int i=0;i<=7;i++){
			for(int j=0;j<=7;j++){
				if(board[i][j]==-6){
				cout<<"("<<i<<","<<j<<")";
				bpcount++;
				}
			}
		}
		int**bpc=new int*[bpcount];
		for(int i=0;i<bpcount;i++){
		  bpc[i]=new int[2];
		}
		cout<<endl<<"Movable Black Pawns:"<<endl;
			int k=0;
	   int checkpc=0;   // for knocking out opponent piece;
		for(int i=0;i<=7;i++){
			for(int j=0;j<=7;j++){
				if(board[i][j]==-6){
					if(board[i-1][j]==0  && i-1>=0){
					   cout<<"("<<i<<","<<j<<")"<<" ";
					   bpc[k][0]=i;
					   bpc[k][1]=j;
					   k++;
					}
					if(board[i-1][j-1]>1){
					
					/*cout<<"Positions to knockout Opponent piece"<<endl;
			
					cout<<"("<<i-1<<","<<j-1<<")";*/
		            checkpc++;
					}
					if (board[i-1][j+1]>1)
					{
					//	cout<<"("<<i-1<<","<<j+1<<")";
					cout<<endl;
		            checkpc++;
					

					}
				}
			

			}
		}
		cout<<endl;
		di*bo=new di[checkpc];
		int x=0;
		for(int i=0;i<=7;i++){
			for(int j=0;j<=7;j++){
				if(board[i][j]==-6){
				


					if(board[i-1][j-1]>1){
				
						cout<<"Positions to knockout Opponent piece:"<<" ";
					cout<<"("<<i-1<<","<<j-1<<")"<<" ";

						bo[x].x=i-1;
					bo[x].y=j-1;
				   x++;	
					}
					if(board[i-1][j+1]>1){
						cout<<"("<<i-1<<","<<j+1<<")"<<" ";
						bo[x].x=i-1;
					bo[x].y=j+1;
					x++;
					}}}}

		cout<<endl;
		di bd[8];
		cout<<"Enter Coordinates from above mentioned movable postions:"<<endl;
		cout<<"X:";
		cin>>bd[0].x;
		cout<<endl<<"Y:";
		cin>>bd[0].y;
		bool check3=false;
		bool check4=false;
		bool check1=false;
		bool check2=false;
		int ground=1;
		//cout<<bpcount<<endl;
		for(int j=0;j<checkpc;j++)
		{
		
			if(bo[j].x==bd[0].x){
			  check3=true;
			}
			if(bo[j].y==bd[0].y){
			  check4=true;
			}

			if(check3==true && check4==true){
		
		     board=checkmateblackpawn(bo[j].x,bo[j].y,board);  
			 ground=0;
		}

		}

			if(ground!=0){



					bool check1=false;
		bool check2=false;
		//cout<<bpcount<<endl;
		for(int j=0;j<bpcount;j++)
		{
		
			if(bpc[j][0]==bd[0].x){
			  check1=true;
			}
			if(bpc[j][1]==bd[0].y){
			  check2=true;
			}

		}
		if(check1==false  || check2==false){
		  cout<<"Enter Correct Values. You have enter wrong coordinates:"<<endl;
		  cout<<"Enter Coordinates from above mentioned movable postions:"<<endl;
		cout<<"X:";
		cin>>bd[0].x;
		cout<<endl<<"Y:";
		cin>>bd[0].y;
		check1=false;
		check2=false;
		for(int j=0;j<bpcount;j++)
		{
		
			if(bpc[j][0]==bd[0].x){
			 
				check1=true;
			}
			if(bpc[j][1]==bd[0].y){
			  
				check2=true;
			}

		}
		}

		if(check1==false  || check2==false){
		  cout<<"Enter Correct Values. You have enter wrong coordinates:"<<endl;
		  cout<<"Enter Coordinates from above mentioned movable postions:"<<endl;
		cout<<"X:";
		cin>>bd[0].x;
		cout<<endl<<"Y:";
		cin>>bd[0].y;
		check1=false;
		check2=false;

		for(int j=0;j<bpcount;j++)
		{
		
			if(bpc[j][0]==bd[0].x){
			 
				check1=true;
			}
			if(bpc[j][1]==bd[0].y){
			  				  
				check2=true;
			}

		}
		}
			
		//cout<<bpcount<<endl;
		for(int j=0;j<bpcount;j++)
		{
		
			if(bpc[j][0]==bd[0].x){
			  check1=true;
			}
			if(bpc[j][1]==bd[0].y){
			  check2=true;
			}

		}
		if(check1==false  || check2==false){
		  cout<<"Enter Correct Values. You have enter wrong coordinates:"<<endl;
		  cout<<"Enter Coordinates from above mentioned movable postions:"<<endl;
		cout<<"X:";
		cin>>bd[0].x;
		cout<<endl<<"Y:";
		cin>>bd[0].y;
		check1=false;
		check2=false;
		for(int j=0;j<bpcount;j++)
		{
		
			if(bpc[j][0]==bd[0].x){
			 
				check1=true;
			}
			if(bpc[j][1]==bd[0].y){
			  
				check2=true;
			}

		}
		}


		if(check1==true && check2==true){
		
		board[bd[0].x-1][bd[0].y]=board[bd[0].x][bd[0].y];
		board[bd[0].x][bd[0].y]=0;
		 
		}
		}
    out();
	}
	
	void whook(){
	   di dh[2];       // for saving hook dimensions
	   int k=0;
	   int uphookcount=0,downhookcount=0,righthookcount=0,lefthookcount=0;
	   for(int i=0;i<=7;i++){
		   for(int j=0;j<=7;j++){
		   
			   if(board[i][j]==+5){
	                 cout<<"("<<i<<","<<j<<")"<<" ";		       
				   dh[k].x=i;
				   dh[k].y=j;
			    k++;     
			   }
		   
		   }
	   
	   }
	   cout<<"Select hooks from above two"<<endl;
	   int x;
	   cout<<"Enter X coordinate:"<<endl;
	   cin>>x;
	   cout<<"Enter Y coordinate:"<<endl;
	   int y;
	   cin>>y;
	   if(x==dh[0].x && y==dh[0].y){
		   
		
		   if(dh[0].x+1<7){
	   if(board[dh[0].x+1][dh[0].y]==0){      //uphook
	   
		   for(int i=dh[0].x+1;board[i][dh[0].y]==0 && i<7;i++){
		      
		   uphookcount++;
		   }
	   }
		   }
	   if(dh[0].x-1>0){
	    if(board[dh[0].x-1][dh[0].y]==0){      //donwhook
	   
		   for(int i=dh[0].x-1;board[i][dh[0].y]==0 && i>0;i++){
		      
		   downhookcount++;
		   }
		}
	   } 
	   if(dh[0].y+1<7){
		   	    if(board[dh[0].x][dh[0].y+1]==0){      //lefthook
	   
		   for(int i=dh[0].y+1;board[dh[0].x][i]==0 && i<7;i++){ 
		      
		  lefthookcount++;
		   }	}
	   }
		
	   if(dh[0].y-1>0){     // out of bound check
	   if(board[dh[0].x][dh[0].y-1]==0){      //righthook
	   
		   for(int i=dh[0].y+1;board[dh[0].x][i]==0 && i>0;i++){ 
		      
		  righthookcount++;
		   }	}           

	   }                     if(x==0 || y==0 ||x==7 || y==7){
	                            //if(dh[0].x+1<7  && dh[0].y+1<7){
		                    
		                         
							if(board[dh[0].x+1][dh[0].y]!=0){/* && board[dh[0].x-1][dh[0].y]!=0*/  //&& board[dh[0].x][dh[0].y+1]!=0 /*&& board[dh[0].x][dh[0].y-1]!=0*/){
								
									cout<<"This hook cannot move as it has not as space empty in stright line"<<endl;
									cout<<"Select Another or Select other hook if its free"<<endl;
									plays();
								}
	   
							
	   
	   }
	   else{
	                     if(dh[0].x+1<7 &&dh[0].x-1>0 && dh[0].y+1<7 && dh[0].y-1>0){
		                    
		   
							if(board[dh[0].x+1][dh[0].y]!=0 && board[dh[0].x-1][dh[0].y]!=0 && board[dh[0].x][dh[0].y+1]!=0 && board[dh[0].x][dh[0].y-1]!=0){
								
									cout<<"This hook cannot move as it has not as space empty in stright line"<<endl;
									cout<<"Select Another or Select other hook if its free"<<endl;
									plays();
								}}
	    
	   }


	   
	   int**upc= new int*[uphookcount];
	   for(int i=0;i<uphookcount;i++){
	        upc[i]=new int[2];
	   }
	   int**dch=new int*[downhookcount];
	   for(int i=0;i<downhookcount;i++){
	        dch[i]=new int[2];
	   }
	  int**rch=new int*[lefthookcount];
	  for(int i=0;i<lefthookcount;i++){
	        rch[i]=new int[2];
	   }
	  int**lch=new int*[righthookcount];
	   for(int i=0;i<righthookcount;i++){
	        lch[i]=new int[2];
	   }
	  //upc[1][2];
	   if(x==dh[0].x && y==dh[0].y){
		   
		   if(dh[0].x+1<7){
			   if(uphookcount>0){
	   if(board[dh[0].x+1][dh[0].y]==0){      //uphook
	           int k=0;
		   for(int i=dh[0].x+1;board[i][dh[0].y]==0 && i<7;i++){
		       upc[k][0]=i;              
		       upc[k][1]=dh[0].y;
				   k++;
		   }
	   }
			   }
		   }
	   if(dh[0].x-1>0){
		   if(downhookcount>0){
	    if(board[dh[0].x-1][dh[0].y]==0){      //donwhook
	   int k=0;
		   for(int i=dh[0].x-1;board[i][dh[0].y]==0 && i>0;i++){
		      
		   dch[k][0]=i;              
		       dch[k][1]=dh[0].y;
				   k++;
		   }
		}
		   }
	   } 
	   if(dh[0].y+1<7){
		   if(lefthookcount>0){
		   	    if(board[dh[0].x][dh[0].y+1]==0){      //lefthook
	       int k=0;
		   for(int i=dh[0].y+1;board[dh[0].x][i]==0 && i<7;i++){ 
		      
		      lch[k][0]=i;              
		       lch[k][1]=dh[0].y;
				   k++;
		   }	}
	   }
	   }
	   if(dh[0].y-1>0){     // out of bound check
		   if(righthookcount>0){
	   if(board[dh[0].x][dh[0].y-1]==0){      //righthook
	     int k=0;
		   for(int i=dh[0].y+1;board[dh[0].x][i]==0 && i>0;i++){ 
		 for(int i=dh[0].y+1;board[dh[0].x][i]==0 && i<7;i++){ 
		      
		      rch[k][0]=i;              
		       rch[k][1]=dh[0].y;
				   k++;
		   }      
		  
		   }	}           

	   }
	   }
	   cout<<"Movable positions available:"<<endl;
	   for(int i=0;i<uphookcount;i++){
		    cout<<"(";
		   for(int j=0;j<2;j++){
		   
		  cout<<upc[i][j]<<",";
		   }
		   cout<<")";
	   }
	   for(int i=0;i<downhookcount;i++){
		   cout<<"(";
		   for(int j=0;j<2;j++){   
		   cout<<dch[i][j]<<",";
		   }
		   cout<<")";
	   }
	   for(int i=0;i<righthookcount;i++){
		   cout<<"(";
		   for(int j=0;j<2;j++){
		   
		   cout<<rch[i][j]<<",";
		   }
		   cout<<")";
	   }

	   for(int i=0;i<lefthookcount;i++){
		   cout<<"(";
		   for(int j=0;j<2;j++){
		   
		   cout<<lch[i][j]<<",";
		   }
		   cout<<")";
	   }
	   cout<<endl;
	
	   int x1;
	   int y1;
	   cout<<"Enter Coordinates to move rook"<<endl;
	   cout<<"X:";
	   cin>>x1;
	   cout<<"Y:";
	   cin>>y1;
      board[x1][y1]=5;
	  board[dh[0].x][dh[0].y]=0;
	   }
	}
	 else if(x==dh[1].x && y==dh[1].y){
		   
		   if(dh[1].x+1<7){
	   if(board[dh[1].x+1][dh[1].y]==0){      //uphook
	   
		   for(int i=dh[1].x+1;board[i][dh[1].y]==0 && i<7;i++){
		      
		   uphookcount++;
		   }
	   }
		   }
	   if(dh[1].x-1>0){
	    if(board[dh[1].x-1][dh[1].y]==0){      //donwhook
	   
		   for(int i=dh[1].x-1;board[i][dh[1].y]==0 && i>0;i++){
		      
		   downhookcount++;
		   }
		}
	   } 
	   if(dh[1].y+1<7){
		   	    if(board[dh[1].x][dh[1].y+1]==0){      //lefthook
	   
		   for(int i=dh[1].y+1;board[dh[1].x][i]==0 && i<7;i++){ 
		      
		  lefthookcount++;
		   }	}
	   }
		
	   if(dh[1].y-1>0){     // out of bound check
	   if(board[dh[1].x][dh[1].y-1]==0){      //righthook
	   
		   for(int i=dh[1].y+1;board[dh[1].x][i]==0 && i>0;i++){ 
		      
		  righthookcount++;
		   }	}           

	   }                     if(x==0 || y==0 ||x==7 || y==7){
	                            //if(dh[0].x+1<7  && dh[0].y+1<7){
		                    
		                         
							if(board[dh[1].x+1][dh[1].y]!=0){/* && board[dh[0].x-1][dh[0].y]!=0*/  //&& board[dh[0].x][dh[0].y+1]!=0 /*&& board[dh[0].x][dh[0].y-1]!=0*/){
								
									cout<<"This hook cannot move as it has not as space empty in stright line"<<endl;
									cout<<"Select Another or Select other hook if its free"<<endl;
									plays();
								}
	   
							
	   
	   }
	   else{
	                     if(dh[1].x+1<7 &&dh[1].x-1>0 && dh[1].y+1<7 && dh[1].y-1>0){
		                    
		   
							if(board[dh[1].x+1][dh[1].y]!=0 && board[dh[1].x-1][dh[1].y]!=0 && board[dh[1].x][dh[1].y+1]!=0 && board[dh[1].x][dh[1].y-1]!=0){
								
									cout<<"This hook cannot move as it has not as space empty in stright line"<<endl;
									cout<<"Select Another or Select other hook if its free"<<endl;
									plays();
								}}
	    
	   }


	   
	   int**upc= new int*[uphookcount];
	   for(int i=0;i<uphookcount;i++){
	        upc[i]=new int[2];
	   }
	   int**dch=new int*[downhookcount];
	   for(int i=0;i<downhookcount;i++){
	        dch[i]=new int[2];
	   }
	  int**rch=new int*[lefthookcount];
	  for(int i=0;i<lefthookcount;i++){
	        rch[i]=new int[2];
	   }
	  int**lch=new int*[righthookcount];
	   for(int i=0;i<righthookcount;i++){
	        lch[i]=new int[2];
	   }
	  //upc[1][2];
	   if(x==dh[1].x && y==dh[1].y){
		   
		   if(dh[1].x+1<7){
			   if(uphookcount>0){
	   if(board[dh[1].x+1][dh[1].y]==0){      //uphook
	           int k=0;
		   for(int i=dh[1].x+1;board[i][dh[1].y]==0 && i<7;i++){
		       upc[k][0]=i;              
		       upc[k][1]=dh[0].y;
				   k++;
		   }
	   }
			   }
		   }
	   if(dh[1].x-1>0){
		   if(downhookcount>0){
	    if(board[dh[1].x-1][dh[1].y]==0){      //donwhook
	   int k=0;
		   for(int i=dh[1].x-1;board[i][dh[1].y]==0 && i>0;i++){
		      
		   dch[k][0]=i;              
		       dch[k][1]=dh[0].y;
				   k++;
		   }
		}
		   }
	   } 
	   if(dh[1].y+1<7){
		   if(lefthookcount>0){
		   	    if(board[dh[1].x][dh[1].y+1]==0){      //lefthook
	       int k=0;
		   for(int i=dh[1].y+1;board[dh[1].x][i]==0 && i<7;i++){ 
		      
		      lch[k][0]=i;              
		       lch[k][1]=dh[0].y;
				   k++;
		   }	}
	   }
	   }
	   if(dh[1].y-1>0){     // out of bound check
		   if(righthookcount>0){
	   if(board[dh[1].x][dh[1].y-1]==0){      //righthook
	     int k=0;
		   for(int i=dh[1].y+1;board[dh[1].x][i]==0 && i>0;i++){ 
		 for(int i=dh[1].y+1;board[dh[1].x][i]==0 && i<7;i++){ 
		      
		      rch[k][0]=i;              
		       rch[k][1]=dh[0].y;
				   k++;
		   }      
		  
		   }	}           

	   }
	   }
	   cout<<"Movable positions available:"<<endl;
	   for(int i=0;i<uphookcount;i++){
		    cout<<"(";
		   for(int j=0;j<2;j++){
		   
		  cout<<upc[i][j]<<",";
		   }
		   cout<<")";
	   }
	   for(int i=0;i<downhookcount;i++){
		   cout<<"(";
		   for(int j=0;j<2;j++){   
		   cout<<dch[i][j]<<",";
		   }
		   cout<<")";
	   }
	   for(int i=0;i<righthookcount;i++){
		   cout<<"(";
		   for(int j=0;j<2;j++){
		   
		   cout<<rch[i][j]<<",";
		   }
		   cout<<")";
	   }

	   for(int i=0;i<lefthookcount;i++){
		   cout<<"(";
		   for(int j=0;j<2;j++){
		   
		   cout<<lch[i][j]<<",";
		   }
		   cout<<")";
	   }
	   cout<<endl;
	
	   int x1;
	   int y1;
	   cout<<"Enter Coordinates to move rook"<<endl;
	   cout<<"X:";
	   cin>>x1;
	   cout<<"Y:";
	   cin>>y1;
      board[x1][y1]=5;
	  board[dh[1].x][dh[1].y]=0;
	   }
	}
	   }//
	   void wbis(){
	   int upright=0;
	   int upright2=0;
	   int upleft=0;
	   int upleft2=0;
	   int downright=0;
	   int downright2=0;
	   int downleft=0;
	   int downleft2=0;
	   di db0[2];
	   int k=0;
	   cout<<"White Bi**ops are present"<<endl;    //sh have been silent due to religional purposes
		   for(int i=0;i<=7;i++){
			   for(int j=0;j<=7;j++){
				   if(board[i][j]==3){
				     db0[k].x=i;
					 db0[k].y=j;
					 k++;
				   cout<<"("<<i<<","<<j<<")"<<" ";
				      if(i<7){
				    if( j!=0  && i!=7 && j!=7  && board[i+1][j-1]==0 || board[i+1][j-1]<-1){
				        
				       upright++;
					   if(j!=1 && i!=6 && board[i+1+1][j-1-1]==0){
						   for(int t=i+1+1,t2=j-1-1;;i++,j--){
							   if(board[t][t2]==0 && t2!=-1){
							    upright2++;
							   }
							   if(board[t][t2]!=0 || board[t][t2]>-1){
							      break;
							   }
						   
						   }
					   
					   }
				   }
					  }
					  if(i<7 && j<7){
				   if(board[i+1][j+1]<-1 || board[i+1][j+1]==0 && i!=7 && j!=7 && j!=0){
				      upleft++;
				  
					  if(i!=6 && j!=6 && board[i+1+1][j+1+1]==0 ){
						   for(int t=i+1+1,t2=j+1+1;;i++,j++){
							   if(board[t][t2]==0 && t2!=8){
							    upleft2++;
							   }
							   if(board[t][t2]!=0 || board[t][t2]>-1){
							      break;
							   }
						   
						   }
					   
					   }


				   }}
				   if(i>0){
				   if(i!=0 && j!=0 && i!=7 && j!=7  && board[i-1][j-1]<-1 || board[i-1][j-1]==0  ) 
				   {
				     downright++;
					 				  
					  if(i!=1 && j!=1 && board[i-1-1][j-1-1]==0 ){
						   for(int t=i-1-1,t2=j-1-1;;i--,j--){
							   if(board[t][t2]==0 && t!=-1 && t2!=-1){
							    downright2++;
							   }
							   if(board[t][t2]!=0 || board[t][t2]>-1){
							      break;
							   }
						   
						   }
					   
					   }






				   }
				   }
				   if(i>0){
				   if(  i!=0 && j!=0 && i!=7 && j!=7 && board[i-1][j+1]<-1 || board[i-1][j+1]==0 ) 
				   {
				     downleft++;
					 if(i!=1 && j!=7 && board[i-1-1][j+1+1]==0 ){
						   for(int t=i-1-1,t2=j+1+1;;i--,j++){
							   if(board[t][t2]==0 && t!=-1 && t2!=8){
							    downleft2++;
							   } 
							   if(board[t][t2]!=0 || board[t][t2]>-1){
							      break;
							   }
						   
						   }
					   
					   }





				   }
				   }
				   }
				   
				  
			   
			   }
		   }
     	int**ur=new int*[upright];
		int**dr=new int*[downright];
		int**dl=new int*[downleft];
		int**ul=new int*[upleft];
		int**ur2=new int*[upright2];
		int**ul2=new int*[upleft];
		int**dl2=new int*[downleft];
		int**dr2=new int*[downright];
		for(int i=0;i<upright;i++){
			for(int j=0;j<2;j++){
			
			ur[i]=new int[2];
			}
		}
		for(int i=0;i<downright;i++){
			for(int j=0;j<2;j++){
			
			dr[i]=new int[2];
			}
		}
		for(int i=0;i<upleft;i++){
			for(int j=0;j<2;j++){
			
			ul[i]=new int[2];
			}
		}
		for(int i=0;i<downleft;i++){
			for(int j=0;j<2;j++){
			
			dl[i]=new int[2];
			}
		}
				for(int i=0;i<downleft;i++){
			for(int j=0;j<2;j++){
			
			ur2[i]=new int[2];
			}
		}
				for(int i=0;i<upleft2;i++){
					for(int j=0;j<2;j++){
					
					ul2[i]=new int[2];
					}
				}
				for(int i=0;i<downleft2;i++){
					for(int j=0;j<2;j++){
					
					dl2[i]=new int[2];
					}
				}
				for(int i=0;i<downright2;i++){
					for(int j=0;j<2;j++){
					
					dr2[i]=new int[2];
					}
				}
		int k1=0;
		int k2=0;
		int k3=0;
		int k4=0;
		int k5=0;
		int k6=0;
		int k7=0;
		int k8=0;
	 //cout<<upright<<downleft<<upleft<<downleft<<endl;
	     for(int i=0;i<=7;i++){
			   for(int j=0;j<=7;j++){
				   if(board[i][j]==3){
				   
				if(i<7 && j<7){
				    if( j!=0 && i!=7 && j!=7  && board[i+1][j-1]==0 || board[i+1][j-1]<-1){
				        
				       ur[k1][0]=i;
					  ur[k1][1]=j;
					  k1++;
					  
					  if(i!=6 && j!=1 && board[i+1+1][j-1-1]==0){
						   for(int t=i+1+1,t2=j-1-1;;i++,j--){
							   if(board[t][t2]>-1 || board[t][t2]==0 && t2!=-1){
							    ur2[k5][0]=t;
								ur2[k5][1]=t2;
								k5++;
							   }
							   if(board[t][t2]!=0 || board[t][t2]>-1){
							      break;
							   }
						   
						   }
					   
					   }



					}}}}
	   
		 }
	   
		 for(int i=0;i<=7;i++){
			   for(int j=0;j<=7;j++){
				   if(board[i][j]==3){
					   if(i<7 && j<7){
	                if(board[i+1][j+1]<-1 || board[i+1][j+1]==0 && i!=7 && j!=7 && j!=0){
				    //  upleft++;
				  ul[k2][0]=i;
					  ul[k2][1]=j;
					  k2++;
					  if(i!=6 && j!=6 && board[i+1+1][j+1+1]==0){
						   for(int t=i+1+1,t2=j+1+1;;i++,j++){
							   if(board[t][t2]==0){
							    //upleft2++;
								   ul2[k6][0]=t;
								   ul2[k6][1]=t2;
								   k6++;
							   }
							   if(board[t][t2]!=0 || board[t][t2]>-1){
							      break;
							   }
						   
						   }
					   
					   }

				   }
				   }
				   }
			   }
		 }
	   
		 
	   
		 for(int i=0;i<=7;i++){
			   for(int j=0;j<=7;j++){
				   if(board[i][j]==3){
		 
		 if(i>0){
				   if(i!=0 && j!=0 && i!=7 && j!=7  && board[i-1][j-1]<-1 || board[i-1][j-1]==0  ) 
				   {
				     //downright++;
					   dr[k3][0]=i;
					   dr[k3][1]=j;
					   k3++;
                if(i!=1 && j!=1 && board[i-1-1][j-1-1]==0 ){
						   for(int t=i-1-1,t2=j-1-1;;i--,j--){
							   if(board[t][t2]==0 && t!=-1 && t2!=-1){
							    downright2++;
							   }
							   if(board[t][t2]!=0 || board[t][t2]>-1){
							      break;
							   }
						   
						   }
					   
					   }





				   }
				   }
				   }
			   }
		 }

        		 for(int i=0;i<=7;i++){
			   for(int j=0;j<=7;j++){
				   if(board[i][j]==3){

		 if(i>0){
				   if(  i!=0 && j!=0 && i!=7 && j!=7 && board[i-1][j+1]<-1 || board[i-1][j+1]==0 ) 
				   {
				   //  downleft++;
					   dl[k4][0]=i;
					   dl[k4][1]=j;
					   k4++;

					   if(i!=1 && j!=7 && board[i-1-1][j+1+1]==0 ){
						   for(int t=i-1-1,t2=j+1+1;;i--,j++){
							   if(board[t][t2]==0 && t!=-1 && t2!=8){
							    downleft2++;
							   } 
							   if(board[t][t2]!=0 || board[t][t2]>-1){
							      break;
							   }
						   
						   }
					   
					   }







				   }
		 }}}}
               k1=0;
			   k2=0;
			   k3=0;
			   k4=0;
			   k5=0;
				 cout<<"Select Bishops from above two positions:"<<endl;
				 cout<<"Enter Coordinates:"<<endl;
				 di db;
				 cout<<"X:";
				 cin>>db.x;
				 cout<<endl<<"Y:";
				 cin>>db.y;
				 bool check=false;
				 if(db0[0].x==db.x && db0[0].y==db.y){
				     if(db.x>7 && db.y>0){
					 if(db.y!=0  &&  board[db.x+1][db.y-1]==0 || board[db.x+1][db.y-1]<-1){
					 
						   check=true;
					 }
					 }
					 if(db.x<7 && db.y<7){
					 if( db.x!=7 && db.y!=7 && board[db.x+1][db.y+1]==0 || board[db.x+1][db.y+1]<-1){
					 
					   check==true;
					 }}


				   if(db.x!=0 && db.y>0){
					 if(db.x!=0 && db.y!=0 &&  board[db.x-1][db.y-1]==0 || board[db.x-1][db.y-1]<-1){ 
					 
					   check=true;
					 }
				   }
				   if(db.x!=0  && db.y<7){
					 if(db.x!=0  && db.y!=0 && db.y!=7 && board[db.x-1][db.y+1]<-1 || board[db.x-1][db.y+1]==0)
					 {
                                         check=true;					 
					 
					 }
				   }
					 if(check==false){
					 
					 cout<<"No position is empty for B**hop to move. So chose other"<<endl;
					 plays();
					 
					 }
					 else if(check==true){
						 cout<<"Movable positions where b**hops can move:"<<endl;
					  for(int i=0;i<=7;i++){
			   for(int j=0;j<=7;j++){
				   if(board[i][j]==3){
				   
				
				    if( j!=0 && i!=7 && j!=7  && board[i+1][j-1]==0 || board[i+1][j-1]<-1){
				        
				       ur[k1][0]=i+1;
					  ur[k1][1]=j-1;
					  cout<<"("<<ur[k1][0]<<","<<ur[k1][1]<<")"<<" ";
					  k1++;
					
					 

					}}}
	   
		 }
	   
		 for(int i=0;i<=7;i++){
			   for(int j=0;j<=7;j++){
				   if(board[i][j]==3){
	                if(board[i+1][j+1]<-1 || board[i+1][j+1]==0 && i!=7 && j!=7 && j!=0){
				    //  upleft++;
						int t1=i;
						int t2=j;
						
					  ul[k2][0]=i+1;
					  ul[k2][1]=j+1;
					  
					  cout<<"("<<ul[k2][0]<<","<<ul[k2][1]<<")"<<" ";
					  					  k2++;
						if(i<6 && j<6){									  
					  if(board[i+1+1][j+1+1]==0 && j!=7 && i!=7){


						   for(int t=i+1+1,t2=j+1+1;;i++,j++){
							   if(board[t][t2]==0){
							    //upleft2++;
								   ul2[k6][0]=t;
								   ul2[k6][1]=t2;
								    cout<<"("<<ul[k6][0]<<","<<ul[k6][1]<<")"<<" ";
								   k6++;
							   }
							   if(board[t][t2]!=0 || board[t][t2]>-1){
							      break;
							   }
						   
						   }
					   
					  }}
				   }
				   }
			   }
		 }
	   
		 
	   
		 for(int i=0;i<=7;i++){
			   for(int j=0;j<=7;j++){
				   if(board[i][j]==3){
		 
		 if(i>0 && j>0){
				   if(i!=0 && j!=0 && i!=7 && j!=7  && board[i-1][j-1]<-1 || board[i-1][j-1]==0  ) 
				   {
				     //downright++;
					   dr[k3][0]=i-1;
					   dr[k3][1]=j-1;
					   cout<<"("<<dr[k3][0]<<","<<dr[k3][1]<<")"<<" ";
					   k3++;

					   if(i!=1 && j!=1 && board[i-1-1][j-1-1]==0 ){
						   for(int t=i-1-1,t2=j-1-1;;i--,j--){
							   if(board[t][t2]==0 && t!=-1 && t2!=-1){
							   dr2[k7][0]=t;
							   dr2[k7][1]=t2;
                         cout<<"("<<dr2[k7][0]<<","<<dr2[k7][1]<<")"<<" ";

							   k7++;
							   }
							   if(board[t][t2]!=0 || board[t][t2]>-1){
							      break;
							   }
						   
						   }
					   
					   }

				   }
				   }
				   }
			   }
		 }

        		 for(int i=0;i<=7;i++){
			   for(int j=0;j<=7;j++){
				   if(board[i][j]==3){

		 if(i>0 && j<7){
				   if(  i!=0 && j!=0 && i!=7 && j!=7 && board[i-1][j+1]<-1 || board[i-1][j+1]==0 ) 
				   {
				   //  downleft++;
					   dl[k4][0]=i-1;
					   dl[k4][1]=j+1;
					   cout<<"("<<dl[k4][0]<<","<<dl[k4][1]<<")"<<" ";
					   k4++;
					   if(i!=1 && j!=7 && board[i-1-1][j+1+1]==0 ){
						   for(int t=i-1-1,t2=j+1+1;;i--,j++){
							   if(board[t][t2]==0 && t!=-1 && t2!=8){
							    dl2[k8][0]=t;
								dl2[k8][1]=t2;
								cout<<"("<<dl2[k8][0]<<","<<dl2[k8][1]<<")"<<" ";

								k8++;

							   } 
							   if(board[t][t2]!=0 || board[t][t2]>-1){
							      break;
							   }
						   
						   }
					   
					   }



				   }
		 }}}}

				 di x1;
				 di y1;
				 cout<<"Enter coordinates from above postions of bishops to move"<<endl;
				 cout<<"X:";
				 cin>>x1.x;
				 cout<<"Y:";
				 cin>>y1.y;
				 bool check2=false;
				 for(int i=0;i<k1;i++){	 
						 if(x1.x==ur[i][0]  &&  y1.y==ur[i][1]){
						 check2=true;
						 break;
						 
					 }
				   
				 }
               
				 if(check2==true){
				      board[x1.x][y1.y]=+3;
					  board[db.x][db.y]=0;
				 }
				 check2=false;
				 for(int i=0;i<k5;i++){
				 
					 if(x1.x==ur2[i][0] && x1.y==ur2[i][1]){
					    check2=true;
						break;
					 
					 }
				 
				 }
				 if(check2==true){
				    board[x1.x][y1.y]=+3;
				    board[db.x][db.y]=0;
				 }
				 check2=false;


					 for(int i=0;i<k2;i++){	 
						 if(x1.x==ul[i][0]  &&  y1.y==ul[i][1]){
						 check2=true;
						 break;
						 
					 }
				   
				 }

				 if(check2==true){
				      board[x1.x][y1.y]=+3;
					  board[db.x][db.y]=0;
				 }
					 check2=false;

					  for(int i=0;i<k6;i++){
				 
					 if(x1.x==ul2[i][0] && x1.y==ul2[i][1]){
					    check2=true;
						break;
					 
					 }
				 
				 }
				 if(check2==true){
				    board[x1.x][y1.y]=+3;
				    board[db.x][db.y]=0;
				 }
				 check2=false;





					for(int i=0;i<k3;i++){	 
						 if(x1.x==dr[i][0]  &&  y1.y==dr[i][1]){
						 check2=true;
						 break;
						 
					 }
				   
				 }

				 if(check2==true){
				      board[x1.x][y1.y]=+3;
					  board[db.x][db.y]=0;
				 } 
				check2=false;

				for(int i=0;i<k4;i++){	 
						 if(x1.x==dl[i][0]  &&  y1.y==dl[i][1]){
						 check2=true;
						 break;
						 
					 }  
				 }

				 if(check2==true){
				      board[x1.x][y1.y]=+3;
					  board[db.x][db.y]=0;
					  out();
				 }



					 
					 }

				 }


				 else if(db0[1].x==db.x && db0[1].y==db.y){
				 if(db.x<7 && db.y>0){
					 if(db.y!=0  &&  board[db.x+1][db.y-1]==0 || board[db.x+1][db.y-1]<-1){
					 
						   check=true;
					 }
				 }
				    if(db.x<7 && db.y<7){
					 if( db.x!=7 && db.y!=7 && board[db.x+1][db.y+1]==0 || board[db.x+1][db.y+1]<-1){
					 
					   check==true;
					 }}
				   if(db.x!=0){
					 if(db.x!=0 && db.y!=0 &&  board[db.x-1][db.y-1]==0 || board[db.x-1][db.y-1]<-1){ 
					 
					   check=true;
					 }
				   }
				   if(db.x!=0  && db.y<7){
					 if(db.x!=0  && db.y!=0 && db.y!=7 && board[db.x-1][db.y+1]<-1 || board[db.x-1][db.y+1]==0)
					 {
                                         check=true;					 
					 
					 }
				   }
					 if(check==false){
					 
					 cout<<"No position is empty for B**hop to move. So chose other"<<endl;
					 plays();
					 
					 }
					 else if(check==true){
						 cout<<"Movable positions where b**hops can move:"<<endl;
					  for(int i=0;i<=7;i++){
			   for(int j=0;j<=7;j++){
				   if(board[i][j]==3){
				   
				if(i>7){
				    if( j!=0 && i!=7 && j!=7  && board[i+1][j-1]==0 || board[i+1][j-1]<-1){
				        //upright
				       ur[k1][0]=i+1;
					  ur[k1][1]=j-1;
					  cout<<"("<<ur[k1][0]<<","<<ur[k1][1]<<")"<<" ";
					  k1++;
					   if(i<6 && j<=2 && board[i+1+1][j-1-1]==0){
						   for(int t=i+1+1,t2=j-1-1;;i++,j--){
							   if(board[t][t2]==0 && t2!=-1){
							    ur2[k5][0]=t;
								ur2[k5][1]=t2;
								cout<<"("<<ur2[k5][0]<<","<<ur2[k5][1]<<")"<<" ";
								k5++;
							   }
							   if(board[t][t2]!=0 || board[t][t2]>-1){
							      break;
							   }
						   
						   }
					   
					   }



					}}}}
	   
		 }
	   k6=0;
		 for(int i=0;i<=7;i++){
			   for(int j=0;j<=7;j++){
				   if(board[i][j]==3){
					   if(i<7 && j<7){
	                if(board[i+1][j+1]<-1 || board[i+1][j+1]==0 && i!=7 && j!=7 && j!=0){
				    //  upleft++;
				  ul[k2][0]=i+1;
				ul[k2][1]=j+1;
					  int t1=i+1;
					  int t2=j+1;
				
					  cout<<"("<<ul[k2][0]<<","<<ul[k2][1]<<")"<<" ";
					  
					 if(i<6 && j<6 && board[i+1+1][j+1+1]==0 ){


						   for(int t=i+1+1,t2=j+1+1;;i++,j++){
							 
							   if(board[t][t2]==0){
							    //upleft2++;
								   ul2[k6][0]=t;
								   ul2[k6][1]=t2;
								    cout<<"("<<ul2[k6][0]<<","<<ul2[k6][1]<<")"<<" ";
								   k6++;
							   }
							   if(board[t][t2]!=0 || board[t][t2]>-1){
							      break;
							   }
						   
						   }
					   
					   }
				   
					  k2++;
					}}
				   }
			   }
		 }
	   
		 
	   
		 for(int i=0;i<=7;i++){
			   for(int j=0;j<=7;j++){
				   if(board[i][j]==3){
		 
		 if(i>0){
				   if(i!=0 && j!=0 && i!=7 && j!=7  && board[i-1][j-1]<-1 || board[i-1][j-1]==0  ) 
				   {
				     //downright++;
					   dr[k3][0]=i-1;
					   dr[k3][1]=j-1;
					   cout<<"("<<dr[k3][0]<<","<<dr[k3][1]<<")"<<" ";
					   k3++;

					    if(i!=1 && j!=1 && board[i-1-1][j-1-1]==0 ){
						   for(int t=i-1-1,t2=j-1-1;;i--,j--){
							   if(board[t][t2]==0 && t!=-1 && t2!=-1){
							   dr2[k7][0]=t;
							   dr2[k7][1]=t2;
                         cout<<"("<<dr2[k7][0]<<","<<dr2[k7][1]<<")"<<" ";

							   k7++;
							   }
							   if(board[t][t2]!=0 || board[t][t2]>-1){
							      break;
							   }
						   
						   }
					   
					   }



				   }
				   }
				   }
			   }
		 }

        		 for(int i=0;i<=7;i++){
			   for(int j=0;j<=7;j++){
				   if(board[i][j]==3){

		 if(i>0){
				   if(  i!=0 && j!=0 && i!=7 && j!=7 && board[i-1][j+1]<-1 || board[i-1][j+1]==0 ) 
				   {
				   //  downleft++;
					   dl[k4][0]=i-1;
					   dl[k4][1]=j+1;
					   cout<<"("<<dl[k4][0]<<","<<dl[k4][1]<<")"<<" ";
					   k4++;

					   if(i!=1 && j!=7 && board[i-1-1][j+1+1]==0 ){
						   for(int t=i-1-1,t2=j+1+1;;i--,j++){
							   if(board[t][t2]==0 && t!=-1 && t2!=8){
							    dl2[k8][0]=t;
								dl2[k8][1]=t2;
								cout<<"("<<dl2[k8][0]<<","<<dl2[k8][1]<<")"<<" ";

								k8++;

							   } 
							   if(board[t][t2]!=0 || board[t][t2]>-1){
							      break;
							   }
						   
						   }
					   
					   }


				   }
		 }}}}

				 di x1;
				 di y1;
				 cout<<"Enter coordinates from above postions of bishops to move"<<endl;
				 cout<<"X:";
				 cin>>x1.x;
				 cout<<"Y:";
				 cin>>y1.y;
				 bool check2=false;
				 for(int i=0;i<k1;i++){	 
						 if(x1.x==ur[i][0]  &&  y1.y==ur[i][1]){
						 check2=true;
						 break;
						 
					 }
				   
				 }

				 if(check2==true){
				      board[x1.x][y1.y]=+3;
					  board[db.x][db.y]=0;
				 }
				 check2=false;
				 for(int i=0;i<k5;i++){
				 
					 if(x1.x==ur2[i][0] && x1.y==ur2[i][1]){
					    check2=true;
						break;
					 
					 }
				 
				 }
				 if(check2==true){
				    board[x1.x][y1.y]=+3;
				    board[db.x][db.y]=0;
				 }
				
					 check2=false;

				
	 
					 for(int i=0;i<k2;i++){	 
						 if(x1.x==ul[i][0]  &&  y1.y==ul[i][1]){
						 check2=true;
						 break;
						 
					 }
				   
				 }

				 if(check2==true){
				      board[x1.x][y1.y]=+3;
					  board[db.x][db.y]=0;
				 }
					 check2=false;
					 					 for(int i=0;i<k6;i++){	 
						 if(x1.x==ul2[i][0]  &&  y1.y==ul2[i][1]){
						 check2=true;
						 break;
						 
					 }
				   
				 }

				 if(check2==true){
				      board[x1.x][y1.y]=+3;
					  board[db.x][db.y]=0;
				 }
					 check2=false;
					for(int i=0;i<k3;i++){	 
						 if(x1.x==dr[i][0]  &&  y1.y==dr[i][1]){
						 check2=true;
						 break;
						 
						 }}


					if(check2==true){
				      board[x1.x][y1.y]=+3;
					  board[db.x][db.y]=0;
				 } 

					check2=false;
				   	 					 for(int i=0;i<k7;i++){	 
						 if(x1.x==dr2[i][0]  &&  y1.y==dr2[i][1]){
						 check2=true;
						 break;
						 
					 }
				   
				 }

				 if(check2==true){
				      board[x1.x][y1.y]=+3;
					  board[db.x][db.y]=0;
				 }
				
				check2=false;

				for(int i=0;i<k4;i++){	 
						 if(x1.x==dl[i][0]  &&  y1.y==dl[i][1]){
						 check2=true;
						 break;
						 
					 }  
				 }

				 if(check2==true){
				      board[x1.x][y1.y]=+3;
					  board[db.x][db.y]=0;
					  
				 }
				 check2=false;
				 for(int i=0;i<k8;i++){	 
						 if(x1.x==dl2[i][0]  &&  y1.y==dl2[i][1]){
						 check2=true;
						 break;
						 
					 }  
				 }

				 if(check2==true){
				      board[x1.x][y1.y]=+3;
					  board[db.x][db.y]=0;
					//  out();
				 }
				 out();
					 }

				 }

	   }

	   void wqueen(){
	   int up=0;
	   int down=0;
	   int left=0;
	   int right=0;
	   int upright=0;
	   int downright=0;
	   int upleft=0;
	   int downleft=0;
		   for(int i=0; i<7;i++){
			   for(int j=0;j<7;j++){
			   if(board[i][j]==+2){
				   if(i<7 && j<7){
				   
					   if(board[i+1][j]==0){
						   for(int t=i+1; ;t++){
						   if(board[t][j]!=0){
						     break;
						   }
							   up++;
						  
						   if(board[t][j]<-1){
							   up++;
						      break;
						   }
						   
						   
						   }
					   
					   }
				   
				   }
			   }


			   }
		   }
	   

        int**u=new int*[2];
		for(int i=0;i<up;i++){
		u[i]=new int[2];
		}
		int k1=0;
		cout<<endl<<"Moveable Positions by Queen"<<endl;
		for(int i=0; i<=7;i++){
			   for(int j=0;j<=7;j++){
			   if(board[i][j]==+2){
				   if(i<7 && j<7){
				   
					   if(board[i+1][j]==0){
						   for(int t=i+1; ;t++){
						  // up++;
							   if(board[t][j]!=0){
						     break;
						   }
							   u[k1][0]=t;
							   u[k1][1]=j;
							   cout<<"("<<u[k1][0]<<","<<u[k1][1]<<")"<<" ";
						        
						   if(board[t][j]<-1){
							  cout<<"Knockout Position:";
							  cout<<"("<<u[k1][0]<<","<<u[k1][1]<<")"<<" "<<endl;
						      break;
						   }
						  k1++;
						   }}}}}}
		
		for(int i=0;i<=7;i++){
			for(int j=0;j<=7;j++){
			
				if(board[i][j]==+2){
				
					if(i>0){
					
						if(board[i-1][j]==0 || board[i-1][j]){

							for(int t=i-1;;t--){
								if(t<0){ break;}
								if(board[t][j]!=0){
								    break;
								}
	
							   down++;
							   if(board[t][j]<-1){
							   break;
							   }}}}}}}

			int**d=new int*[2];
		for(int i=0;i<down;i++){
		d[i]=new int[2];
		}
		

		int k2=0;

                         		for(int i=0;i<=7;i++){
			for(int j=0;j<=7;j++){
			
				if(board[i][j]==+2){
				
					if(i>0){
					
						if(board[i-1][j]==0 || board[i-1][j]){
							for(int t=i-1;;t--){
								if(t<0){break;}
								if(board[t][j]!=0){
								    break;
								}
							   d[k2][0]=t;
							   d[k2][1]=j;
							   cout<<"("<<d[k2][0]<<","<<d[k2][1]<<")"<<" ";
								if(board[t][j]<-1){
								   cout<<endl<<"Knockout postions:"<<" "<<"("<<d[k2][0]<<","<<d[k2][1]<<")"<<" ";
							   break;
							   }

						 
							   k2++;
							   
							
							
							}}}}}}

	         ///---------------------------------/////

                   cout<<endl<<"Moveable Positions by Queen"<<endl;

								for(int i=0;i<=7;i++){
			for(int j=0;j<=7;j++){
			
				if(board[i][j]==+2){
				
					if(i>=0 && j>=1){
					
						if(board[i][j-1]==0 || board[i][j-1]){
							for(int t=j-1;;t--){
								if(board[i][t]!=0){
								    break;
								}
							   right++;
							   if(board[i][t]<-1){
							   break;
							   }}}}}}}

			int**r=new int*[2];
		for(int i=0;i<right;i++){
		r[i]=new int[2];
		}
		cout<<right;
		int k3=0;

                         		for(int i=0;i<=7;i++){
			for(int j=0;j<=7;j++){
			
				if(board[i][j]==+2){
				
					if(i>=0 && j>=1){
					
						if(board[i][j-1]==0 || board[i][j-1]){
							for(int t=j-1;;t--){
								if(board[i][t]!=0){
								    break;
								}
								r[k3][0]=i;
							   r[k3][1]=t;
							   cout<<"("<<r[k3][0]<<","<<r[k3][1]<<")"<<" ";
								if(board[t][j]<-1){
								   cout<<endl<<"Knockout postions:"<<" "<<"("<<r[k3][0]<<","<<r[k3][1]<<")"<<endl;
							   break;
							   }
								
						
							   k3++;
							   }}}}}}

                ///------------------------------------///


								cout<<endl<<"Moveable Positions by Queen"<<endl;
               		for(int i=0;i<=7;i++){
			for(int j=0;j<=7;j++){
			
				if(board[i][j]==+2){
				
					if(i>=0 && j<=6){
					
						if(board[i][j+1]==0 || board[i][j+1]){
							for(int t=j+1;;t++){
								if(board[i][t]!=0){
								    break;
								}
							   left++;
							   if(board[i][t]<-1){
							   break;
							   }}}}}}}

			int**l=new int*[2];
		for(int i=0;i<left;i++){
		l[i]=new int[2];
		}
		int k4=0;

                         		for(int i=0;i<=7;i++){
			for(int j=0;j<=7;j++){
			
				if(board[i][j]==+2){
				
					if(i>=0 && j<=6){
					
						if(board[i][j+1]==0 || board[i][j+1]){
							for(int t=j+1;;t++){
								if(board[i][t]!=0){
								    break;
								}
							   l[k4][0]=i;
							   l[k4][1]=t;
						 cout<<"("<<l[k4][0]<<","<<l[k4][1]<<")"<<" ";
							   
							   if(board[t][j]<-1){
								   cout<<endl<<"Knockout postions:"<<" "<<"("<<l[k4][0]<<","<<l[k4][1]<<")"<<" ";
							   break;
							   }
							k4++;
							}}}}}}
            

								////--------------------------------/////////

								cout<<endl<<"Moveable Positions by Queen"<<endl;

								for(int i=0;i<=7;i++){
									for(int j=0;j<=7;j++){
										if(board[i][j]==+2){
											if(i>=1 && j>=1){
											
												if(board[i-1][j-1]==0 || board[i-1][j-1]<-1){
												
												for(int t1=i-1,t2=j-1;;t1--,t2--){
													if(t1<0 || t2<0){
													  break;
													}
													else{
														if(board[t1][t2]!=0 && board[t1][t2]<-1){
														    downright++;
															break;
														}
														else if(board[t1][t2]!=0 && board[t1][t2]>-1){
														  break; 
														
														}
													    downright++;
													}
												}
												}
											
											}							
										
										}
									
									}
								
								}
								
		int**dr=new int*[2];
		for(int i=0;i<downright;i++){
		dr[i]=new int[2];
		}
		int k5=0;



		              for(int i=0;i<=7;i++){
									for(int j=0;j<=7;j++){
										if(board[i][j]==+2){
											if(i>=1 && j>=1){
											
												if(board[i-1][j-1]==0 || board[i-1][j-1]<-1){
												
												for(int t1=i-1,t2=j-1;;t1--,t2--){
													if(t1<0 || t2<0){
													  break;
													}
													else{

														dr[k5][0]=t1;
														dr[k5][1]=t2;
														cout<<"("<<dr[k5][0]<<","<<dr[k5][1]<<")"<<" ";
														if(board[t1][t2]!=0 && board[t1][t2]>-1){
														    
															break;
														}
														else if(board[t1][t2]!=0 && board[t1][t2]<-1){
	                                                      cout<<endl<<"Knockout Positions:"<<"("<<dr[k5][0]<<","<<dr[k5][1]<<")"<<" "<<endl;
															break; 
						
														}
													    


														
													        k5++;
																											}
												}
												}
											
											}							
										
										}
									
									}
								
								}


		/////---------------------////////////--------------///////////
    
					  cout<<endl<<"Moveable Positions by Queen"<<endl;


					  for(int i=0;i<=7;i++){
									for(int j=0;j<=7;j++){
										if(board[i][j]==+2){
											if(i>=1 && j<=6){
											
												if(board[i-1][j+1]==0 || board[i-1][j+1]<-1){
												
												for(int t1=i-1,t2=j+1;;t1--,t2++){
													if(t1<0 || t2>7){
													  break;
													}
													else{
														if(board[t1][t2]!=0 && board[t1][t2]<-1){
														    downleft++;
															break;
														}
														else if(board[t1][t2]!=0 && board[t1][t2]>-1){
														  break; 
														
														}
													    downleft++;
													}
												}
												}
											
											}							
										
										}
									
									}
								
								}
								
		int**dl=new int*[2];
		for(int i=0;i<downleft;i++){
		dl[i]=new int[2];
		}
		int k6=0;



		              for(int i=0;i<=7;i++){
									for(int j=0;j<=7;j++){
										if(board[i][j]==+2){
											if(i>=1 && j<=7 && j>=1){
											
												if(board[i-1][j+1]==0 || board[i-1][j+1]<-1){
												
												for(int t1=i-1,t2=j+1;;t1--,t2++){
													if(t1<0 || t2>7){
													  break;
													}
													else{

														dl[k6][0]=t1;
                                                        dl[k6][1]=t2;
														cout<<"("<<dl[k6][0]<<","<<dl[k6][1]<<")"<<" ";

														if(board[t1][t2]!=0 && board[t1][t2]>-1){
														         
															break;
														}
														else if(board[t1][t2]!=0 && board[t1][t2]<-1){
	                                                      cout<<endl<<"Knockout Positions:"<<"("<<dl[k6][0]<<","<<dl[k6][1]<<")"<<" "<<endl;
															break; 
						
														}

																											        k6++;
														
													}
												}
												}
											
											}							
										
										}
									
									}
								
								}



                       /////---------------------////////
                

					  cout<<endl<<"Moveable Positions by Queen"<<endl;

					  for(int i=0;i<=7;i++){
									for(int j=0;j<=7;j++){
										if(board[i][j]==+2){
											if(i<=6 && j<=6){
											
												if(board[i+1][j+1]==0 || board[i+1][j+1]<-1){
												
												for(int t1=i+1,t2=j+1;;t1++,t2++){
													if(t1>7 || t2>7){
													  break;
													}
													else{
														
														 if(board[t1][t2]!=0 && board[t1][t2]>-1){
														  break; 
														
														}
													    upleft++;
													}
												}
												}
											
											}							
										
										}
									
									}
								
								}
								
		int**ul=new int*[2];
		for(int i=0;i<upleft;i++){
		ul[i]=new int[2];
		}
		int k7=0;
		//cout<<upleft<<endl;


		              for(int i=0;i<=7;i++){
									for(int j=0;j<=7;j++){
										if(board[i][j]==+2){
											if(i<=6 && j<=6){
											
												if(board[i+1][j+1]==0 || board[i+1][j+1]<-1){
												
												for(int t1=i+1,t2=j+1;;t1++,t2++){
													if(t1>7 || t2>7){
													  break;
													}
													else{
														if(board[t1][t2]!=0 && board[t1][t2]>-1){
														    
															break;
														}

														ul[k7][0]=t1;
														ul[k7][1]=t2;
														cout<<"("<<ul[k7][0]<<","<<ul[k7][1]<<")"<<" ";
														 if(board[t1][t2]!=0 && board[t1][t2]<-1){
	                                                      cout<<endl<<"Knockout Positions:"<<"("<<ul[k7][0]<<","<<ul[k7][1]<<")"<<" "<<endl;
															break; 
						
														}
														
													        k7++;
														}}}}}}}

					  ///----------------------------------------///


					  cout<<endl<<"Moveable Positions by Queen"<<endl;

					  for(int i=0;i<=7;i++){
									for(int j=0;j<=7;j++){
										if(board[i][j]==+2){
											if(i<=6 && j>=1){
											
												if(board[i+1][j-1]==0 || board[i+1][j-1]<-1){
												
												for(int t1=i+1,t2=j-1;;t1++,t2--){
													if(t1>7 || t2<0){
													  break;
													}
													else{
														if(board[t1][t2]!=0 && board[t1][t2]<-1){
														    upright++;
															break;
														}
														else if(board[t1][t2]!=0 && board[t1][t2]>-1){
														  break; 
														
														}
													    upright++;
													}
												}
												}
											
											}							
										
										}
									
									}
								
								}
								
		int**ur=new int*[2];
		for(int i=0;i<upright;i++){
		ur[i]=new int[2];
		}
		int k8=0;



		              for(int i=0;i<=7;i++){
									for(int j=0;j<=7;j++){
										if(board[i][j]==+2){
											if(i<=6 && j>=1){
											
												if(board[i+1][j-1]==0 || board[i+1][j-1]<-1){
												
												for(int t1=i+1,t2=j-1;;t1++,t2--){
													if(t1>7 || t2<0){
													  break;
													}
													else{

														ur[k8][0]=t1;
														ur[k8][1]=t2;
												if(board[t1][t2]!=0 && board[t1][t2]>-1){
														    
															break;
														}
														else if(board[t1][t2]!=0 && board[t1][t2]<-1){
	                                                      cout<<endl<<"Knockout Positions:"<<"("<<ur[k8][0]<<","<<ur[k8][1]<<")"<<" ";
															break; 
						
	                                 }
														cout<<"("<<ur[k8][0]<<","<<ur[k8][1]<<")"<<" ";
													        k8++;
}}}}}}}

					  //---///
					  cout<<endl;
					  bool check=false;
					  di pos;
					  
					  for(int i=0;i<=7;i++){
						  for(int j=0;j<=7;j++){
							  if(board[i][j]==+2){
							  cout<<"Position of Queen:"<<endl;
							  cout<<"("<<i<<","<<j<<")"<<endl;
							   pos.x=i;
							   pos.y=j;
							  if(i<7 && j<=7){
							  
								  if(board[i+1][j]==0 || board[i+1][j]<-1){
								     check=true;
								  }
							
							  }
								  if(i!=0 && j<=7){
								  
									  if(board[i-1][j]==0  || board[i-1][j]<-1){
									  check=true;
									  }
								      
								  }
								  if(j>=1 && i<=7){
									  if(board[i][j-1]==0 || board[i][j-1]<-1){
									  check=true;
									  }
								  }
								    if(i<=7 && j<=6){
									  if(board[i][j+1]==0 || board[i][j+1]<-1){
									  check=true;
									  }
								  }
									if(i<=6 && j<=6){
										if(board[i+1][j+1]==0 || board[i+1][j+1]<-1){
										check=true;
										}
									}
									if(i<=6 && j<=1){
									
										if(board[i+1][j-1]==0 ||  board[i+1][j-1]<-1){
										 check=true;
										}
									}
									if(i>=1 && j<=6){
									
										if(board[i-1][j+1]==0 || board[i-1][j+1]<-1){
										  check=true;
										}
									}
									if(i>=1 && j<=1){
									
										if(board[i-1][j-1]==0 || board[i-1][j-1]<-1){
										  check=true;
										
										}
									}

							  }
						  }//end for loop
					  }

					  if(check==false){
					     cout<<endl;
					   cout<<"Queen can move in any number of empty boxes iny any Direction But no box is empty for movement. Choose another:"<<endl;
					     plays();
					  }
					  if(check==true){
					  di q;
					  cout<<"Enter Coordiantes from above mentioned movable positions:"<<endl;
					  cout<<"X:";
					  cin>>q.x;
					  cout<<endl<<"Y:";
					  cin>>q.y;
					  bool check1=false;
				
					  for(int i=0;i<k1;i++){
						 
						  if(u[i][0]==q.x && u[i][1]==q.y){
							    
						check1=true;  
						  }
						  if(check1==true){
						
						board=checkmatewhitequeen(q.x,q.y,board);
						board[pos.x][pos.y]=0;
						
						  }
					  }
					  check1=false;
					  for(int i=0;i<k2;i++){
						  if(d[i][0]==q.x && d[i][1]==q.y){
						check1=true;  
						  }
						  if(check1==true){
						  
						board=checkmatewhitequeen(q.x,q.y,board);
						board[pos.x][pos.y]=0;
						  }
					  }
					  check1=false;
					  for(int i=0;i<k3;i++){
						  if(r[i][0]==q.x && r[i][1]==q.y){
						check1=true;  
						  }
						  if(check1==true){
						  
						board=checkmatewhitequeen(q.x,q.y,board);
						board[pos.x][pos.y]=0;
						  }
					  }
					  check1=false;
					  for(int i=0;i<k4;i++){
						  if(l[i][0]==q.x && l[i][1]==q.y){
						check1=true;  
						  }
						  if(check1==true){
						  
						board=checkmatewhitequeen(q.x,q.y,board);  
						  board[pos.x][pos.y]=0;
						  }
					  }
					  check1=false;
					  for(int i=0;i<k5;i++){
						  if(dr[i][0]==q.x && dr[i][1]==q.y){
						check1=true;  
						  }
						  if(check1==true){
						  
						board=checkmatewhitequeen(q.x,q.y,board);  
						  board[pos.x][pos.y]=0;
						  }
					  }
					  check1=false;
					  for(int i=0;i<k6;i++){
						  if(dl[i][0]==q.x && dl[i][1]==q.y){
						check1=true;  
						  }
						  if(check1==true){
						  
						board=checkmatewhitequeen(q.x,q.y,board);  
						  board[pos.x][pos.y]=0;
						  }
					  }
					  check1=false;
					  for(int i=0;i<k7;i++){
						  if(ul[i][0]==q.x && ul[i][1]==q.y){
						check1=true;  
						  }
						  if(check1==true){
						  
						board=checkmatewhitequeen(q.x,q.y,board);  
						  board[pos.x][pos.y]=0;
						  }
					  }
					  check1=false;
					  for(int i=0;i<k8;i++){
						  if(ur[i][0]==q.x && ur[i][1]==q.y){
						check1=true;  
						  }
						  if(check1==true){
						  
						board=checkmatewhitequeen(q.x,q.y,board);  
						  board[pos.x][pos.y]=0;
						  }
					  }

					  }///end of else if
                      
}
	
};
int main()
{
	cout << "\t" << "\t" << "                    Chess Game" << endl;
	cout << "Press 1 to Start new Game:" << endl;
	cout << "Press 2 to Reload Game:" << endl;
	cout << "Press E to end Game:" << endl;
	cout << "Press S to save game:" << endl;
	char press;
	cin>>press;
	players s(1);
	if (press == '2') {
		while(press!='e'){
			cout<<"Press E to exit"<<endl;
		press=getch();
		if(press=='e'){
		cout<<endl<<"saving game"<<endl;
		s.savefilecaller();
			break;
		}
		
		
		s.plays();
		s.bplays();
		
		}

	}



	if (press == '1') {

		players s(1,"new");
		while(press!='e'){
			cout<<"Press E to exit"<<endl;
		press=getch();
		if(press=='e'){
		cout<<endl<<"saving game"<<endl;
		s.savefilecaller();
			break;
		}
		
		
		s.plays();
		s.bplays();
		
		}

	}
	system("pause");

	return 0;
}
