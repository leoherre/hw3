#include "llrec.h"

//*********************************************
// Provide your implementation of llpivot below
//*********************************************
void llpivot (Node*& head, Node*& smaller, Node*& larger, int pivot){
  if(head == NULL){
    return;
  }
  else{
    llpivot(head->next,smaller,larger,pivot);
    if(head->next > pivot){
      head->next = larger;
      larger = head; 
    }
    else if(head-> <= pivot){
      head->next = smaller;
      smaller = head;
    }

    head = NULL;
  }
}

