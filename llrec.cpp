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
    //adds value grater than pivot to larger list 
    if((head->val) > pivot){
      head->next = larger;
      larger = head; 
    }
    //adds value less than to smaller list 
    else if(head->val <= pivot){
      head->next = smaller;
      smaller = head;
    }

    head = NULL;
  }
}

