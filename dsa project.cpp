#include <iostream>
#include <string>
#include <cstdlib>
#include <stack>
using namespace std;
struct AnswerNode {
 int questionNumber;
 string answer;
 AnswerNode* next;
 AnswerNode(int q, string a) {
 questionNumber = q;
 answer = a;
 next = NULL;
 }
};
class AnswerLinkedList {
 AnswerNode* head;
public:
 AnswerLinkedList() {
 head = NULL;
 }

 void addAnswer(
int qNum, string ans) {
 AnswerNode* newNode = new AnswerNode(qNum, ans);
 if (head == NULL) {
 head = newNode;
 } else {
 AnswerNode* temp = head;
 while (temp->next != NULL) {
 temp = temp->next;
 }
 temp->next = newNode;
 }
 }

 void updateAnswer(int qNum, string newAns) {
 AnswerNode* temp = head;
 while (temp != NULL) {
 if (temp->questionNumber == qNum) {
 temp->answer = newAns;
 return;
 }
 temp = temp->next;
 }
 }

 string getAnswer(int qNum) {
 AnswerNode* temp = head;
 while (temp != NULL) {
 if (temp->questionNumber == qNum) {
 return temp->answer;
 }
 temp = temp->next;
 }
 return "";
 }

 void displayAllAnswers() {
 cout << "\n--- Your Answers ---\n";
 AnswerNode* temp = head;
 while (temp != NULL) {
 cout << "Question " << temp->questionNumber << ": " << temp->answer << endl;
 temp = temp->next;
 }
 cout << "-------------------\n";
 }

 int countYesAnswers() {
 int count = 0;
 AnswerNode* temp = head;
 while (temp != NULL) {
 if (temp->answer == "yes") {
 count++;
 }
 temp = temp->next;
 }
 return count;
 }
};
void clearScreen() {
 system("cls");
}
void printHeader() {
 cout <<
"\t\t\t\t\t***********************************************************\n\n";
}
string toLowerCase(string str) {
 string result = str;
 for (int i = 0; i < result.length(); i++) {
 result[i] = tolower(result[i]);
 }
 return result;
}
void showMyth(int type) {
 if (type == 0) {
 cout << "Myth: Only weak people suffer from mental health issues.\n";
 cout << "Fact: Mental health challenges can affect anyone, regardless of strength." << endl;
 } else if (type == 1) {
 cout << "\nMyth: People with anxiety should just calm down." << endl;
 cout << "Fact: Anxiety isn't a choice. It's a real mental health condition that often requires therapy, medication, or both." << endl;
 } else if (type == 2) {
 cout << "\nMyth: ADHD only affects kids and they just need to try harder." << endl;
 cout << "Fact: ADHD is a lifelong neurodevelopmental disorder that impacts focus, impulse control, and organization." << endl;
 } else if (type == 3) {
 cout << "\nMyth: All autistic people are either geniuses or completely nonverbal." << endl;
 cout << "Fact: Autism is a spectrum. People experience it in vastly different ways." <<
endl;
 }
}
class MentalHealthTest {
protected:
 AnswerLinkedList answerList;
 stack<int> navigationStack;
 string questions[5];
 string testName;
 int testType;

public:

 void diagnose() {
 showDiagnosisResults();
 offerAnswerChange();
 showDiagnosisResults();
}
void offerAnswerChange() {
 cout << "\nWould you like to change any answers and recalculate? (yes/no): ";
 string userChoice;
 cin >> userChoice;
 userChoice = toLowerCase(userChoice);

 if (userChoice == "yes") {
 clearScreen();
 cout << "\n--- Answer Change ---\n";
 answerList.displayAllAnswers();
 cout << "\nEnter question number to change (1-5), or 0 to finish: ";

 int questionToChange;
 while (true) {
 cin >> questionToChange;
 if (questionToChange == 0) {
 break;
 }
 if (questionToChange >= 1 && questionToChange <= 5) {
 cout << "Enter new answer for question " << questionToChange << " (yes/no): ";
 string newAnswer;
 cin >> newAnswer;
 newAnswer = toLowerCase(newAnswer);

 if (newAnswer == "yes" || newAnswer == "no") {
 answerList.updateAnswer(questionToChange, newAnswer);
 cout << "\nAnswer updated.\n";
 } else {
 cout << "Invalid input! Please enter only 'yes' or 'no'.\n";
 }
 } else {
 cout << "Please enter a valid question number (1-5) or 0 to finish.\n";
 }
 cout << "\nEnter another question number to change (1-5), or 0 to finish: ";
 }
 cout << "\nScore recalculated. New score: " << answerList.countYesAnswers() << endl;
 }
}



 virtual void showTips() {

 }

