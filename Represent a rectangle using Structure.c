#include <stdio.h>

struct Rectangle {
	float length;
float width;
};
int calcrec(struct Rectangle rect){
	float area = rect.length*rect.width;
	return area;
}

int main() {
	struct Rectangle rect;
	printf("Enter the length of the rectangle: ");
	scanf("%f",&rect.length);
	printf("Enter the width of the rectangle: ");
	scanf("%f",&rect.width);
	float area = rect.length*rect.width;
	printf("The area of the rectangle is: %.2f\n",area);
}