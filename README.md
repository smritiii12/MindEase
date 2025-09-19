# MindEase: CLI-Based Mental Wellness Journal

## Project Overview
MindEase is a mental wellness journaling application designed to help users track their emotions, reflect on their daily experiences, and receive motivational insights. The project combines a C++ command-line interface (CLI) for journaling with Python-based sentiment analysis and motivational quote suggestions. A GUI prototype is also partially implemented using Windows Forms.

## Features
- **Structured Journaling:** Add, view, and manage daily journal entries with timestamps.  
- **Emotion Tagging:** Tag entries with emotions for better self-awareness.  
- **Sentiment Analysis:** Python integration with TextBlob to analyze the sentiment of journal entries.  
- **Motivational Quotes:** Receive motivational quotes based on mood and sentiment.  
- **Local File Storage:** All entries and data are stored locally for privacy.  
- **GUI Prototype:** Partial Windows Forms interface for a more user-friendly experience.

## System Architecture
1. **CLI Module (C++):** Handles journaling input, viewing, and file management.  
2. **Python Module:** Performs sentiment analysis and generates motivational suggestions.  
3. **GUI Prototype (Windows Forms):** Experimental interface for future enhancements.  

## Technologies & Libraries Used
- **C++** – Core CLI development  
- **Python** – Sentiment analysis using TextBlob  
- **Visual Studio Windows Forms** – GUI prototype  
- **Local File Handling** – Data storage and retrieval  

## Objectives
- Encourage regular journaling for mental well-being.  
- Provide sentiment-based insights and motivational support.  
- Enable a simple, secure, and private journaling experience.  
- Explore integration of CLI and Python-based analytical tools.  

## How to Run
### CLI Version:
```bash
# Compile the C++ code
g++ MindEase.cpp -o MindEase

# Run the application
./MindEase
