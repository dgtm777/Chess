#include "gtest/gtest.h"
#include "chess.h"
#include "figures.h"

TEST(CreateFigureTest, PawnInit) {
  Pawn pawn = Pawn(2, 0, 'w');
  ASSERT_EQ(pawn.get_col(), 0);
  ASSERT_EQ(pawn.get_row(), 2);
  ASSERT_EQ(pawn.get_color(), 'w');
  ASSERT_EQ(pawn.to_char(), 'P');
}
TEST(CreateFigureTest, HorseInit) {
  Horse horse = Horse(2, 0, 'w');
  ASSERT_EQ(horse.get_col(), 0);
  ASSERT_EQ(horse.get_row(), 2);
  ASSERT_EQ(horse.get_color(), 'w');
  ASSERT_EQ(horse.to_char(), 'H');
}
TEST(CreateFigureTest, RookInit) {
  Rook rook = Rook(2, 0, 'w');
  ASSERT_EQ(rook.get_col(), 0);
  ASSERT_EQ(rook.get_row(), 2);
  ASSERT_EQ(rook.get_color(), 'w');
  ASSERT_EQ(rook.to_char(), 'R');
}
TEST(CreateFigureTest, ElephantInit) {
  Elephant elephant = Elephant(2, 0, 'w');
  ASSERT_EQ(elephant.get_col(), 0);
  ASSERT_EQ(elephant.get_row(), 2);
  ASSERT_EQ(elephant.get_color(), 'w');
  ASSERT_EQ(elephant.to_char(), 'E');
}
TEST(CreateFigureTest, KingInit) {
  King king = King(2, 0, 'w');
  ASSERT_EQ(king.get_col(), 0);
  ASSERT_EQ(king.get_row(), 2);
  ASSERT_EQ(king.get_color(), 'w');
  ASSERT_EQ(king.to_char(), 'K');
}
TEST(CreateFigureTest, QueenInit) {
  Queen queen = Queen(2, 0, 'w');
  ASSERT_EQ(queen.get_col(), 0);
  ASSERT_EQ(queen.get_row(), 2);
  ASSERT_EQ(queen.get_color(), 'w');
  ASSERT_EQ(queen.to_char(), 'Q');
}


