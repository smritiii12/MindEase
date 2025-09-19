#include "entry.h"
#include <iostream>
#include <ctime>
#include <sstream>

Entry::Entry(std::string t, std::vector<EmotionTag> e, std::string trig) {
    text = t;
    emotions = e;
    trigger = trig;

    // Get current time as string
    time_t now = time(0);
    date = ctime(&now);
    date.pop_back(); // remove newline character
}

void Entry::display() const {
    std::cout << "\n=== Journal Entry ===\n";
    std::cout << "Date      : " << date << "\n";
    std::cout << "Text      : " << text << "\n";
    std::cout << "Trigger   : " << trigger << "\n";
    std::cout << "Emotions  : ";
    for (const auto& e : emotions) {
        std::cout << e.name << "(" << e.intensity << ") ";
    }
    std::cout << "\n=====================\n";
}


std::string Entry::getPrimaryEmotion() const {
    return emotions.empty() ? "Neutral" : emotions[0].name;
}

std::string Entry::toString() const {
    std::stringstream ss;
    ss << "Date: " << date << "\n";
    ss << "Text: " << text << "\n";
    ss << "Trigger: " << trigger << "\n";
    ss << "Emotions: ";
    for (auto e : emotions) {
        ss << e.name << "(" << e.intensity << ") ";
    }
    ss << "\n";
    return ss.str();
}
std::string Entry::getDate() const {
    return date;
}

void Entry::setDate(const std::string& d) {
    date = d;
}


