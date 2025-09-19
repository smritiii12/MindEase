#ifndef EMOTION_TAG_H
#define EMOTION_TAG_H

#include <string>
using namespace std;

class EmotionTag {
public:
    string name;
    int intensity;

    EmotionTag() {}

    EmotionTag(string n, int i) {
        name = n;
        intensity = i;
    }
};

#endif
