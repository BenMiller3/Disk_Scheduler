/* Disk Scheduler Simulator - 3SH3 Assignment 3
 * ==============================================
 *
 *
 * By: Benjamin D. Miller
 *      001416516
 *      millebd
 */

#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

// Function definitions
int FCFS(int position, int total_requests, int direction);
int SSTF(int requests[], int position, int direction);
int SCAN(int requests[], int position, int direction);
int LOOK(int requests[], int position, int direction);
void show_requests(char* algorithm, int service_times[], int total_cylinders);

// Global Variables
int fcfs_requests[8] = {98, 183, 37, 122, 14, 124, 65, 67};
//int sstf_requests[8], scan_requests[8], look_requests[8] = fcfs_requests;

int main(int argc, char* argv []){

        // Ensure correct commandline arguments
        if(argc != 3){
                printf("ERROR: Incorrect # of arguments. [Initial Disk Head Position] [LEFT | RIGHT]\n");
                return -1;
        }

        // Arbitrary disk # positions
        int requests[8] = {98, 183, 37, 122, 14, 124, 65, 67};
        int position = *argv[1];
        // left == 0, right == 1
        int direction = (argv[2] == "left" || argv[2] == "L") ? 0 : 1;

        int fcfs = FCFS(position, sizeof(fcfs_requests)/sizeof(fcfs_requests[0]), direction);
        show_requests("FCFS", fcfs_requests, fcfs);

        return 0;
}


int FCFS(int position, int total_requests,  int direction){
        /*
         * First come first serve
         * Scheduled on a first come first serve basis
         * Easiest and fair. Highly inefficient.
         */
        int total_moves = 0;
        int current_pos = position;

        int i = 0;
        for(i; i < total_requests; i++){
                total_moves += abs(current_pos - fcfs_requests[i]);
                current_pos = fcfs_requests[i];
        }

        return total_moves;
}

int SSTF(int requests[], int position, int direction){
        /*
         * Shortest seek time first
         * Selects the request within the minimum seek
         * time from the current head position. -- May cause starvation
         */
        int total_requests = sizeof(requests);
        int head_movements = 0;

        for(total_requests; (total_requests - 1) >= 0; total_requests--){
                //printf("SSTF - servicing request: %d", requests[total_requests]);
        }

        return head_movements;
}

int SCAN(int requests[], int position, int direction){
        /*
         * The arm starts at one end of the disk and moves toward the other end
         * servicing requests until it gets to the other end of the disk
         * The head continuously scans back and forth along the disk.
         */
        int total_requests = sizeof(requests);
        int head_movements = 0;

        for(total_requests; (total_requests - 1) >= 0; total_requests--){
                //printf("SCAN - servicing request: %d", requests[total_requests]);
        }

        return head_movements;
}

int LOOK(int requests[], int position, int direction){
        /*
         * A version of scan, but the arm only goes as far as the last
         * request in each direction. Then reverses without going to the end.
         */
        int total_requests = sizeof(requests);
        int head_movements = 0;

        for(total_requests; (total_requests - 1) >= 0; total_requests--){
                //printf("LOOK - servicing request: %d", requests[total_requests]);
        }

        return head_movements;
}

void show_requests(char* algorithm, int service_times[], int total_cylinders){
        int i = 0;

        printf("%s - DISK SCHEDULING ALGORITHM\n\n", algorithm);
                for(i; i <= (sizeof(service_times) - 1); i++){
                        printf("%s- servicing request: %d\n", algorithm, service_times[i]);
                }
        printf("%s - Total head movements = %d\n", algorithm, total_cylinders);
}
