#ifndef ENTRY_H
#define ENTRY_H

#include "emotion_tag.h"
#include <vector>
#include <string>

class Entry {
private:
    std::string text;
    std::string date;
    std::vector<EmotionTag> emotions;
    std::string trigger;

public:
    Entry(std::string t, std::vector<EmotionTag> e, std::string trig);

    void display() const;
    std::string getPrimaryEmotion() const;
    std::string toString() const;

    std::string getDate() const;       // ✅ needed for viewing by date
    void setDate(const std::string&);  // ✅ needed when loading from file
};

#endif


