#include <iostream>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
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
	
/* int a[5] = {4, 3, 2, 7, 1};
   int b[5] = {6, 4, 2, 7, 3};
   
   int dot_product = 0;
   
   for (int x = 0; x < 5; x++) {
	   dot_product += (a[x]*b[x]);  
   }
   */
   
   //Know the Problem
   srand(time(0));
   int n = 300000;
   int a [300000], b[300000];
   double dotproduct = 0;
   
   if (my_rank == 0) 
	   for (int x = 0; x < 300000; x++) {
		   a[x] = rand () % 8;
		   b[x] = rand () % 8;
	   }
	   
	// Divide the problem up
	// Assume 30 processors
	
	int local_a[10000], local_b[10000];
	int local_n = n/p;
	// What, How big, what type, where to put them, size, what type, who did it
	MPI_Scatter(&a[0], local_n, MPI_INT, local_a, local_n, MPI_INT, 0, MPI_COMM_WORLD);
	MPI_Scatter(&b[0], local_n, MPI_INT, local_b, local_n, MPI_INT, 0, MPI_COMM_WORLD);
	// After these commands, local_a and local_b have the right stuff in them for each process;
	
	// Do the local work for each process
	double = local_dot_product = 0;
	
	for (int x = 0; x < local_n; x++) {
		local_dot_product += local_a[x] * local_b[x];
	}
	
	// Glue the results together
	// Take all of these, put them together  here, by adding, put it on process 0
	MPI_Allreduce (&local_dot_product, &dot_product, 1, MPI_DOUBLE, MPI_SUM, 0, MPI_COMM_WORLD);
	
	if (my_rank == 0)
		cout << dot_product << endl;
	
	// Shut down MPI
	MPI_Finalize();

	return 0;
}
