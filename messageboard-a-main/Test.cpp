
/**
 * @file Test.cpp
 * @author Avigael Abitbol
 * @brief tests for the second assignment messageboard
 * @date 2021-03-22
 * @copyright Copyright (c) 2021
 * 
 */

#include <string>
#include "doctest.h"
#include "Direction.hpp"
#include "Board.hpp"
using namespace ariel;
using namespace std;

TEST_CASE("Board changes") {
    Board board;
    CHECK_NOTHROW(board.post(3,3,Direction::Horizontal,"avigael"));
    CHECK_NOTHROW(board.post(3,3,Direction::Vertical,"avigael"));
    CHECK(board.read(3,3,Direction::Horizontal,7) == "avigael");
    CHECK(board.read(3,3,Direction::Vertical,7) == "avigael");
    CHECK_NOTHROW(board.post(3,3,Direction::Horizontal,"u"));
    CHECK(board.read(3,3,Direction::Horizontal,7) == "uvigael");
    CHECK(board.read(3,3,Direction::Vertical,7) == "uvigael");
    CHECK_NOTHROW(board.post(3,3,Direction::Horizontal,"uvigael"));
    CHECK(board.read(3,3,Direction::Horizontal,7) == "uvigael");
    CHECK(board.read(3,3,Direction::Vertical,7) == "uvigael");
    CHECK_NOTHROW(board.post(3,3,Direction::Horizontal,"pasta"));
    CHECK_NOTHROW(board.post(3,3,Direction::Vertical,"pasta"));
    CHECK(board.read(3,3,Direction::Horizontal,8) == "pasta");
    CHECK(board.read(3,3,Direction::Vertical,8) == "pasta");
}

TEST_CASE("Exceptions Error") {
    Board board;
    CHECK_THROWS(board.read(0,0,Direction::Horizontal,7));
    CHECK_THROWS(board.read(0,0,Direction::Vertical,8));
    CHECK_NOTHROW(board.post(0,0,Direction::Horizontal,"avi"));
    CHECK_NOTHROW(board.post(0,0,Direction::Vertical,"abi"));
    CHECK_THROWS(board.read(450,450,Direction::Horizontal,6));
    CHECK_THROWS(board.read(450,450,Direction::Vertical,17));
    CHECK_NOTHROW(board.post(450,450,Direction::Horizontal,"abiabi"));
    CHECK_NOTHROW(board.post(450,450,Direction::Vertical,"abiabi"));
    CHECK_NOTHROW(board.read(450,450,Direction::Horizontal,6));
    CHECK_NOTHROW(board.read(450,450,Direction::Vertical,6));
}



