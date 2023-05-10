#include<iostream>
#define NO_OF_INPUTS 100
#define MIN_SIZE 30
#define MAX_SIZE 1000


/// @brief 
/// @param order 1 = ascending, 2 = random (default), 3 = descending
void generate_array(int *array, int size, int order=2){
    // Seeding rand with time to avoid same sequence caused by rand having 1 as default seed. 
    srand(time(NULL)); 
    switch(order){
        case 1: // Best Case
        {
            int tmp = 1+rand()%NO_OF_INPUTS;
            array[0] = tmp;
            for (int i = 1; i<size; array[i++] = ++tmp);
            break;
        }
        case 2: // Average Case
        {
            for (int i = 0; i<size; i++){
                array[i] = 1+rand()%NO_OF_INPUTS;
            }
            break;
        }
        case 3: // Worst Case
        {
            int tmp = MIN_SIZE+rand()%NO_OF_INPUTS;
            array[0] = tmp;
            for (int i = 1; i<size; array[i++] = --tmp);
            break;
        }
        default:
            std::cerr<<"ERROR: Invalid `case_type`.\nAssign 1 for best, 2 for average, 3 for worst case";
            exit(0);
    }
}