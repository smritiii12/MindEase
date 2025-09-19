#ifndef JOURNAL_H
#define JOURNAL_H

#include "entry.h"
#include <vector>
#include <string>

class Journal {
private:
    std::vector<Entry> entries;

public:
    void addEntry(const Entry& entry);
    void viewEntriesByEmotion(const std::string& emotionName) const;
    void viewEntriesByDate(const std::string& date) const; // ✅ ADD THIS
    void saveToFile(const std::string& filename) const;
    void loadFromFile(const std::string& filename);
    std::vector<Entry> getAllEntries() const;
};


#endif
