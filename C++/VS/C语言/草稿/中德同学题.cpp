//#include<stdio.h>
//int main()
//{
//    int a, n, count, b;
//    count = 0;
//    scanf_s("%d%d", &a, &n);
//    do {
//        scanf_s("%d", &b);
//        if (b < 0) {
//            printf("Game Over");
//            return 0;
//        }
//        else if (b > a) {
//            count++;
//            printf("Too big\n");
//            break;
//        }
//        else if (b < a) {
//            count++;
//            printf("Too small\n");
//            break;
//        }
//        else if (b == a) {
//            count++;
//            printf("Bingo!");
//            return 0;
//        }
//    } while (count < 1 && count <= n);
//
//    do {
//        scanf_s("%d", &b);
//        if (b < 0) {
//            printf("Game Over");
//            return 0;
//        }
//        else if (b > a) {
//            count++;
//            printf("Too big\n");
//            break;
//        }
//        else if (b < a) {
//            count++;
//            printf("Too small\n");
//            break;
//        }
//        else if (b == a) {
//            count++;
//            printf("Lucky You!");
//            return 0;
//        }
//    } while (count >= 1 && count < 3 && count <= n);
//
//    do {
//        scanf_s("%d", &b);
//        if (b < 0) {
//            printf("Game Over");
//            return 0;
//        }
//        else if (b > a) {
//            count++;
//            printf("Too big\n");
//            // break;
//
//        }
//        else if (b < a) {
//            count++;
//            printf("Too small\n");
//            //break;
//
//        }
//        else if (b == a) {
//            count++;
//            printf("Good Guess!");
//            return 0;
//        }
//    } while (count >= 3 && count < n);
//    printf("Game Over");
//    return 0;
//}