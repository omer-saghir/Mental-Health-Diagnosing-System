
# Mental Health Diagnosing System

[cite_start]This is an educational, menu-driven mental health self-assessment system implemented in **C++** using advanced **Data Structures and Algorithms (DSA)**[cite: 3, 4]. [cite_start]The system allows users to privately screen for common conditions like Depression, Anxiety, ADHD, and Autism through interactive, structured testing[cite: 2, 4].

# Features

### Customer Management
* [cite_start]**Interactive Testing:** Take structured yes/no assessments for multiple mental health conditions[cite: 3].
* [cite_start]**Dynamic Navigation:** Use "Back" functionality to revisit and change previous answers during a test using Stack logic[cite: 3].
* [cite_start]**Review & Edit:** Review all responses at the end of a session and modify them before final calculation[cite: 3].
* [cite_start]**Educational Insights:** View "Myths vs. Facts" and self-care tips tailored to each specific diagnosis[cite: 3].

### Diagnostic Management
* [cite_start]**Automated Scoring:** Calculate severity levels based on user responses using structured diagnostic models[cite: 3, 4].
* [cite_start]**Severity Categorization:** Efficiently determine if symptoms are Stable, Mild, or Severe using search algorithms[cite: 3].
* [cite_start]**Result Persistence:** Store and manage question-answer pairs throughout the session using dynamic memory[cite: 4].

### Technical Architecture (DSA & OOP)
* [cite_start]**Linked Lists:** Used to store and manage user answers with their corresponding question numbers[cite: 3, 4].
* [cite_start]**Stacks:** Implemented to enable the backward navigation (undo) feature during tests[cite: 3, 4].
* [cite_start]**Search Algorithms:** Binary Search is used to categorize scores into severity levels efficiently[cite: 3].
* [cite_start]**Inheritance & Polymorphism:** A modular base class (`MentalHealthTest`) allows for easy extension to new test types[cite: 4].

### Main Form
* [cite_start]**Main Menu Interface:** The central hub for selecting different tests (1–4) or exiting the system securely[cite: 4].

# Prerequisites

* [cite_start]**C++ compiler** (Visual Studio or standard GCC) [cite: 4]
