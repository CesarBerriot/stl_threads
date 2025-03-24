extern "C" {
	#include "stl_threads.h"
}
#include <thread>
#include <mutex>

template<typename procedure_type, typename... procedure_argument_types>
static stlt_thread run(procedure_type, procedure_argument_types...);

stlt_thread stlt_run_basic(stlt_basic_thread_procedure procedure)
{	return run(procedure);
}

stlt_thread stlt_run_advanced(stlt_advanced_thread_procedure procedure, void * thread_procedure_argument)
{	return run(procedure, thread_procedure_argument);
}

void stlt_join(stlt_thread thread)
{	std::thread * stl_thread = (std::thread*)thread;
	stl_thread->join();
	delete stl_thread;
}

stlt_mutex stlt_mutex_construct(void)
{	return (stlt_mutex)new std::mutex;
}

void stlt_mutex_lock(stlt_mutex mutex)
{	((std::mutex*)mutex)->lock();
}

void stlt_mutex_unlock(stlt_mutex mutex)
{	((std::mutex*)mutex)->unlock();
}

void stlt_mutex_destruct(stlt_mutex mutex)
{	delete (std::mutex*)mutex;
}

template<typename procedure_type, typename... procedure_argument_types>
static stlt_thread run(procedure_type procedure, procedure_argument_types... procedure_arguments)
{
	return (stlt_thread)new std::thread(procedure, procedure_arguments...);
}
