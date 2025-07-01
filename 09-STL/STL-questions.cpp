/*
 * STL Practice: 10 Questions using C++ Standard Library
 * Description:
 *  - Q1: Sort integers
 *  - Q2: Unique elements in sorted order
 *  - Q3: Frequency counter
 *  - Q4: Intersection of vectors
 *  - Q5: Stack with deque
 *  - Q7: Character frequency in string
 *  - Q8: Check membership in set
 *  - Q9: Basic phonebook with map
 *  - Q10: Sort vector of pairs
 */

#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <deque>
#include <algorithm>

using namespace std;

/* Utility: Take integer vector input */
vector<int> take_input()
{
    size_t n;
    cout << "Enter number of elements: ";
    cin >> n;
    vector<int> v(n);
    cout << "Enter elements: ";
    for (auto& it : v) cin >> it;
    return v;
}

/* Utility: Print vector */
void print_vector(const vector<int>& v)
{
    for (const auto& it : v) cout << it << " ";
    cout << endl;
}

/* Q1. Read N integers and print them in sorted order */
void Q1()
{
    auto v = take_input();
    sort(v.begin(), v.end());
    cout << "Sorted: ";
    print_vector(v);
}

/* Q2. Print unique elements in increasing order */
void Q2()
{
    auto v = take_input();
    set<int> st(v.begin(), v.end());
    cout << "Unique elements: ";
    for (const auto& it : st) cout << it << " ";
    cout << endl;
}

/* Q3. Frequency counter of integers */
void Q3()
{
    auto v = take_input();
    map<int, int> freq;
    for (const auto& it : v) freq[it]++;
    cout << "Frequencies:\n";
    for (const auto& it : freq) cout << it.first << ": " << it.second << " ";
    cout << endl;
}

/* Q4. Intersection of two vectors */
vector<int> Q4()
{
    vector<int> A = {1, 2, 2, 3, 4};
    vector<int> B = {2, 2, 4, 6};
    vector<int> result;

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    set_intersection(A.begin(), A.end(), B.begin(), B.end(), back_inserter(result));

    cout << "Intersection: ";
    print_vector(result);
    return result;
}

/* Q5. Stack implemented with std::deque */
class MyStack
{
   private:
    deque<int> dq;

   public:
    void push(int x) { dq.push_back(x); }
    void pop()
    {
        if (dq.empty())
        {
            cout << "Stack is empty.\n";
            return;
        }
        dq.pop_back();
    }
    int top() const
    {
        if (!dq.empty()) return dq.back();
        cout << "Stack is empty.\n";
        return -1;
    }
    bool empty() const { return dq.empty(); }
};

void Q5()
{
    MyStack stack;
    stack.push(10);
    stack.push(20);
    stack.push(30);
    cout << "Top: " << stack.top() << endl;
    stack.pop();
    cout << "Top after pop: " << stack.top() << endl;
    stack.pop();
    stack.pop();
    stack.pop();  // Extra pop to test empty handling
}

/* Q7. Frequency of characters in a string using unordered_map */
void Q7()
{
    string text = "frequency_of_each_character_in_string";
    unordered_map<char, int> freq;
    for (char ch : text) freq[ch]++;
    cout << "Character Frequencies:\n";
    for (const auto& [ch, count] : freq) cout << ch << ":" << count << "  ";
    cout << endl;
}

/* Q8. Check if integer is present in std::set */
void Q8()
{
    set<int> st = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    cout << "Enter integer to search: ";
    int x;
    cin >> x;
    auto it = st.find(x);
    if (it != st.end())
        cout << "Found: " << *it << endl;
    else
        cout << "Not found" << endl;
}

/* Q9. Basic phone book using map<string, string> */
class Phonebook
{
   private:
    map<string, string> contacts;

   public:
    Phonebook() { contacts["JETHALAL"] = "81xxxx93"; }
    void addNumber(const string& name, const string& number) { contacts[name] = number; }
    void search(const string& name) const
    {
        auto it = contacts.find(name);
        if (it != contacts.end())
            cout << name << " found: " << it->second << endl;
        else
            cout << "Not found" << endl;
    }
    void showContacts() const
    {
        cout << "Phonebook:\n";
        for (const auto& [name, number] : contacts) cout << name << ": " << number << endl;
    }
};

void Q9()
{
    Phonebook pb;
    pb.addNumber("Lana", "94xxxx65");
    pb.search("JETHALAL");
    pb.showContacts();
}

/* Q10. Sort vector of pairs by first element */
void Q10()
{
    vector<pair<int, int>> pairs = {{5, 20}, {1, 99}, {3, 50}, {2, 10}};
    sort(pairs.begin(), pairs.end());
    cout << "Sorted pairs:\n";
    for (const auto& [first, second] : pairs) cout << first << " " << second << endl;
}

int main()
{
    // Uncomment any question to test:
    // Q1();
    // Q2();
    // Q3();
    // Q4();
    // Q5();
    // Q7();
    // Q8();
    Q9();
    // Q10();

    return 0;
}
