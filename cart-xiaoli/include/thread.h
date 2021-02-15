#ifndef _THREAD_H
#define _THREAD_H

int thread_create(struct thread *thr, void *func, void *arg);
int thread_start(struct thread *thr);
int thread_join(struct thread *thr);
int thread_stop(struct thread *thr);
int thread_exit(struct thread *thr);
bool thread_mutex_lock(struct thread_mutex *mutex);
bool thread_mutex_unlock(struct thread_mutex *mutex);

#endif