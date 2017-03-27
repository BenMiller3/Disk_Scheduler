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
        if(argv[2] == "left"){
            direction = 0;
        }
        else{
            direction = 1;
        }

        return 0;
}


int FCFS(int requests[], int position, int direction){
    int total_requests = sizeof(requests);
    int head_movements = 0;

    printf("FCFS DISK SCHEDULING ALGORITHM\n");
    for(total_requests; (total_requests - 1) >= 0; total_requests--){
        printf("FCFS - servicing request: %d", requests[total_requests]);
    }

    return head_movements;
}

int SSTF(int requests[], int position, int direction){
    int total_requests = sizeof(requests);
    int head_movements = 0;

    printf("SSTF DISK SCHEDULING ALGORITHM\n");
    for(total_requests; (total_requests - 1) >= 0; total_requests--){
        printf("SSTF - servicing request: %d", requests[total_requests]);
    }

    return head_movements;
}

int SCAN(int requests[], int position, int direction){
    int total_requests = sizeof(requests);
    int head_movements = 0;

    printf("SCAN DISK SCHEDULING ALGORITHM\n");
    for(total_requests; (total_requests - 1) >= 0; total_requests--){
        printf("SCAN - servicing request: %d", requests[total_requests]);
    }

    return head_movements;
}

int LOOK(int requests[], int position, int direction){
    int total_requests = sizeof(requests);
    int head_movements = 0;

    printf("LOOK DISK SCHEDULING ALGORITHM\n");
    for(total_requests; (total_requests - 1) >= 0; total_requests--){
        printf("LOOK - servicing request: %d", requests[total_requests]);
    }

    return head_movements;
}
