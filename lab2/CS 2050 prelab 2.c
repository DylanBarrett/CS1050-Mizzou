#include <stdio.h>
#include <stdlib.h>
#include "Listinfo.h"

    int main()
    {
        struct listnode Grocerylist;

        Grocerylist.listnodelist = 1;
        puts("Enter the name of your list");
        gets(Grocerylist.indexOfLastItemOfList);

        return 0;
    }
int createList(List *list, int size) {
  list-> maxSizeOfList = size; //initialization phase
  list->indexOfLastItemOfList = -1;

  array=(float*)malloc(size*sizeof(float));
}

float addItem(float item, List l){
  l.array[++l.indexOfLastItemOfList] = item; //add item to the end of list
}

float getItem(int index, List l) {
  return l.array[l.indexOfLastItemOfList]; //return the indexed item
}

int sizeOfList(List l) {
  return l.indexOfLastItemOfList+1; // return statement
}

void deleteList(List *) {
  free(list->arraay); //free up array memory
  list-> maxSizeOfList = 0; //initialization phase
  list->indexOfLastItemOfList = -1;
  array = NULL;
}
