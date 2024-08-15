#include <stdio.h>

int coordinator;

void up(int up, int *state, int PROCESS_COUNT) {
  if (state[up - 1]) {
    printf("process %d is already up\n", up);
  } else {
    int i;
    state[up - 1] = 1;
    printf("process %d held election\n", up);
    for (i = up; i <= PROCESS_COUNT; ++i) {
      printf("election message sent from process %d to process %d\n", up, i);
    }
    for (i = up + 1; i <= PROCESS_COUNT; ++i) {
      if (!state[i - 1])
        continue;
      printf("alive message sent from process %d to process %d\n", i, up);
      break;
    }
  }
}

void down(int down, int *state, int PROCESS_COUNT) {
  if (!state[down - 1]) {
    printf("process %d is already down\n", down);
  } else {
    state[down - 1] = 0;
  }
}

void mess(int mess, int *state, int PROCESS_COUNT) {
  if (state[mess - 1]) {
    if (state[PROCESS_COUNT - 1]) {
      printf("OK\n");
    } else if (!state[PROCESS_COUNT - 1]) {
      int i;
      printf("process %d election\n", mess);
      for (i = mess; i <= PROCESS_COUNT; ++i) {
        printf("election send from process %d to process %d\n", mess, i);
      }
      for (i = PROCESS_COUNT; i >= mess; --i) {
        if (!state[i - 1])
          continue;
        printf("Coordinator message send from process %d to all\n", i);
        break;
      }
    }
  } else {
    printf("Process %d is down\n", mess);
  }
}

int main() {
  int choice;
  printf("Enter number of active processes to take part in Bully Algo Election:\n");
  int process_cnt;
  scanf("%d", &process_cnt);
  int state[process_cnt];
  for (int i = 0; i < process_cnt; ++i) {
    state[i] = 1;
  }
  printf("%d active processes are:\n", process_cnt);
  printf("Processes up = p1 ....-> p%d\n", process_cnt);
  printf("Process %d is coordinator\n", process_cnt);
  do {
    printf(".........\n");
    printf("1. Up a process\n");
    printf("2. Down a process\n");
    printf("3. Send a message\n");
    printf("4. Exit\n");
    scanf("%d", &choice);
    switch (choice) {
      case 1: {
        printf("Bring process up\n");
        int up1;
        scanf("%d", &up1);
        if (up1 == process_cnt) {
          printf("Process %d is coordinator\n", process_cnt);
          state[process_cnt - 1] = 1;
          break;
        }
        up(up1, state, process_cnt);
        break;
      }
      case 2: {
        printf("Bring down any process\n");
        int down1;
        scanf("%d", &down1);
        down(down1, state, process_cnt);
        break;
      }
      case 3: {
        printf("Which process will send a message\n");
        int mess1;
        scanf("%d", &mess1);
        mess(mess1, state, process_cnt);
        break;
      }
    }
  } while (choice != 4);

  return 0;
}