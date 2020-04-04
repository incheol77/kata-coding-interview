


/* original functions which have the bugs */
void removeHead(ListElement *head) {
	free(head);
	head = head->next;
}


/* step 1 */
void removeHead(ListElement *head) {
	ListElement *newHead = head->next;
	free(head);
	head = newHead;
}

/* step 2 */
void removeHead(ListElement **head) {
	ListElement *newHead = (*head)->next;
	free(*head);
	*head = newHead;
}

/* step 3 */
void removeHead(ListElement **head) {
	ListElement *newHead;
	if (head && *head) {
		newHead = (*head)->next;
		free(*head);
		*head = newHead;
	}
}

/* step 4 */
void removeHead(ListElement **head) {
	if (!head || !(*head)) 
		return;

	ListElement *newHead = (*head)->next;
	free(*head);
	*head = newHead;
}
