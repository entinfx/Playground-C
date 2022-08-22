//
//  structs.c
//  c_playground
//
//  Created by Constantine Shatalov on 9/28/18.
//  Copyright © 2018 Hexocat. All rights reserved.
//

#include "structs.h"

void structs() {
    /* Create single struct object */
    Person p1;
    puts("Enter the name:");

    // Input of unknown length ATTEMPT #1
    // char *p1Name = NULL;
    // scanf("%ms", &p1Name); // m measures the size of user input and allocates memory in p1Name

    // Input of unknown length ATTEMPT #2 (limit buffer, realloc if usr used less, cut input if used more
    int acceptedLength = 10;
    char *p1Name = (char *)malloc(acceptedLength * sizeof(char));
    fgets(p1Name, acceptedLength, stdin);
    p1Name = realloc(p1Name, strlen(p1Name) * sizeof(char));

    // Input of unknown length ATTEMPT #3 (weird since structs would have to point to stack)
    // int acceptedLength = 10;
    // char p1Name[acceptedLength];
    // fgets(p1Name, acceptedLength, stdin);

    personInit(&p1, p1Name, 22);
    personDisplay(&p1);
    free(p1Name);

    /* Array of Structs */
    Person *randPeople = randPersonArray(5);
    for (int i = 0; i < 5; i++) {
        printf("Name: %s, Age: %d\n", (*(randPeople + i)).name, (*(randPeople + i)).age);
        free((*(randPeople + i)).name); // free the strings used by each struct
    }
    free(randPeople);
}

Person *randPersonArray(int count) {
    Person *people = malloc(count * sizeof(Person));
    for (int i = 0; i < count; i++) {
        Person tempPerson;
        int wordLength = 6;
        // The following works, but a better design would probably
        // be to allocate the string inside the randWord.
        tempPerson.name = (void *)malloc(wordLength * sizeof(char *));
        randWord(tempPerson.name, wordLength);
        tempPerson.age = rand() % (66 - 18) + 18; // 18 to 65, ruby analogy: (0...47).each do |n|; n += 18; # n is each result
        *(people + i) = tempPerson; // TODO: Might leak memory
    }
    return people;
}

void personDisplay(Person *person) {
    // printf("Struct %p\n* %s* %d\n", person, person->name, person->age);
    // `person->name` is same as `(*person).name`
    printf("Struct %p\n* %s* %d\n", person, (*person).name, (*person).age);
}

void personInit(Person *person, char *name, int age) {
    person->name = name;
    person->age = age;
}
