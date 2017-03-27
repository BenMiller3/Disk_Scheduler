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
int FCFS(int requests[], int position, int direction);
int SSTF(int requests[], int position, int direction);
int SCAN(int requests[], int position, int direction);
int LOOK(int requests[], int position, int direction);
void show_requests(char* algorithm, int service_times[], int total_cylinders);

int main(int argc, char* argv []){

        // Ensure correct commandline arguments 
        if(argc != 3){ 
            printf("ERROR: Incorrect # of arguments. [Initial Disk Head Position] [LEFT | RIGHT]\n");
            return -1;
        }

        // Arbitrary disk # positions
        int requests[8] = {98, 183, 37, 122, 14, 124, 65, 67};
        int init_pos = *argv[1];
        int direction;

        // left == 0, right == 1
        direction = (argv[2] == "left") ? 0 : 1;

        return 0;
}


int FCFS(int requests[], int position, int direction){
    /*
    * First come first serve
    * Scheduled on a first come first serve basis
    * Easiest and fair. Highly inefficient.
    */
    int total_requests = sizeof(requests);
    int head_movements = 0;

    for(total_requests; (total_requests - 1) >= 0; total_requests--){
        //printf("FCFS - servicing request: %d", requests[total_requests]);
    }

    return head_movements;
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

    printf("%s - DISK SCHEDULING ALGORITHM\n")
    for(i; i <= (sizeof(service_times) - 1); i++){
        printf("%s- servicing request: %d", algorithm, service_times[i])
    }
    printf("%s- Total head movements = %d", algorithm, total_cylinders); 
}
