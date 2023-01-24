#pragma once

#include <string>
#include <vector>

/// The main Address Book implementation
class AddressBook {
public:
	/// A container for address book data
	struct Entry
	{
		std::string first_name;
		std::string last_name;
		std::string phone_number;
	};

	// vector container for the collection of entries in the address book
	std::vector<Entry> entries;

	/// Add an entry
	void add(Entry person);

	/// Remove an entry
	void remove(Entry person);

	/// Return all entries sorted by first names
	std::vector<Entry> sortedByFirstName();

	/// Return all entries sorted by last names
	std::vector<Entry> sortedByLastName();

	/// Return all matching entries
	std::vector<Entry> find(const std::string & name);
};