#include <gtest/gtest.h>
extern "C" {
	#include <stl_threads.h>
}

static int value;

TEST(thread, advanced)
{	stlt_thread thread = stlt_run_advanced
	(	[](void * argument)
		{	ASSERT_EQ(argument, &value);
		},
		&value
	);
	stlt_join(thread);
}
