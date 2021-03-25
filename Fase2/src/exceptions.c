#include "initialize.h"
#include "../include/include.h"




/*create a new process as a child of the caller*/
int SYSCALL(int a, state_t *statep, support_t *supportp, int d){

    pcb_PTR newProcess = allocPcb(); 
    newProcess->p_s.status = &statep;
    newProcess->p_supportStruct = &supportp;
    insertProcQ(&readyQueue, newProcess);
    insertChild(currentProcess, newProcess);
    newProcess->p_time = 0;
    newProcess->p_semAdd = NULL;
    if(newProcess == NULL) return -1;
    else return 0;
}
