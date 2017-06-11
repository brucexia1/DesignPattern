#include <gtest/gtest.h>
#include "lru.h"

TEST(lrutest, a)
{
    LRU lru;
    EXPECT_EQ(2, lru.Foo());
}
