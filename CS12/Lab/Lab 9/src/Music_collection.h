#include <fstream>
#include <iostream>
#include <string>

using namespace std;

#ifndef MUSIC_COLLECTION_H_
#define MUSIC_COLLECTION_H_

class Tune
{
	private:
		string title;
	
	public:
		Tune();
		Tune(const string&);
		const string & get_title() const;
};

class Music_collection
{
	private:
		int number; // Number of songs in the collection
		int max;    // The number of tunes the collection can hold
		Tune *collection; // a dynamic aray of tunes

	public:
		Music_collection(); // Sets max to 100
		Music_collection(int); // sets max to the value of int
		Music_collection(const Music_collection&);
		~Music_collection();

		bool add_tune(const Tune&); // True if possible to add tune
		bool set_tune(int, const Tune&);

		Music_collection & operator=(const Music_collection&);
		friend ostream & operator<<(ostream&, const Music_collection&);
};

#endif    // MUSIC_COLLECTION_H_
