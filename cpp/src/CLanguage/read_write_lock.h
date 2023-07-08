#ifndef READ_WRITE_LOCK_H
#define READ_WRITE_LOCK_H
#include <pthread.h>

pthread_rwlock_t test_lock;

typedef struct {
    pthread_mutex_t mutex;
    pthread_cond_t cond_readers;
    pthread_cond_t cond_writers;
    int readers;
    int writers;
    int writer_waiting;
} rwlock_t;

void rwlock_init(rwlock_t *lock) {
    lock->readers = 0;
    lock->writers = 0;
    lock->writer_waiting = 0;
    pthread_mutex_init(&(lock->mutex), NULL);
    pthread_cond_init(&(lock->cond_readers), NULL);
    pthread_cond_init(&(lock->cond_writers), NULL);
}

void rwlock_read_lock(rwlock_t *lock) {
    pthread_mutex_lock(&(lock->mutex));
    while (lock->writers > 0 || lock->writer_waiting > 0) {
        pthread_cond_wait(&(lock->cond_readers), &(lock->mutex));
    }
    lock->readers++;
    pthread_mutex_unlock(&(lock->mutex));
}

void rwlock_read_unlock(rwlock_t *lock) {
    pthread_mutex_lock(&(lock->mutex));
    lock->readers--;
    if (lock->readers == 0 && lock->writer_waiting > 0) {
        pthread_cond_signal(&(lock->cond_writers));
    }
    pthread_mutex_unlock(&(lock->mutex));
}

void rwlock_write_lock(rwlock_t *lock) {
    pthread_mutex_lock(&(lock->mutex));
    lock->writer_waiting++;
    while (lock->readers > 0 || lock->writers > 0) {
        pthread_cond_wait(&(lock->cond_writers), &(lock->mutex));
    }
    lock->writer_waiting--;
    lock->writers++;
    pthread_mutex_unlock(&(lock->mutex));
}

void rwlock_write_unlock(rwlock_t *lock) {
    pthread_mutex_lock(&(lock->mutex));
    lock->writers--;
    if (lock->writer_waiting > 0) {
        pthread_cond_signal(&(lock->cond_writers));
    } else {
        pthread_cond_broadcast(&(lock->cond_readers));
    }
    pthread_mutex_unlock(&(lock->mutex));
}

#endif /*READ_WRITE_LOCK_H*/