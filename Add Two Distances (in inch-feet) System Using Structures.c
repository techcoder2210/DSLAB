#include <stdio.h>
struct Distance{
int feet;
float inches;
};
struct Distance addD(struct Distance d1, struct Distance d2){
	struct Distance result;
	result.feet = d1.feet + d2.feet;
	result.inches = d1.inches+d2.inches;
	if(result.inches>=12.0){
		result.feet += (int)(result.inches/12);
		result.inches = (int)result.inches%12 + (result.inches - (int)result.inches);
	}
	return result;
}
int main(){
	struct Distance d1,d2,result;
	printf("Enter 1st distance \n");
	printf("feet: ");
	scanf("%d",&d1.feet);
	printf("inch: ");
	scanf("%f",&d1.inches);
	printf("Enter 2nd distance \n");
	printf("feet: ");
	scanf("%d",&d2.feet);
	printf("inch: ");
	scanf("%f",&d2.inches);
	result = addD(d1,d2);
	printf("Sum of distances = %d'-%0.1f\"\n" ,result.feet,result.inches);
}