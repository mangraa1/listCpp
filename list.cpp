#include <iostream>

using namespace std;

struct list {
    string data;
    list* next;
};

//adding elements to a list
void listAdd(list** head, list** tail, string data){
    list* temp = new list;
    temp->data = data;
    temp->next = NULL;

    if (!(*head))
        *head = *tail = temp;
    else {
        (*tail)->next = temp;
        *tail = temp;
    }
}

//list output
void listShow(list* head){
    cout << endl << "your list is: " << endl;
    int i = 1;
    while (head){
        cout << i << ". " << head->data << endl;
        i++;
        head = head->next;
    }
    cout << endl;
}

//adding a new element to any position
void listAddPos(list** head, list** tail){
    string data;
    int pos;
    cout << "enter data: "; cin >> data;
    cout << "enter position: "; cin >> pos;

    list* temp = new list;
    temp->data = data;

    if (!(*head)){
        temp->next = NULL;
        *head = *tail = temp;
        return;
    }

    if (pos == 1){
        temp->next = *head;
        *head = temp;
        return;
    }

    list* prev = *head;
    for (int i = 2; i < pos && prev->next; i++)
        prev = prev->next;

    temp->next = prev->next;
    prev->next = temp;

    if (*tail == prev)
       *tail = temp;
}

//deleting a list
void listDel(list** head, list** tail){
    list* tempDel;
    while (*head){
        tempDel = *head;
        *head = (*head)->next;
        delete tempDel;
    }
    *tail = NULL;
}

//checking for values that start and end with the same letter
void beginAndEnd(list* head){
    int count = 0;

    while (head){
        string word;
        word = head->data;

        if (word.front() == word.back())
            count++;
        head = head->next;
    }
    cout << "Words that start and end with the same letter: " << count << endl;
}

//checking for values that start with the same letter as the previous word ends
void beginFirstEndPrevious(list* head){
    int count = 0;
    string previous = "";

    while (head){
        string word = head->data;
        
        if (!previous.empty() && previous.back() == word.front()) 
            count++;
        previous = word;
        head = head->next;
    }
    cout << "Words that start with the same letter as the previous word ends: " << count << endl;
}

//checking for values that match the last word
void matchTheLastWord (list* head, int sizeOfList){
    string arr[sizeOfList];
    int i = 0;
    int count = 0;

    while (head){
        arr[i] += head->data;
        i++;
        head = head->next;
    }

    for (int i = 0; i < sizeOfList - 1; i++)
        if (arr[i] == arr[sizeOfList -1])
            count++;
    cout << "Words matching the last word: " << count << endl;
}

int main(){

    list *head;
    list *tail; 
    head = tail = NULL;

    int n;
    cout << "Enter word count: "; cin >> n;

    //populating a list with elements entered by the user
    for (int i = 0; i < n; i++){
        string str;
        cout << "Enter "<< i+1 << " word: "; cin >> str;
        listAdd(&head, &tail, str);
    }

    listShow(head);

    beginAndEnd(head);
    beginFirstEndPrevious(head);
    matchTheLastWord(head, n);

    listDel(&head, &tail);
}