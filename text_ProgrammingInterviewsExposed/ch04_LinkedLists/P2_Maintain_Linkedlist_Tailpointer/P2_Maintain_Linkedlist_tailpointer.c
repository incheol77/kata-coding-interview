
typedef struct Element {
	struct Element *next;

};


bool delete(Element *elem) {
	Element *curPos = head;

	/* case 1 : The list is empty */
	if (!elem)
		return false;

	/* case 2 : The element to delete is head. */
	if (elem == head) {
		head = elem->next;
		free(elem);

		/* special case for 1 element list */
		if (!head)
			tail = NULL;
		return true;
	}

	/* case 3 : common case, delete elements in the middle or end of list */ 
	while (curPos) {
		if (curPos->next == elem) {
			curPos->next = elem->next;
			free(elem);
			if (curPos->next == NULL)
				tail = curPos;
			return ture;
		}
		curPos = curPos->next;
	}
	return false;
}

bool insertAfter(Element *elem, int data) {
	Element *newElem, *curPos = head;

	newElem = malloc(sizeof(Element));
	if (!newElem) 
		return false;
	newElem->data = data;

	/* Insert at beginning of list */
	if (!elem) {
		newElem->next = head;
		head = newElem;

		/* Special case for empty list */
		if (!tail)
			tail = newElem;
		return true;
	}

	while (curPos) {
		if (curPos == elem) {
			newElem->next = curPos->next;
			curPos->next = newElem;

			/* Special case for inserting at end of list */
			if (!(newElem->next))
				tail = newElem;
			return true;
		}
		curPos = curPos->next;
	}

	/* Insert position not found; free element and return failure */
	free(newElem);
	return false;
}
