//  ============== BEGIN ASSESSMENT HEADER ===============
/// @file assn<7>/Message.h
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


#ifndef MESSAGE_H_
#define MESSAGE_H_

#include <vector>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <sstream>


class Message
{
	protected:
		std::string author;
		std::string subject;
		std::string body;
		unsigned id;
		std::vector<Message*> child_list;

	public:
		Message();
		Message(const std::string &athr,
			const std::string &sbjct,
			const std::string &body,
			unsigned id);

		virtual ~Message() {};

		virtual bool is_reply() const = 0;
		virtual std::string to_formatted_string() const = 0;

		void print(unsigned) const;
		const std::string & get_subject() const;
		unsigned get_id() const;
		void add_child(Message*);
};
#endif	// MESSAGE_H_
