#include <iostream>

class Stack
{
public:
	Stack() : head(NULL) {};
	~Stack();
	void push(void *data);
	void *pop();

protected:
	class Element {
	public:
		Element(Element *n, void *d): next(n), data(d) {}
		Element *getNext() const { return next; }
		void *value() const { return data; }
	private:
		Element *next;
		void *data;
	};

	Element *head;

};


Stack::~Stack() {
	while(head) {
		Element *next = head->getNext();
		delete head;
		head = next;
	}
}

void Stack::push(void *data) {
	// Allocation error will throw exception
	Element *element = new Element(head, data);
	head = element;
}

void *Stack::pop() {
	Element *popElement = head;
	void *data;

	/* Assume StackError exception class is defined elsewhere */
	if (head == NULL)
		throw StackError(E_EMPTY);

	data = head->value();
	head = head->getNext();
	delete popElement;
	return data;
}
