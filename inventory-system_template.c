#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 500

struct inventory_item
{
	// Fill in the required attributes
	char itemName[50];
	int quantity;
	double price;
	int id;
	char soldDate[25];
};
typedef struct inventory_item item;
item database[SIZE];
FILE *fp;

int readFile(char filename[], struct inventory_item inventory_list[]);
int getTotalItems(struct inventory_item inventory_list[], int count);
double getTotalVal(struct inventory_item inventory_list[], int count);

void printItem(struct inventory_item item)
{
	// Print off properties of one individual item
}

int main(int argc, char *argv[])
{

	// Check number of arguments
	if (argc != 2)
	{
		printf("Error! Missing arguments!\n");
		return 1;
	}

	struct inventory_item database[SIZE];
	int count;
	count = readFile(argv[1], database);

	getTotalVal(database, count);
	getTotalItems(database, count);

	return 0;
}

int readFile(char filename[], struct inventory_item inventory_list[])
{

	fp = fopen(filename, "r");
	int numOfItems;
	fscanf(fp, "%d\n", &numOfItems);

	for (int i = 0; i < numOfItems; i++)
	{
		fscanf(fp, "%s\n", database[i].itemName);
		fscanf(fp, "%d\n", &database[i].quantity);
		fscanf(fp, "%lf\n", &database[i].price);
		fscanf(fp, "%d\n", &database[i].id);
		fscanf(fp, "%s\n", database[i].soldDate);
	}
	fclose(fp);
	return numOfItems;
}

int getTotalItems(struct inventory_item inventory_list[], int count)
{

	int i;
	int total = 0;

	for (i = 0; i < count; ++i)
	{
		total += database[i].quantity;
	}

	printf("Total inventory quantity: %d\n", total);
	printf("Items that need to be ordered: \n");

	for (i = 0; i < count; ++i)
	{

		if (database[i].quantity < 10)
		{

			printf("    %s\n", database[i].itemName);
		}
	}

	return total;
}

double getTotalVal(struct inventory_item inventory_list[], int count)
{
	// --Qty of each item * its price--
	// Coke: Qty = 15, price = 1.59
	// Pepsi: Qty = 9, price = 1.49
	// Sprite: Qty = 7, price = 1.59

	int i;
	double cokeVal;
	double pepsiVal;
	double spriteVal;

	for (i = 0; i < count; ++i)
	{
		cokeVal = database[0].price * database[0].quantity;
		pepsiVal = database[1].price * database[1].quantity;
		spriteVal = database[2].price * database[2].quantity;
	}
	double totVal = (cokeVal + pepsiVal + spriteVal);

	printf("Total inventory value: $%-5.2f\n", totVal);

	return totVal;
}