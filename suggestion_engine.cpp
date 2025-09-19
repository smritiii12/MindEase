#include "suggestion_engine.h"
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>

// Convert text to lowercase
std::string toLower(const std::string& str) {
    std::string out = str;
    std::transform(out.begin(), out.end(), out.begin(), ::tolower);
    return out;
}

// Return a random string from a list
std::string getRandom(const std::vector<std::string>& options) {
    if (options.empty()) return "You're doing great. Keep going!";
    int idx = rand() % options.size();
    return options[idx];
}

// Random motivational quote
std::string getRandomQuote() {
    std::vector<std::string> quotes = {
        "You are stronger than you think.",
        "Every day may not be good, but there is something good in every day.",
        "The comeback is always stronger than the setback.",
        "It's okay to not be okay — just don't stay that way.",
        "Even the darkest night will end and the sun will rise.",
        "Progress, not perfection.",
        "You have survived 100 percent of your bad days."
    };
    return getRandom(quotes);
}

// Generate suggestion based on input journal text
std::string SuggestionEngine::getSuggestion(const std::string& journalText) {
    std::string text = toLower(journalText);
    srand(static_cast<unsigned>(time(0)));  // Seed for randomness

    if (text.find("exam") != std::string::npos || text.find("study") != std::string::npos) {
        return getRandom({
            "Take a deep breath. You've got this! Focus on what you've already prepared.",
            "Don't stress too much. Exams pass, but health and peace matter more.",
            "Try the Pomodoro technique or a short break — you'll come back stronger!"
        }) + "\nQuote: " + getRandomQuote();

    } else if (text.find("tired") != std::string::npos || text.find("fatigue") != std::string::npos) {
        return getRandom({
            "Your body is asking for care. Try a short nap or drink water.",
            "Take a quick walk or stretch — refresh your mind.",
            "Pause and recharge. Hustling without energy leads nowhere."
        }) + "\nQuote: " + getRandomQuote();

    } else if (text.find("overthink") != std::string::npos || text.find("worry") != std::string::npos) {
        return getRandom({
            "Writing down your worries is already a great start!",
            "Don't believe everything you think — thoughts aren't facts.",
            "Meditation or music might help you get out of the loop."
        }) + "\nQuote: " + getRandomQuote();

    } else if (text.find("fight") != std::string::npos || text.find("argue") != std::string::npos) {
        return getRandom({
            "Conflicts happen. What matters is how we grow from them.",
            "Give it space. Time heals many small wounds.",
            "You can't control others, but you can control how you respond."
        }) + "\nQuote: " + getRandomQuote();

    } else if (text.find("lonely") != std::string::npos || text.find("alone") != std::string::npos) {
        return getRandom({
            "You are loved, even if it doesn't feel like it right now.",
            "Reach out to someone — a friend, a stranger, or even a journal.",
            "It's okay to feel lonely. You're not the only one, and it will pass."
        }) + "\nQuote: " + getRandomQuote();

    } else if (text.find("happy") != std::string::npos || text.find("joy") != std::string::npos) {
        return getRandom({
            "Celebrate this moment — you earned it!",
            "Capture this joy. Write more when you're in this zone!",
            "Gratefulness multiplies happiness. Keep shining!"
        }) + "\nQuote: " + getRandomQuote();

    } else if (text.find("angry") != std::string::npos || text.find("irritated") != std::string::npos) {
        return getRandom({
            "Take a breath. Anger often hides hurt beneath.",
            "Step away from the trigger. Cool minds handle better.",
            "Write it all out — anger loses power when understood."
        }) + "\nQuote: " + getRandomQuote();

    } else if (text.find("breakup") != std::string::npos || text.find("heartbreak") != std::string::npos) {
        return getRandom({
            "Healing takes time. Be patient with your heart.",
            "You were whole before — and you will be again.",
            "Let it out. Tears are the body's way of washing pain."
        }) + "\nQuote: " + getRandomQuote();

    } else if (text.find("demotivate") != std::string::npos || text.find("unmotivated") != std::string::npos) {
        return getRandom({
            "It's okay to lose motivation — but don't lose sight of your 'why'.",
            "Progress isn't always visible. Just showing up matters.",
            "Small wins lead to big change. Try one tiny task right now!"
        }) + "\nQuote: " + getRandomQuote();

    } else if (text.find("give up") != std::string::npos || text.find("hopeless") != std::string::npos) {
        return getRandom({
            "You've made it this far. That already shows you're capable.",
            "Even on your worst days, you're still growing — silently, steadily.",
            "Rest if you must. But don't quit. Tomorrow might surprise you."
        }) + "\nQuote: " + getRandomQuote();

    } else if (text.find("self doubt") != std::string::npos || text.find("worthless") != std::string::npos) {
        return getRandom({
            "You are worthy. You don't have to prove your value to anyone.",
            "Self-doubt is normal — don't let it silence your potential.",
            "You've handled hard things before. You can handle this too."
        }) + "\nQuote: " + getRandomQuote();

    } else if (text.find("burnout") != std::string::npos || text.find("overwhelm") != std::string::npos) {
        return getRandom({
            "Your brain isn't a machine. You need breaks to be at your best.",
            "Say no without guilt. Your peace matters.",
            "It's okay to pause. Recovery is productive too."
        }) + "\nQuote: " + getRandomQuote();

    } else if (text.find("empty") != std::string::npos || text.find("numb") != std::string::npos) {
        return getRandom({
            "Feeling nothing is still feeling something. You're still here, and that matters.",
            "Sometimes numbness is your mind asking for peace. Be gentle with yourself.",
            "Keep going. Even small sparks can light the dark."
        }) + "\nQuote: " + getRandomQuote();
    }

    // Default suggestion
    return getRandom({
        "Every storm runs out of rain. You'll smile again soon.",
        "This too shall pass. Stay strong.",
        "You're not alone in this. Keep writing, keep healing."
    }) + "\nQuote: " + getRandomQuote();
}

