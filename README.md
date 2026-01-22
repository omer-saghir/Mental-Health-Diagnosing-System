This is an educational, menu-driven mental health self-assessment system implemented in C++ using advanced Data Structures and Algorithms (DSA). The system allows users to privately screen for common conditions like Depression, Anxiety, ADHD, and Autism through interactive, structured testing.

Features
Customer Management
Interactive Testing: Take structured yes/no assessments for multiple mental health conditions.

Dynamic Navigation: Use "Back" functionality to revisit and change previous answers during a test.

Review & Edit: Review all responses at the end of a session and modify them before final calculation.

Educational Insights: View "Myths vs. Facts" and self-care tips tailored to each specific diagnosis.

Diagnostic Management
Automated Scoring: Calculate severity levels based on user responses using structured diagnostic models.

Severity Categorization: Efficiently determine if symptoms are Stable, Mild, or Severe using search algorithms.

Result Persistence: Store and manage question-answer pairs throughout the session using dynamic memory.

Technical Architecture (DSA & OOP)
Linked Lists: Used to store and manage user answers with their corresponding question numbers.

Stacks: Implemented to enable the backward navigation (undo) feature during tests.

Search Algorithms: Binary Search is used to categorize scores into severity levels efficiently.

Inheritance & Polymorphism: A modular base class (MentalHealthTest) allows for easy extension to new test types.

Main Form
Main Menu Interface: The central hub for selecting different tests (1–4) or exiting the system securely.

Prerequisites
C++ compiler (Visual Studio or standard GCC)
