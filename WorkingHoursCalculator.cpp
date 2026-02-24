
/*------------------------------------------------------------------------------------------------

  Project Title : Employee Working Hour Calculator
  Description   : A simple C++ program that takes the employee's name, arrival and departure
                  times, and compute the total working hours spent on his/her job on a 
				  particular day.

  Created by    : Intan Suraya
  Date Created  : 19th February 2026
  Last Modified : 24th February 2026
 
  © 2026 Intan Suraya. All rights reserved. 
  
 /*---------------------------------- PROGRAM STARTS HERE --------------------------------------*/

#include<iostream>
#include<iomanip>
using namespace std;

const int LINE_LENGTH = 45;

void printLine( int length );
void printHeader( );
void startProgram( char& response );
void getEmployeeName( string& name );
void getArrivalTime( int& arrHour, int& arrMin, char& isItAM, bool& arrAM  );
void getDepartureTime( int& depHour, int& depMin, char& isItAM, bool& depAM );
void displayTimeOnJob( int arrHour, int arrMin, bool arrAM, int depHour, int depMin, bool depAM );
void runProgramAgain( char& respond );

/*-------------------------------------- MAIN FUNCTION -----------------------------------------*/

int main ()
{	
    printHeader(); 
	
	char decision;
	startProgram( decision );
	
	while( decision == 'y' || decision == 'Y' )
	{
		cout<<endl;
		printLine( LINE_LENGTH );
		cout<<endl;
		
		// Get employee's name
		string employeeName;
		getEmployeeName( employeeName );
		
		// Get the arrival time
		int arriveHour;
		int arriveMin;
		char isAM;
		bool arriveAM;
		getArrivalTime( arriveHour, arriveMin, isAM, arriveAM );
		cout<<endl;
		
		// Get the departure time
		int departHour;
		int departMin;
		bool departAM;
		getDepartureTime( departHour, departMin, isAM, departAM );
		cout<<endl;
		
		// Calculate and display the total time spent on the job
		// in a particular day
		displayTimeOnJob( arriveHour, arriveMin, arriveAM, departHour, departMin, departAM );
		
		// Ask user if he wants to run the program again
		runProgramAgain( decision );		
		
	}	
	
	return 0;
}

/*---------------------------------- FUNCTION DEFINITIONS --------------------------------------*/

void printLine( int length )
{
	for( int i=0; i<length; i++ )
	{
		cout<<'-';
	}
}

void printHeader( )
{	
	cout<<endl<<" This program calculates the total time"<<endl
	    <<" spent by an employee on the job."<<endl<<endl;	    
	
}

void startProgram( char& response )
{   
    cout<<" Enter (y/Y) to run this program  "<<endl
        <<" > ";
    cin>>response;
    
    cin.ignore();
}

void getEmployeeName( string& name )
{
	cout<<endl<<" Enter the employee name "<<endl
	    <<" > ";
	getline( cin, name );	
	
	cout<<endl;
}

void getArrivalTime( int& arrHour, int& arrMin, char& isItAM, bool& arrAM  )
{
	
	cout<<" Enter the arrival hour "<<endl
	    <<" > ";
	cin>>arrHour;
	
    cout<<" Enter the arrival minute "<<endl
        <<" > ";  
	cin>>arrMin;
	
	cout<<" Arrival time before 12.00 PM (y/Y) ? "<<endl
	    <<" > ";
	cin>>isItAM;
	
	if( isItAM == 'y' || isItAM == 'Y' )
	{
		arrAM = true;
	}
	
	else
	{
		arrAM = false;
	}
}

void getDepartureTime( int& depHour, int& depMin, char& isItAM, bool& depAM )
{
	cout<<" Enter the departure hour "<<endl
	    <<" > ";
	cin>>depHour;
	
	cout<<" Enter the departure minute "<<endl
	    <<" > ";
	cin>>depMin;
	
	cout<<" Departure time before 12.00 PM (y/Y) ?"<<endl
	    <<" > ";
	cin>>isItAM;
	
	if( isItAM == 'y' || isItAM == 'Y' )
	{
		depAM = true;
	}
	else
	{
		depAM = false;
	}
}

void displayTimeOnJob( int arrHour, int arrMin, bool arrAM, int depHour, int depMin, bool depAM )
{
	int arrTimeInMin;
    int depTimeInMin;
	int timeOnJobInMin;	
	
	// Case 1 : The employee arrived and departed before noon, or
	//          arrived and departed after noon.
	if( ( arrAM == true && depAM == true ) || ( arrAM == false && depAM == false ) )
	{
		cout<<" Invalid input. "<<endl<<endl;
	}
	
	// Case 2 : The employee arrived before noon and departed after noon.
	else if( arrAM == true && depAM == false )
	{
		arrTimeInMin = 60*arrHour + arrMin;
		depTimeInMin = 60*depHour + depMin;
		
		const int NOON_IN_MIN = 12*60;
		timeOnJobInMin = ( NOON_IN_MIN - arrTimeInMin ) + depTimeInMin;
		
		cout<<" Time spent on job"<<endl<<" : "
		    <<timeOnJobInMin / 60<<" hour(s) and "
		    <<timeOnJobInMin % 60<<" minute(s). "<<endl<<endl;		
	}
	
	// Case 3 : Other than Case 1 or Case 2.
	else
	{
		cout<<" Invalid input. "<<endl<<endl;
	}	
}

void runProgramAgain( char& respond )
{
	cout<<" Run program again (y/Y) ? "<<endl
	    <<" > ";
	cin>>respond;
	
	if( respond == 'y' || respond == 'Y' )
	{
		cin.ignore();
	}
	
	else
	{
		cout<<endl;
		printLine( LINE_LENGTH );
		cout<<endl;
		
		cout<<" Terminating the program..."<<endl<<endl;
	}
	
}

/*------------------------------------ PROGRAM ENDS HERE ---------------------------------------*/