TEST(check_turn_Test, PawnOneCell) {
  Pawn pawnW1 = Pawn(0, 1, 'w');
  Pawn pawnW2 = Pawn(2, 1, 'w');
  Pawn pawnW3 = Pawn(7, 1, 'w');
  Pawn pawnB1 = Pawn(5, 0, 'b');
  Pawn pawnB2 = Pawn(1, 0, 'b');
  Pawn pawnB3 = Pawn(6, 0, 'b');
  EXPECT_EQ(pawnW1.check_turn(1, 1, '0'), false);
  EXPECT_EQ(pawnW2.check_turn(1, 1, '0'), true);
  EXPECT_EQ(pawnW3.check_turn(6, 1, '0'), false);
  EXPECT_EQ(pawnB1.check_turn(6, 0, 'b'), false);
  EXPECT_EQ(pawnB2.check_turn(2, 0, '0'), true);
  EXPECT_EQ(pawnB3.check_turn(7, 0, '0'), true);
}
TEST(check_turn_Test, PawnTwoCell) {
  Pawn pawnB1 = Pawn(1, 0, 'b');
  Pawn pawnB2 = Pawn(3, 0, 'b');
  Pawn pawnB3 = Pawn(1, 1, 'b');
  Pawn pawnW1 = Pawn(6, 0, 'w');
  Pawn pawnW2 = Pawn(3, 3, 'w');
  Pawn pawnW3 = Pawn(6, 1, 'w');
  EXPECT_EQ(pawnW1.check_turn(4, 0, '0'), true);
  EXPECT_EQ(pawnW2.check_turn(1, 3, '0'), false);
  EXPECT_EQ(pawnW3.check_turn(4, 1, '0'), true);
  EXPECT_EQ(pawnB1.check_turn(3, 0, 'b'), false);
  EXPECT_EQ(pawnB2.check_turn(5, 0, '0'), false);
  EXPECT_EQ(pawnB3.check_turn(3, 1, '0'), true);
}
TEST(check_turn_Test, PawnEat) {
  Pawn pawnB0 = Pawn(3, 4, 'b');
  Pawn pawnW1 = Pawn(4, 5, 'w');
  Pawn pawnW2 = Pawn(4, 3, 'w');
  Pawn pawnW3 = Pawn(2, 3, 'w');
  Pawn pawnW4 = Pawn(2, 5, 'w');

  Pawn pawnW0 = Pawn(2, 2, 'w');
  Pawn pawnW00 = Pawn(1, 3, 'w');
  Pawn pawnB2 = Pawn(3, 1, 'b');
  Pawn pawnB3 = Pawn(3, 3, 'b');
  Pawn pawnB4 = Pawn(1, 1, 'b');
  EXPECT_EQ(pawnB0.check_turn(4, 5, 'w'), true);
  EXPECT_EQ(pawnB0.check_turn(4, 3, 'w'), true);
  EXPECT_EQ(pawnB0.check_turn(2, 3, 'w'), false);
  EXPECT_EQ(pawnB0.check_turn(2, 5, 'w'), false);
  EXPECT_EQ(pawnB2.check_turn(4, 2, '0'), false);
  EXPECT_EQ(pawnW0.check_turn(3, 3, 'b'), false);
  EXPECT_EQ(pawnW0.check_turn(3, 1, 'b'), false);
  EXPECT_EQ(pawnW0.check_turn(1, 3, 'w'), false);
  EXPECT_EQ(pawnW0.check_turn(1, 1, 'b'), true);
  EXPECT_EQ(pawnW00.check_turn(2, 4, '0'), false);
}
TEST(check_turn_Test, Horse) {
  Horse horseW1 = Horse(4, 4, 'w');
  Horse horseB1 = Horse(2, 3, 'b');
  Pawn pawnW = Pawn(3, 2, 'w');
  Pawn pawnB = Pawn(3, 1, 'b');
  EXPECT_EQ(horseW1.check_turn(2, 3, 'b'), true);
  EXPECT_EQ(horseW1.check_turn(2, 5, '0'), true);
  EXPECT_EQ(horseW1.check_turn(3, 2, 'w'), false);
  EXPECT_EQ(horseW1.check_turn(5, 2, '0'), true);
  EXPECT_EQ(horseW1.check_turn(6, 5, '0'), true);
  EXPECT_EQ(horseW1.check_turn(6, 3, '0'), true);
  EXPECT_EQ(horseW1.check_turn(5, 6, '0'), true);
  EXPECT_EQ(horseW1.check_turn(3, 6, '0'), true);
  EXPECT_EQ(horseW1.check_turn(7, 7, '0'), false);
  EXPECT_EQ(horseB1.check_turn(3, 5, '0'), true);
  EXPECT_EQ(horseB1.check_turn(3, 1, 'b'), false);
  EXPECT_EQ(horseB1.check_turn(1, 5, '0'), true);
  EXPECT_EQ(horseB1.check_turn(1, 1, '0'), true);
  EXPECT_EQ(horseB1.check_turn(4, 4, '0'), true);
  EXPECT_EQ(horseB1.check_turn(4, 2, '0'), true);
  EXPECT_EQ(horseB1.check_turn(0, 4, '0'), true);
  EXPECT_EQ(horseB1.check_turn(0, 2, '0'), true);
  EXPECT_EQ(horseB1.check_turn(7, 7, '0'), false);

}
TEST(check_turn_Test, Rook) {
  Rook rookW1 = Rook(4, 4, 'w');
  Rook rookB1 = Rook(4, 3, 'b');
  Pawn pawnW = Pawn(4, 7, 'w');
  Pawn pawnB = Pawn(3, 3, 'b');
  EXPECT_EQ(rookW1.check_turn(4, 7, 'w'), false);
  EXPECT_EQ(rookW1.check_turn(4, 3, 'b'), true); 
  EXPECT_EQ(rookW1.check_turn(2, 4, '0'), true);
  EXPECT_EQ(rookW1.check_turn(6, 4, '0'), true);
  EXPECT_EQ(rookW1.check_turn(7, 7, '0'), false);


  EXPECT_EQ(rookB1.check_turn(4, 4, '0'), true);
  EXPECT_EQ(rookB1.check_turn(4, 0, '0'), true); 
  EXPECT_EQ(rookB1.check_turn(3, 3, 'b'), false);
  EXPECT_EQ(rookB1.check_turn(0, 3, '0'), true);
  EXPECT_EQ(rookB1.check_turn(7, 7, '0'), false);

}

