#include <stdio.h>
#include <stdlib.h>
#include <ucontext.h>

#include "thread.h"

typedef unsigned int thread_id;
typedef ucontext_t uthread_ctx_t;

typedef enum {
	STATE_RUNNING,
	STATE_READY,
	STATE_BLOCKED,
} thread_state;

/* Thread Control Block */
struct thread_control_block {
	thread_id tid;
	thread_state state;
	thread_ctx ctx;
	int retval;
	struct thread_control_block *join;
};

struct thread_mutex {
	int lock;
}

// TODO: implement a queue for threads.
thr_queue all_threads;
thr_queue ready_threads;

struct thread_control_block init_thr;
struct thread_control_block *cur_thr;

struct thread_mutex *thr_lock;
thr_lock.lock=0;

int thread_create(struct thread *thr, void *func, void *arg){

}

int thread_start(struct thread *thr){

}

int thread_join(struct thread *thr){

}

int thread_stop(struct thread *thr){

}

int thread_exit(struct thread *thr){

}

bool thread_mutex_lock(struct thread_mutex *mutex){
	if(thr_lock.lock==0){
		thr_lock.lock=1;
		return true
	}
	return false;
}

bool thread_mutex_unlock(struct thread_mutex *mutex){
	if(thr_lock.lock==1){
		thr_lock.lock=0;
		return true
	}
	return false;
}