#include <stdio.h>
#include <math.h>

//These operations are only valid for square matricies 


void buildMatrix(int* mat1, int size);
void addMatrix(int* mat1, int* mat2, int* mat3, int size);
void multMatrix(int* mat1, int* mat2, int* mat3, int size);
void rotateMatrix(int* mat1, int angle, float* mat3);
void printMat(float* mat,int size);

void printMatFloat(float* mat, int size){
    for(int i = 1; i < size*size + 1; i++){
        printf("%f ",*mat);
        mat++;
        if (i % size == 0){
            printf("\n");
        }
    }
}
void printMatInt(int* mat, int size){
    for(int i = 1; i < size*size + 1; i++){
        printf("%d ",*mat);
        mat++;
        if (i % size == 0){
            printf("\n");
        }
    }
}

void addMatrix(int* mat1, int* mat2, int* mat3, int size){
    for (int i = 0; i < size*size; i++){
        *mat3 = *mat1 + *mat2;
        mat1 ++;
        mat2 ++;
        mat3 ++;    
    }
}

void multMatrix(int* mat1, int* mat2, int* mat3, int size){
    int temp = 0;
    for (int i = 0; i < size; i++){
        for (int j = 0; j < size; j++){
            for (int k = 0; k < size; k++){
                //printf("%d,%d : %d,%d\n ",i,j,*(mat1+(j*size) + k),*(mat2 + i + size*k));
                temp += *(mat1+(i*size) + k) * *(mat2 + j + size*k);
            }
            *mat3 = temp;
            temp = 0;
            mat3 ++;
        }
    }
}

void buildMatrix(int* mat1, int size){
    int current;
    printf("Enter the digits\n");
    for (int i = 0; i < size*size; i++){
        printf(">");
        scanf("%d",&current);
        *(mat1 + i) = current;
    }
}

void rotateMatrix(int* mat1, int angle, float* mat3){ //only applies to 2x matricies 
    float rot[2][2] = {{cos(angle),-sin(angle)},{sin(angle),cos(angle)}};
    float* rotPrt = &rot[0][0];
    float temp = 0;
    for (int i = 0; i < 2; i++){
        for (int j = 0; j < 2; j++){
            for (int k = 0; k < 2; k++){
                temp += *(mat1+(i*2) + k) * *(rotPrt + j + 2*k);
            }
            *mat3 = temp;
            temp = 0;
            mat3 ++;
        }
    }
}


int main (int argc, char** argv){
    
    int size = 2;
    // printf("Enter the size of the matrix A ");
    // scanf("%d",&size);
    int mat1[2][2] = {{5,2},{5,4}};
    int mat2[2][2] = {{6,7},{4,9}};
    float mat3[2][2];
    // int mat1[3][3] = {{7,3,8},{2,1,6},{9,5,4}};
    // int mat2[3][3] = {{5,7,6},{8,4,3},{3,1,9}};
    // int mat3[3][3];
    // multMatrix(&mat1[0][0],&mat2[0][0],&mat3[0][0],size);
    // printMat(&mat3[0][0],size);
}
