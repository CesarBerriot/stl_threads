#pragma once

typedef void * stlt_thread;
typedef void * stlt_mutex;

typedef void(*stlt_basic_thread_procedure)(void);
typedef void(*stlt_advanced_thread_procedure)(void*);

stlt_thread stlt_run_basic(stlt_basic_thread_procedure);
stlt_thread stlt_run_advanced(stlt_advanced_thread_procedure, void * thread_procedure_argument);
void stlt_join(stlt_thread);

stlt_mutex stlt_mutex_construct(void);
void stlt_mutex_lock(stlt_mutex);
void stlt_mutex_unlock(stlt_mutex);
void stlt_mutex_destruct(stlt_mutex);
