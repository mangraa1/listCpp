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

int main(){

    list *head;
    list *tail; 
    head = tail = NULL;

    int n;
    cout << "Enter word count: "; cin >> n;

    for (int i = 0; i < n; i++){
        string str;
        cout << "Enter "<< i+1 <<" word: "; cin >> str;
        listAdd(&head, &tail, str);
    }

    listShow(head);

    listDel(&head, &tail);
}