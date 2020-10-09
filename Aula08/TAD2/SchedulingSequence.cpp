//NMEC: 93295
//NOME: João Diogo Videira Oliveira

// Complete the functions (marked by ...)
// so that it passes all tests in DateTimeTest.

#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "SchedulingSequence.h"

// You may add auxiliary definitions and declarations here, if you need to.



// Create a SchedulingSequence capable of storing up to (capacity) intervals.
SchedulingSequence* SchedulingSequenceCreate(int capacity) {//
  assert(capacity >= 0);
  // You must allocate space for the struct and for the intervals array!
  SchedulingSequence* instance = (SchedulingSequence*)malloc(sizeof(SchedulingSequence));

  TimeInterval** intervals = (TimeInterval**)malloc(capacity * sizeof(TimeInterval*));

  instance->intervals = intervals;
  instance->size = 0;
  instance->capacity = capacity;
  
  return instance;
}

// Destroy SchedulingSequence *pss
void SchedulingSequenceDestroy(SchedulingSequence **pss) {//
  assert(*pss != NULL);
  free((*pss)->intervals);
  free(*pss);
  *pss = NULL;
}

int SchedulingSequenceIsEmpty(SchedulingSequence *ss) {
  return ss->size == 0;
}

int SchedulingSequenceIsFull(SchedulingSequence *ss) {
  return ss->size == ss->capacity;
}

// Add interval *ti to *ss.
// Return true on success,
// return false if *ti overlaps any of the intervals in *ss.
int SchedulingSequenceAdd(SchedulingSequence *ss, TimeInterval *ti) {//
  assert(!SchedulingSequenceIsFull(ss));
  if(ss->size == 0){
    ss->intervals[ss->size] = ti;
    ss->size++;
    return 1;
  }
  int flag1 = 0;
  int flag2 = 0;
  for(int i = 0; i < ss->size; i++){
    flag1 = (TimeIntervalOverlaps(ti,ss->intervals[i]) || TimeIntervalContains(ti,ss->intervals[i]));
    if(flag1 == 1){
      return 0;
    }
  }
  if(flag1 == 0){
    for(int j = 0; j < ss->size; j++){
       int temp = DateTimeCompare(ti->start, (ss->intervals[j])->start); 
       if(temp < 0){
          ss->size++;
          for(int k = ss->size; k >= j;k--){
             ss->intervals[k] = ss->intervals[k-1];
          }
          ss->intervals[j] = ti;
          flag2 = 1;
          break;
       }
    }
    if(flag2 == 0){
      ss->intervals[ss->size] = ti;
      ss->size++;
    }
  }
  return 1;
}

// Get the interval at position (idx) of *ss.
// idx=0 is the first position idx=ss->size-1 is the last position.
// Precondition: 0 <= idx < ss->size.
TimeInterval *SchedulingSequenceGet(SchedulingSequence *ss, int idx) {//
  assert (0 <= idx && idx < ss->size);
  return ss->intervals[idx];
  
}

// Remove the interval at position (idx) of *ss, and return it.
// idx=0 is the first position idx=ss->size-1 is the last position.
// Precondition: 0 <= idx < ss->size.
TimeInterval *SchedulingSequencePop(SchedulingSequence *ss, int idx) {//
  assert (0 <= idx && idx < ss->size);
  // This implies !SchedulingSequenceIsEmpty(ss).
  TimeInterval* result = ss->intervals[idx];
  for (int i = idx; i < (ss->size-1); i++) {
    TimeInterval* tmp = *(&(ss->intervals[i]));
    *(&(ss->intervals[i])) = *(&(ss->intervals[i + 1]));
    *(&(ss->intervals[i + 1])) = tmp;
  }
  ss->size--;
  return result;
}

// You may add auxiliary definitions and declarations here, if you need to.


