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
int SSTF(int position, int total_requests, int direction);
int SCAN(int position, int total_requests, int direction);
int LOOK(int position, int total_requests, int direction);
void show_requests(char* algorithm, int service_times[], int total_cylinders);

// Global Variables
int fcfs_requests[8] = {98, 183, 37, 122, 14, 124, 65, 67};
int sstf_requests[8] = {98, 183, 37, 122, 14, 124, 65, 67};
int scan_requests[8] = {98, 183, 37, 122, 14, 124, 65, 67};
int look_requests[8] = {98, 183, 37, 122, 14, 124, 65, 67};

int sstf_ord[8] = {-1, -1, -1, -1, -1, -1, -1, -1};
int scan_ord[8] = {-1, -1, -1, -1, -1, -1, -1, -1};
int look_ord[8] = {-1, -1, -1, -1, -1, -1, -1, -1};

int main(int argc, char* argv []){

        // Ensure correct commandline arguments
        if(argc != 3){
                printf("ERROR: Incorrect # of arguments. [Initial Disk Head Position] [LEFT | RIGHT]\n");
                return -1;
        }

        // Arbitrary disk # positions
        int requests[8] = {98, 183, 37, 122, 14, 124, 65, 67};
        int position = atoi(argv[1]);

        // left == 0, right == 1
        int direction = (argv[2] == "left" || argv[2] == "L") ? 0 : 1;

        int fcfs = FCFS(position, sizeof(fcfs_requests)/sizeof(fcfs_requests[0]), direction);
        int sstf = SSTF(position, sizeof(fcfs_requests)/sizeof(fcfs_requests[0]), direction);
        //int scan = SCAN(position, sizeof(fcfs_requests)/sizeof(fcfs_requests[0]), direction);
        //int look = LOOK(position, sizeof(fcfs_requests)/sizeof(fcfs_requests[0]), direction);
        
        show_requests("FCFS", fcfs_requests, fcfs);
        show_requests("SSTF", sstf_ord, sstf);
        //show_requests("SCAN", scan_requests, scan);
        //show_requests("LOOK", look_requests, look);

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

int SSTF(int position, int total_requests,  int direction){
        /*
         * Shortest seek time first
         * Selects the request within the minimum seek
         * time from the current head position. -- May cause starvation
         */
        int total_moves = 0;
        int current_pos = position;

        int i = 0;
        int j = 0;
        for(i; i < total_requests; i++){

                j = 0;
                int closest = 401;
                int closest_index = 0;

                printf("THE CURRENT POSITION IS: %d",current_pos);

                for(j; j < total_requests; j++){
                        int next_dist = abs(current_pos - sstf_requests[j]);
                        if(next_dist < closest){
                                closest = next_dist;
                                closest_index = j;
                        }

                }

                total_moves += closest;
                current_pos = sstf_requests[closest_index];

                sstf_ord[i] = current_pos;
                sstf_requests[closest_index] = 401;
        }

        return total_moves;
}

int SCAN(int position, int total_requests,  int direction){
        /*
         * The arm starts at one end of the disk and moves toward the other end
         * servicing requests until it gets to the other end of the disk
         * The head continuously scans back and forth along the disk.
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

int LOOK(int position, int total_requests,  int direction){
        /*
         * A version of scan, but the arm only goes as far as the last
         * request in each direction. Then reverses without going to the end.
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

void show_requests(char* algorithm, int service_times[], int total_cylinders){
        int i = 0;
        int total_requests = 8;

        printf("%s - DISK SCHEDULING ALGORITHM\n\n", algorithm);
                for(i; i < total_requests; i++){
                        printf("%s - servicing request: %d\n", algorithm, service_times[i]);
                }
        printf("%s - Total head movements = %d\n\n", algorithm, total_cylinders);
}
