/* Disk Scheduler Simulator - 3SH3 Assignment 3
 * ==============================================
 *
 *      USAGE: [Initial Disk Head Position] [LEFT | RIGHT]
 *
 *      - Initial disk head position must be an integer,
 *      - LEFT or RIGHT specifies the disk direction
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
        int direction = (argv[2][0] == 'L' || argv[2][0] == 'l') ? 0 : 1;

        // Run the algorithms, and compute their total head movements, while changing global array variables
        int fcfs = FCFS(position, sizeof(fcfs_requests)/sizeof(fcfs_requests[0]), direction);
        int sstf = SSTF(position, sizeof(sstf_requests)/sizeof(sstf_requests[0]), direction);
        int scan = SCAN(position, sizeof(scan_requests)/sizeof(scan_requests[0]), direction);
        int look = LOOK(position, sizeof(look_requests)/sizeof(look_requests[0]), direction);
        
        // Print the ordered requests, total head movements for each algorithm and format them.
        show_requests("FCFS", fcfs_requests, fcfs);
        show_requests("SSTF", sstf_ord, sstf);
        show_requests("SCAN", scan_ord, scan);
        show_requests("LOOK", look_ord, look);

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
                int closest = 401; // Arbitrarily high so that the requests won't be serviced twice
                int closest_index = 0;

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
        int scanned_index = 0;
        int total_indicies = 8; // Length of the array.

        // If direction == 0 then the disk is pointing LEFT. Else, it's RIGHT
        if(direction == 0){
                // Scanning from current position to the left side of the disk.
                while(current_pos > 0 && scanned_index < total_indicies){
                        current_pos--;
                        total_moves++;

                        int i = 0;
                        for(i; i < 8; i++){
                                if(scan_requests[i] == current_pos){
                                        scan_ord[scanned_index] = current_pos;
                                        scanned_index++;
                                        scan_requests[i] = -1;
                                }
                        }
                }

                // Now scan from the left side of the disk to the right, or until all positions have been serviced.
                while(current_pos < 199 && scanned_index < total_indicies){
                        current_pos++;
                        total_moves++;

                        int i = 0;
                        for(i; i < total_indicies; i++){
                                if(scan_requests[i] == current_pos){
                                        scan_ord[scanned_index] = current_pos;
                                        scanned_index++;
                                        scan_requests[i] = -1;
                                }
                        }
                }
        }
        else{
                // Scan from current position to the right.
                while(current_pos < 199 && scanned_index < total_indicies){
                        current_pos++;
                        total_moves++;

                        int i = 0;
                        for(i; i < total_indicies; i++){
                                if(scan_requests[i] == current_pos){
                                        scan_ord[scanned_index] = current_pos;
                                        scanned_index++;
                                        scan_requests[i] = -1;
                                }
                        }
                }

                // scan from the right to the left, or until all jobs have been serviced.
                while(current_pos > 0 && scanned_index < total_indicies){
                        current_pos--;
                        total_moves++;

                        int i = 0;
                        for(i; i < total_indicies; i++){
                                if(scan_requests[i] == current_pos){
                                        scan_ord[scanned_index] = current_pos;
                                        scanned_index++;
                                        scan_requests[i] = -1;
                                }
                        }
                }
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
        int scanned_index = 0;
        int total_indicies = 8;

        // This algorithm is the exact same as SCAN with one minor difference.
        // Rather than going to the ends of the disk, it only goes as far as it needs to be serviced.
        // To compensate this, the min and max values in the requests array will be the upper and lower bounds.
        int lower_bound = look_requests[0];
        int upper_bound = look_requests[0];

        int i = 0;
        for(i; i < total_indicies; i++){
                if(look_requests[i] > upper_bound){
                        upper_bound = look_requests[i];
                }
                else if(look_requests[i] < lower_bound){
                        lower_bound = look_requests[i];
                }
        }

        // If direction == 0 then the disk is pointing LEFT. Else, it's RIGHT
        if(direction == 0){
                // Scanning from current position to as far left as we need to service.
                while(current_pos > lower_bound && scanned_index < total_indicies){
                        current_pos--;
                        total_moves++;

                        int i = 0;
                        for(i; i < total_indicies; i++){
                                if(look_requests[i] == current_pos){
                                        look_ord[scanned_index] = current_pos;
                                        scanned_index++;
                                        look_requests[i] = -1;
                                }
                        }
                }

                // Now scan to the right, or until all positions have been serviced.
                while(current_pos < upper_bound && scanned_index < total_indicies){
                        current_pos++;
                        total_moves++;

                        int i = 0;
                        for(i; i < total_indicies; i++){
                                if(look_requests[i] == current_pos){
                                        look_ord[scanned_index] = current_pos;
                                        scanned_index++;
                                        look_requests[i] = -1;
                                }
                        }
                }
        }
        else{
                // Scan from current position to the right.
                while(current_pos < upper_bound && scanned_index < total_indicies){
                        current_pos++;
                        total_moves++;

                        int i = 0;
                        for(i; i < total_indicies; i++){
                                if(look_requests[i] == current_pos){
                                        look_ord[scanned_index] = current_pos;
                                        scanned_index++;
                                        look_requests[i] = -1;
                                }
                        }
                }

                // scan from the right to the left, or until all jobs have been serviced.
                while(current_pos > lower_bound && scanned_index < total_indicies){
                        current_pos--;
                        total_moves++;

                        int i = 0;
                        for(i; i < total_indicies; i++){
                                if(look_requests[i] == current_pos){
                                        look_ord[scanned_index] = current_pos;
                                        scanned_index++;
                                        look_requests[i] = -1;
                                }
                        }
                }
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
