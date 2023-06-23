#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SET_SIZE 10

typedef struct {
    int elements[MAX_SET_SIZE];
    int size;
} Set;

Set createSet() {
    Set s;
    s.size = 0;
    return s;
}

void addElement(Set* s, int element) {
    if (s->size < MAX_SET_SIZE) {
        s->elements[s->size] = element;
        s->size++;
    }
}

int inSet(Set* s, int element) {
    int i;
    for (i = 0; i < s->size; i++) {
        if (s->elements[i] == element) {
            return 1;
        }
    }
    return 0;
}

Set generateSet() {
    Set s = createSet();
    int element, i;
    for (i = 0; i < MAX_SET_SIZE; i++) {
        element = rand() % 10 + 1; 
        addElement(&s, element);
    }
    return s;
}

Set unionSets(Set* s1, Set* s2) {
    Set s = createSet();
    int i;
    for (i = 0; i < s1->size; i++) {
        addElement(&s, s1->elements[i]);
    }
    for (i = 0; i < s2->size; i++) {
        if (!inSet(&s1, s2->elements[i]) && !inSet(&s, s2->elements[i])) {
            addElement(&s, s2->elements[i]);
        }
    }
    return s;
}

Set intersectionSets(Set* s1, Set* s2) {
    Set s = createSet();
    int i;
    for (i = 0; i < s1->size; i++) {
        if (inSet(&s2, s1->elements[i]) && !inSet(&s, s1->elements[i])) {
            addElement(&s, s1->elements[i]);
        }
    }
    return s;
}

void printSet(Set* s) {
    int i;
    printf("{");
    for (i = 0; i < s->size; i++) {
        printf("%d", s->elements[i]);
        if (i < s->size - 1) {
            printf(", ");
        }
    }
    printf("}\n");
}

int main() {
    srand(time(NULL)); 
    Set s1 = generateSet();
    Set s2 = generateSet();
    Set unionSet = unionSets(&s1, &s2);
    Set intersectionSet = intersectionSets(&s1, &s2);
    printf("Set 1: ");
    printSet(&s1);
    printf("Set 2: ");
    printSet(&s2);
    printf("Union: ");
    printSet(&unionSet);
    printf("Intersection: ");
    printSet(&intersectionSet);

    return 0;
}
