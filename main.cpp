#include <iostream>
#include <vector>
#include <string>
#include "entry.h"
#include "journal.h"
#include "suggestion_engine.h"

using namespace std;

int main() {
    Journal myJournal;
    myJournal.loadFromFile("data.txt");

while (true) {
    int choice;
    cout << "\n==== MindEase Menu ====\n";
    cout << "1. Add Journal Entry\n";
    cout << "2. View All Entries\n";
    cout << "3. Search by Emotion\n";
    cout << "4. Search by Date (e.g., 2025-06-27)\n";
    cout << "5. Exit\n";
    cout << "Enter your choice: ";

    if (!(cin >> choice)) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Invalid input. Please enter a number.\n";
        continue;
    }
    cin.ignore(); // flush newline

    if (choice == 1) {
        string text, trigger;
        int emoCount;
        vector<EmotionTag> emotions;

        cout << "Write your journal text:\n";
        getline(cin, text);

        cout << "What triggered these feelings?\n";
        getline(cin, trigger);

        cout << "How many emotions do you want to tag? ";
        while (!(cin >> emoCount)) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Please enter a valid number: ";
        }
        cin.ignore();

        for (int i = 0; i < emoCount; ++i) {
            string emoName;
            int intensity;

            cout << "Emotion " << i + 1 << " name: ";
            getline(cin, emoName);

            cout << "Intensity (1-10): ";
            while (!(cin >> intensity)) {
                cin.clear();
                cin.ignore(1000, '\n');
                cout << "Enter a number (1-10): ";
            }
            cin.ignore();

            emotions.push_back(EmotionTag(emoName, intensity));
        }

        Entry newEntry(text, emotions, trigger);
        myJournal.addEntry(newEntry);
        myJournal.saveToFile("data.txt");

        cout << "\n[OK] Entry saved successfully!\n";
        string suggestion = SuggestionEngine::getSuggestion(newEntry.getPrimaryEmotion());
        cout << "[Suggestion] " << suggestion << "\n";

    } else if (choice == 2) {
        cout << "\nAll Journal Entries:\n";
        vector<Entry> entries = myJournal.getAllEntries();
        for (const auto& e : entries) {
            e.display();
        }

    } else if (choice == 3) {
        string searchEmotion;
        cout << "Enter emotion to search: ";
        getline(cin, searchEmotion);
        myJournal.viewEntriesByEmotion(searchEmotion);

    } else if (choice == 4) {
        string searchDate;
        cout << "Enter date to search (e.g., 2025-06-27): ";
        getline(cin, searchDate);
        myJournal.viewEntriesByDate(searchDate);

    } else if (choice == 5) {
        cout << "Exiting MindEase. Take care!\n";
        break;

   } else {
        cout << "Invalid choice. Please enter a number from 1 to 5.\n";
    }
} // ✅ CLOSES main()

return 0;
}




