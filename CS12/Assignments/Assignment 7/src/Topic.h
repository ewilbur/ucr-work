//  ============== BEGIN ASSESSMENT HEADER ===============
/// @file assn<7>/Topic.h
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


#ifndef TOPIC_H_
#define TOPIC_H_

#include "Message.h"

class Topic : public Message
{
	public:
		Topic();
		Topic(const std::string&,
		      const std::string&,
		      const std::string&,
		      unsigned id);

		virtual bool is_reply() const {return false;};
		virtual std::string to_formatted_string() const;
};
#endif	// TOPIC_H_
