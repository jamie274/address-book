#include "include/address_book.h"
#include <stdexcept>
#include <algorithm>

void AddressBook::add(AddressBook::Entry person){
	entries.push_back(person); // adds person entry to entries vector
}

void AddressBook::remove(AddressBook::Entry person) {
	/* remove_if function used to remove every occurrence of the given person in the entries vector using lambda function
		by checking if each first name is equal to the provided entry from the paramater 'person' */
	auto it = remove_if(entries.begin(), entries.end(), 
		[person](Entry p) {return person.first_name == p.first_name; });
	entries.erase(it, entries.end()); // all occurences are erased up to the end of the vector (entries)
}

std::vector<AddressBook::Entry> AddressBook::sortedByFirstName() {
	/* sorts the entries vector by first name by using the lambda function to swap entries
	   when adjacent first names come before another first name in the alphabet */
	// (Quicksort sorting algorithm could have been used instead of built in sort function)
	sort(entries.begin(), entries.end(), [](Entry& entry1, Entry& entry2) // entries passed by reference
		{return entry1.first_name < entry2.first_name; }); // entries swapped
	return entries; // entries vector is returned 
}

std::vector<AddressBook::Entry> AddressBook::sortedByLastName() {
	/* sorts the entries vector by last name by using the lambda function to swap entries
	   when adjacent first names come before another last name in the alphabet */
	// (Quicksort sorting algorithm could have been used instead of built in sort function)
	sort(entries.begin(), entries.end(), [](Entry& entry1, Entry& entry2) // entries passed by reference
		{return entry1.last_name < entry2.last_name; }); // entries swapped
	return entries; // entries vector is returned
}

std::vector<AddressBook::Entry> AddressBook::find(const std::string& name) {
	std::vector<Entry> matchingEntries; // new vector created to store matching entries
	for (const auto &entry : entries) { // ranged for loop used to traverse the collection of entries in the vector (entries)
		/* rfind built in function used to check if the first or last names start with the given string name
		(name, 0) == 0 : name is passed and so is 0 as the name is checked from the beginning. 0 is checked as the return value to see if
		the given name string is contained at the beginning of the first or last name of the entry*/
		if (entry.last_name.rfind(name, 0) == 0 || entry.first_name.rfind(name, 0) == 0) { 
			matchingEntries.push_back(entry); // entry is added to vector (matchingEntries) if found
		}
	}
	return matchingEntries; // matching entries vector is returned
}
