#include <Arduino.h>

class Record {
  char** instructions;
  int count;

public:
  Record() {
    count = 0;
    instructions = NULL;
  }

  ~Record() {
    free(instructions);
  }

  void play() {
    for(int i = 0; i < count; i++) {
      switch(instructions[i][0]) {
        case 'S':
        case 'E':
        case 'P': break;
        case 'D': actions::move_to_default(); break;
        case 'R': 
        case 'T': break;
      };
    }
  }

  void push(char* instr) {
    count++;

    if(instructions) {
      instructions = malloc(count * sizeof(char**));
    } else {
      instructions = realloc(instructions, count * sizeof(char**));
    }

    instructions[count] = instr;
  }

  void pop() {
    if(!instructions) {
      count--;
      instructions = realloc(instructions, count * sizeof(char**));
    }
  }
};