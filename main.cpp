#include "solver.h"
#include <gtest/gtest.h>

TEST(SOLVER_TEST, A_EQ_ZERO)
{
    double a = 0.0;
    try
    {
        auto res = Solver::Solve(a);
        if(!res.empty())
            FAIL();
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << '\n';
    }
}

TEST(SOLVER_TEST, NO_ROOTS)
{
    double a = 1.0, b = 0.0, c = 1.0;
    EXPECT_TRUE(Solver::Solve(a, b, c).empty());
}

int main(int argc, char* argv[])
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
