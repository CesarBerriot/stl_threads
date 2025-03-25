#include <gtest/gtest.h>
extern "C" {
	#include <stl_threads.h>
}
#include <thread>

static int value;

static void sleep(int milliseconds);

TEST(thread, basic)
{	stlt_thread thread = stlt_run_basic
	(	[]
		{	sleep(200);
			value = 1;
		}
	);
	sleep(100);
	ASSERT_EQ(value, 0);
	stlt_join(thread);
	ASSERT_EQ(value, 1);
}

static void sleep(int milliseconds)
{	std::this_thread::sleep_for(std::chrono::milliseconds(milliseconds));
}
