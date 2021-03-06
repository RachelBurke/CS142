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
	
//	int sum = 0;
//	for (int x = 0; x <= 100; x++)
//		sum += x;
//	cout << sum <<

	// Know the problem
	int n = 300000;
	double sum = 0;
	
	//Break the problem up
	int local_start = my_rank * (n/p) + 1;
	
	// Each process does its own local work;
	double local_sum = 0;
	for (int x = local_start; x < local_start + n/p; x++)
		local_sum += x;
	
	// Add up all local sum variables into one total on one processor
	//Set 0 as the overseer process
	
	if (my_rank != 0) 
		MPI_Send (&local_sum, 1, MPI_DOUBLE, 0, tag, MPI_COMM_WORLD);

	else {
		sum = local_sum;
		double temp;
		for (int x = 1; x < p; x++) {
			MPI_Recv (&temp, 1, MPI_DOUBLE, x, tag, MPI_COMM_WORLD, &status);
			sum += temp;			
		}
		cout << sum << endl;
	}

	
	// Shut down MPI
	MPI_Finalize();

	return 0;
}
