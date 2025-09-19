#ifndef SUGGESTION_ENGINE_H
#define SUGGESTION_ENGINE_H

#include <string>

class SuggestionEngine {
public:
    static std::string getSuggestion(const std::string& journalText);
};

#endif

