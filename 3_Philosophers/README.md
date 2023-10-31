> 본 프로그램은 Mac OS 에 최적화되어 있습니다

![cat](https://github.com/SikPang/42Seoul/assets/87380790/c0f4c908-a649-4456-96b7-eb43704bb797)

# Assignment Overview

- <a href="https://en.wikipedia.org/wiki/Dining_philosophers_problem" target="_blank">Dining philosophers problem </a>
- One or more philosophers sit at a round table.

  There is a large bowl of spaghetti in the middle of the table.
- The philosophers alternatively eat, think, or sleep.

  While they are eating, they are not thinking nor sleeping;

  while thinking, they are not eating nor sleeping;

  and, of course, while sleeping, they are not eating nor thinking.
- There are also forks on the table. There are as many forks as philosophers.
- Because serving and eating spaghetti with only one fork is very inconvenient,

  a philosopher takes their right and their left forks to eat, one in each hand.
- When a philosopher has finished eating, they put their forks back on the table and start sleeping.

  Once awake, they start thinking again. The simulation stops when a philosopher dies of starvation.
- Every philosopher needs to eat and should never starve.
- Philosophers don’t speak with each other.
- Philosophers don’t know if another philosopher is about to die.
- No need to say that philosophers should avoid dying!


# Usage
```
./philo [number of philosophers] [time to die] [time to eat] [time to sleep]
```

### Mandatory (Multi-thread with Mutex)
```
cd philo && make && ./philo 4 410 200 200
```

### Bonus (Multi-process with Semaphore)
```
cd philo_bonus && make && ./philo_bonus 4 410 200 200
```

# Screen shots
![philo](https://github.com/SikPang/42Seoul/assets/87380790/89cb5aa4-6cd8-4e30-b861-11811fdbb687)
- timestamp_in_ms X has taken a fork
- timestamp_in_ms X is eating
- timestamp_in_ms X is sleeping
- timestamp_in_ms X is thinking
- timestamp_in_ms X died


![캡처](https://github.com/SikPang/42Seoul/assets/87380790/faf8159c-8b50-4b73-957d-1dfb3ecd8c6f)
