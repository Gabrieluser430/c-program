#include <stdio.h>
#include <string.h>
#include <inttypes.h>
#include <stdlib.h>
#define Class struct


Class Person {
	char name[10];
	uint8_t age;
	uint8_t height;
	void (*show)(Class Person *);
};

void printPerson(Class Person *self) {
	printf("%s %d %d\n", self->name, self->age, self->height);
}

Class Person * newPerson(
		char name[],
		uint8_t age,
		uint8_t height
		){
	Class Person *self = (Class Person *)malloc(sizeof(Class Person));
	strcpy(self -> name, name);
	self -> age = age;
	self -> height = height;
	self -> show = &printPerson;
	return self;
}

int main() {
	Class Person *somePerson = (Class Person *) newPerson("Gabriel", 19, 163);
	somePerson -> show(somePerson);
	return 0;
}
