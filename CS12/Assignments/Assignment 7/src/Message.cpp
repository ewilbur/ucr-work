//  ============== BEGIN ASSESSMENT HEADER ===============
/// @file assn<7>/Message.cpp
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


#include "Message.h"


using namespace std;



Message::Message()
: author(""),
  subject(""),
  body(""),
  id(0)
{}

Message::Message(const string &athr,
		 const string &sbjct,
		 const string &body,
		 unsigned id)
: author(athr),
  subject(sbjct),
  body(body),
  id(id)
{}


void Message::print(unsigned indentLevel) const
{
	string indent = "";

	for(unsigned i = 0; i < indentLevel; i++)
		indent += "  ";

	cout << indent << "Message #" << id << ": " << subject << endl;
	cout << indent << "from " << author << ": ";

	for(unsigned i = 0; i < body.size() - 1; i++)
	{
		if(body[i] == '\n')
			cout << '\n' << indent;

		else
			putchar(body[i]);
	}
	cout << endl;
	for(unsigned i = 0; i < child_list.size(); i++)
	{
		cout << endl;
		child_list[i]->print(indentLevel + 1);
	}
}

const string & Message::get_subject() const
{
	return subject;
}

unsigned Message::get_id() const
{
	return id;
}

void Message::add_child(Message *child)
{
	child_list.push_back(child);
}

