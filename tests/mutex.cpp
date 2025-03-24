#include <gtest/gtest.h>
extern "C" {
	#include <stl_threads.h>
}
#include <list>
#include <thread>

static stlt_mutex mutex;

static void procedure(void);

TEST(mutex, mutex)
{	mutex = stlt_mutex_construct();

	std::list<stlt_thread> threads;

	for(int i = 0; i < 40; ++i)
		threads.push_back(stlt_run_basic(procedure));

	for(stlt_thread thread : threads)
		stlt_join(thread);

	stlt_mutex_destruct(mutex);
}

static void procedure(void)
{	static int counter;
	stlt_mutex_lock(mutex);
	++counter;
	ASSERT_EQ(counter, 1);
	std::this_thread::sleep_for(std::chrono::milliseconds(50));
	--counter;
	stlt_mutex_unlock(mutex);
}
