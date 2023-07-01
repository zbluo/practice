#include "posix_semaphore/test.h"

#include <iostream>
#include <semaphore.h>
#include <fcntl.h>
#include <unistd.h>

int testSemaphore()
{
    const char *semaphoreName = "./my_semaphore";
    const int initialVal = 1; // Initial semaphore value

    // Create or open the semaphore
    sem_t *semaphore = sem_open(semaphoreName, O_CREAT, 0644, initialVal);
    if (semaphore == SEM_FAILED)
    {
        std::cout << "Semaphore creation/opening failed." << std::endl;
        return 1;
    }
    for (int i = 0; i < 10; i++)
    {
        // Acquire the semaphore (decrement its value)
        sem_wait(semaphore);

        // Critical section - shared resource access
        std::cout << "Critical section: Resource is being accessed by ";
        pid_t pid = getpid();
        std::cout << "Process ID: " << pid << std::endl;
        sleep(1); // Simulating some work in the critical section

        // Release the semaphore (increment its value)
        sem_post(semaphore);
    }
    // Clean up and close the semaphore
    sem_close(semaphore);
    sem_unlink(semaphoreName);

    return 0;
}