TEST(check_turn_Test, Elephant) {
  Elephant elephantW1 = Elephant(4, 4, 'w');
  Elephant elephantB1 = Elephant(3, 3, 'b');
  EXPECT_EQ(elephantW1.check_turn(7, 7, 'w'), false);
  EXPECT_EQ(elephantW1.check_turn(3, 3, 'b'), true); 
  EXPECT_EQ(elephantW1.check_turn(2, 6, '0'), true);
  EXPECT_EQ(elephantW1.check_turn(6, 2, '0'), true);
  EXPECT_EQ(elephantW1.check_turn(6, 7, '0'), false);


  EXPECT_EQ(elephantB1.check_turn(4, 4, 'w'), true);
  EXPECT_EQ(elephantB1.check_turn(0, 0, '0'), true); 
  EXPECT_EQ(elephantB1.check_turn(2, 4, 'b'), false);
  EXPECT_EQ(elephantB1.check_turn(4, 2, '0'), true);
  EXPECT_EQ(elephantB1.check_turn(7, 6, '0'), false);
}

TEST(check_turn_Test, King) {
  King kingB1 = King(0, 4, 'b');
  King kingW1 = King(7, 4, 'w');
  EXPECT_EQ(kingB1.check_turn(0, 5, 'b'), false);
  EXPECT_EQ(kingB1.check_turn(1, 5, 'w'), true); 
  EXPECT_EQ(kingB1.check_turn(1, 4, '0'), true);
  EXPECT_EQ(kingB1.check_turn(0, 3, '0'), true);
  EXPECT_EQ(kingB1.check_turn(1, 3, '0'), true);
  EXPECT_EQ(kingB1.check_turn(6, 2, '0'), false);
  EXPECT_EQ(kingB1.check_turn(0, 2, '0'), true);
  EXPECT_EQ(kingB1.check_turn(0, 6, '0'), true);
  EXPECT_EQ(kingB1.check_turn(6, 7, '0'), false);


  EXPECT_EQ(kingW1.check_turn(7, 5, 'b'), true);
  EXPECT_EQ(kingW1.check_turn(6, 5, '0'), true); 
  EXPECT_EQ(kingW1.check_turn(6, 4, 'w'), false);
  EXPECT_EQ(kingW1.check_turn(7, 3, '0'), true);
  EXPECT_EQ(kingW1.check_turn(7, 3, '0'), true); 
  EXPECT_EQ(kingW1.check_turn(2, 2, 'b'), false);
  EXPECT_EQ(kingW1.check_turn(7, 2, '0'), true);
  EXPECT_EQ(kingW1.check_turn(7, 6, '0'), true);
  EXPECT_EQ(kingW1.check_turn(7, 7, '0'), false);
}

TEST(check_turn_Test, Queen) {
  Queen queenB1 = Queen(4, 3, 'b');
  Queen queenW1 = Queen(3, 4, 'w');
  EXPECT_EQ(queenB1.check_turn(6, 5, 'b'), false);
  EXPECT_EQ(queenB1.check_turn(3, 4, 'w'), true); 
  EXPECT_EQ(queenB1.check_turn(4, 5, '0'), true);
  EXPECT_EQ(queenB1.check_turn(7, 3, '0'), true);
  EXPECT_EQ(queenB1.check_turn(2, 1, '0'), true);
  EXPECT_EQ(queenB1.check_turn(0, 3, '0'), true);
  EXPECT_EQ(queenB1.check_turn(5, 2, '0'), true);
  EXPECT_EQ(queenB1.check_turn(4, 6, '0'), true);
  EXPECT_EQ(queenB1.check_turn(6, 7, '0'), false);

  EXPECT_EQ(queenW1.check_turn(4, 3, 'b'), true);
  EXPECT_EQ(queenW1.check_turn(5, 6, '0'), true); 
  EXPECT_EQ(queenW1.check_turn(5, 4, 'w'), false);
  EXPECT_EQ(queenW1.check_turn(3, 7, '0'), true);
  EXPECT_EQ(queenW1.check_turn(1, 2, '0'), true); 
  EXPECT_EQ(queenW1.check_turn(3, 0, 'b'), true);
  EXPECT_EQ(queenW1.check_turn(2, 5, '0'), true);
  EXPECT_EQ(queenW1.check_turn(6, 4, '0'), true);
  EXPECT_EQ(queenW1.check_turn(7, 6, '0'), false);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
