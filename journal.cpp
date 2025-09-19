#include "journal.h"
#include <fstream>
#include <sstream>
#include <iostream>

void Journal::addEntry(const Entry& entry) {
    entries.push_back(entry);
}

void Journal::viewEntriesByEmotion(const std::string& emotionName) const {
    bool found = false;
    for (const auto& e : entries) {
        if (e.getPrimaryEmotion() == emotionName) {
            e.display();
            found = true;
        }
    }
    if (!found) {
        std::cout << "No entries found with emotion: " << emotionName << "\n";
    }
}

void Journal::saveToFile(const std::string& filename) const {
    std::ofstream file(filename);
    for (const auto& e : entries) {
        file << e.toString() << "---\n"; // separator for each entry
    }
    file.close();
}

void Journal::loadFromFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file) {
        std::cout << "No saved data found.\n";
        return;
    }

    std::string line, text, trigger, date;
    std::vector<EmotionTag> emotions;
    while (getline(file, line)) {
        if (line.find("Date: ") == 0)
            date = line.substr(6);
        else if (line.find("Text: ") == 0)
            text = line.substr(6);
        else if (line.find("Trigger: ") == 0)
            trigger = line.substr(9);
        else if (line.find("Emotions: ") == 0) {
            emotions.clear();
            std::string emoLine = line.substr(10);
            std::stringstream ss(emoLine);
            std::string part;
            while (ss >> part) {
                size_t l = part.find('(');
                size_t r = part.find(')');
                if (l != std::string::npos && r != std::string::npos) {
                    std::string name = part.substr(0, l);
                    int intensity = stoi(part.substr(l + 1, r - l - 1));
                    emotions.push_back(EmotionTag(name, intensity));
                }
            }
        } else if (line == "---") {
            Entry e(text, emotions, trigger);
            e.setDate(date);  // Set the actual loaded date
            addEntry(e);
        }
    }
    file.close();
}

std::vector<Entry> Journal::getAllEntries() const {
    return entries;
}

// ✅ NEW FUNCTION: Search by Date
void Journal::viewEntriesByDate(const std::string& date) const {
    bool found = false;
    for (const auto& e : entries) {
        if (e.getDate().find(date) != std::string::npos) {
            e.display();
            found = true;
        }
    }
    if (!found) {
        std::cout << "No entries found for the given date.\n";
    }
}
