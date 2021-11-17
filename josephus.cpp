#include <iostream>

using namespace std;

class rebel {
public:
	int position;
	rebel* next;
};

rebel* newNode(int data)
{
	rebel* temp = new rebel;
	temp->next = temp;
	temp->position = data;
	return temp;
}

rebel *createRebelCircle(int n) {
	rebel* head = newNode(1);
	rebel* prev = head;
	for (int i = 2; i <= n; i++)
	{
		prev->next = newNode(i);
		prev = prev->next;
	}
	prev->next = head;

	return head;
}

void killRebel(rebel *killer) {
	rebel* temp;
	temp = killer->next;
	killer->next = temp->next;
	delete temp;
}

void displayCircle(rebel* current) {
	int temp = current->position;
	cout << "[ " << temp << " ";
	current = current->next;
	while (current->position != temp) {
		cout << current->position << " ";
		current = current->next;
	}
	cout << "]" << endl;
}

int josephus(rebel *current) {
	if (current->next == current) {
		return current->position;
	}
	else {
		displayCircle(current);
		killRebel(current);
		josephus(current->next);
	}
}

int main() {
	int n = 0;
	cout << "Enter number of rebels: ";
	cin >> n;

	rebel *start = createRebelCircle(n);
	cout << josephus(start);
}