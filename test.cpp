#include "gtest/gtest.h"
#include "chess.h"
#include "figures.h"

TEST(FigureTest, PawnInit) {
  Pawn pawn = Pawn(2, 0, 'w');
  ASSERT_EQ(pawn.get_col(), 0);
  ASSERT_EQ(pawn.get_row(), 2);
  ASSERT_EQ(pawn.get_color(), 'w');
  ASSERT_EQ(pawn.to_char(), 'P');
}


int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
