/**
 * Unit Tests for TicTacToeBoard
**/

#include <gtest/gtest.h>
#include "TicTacToeBoard.h"
 
class TicTacToeBoardTest : public ::testing::Test
{
	protected:
		TicTacToeBoardTest(){} 
		virtual ~TicTacToeBoardTest(){} 
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor) 
};

TEST(TicTacToeBoardTest, smoke_test)
{
    ASSERT_TRUE(true);
}


/*
	TOGGLE TURN TESTS
*/
TEST(TicTacToeBoardTest, X_takes_Thier_Turn)
{
	TicTacToeBoard game1;
	//Piece current = game1.turn; X always goes first
	Piece Answer = O;
	Piece turn1 = game1.toggleTurn();
	ASSERT_EQ(turn1, Answer);
}

TEST(TicTacToeBoardTest, O_takes_Thier_Turn)
{
	TicTacToeBoard game1;
	//Piece current = game1.turn; X always goes first
	Piece Answer = X;
	Piece turn1 = game1.toggleTurn();
	turn1 = game1.toggleTurn();
	ASSERT_EQ(turn1, Answer);
}

/*
	PLACE PIECE TESTS
*/

TEST(TicTacToeBoardTest, X_Places_Piece_begin)//happy test
{
	TicTacToeBoard game1;
	//Piece current = game1.turn; X always goes first
	Piece Answer = X;
	Piece turn1 = game1.placePiece(0,0);
	ASSERT_EQ(turn1, Answer);
}
TEST(TicTacToeBoardTest, X_Places_Piece_end) //happy
{
	TicTacToeBoard game1;
	//Piece current = game1.turn; X always goes first
	Piece Answer = X;
	Piece turn1 = game1.placePiece(2,2);
	ASSERT_EQ(turn1, Answer);
}

TEST(TicTacToeBoardTest, X_Places_Piece_OOB)//sad test
{
	TicTacToeBoard game1;
	//Piece current = game1.turn; X always goes first
	Piece Answer = Invalid;
	Piece turn1 = game1.placePiece(4,4);
	ASSERT_EQ(turn1, Answer);
}

TEST(TicTacToeBoardTest, X_Places_Piece_OOB_branch_2)//sad test
{
	TicTacToeBoard game1;
	//Piece current = game1.turn; X always goes first
	Piece Answer = Invalid;
	Piece turn1 = game1.placePiece(1,4);
	ASSERT_EQ(turn1, Answer);
}


/*
	GET PIECE TESTS
*/

TEST(TicTacToeBoardTest, X_Get_Piece_begin)//happy test
{
	TicTacToeBoard game1;
	//Piece current = game1.turn; X always goes first
	Piece Answer = X;
	Piece turn1 = game1.placePiece(0,0);
	turn1 = game1.getPiece(0,0);
	ASSERT_EQ(turn1, Answer);
}

TEST(TicTacToeBoardTest, O_Get_Piece_end) //happy
{
	TicTacToeBoard game1;
	//Piece current = game1.turn; X always goes first
	Piece Answer = O;
	Piece turn1 = game1.placePiece(0,0);
	turn1 = game1.placePiece(2,2);
	turn1 = game1.getPiece(2,2);
	ASSERT_EQ(turn1, Answer);
}

TEST(TicTacToeBoardTest, X_Get_Piece_OOB)//sad test
{
	TicTacToeBoard game1;
	//Piece current = game1.turn; X always goes first
	Piece Answer = Invalid;
	Piece turn1 = game1.getPiece(4,4);
	ASSERT_EQ(turn1, Answer);
}

TEST(TicTacToeBoardTest, X_Get_Piece_OOB_branch_2)//sad test
{
	TicTacToeBoard game1;
	//Piece current = game1.turn; X always goes first
	Piece Answer = Invalid;
	Piece turn1 = game1.getPiece(1,4);
	ASSERT_EQ(turn1, Answer);
}

TEST(TicTacToeBoardTest, X_Get_Piece_Empty_spot)//sad test
{
	TicTacToeBoard game1;
	//Piece current = game1.turn; X always goes first
	Piece Answer = Blank;
	Piece turn1 = game1.getPiece(1,2);
	ASSERT_EQ(turn1, Answer);
}

/*
	GET WINNER TESTS
*/

TEST(TicTacToeBoardTest, X_Win_top_row)//happy test
{
	TicTacToeBoard game1;
	//Piece current = game1.turn; X always goes first
	Piece Answer = X;
	Piece turn1 = game1.placePiece(0,0);
	turn1 = game1.getPiece(0,0);
	ASSERT_EQ(turn1, Answer);
}

TEST(TicTacToeBoardTest, Game_Not_Over_No_winner)//happy test
{
	TicTacToeBoard game1;
	//Piece current = game1.turn; X always goes first
	Piece Answer = Invalid;
	Piece turn1 = game1.placePiece(0,0);
	turn1 = game1.getWinner();
	ASSERT_EQ(turn1, Answer);
}

TEST(TicTacToeBoardTest, Game_Over_No_winner)//happy test
{
	TicTacToeBoard game1;
	//Piece current = game1.turn; X always goes first
	Piece Answer = Invalid;
	Piece turn1 = game1.placePiece(0,0);//x
	Piece turn1 = game1.placePiece(0,0);//o
	Piece turn1 = game1.placePiece(0,0);//x
	Piece turn1 = game1.placePiece(0,0);//o
	Piece turn1 = game1.placePiece(0,0);//x
	Piece turn1 = game1.placePiece(0,0);//o
	Piece turn1 = game1.placePiece(0,0);//x
	Piece turn1 = game1.placePiece(0,0);//o
	Piece turn1 = game1.placePiece(0,0);//x
	/*
	xxo
	oox
	xox
	*/
	turn1 = game1.getWinner();
	ASSERT_EQ(turn1, Answer);
}