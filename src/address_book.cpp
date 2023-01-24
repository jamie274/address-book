#include "include/address_book.h"
#include <stdexcept>
#include <algorithm>

void AddressBook::add(AddressBook::Entry person){
	entries.push_back(person);
	//throw std::runtime_error("Not implemented");
}

void AddressBook::remove(AddressBook::Entry person) {
	auto it = remove_if(entries.begin(), entries.end(), [person](Entry p) {return person.first_name == p.first_name; });
	entries.erase(it, entries.end());
	//throw std::runtime_error("Not implemented");
}

std::vector<AddressBook::Entry> AddressBook::sortedByFirstName() {
	sort(entries.begin(), entries.end(), [](Entry& entry1, Entry& entry2)
		{return entry1.first_name < entry2.first_name; });
	return entries;
	//throw std::runtime_error("Not implemented");
}

std::vector<AddressBook::Entry> AddressBook::sortedByLastName() {
	sort(entries.begin(), entries.end(), [](Entry& entry1, Entry& entry2)
		{return entry1.last_name < entry2.last_name; });
	return entries;
	//throw std::runtime_error("Not implemented");
}

std::vector<AddressBook::Entry> AddressBook::find(const std::string& name) {
	std::vector<Entry> matchingEntries;
	for (const auto &entry : entries) {
		if (entry.last_name.rfind(name,0) == 0 || entry.first_name.rfind(name, 0) == 0) {
			matchingEntries.push_back(entry);
		}
	}
	return matchingEntries;
	//throw std::runtime_error("Not implemented");
}
