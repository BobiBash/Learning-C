#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void calculateShapeArea();
double calculateSquare(double width);
double calculateTriangle(double width, double height);
double calculateRectangle(double width, double height);
double calculateTrapezoid(double top_side, double bottom_side, double height);
double calculateCircle(double radius);
double calculateEllipse(double major_axis, double minor_axis);
double calculateParallelogram(double width, double height);

int main() {
    calculateShapeArea();
    return 0;
}


void calculateShapeArea() {

    int shape_choice = 0;
    
    while(1) {
        printf("Choose a shape: \n");
        printf("1. Square\n");
        printf("2. Triangle\n");
        printf("3. Rectangle\n");
        printf("4. Trapezoid\n");
        printf("5. Ellipse\n");
        printf("6. Circle\n");
        printf("7. Parallelogram\n");
        printf("8. Exit\n");
        scanf("%d", &shape_choice);
        if(shape_choice > 8 || shape_choice < 1){
            printf("Invalid choice.");
            continue;
        }

        if(shape_choice == 8) {
            exit(0);
        }
        break;
    }

    double width, height, bottom_side, top_side, radius, major_axis, minor_axis;
    double result;

    switch(shape_choice) {
        case(1): 
            printf("Square width: ");
            scanf("%lf", &width);
            result = calculateSquare(width);
            break;
        case(2): 
            printf("Triangle width and height: ");
            scanf("%lf%lf", &width, &height);
            result = calculateTriangle(width, height);
            break;
        case(3): 
            printf("Rectangle width and height: ");
            scanf("%lf%lf", &width, &height);
            result = calculateRectangle(width, height);
            break;
        case(4): 
            printf("Trapezoid top side, bottom side and height: ");
            scanf("%lf%lf%lf", &top_side, &bottom_side, &height);
            result = calculateTrapezoid(top_side, bottom_side, height);
            break;
        case(5): 
            printf("Circle radius: ");
            scanf("%lf", &radius);
            result = calculateCircle(radius);
            break;
        case(6): 
            printf("Ellipse major axis and minor axis: ");
            scanf("%lf%lf", &major_axis, &minor_axis);
            result = calculateEllipse(major_axis, minor_axis);
            break;
        case(7): 
            printf("Parallelogram width and height: ");
            scanf("%lf%lf", &width, &height);
            result = calculateParallelogram(width, height);
            break;
    }

    printf("Result: %.0lf", result);
}

double calculateSquare(double width) {
    return pow(width, 2);
}
double calculateTriangle(double width, double height) {
    return (width * height) / 2;
}
double calculateRectangle(double width, double height) {
    return width * height;
}
double calculateTrapezoid(double top_side, double bottom_side, double height) {
    return ((top_side + bottom_side) / 2) * height;
}
double calculateCircle(double radius) {
    return M_PI * pow(radius, 2);
}
double calculateEllipse(double major_axis, double minor_axis) {
    return M_PI * major_axis * minor_axis;
}
double calculateParallelogram(double width, double height) {
    return width * height;
}