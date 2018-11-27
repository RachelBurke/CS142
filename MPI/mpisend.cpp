#include <iostream>
#include <stdio.h>
#include <string.h>
#include "mpi.h" // message passing interface
using namespace std;

// Do this ONCE when you start up thomas
// module load openmpi-x86_64

// New compile and run commands for MPI!
// mpicxx -o blah file.cpp
// mpirun -np 32 blah

int main (int argc, char * argv[]) {

	int my_rank;			// my CPU number for this process
	int p;					// number of CPUs that we have
	int source;				// rank of the sender
	int dest;				// rank of destination
	int tag = 0;			// message number
	char message[100];		// message itself
	MPI_Status status;		// return status for receive
	
	// Start MPI
	MPI_Init(&argc, &argv);
	
	// Find out my rank!
	MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);
	
	// Find out the number of processes!
	MPI_Comm_size(MPI_COMM_WORLD, &p);
	
	// THE REAL PROGRAM IS HERE
	
	sprintf(message, "temporary");
	
	if (my_rank == 0) 
		sprintf(message, "permanent");
	
	cout << my_rank << " " << message << endl;
	
	cout << endl;
	cout << endl;
	
	//MPI_Send is a function (black box).  Give it the message, message size, and destination.  
	//It will return an output of "success tracking" (like a UPS tracking number)
	
	MPI_Send (message, strlen(message) + 1, MPI_CHAR, 1, tag, MPI_COMM_WORLD);
	
	// I only need to know how the function works and what it does. (not syntax)
	//Parameter 1 - message
	//Parameter 2 - math expression with function - strlen is the length of the message
	//Parameter 3 - tells MPI the type of data is a character type
	//Parameter 4 - tells the where the message needs to be sent (processor 1)
	//Parameter 5 - don't need to know, but it is an identifier to keep track of a message number
	//Parameter 6 - don't need to know, but is the communication world of this thing and contains 
	//              the number of things being communicated with
		
	//MPI_Recv is a function (black box).  Give it the sender, the place to keep message, and the message size.  
	//It will return an output of "success tracking."
	
	MPI_Recv (message, 100, MPI_CHAR, 0, tag, MPI_COMM_WORLD, &status);
	
	//Parameter 1 - the place in process 1 that will store the message
	//Parameter 2 - maximum size for the place
	//Parameter 3 - who sent the message
	//Parameter 4 - 
	//Parameter 5 - 
	//Parameter 6 - 
	//Parameter 7 -
	
	cout << my_rank << " " << message << endl;
	
	// Shut down MPI
	MPI_Finalize();

	return 0;
}
