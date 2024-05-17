#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "column.h"
#include "cdataframe.h"



//



int main(){
	COLUMN* my_column = create_column("Titre de la colonne");

	if (my_column != NULL) {
	printf("Colonne créée avec succès : %s\n", my_column->title);
	delete_column(&my_column);
	} else {
		printf("Erreur lors de la création de la colonne.\n");
	}

	int val = 5;
	if (insert_value(my_column, val)){
		printf("Value added successfully to my column\n");
	
	}else{
		printf("Error adding value to my column\n");
	}
	COLUMN *mycol = create_column("My column");
	insert_value(mycol, 53);
	insert_value(mycol, 15);
	insert_value(mycol, 44);
	insert_value(mycol, 15);
	insert_value(mycol, 15);
	print_col(mycol);
	position_value(mycol, 15);
	superior_value(mycol, 20);
	inferior_value(mycol, 20);
	equal_value(mycol, 53);
	delete_column(&mycol);
	return 0;
}