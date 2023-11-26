#include "deck.h"

void sort_deck(deck_node_t **deck);
void insertion_sort_deck_value(deck_node_t **deck);
char get_value(deck_node_t *card);
int _strcmp(const char *s1, const char *s2);

/**
 * sort_deck - Sorts a deck of cards.
 *
 * @deck: Pointer to the head of the list.
 */
void sort_deck(deck_node_t **deck)
{
	deck_node_t *iter, *insert, *tmp;

	if (deck == NULL || *deck == NULL || (*deck)->next == NULL)
		return;

	for (iter = (*deck)->next; iter != NULL; iter = tmp)
	{
		tmp = iter->next;
		insert = iter->prev;

		while (insert != NULL && insert->card->kind > iter->card->kind)
		{

			insert->next = iter->next;
			if (iter->next != NULL)
				iter->next->prev = insert;
			iter->prev = insert->prev;
			iter->next = insert;
			if (insert->prev != NULL)
				insert->prev->next = iter;
			else
				*deck = iter;
			insert->prev = iter;
			insert = iter->prev;
		}
	}

	insertion_sort_deck_value(deck);
}

/**
 * insertion_sort_deck_value - Sort a deck of cards.
 *
 * @deck: A pointer to the head of a list.
 */
void insertion_sort_deck_value(deck_node_t **deck)
{
	deck_node_t *iter, *insert, *tmp;

	for (iter = (*deck)->next; iter != NULL; iter = tmp)
	{
		tmp = iter->next;
		insert = iter->prev;

		while (insert != NULL &&
				insert->card->kind == iter->card->kind
				&& get_value(insert) > get_value(iter))
		{
			insert->next = iter->next;
			if (iter->next != NULL)
				iter->next->prev = insert;
			iter->prev = insert->prev;
			iter->next = insert;
			if (insert->prev != NULL)
				insert->prev->next = iter;
			else
				*deck = iter;
			insert->prev = iter;
			insert = iter->prev;
		}
	}
}

/**
 * get_value - Get the numerical value of a card.
 *
 * @card: A pointer to a list.
 *
 * Return: The numerical value of the card.
 */
char get_value(deck_node_t *card)
{
	if (_strcmp(card->card->value, "Ace") == 0)
		return (0);
	if (_strcmp(card->card->value, "1") == 0)
		return (1);
	if (_strcmp(card->card->value, "2") == 0)
		return (2);
	if (_strcmp(card->card->value, "3") == 0)
		return (3);
	if (_strcmp(card->card->value, "4") == 0)
		return (4);
	if (_strcmp(card->card->value, "5") == 0)
		return (5);
	if (_strcmp(card->card->value, "6") == 0)
		return (6);
	if (_strcmp(card->card->value, "7") == 0)
		return (7);
	if (_strcmp(card->card->value, "8") == 0)
		return (8);
	if (_strcmp(card->card->value, "9") == 0)
		return (9);
	if (_strcmp(card->card->value, "10") == 0)
		return (10);
	if (_strcmp(card->card->value, "Jack") == 0)
		return (11);
	if (_strcmp(card->card->value, "Queen") == 0)
		return (12);
	return (13);
}

/**
 * _strcmp - Compares two strings.
 *
 * @s1: The first string.
 * @s2: The seond string.
 *
 * Return: Positive byte differnce if s1 > s2
 *         0 if s1 == s2
 *         Negative byte difference if s1 < s2.
 */
int _strcmp(const char *s1, const char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}

	if (*s1 != *s2)
		return (*s1 - *s2);
	return (0);
}
