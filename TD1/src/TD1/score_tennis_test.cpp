#include "score_tennis.hpp"
#include <gtest/gtest.h>

TEST(TennisTestSuite, EarlyScoreNotEqual)
{
    EXPECT_EQ("THIRTY-FIFTEEN", calcul_score(2,1));
    EXPECT_EQ("FIFTEEN-THIRTY", calcul_score(1,2));
}

TEST(TennisTestSuite, ScoreEqual)
{
    EXPECT_EQ("THIRTY-ALL", calcul_score(2,2));
    EXPECT_EQ("DEUCE", calcul_score(5,5));
}

TEST(TennisTestSuite, ScoreNotAccepted)
{
    ASSERT_FALSE(calcul_score(7,4).has_value());
    EXPECT_EQ("Impossible score!",calcul_score(7,4).error());
}

TEST(TennisTestSuite, ScoreAdvantage)
{
    EXPECT_EQ("ADVANTAGE PLAYER1", calcul_score(5,4));
}
