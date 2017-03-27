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

    return 0;
}

int SSTF(int requests[], int position, int direction){
    return 0;
}

int SCAN(int requests[], int position, int direction){
    return 0;
}

int LOOK(int requests[], int position, int direction){
    return 0;
}
