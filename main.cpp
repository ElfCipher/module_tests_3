#include "solver.h"
#include <gtest/gtest.h>

TEST(SOLVER_TEST, A_EQ_ZERO)
{
    double a = 0.0;
    EXPECT_ANY_THROW(Solver::Solve(a));
}

TEST(SOLVER_TEST, NO_ROOTS)
{
    double a = 1.0, b = 0.0, c = 1.0;
    EXPECT_TRUE(Solver::Solve(a, b, c).empty());
}

TEST(SOLVER_TEST, TWO_ROOTS)
{
    double a = 1.0, b = 0.0, c = -1.0;
    double first_root = 1.0, second_root = -1.0;
    auto roots = Solver::Solve(a, b, c);
    EXPECT_EQ(roots.size(), 2);
    EXPECT_DOUBLE_EQ(roots[0], first_root);
    EXPECT_DOUBLE_EQ(roots[1], second_root);
}

TEST(SOLVER_TEST, ONLY_ROOT)
{
    double a = 1e-5, b = 2e-5, c = 1e-7;
    double root = -1.0;
    auto roots = Solver::Solve(a, b, c);
    EXPECT_EQ(roots.size(), 1);
    EXPECT_DOUBLE_EQ(roots[0], root);
}

TEST(SOLVER_TEST, NAN_CHECK)
{
    double a = 0.0/0.0;
    EXPECT_ANY_THROW(Solver::Solve(a));
}

int main(int argc, char* argv[])
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
