#include <gtest/gtest.h>

#include "lib.h"

TEST(VersionTest, PatchVersion) {
    EXPECT_GE(version(), 1)  << "Version should be greater than 0";
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
