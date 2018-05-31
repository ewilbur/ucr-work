//  ============== BEGIN ASSESSMENT HEADER ===============
/// @file assn<7>/BBoard.h
/// @brief Assignment <7> for CS 12 <Fall 2015>
///
/// @author <Evan Wilbur> [ewilb001@ucr.edu]
/// @date <11/29/2015>
///
/// @par Enrollment Notes
///	 Lecture Section: <21>
/// @par
///	 Lab Section: <1>
/// @par
///	 TA: <Entezari>
///
/// @par Plagiarism Section
/// I hereby certify that the code in this file
/// is ENTIRELY my own original work.
//  ================== END ASSESSMENT HEADER ===============


#ifndef BBOARD_H_
#define BBOARD_H_

#include <string>
#include <vector>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include "User.h"
#include "Message.h"
#include "Topic.h"
#include "Reply.h"

class BBoard
{
	private:
		std::string title;
		std::vector<User> user_list;
		const User *current_user;
		std::vector<Message*> message_list;

		/* ===== Helper Functions ===== */
		void add_user(const std::string&, const std::string&);
		const User * get_user(const std::string&, const std::string&) const;
		void display() const;
		void add_topic();
		void add_reply();

	public:
		BBoard();
		BBoard(const std::string&);
		~BBoard();

		bool load_users(const std::string&);
		bool load_messages(const std::string&);
		bool save_messages(const std::string&);
		void login();
		void run();
};
#endif	// BBOARD_H_