 void askQuestions() {
 clearScreen();
 printHeader();
 cout << "\t\t\t\t\t\t\t\t\t " << testName << " \n\n";
 printHeader();
 cout << "Instructions: Type 'yes' or 'no' to answer, 'back' to go to previous question, 'review' to see all answers\n";
 cout << "------------------------------------------------------------------------------------------------------------\n\n";

 for (int currentQuestion = 1; currentQuestion <= 5; currentQuestion++) {
 clearScreen();
 printHeader();
 cout << "\t\t\t\t\t\t\t\t\t " << testName << " \n\n";
 printHeader();
 cout << "Question " << currentQuestion << "/5\n\n";

 while (true) {
 cout << questions[currentQuestion - 1] << " (yes/no/back/review): ";
 string userAnswer;
 cin >> userAnswer;
 userAnswer = toLowerCase(userAnswer);

 if (userAnswer == "yes" || userAnswer == "no") {
 answerList.addAnswer(currentQuestion, userAnswer);
 navigationStack.push(currentQuestion);
 break;
 }
 else if (userAnswer == "back" && !navigationStack.empty()) {
 int previousQuestion = navigationStack.top();
 navigationStack.pop();
 currentQuestion = previousQuestion - 1;
 break;
 }
 else if (userAnswer == "review") {
 clearScreen();
 answerList.displayAllAnswers();
 cout << "\nPress Enter to continue...";
 cin.ignore();
 cin.get();

 clearScreen();
 printHeader();
 cout << "\t\t\t\t\t\t\t\t\t " << testName << " \n\n";
 printHeader();
 cout << "Question " << currentQuestion << "/5\n\n";
 }
 else {
 cout << "Invalid input! Please enter only: yes, no, back, or review\n";
 }
 }
 }
 }
 int binarySearchCategory(int score) {
 int thresholds[3] = {2, 4, 6};
 int left = 0, right = 2;
 int category = 0;
 while (left <= right) {
 int mid = (left + right) / 2;
 if (score < thresholds[mid]) {
 category = mid;
 right = mid - 1;
 } else {
 left = mid + 1;
 }
 }
 return category;
}
 void showDiagnosisResults() {
 clearScreen();
 printHeader();
 cout << "\t\t\t\t\t\t\t\t\tDiagnosis Result \n\n";
 printHeader();

 answerList.displayAllAnswers();
 int score = answerList.countYesAnswers();

 int category = binarySearchCategory(score);
 if (testType == 0) {
 if (category == 2)
 cout << "\nYou may be experiencing severe depression.\n";
 else if (category == 1)
 cout << "\nYou may be experiencing mild to moderate depression.\n";
 else
 cout << "\nYou seem to be mentally stable regarding depression.\n";
 }
 else if (testType == 1) {
 if (category == 2)
 cout << "\nYou may be experiencing severe anxiety.\n";
 else if (category == 1)
 cout << "\nYou may be experiencing mild to moderate anxiety.\n";
 else
 cout << "\nYou seem to be mentally stable regarding anxiety.\n";
 }
 else if (testType == 2) {
 if (category == 2)
 cout << "\nYou may be showing signs of strong ADHD traits.\n";
 else if (category == 1)
 cout << "\nYou may have mild to moderate ADHD symptoms.\n";
 else
 cout << "\nYou likely do not exhibit significant ADHD symptoms.\n";
 }
 else if (testType == 3) {
 if (category == 2)
 cout << "\nYou may show significant autism traits.\n";
 else if (category == 1)
 cout << "\nYou may exhibit some traits of autism spectrum.\n";
 else
 cout << "\nYou likely do not fall on the autism spectrum.\n";
 }

 cout << "Note: This is not a clinical diagnosis. Please consult a professional.\n";
 showMyth(testType);
}


};
class DepressionTest : public MentalHealthTest {
public:
 DepressionTest() {
 testName = "Depression Test";
 testType = 0;
 questions[0] = "1. Do you feel sad or empty most of the day?";
 questions[1] = "2. Have you lost interest in activities you once enjoyed?";
 questions[2] = "3. Do you feel tired or have little energy?";
 questions[3] = "4. Do you feel worthless or guilty?";
 questions[4] = "5. Do you have trouble concentrating?";
 }

 void diagnose() {
 showDiagnosisResults();
 }

 void showTips() {
 clearScreen();
 printHeader();
 cout << "\t\t\t\t\t\t\t\tSelf-Care Tips for Depression\n\n";
 printHeader();

 int score = answerList.countYesAnswers();
 if (score >= 4) {
 cout << "• Talk to someone you trust\n• Seek professional help\n";
 cout << "• Try grounding techniques\n• Practice deep breathing exercises\n";
 } else if (score >= 2) {
 cout << "• Go for a walk or light exercise\n• Do things you used to enjoy\n";
 cout << "• Maintain a sleep schedule\n• Connect with friends or family\n";
 } else {
 cout << "• Keep up your current healthy habits\n• Practice gratitude and mindfulness\n";
 cout << "• Stay connected with loved ones\n• Continue regular exercise\n";
 }

 offerAnswerChange();
 }
};
class AnxietyTest : public MentalHealthTest {
public:
 AnxietyTest() {
 testName = "Anxiety Test";
 testType = 1;
 questions[0] = "1. Do you feel nervous or on edge frequently?";
 questions[1] = "2. Do you have difficulty controlling worry?";
 questions[2] = "3. Do you experience restlessness or irritability?";
 questions[3] = "4. Do you have trouble sleeping due to worry?";
 questions[4] = "5. Do you feel your anxiety affects your daily life?";
 }

