#ifndef COLUMN_H
#define COLUMN_H

typedef struct {
	char* title;
	int* data;
	int size;
}COLUMN;

COLUMN* create_column(char* title);
int insert_value(COLUMN* col, int value);
void delete_column(COLUMN **col);
void print_col(COLUMN* col);
void occurence_value(COLUMN* col, int value);
void position_value(COLUMN* col, int value);
void superior_value(COLUMN* col, int value);
void inferior_value(COLUMN* col, int value);
void equal_value(COLUMN* col, int value);



//



COLUMN* create_column(char* title){
	COLUMN* col = (COLUMN*)malloc(sizeof(COLUMN));
	
	if (col == NULL) {
		perror("Erreur d'allocation de mémoire pour la colonne");
		return NULL;
	}

	col-> title = strdup(title);
	if (col->title == NULL) {
		perror("Erreur d'allocation de mémoire pour le titre de la colonne");
		free(col);
		return NULL; 
	}

	col-> size = 0;
	col-> data = NULL;
	return col;
}

int insert_value(COLUMN* col, int value){
	if (col->size % 256 == 0 || col->size == 0){
		int* new_data = (int*)realloc(col->data, (col->size + 256) * sizeof(int));
		if (new_data == NULL) {
			perror("Erreur de ré-allocation de mémoire pour les données de la colonne");
			return 0; 
        	}

		col->data = new_data;
	}
	col->data[col->size] = value;
	col->size++;
	return 1;
}

void delete_column(COLUMN **col){
	if (*col == NULL){
		return;
	}
	free((*col)->title);
	free((*col)->data);
	free(*col);
}

void print_col(COLUMN* col){
	printf("%s\n",col->title);
	for (int i = 0; i< col->size; i++){
		printf("[%d]   %d\n", i, col->data[i]);
	}
}

void occurence_value(COLUMN* col, int value){
	int count = 0;
	for (int i = 0; i < col->size; i++){
		if (col->data[i] == value){
			count++;
		}
	}
	printf("%d", count);
}

void position_value(COLUMN* col, int value){
	int* position = (int*)malloc((col->size)* sizeof(int));
	if (position == NULL) {
		perror("Erreur d'allocation de mémoire pour le tableau de positions");
		return;
    }
	int count = 0;
	for (int i = 0; i < col->size; i++){
		if (col->data[i] == value){
			position[count] = i;
			count++;
		}
	}
	position = (int*)realloc(position, count * sizeof(int));
	if (position == NULL) {
		perror("Erreur de ré-allocation de mémoire pour le tableau de positions");
		free(position); 
		return;
	}
	for (int i = 0; i<count; i++){
		printf("%d\n", position[i]);
	}
}

void superior_value(COLUMN* col, int value){
	int count = 0;
	for (int i = 0; i < col->size; i++){
		if (col->data[i] > value){
			count++;
		}
	}
	printf("%d\n", count);
}

void inferior_value(COLUMN* col, int value){
	int count = 0;
	for (int i = 0; i < col->size; i++){
		if (col->data[i] < value){
			count++;
		}
	}
	printf("%d\n", count);
}

void equal_value(COLUMN* col, int value){
	int count = 0;
	for (int i = 0; i< col->size; i++){
		if (col->data[i] == value){
			count++;
		}
	}
	printf("%d\n", count);
}

#endif