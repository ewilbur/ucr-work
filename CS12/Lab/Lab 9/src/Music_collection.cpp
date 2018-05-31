#include "Music_collection.h"
#include <string>


Tune::Tune()
{
	/* The song with no name */
	title = "";
}

Tune::Tune(const string &n)
{
	/* Sets the title to some refrence of a string */
	title = n;
}

const string & Tune::get_title() const
{
	/* Basic getter function */
	return title;
}

Music_collection::Music_collection()
{
	/* Initialize a collection to hold at most 100 songs and
	 * allocate a section of memory to hold the songs */
	number = 0;
	max = 100;
	collection = new Tune[max];
}

Music_collection::Music_collection(int n)
{
	/* If they specify the maximum size then it will do that instead */
	number = 0;
	max = n;
	collection = new Tune[max];
}

Music_collection::Music_collection(const Music_collection &m)
{
	/* Copy constructor. Essentially copies the tunes to the new object */

	number = m.number;
	max = m.max;
	collection = new Tune[max];

	for(int i = 0; i < number; i++)
	{
		collection[i] = Tune(m.collection[i].get_title());
	}
}

Music_collection::~Music_collection()
{
	delete[] collection;
}

/* ========== MUTATORS ========== */

bool Music_collection::add_tune(const Tune &t)
{
	/* Adds a tune to the end of the Tune array if there is room.
	 * Will return true if the song was added (there is enough room
	 * in memory), otherwise this will return false. */
	if(max <= number)
		/* Not enough room to add a song */
		return false;
	else
	{
		/* We have room */
		collection[number] = t; // Adds tune to the end of the array.
		number++; // Increase the number of songs.
		return true;
	}
}

bool Music_collection::set_tune(int i, const Tune &t)
{
	/* Alters the Tune at index i to t. Returns true if the index is 
	 * in range amd false otherwise. */
	if(i < number && i >= 0)
	{
		/* We are given a valid index */
		collection[i] = t;
		return true;
	}

	else
		/* The index is not in the range of the array */
		return false;
}

/*  ========== Operators ========== */

ostream &operator<<(ostream &out, const Music_collection &m)
{
	for(int i = 0; i < m.number; i++)
	{
		/* Print the title of each Tune in collection */
		out << (m.collection[i].get_title()) << endl;
	}
	return out;
}

Music_collection & Music_collection::operator=(const Music_collection &m)
{
	this->number = m.number;
	this->max = m.max;

	/* Deallocate previously allocated memory when *this was initialized */
	delete[] this->collection;


	this->collection = new Tune[max]; // Reallocate new memory of new size
	for(int i = 0; i < number; i++)
	{
		/* Copy the Tunes */
		collection[i] = Tune(m.collection[i].get_title());
	}
}