 void diagnose() {
 showDiagnosisResults();
 }

 void showTips() {
 clearScreen();
 printHeader();
 cout << "\t\t\t\t\t\t\t\tSelf-Care Tips for Anxiety\n\n";
 printHeader();

 int score = answerList.countYesAnswers();
 if (score >= 4) {
 cout << "• Try daily meditation or breathing exercises\n• Limit caffeine\n";
 cout << "• Seek therapy\n• Practice progressive muscle relaxation\n";
 } else if (score >= 2) {
 cout << "• Keep a worry journal\n• Use calming hobbies\n";
 cout << "• Practice mindfulness\n• Limit news consumption\n";
 } else {
 cout << "• Maintain your calm routines\n• Stay connected with supportive people\n";
 cout << "• Continue stress management techniques\n• Regular exercise helps maintain balance\n";
 }

 offerAnswerChange();
 }
};
class ADHDTest : public MentalHealthTest {
public:
 ADHDTest() {
 testName = "ADHD Test";
 testType = 2;
 questions[0] = "1. Do you often have trouble paying attention?";
 questions[1] = "2. Do you frequently interrupt others?";
 questions[2] = "3. Do you struggle to stay organized?";
 questions[3] = "4. Do you find it hard to sit still for long?";
 questions[4] = "5. Do you often act without thinking?";
 }

 void diagnose() {
 showDiagnosisResults();
 }

 void showTips() {
 clearScreen();
 printHeader();
 cout << "\t\t\t\t\t\t\t\tSelf-Care Tips for ADHD\n\n";
 printHeader();

 int score = answerList.countYesAnswers();
 if (score >= 4) {
 cout << "• Consult a doctor for assessment\n• Use timers and reminders to stay on track\n";
 cout << "• Break tasks into smaller chunks\n• Create a structured daily routine\n";
 } else if (score >= 2) {
 cout << "• Break tasks into smaller steps\n• Reduce distractions while working\n";
 cout << "• Use organizational tools like planners\n• Practice mindfulness meditation\n";
 } else {
 cout << "• Keep practicing your existing focus strategies\n";
 cout << "• Maintain good organizational habits\n";
 }

 offerAnswerChange();
 }
};
class AutismTest : public MentalHealthTest {
public:
 AutismTest() {
 testName = "Autism Spectrum Test";
 testType = 3;
 questions[0] = "1. Do you struggle with social interactions?";
 questions[1] = "2. Do you find it hard to understand others' emotions?";
 questions[2] = "3. Do you prefer routines and get upset with changes?";
 questions[3] = "4. Do you engage in repetitive behaviors?";
 questions[4] = "5. Do sensory experiences overwhelm you?";
 }


 void diagnose() {
 showDiagnosisResults();
 }

 void showTips() {
 clearScreen();
 printHeader();
 cout << "\t\t\t\t\t\t\t\tSelf-Care Tips for Autism\n\n";
 printHeader();

 int score = answerList.countYesAnswers();
 if (score >= 2) {
 cout << "• Create structured routines\n• Use visual aids\n";
 cout << "• Seek sensory-friendly environments\n• Practice social skills in low-pressure settings\n";
 } else {
 cout << "• Continue with supportive habits that work for you\n";
 cout << "• Practice empathy and understanding towards others\n";
 }

 offerAnswerChange();
 }
};
int main() {
 bool running = true;

 while (running) {
 clearScreen();
 printHeader();
 cout << " \t\t\t\t\tWelcome to the Mental Health Diagnosing System \n\n";
 printHeader();
 cout << "\t\t\t\t\tYour First Step Toward Mental Clarity.\n\n";
 cout << "Select a test to take:\n";
 cout << "1. Depression Test\n";
 cout << "2. Anxiety Test\n";
 cout << "3. ADHD Test\n";
 cout << "4. Autism Test\n";
 cout << "5. Exit\n\n";
 cout << "Enter your choice (1-5): ";

 int userChoice;
 cin >> userChoice;

 if (cin.fail() || userChoice < 1 || userChoice > 5) {
 cin.clear();
 cin.ignore(1000, '\n');
 cout << "\nInvalid input. Please enter a number from 1 to 5.\n";
 cout << "Press Enter to try again...";
 cin.get();
 continue;
 }

 if (userChoice == 5) {
 cout << "\nThank you for using the Mental Health Diagnosing System.\n";
 printHeader();
 running = false;
 continue;
 }

 MentalHealthTest* test = NULL;
 switch (userChoice) {
 case 1: test = new DepressionTest();
break;
 case 2: test = new AnxietyTest();
break;
 case 3: test = new ADHDTest();
break;
 case 4: test = new AutismTest();
break;
 }

 cin.ignore();
 test->askQuestions();
 test->diagnose();
 cout << "\nPress Enter to continue...";
 cin.get();
 test->showTips();
 delete test;
 cout << "\nPress Enter to return to the main menu...";
 cin.ignore();
 cin.get();
 }

 return 0;
}

