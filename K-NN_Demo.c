#include <stdio.h>
#include <math.h>

#define TRAINING_DATA_LENGTH 19900 // for train
#define TEST_DATA_LENGTH 100 // for test

// class letter (use C 'struct' type)
struct letter
{
    char character; // true value
    int attributes[16]; // by defination, number of attributes is 16.
    float distance;
};

// training set, sample number: TRAINING_DATA_LENGTH
struct letter train_letters_set[TRAINING_DATA_LENGTH];
// test set, sample number: TEST_DATA_LENGTH
struct letter test_letters_set[TEST_DATA_LENGTH];

// read train data (plain txt file like train19900.txt) into `train_letters_set[TRAINING_DATA_LENGTH]` in memory
void Read_training_file_from_disk()
{
    FILE *fp;
    int i, j;
    fp = fopen("train19900.txt", "r");
    for(i = 0; i < TRAINING_DATA_LENGTH; i++) {
        fscanf(fp, "%c ", &train_letters_set[i].character); // first column is lettr capital letter (26 values from A to Z) 
        for(j = 0; j < 16; j++)
            fscanf(fp, "%d ", &train_letters_set[i].attributes[j]); // scan 16 attributes in data set
    }
    fclose(fp);
}

// read test data (plain txt file like test100.txt) into `test_letters_set[TEST_DATA_LENGTH]` in memory
void Read_testing_file_from_disk()
{
    int i, j;
    FILE *fp;
    fp = fopen("test100.txt", "r");
    for(i = 0; i < TEST_DATA_LENGTH; i++) {
        fscanf(fp,"%c ", &test_letters_set[i].character); // first column is lettr capital letter (26 values from A to Z) 
        for(j = 0; j < 16; j++)
            fscanf(fp, "%d ", &test_letters_set[i].attributes[j]); // scan 16 attributes in data set
    }
    fclose(fp);
}

// calculate euclidean distance between a test sample and all trtaining samples
void Calc_Euclidean_Distance(struct letter *p)
{
    int i, j;
    float tmp = 0.0;
    for(i = 0; i < TRAINING_DATA_LENGTH; i++) {
        for(j = 0; j < 16; j++) {
            tmp+= ((train_letters_set[i].attributes[j]-(*p).attributes[j])*(train_letters_set[i].attributes[j]-(*p).attributes[j]));
        }
        train_letters_set[i].distance = sqrt(tmp);
        //restore default
        tmp = 0.0;
    }
}

// classify depending on user's `K` input
char KNN(int K)
{
    int i, j, max;
    int letters_appearance[26]={0};

    for(i = 0; i < K; i++) {
        switch(train_letters_set[i].character) {
            case'A':
                letters_appearance[0]++;
                break;
            case'B':
                letters_appearance[1]++;
                break;
            case'C':
                letters_appearance[2]++;
                break;
            case'D':
                letters_appearance[3]++;
                break;
            case'E':
                letters_appearance[4]++;
                break;
            case'F':
                letters_appearance[5]++;
                break;
            case'G':
                letters_appearance[6]++;
                break;
            case'H':
                letters_appearance[7]++;
                break;
            case'I':
                letters_appearance[8]++;
                break;
            case'J':
                letters_appearance[9]++;
                break;
            case'K':
                letters_appearance[10]++;
                break;
            case'L':
                letters_appearance[11]++;
                break;
            case'M':
                letters_appearance[12]++;
                break;
            case'N':
                letters_appearance[13]++;
                break;
            case'O':
                letters_appearance[14]++;
                break;
            case'P':
                letters_appearance[15]++;
                break;
            case'Q':
                letters_appearance[16]++;
                break;
            case'R':
                letters_appearance[17]++;
                break;
            case'S':
                letters_appearance[18]++;
                break;
            case'T':
                letters_appearance[19]++;
                break;
            case'U':
                letters_appearance[20]++;
                break;
            case'V':
                letters_appearance[21]++;
                break;
            case'W':
                letters_appearance[22]++;
                break;
            case'X':
                letters_appearance[23]++;
                break;
            case'Y':
                letters_appearance[24]++;
                break;
            case'Z':
                letters_appearance[25]++;
                break;
        }
    }

    max = letters_appearance[0];
    j = 0;
    for(i = 0; i < 26; i++)
    {
        if(letters_appearance[i] > max)
        {
            max = letters_appearance[i];
            j = i;
        }
    }
    return (char)(j + 65); //ASCII
}

// sort letters distance from min to max
void Sort_letters_distance()
{
    int i, j;
    struct letter tmp;
    for(i = 0; i < TRAINING_DATA_LENGTH - 1; i++) {
        for(j = i + 1; j < TRAINING_DATA_LENGTH; j++) {
            if(train_letters_set[i].distance>train_letters_set[j].distance) {
                tmp = train_letters_set[i];
                train_letters_set[i] = train_letters_set[j];
                train_letters_set[j] = tmp;
            }
        }
    }
}

int main()
{
    int i, j, K_nearest_neighbour = 0;
    int right_prediction_count = 0, wrong_prediction_count = 0;
    struct letter * p;
    char predictValue;
    printf("   \
            ************************************************************************************************\n   \
            *                           K-NN Demo using Data Set: UCI Letter Recognition                   *\n   \
            *                                       - [Yang (Simon) Guo] -                                 *\n   \
            ************************************************************************************************\n"
    );
    printf("\nrows of training data set: %d\n", TRAINING_DATA_LENGTH);
    Read_training_file_from_disk();
    printf("rows of test data set: %d\n", TEST_DATA_LENGTH);
    Read_testing_file_from_disk();
    printf("input K in K-nearest-neighbour algorithm: ");
    scanf("%d", &K_nearest_neighbour);
    printf("\n-------------------INDIVIDUAL TEST RESULT-------------------\n");
    for(i = 0; i < TEST_DATA_LENGTH; i++) {
        p = &test_letters_set[i];
        Calc_Euclidean_Distance(p);
        Sort_letters_distance();
        predictValue = KNN(K_nearest_neighbour);
        if(test_letters_set[i].character == predictValue) {
            printf("Distance is %f.\n", train_letters_set[0].distance);
            printf("This subject belongs to class: [%c], prediction is class: [%c], CORRECT!\n", test_letters_set[i].character, predictValue);
            right_prediction_count++;
        }
        else {
            printf("Distance is %f.\n", train_letters_set[0].distance);
            printf("This subject belongs to class: [%c], prediction is class: [%c], WRONG!\n", test_letters_set[i].character, predictValue);
            wrong_prediction_count++;
        }
        
    }
    printf("\n-------------------TEST RESULT SUMMARY-------------------\n");
    printf("right prediction: %d\n", right_prediction_count);
    printf("wrong prediction: %d\n", wrong_prediction_count);
    printf("accuracy: %.3f%% [%f]\n", (float)(right_prediction_count)*100 / TEST_DATA_LENGTH, (float)(right_prediction_count) / TEST_DATA_LENGTH);
    return 0;
}
