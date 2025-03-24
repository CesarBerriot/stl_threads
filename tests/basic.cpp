#include <gtest/gtest.h>
extern "C" {
	#include <stl_threads.h>
}
#include <thread>

static int value;

TEST(thread, basic)
{	stlt_thread thread = stlt_run_basic
	(	[]
		{	std::this_thread::sleep_for(std::chrono::milliseconds(100));
			value = 1;
		}
	);
	ASSERT_EQ(value, 0);
	stlt_join(thread);
	ASSERT_EQ(value, 1);
}
